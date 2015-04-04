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
using namespace System;

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
	private: System::Windows::Forms::RichTextBox^  outputBox2;






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
			this->outputBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->BackColor = System::Drawing::Color::Black;
			this->commandInputBox->ForeColor = System::Drawing::Color::Silver;
			this->commandInputBox->Location = System::Drawing::Point(12, 349);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(610, 20);
			this->commandInputBox->TabIndex = 0;
			this->commandInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &iPlannerUI::commandInputBox_KeyDown);
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::Color::Black;
			this->outputBox->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->outputBox->Location = System::Drawing::Point(12, 58);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(359, 251);
			this->outputBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Salmon;
			this->label1->Location = System::Drawing::Point(267, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"iPlanner";
			// 
			// commandOutcomeLabel
			// 
			this->commandOutcomeLabel->AutoSize = true;
			this->commandOutcomeLabel->BackColor = System::Drawing::Color::Black;
			this->commandOutcomeLabel->ForeColor = System::Drawing::Color::IndianRed;
			this->commandOutcomeLabel->Location = System::Drawing::Point(12, 324);
			this->commandOutcomeLabel->Name = L"commandOutcomeLabel";
			this->commandOutcomeLabel->Size = System::Drawing::Size(0, 13);
			this->commandOutcomeLabel->TabIndex = 5;
			// 
			// outputBox2
			// 
			this->outputBox2->BackColor = System::Drawing::SystemColors::MenuText;
			this->outputBox2->ForeColor = System::Drawing::Color::White;
			this->outputBox2->HideSelection = false;
			this->outputBox2->Location = System::Drawing::Point(12, 58);
			this->outputBox2->Name = L"outputBox2";
			this->outputBox2->ReadOnly = true;
			this->outputBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputBox2->Size = System::Drawing::Size(610, 251);
			this->outputBox2->TabIndex = 7;
			this->outputBox2->Text = L"";
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(637, 447);
			this->Controls->Add(this->outputBox2);
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
				 outputBox2->Font = gcnew System::Drawing::Font("Arial", 10);
				 outputBox2->ForeColor = Color::CadetBlue;
				 if (e->KeyCode == Keys::Enter) {
					 string outcome = testLogic->initiateCommandAction(testParser, stdUserInput);

					 string outcometask;
					 String^ output = "\t\t\t\t\tSCHEDULE \r\n";
					 for (unsigned int i = 0; i < testLogic->getScheduleSize(); i++) {
						 iterItem = testLogic->getDisplaySchedule()[i];
						 String^ indexString = (i + 1).ToString();
						 String^ nameString = gcnew String(iterItem.getItemName().c_str());
						 //						 outputBox2->SelectionColor = System::Drawing::Color::Blue;
						 outputBox2->SelectedText = indexString + " " + nameString;

						 String^ UIHour;
						 String^ UIMinute;
						 String^ UIDay;
						 String^ UIMonth;
						 String^ UIYear;

						 if (iterItem.getStartTime().getHour() == -1){
							 UIHour = gcnew String("");
						 }
						 else {
							 UIHour = iterItem.getStartTime().getHour().ToString() + ":";
						 }
						 if (iterItem.getStartTime().getMinute() == -1) {
							 UIMinute = gcnew String("");
						 }
						 else {
							 UIMinute = iterItem.getStartTime().getMinute().ToString() + " ";
						 }
						 if (iterItem.getStartTime().getDay() == -1) {
							 UIDay = gcnew String("");
						 }
						 else {
							 UIDay = iterItem.getStartTime().getDay().ToString() + "/";
						 }
						 if (iterItem.getStartTime().getMonth() == -1) {
							 UIMonth = gcnew String("");
						 }
						 else {
							 UIMonth = iterItem.getStartTime().getMonth().ToString() + "/";
						 }
						 if (iterItem.getStartTime().getYear() == -1) {
							 UIYear = gcnew String("");
						 }
						 else {
							 UIYear = iterItem.getStartTime().getYear().ToString() + " ";
						 }
						 String^ startTimeString = UIHour + UIMinute;
						 String^ startDateString = UIDay + UIMonth + UIYear;

						 if (iterItem.getEndTime().getHour() == -1) {
							 UIHour = gcnew String("");
						 }
						 else {
							 UIHour = iterItem.getEndTime().getHour().ToString() + ":";
						 }
						 if (iterItem.getEndTime().getMinute() == -1) {
							 UIMinute = gcnew String("");
						 }
						 else {
							 UIMinute = iterItem.getEndTime().getMinute().ToString() + " ";
						 }
						 if (iterItem.getEndTime().getDay() == -1) {
							 UIDay = gcnew String("");
						 }
						 else {
							 UIDay = iterItem.getEndTime().getDay().ToString() + "/";
						 }
						 if (iterItem.getEndTime().getMonth() == -1) {
							 UIMonth = gcnew String("");
						 }
						 else {
							 UIMonth = iterItem.getEndTime().getMonth().ToString() + "/";
						 }
						 if (iterItem.getEndTime().getYear() == -1) {
							 UIYear = gcnew String("");
						 }
						 else {
							 UIYear = iterItem.getEndTime().getYear().ToString() + " ";
						 }
						 String^ endTimeString = UIHour + UIMinute;
						 String^ endDateString = UIDay + UIMonth + UIYear;

						 String^ priorityString;
						 /*						 if (iterItem.getPriority() == 'E') {
													   priorityString = gcnew String("");
													   }
													   else {
													   string charString1(1, iterItem.getPriority());
													   priorityString = gcnew String(charString1.c_str());
													   }*/
						 if (iterItem.getPriority() == 'H') {
							 priorityString = "H";
							 //							 outputBox2->Font = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Red;
							 outputBox2->SelectedText = "\t\t\t" + priorityString;
						 }
						 else if (iterItem.getPriority() == 'M') {
							 priorityString = "M";
							 //							 outputBox2->Font = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Yellow;
							 outputBox2->SelectedText = "\t\t\t" + priorityString;
						 }
						 else if (iterItem.getPriority() == 'L') {
							 priorityString = "L";
							 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Green;
							 outputBox2->SelectedText = "\t\t\t" + priorityString;
						 }
						 else {
							 priorityString = gcnew String("");
							 outputBox2->Text = "\t\t\t" + priorityString;
						 }

						 String^ labelString;
						 /*						 if (iterItem.getLabel() == 'E') {
													   labelString = gcnew String("");
													   }
													   else {
													   string charString1(1, iterItem.getPriority());
													   labelString = gcnew String(charString1.c_str());
													   }*/
						 if (iterItem.getLabel() == 'P') {
							 labelString = "Personal";
							 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Purple;
							 outputBox2->SelectedText = "\t\t\t" + labelString;
						 }
						 else if (iterItem.getLabel() == 'O') {
							 labelString = "Official";
							 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::LightPink;
							 outputBox2->SelectedText = "\t\t\t" + labelString;
						 }
						 else if (iterItem.getLabel() == 'M') {
							 labelString = "Milestone";
							 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Maroon;
							 outputBox2->SelectedText = "\t\t\t" + labelString;
						 }
						 else {
							 labelString = gcnew String("");
							 outputBox2->Text = "\t\t\t" + labelString;
						 }

						 string charString3(1, iterItem.getCompletion());
						 String^ completionString;

						 if (charString3.compare("")) {
							 completionString = "";
						 }
						 else if (charString3.compare("true")) {
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Gold;
							 outputBox2->SelectedText = "\t\t\t  Done\r\n";
							 completionString = "Done";
						 }
						 else {
							 outputBox2->SelectionColor = System::Drawing::Color::Silver;
							 outputBox2->SelectedText = "\t\t\tNot Done\r\n";
							 completionString = "Not Done";
						 }

						 String^ descriptionString = gcnew String(iterItem.getDescription().c_str());
						 //						 outputBox2->Font = System::Drawing::FontStyle::Italic;
						 //						 outputBox2->SelectionColor = System::Drawing::Color::BlueViolet;
						 outputBox2->SelectedText = "\r\n" + descriptionString;

						 output += indexString + ". " + nameString + "\t\t\t" + priorityString + "\t\t\t" + labelString + "\t\t\t" + completionString + "\r\n";
						 
						 if (startDateString != "" && startTimeString != "") {
							 output += "\tStart : " + startTimeString + " " + startDateString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::BlueViolet;
							 outputBox2->SelectedText = "\r\n\tStart" + startTimeString + " " + startDateString + "\r\n";
						 }
						 else if (startDateString == "" && startTimeString != "") {
							 output += "\tStart : " + startTimeString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::BlueViolet;
							 outputBox2->SelectedText = "\r\n\tStart" + startTimeString + "\r\n";
						 }
						 else if (startDateString != "" && startTimeString == "") {
							 output += "\tStart : " + startDateString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::BlueViolet;
							 outputBox2->SelectedText = "\r\n\tStart" + startDateString + "\r\n";
						 }
						 else {
							 output += "\r\n";
							 outputBox2->Text = "\r\n";
						 }

						 if (endDateString != "" && endTimeString != "") {
							 output += "\tEnd : " + endTimeString + " " + endDateString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Crimson;
							 outputBox2->SelectedText = "\r\n\tEnd" + endTimeString + " " + endDateString + "\r\n";
						 }
						 else if (endDateString == "" && endTimeString != "") {
							 output += "\tEnd : " + endTimeString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Crimson;
							 outputBox2->SelectedText = "\r\n\tEnd" + endTimeString + "\r\n";
						 }
						 else if (endDateString != "" && endTimeString == "") {
							 output += "\tEnd : " + endDateString + "\r\n";
							 //							 outputBox2->SelectionColor = System::Drawing::Color::Crimson;
							 outputBox2->SelectedText = "\r\n\tEnd" + endDateString + "\r\n";
						 }
						 else {
							 output += "\r\n";
							 outputBox2->Text = "\r\n";
						 }
						 output += "\t" + descriptionString + "\r\n";
					 }

					 String^ outcomeString = gcnew String(outcome.c_str());
					 commandOutcomeLabel->Text = outcomeString;
					 outputBox2->Text = output;
					 //					 outputBox->Text = output;
					 commandInputBox->Clear();
				 }
				 if (e->KeyCode == Keys::Alt && e->KeyCode == Keys::L) {
					 outputBox2->BackColor = Color::White;
					 outputBox2->ForeColor = Color::Crimson;
					 commandInputBox->BackColor = Color::White;
					 commandInputBox->ForeColor = Color::Crimson;
				 }
				 if (e->KeyCode == Keys::Alt && e->KeyCode == Keys::D) {
					 outputBox2->BackColor = Color::Black;
					 outputBox2->ForeColor = Color::Aqua;
					 commandInputBox->BackColor = Color::Black;
					 commandInputBox->ForeColor = Color::Aqua;
				 }

	}

	private: System::Void iPlannerUI_Load(System::Object^  sender, System::EventArgs^  e) {

				 testLogic->retrieveDirectoryFromTextFile();
				 testLogic->readDataFromFile();
				 Item iterItem;
				 outputBox2->Font = gcnew System::Drawing::Font("Arial", 10);
				 String^ output = "\t\t\t\t\t   SCHEDULE \r\n";

				 //				 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 16);
				 outputBox2->SelectionColor = Color::CadetBlue;
				 outputBox2->SelectedText = output;

				 // outputBox2 - RichtextBox outputBox - normal textbox output - a system string to store output for display in outputBox
				 //Within the for loop I am not able to display text in outputTextBox2
				 //Also th above line SCHEDULE does not get displayed in outputTextBox2
				 //Code under this for loop is different from previous function Keydown. In KeyDown, colour of entire text changes which is not required.
				 for (unsigned int i = 0; i < testLogic->getScheduleSize(); i++) {
					 iterItem = testLogic->getDisplaySchedule()[i];
					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
					 //					 outputBox->Text = "hgjkiyujvdg\n";
					 String ^indexString = (i + 1).ToString();
					 String^ nameString = gcnew String(iterItem.getItemName().c_str());

					 //					 outputBox2->SelectionColor = System::Drawing::Color::Blue;
					 //		             outputBox2->SelectedText = indexString + "dgfchc " + nameString;
					 //					 outputBox2->SelectedText = "nameStrin";
					 //					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
					 outputBox2->SelectionColor = Color::CadetBlue;
					 outputBox2->SelectedText = indexString + " " + nameString;
					 //					 output = indexString + ". " + nameString;
					 //					 outputBox2->Text = output;
					 String^ UIHour;
					 String^ UIMinute;
					 String^ UIDay;
					 String^ UIMonth;
					 String^ UIYear;

					 if (iterItem.getStartTime().getHour() == -1){
						 UIHour = gcnew String("");
					 }
					 else {
						 UIHour = iterItem.getStartTime().getHour().ToString() + ":";
					 }
					 if (iterItem.getStartTime().getMinute() == -1) {
						 UIMinute = gcnew String("");
					 }
					 else {
						 UIMinute = iterItem.getStartTime().getMinute().ToString() + " ";
					 }
					 if (iterItem.getStartTime().getDay() == -1) {
						 UIDay = gcnew String("");
					 }
					 else {
						 UIDay = iterItem.getStartTime().getDay().ToString() + "/";
					 }
					 if (iterItem.getStartTime().getMonth() == -1) {
						 UIMonth = gcnew String("");
					 }
					 else {
						 UIMonth = iterItem.getStartTime().getMonth().ToString() + "/";
					 }
					 if (iterItem.getStartTime().getYear() == -1) {
						 UIYear = gcnew String("");
					 }
					 else {
						 UIYear = iterItem.getStartTime().getYear().ToString() + " ";
					 }
					 String^ startTimeString = UIHour + UIMinute;
					 String^ startDateString = UIDay + UIMonth + UIYear;

					 if (iterItem.getEndTime().getHour() == -1) {
						 UIHour = gcnew String("");
					 }
					 else {
						 UIHour = iterItem.getEndTime().getHour().ToString() + ":";
					 }
					 if (iterItem.getEndTime().getMinute() == -1) {
						 UIMinute = gcnew String("");
					 }
					 else {
						 UIMinute = iterItem.getEndTime().getMinute().ToString() + " ";
					 }
					 if (iterItem.getEndTime().getDay() == -1) {
						 UIDay = gcnew String("");
					 }
					 else {
						 UIDay = iterItem.getEndTime().getDay().ToString() + "/";
					 }
					 if (iterItem.getEndTime().getMonth() == -1) {
						 UIMonth = gcnew String("");
					 }
					 else {
						 UIMonth = iterItem.getEndTime().getMonth().ToString() + "/";
					 }
					 if (iterItem.getEndTime().getYear() == -1) {
						 UIYear = gcnew String("");
					 }
					 else {
						 UIYear = iterItem.getEndTime().getYear().ToString() + " ";
					 }
					 String^ endTimeString = UIHour + UIMinute;
					 String^ endDateString = UIDay + UIMonth + UIYear;

					 String^ priorityString;
					 /*						 if (iterItem.getPriority() == 'E') {
					 priorityString = gcnew String("");
					 }
					 else {
					 string charString1(1, iterItem.getPriority());
					 priorityString = gcnew String(charString1.c_str());
					 }*/
					 if (iterItem.getPriority() == 'H') {
						 priorityString = "H";
						 outputBox2->SelectionColor = Color::Red;
						 outputBox2->SelectedText = "\t\t\t" + priorityString;
					 }
					 else if (iterItem.getPriority() == 'M') {
						 priorityString = "M";
						 //							 outputBox2->Font = System::Drawing::FontStyle::Bold;
						 outputBox2->SelectionColor = Color::Yellow;
						 outputBox2->SelectedText = "\t\t\t" + priorityString;
					 }
					 else if (iterItem.getPriority() == 'L') {
						 priorityString = "L";
						 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 outputBox2->SelectionColor = Color::Green;
						 outputBox2->SelectedText = "\t\t\t" + priorityString;

					 }
					 else {
						 priorityString = gcnew String("");
						 outputBox2->Text = "\t\t\t" + priorityString;
					 }

					 String^ labelString;
					 /*						 if (iterItem.getLabel() == 'E') {
					 labelString = gcnew String("");
					 }
					 else {
					 string charString1(1, iterItem.getPriority());
					 labelString = gcnew String(charString1.c_str());
					 }*/
					 if (iterItem.getLabel() == 'P') {
						 labelString = "Personal";
						 //						 outputBox2->SelectionFont = System::Windows::FontStyle::Bold;
						 outputBox2->SelectionColor = Color::Purple;
						 outputBox2->SelectedText = "\t\t\t" + labelString;
					 }
					 else if (iterItem.getLabel() == 'O') {
						 labelString = "Official";
						 //outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 outputBox2->SelectionColor = Color::LightPink;
						 outputBox2->SelectedText = "\t\t\t" + labelString;
					 }
					 else if (iterItem.getLabel() == 'M') {
						 labelString = "Milestone";
						 //						 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 outputBox2->SelectionColor = Color::Maroon;
						 outputBox2->SelectedText = "\t\t\t" + labelString;

					 }
					 else {
						 labelString = gcnew String("");
						 outputBox2->Text = "\t\t\t" + labelString;
					 }

					 string charString3(1, iterItem.getCompletion());
					 if (charString3.compare("true")) {
						 //	 outputBox2->SelectionColor = Color::Gold;
						 outputBox2->SelectedText = "\t\t\t  Done\r\n";
					 }
					 else {
						 outputBox2->SelectionColor = Color::Silver;
						 outputBox2->SelectedText = "\t\t\tNot Done\r\n";
					 }
					 String^ completionString = gcnew String(charString3.c_str());

					 String^ descriptionString = gcnew String(iterItem.getDescription().c_str());
					 //						 outputBox2->Font = System::Drawing::FontStyle::Italic;
					 outputBox2->SelectionColor = Color::BlueViolet;
					 outputBox2->SelectedText = "\r\n" + descriptionString;



					 output += indexString + ". " + nameString + "\t\t\t" + priorityString + "\t\t\t" + labelString + "\t\t\t" + completionString + "\r\n";
					 
					 outputBox2->SelectionColor = Color::BlueViolet;
					 if (startDateString != "" && startTimeString != "") {
						 output += "\tStart : " + startTimeString + " " + startDateString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tStart" + startTimeString + " " + startDateString + "\r\n";
					 }
					 else if (startDateString == "" && startTimeString != "") {
						 output += "\tStart : " + startTimeString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tStart" + startTimeString + "\r\n";
					 }
					 else if (startDateString != "" && startTimeString == "") {
						 output += "\tStart : " + startDateString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tStart" + startDateString + "\r\n";
						 //outputBox2->Text = output;
					 }
					 else {
						 output += "\r\n";
						 outputBox2->Text = "\r\n";
					 }
					 outputBox2->SelectionColor = Color::Crimson;
					 if (endDateString != "" && endTimeString != "") {
						 output += "\tEnd : " + endTimeString + " " + endDateString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tEnd" + endTimeString + " " + endDateString + "\r\n";
						 //						 outputBox2->Text = output;
					 }
					 else if (endDateString == "" && endTimeString != "") {
						 output += "\tEnd : " + endTimeString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tEnd" + endTimeString + "\r\n";
						 //						 outputBox2->Text = output;
					 }
					 else if (endDateString != "" && endTimeString == "") {
						 output += "\tEnd : " + endDateString + "\r\n";
						 outputBox2->SelectedText = "\r\n\tEnd" + endDateString + "\r\n";
						 //						 outputBox2->Text = output;
					 }
					 else {
						 output += "\r\n";
						 outputBox2->Text = "\r\n";
						 //						 outputBox2->Text = output;
					 }
					 output += "\t" + descriptionString + "\r\n";
				 }

				 //	 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 16);
				 // outputBox2->SelectedText = output;

				 //				 outputBox->Text = output;
				 outputBox2->Text = output;
				 //			 outputBox2->Select
				 //				 outputBox2->ForeColor = Color::Crimson;
				 commandOutcomeLabel->Text = "Enter the command";

	}
	
};
}