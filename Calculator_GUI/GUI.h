#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"

namespace Calculator_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	CalculatorLib Calculate;
	myTypes::notation SelectedType = myTypes::Dec;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
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
			this->SuspendLayout();
			// 
			// button_7
			// 
			this->button_7->Location = System::Drawing::Point(26, 171);
			this->button_7->Name = L"button_7";
			this->button_7->Size = System::Drawing::Size(75, 23);
			this->button_7->TabIndex = 1;
			this->button_7->Text = L"7";
			this->button_7->UseVisualStyleBackColor = true;
			this->button_7->Click += gcnew System::EventHandler(this, &GUI::button_7_Click);
			// 
			// resultBox
			// 
			this->resultBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultBox->Location = System::Drawing::Point(87, 91);
			this->resultBox->Name = L"resultBox";
			this->resultBox->ReadOnly = true;
			this->resultBox->Size = System::Drawing::Size(177, 27);
			this->resultBox->TabIndex = 2;
			this->resultBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button_8
			// 
			this->button_8->Location = System::Drawing::Point(108, 171);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(75, 23);
			this->button_8->TabIndex = 3;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = true;
			this->button_8->Click += gcnew System::EventHandler(this, &GUI::button_8_Click);
			// 
			// button_9
			// 
			this->button_9->Location = System::Drawing::Point(190, 171);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(75, 23);
			this->button_9->TabIndex = 4;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = true;
			this->button_9->Click += gcnew System::EventHandler(this, &GUI::button_9_Click);
			// 
			// button_4
			// 
			this->button_4->Location = System::Drawing::Point(26, 200);
			this->button_4->Name = L"button_4";
			this->button_4->Size = System::Drawing::Size(75, 23);
			this->button_4->TabIndex = 5;
			this->button_4->Text = L"4";
			this->button_4->UseVisualStyleBackColor = true;
			this->button_4->Click += gcnew System::EventHandler(this, &GUI::button_4_Click);
			// 
			// button_5
			// 
			this->button_5->Location = System::Drawing::Point(108, 200);
			this->button_5->Name = L"button_5";
			this->button_5->Size = System::Drawing::Size(75, 23);
			this->button_5->TabIndex = 6;
			this->button_5->Text = L"5";
			this->button_5->UseVisualStyleBackColor = true;
			this->button_5->Click += gcnew System::EventHandler(this, &GUI::button_5_Click);
			// 
			// button_6
			// 
			this->button_6->Location = System::Drawing::Point(190, 200);
			this->button_6->Name = L"button_6";
			this->button_6->Size = System::Drawing::Size(75, 23);
			this->button_6->TabIndex = 7;
			this->button_6->Text = L"6";
			this->button_6->UseVisualStyleBackColor = true;
			this->button_6->Click += gcnew System::EventHandler(this, &GUI::button_6_Click);
			// 
			// button_1
			// 
			this->button_1->Location = System::Drawing::Point(26, 229);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(75, 23);
			this->button_1->TabIndex = 8;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = true;
			this->button_1->Click += gcnew System::EventHandler(this, &GUI::button_1_Click);
			// 
			// button_2
			// 
			this->button_2->Location = System::Drawing::Point(108, 229);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(75, 23);
			this->button_2->TabIndex = 9;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = true;
			this->button_2->Click += gcnew System::EventHandler(this, &GUI::button_2_Click);
			// 
			// button_3
			// 
			this->button_3->Location = System::Drawing::Point(190, 229);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(75, 23);
			this->button_3->TabIndex = 10;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = true;
			this->button_3->Click += gcnew System::EventHandler(this, &GUI::button_3_Click);
			// 
			// button_0
			// 
			this->button_0->Location = System::Drawing::Point(108, 258);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(75, 23);
			this->button_0->TabIndex = 11;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = true;
			this->button_0->Click += gcnew System::EventHandler(this, &GUI::button_0_Click);
			// 
			// button_dot
			// 
			this->button_dot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_dot->Location = System::Drawing::Point(26, 258);
			this->button_dot->Name = L"button_dot";
			this->button_dot->Size = System::Drawing::Size(75, 23);
			this->button_dot->TabIndex = 12;
			this->button_dot->Text = L"•";
			this->button_dot->UseVisualStyleBackColor = true;
			this->button_dot->Click += gcnew System::EventHandler(this, &GUI::button_dot_Click);
			// 
			// button_equals
			// 
			this->button_equals->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button_equals->Location = System::Drawing::Point(190, 258);
			this->button_equals->Name = L"button_equals";
			this->button_equals->Size = System::Drawing::Size(75, 23);
			this->button_equals->TabIndex = 13;
			this->button_equals->Text = L"=";
			this->button_equals->UseVisualStyleBackColor = false;
			this->button_equals->Click += gcnew System::EventHandler(this, &GUI::button_equals_Click);
			// 
			// button_divide
			// 
			this->button_divide->Location = System::Drawing::Point(296, 171);
			this->button_divide->Name = L"button_divide";
			this->button_divide->Size = System::Drawing::Size(75, 23);
			this->button_divide->TabIndex = 14;
			this->button_divide->Text = L"/";
			this->button_divide->UseVisualStyleBackColor = true;
			this->button_divide->Click += gcnew System::EventHandler(this, &GUI::button_divide_Click);
			// 
			// button_multiply
			// 
			this->button_multiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_multiply->Location = System::Drawing::Point(296, 200);
			this->button_multiply->Name = L"button_multiply";
			this->button_multiply->Size = System::Drawing::Size(75, 23);
			this->button_multiply->TabIndex = 15;
			this->button_multiply->Text = L"*";
			this->button_multiply->UseVisualStyleBackColor = true;
			this->button_multiply->Click += gcnew System::EventHandler(this, &GUI::button_multiply_Click);
			// 
			// button_minus
			// 
			this->button_minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_minus->Location = System::Drawing::Point(296, 229);
			this->button_minus->Name = L"button_minus";
			this->button_minus->Size = System::Drawing::Size(75, 23);
			this->button_minus->TabIndex = 16;
			this->button_minus->Text = L"-";
			this->button_minus->UseVisualStyleBackColor = true;
			this->button_minus->Click += gcnew System::EventHandler(this, &GUI::button_minus_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(296, 258);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(75, 23);
			this->button_add->TabIndex = 17;
			this->button_add->Text = L"+";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &GUI::button_add_Click);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(296, 19);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(75, 23);
			this->button_delete->TabIndex = 18;
			this->button_delete->Text = L"← Delete";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &GUI::button_delete_Click);
			// 
			// button_clear
			// 
			this->button_clear->Location = System::Drawing::Point(296, 47);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(75, 23);
			this->button_clear->TabIndex = 19;
			this->button_clear->Text = L"Clear";
			this->button_clear->UseVisualStyleBackColor = true;
			this->button_clear->Click += gcnew System::EventHandler(this, &GUI::button_clear_Click);
			// 
			// button_sin
			// 
			this->button_sin->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_sin->Location = System::Drawing::Point(26, 129);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(53, 23);
			this->button_sin->TabIndex = 20;
			this->button_sin->Text = L"sin(x)";
			this->button_sin->UseVisualStyleBackColor = true;
			// 
			// button_cos
			// 
			this->button_cos->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_cos->Location = System::Drawing::Point(87, 129);
			this->button_cos->Name = L"button_cos";
			this->button_cos->Size = System::Drawing::Size(55, 23);
			this->button_cos->TabIndex = 21;
			this->button_cos->Text = L"cos(x)";
			this->button_cos->UseVisualStyleBackColor = true;
			// 
			// button_tan
			// 
			this->button_tan->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_tan->Location = System::Drawing::Point(149, 129);
			this->button_tan->Name = L"button_tan";
			this->button_tan->Size = System::Drawing::Size(53, 23);
			this->button_tan->TabIndex = 22;
			this->button_tan->Text = L"tan(x)";
			this->button_tan->UseVisualStyleBackColor = true;
			// 
			// button_ans
			// 
			this->button_ans->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_ans->Location = System::Drawing::Point(296, 129);
			this->button_ans->Name = L"button_ans";
			this->button_ans->Size = System::Drawing::Size(75, 23);
			this->button_ans->TabIndex = 23;
			this->button_ans->Text = L"Ans";
			this->button_ans->UseVisualStyleBackColor = true;
			// 
			// button_power
			// 
			this->button_power->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_power->Location = System::Drawing::Point(211, 129);
			this->button_power->Name = L"button_power";
			this->button_power->Size = System::Drawing::Size(53, 23);
			this->button_power->TabIndex = 24;
			this->button_power->Text = L"x^y";
			this->button_power->UseVisualStyleBackColor = true;
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(26, 32);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(238, 27);
			this->inputBox->TabIndex = 0;
			this->inputBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::inputBox_KeyPress);
			// 
			// button_invert
			// 
			this->button_invert->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->button_invert->Location = System::Drawing::Point(296, 91);
			this->button_invert->Name = L"button_invert";
			this->button_invert->Size = System::Drawing::Size(75, 23);
			this->button_invert->TabIndex = 23;
			this->button_invert->Text = L"1/x";
			this->button_invert->UseVisualStyleBackColor = true;
			// 
			// button_Dec
			// 
			this->button_Dec->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_Dec->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Dec->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Dec->Location = System::Drawing::Point(26, 91);
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
			this->button_Sci->Location = System::Drawing::Point(46, 91);
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
			this->button_Eng->Location = System::Drawing::Point(65, 91);
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
			this->label1->Location = System::Drawing::Point(27, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 27;
			this->label1->Text = L"Notation";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 303);
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
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button_equals_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string input_string;
			std::string output_string;

			// get user input
			System::String ^ sysTextIn = this->inputBox->Text;
			input_string = msclr::interop::marshal_as<std::string>(sysTextIn);


			// Parse input
			output_string = "";
			output_string = Calculate.Parse(input_string);


			// calculate result
			if (output_string.empty()) {
				output_string = Calculate.Result(SelectedType, 10);
			}


			// output result
			this->resultBox->Text = gcnew String(output_string.c_str());


			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
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

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_Sci_Click(System::Object^  sender, System::EventArgs^  e) {
			// Change formatting to Scientific
			SelectedType = myTypes::Sci;
			this->button_Dec->BackColor = System::Drawing::SystemColors::Control;
			this->button_Sci->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_Eng->BackColor = System::Drawing::SystemColors::Control;

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_Eng_Click(System::Object^  sender, System::EventArgs^  e) {
			// Change formatting to Engeneering
			SelectedType = myTypes::Eng;
			this->button_Dec->BackColor = System::Drawing::SystemColors::Control;
			this->button_Sci->BackColor = System::Drawing::SystemColors::Control;
			this->button_Eng->BackColor = System::Drawing::SystemColors::ControlDark;

			// Run button_equals_Click
			this->button_equals->PerformClick();

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_0_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 0
			this->inputBox->Text = this->inputBox->Text + "0";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_1_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 1
			this->inputBox->Text = this->inputBox->Text + "1";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_2_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 2
			this->inputBox->Text = this->inputBox->Text + "2";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_3_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 3
			this->inputBox->Text = this->inputBox->Text + "3";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_4_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 4
			this->inputBox->Text = this->inputBox->Text + "4";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_5_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 5
			this->inputBox->Text = this->inputBox->Text + "5";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_6_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 6
			this->inputBox->Text = this->inputBox->Text + "6";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_7_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 7
			this->inputBox->Text = this->inputBox->Text + "7";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_8_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 8
			this->inputBox->Text = this->inputBox->Text + "8";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_9_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter 9
			this->inputBox->Text = this->inputBox->Text + "9";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_dot_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter decimal point
			this->inputBox->Text = this->inputBox->Text + ".";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter +
			this->inputBox->Text = this->inputBox->Text + "+";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_minus_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter -
			this->inputBox->Text = this->inputBox->Text + "-";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_multiply_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter *
			this->inputBox->Text = this->inputBox->Text + "*";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_divide_Click(System::Object^  sender, System::EventArgs^  e) {
			// Enter /
			this->inputBox->Text = this->inputBox->Text + "/";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e) {
			// Delete last character
			System::String ^ sysTextIn = this->inputBox->Text;
			std::string stdText = msclr::interop::marshal_as<std::string>(sysTextIn);
			stdText = stdText.substr(0, stdText.size() - 1);
			this->inputBox->Text = gcnew String(stdText.c_str());

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}

		private: System::Void button_clear_Click(System::Object^  sender, System::EventArgs^  e) {
			// Clear Input
			this->inputBox->Text = "";

			// Reselect inputBox without highlight
			this->inputBox->Select();
			this->inputBox->DeselectAll();
			// Move caret to end of input
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = this->inputBox->Text->Length;
		}
	};
}
