#pragma once
#include "popup.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <io.h>
#include <time.h> 
#include <cmath>
#include <sstream>
#define N 256

const char* pfileDATA = "fileDATA.txt";
std::string fileDATA = "fileDATA.txt", _line;


char line[N], c;
int i, k, u, a = 0, dem;
FILE* file;

struct DATA
{
	int stt;
	std::string tvt;
	std::string tg;
};

namespace Dictionary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace System;
	using namespace System::Collections::Generic;

	using namespace System::IO;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			readEachLine("fileDATA.txt"); //Đọc file ngay khi mở app
		}
		DATA TaoData(int stt, std::string tvt, std::string tg) {
			DATA* data = new DATA;
			data->stt = stt;
			data->tvt = tvt;
			data->tg = tg;
			return *data;
		}
		void readEachLine(String^ fileName) {
			int stt = 0;
			char tuviettat[15] = { 0 }, tugoc[45] = { 0 };
			try
			{
				StreamReader^ DataIn = File::OpenText(fileName);
				String^ DataStr;
				int count = 0;
				while ((DataStr = DataIn->ReadLine()) != nullptr)
				{
					count++;
					char cStr[50] = { 0 };

					if (DataStr->Length < sizeof(cStr))
						sprintf(cStr, "%s", DataStr);

					sscanf(cStr, "[%d] %s %[^.]", &stt, tuviettat, tugoc);
					//listBox1->Items->Add(DataStr);
					std::string TVT, TG;

					TVT = std::string(tuviettat);
					TG = std::string(tugoc);
					System::String^ str1 = stt.ToString();
					String^ str2 = gcnew String(TVT.c_str());
					String^ str3 = gcnew String(TG.c_str());

					listViewItem = gcnew Windows::Forms::ListViewItem(str1);
					listViewItem->SubItems->Add(str2);
					listViewItem->SubItems->Add(str3);
					this->listView1->Items->Add(this->listViewItem);
				}
				DataIn->Close();
			}
			catch (Exception^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					MessageBox::Show("File " + fileName + " not found");
			}
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
		System::Windows::Forms::ListViewItem^ listViewItem;
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtTVT;
	private: System::Windows::Forms::TextBox^ txtTG;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;







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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtTVT = (gcnew System::Windows::Forms::TextBox());
			this->txtTG = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 21);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Thêm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(307, 21);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 35);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Sửa";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(536, 21);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 35);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Xóa";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(774, 21);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->MaximumSize = System::Drawing::Size(112, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 35);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Tìm kiếm";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &mainForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label1->Location = System::Drawing::Point(252, 14);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(474, 81);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Từ điển viết tắt";
			this->label1->Click += gcnew System::EventHandler(this, &mainForm::label1_Click);
			// 
			// txtTVT
			// 
			this->txtTVT->BackColor = System::Drawing::Color::White;
			this->txtTVT->Location = System::Drawing::Point(134, 45);
			this->txtTVT->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtTVT->Multiline = true;
			this->txtTVT->Name = L"txtTVT";
			this->txtTVT->Size = System::Drawing::Size(166, 37);
			this->txtTVT->TabIndex = 2;
			// 
			// txtTG
			// 
			this->txtTG->Location = System::Drawing::Point(523, 45);
			this->txtTG->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtTG->Multiline = true;
			this->txtTG->Name = L"txtTG";
			this->txtTG->Size = System::Drawing::Size(394, 37);
			this->txtTG->TabIndex = 2;
			this->txtTG->TextChanged += gcnew System::EventHandler(this, &mainForm::txtTG_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 45);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Từ viết tắt";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(442, 45);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Từ gốc";
			this->label3->Click += gcnew System::EventHandler(this, &mainForm::label3_Click);
			// 
			// listView1
			// 
			this->listView1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->listView1->BackColor = System::Drawing::SystemColors::Menu;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(32, 21);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(918, 296);
			this->listView1->TabIndex = 7;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"STT";
			this->columnHeader1->Width = 83;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Từ viết tắt";
			this->columnHeader2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader2->Width = 161;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Từ gốc";
			this->columnHeader3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader3->Width = 359;
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->Controls->Add(this->listView1);
			this->panel1->Location = System::Drawing::Point(0, 315);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(980, 336);
			this->panel1->TabIndex = 8;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::panel1_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Location = System::Drawing::Point(0, 233);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(980, 79);
			this->panel2->TabIndex = 9;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::panel2_Paint);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txtTVT);
			this->panel3->Controls->Add(this->txtTG);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(0, 115);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(980, 112);
			this->panel3->TabIndex = 10;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(978, 109);
			this->panel4->TabIndex = 11;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 644);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximumSize = System::Drawing::Size(1000, 700);
			this->Name = L"mainForm";
			this->Text = L"Từ điển viết tắt";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	popup^ popupForm = gcnew popup;
	popupForm->ShowDialog();
}

private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listView1->SelectedItems->Count > 0) {

	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//Hai ô Từ gốc và Từ viết tắt bị trống
	if (txtTVT->Text == "" || txtTG -> Text == "") {
		MessageBox::Show("Khong the thuc hien thao tac nay");
		return;
	}
	//
	// Kiểm tra xem từ đã tồn tại hay chưa
	//
	String^ fileName = "fileDATA.txt";
	StreamReader^ DataIn = File::OpenText(fileName); //khai báo để đọc file
	String^ DataStr; // Biến này sẽ lưu từng dòng của file text. Mỗi vòng while là một dòng
	int count = 0;
	int stt = 0;
	char tuviettat[15] = { 0 }, tugoc[45] = { 0 };
	while ((DataStr = DataIn->ReadLine()) != nullptr)
	{
		count++;
		//Phân tích từng dòng trong file Text
		char cStr[50] = { 0 };
		if (DataStr->Length < sizeof(cStr))
			sprintf(cStr, "%s", DataStr);//Chuyền String^ là DataStr sang char cStr
		sscanf(cStr, "[%d] %s %[^.]", &stt, tuviettat, tugoc);// hàm sscanf yêu cầu biến char nên phải dùng các biến char, k dùng được string 
		//Chuyển char sang std::string rồi sau đó từ std::string sang String^
		std::string TVT, TG;
		TVT = std::string(tuviettat);
		TG = std::string(tugoc);
		System::String^ str1 = stt.ToString();
		String^ str2 = gcnew String(TVT.c_str());
		String^ str3 = gcnew String(TG.c_str());
		if (str2 == (txtTVT->Text) && str3 == (txtTG->Text)) {
			MessageBox::Show("Tu nay da ton tai");
			return;
		}
		else if (str3 == (txtTG->Text)) {
			MessageBox::Show("Tu goc nay da ton tai");
			return;
		}
		else if (str2 == (txtTVT->Text)) {
			MessageBox::Show("Tu viet tat nay da ton tai");
			return;
		}
		
	}
	DataIn->Close(); // Nhớ đóng file sau khi dùng biến đọc file xong
	//
	//Ghi vào file theo cấu trúc VD: "[1] txt text."
	//
	char cStr1[50] = { 0 };
	char cStr2[50] = { 0 };
	std::ofstream fp;
	fp.open(fileDATA.c_str(), std::ios::app);
	if (txtTVT->Text->Length < sizeof(cStr1))
		sprintf(cStr1, "%s", txtTVT->Text);
	if (txtTG->Text->Length < sizeof(cStr2))
		sprintf(cStr2, "%s", txtTG->Text);
	fp << "[" << count+1 << "] " << std::string(cStr1) << " " << std::string(cStr2) << ".\n";
	fp.close();
	//
	//Thêm vào bảng các từ trong file dữ liệu
	//
	stt=0;
	tuviettat[15] = { 0 }; 
	tugoc[45] = { 0 };
	try
	{
		listView1->Items->Clear();
		StreamReader^ DataIn = File::OpenText(fileName);
		String^ DataStr;
		int count = 0;
		while ((DataStr = DataIn->ReadLine()) != nullptr)
		{
			count++;
			char cStr[50] = { 0 };
			
			if (DataStr->Length < sizeof(cStr))
				sprintf(cStr, "%s", DataStr);
			
			sscanf(cStr, "[%d] %s %[^.]", &stt, tuviettat, tugoc);
			//listBox1->Items->Add(DataStr);
			std::string TVT, TG;

			TVT = std::string(tuviettat);
			TG = std::string(tugoc);
			System::String^ str1 = stt.ToString();
			String^ str2 = gcnew String(TVT.c_str());
			String^ str3 = gcnew String(TG.c_str());

			listViewItem = gcnew Windows::Forms::ListViewItem(str1);
			listViewItem->SubItems->Add(str2);
			listViewItem->SubItems->Add(str3);
			this->listView1->Items->Add(this->listViewItem);
		}
		DataIn->Close();
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			MessageBox::Show("File " + fileName + " not found");
	}
	DataIn->Close();
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtTG_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
