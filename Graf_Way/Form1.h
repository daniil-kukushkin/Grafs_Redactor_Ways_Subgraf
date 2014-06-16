#pragma once
#include "Graf.h"

namespace Graf_Way {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		static Graphics  ^gr;
		static BufferedGraphicsContext ^st = BufferedGraphicsManager::Current;
		static BufferedGraphics ^buff;
		Pen^ pen;
		Graf^ graf1;
		Vertex^ SelectV;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  типГрафаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  взвешенныйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ориентированныйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  невзвешенныйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  неориентированныйToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;

			 int NowMouseDown;
	public:
		Form1(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			System::Drawing::Rectangle rect(0,0,1000,500);
			buff = st->Allocate(gr, rect);
			pen = gcnew Pen(Color::Green);
			buff->Graphics->Clear(Color::WhiteSmoke);
			graf1 = gcnew Graf(25);
			SelectV = nullptr;
			NowMouseDown = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->типГрафаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->взвешенныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ориентированныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->невзвешенныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->неориентированныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(654, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Delete All";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(654, 203);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 173);
			this->listBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(654, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 41);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Find some way";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(651, 135);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"From";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(721, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"to";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(683, 132);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(32, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(741, 132);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(32, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"5";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(731, 62);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(41, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"10";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(651, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Current weight:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(654, 85);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 42);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Найти ост. подграф";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->типГрафаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(786, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// типГрафаToolStripMenuItem
			// 
			this->типГрафаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->взвешенныйToolStripMenuItem, 
				this->ориентированныйToolStripMenuItem, this->невзвешенныйToolStripMenuItem, this->неориентированныйToolStripMenuItem});
			this->типГрафаToolStripMenuItem->Name = L"типГрафаToolStripMenuItem";
			this->типГрафаToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->типГрафаToolStripMenuItem->Text = L"Тип графа";
			// 
			// взвешенныйToolStripMenuItem
			// 
			this->взвешенныйToolStripMenuItem->Name = L"взвешенныйToolStripMenuItem";
			this->взвешенныйToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->взвешенныйToolStripMenuItem->Text = L"Взвешенный";
			// 
			// ориентированныйToolStripMenuItem
			// 
			this->ориентированныйToolStripMenuItem->Name = L"ориентированныйToolStripMenuItem";
			this->ориентированныйToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->ориентированныйToolStripMenuItem->Text = L"Ориентированный";
			// 
			// невзвешенныйToolStripMenuItem
			// 
			this->невзвешенныйToolStripMenuItem->Name = L"невзвешенныйToolStripMenuItem";
			this->невзвешенныйToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->невзвешенныйToolStripMenuItem->Text = L"Невзвешенный";
			// 
			// неориентированныйToolStripMenuItem
			// 
			this->неориентированныйToolStripMenuItem->Name = L"неориентированныйToolStripMenuItem";
			this->неориентированныйToolStripMenuItem->Size = System::Drawing::Size(191, 22);
			this->неориентированныйToolStripMenuItem->Text = L"Неориентированный";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(654, 382);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(91, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Взвешенный";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(654, 405);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(119, 17);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"Ориентированный";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 426);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Oriented Graphs";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void RepaintGraph()
	{
		buff->Graphics->Clear(Color::WhiteSmoke);
		graf1->Draw(buff);
		buff->Render();
	}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)  {	 
			 }
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
				 graf1->Add(100, 100);
				 RepaintGraph();
			 }
	private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if( e->Button == System::Windows::Forms::MouseButtons::Left )
				 {
					if( graf1->GetVertex(e->X, e->Y) == nullptr ) // если вершина не найдена то можно ее сюда тыкнуть
						graf1->Add(e->X, e->Y);
				 }
				 if( e->Button == System::Windows::Forms::MouseButtons::Right )
				 {

				 }
				 RepaintGraph();
			 }
	private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
				 if( e->Button == System::Windows::Forms::MouseButtons::Left )
					 NowMouseDown = 1;

				 if( e->Button == System::Windows::Forms::MouseButtons::Right )
					 NowMouseDown = 2;

				 SelectV = graf1->GetVertex(e->X, e->Y);
			 }
	private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 buff->Graphics->Clear(Color::WhiteSmoke);
				 if(NowMouseDown)
				 {
					 if(NowMouseDown == 1)
					 {
						 if(SelectV != nullptr)
						 {
							 SelectV->x = e->X;
							 SelectV->y = e->Y;
						 }
					 }
					 if(NowMouseDown == 2)
					 {
						 if(SelectV != nullptr)
						 {
							buff->Graphics->DrawLine(pen, SelectV->x, SelectV->y, e->X, e->Y);
						 }
					 }
					 graf1->Draw(buff);
					 buff->Render();
				 }
			 }
	private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(NowMouseDown)
				 {
					 if(NowMouseDown == 1)
					 {
						 if(SelectV != nullptr)
						 {
							 SelectV->x = e->X;
							 SelectV->y = e->Y;
						 }
					 }
					 if(NowMouseDown == 2)
					 {
						 if(SelectV != nullptr)
						 {
							 Vertex^ temp = graf1->GetVertex(e->X, e->Y);
							 if(temp != nullptr && SelectV->Number != temp->Number) // если мы отпускаем ребро в вершине (и отличной от начальной)
								 graf1->AddEdge(SelectV->Number, temp->Number, Convert::ToInt32(textBox3->Text) );

							 //if(temp != nullptr && SelectV->Number == temp->Number) // значит мы щелкнули по вершине правой кнопкой мыши
							//	 graf1->Del(SelectV->Number);
						 }
					 }
					 RepaintGraph();
				 }
				 NowMouseDown = 0;
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 graf1->Clear();
			 RepaintGraph();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 int anum, bnum;
			 anum = Convert::ToInt32( textBox1->Text );
			 bnum = Convert::ToInt32( textBox2->Text );
			 listBox1->BeginUpdate();
			 int* Way = graf1->FindWay(anum, bnum);
			 int i=0;
			 if(Way != NULL)
				 while(Way[i] != -1)
				 {
					 listBox1->Items->Add( Convert::ToString(Way[i]) );
					 i++;
				 }
			 else
				listBox1->Items->Add( "There is no way" );
			 listBox1->EndUpdate();
			 // перерисовываем
			 RepaintGraph();
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 graf1->FindMinOstSubgraph();
			 RepaintGraph();
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(checkBox1->Checked)
				 graf1->Weighted = true;
			 else
				 graf1->Weighted = false;
			 RepaintGraph();
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(checkBox2->Checked)
				 graf1->Oriented = true;
			 else
				 graf1->Oriented = false;
			 RepaintGraph();
		 }
};
}

