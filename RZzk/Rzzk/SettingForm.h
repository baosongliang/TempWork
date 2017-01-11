#pragma once

namespace Rzzk {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	typedef enum _TheProtoType
	{
		t_Unkown = 0,
		t_TCP = 1,
		t_UDP = 2,
	}TheProtoType;


	/// <summary>
	/// Summary for SettingForm
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
	public:
		SettingForm(Form^ form)
			: m_protoType(t_TCP)
			,m_listeningPort(9970)
			,m_Dev2Num(2)
			,m_Dev1Num(1)
			,m_RefreshTime(5)
		{
			m_MainForm = form;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		/*SettingForm(Form^ form)
		{
			m_MainForm = form;
			SettingForm();
		}*/

		TheProtoType GetProtoType();

		UInt16 GetListeningPort();

		UInt16 GetDev1Num();

		UInt16 GetDev2Num();

		UInt16 GetRefreshTime();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cmbBox_protoType;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbx_ListeningPort;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbx_DevNum1;
	private: System::Windows::Forms::TextBox^  tbx_DevNum2;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbx_RefreshTime;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  btn_ChangeSetting;


	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbBox_protoType = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbx_ListeningPort = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbx_DevNum1 = (gcnew System::Windows::Forms::TextBox());
			this->tbx_DevNum2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbx_RefreshTime = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btn_ChangeSetting = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(40, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"协议：";
			// 
			// cmbBox_protoType
			// 
			this->cmbBox_protoType->FormattingEnabled = true;
			this->cmbBox_protoType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"TCP", L"UDP"});
			this->cmbBox_protoType->Location = System::Drawing::Point(95, 26);
			this->cmbBox_protoType->Name = L"cmbBox_protoType";
			this->cmbBox_protoType->Size = System::Drawing::Size(64, 20);
			this->cmbBox_protoType->TabIndex = 1;
			this->cmbBox_protoType->SelectedIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(12, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 14);
			this->label2->TabIndex = 2;
			this->label2->Text = L"监听端口：";
			// 
			// tbx_ListeningPort
			// 
			this->tbx_ListeningPort->Location = System::Drawing::Point(95, 63);
			this->tbx_ListeningPort->MaxLength = 5;
			this->tbx_ListeningPort->Name = L"tbx_ListeningPort";
			this->tbx_ListeningPort->Size = System::Drawing::Size(64, 21);
			this->tbx_ListeningPort->TabIndex = 3;
			this->tbx_ListeningPort->Text = L"9970";
			this->tbx_ListeningPort->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SettingForm::tbx_ListeningPort_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(5, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 14);
			this->label3->TabIndex = 4;
			this->label3->Text = L"设备1编号：";
			// 
			// tbx_DevNum1
			// 
			this->tbx_DevNum1->Location = System::Drawing::Point(95, 100);
			this->tbx_DevNum1->MaxLength = 4;
			this->tbx_DevNum1->Name = L"tbx_DevNum1";
			this->tbx_DevNum1->Size = System::Drawing::Size(64, 21);
			this->tbx_DevNum1->TabIndex = 5;
			this->tbx_DevNum1->Text = L"1";
			this->tbx_DevNum1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SettingForm::tbx_DevNum1_KeyPress);
			// 
			// tbx_DevNum2
			// 
			this->tbx_DevNum2->Location = System::Drawing::Point(95, 137);
			this->tbx_DevNum2->MaxLength = 4;
			this->tbx_DevNum2->Name = L"tbx_DevNum2";
			this->tbx_DevNum2->Size = System::Drawing::Size(64, 21);
			this->tbx_DevNum2->TabIndex = 7;
			this->tbx_DevNum2->Text = L"2";
			this->tbx_DevNum2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SettingForm::tbx_DevNum2_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(5, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 14);
			this->label4->TabIndex = 6;
			this->label4->Text = L"设备2编号：";
			// 
			// tbx_RefreshTime
			// 
			this->tbx_RefreshTime->Location = System::Drawing::Point(95, 173);
			this->tbx_RefreshTime->MaxLength = 6;
			this->tbx_RefreshTime->Name = L"tbx_RefreshTime";
			this->tbx_RefreshTime->Size = System::Drawing::Size(64, 21);
			this->tbx_RefreshTime->TabIndex = 9;
			this->tbx_RefreshTime->Text = L"5";
			this->tbx_RefreshTime->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SettingForm::tbx_RefreshTime_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(12, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 14);
			this->label5->TabIndex = 8;
			this->label5->Text = L"刷新时间：";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(164, 176);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 14);
			this->label6->TabIndex = 10;
			this->label6->Text = L"s";
			// 
			// btn_ChangeSetting
			// 
			this->btn_ChangeSetting->Location = System::Drawing::Point(65, 220);
			this->btn_ChangeSetting->Name = L"btn_ChangeSetting";
			this->btn_ChangeSetting->Size = System::Drawing::Size(63, 29);
			this->btn_ChangeSetting->TabIndex = 11;
			this->btn_ChangeSetting->Text = L"更改";
			this->btn_ChangeSetting->UseVisualStyleBackColor = true;
			this->btn_ChangeSetting->Click += gcnew System::EventHandler(this, &SettingForm::btn_ChangeSetting_Click);
			// 
			// SettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(208, 261);
			this->Controls->Add(this->btn_ChangeSetting);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbx_RefreshTime);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tbx_DevNum2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbx_DevNum1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbx_ListeningPort);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cmbBox_protoType);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MinimizeBox = false;
			this->Name = L"SettingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"设置";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private:
		TheProtoType m_protoType;
		UInt16 m_listeningPort;
		UInt16 m_Dev1Num;
		UInt16 m_Dev2Num;
		UInt16 m_RefreshTime;
		Form^	m_MainForm;
	private:
		// Check weather input is a number.
		void InputNumberCheck(System::Windows::Forms::KeyPressEventArgs^  e);
	private: 
		// All events
		System::Void btn_ChangeSetting_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void tbx_ListeningPort_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
		System::Void tbx_DevNum1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) ;
		System::Void tbx_DevNum2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) ;
		System::Void tbx_RefreshTime_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
};
}
