#include "StdAfx.h"
#include "LogForm.h"

namespace Rzzk 
{

	bool LogForm::DoVerifiy()
	{
		if (!System::String::Compare(tbx_usrName->Text,L"admin")
			&& !System::String::Compare(tbx_usrPwd->Text,L"admin"))
		{
			this->Visible = false;

			m_MainForm = gcnew MainForm();
			m_MainForm->ShowDialog();
			return true;
		}
		else
		{
			return false;
		}
			
	}

	System::Void LogForm::btn_login_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !DoVerifiy() )
			 System::Windows::Forms::DialogResult result = MessageBox::Show(L"ÓÃ»§Ãû»òÃÜÂë´íÎó£¡",L"µÇÂ½´íÎó",MessageBoxButtons::RetryCancel,
				MessageBoxIcon::Error,MessageBoxDefaultButton::Button2);		
	}

	System::Void LogForm::btn_exit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
}