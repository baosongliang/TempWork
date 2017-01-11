#include "stdafx.h"
#include "SettingForm.h"
#include "MainForm.h"
#include "LQ1000.h"

namespace Rzzk
{
	TheProtoType SettingForm::GetProtoType()
	{
		return m_protoType;
	}

	UInt16 SettingForm::GetListeningPort()
	{
		return m_listeningPort;
	}
	UInt16 SettingForm::GetDev1Num()
	{
		return m_Dev1Num;
	}
	UInt16 SettingForm::GetDev2Num()
	{
		return m_Dev2Num;
	}
	UInt16 SettingForm::GetRefreshTime()
	{
		return m_RefreshTime;
	}

	//////////////////////////////////////////////////////////////////////////////
	// Events
	System::Void SettingForm::btn_ChangeSetting_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			// Store the protocol type.
			Object^ protoType  = this->cmbBox_protoType->SelectedItem;
			if( protoType->ToString()->Equals(L"TCP") )
				m_protoType = t_TCP;
			else
				m_protoType = t_UDP;

			// Store the listening port.
			m_listeningPort = System::Convert::ToUInt16(tbx_ListeningPort->Text);

			// Store dev1 number.
			m_Dev1Num = System::Convert::ToUInt16(tbx_DevNum1->Text);
			if (m_Dev1Num < 1 || m_Dev1Num > 9999)
			{
				MessageBox::Show(L"设备编号范围为1~9999",L"输入错误",MessageBoxButtons::OK,
					MessageBoxIcon::Error,MessageBoxDefaultButton::Button1);

				return;
			}

			// Store dev2 number.
			m_Dev2Num = System::Convert::ToUInt16(tbx_DevNum2->Text);
			if (m_Dev2Num < 1 || m_Dev2Num > 9999)
			{
				MessageBox::Show(L"设备编号范围为1~9999",L"输入错误",MessageBoxButtons::OK,
					MessageBoxIcon::Error,MessageBoxDefaultButton::Button1);

				return;
			}

			// Store the refresh time.
			m_RefreshTime = System::Convert::ToUInt16(tbx_RefreshTime->Text);

			MessageBox::Show(L"更改成功！",L"成功",MessageBoxButtons::OK,
				MessageBoxIcon::Information,MessageBoxDefaultButton::Button1);

			this->Visible = false;

			MainForm^ theMainForm = dynamic_cast<MainForm^>(m_MainForm);
			if (theMainForm != nullptr)
			{
				StopService(); // Stop the LQ1000 Service
				theMainForm->bkg_worker_GetData->CancelAsync();
				theMainForm->bkg_worker_SendData->CancelAsync();
			}
		}
		catch(Exception^ e)
		{
			MessageBox::Show(e->ToString(),L"错误",MessageBoxButtons::OK,
					MessageBoxIcon::Error,MessageBoxDefaultButton::Button1);
		}
	}

	void SettingForm::InputNumberCheck(System::Windows::Forms::KeyPressEventArgs^  e)
	{
		// Check weather input a number,'\b' is the 'Backspace'
		if ( !(Char::IsDigit(e->KeyChar)) && e->KeyChar != L'\b' )
			e->Handled = true; 
	}

	System::Void SettingForm::tbx_ListeningPort_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		// Check weather input a number
		InputNumberCheck(e);
	}
	System::Void SettingForm::tbx_DevNum1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		InputNumberCheck(e);
	}
	System::Void SettingForm::tbx_DevNum2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		InputNumberCheck(e);
	}
	System::Void SettingForm::tbx_RefreshTime_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		InputNumberCheck(e);
	}
}
