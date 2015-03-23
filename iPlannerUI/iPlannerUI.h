#pragma once

#include "Logic.h""
#include "ItemVerification.h"
#include "DateTimeVerification.h"

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
	private: System::Windows::Forms::TextBox^  commandOutcomeBox;
	private: System::Windows::Forms::Label^  label1;




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
			this->commandOutcomeBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->Location = System::Drawing::Point(12, 315);
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
			// commandOutcomeBox
			// 
			this->commandOutcomeBox->Location = System::Drawing::Point(12, 341);
			this->commandOutcomeBox->Name = L"commandOutcomeBox";
			this->commandOutcomeBox->Size = System::Drawing::Size(409, 20);
			this->commandOutcomeBox->TabIndex = 3;
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
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 438);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->commandOutcomeBox);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->commandInputBox);
			this->Name = L"iPlannerUI";
			this->Text = L"iPlannerUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	
	private: System::Void commandInputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 iParser testParser;
				 Logic testLogic;
				 string userInput;
				 vector <Item> tempItem;
				 int lineNumber;
				 //const string COMMAND_NEW = "Enter the command";
				 //cout << "THIS IS NEW" << endl;
				 //cout << "command : ";
				 testLogic.readDataFromFile();
				 for
				 commandOutcomeBox->Text = "Enter the command";
				 while (getline(cin, userInput)){
					 if (e->KeyCode == Keys::Enter) {
						 testLogic.initiateCommandAction(testParser, userInput);
						 /*
						 vector<Item>::iterator iterItem;
						 for (iterItem = testLogic.getSchedule().begin(); iterItem != testLogic.getSchedule().end(); ++iterItem) {
							 int x = iterItem->getItemID();
							 string s =
								 outputBox->Text = x.str();
							 outputBox->Text = iterItem->getItemName().ToString();
							 outputBox->Text = iterItem->getStartTime().getHour();
							 outputBox->Text = iterItem->getEndTime();
							 outputBox->Text = iterItem->getDescription();
							 outputBox->Text = iterItem->getPriority();
							 outputBox->Text = iterItem->getLabel();
							 outputBox->Text = iterItem->getCompletion();
						 }*/
						 /*
						 for (unsigned int lineNumber = 0; lineNumber < testLogic.getScheduleSize(); lineNumber++){
							 string s;
							 s = itoa(testLogic.getSchedule()[lineNumber].getItemID());
							 outputBox->Text = to_string(testLogic.getSchedule()[lineNumber].getItemName());
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getYear() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMonth() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getDay() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getHour() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMinute() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getYear() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMonth() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getDay() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getHour() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMinute() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getDescription() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getPriority() << endl;
							 writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getLabel() << endl;
							*/ 

						 //outputBox->Text = testLogic.getSchedule();
						 commandOutcomeBox->Text = "Enter the command";
					 }
				 }
	}
	};
}
