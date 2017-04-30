#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
//#include "C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.5.2\PresentationCore.dll"

namespace Calculator_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	CalculatorLib Calculate;
	myTypes::notation SelectedType = myTypes::Dec;
	long double PreviousAnswer = 0;
	std::string PreviousCalc = "";

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();

			/*Uri iconUri = new Uri("pack://application:,,,/Calculator-icon.ico", UriKind.RelativeOrAbsolute);
			this.Icon = BitmapFrame.Create(iconUri);*/
			//this->Icon = gcnew System::Drawing::Icon("Resources\\Calculator-icon.ico");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_7;

	private: System::Windows::Forms::TextBox^  resultBox;
	protected:
	//public:
	//	property System::Windows::ImageSource^ Icon {
	//		System::Windows::ImageSource^ get();
	//		[SecurityCriticalAttribute]
	//		void set(System::Windows::ImageSource^ value);
	//	}

	// array<String^>^ text = System::Reflection::Assembly::GetExecutingAssembly()->GetManifestResourceNames();

	private: System::Windows::Forms::Button^  button_8;
	private: System::Windows::Forms::Button^  button_9;
	private: System::Windows::Forms::Button^  button_4;
	private: System::Windows::Forms::Button^  button_5;
	private: System::Windows::Forms::Button^  button_6;
	private: System::Windows::Forms::Button^  button_1;
	private: System::Windows::Forms::Button^  button_2;
	private: System::Windows::Forms::Button^  button_3;
	private: System::Windows::Forms::Button^  button_0;
	private: System::Windows::Forms::Button^  button_dot;
	private: System::Windows::Forms::Button^  button_equals;
	private: System::Windows::Forms::Button^  button_divide;

	private: System::Windows::Forms::Button^  button_multiply;

	private: System::Windows::Forms::Button^  button_minus;

	private: System::Windows::Forms::Button^  button_add;
	private: System::Windows::Forms::Button^  button_delete;



	private: System::Windows::Forms::Button^  button_clear;
	private: System::Windows::Forms::Button^  button_sin;
	private: System::Windows::Forms::Button^  button_cos;
	private: System::Windows::Forms::Button^  button_tan;




	private: System::Windows::Forms::Button^  button_ans;
	private: System::Windows::Forms::Button^  button_power;

	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::Button^  button_invert;
	private: System::Windows::Forms::Button^  button_Dec;
	private: System::Windows::Forms::Button^  button_Sci;
	private: System::Windows::Forms::Button^  button_Eng;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;





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
			this->button_7 = (gcnew System::Windows::Forms::Button());
			this->resultBox = (gcnew System::Windows::Forms::TextBox());
			this->button_8 = (gcnew System::Windows::Forms::Button());
			this->button_9 = (gcnew System::Windows::Forms::Button());
			this->button_4 = (gcnew System::Windows::Forms::Button());
			this->button_5 = (gcnew System::Windows::Forms::Button());
			this->button_6 = (gcnew System::Windows::Forms::Button());
			this->button_1 = (gcnew System::Windows::Forms::Button());
			this->button_2 = (gcnew System::Windows::Forms::Button());
			this->button_3 = (gcnew System::Windows::Forms::Button());
			this->button_0 = (gcnew System::Windows::Forms::Button());
			this->button_dot = (gcnew System::Windows::Forms::Button());
			this->button_equals = (gcnew System::Windows::Forms::Button());
			this->button_divide = (gcnew System::Windows::Forms::Button());
			this->button_multiply = (gcnew System::Windows::Forms::Button());
			this->button_minus = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_cos = (gcnew System::Windows::Forms::Button());
			this->button_tan = (gcnew System::Windows::Forms::Button());
			this->button_ans = (gcnew System::Windows::Forms::Button());
			this->button_power = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->button_invert = (gcnew System::Windows::Forms::Button());
			this->button_Dec = (gcnew System::Windows::Forms::Button());
			this->button_Sci = (gcnew System::Windows::Forms::Button());
			this->button_Eng = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_7
			// 
			this->button_7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_7->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_7->Location = System::Drawing::Point(26, 253);
			this->button_7->Name = L"button_7";
			this->button_7->Size = System::Drawing::Size(90, 30);
			this->button_7->TabIndex = 1;
			this->button_7->Text = L"7";
			this->button_7->UseVisualStyleBackColor = false;
			this->button_7->Click += gcnew System::EventHandler(this, &GUI::button_7_Click);
			// 
			// resultBox
			// 
			this->resultBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->resultBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultBox->Location = System::Drawing::Point(87, 101);
			this->resultBox->Name = L"resultBox";
			this->resultBox->ReadOnly = true;
			this->resultBox->Size = System::Drawing::Size(245, 27);
			this->resultBox->TabIndex = 2;
			this->resultBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button_8
			// 
			this->button_8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_8->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_8->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_8->Location = System::Drawing::Point(134, 253);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(90, 30);
			this->button_8->TabIndex = 3;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = false;
			this->button_8->Click += gcnew System::EventHandler(this, &GUI::button_8_Click);
			// 
			// button_9
			// 
			this->button_9->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_9->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_9->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_9->Location = System::Drawing::Point(242, 253);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(90, 30);
			this->button_9->TabIndex = 4;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = false;
			this->button_9->Click += gcnew System::EventHandler(this, &GUI::button_9_Click);
			// 
			// button_4
			// 
			this->button_4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_4->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_4->Location = System::Drawing::Point(26, 301);
			this->button_4->Name = L"button_4";
			this->button_4->Size = System::Drawing::Size(90, 30);
			this->button_4->TabIndex = 5;
			this->button_4->Text = L"4";
			this->button_4->UseVisualStyleBackColor = false;
			this->button_4->Click += gcnew System::EventHandler(this, &GUI::button_4_Click);
			// 
			// button_5
			// 
			this->button_5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_5->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_5->Location = System::Drawing::Point(134, 301);
			this->button_5->Name = L"button_5";
			this->button_5->Size = System::Drawing::Size(90, 30);
			this->button_5->TabIndex = 6;
			this->button_5->Text = L"5";
			this->button_5->UseVisualStyleBackColor = false;
			this->button_5->Click += gcnew System::EventHandler(this, &GUI::button_5_Click);
			// 
			// button_6
			// 
			this->button_6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_6->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_6->Location = System::Drawing::Point(242, 301);
			this->button_6->Name = L"button_6";
			this->button_6->Size = System::Drawing::Size(90, 30);
			this->button_6->TabIndex = 7;
			this->button_6->Text = L"6";
			this->button_6->UseVisualStyleBackColor = false;
			this->button_6->Click += gcnew System::EventHandler(this, &GUI::button_6_Click);
			// 
			// button_1
			// 
			this->button_1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_1->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_1->Location = System::Drawing::Point(26, 347);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(90, 30);
			this->button_1->TabIndex = 8;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = false;
			this->button_1->Click += gcnew System::EventHandler(this, &GUI::button_1_Click);
			// 
			// button_2
			// 
			this->button_2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_2->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_2->Location = System::Drawing::Point(134, 347);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(90, 30);
			this->button_2->TabIndex = 9;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = false;
			this->button_2->Click += gcnew System::EventHandler(this, &GUI::button_2_Click);
			// 
			// button_3
			// 
			this->button_3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_3->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_3->Location = System::Drawing::Point(242, 347);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(90, 30);
			this->button_3->TabIndex = 10;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = false;
			this->button_3->Click += gcnew System::EventHandler(this, &GUI::button_3_Click);
			// 
			// button_0
			// 
			this->button_0->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_0->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_0->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_0->Location = System::Drawing::Point(134, 396);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(90, 30);
			this->button_0->TabIndex = 11;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = false;
			this->button_0->Click += gcnew System::EventHandler(this, &GUI::button_0_Click);
			// 
			// button_dot
			// 
			this->button_dot->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_dot->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_dot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_dot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dot->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_dot->Location = System::Drawing::Point(26, 396);
			this->button_dot->Name = L"button_dot";
			this->button_dot->Size = System::Drawing::Size(90, 30);
			this->button_dot->TabIndex = 12;
			this->button_dot->Text = L"•";
			this->button_dot->UseVisualStyleBackColor = false;
			this->button_dot->Click += gcnew System::EventHandler(this, &GUI::button_dot_Click);
			// 
			// button_equals
			// 
			this->button_equals->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_equals->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_equals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_equals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_equals->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_equals->Location = System::Drawing::Point(242, 396);
			this->button_equals->Name = L"button_equals";
			this->button_equals->Size = System::Drawing::Size(90, 30);
			this->button_equals->TabIndex = 13;
			this->button_equals->Text = L"=";
			this->button_equals->UseVisualStyleBackColor = false;
			this->button_equals->Click += gcnew System::EventHandler(this, &GUI::button_equals_Click);
			// 
			// button_divide
			// 
			this->button_divide->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_divide->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_divide->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_divide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_divide->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_divide->Location = System::Drawing::Point(378, 253);
			this->button_divide->Name = L"button_divide";
			this->button_divide->Size = System::Drawing::Size(90, 30);
			this->button_divide->TabIndex = 14;
			this->button_divide->Text = L"/";
			this->button_divide->UseVisualStyleBackColor = false;
			this->button_divide->Click += gcnew System::EventHandler(this, &GUI::button_divide_Click);
			// 
			// button_multiply
			// 
			this->button_multiply->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_multiply->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_multiply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_multiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_multiply->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_multiply->Location = System::Drawing::Point(378, 301);
			this->button_multiply->Name = L"button_multiply";
			this->button_multiply->Size = System::Drawing::Size(90, 30);
			this->button_multiply->TabIndex = 15;
			this->button_multiply->Text = L"X";
			this->button_multiply->UseVisualStyleBackColor = false;
			this->button_multiply->Click += gcnew System::EventHandler(this, &GUI::button_multiply_Click);
			// 
			// button_minus
			// 
			this->button_minus->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_minus->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_minus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_minus->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_minus->Location = System::Drawing::Point(378, 347);
			this->button_minus->Name = L"button_minus";
			this->button_minus->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button_minus->Size = System::Drawing::Size(90, 30);
			this->button_minus->TabIndex = 16;
			this->button_minus->Text = L"─";
			this->button_minus->UseVisualStyleBackColor = false;
			this->button_minus->Click += gcnew System::EventHandler(this, &GUI::button_minus_Click);
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_add->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_add->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_add->Location = System::Drawing::Point(378, 396);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(90, 30);
			this->button_add->TabIndex = 17;
			this->button_add->Text = L"+";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &GUI::button_add_Click);
			// 
			// button_delete
			// 
			this->button_delete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_delete->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_delete->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_delete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_delete->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_delete->Location = System::Drawing::Point(378, 18);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(90, 30);
			this->button_delete->TabIndex = 18;
			this->button_delete->Text = L"← Delete";
			this->button_delete->UseVisualStyleBackColor = false;
			this->button_delete->Click += gcnew System::EventHandler(this, &GUI::button_delete_Click);
			// 
			// button_clear
			// 
			this->button_clear->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_clear->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_clear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_clear->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_clear->Location = System::Drawing::Point(378, 51);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(90, 30);
			this->button_clear->TabIndex = 19;
			this->button_clear->Text = L"Clear";
			this->button_clear->UseVisualStyleBackColor = false;
			this->button_clear->Click += gcnew System::EventHandler(this, &GUI::button_clear_Click);
			// 
			// button_sin
			// 
			this->button_sin->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_sin->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_sin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_sin->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_sin->Location = System::Drawing::Point(26, 171);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(70, 30);
			this->button_sin->TabIndex = 20;
			this->button_sin->Text = L"sin(x)";
			this->button_sin->UseVisualStyleBackColor = false;
			this->button_sin->Click += gcnew System::EventHandler(this, &GUI::button_sin_Click);
			// 
			// button_cos
			// 
			this->button_cos->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_cos->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_cos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_cos->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_cos->Location = System::Drawing::Point(105, 171);
			this->button_cos->Name = L"button_cos";
			this->button_cos->Size = System::Drawing::Size(70, 30);
			this->button_cos->TabIndex = 21;
			this->button_cos->Text = L"cos(x)";
			this->button_cos->UseVisualStyleBackColor = false;
			this->button_cos->Click += gcnew System::EventHandler(this, &GUI::button_cos_Click);
			// 
			// button_tan
			// 
			this->button_tan->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_tan->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_tan->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_tan->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_tan->Location = System::Drawing::Point(183, 171);
			this->button_tan->Name = L"button_tan";
			this->button_tan->Size = System::Drawing::Size(70, 30);
			this->button_tan->TabIndex = 22;
			this->button_tan->Text = L"tan(x)";
			this->button_tan->UseVisualStyleBackColor = false;
			this->button_tan->Click += gcnew System::EventHandler(this, &GUI::button_tan_Click);
			// 
			// button_ans
			// 
			this->button_ans->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_ans->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_ans->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_ans->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_ans->Location = System::Drawing::Point(378, 171);
			this->button_ans->Name = L"button_ans";
			this->button_ans->Size = System::Drawing::Size(90, 30);
			this->button_ans->TabIndex = 23;
			this->button_ans->Text = L"Ans";
			this->button_ans->UseVisualStyleBackColor = false;
			this->button_ans->Click += gcnew System::EventHandler(this, &GUI::button_ans_Click);
			// 
			// button_power
			// 
			this->button_power->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_power->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_power->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_power->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_power->Location = System::Drawing::Point(262, 171);
			this->button_power->Name = L"button_power";
			this->button_power->Size = System::Drawing::Size(70, 30);
			this->button_power->TabIndex = 24;
			this->button_power->Text = L"x^y";
			this->button_power->UseVisualStyleBackColor = false;
			this->button_power->Click += gcnew System::EventHandler(this, &GUI::button_power_Click);
			// 
			// inputBox
			// 
			this->inputBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(26, 37);
			this->inputBox->MaxLength = 250;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(306, 27);
			this->inputBox->TabIndex = 0;
			this->inputBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::inputBox_KeyPress);
			// 
			// button_invert
			// 
			this->button_invert->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_invert->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->button_invert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_invert->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_invert->Location = System::Drawing::Point(378, 101);
			this->button_invert->Name = L"button_invert";
			this->button_invert->Size = System::Drawing::Size(90, 30);
			this->button_invert->TabIndex = 23;
			this->button_invert->Text = L"1/x";
			this->button_invert->UseVisualStyleBackColor = false;
			this->button_invert->Click += gcnew System::EventHandler(this, &GUI::button_invert_Click);
			// 
			// button_Dec
			// 
			this->button_Dec->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_Dec->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Dec->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Dec->Location = System::Drawing::Point(26, 101);
			this->button_Dec->Name = L"button_Dec";
			this->button_Dec->Size = System::Drawing::Size(23, 27);
			this->button_Dec->TabIndex = 25;
			this->button_Dec->Text = L"D";
			this->button_Dec->UseVisualStyleBackColor = false;
			this->button_Dec->Click += gcnew System::EventHandler(this, &GUI::button_Dec_Click);
			// 
			// button_Sci
			// 
			this->button_Sci->BackColor = System::Drawing::SystemColors::Control;
			this->button_Sci->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Sci->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Sci->Location = System::Drawing::Point(46, 101);
			this->button_Sci->Name = L"button_Sci";
			this->button_Sci->Size = System::Drawing::Size(23, 27);
			this->button_Sci->TabIndex = 25;
			this->button_Sci->Text = L"S";
			this->button_Sci->UseVisualStyleBackColor = false;
			this->button_Sci->Click += gcnew System::EventHandler(this, &GUI::button_Sci_Click);
			// 
			// button_Eng
			// 
			this->button_Eng->BackColor = System::Drawing::SystemColors::Control;
			this->button_Eng->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Eng->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Eng->Location = System::Drawing::Point(65, 101);
			this->button_Eng->Name = L"button_Eng";
			this->button_Eng->Size = System::Drawing::Size(23, 27);
			this->button_Eng->TabIndex = 26;
			this->button_Eng->Text = L"E";
			this->button_Eng->UseVisualStyleBackColor = false;
			this->button_Eng->Click += gcnew System::EventHandler(this, &GUI::button_Eng_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Location = System::Drawing::Point(27, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 27;
			this->label1->Text = L"Notation";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 17);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Radians";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 445);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_Eng);
			this->Controls->Add(this->button_Sci);
			this->Controls->Add(this->button_Dec);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->button_power);
			this->Controls->Add(this->button_invert);
			this->Controls->Add(this->button_ans);
			this->Controls->Add(this->button_tan);
			this->Controls->Add(this->button_cos);
			this->Controls->Add(this->button_sin);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->button_minus);
			this->Controls->Add(this->button_multiply);
			this->Controls->Add(this->button_divide);
			this->Controls->Add(this->button_equals);
			this->Controls->Add(this->button_dot);
			this->Controls->Add(this->button_0);
			this->Controls->Add(this->button_3);
			this->Controls->Add(this->button_2);
			this->Controls->Add(this->button_1);
			this->Controls->Add(this->button_6);
			this->Controls->Add(this->button_5);
			this->Controls->Add(this->button_4);
			this->Controls->Add(this->button_9);
			this->Controls->Add(this->button_8);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->button_7);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button_equals_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string input_string;
			std::string output_string;

			// set previous answer to current answer value
			PreviousAnswer = Calculate.getAnswer();

			// get user input
			System::String ^ sysTextIn = this->inputBox->Text;
			input_string = msclr::interop::marshal_as<std::string>(sysTextIn);


			// set previous calculation to current calculation value
			PreviousCalc = input_string;


			// Parse input
			output_string = "";
			output_string = Calculate.Parse(input_string);


			// calculate result
			if (output_string.empty()) {
				output_string = Calculate.Result(SelectedType, 10);
			}


			// output result
			this->resultBox->Text = gcnew String(output_string.c_str());


			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void inputBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if ((e->KeyChar == 13) || (e->KeyChar == '='))
			{
				// Run button_equals_Click
				this->button_equals->PerformClick();
				// Tell system event has already been handled
				e->Handled = true;
			}
			else {
				// Let system peform normal input
			}
		}

		private: System::Void button_Dec_Click(System::Object^  sender, System::EventArgs^  e) {
			// Change formatting to Decimal
			SelectedType = myTypes::Dec;
			this->button_Dec->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_Sci->BackColor = System::Drawing::SystemColors::Control;
			this->button_Eng->BackColor = System::Drawing::SystemColors::Control;

			// remember user input
			System::String ^ sysTextIn = this->inputBox->Text;

			// Set answer to what is was before last calculation ran
			Calculate.setAnswer(PreviousAnswer);
			// Set calculation to what is was before last calculation ran
			this->inputBox->Text = gcnew String(PreviousCalc.c_str());

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// reset user input
			this->inputBox->Text = sysTextIn;

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_Sci_Click(System::Object^  sender, System::EventArgs^  e) {
			// Change formatting to Scientific
			SelectedType = myTypes::Sci;
			this->button_Dec->BackColor = System::Drawing::SystemColors::Control;
			this->button_Sci->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_Eng->BackColor = System::Drawing::SystemColors::Control;

			// remember user input
			System::String ^ sysTextIn = this->inputBox->Text;

			// Set answer to what is was before last calculation ran
			Calculate.setAnswer(PreviousAnswer);
			// Set calculation to what is was before last calculation ran
			this->inputBox->Text = gcnew String(PreviousCalc.c_str());

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// reset user input
			this->inputBox->Text = sysTextIn;

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_Eng_Click(System::Object^  sender, System::EventArgs^  e) {
			// Change formatting to Engeneering
			SelectedType = myTypes::Eng;
			this->button_Dec->BackColor = System::Drawing::SystemColors::Control;
			this->button_Sci->BackColor = System::Drawing::SystemColors::Control;
			this->button_Eng->BackColor = System::Drawing::SystemColors::ControlDark;

			// remember user input
			System::String ^ sysTextIn = this->inputBox->Text;

			// Set answer to what is was before last calculation ran
			Calculate.setAnswer(PreviousAnswer);
			// Set calculation to what is was before last calculation ran
			this->inputBox->Text = gcnew String(PreviousCalc.c_str());

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// reset user input
			this->inputBox->Text = sysTextIn;

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_0_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 0
			this->inputBox->Text = this->inputBox->Text + "0";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_1_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 1
			this->inputBox->Text = this->inputBox->Text + "1";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_2_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 2
			this->inputBox->Text = this->inputBox->Text + "2";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_3_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 3
			this->inputBox->Text = this->inputBox->Text + "3";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_4_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 4
			this->inputBox->Text = this->inputBox->Text + "4";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_5_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 5
			this->inputBox->Text = this->inputBox->Text + "5";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_6_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 6
			this->inputBox->Text = this->inputBox->Text + "6";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_7_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 7
			this->inputBox->Text = this->inputBox->Text + "7";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_8_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 8
			this->inputBox->Text = this->inputBox->Text + "8";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_9_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 9
			this->inputBox->Text = this->inputBox->Text + "9";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_dot_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter decimal point
			this->inputBox->Text = this->inputBox->Text + ".";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "+";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_minus_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter -
			this->inputBox->Text = this->inputBox->Text + "-";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_multiply_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter *
			this->inputBox->Text = this->inputBox->Text + "*";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_divide_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter /
			this->inputBox->Text = this->inputBox->Text + "/";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_sin_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "sin";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_cos_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "cos";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_tan_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "tan";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_power_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "^";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_ans_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "ans";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_invert_Click(System::Object^  sender, System::EventArgs^  e) {

			// remember user input
			System::String ^ sysTextIn = this->inputBox->Text;

			// Enter +
			this->inputBox->Text = "1/ans";

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// reset user input
			this->inputBox->Text = sysTextIn;

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e) {
			bool deleteNext(true);
			std::string stdText;
			std::string removed;
			std::string next;

			// limit delete to 3 characters
			for (int i = 0; i < 3; i++) {
				// Delete last character
				System::String ^ sysTextIn = this->inputBox->Text;
				stdText = msclr::interop::marshal_as<std::string>(sysTextIn);

				// check size
				if (stdText.size() == 0) {
					// do nothing
				}
				else if (stdText.size() == 1) {
					// delete char & set next to empty
					removed = stdText.substr(stdText.size() - 1, 1);
					stdText = stdText.substr(0, stdText.size() - 1);
					next = "";

				}
				else {
					// delete char & read next
					removed = stdText.substr(stdText.size() - 1, 1);
					stdText = stdText.substr(0, stdText.size() - 1);
					next = stdText.substr(stdText.size() - 1, 1);

				}
				this->inputBox->Text = gcnew String(stdText.c_str());

				// for sin, cos, tan, & ans remaining characters need deleting
				deleteNext = this->check_NextChar(*removed.c_str(), *next.c_str());

				if (deleteNext == false) {
					break; // stop if next char is not to be deleted
				}
				else {
					// else delete next char
				}
			}

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void button_clear_Click(System::Object^  sender, System::EventArgs^  e) {
			// Clear Input
			this->inputBox->Text = "";

			// Re-select InputBox
			this->reselect_inputbox();
		}

		private: System::Void reselect_inputbox(System::Void) {
			// Reselect inputBox
			this->inputBox->Select();

			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: bool check_NextChar(char removed, char next) {
			// check if next character needs deleting
			// for sin, cos, tan, & ans remaining characters need deleting
			bool deleteNext(false);

			switch (removed) {
				case 'A': // fall through
				case 'a':
					if (next == 'T' || next == 't') {
						deleteNext = true; // delete next character
					}
					else {
						// stop deleting
					}
					break;

				case 'C': // fall through
				case 'c':
					// stop deleting
					break;

				case 'I': // fall through
				case 'i':
					if (next == 'S' || next == 's') {
						deleteNext = true; // delete next character
					}
					else {
						// stop deleting
					}
					break;

				case 'N': // fall through
				case 'n':
					if (next == 'I' || next == 'O' || next == 'A') {
						deleteNext = true; // delete next character
					}
					else if (next == 'i' || next == 'o' || next == 'a') {
						deleteNext = true; // delete next character
					}
					else {
						// stop deleting
					}
					break;

				case 'O': // fall through
				case 'o':
					if (next == 'C' || next == 'c') {
						deleteNext = true; // delete next character
					}
					else {
						// stop deleting
					}
					break;

				case 'S': // fall through
				case 's':
					if (next == 'N' || next == 'O') {
						deleteNext = true; // delete next character
					}
					else if (next == 'n' || next == 'o') {
						deleteNext = true; // delete next character
					}
					else {
						// stop deleting
					}
					break;

				case 'T': // fall through
				case 't':
					// stop deleting
					break;

				default:
					// stop deleting
					break;
			}

			return deleteNext;
		}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
