#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "MathHandler.h"
#include <chrono> 
#include <thread>

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void)
    {
      InitializeComponent();
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::TextBox^ textBox1;
  protected:
  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::TextBox^ textBox2;
  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::Button^ button2;
  private: System::Windows::Forms::TextBox^ textBox3;
  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::Button^ button3;
  private: System::Windows::Forms::Label^ label4;

  private: System::Windows::Forms::Label^ label5;
  private: System::Windows::Forms::RichTextBox^ richTextBox1;




  protected:






  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->textBox2 = (gcnew System::Windows::Forms::TextBox());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->button2 = (gcnew System::Windows::Forms::Button());
        this->textBox3 = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->button3 = (gcnew System::Windows::Forms::Button());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
        this->SuspendLayout();
        // 
        // textBox1
        // 
        this->textBox1->Location = System::Drawing::Point(12, 29);
        this->textBox1->Multiline = true;
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(357, 85);
        this->textBox1->TabIndex = 0;
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(9, 9);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(34, 13);
        this->label1->TabIndex = 1;
        this->label1->Text = L"Task:";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(9, 123);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(40, 13);
        this->label2->TabIndex = 2;
        this->label2->Text = L"Result:";
        // 
        // textBox2
        // 
        this->textBox2->Location = System::Drawing::Point(12, 139);
        this->textBox2->Name = L"textBox2";
        this->textBox2->ReadOnly = true;
        this->textBox2->Size = System::Drawing::Size(357, 20);
        this->textBox2->TabIndex = 3;
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(294, 261);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(75, 23);
        this->button1->TabIndex = 4;
        this->button1->Text = L"Result";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
        // 
        // button2
        // 
        this->button2->Location = System::Drawing::Point(294, 288);
        this->button2->Name = L"button2";
        this->button2->Size = System::Drawing::Size(75, 23);
        this->button2->TabIndex = 5;
        this->button2->Text = L"Clear";
        this->button2->UseVisualStyleBackColor = true;
        this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
        // 
        // textBox3
        // 
        this->textBox3->Location = System::Drawing::Point(13, 291);
        this->textBox3->Name = L"textBox3";
        this->textBox3->ReadOnly = true;
        this->textBox3->Size = System::Drawing::Size(275, 20);
        this->textBox3->TabIndex = 6;
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(9, 271);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(146, 13);
        this->label3->TabIndex = 7;
        this->label3->Text = L"Time Spent On Solving Task:";
        // 
        // button3
        // 
        this->button3->Location = System::Drawing::Point(12, 324);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(75, 23);
        this->button3->TabIndex = 8;
        this->button3->Text = L"Console";
        this->button3->UseVisualStyleBackColor = true;
        this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Location = System::Drawing::Point(291, 334);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(77, 13);
        this->label4->TabIndex = 9;
        this->label4->Text = L"Made By Fozik";
        // 
        // label5
        // 
        this->label5->AutoSize = true;
        this->label5->Location = System::Drawing::Point(9, 171);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(37, 13);
        this->label5->TabIndex = 11;
        this->label5->Text = L"Solve:";
        // 
        // richTextBox1
        // 
        this->richTextBox1->Location = System::Drawing::Point(12, 187);
        this->richTextBox1->Name = L"richTextBox1";
        this->richTextBox1->ReadOnly = true;
        this->richTextBox1->Size = System::Drawing::Size(357, 68);
        this->richTextBox1->TabIndex = 12;
        this->richTextBox1->Text = L"";
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->AutoSize = true;
        this->ClientSize = System::Drawing::Size(384, 361);
        this->Controls->Add(this->richTextBox1);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->button3);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->textBox3);
        this->Controls->Add(this->button2);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->textBox2);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->textBox1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
        this->Name = L"Form1";
        this->Text = L"Fozik`s C++ Calculator";
        this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion


   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.

   void MarshalString(String^ s, std::string& os) {
       using namespace Runtime::InteropServices;
       const char* chars =
           (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
       os = chars;
       Marshal::FreeHGlobal(IntPtr((void*)chars));
    }
  private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
  }
  
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    double startTime, endTime;
    auto begin = std::chrono::steady_clock::now();
    std::string text;
    std::string new_string;
    float timespent;
    MarshalString(textBox1->Text, text);
    std::string number = tostr(funcAnalyze(text, textBox1->TextLength,new_string));
    auto end = std::chrono::steady_clock::now();
    float time_sec = std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
    float time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    float time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    textBox2->Text = gcnew System::String(number.c_str());
    richTextBox1->Text = gcnew System::String(new_string.c_str());
    textBox3->Text = gcnew System::String((tostr(time_sec) + " sec " + tostr(time_ms) + " ms " + tostr(time_ns) + " ns").c_str());

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    textBox2->Text = "";
    textBox1->Text = "";
    textBox3->Text = "";
    richTextBox1->Text = "";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    system("start time4math.exe");
    system("taskkill /IM CppCLR_WinForms_GUI1.exe");
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

