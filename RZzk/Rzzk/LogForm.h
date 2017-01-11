#pragma once

#include "MainForm.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Rzzk {

	/// <summary>
	/// Summary for LogForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class LogForm : public System::Windows::Forms::Form
	{
	public:
		LogForm(void)
			:m_MainForm(nullptr)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		bool DoVerifiy();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btn_login;

	private: System::Windows::Forms::TextBox^  tbx_usrName;
	private: System::Windows::Forms::TextBox^  tbx_usrPwd;
	private: System::Windows::Forms::Button^  btn_exit;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		MainForm^ m_MainForm;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_login = (gcnew System::Windows::Forms::Button());
			this->tbx_usrName = (gcnew System::Windows::Forms::TextBox());
			this->tbx_usrPwd = (gcnew System::Windows::Forms::TextBox());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(60, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ÓÃ»§Ãû£º";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(76, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ÃÜÂë£º";
			// 
			// btn_login
			// 
			this->btn_login->Location = System::Drawing::Point(79, 140);
			this->btn_login->Name = L"btn_login";
			this->btn_login->Size = System::Drawing::Size(75, 23);
			this->btn_login->TabIndex = 2;
			this->btn_login->Text = L"µÇÂ½";
			this->btn_login->UseVisualStyleBackColor = true;
			this->btn_login->Click += gcnew System::EventHandler(this, &LogForm::btn_login_Click);
			// 
			// tbx_usrName
			// 
			this->tbx_usrName->Location = System::Drawing::Point(138, 50);
			this->tbx_usrName->Name = L"tbx_usrName";
			this->tbx_usrName->Size = System::Drawing::Size(128, 21);
			this->tbx_usrName->TabIndex = 4;
			// 
			// tbx_usrPwd
			// 
			this->tbx_usrPwd->Location = System::Drawing::Point(138, 92);
			this->tbx_usrPwd->Name = L"tbx_usrPwd";
			this->tbx_usrPwd->PasswordChar = '*';
			this->tbx_usrPwd->Size = System::Drawing::Size(128, 21);
			this->tbx_usrPwd->TabIndex = 5;
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(227, 140);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(75, 23);
			this->btn_exit->TabIndex = 6;
			this->btn_exit->Text = L"ÍË³ö";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &LogForm::btn_exit_Click);
			// 
			// LogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 186);
			this->ControlBox = false;
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->tbx_usrPwd);
			this->Controls->Add(this->tbx_usrName);
			this->Controls->Add(this->btn_login);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LogForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"µÇÂ½";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn_login_Click(System::Object^  sender, System::EventArgs^  e);
};
}
