#include "StdAfx.h"
#include "MainForm.h"
#include "LQ1000.h"

#pragma comment(lib, "LQ1000.lib")

using namespace System::Collections::Generic;

namespace Rzzk 
{
	ref class CDevData
	{
	public:
		CDevData()
			:m_devNum(0)
			,m_bOnline(false)
			,m_inPressure(0.0f)
			,m_outPressure(0.0f)
			,m_inDisplacement(0.0f)
			,m_outDisplacement(0.0f)
			,m_suspend(0.0f)
			,m_runTime(0)
		{
		}
		UInt16	m_devNum;
		BOOL	m_bOnline;
		FLOAT	m_inPressure;	//进口压力
		FLOAT	m_outPressure;	// 出口压力
		FLOAT	m_inDisplacement;	//进口排量
		FLOAT	m_outDisplacement;	//出口排量
		FLOAT	m_suspend;	//悬浮物
		UINT32	m_runTime;	//运转时间
	private:

	};



	void MainForm::ShowDevOnline(int devIndex)
	{
		if ( 1 == devIndex )
		{
			m_bDev1Online = true;
			lbl_dev1Status->Text = L"在线";
			lbl_dev1Status->ForeColor = System::Drawing::Color::Green;
		}
		else if( 2 == devIndex)
		{
			m_bDev2Online = true;
			lbl_dev2Status->Text = L"在线";
			lbl_dev2Status->ForeColor = System::Drawing::Color::Green;
		}
	}

	void MainForm::ShowDevOffLine(int devIndex)
	{
		if ( 1 == devIndex )
		{
			m_bDev1Online = false;
			lbl_dev1Status->Text = L"掉线";
			lbl_dev1Status->ForeColor = System::Drawing::Color::Red;
		}
		else if( 2 == devIndex)
		{
			m_bDev2Online = false;
			lbl_dev2Status->Text = L"掉线";
			lbl_dev2Status->ForeColor = System::Drawing::Color::Red;
		}
	}

	System::Void MainForm::btn_query_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (nullptr != m_queryForm)
		{
			m_queryForm->ShowDialog();
		}
	}

	System::Void MainForm::btn_Set_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (nullptr != m_settingForm)
		{
			m_settingForm->ShowDialog();
		}
	}
	
	System::Void MainForm::btn_help_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (nullptr != m_helpForm)
		{
			m_helpForm->ShowDialog();
		}
	}

	System::Void MainForm::btn_quit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}

	System::Void MainForm::bkg_worker_GetDevData_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		/*
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender); 
		UInt32 testData = 10000;
		CTestDatas^ testStruct = gcnew CTestDatas();

		if ( nullptr != worker )
		{
			while (true)
			{
				testData = testData*5+1;
				testStruct->a = testData;
				System::Threading::Thread::Sleep(1000);
				worker->ReportProgress(testData,testStruct);
			}
		}*/

		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender); 
		try
		{
			CDevData^ theDevData =  gcnew CDevData();
			int retStatus = -1;

			// Start LQ1000 Related service
			if (m_settingForm->GetProtoType() == t_TCP )
				retStatus = StartServiceTCP(m_settingForm->GetListeningPort());
			else if(m_settingForm->GetProtoType() == t_UDP )
				retStatus = StartServiceUDP(m_settingForm->GetListeningPort());
			else
				throw gcnew NotImplementedException();

			if (retStatus < 0)
			{
				// Show deivce 1 offline
				theDevData->m_devNum = m_settingForm->GetDev1Num();
				theDevData->m_bOnline = false;
				worker->ReportProgress(0,theDevData);

				// Show deivce 2 offline
				theDevData->m_devNum = m_settingForm->GetDev2Num();
				theDevData->m_bOnline = false;
				worker->ReportProgress(0,theDevData);

				MessageBox::Show(L"通信服务启动失败",L"通信失败",MessageBoxButtons::OK,
					MessageBoxIcon::Error,MessageBoxDefaultButton::Button1);
			}

			// Service started
			m_LQServiceStarted = true;

			UInt16 devNum = 0;
			unsigned char recvDataBuf[256] = {0};
			int dataLen = 0;
			// Start service successed,WaitFrame() in loop
			while( !worker->CancellationPending )
			{
				// Just for test.
				/*theDevData->m_devNum = 1;
				theDevData->m_bOnline = true;
				worker->ReportProgress(0,theDevData);
				Random^ testRandom = gcnew Random();
				theDevData->m_inPressure = testRandom->NextDouble() * 1000;
				theDevData->m_inDisplacement = testRandom->NextDouble() * 1000;
				theDevData->m_outPressure = testRandom->NextDouble() * 1000;
				theDevData->m_outDisplacement = testRandom->NextDouble() * 1000;
				theDevData->m_suspend = testRandom->NextDouble() * 1000;
				theDevData->m_runTime = testRandom->Next(100,50000);
				worker->ReportProgress(50,theDevData);
				System::Threading::Thread::Sleep(2 * 1000);
				theDevData->m_devNum = 1;
				theDevData->m_bOnline = false;
				worker->ReportProgress(0,theDevData);
				System::Threading::Thread::Sleep(2 * 1000);*/
				// test end

				memset(recvDataBuf,0,sizeof(recvDataBuf));
				retStatus = WaitFrame();
				if (retStatus > 0)
				{
					theDevData->m_devNum = GetDtuNum();
				}
				else
				{
					e->Cancel = true; // Service Stoped
					return; 
				}

				if (1 == retStatus || 3 == retStatus)
				{
					// device log in or got heart beat.
					theDevData->m_bOnline = true;
					worker->ReportProgress(0,theDevData);			
				}
				else if( 2 == retStatus)
				{
					// device log off.
					theDevData->m_bOnline = true;
					worker->ReportProgress(0,theDevData);
				}
				else if( 4 == retStatus)
				{
					// got device dtu serial-data.
					dataLen = GetSerialData(recvDataBuf);
					if (dataLen > 0)
					{
						// TODO: Parse the device serialData.
						//String^ str1 = Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)recvDataBuf);
						
						// Follow data just for test.
						theDevData->m_devNum = devNum;
						Random^ testRandom = gcnew Random();
						theDevData->m_inPressure = testRandom->NextDouble() * 1000;
						theDevData->m_inDisplacement = testRandom->NextDouble() * 1000;
						theDevData->m_outPressure = testRandom->NextDouble() * 1000;
						theDevData->m_outDisplacement = testRandom->NextDouble() * 1000;
						theDevData->m_suspend = testRandom->NextDouble() * 1000;
						theDevData->m_runTime = testRandom->Next(100,50000);	

						// report the data
						worker->ReportProgress(50,theDevData);
					}
				}
			}// end of while()
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message,L"异常",MessageBoxButtons::OK,
				MessageBoxIcon::Warning,MessageBoxDefaultButton::Button1);
		}
		
		e->Cancel = true;
	}

	
	System::Void MainForm::bkg_worker_GetDevData_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		CDevData^  devData = dynamic_cast<CDevData^ >(e->UserState);
		if (m_settingForm->GetDev1Num() == devData->m_devNum)
		{
			lbl_InPressure1->Text = devData->m_inPressure.ToString("F2");
			lbl_InDisplacement1->Text = devData->m_inDisplacement.ToString("F2");
			lbl_OutPressure1->Text = devData->m_outPressure.ToString("F2");
			lbl_OutDisplacement1->Text = devData->m_outDisplacement.ToString("F2");
			lbl_suspend1->Text = devData->m_suspend.ToString("F2");
			lbl_RunningTime1->Text = devData->m_runTime.ToString();
			if(devData->m_bOnline)
				ShowDevOnline(1);
			else
				ShowDevOffLine(1);
		}
		else if(  m_settingForm->GetDev2Num() == devData->m_devNum )
		{
			lbl_InPressure2->Text = devData->m_inPressure.ToString("F2");
			lbl_InDisplacement2->Text = devData->m_inDisplacement.ToString("F2");
			lbl_OutPressure2->Text = devData->m_outPressure.ToString("F2");
			lbl_OutDisplacement2->Text = devData->m_outDisplacement.ToString("F2");
			lbl_suspend2->Text = devData->m_suspend.ToString("F2");
			lbl_RunningTime2->Text = devData->m_runTime.ToString();
			if(devData->m_bOnline)
				ShowDevOnline(2);
			else
				ShowDevOffLine(2);
		}
	}
	
	System::Void MainForm::bkg_worker_GetData_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{
		if (e->Cancelled == true)
			bkg_worker_GetData->RunWorkerAsync();
        else if (e->Error != nullptr)
        {
			MessageBox::Show(e->Error->Message,L"错误",MessageBoxButtons::OK,
				MessageBoxIcon::Warning,MessageBoxDefaultButton::Button1);
        }

		m_LQServiceStarted = false;
		m_bDev1Online = false;
		m_bDev2Online = false;
	}

	System::Void MainForm::bkg_worker_SendData_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender); 
		int retStatus = -1;

		while( !worker->CancellationPending )
		{
			if ( m_LQServiceStarted )
			{
				if (m_bDev1Online && m_bDev2Online)
				{
					// TODO: edit the send command.
					unsigned char cmd[] = { 0x01, 0x03, 0x00, 0x01, 0x00, 0x02, 0x95, 0xCB };
					retStatus = SendSerialData(m_settingForm->GetDev1Num(),cmd,sizeof(cmd));
					
					if(retStatus < 0)
						worker->ReportProgress(0,m_settingForm->GetDev1Num()); //report to show device1 offline.

					retStatus = SendSerialData(m_settingForm->GetDev2Num(),cmd,sizeof(cmd));
					if (retStatus < 0)
						worker->ReportProgress(0,m_settingForm->GetDev2Num()); //report to show device2 offline.

					System::Threading::Thread::Sleep(m_settingForm->GetRefreshTime() * 1000);
					continue;
				}	
			}
			System::Threading::Thread::Sleep(1000);
		}
		e->Cancel = true;
	}

	System::Void MainForm::bkg_worker_SendData_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{
		if (e->Cancelled == true)
        {
			MessageBox::Show("即将按新的配置采集数据....",L"重新采集",MessageBoxButtons::OK,
				MessageBoxIcon::Warning,MessageBoxDefaultButton::Button1);
			
			bkg_worker_SendData->RunWorkerAsync();
        }
        else if (e->Error != nullptr)
        {
			MessageBox::Show(e->Error->Message,L"错误",MessageBoxButtons::OK,
				MessageBoxIcon::Warning,MessageBoxDefaultButton::Button1);
        }

		m_LQServiceStarted = false;
		m_bDev1Online = false;
		m_bDev2Online = false;
	}

	System::Void MainForm::bkg_worker_SendData_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		UInt16 devNum = UInt16::Parse(e->UserState->ToString());
		if (m_settingForm->GetDev1Num() == devNum)
			ShowDevOffLine(1);
		else if(  m_settingForm->GetDev2Num() == devNum )
			ShowDevOffLine(2);
	}
}