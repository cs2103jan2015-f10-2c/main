//	GUI
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Shri Kishen Rajendran A0105180W

#pragma once

#include "..\iLogic\Logic.h"
#include "..\iStorage\Item.h"
#include "..\iLogic\ItemVerification.h"
#include "..\iLogic\DateTimeVerification.h"
#include <vector>
#include <msclr\marshal_cppstd.h>
using namespace std;

namespace iPlannerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for iPlannerUI
	/// </summary>
	public ref class iPlannerUI : public System::Windows::Forms::Form {
	private:
		Logic* testLogic;
	public:
		iPlannerUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			testLogic = new Logic();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~iPlannerUI()
		{
			if (components)
			{
				delete components;
				delete testLogic;
			}
		}
	private: System::Windows::Forms::TextBox^  commandInputBox;
	private: System::Windows::Forms::TextBox^  outputBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  commandOutcomeLabel;





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
			this->commandInputBox = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->commandOutcomeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->Location = System::Drawing::Point(12, 349);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(656, 20);
			this->commandInputBox->TabIndex = 0;
			this->commandInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &iPlannerUI::commandInputBox_KeyDown);
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(12, 58);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(656, 251);
			this->outputBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(297, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"iPlanner";
			// 
			// commandOutcomeLabel
			// 
			this->commandOutcomeLabel->AutoSize = true;
			this->commandOutcomeLabel->Location = System::Drawing::Point(12, 324);
			this->commandOutcomeLabel->Name = L"commandOutcomeLabel";
			this->commandOutcomeLabel->Size = System::Drawing::Size(0, 13);
			this->commandOutcomeLabel->TabIndex = 5;
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 438);
			this->Controls->Add(this->commandOutcomeLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->commandInputBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"iPlannerUI";
			this->Text = L"iPlannerUI";
			this->Load += gcnew System::EventHandler(this, &iPlannerUI::iPlannerUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	private: System::Void commandInputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 iParser testParser;
				 String^ userInput;
				 Item iterItem;

				 userInput = commandInputBox->Text;
				 string stdUserInput;
				 MarshalString(userInput, stdUserInput);
				 if (e->KeyCode == Keys::Enter) {
					 string outcome = testLogic->initiateCommandAction(testParser, stdUserInput);

					 String^ output = "\t\t\tSCHEDULE \r\n";
					 for (int i = 0; i < testLogic->getScheduleSize(); i++) {
						 iterItem = testLogic->getDisplaySchedule()[i];
						 System::String^ IDString = iterItem.getItemID().ToString();
						 String^ nameString = gcnew String(iterItem.getItemName().c_str());

						 System::String^ startTimeString = iterItem.getStartTime().getHour().ToString() + ":" + iterItem.getStartTime().getMinute().ToString();
						 System::String^ startDateString = iterItem.getStartTime().getDay().ToString() + "/" + iterItem.getStartTime().getMonth().ToString() + "/" + iterItem.getStartTime().getYear().ToString();

						 System::String^ endTimeString = iterItem.getEndTime().getHour().ToString() + ":" + iterItem.getEndTime().getMinute().ToString();
						 System::String^ endDateString = iterItem.getEndTime().getDay().ToString() + "/" + iterItem.getEndTime().getMonth().ToString() + "/" + iterItem.getEndTime().getYear().ToString();

						 String^ descriptionString = gcnew String(iterItem.getDescription().c_str());

						 string charString1(1, iterItem.getPriority());
						 String^ priorityString = gcnew String(charString1.c_str());

						 string charString2(1, iterItem.getLabel());
						 String^ labelString = gcnew String(charString2.c_str());

						 string charString3(1, iterItem.getCompletion());
						 String^ completionString = gcnew String(charString3.c_str());

						 output += IDString + " " + nameString + "\t\t" + priorityString + " " + labelString + completionString + "\r\n";
						 output += "\t" + startTimeString + " " + startDateString + "\r\n";
						 output += "\t" + endTimeString + " " + endDateString + "\r\n";
					 }

					 String^ outcomeString = gcnew String(outcome.c_str());
					 commandOutcomeLabel->Text = outcomeString;
					 	 
					 outputBox->Text = output;
					 commandInputBox->Clear();
				 }

	}


	private: System::Void iPlannerUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 commandOutcomeLabel->Text = "Enter the command";
	}
	};
}