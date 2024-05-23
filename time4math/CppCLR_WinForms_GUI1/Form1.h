#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include "MathHandler.h"
#include <sstream>

template <typename T> std::string tostr(const T& t)
{
    std::ostringstream os;
    os << t;
    return os.str();
}

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
  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::TextBox^ textBox1;
  private: System::Windows::Forms::ListBox^ listBox1;
  private: System::Windows::Forms::TextBox^ textBox2;
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
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->listBox1 = (gcnew System::Windows::Forms::ListBox());
        this->textBox2 = (gcnew System::Windows::Forms::TextBox());
        this->SuspendLayout();
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(12, 47);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(119, 22);
        this->button1->TabIndex = 0;
        this->button1->Text = L"&Result";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button1_MouseClick);
        // 
        // textBox1
        // 
        this->textBox1->Location = System::Drawing::Point(13, 21);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(345, 20);
        this->textBox1->TabIndex = 1;
        // 
        // listBox1
        // 
        this->listBox1->FormattingEnabled = true;
        this->listBox1->Location = System::Drawing::Point(12, 122);
        this->listBox1->Name = L"listBox1";
        this->listBox1->Size = System::Drawing::Size(346, 212);
        this->listBox1->TabIndex = 3;
        // 
        // textBox2
        // 
        this->textBox2->Location = System::Drawing::Point(137, 48);
        this->textBox2->Name = L"textBox2";
        this->textBox2->ReadOnly = true;
        this->textBox2->Size = System::Drawing::Size(221, 20);
        this->textBox2->TabIndex = 4;
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->AutoSize = true;
        this->ClientSize = System::Drawing::Size(369, 346);
        this->Controls->Add(this->textBox2);
        this->Controls->Add(this->listBox1);
        this->Controls->Add(this->textBox1);
        this->Controls->Add(this->button1);
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
  private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
      std::string text;
      MarshalString(textBox1->Text, text);
      std::string number = tostr(funcAnalyze(text, textBox1->TextLength));
      textBox2->Text = gcnew System::String(number.c_str());

  }







}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

