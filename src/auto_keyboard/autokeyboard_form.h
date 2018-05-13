#pragma once

namespace auto_keyboard {
	#pragma comment(lib, "user32.lib")
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ autokeyboard_form
	/// </summary>
	public ref class autokeyboard_form : public System::Windows::Forms::Form
	{
	public:
		autokeyboard_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~autokeyboard_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(127, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Enable autokeyboard";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &autokeyboard_form::checkBox1_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &autokeyboard_form::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Hotkey:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(62, 38);
			this->textBox1->MaxLength = 3;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"66";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &autokeyboard_form::timer2_Tick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(62, 82);
			this->textBox2->MaxLength = 3;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(63, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"1024";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Screen width:";
			// 
			// autokeyboard_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(137, 106);
			this->ControlBox = false;
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"autokeyboard_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"autokeyboard_form";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &autokeyboard_form::autokeyboard_form_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Point cursor_Position;

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 cursor_Position = System::Windows::Forms::Cursor::Position;
				 if(
					 cursor_Position.X >= Convert::ToInt32(textBox2->Text)/2
				 ){
					SendKeys::Send("D");
				 }

				 else if(
				 cursor_Position.X <= Convert::ToInt32(textBox2->Text)/2
				 ){
					 SendKeys::Send("A");
					 
				 }
				 Windows::Forms::Cursor::Position = cursor_Position;
			 }
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled = checkBox1->Checked;
			 }
	private: System::Void autokeyboard_form_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 		if(GetKeyState(Convert::ToInt16(textBox1->Text))){
					 if(timer1->Enabled == true){
						timer1->Enabled = false;
					 }
					 else{
						 timer1->Enabled = true;
					 }
				 }
		 }
};
}
