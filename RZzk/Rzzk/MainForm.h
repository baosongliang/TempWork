#pragma once

#include "QueryForm.h"
#include "SettingForm.h"
#include "HelpForm.h"

namespace Rzzk {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
			: m_helpForm(nullptr)
			, m_queryForm(nullptr)
			, m_settingForm(nullptr)
			, m_LQServiceStarted(false)
			, m_bDev1Online(false)
			, m_bDev2Online(false)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
			m_queryForm = gcnew QueryForm();
			m_settingForm = gcnew SettingForm(this);
			m_helpForm = gcnew HelpForm();
			
			InitializeBackgroundWorker();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btn_query;
	private: System::Windows::Forms::Button^  btn_Set;
	private: System::Windows::Forms::Button^  btn_help;
	private: System::Windows::Forms::Button^  btn_quit;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_dev1Status;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lbl_InPressure1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lbl_InDisplacement1;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  lbl_OutDisplacement1;



	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  lbl_OutPressure1;


	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  lbl_RunningTime1;



	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  lbl_suspend1;



	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  lbl_RunningTime2;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  lbl_suspend2;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  lbl_OutDisplacement2;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  lbl_OutPressure2;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  lbl_InDisplacement2;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  lbl_InPressure2;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  lbl_dev2Status;
	private: System::Windows::Forms::Label^  label34;	
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label19;
	public: System::ComponentModel::BackgroundWorker^  bkg_worker_GetData;
	public: System::ComponentModel::BackgroundWorker^  bkg_worker_SendData;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		QueryForm		^m_queryForm;
		SettingForm		^m_settingForm;
		HelpForm		^m_helpForm;
		bool			m_LQServiceStarted;
		bool			m_bDev1Online;
		bool			m_bDev2Online;
		 void InitializeBackgroundWorker()
		 {
			// Start the asynchronous operation.
			 bkg_worker_GetData->RunWorkerAsync();
			 bkg_worker_SendData->RunWorkerAsync();
		 }

		 void ShowDevOnline(int devIndex);

		 void ShowDevOffLine(int devIndex);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_query = (gcnew System::Windows::Forms::Button());
			this->btn_Set = (gcnew System::Windows::Forms::Button());
			this->btn_help = (gcnew System::Windows::Forms::Button());
			this->btn_quit = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_dev1Status = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbl_InPressure1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbl_InDisplacement1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbl_OutDisplacement1 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_OutPressure1 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lbl_RunningTime1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lbl_suspend1 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lbl_RunningTime2 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->lbl_suspend2 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->lbl_OutDisplacement2 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->lbl_OutPressure2 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->lbl_InDisplacement2 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->lbl_InPressure2 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->lbl_dev2Status = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->bkg_worker_GetData = (gcnew System::ComponentModel::BackgroundWorker());
			this->bkg_worker_SendData = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(645, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(123, 114);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(312, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 27);
			this->label1->TabIndex = 1;
			this->label1->Text = L"在线监测";
			// 
			// btn_query
			// 
			this->btn_query->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_query->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btn_query->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_query->Location = System::Drawing::Point(51, 90);
			this->btn_query->Name = L"btn_query";
			this->btn_query->Size = System::Drawing::Size(69, 28);
			this->btn_query->TabIndex = 2;
			this->btn_query->Text = L"查询";
			this->btn_query->UseVisualStyleBackColor = true;
			this->btn_query->Click += gcnew System::EventHandler(this, &MainForm::btn_query_Click);
			// 
			// btn_Set
			// 
			this->btn_Set->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_Set->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btn_Set->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_Set->Location = System::Drawing::Point(155, 90);
			this->btn_Set->Name = L"btn_Set";
			this->btn_Set->Size = System::Drawing::Size(69, 28);
			this->btn_Set->TabIndex = 3;
			this->btn_Set->Text = L"设置";
			this->btn_Set->UseVisualStyleBackColor = true;
			this->btn_Set->Click += gcnew System::EventHandler(this, &MainForm::btn_Set_Click);
			// 
			// btn_help
			// 
			this->btn_help->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_help->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btn_help->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_help->Location = System::Drawing::Point(258, 90);
			this->btn_help->Name = L"btn_help";
			this->btn_help->Size = System::Drawing::Size(69, 28);
			this->btn_help->TabIndex = 4;
			this->btn_help->Text = L"帮助";
			this->btn_help->UseVisualStyleBackColor = true;
			this->btn_help->Click += gcnew System::EventHandler(this, &MainForm::btn_help_Click);
			// 
			// btn_quit
			// 
			this->btn_quit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_quit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btn_quit->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_quit->Location = System::Drawing::Point(503, 90);
			this->btn_quit->Name = L"btn_quit";
			this->btn_quit->Size = System::Drawing::Size(69, 28);
			this->btn_quit->TabIndex = 5;
			this->btn_quit->Text = L"退出";
			this->btn_quit->UseVisualStyleBackColor = true;
			this->btn_quit->Click += gcnew System::EventHandler(this, &MainForm::btn_quit_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label2->Location = System::Drawing::Point(35, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"设备一";
			// 
			// lbl_dev1Status
			// 
			this->lbl_dev1Status->AutoSize = true;
			this->lbl_dev1Status->Font = (gcnew System::Drawing::Font(L"LiSu", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_dev1Status->ForeColor = System::Drawing::Color::Red;
			this->lbl_dev1Status->Location = System::Drawing::Point(124, 159);
			this->lbl_dev1Status->Name = L"lbl_dev1Status";
			this->lbl_dev1Status->Size = System::Drawing::Size(51, 19);
			this->lbl_dev1Status->TabIndex = 7;
			this->lbl_dev1Status->Text = L"掉线";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(17, 219);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"进口压力：";
			// 
			// lbl_InPressure1
			// 
			this->lbl_InPressure1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_InPressure1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_InPressure1->Location = System::Drawing::Point(89, 219);
			this->lbl_InPressure1->Name = L"lbl_InPressure1";
			this->lbl_InPressure1->Size = System::Drawing::Size(54, 16);
			this->lbl_InPressure1->TabIndex = 10;
			this->lbl_InPressure1->Text = L"0";
			this->lbl_InPressure1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(149, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"MP";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(312, 219);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"M³/h";
			// 
			// lbl_InDisplacement1
			// 
			this->lbl_InDisplacement1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_InDisplacement1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_InDisplacement1->Location = System::Drawing::Point(260, 219);
			this->lbl_InDisplacement1->Name = L"lbl_InDisplacement1";
			this->lbl_InDisplacement1->Size = System::Drawing::Size(54, 16);
			this->lbl_InDisplacement1->TabIndex = 13;
			this->lbl_InDisplacement1->Text = L"0";
			this->lbl_InDisplacement1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(189, 219);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"进口排量：";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(312, 284);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"M³/h";
			// 
			// lbl_OutDisplacement1
			// 
			this->lbl_OutDisplacement1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_OutDisplacement1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_OutDisplacement1->Location = System::Drawing::Point(260, 284);
			this->lbl_OutDisplacement1->Name = L"lbl_OutDisplacement1";
			this->lbl_OutDisplacement1->Size = System::Drawing::Size(54, 16);
			this->lbl_OutDisplacement1->TabIndex = 19;
			this->lbl_OutDisplacement1->Text = L"0";
			this->lbl_OutDisplacement1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label10->Location = System::Drawing::Point(189, 284);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 16);
			this->label10->TabIndex = 18;
			this->label10->Text = L"出口排量：";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label11->Location = System::Drawing::Point(149, 284);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(24, 16);
			this->label11->TabIndex = 17;
			this->label11->Text = L"MP";
			// 
			// lbl_OutPressure1
			// 
			this->lbl_OutPressure1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_OutPressure1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_OutPressure1->Location = System::Drawing::Point(89, 284);
			this->lbl_OutPressure1->Name = L"lbl_OutPressure1";
			this->lbl_OutPressure1->Size = System::Drawing::Size(54, 16);
			this->lbl_OutPressure1->TabIndex = 16;
			this->lbl_OutPressure1->Text = L"0";
			this->lbl_OutPressure1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label13->Location = System::Drawing::Point(17, 284);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(88, 16);
			this->label13->TabIndex = 15;
			this->label13->Text = L"出口压力：";
			// 
			// lbl_RunningTime1
			// 
			this->lbl_RunningTime1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_RunningTime1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_RunningTime1->Location = System::Drawing::Point(260, 349);
			this->lbl_RunningTime1->Name = L"lbl_RunningTime1";
			this->lbl_RunningTime1->Size = System::Drawing::Size(54, 16);
			this->lbl_RunningTime1->TabIndex = 25;
			this->lbl_RunningTime1->Text = L"0";
			this->lbl_RunningTime1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label12->Location = System::Drawing::Point(189, 349);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(88, 16);
			this->label12->TabIndex = 24;
			this->label12->Text = L"运转时间：";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label14->Location = System::Drawing::Point(149, 349);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(40, 16);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Mg/L";
			// 
			// lbl_suspend1
			// 
			this->lbl_suspend1->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_suspend1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_suspend1->Location = System::Drawing::Point(89, 349);
			this->lbl_suspend1->Name = L"lbl_suspend1";
			this->lbl_suspend1->Size = System::Drawing::Size(54, 16);
			this->lbl_suspend1->TabIndex = 22;
			this->lbl_suspend1->Text = L"0";
			this->lbl_suspend1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label16->Location = System::Drawing::Point(22, 349);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(72, 16);
			this->label16->TabIndex = 21;
			this->label16->Text = L"悬浮物：";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(312, 349);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 16);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Min";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(709, 349);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 16);
			this->label9->TabIndex = 44;
			this->label9->Text = L"Min";
			// 
			// lbl_RunningTime2
			// 
			this->lbl_RunningTime2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_RunningTime2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_RunningTime2->Location = System::Drawing::Point(657, 349);
			this->lbl_RunningTime2->Name = L"lbl_RunningTime2";
			this->lbl_RunningTime2->Size = System::Drawing::Size(54, 16);
			this->lbl_RunningTime2->TabIndex = 43;
			this->lbl_RunningTime2->Text = L"0";
			this->lbl_RunningTime2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label17->Location = System::Drawing::Point(586, 349);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(88, 16);
			this->label17->TabIndex = 42;
			this->label17->Text = L"运转时间：";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label18->Location = System::Drawing::Point(546, 349);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(40, 16);
			this->label18->TabIndex = 41;
			this->label18->Text = L"Mg/L";
			// 
			// lbl_suspend2
			// 
			this->lbl_suspend2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_suspend2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_suspend2->Location = System::Drawing::Point(486, 349);
			this->lbl_suspend2->Name = L"lbl_suspend2";
			this->lbl_suspend2->Size = System::Drawing::Size(54, 16);
			this->lbl_suspend2->TabIndex = 40;
			this->lbl_suspend2->Text = L"0";
			this->lbl_suspend2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label20->Location = System::Drawing::Point(419, 349);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(72, 16);
			this->label20->TabIndex = 39;
			this->label20->Text = L"悬浮物：";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label21->Location = System::Drawing::Point(709, 284);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(36, 16);
			this->label21->TabIndex = 38;
			this->label21->Text = L"M³/h";
			// 
			// lbl_OutDisplacement2
			// 
			this->lbl_OutDisplacement2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_OutDisplacement2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_OutDisplacement2->Location = System::Drawing::Point(657, 284);
			this->lbl_OutDisplacement2->Name = L"lbl_OutDisplacement2";
			this->lbl_OutDisplacement2->Size = System::Drawing::Size(54, 16);
			this->lbl_OutDisplacement2->TabIndex = 37;
			this->lbl_OutDisplacement2->Text = L"0";
			this->lbl_OutDisplacement2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label23->Location = System::Drawing::Point(586, 284);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(88, 16);
			this->label23->TabIndex = 36;
			this->label23->Text = L"出口排量：";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label24->Location = System::Drawing::Point(546, 284);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(24, 16);
			this->label24->TabIndex = 35;
			this->label24->Text = L"MP";
			// 
			// lbl_OutPressure2
			// 
			this->lbl_OutPressure2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_OutPressure2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_OutPressure2->Location = System::Drawing::Point(486, 284);
			this->lbl_OutPressure2->Name = L"lbl_OutPressure2";
			this->lbl_OutPressure2->Size = System::Drawing::Size(54, 16);
			this->lbl_OutPressure2->TabIndex = 34;
			this->lbl_OutPressure2->Text = L"0";
			this->lbl_OutPressure2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label26->Location = System::Drawing::Point(414, 284);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(88, 16);
			this->label26->TabIndex = 33;
			this->label26->Text = L"出口压力：";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label27->Location = System::Drawing::Point(709, 219);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(36, 16);
			this->label27->TabIndex = 32;
			this->label27->Text = L"M³/h";
			// 
			// lbl_InDisplacement2
			// 
			this->lbl_InDisplacement2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_InDisplacement2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_InDisplacement2->Location = System::Drawing::Point(657, 219);
			this->lbl_InDisplacement2->Name = L"lbl_InDisplacement2";
			this->lbl_InDisplacement2->Size = System::Drawing::Size(54, 16);
			this->lbl_InDisplacement2->TabIndex = 31;
			this->lbl_InDisplacement2->Text = L"0";
			this->lbl_InDisplacement2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label29->Location = System::Drawing::Point(586, 219);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(88, 16);
			this->label29->TabIndex = 30;
			this->label29->Text = L"进口排量：";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label30->Location = System::Drawing::Point(546, 219);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(24, 16);
			this->label30->TabIndex = 29;
			this->label30->Text = L"MP";
			// 
			// lbl_InPressure2
			// 
			this->lbl_InPressure2->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_InPressure2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_InPressure2->Location = System::Drawing::Point(486, 219);
			this->lbl_InPressure2->Name = L"lbl_InPressure2";
			this->lbl_InPressure2->Size = System::Drawing::Size(54, 16);
			this->lbl_InPressure2->TabIndex = 28;
			this->lbl_InPressure2->Text = L"0";
			this->lbl_InPressure2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"KaiTi", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label32->Location = System::Drawing::Point(414, 219);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(88, 16);
			this->label32->TabIndex = 27;
			this->label32->Text = L"进口压力：";
			// 
			// lbl_dev2Status
			// 
			this->lbl_dev2Status->AutoSize = true;
			this->lbl_dev2Status->Font = (gcnew System::Drawing::Font(L"LiSu", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->lbl_dev2Status->ForeColor = System::Drawing::Color::Red;
			this->lbl_dev2Status->Location = System::Drawing::Point(510, 159);
			this->lbl_dev2Status->Name = L"lbl_dev2Status";
			this->lbl_dev2Status->Size = System::Drawing::Size(51, 19);
			this->lbl_dev2Status->TabIndex = 46;
			this->lbl_dev2Status->Text = L"掉线";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label34->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label34->Location = System::Drawing::Point(419, 159);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(59, 16);
			this->label34->TabIndex = 45;
			this->label34->Text = L"设备二";
			// 
			// label15
			// 
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label15->Location = System::Drawing::Point(0, 135);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(789, 2);
			this->label15->TabIndex = 47;
			// 
			// label19
			// 
			this->label19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label19->Location = System::Drawing::Point(368, 135);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(2, 285);
			this->label19->TabIndex = 48;
			// 
			// bkg_worker_GetData
			// 
			this->bkg_worker_GetData->WorkerReportsProgress = true;
			this->bkg_worker_GetData->WorkerSupportsCancellation = true;
			this->bkg_worker_GetData->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::bkg_worker_GetDevData_DoWork);
			this->bkg_worker_GetData->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::bkg_worker_GetDevData_ProgressChanged);
			this->bkg_worker_GetData->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::bkg_worker_GetData_RunWorkerCompleted);
			// 
			// bkg_worker_SendData
			// 
			this->bkg_worker_SendData->WorkerReportsProgress = true;
			this->bkg_worker_SendData->WorkerSupportsCancellation = true;
			this->bkg_worker_SendData->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::bkg_worker_SendData_DoWork);
			this->bkg_worker_SendData->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::bkg_worker_SendData_ProgressChanged);
			this->bkg_worker_SendData->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::bkg_worker_SendData_RunWorkerCompleted);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(790, 419);
			this->Controls->Add(this->lbl_RunningTime2);
			this->Controls->Add(this->lbl_suspend2);
			this->Controls->Add(this->lbl_OutDisplacement2);
			this->Controls->Add(this->lbl_OutPressure2);
			this->Controls->Add(this->lbl_InDisplacement2);
			this->Controls->Add(this->lbl_InPressure2);
			this->Controls->Add(this->lbl_RunningTime1);
			this->Controls->Add(this->lbl_suspend1);
			this->Controls->Add(this->lbl_OutDisplacement1);
			this->Controls->Add(this->lbl_OutPressure1);
			this->Controls->Add(this->lbl_InDisplacement1);
			this->Controls->Add(this->lbl_InPressure1);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->lbl_dev2Status);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lbl_dev1Status);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_quit);
			this->Controls->Add(this->btn_help);
			this->Controls->Add(this->btn_Set);
			this->Controls->Add(this->btn_query);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"在线监测程序";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: 
			System::Void btn_query_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void btn_Set_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void btn_help_Click(System::Object^  sender, System::EventArgs^  e);
			System::Void btn_quit_Click(System::Object^  sender, System::EventArgs^  e);
			
			// This event handler is where the data-collection work is done.
			System::Void bkg_worker_GetDevData_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
			System::Void bkg_worker_GetDevData_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
			System::Void bkg_worker_GetData_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
			
			// This event handler is where the send serialdata done.
			System::Void bkg_worker_SendData_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
			System::Void bkg_worker_SendData_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
			System::Void bkg_worker_SendData_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
};
}

