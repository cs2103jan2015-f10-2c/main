//	GUI
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Shri Kishen Rajendran A0105180W

#pragma once

#include "..\iLogic\Logic.h"
#include "..\iStorage\Item.h"
#include "..\iLogic\ItemVerification.h"
#include "..\iLogic\DateTimeVerification.h"
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

	private: System::Windows::Forms::MenuStrip^  HelpmenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addingATaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deletingATaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editingATaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortingScheduleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  miscellneousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dateAndTimeVariationsToolStripMenuItem;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(iPlannerUI::typeid));
			this->commandInputBox = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->commandOutcomeLabel = (gcnew System::Windows::Forms::Label());
			this->outputBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->HelpmenuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dateAndTimeVariationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miscellneousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpmenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->BackColor = System::Drawing::Color::Black;
			this->commandInputBox->ForeColor = System::Drawing::Color::Silver;
			this->commandInputBox->Location = System::Drawing::Point(12, 359);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(610, 20);
			this->commandInputBox->TabIndex = 0;
			this->commandInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &iPlannerUI::commandInputBox_KeyDown);
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::Color::Black;
			this->outputBox->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->outputBox->Location = System::Drawing::Point(12, 70);
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Salmon;
			this->label1->Location = System::Drawing::Point(271, 37);
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
			this->commandOutcomeLabel->Location = System::Drawing::Point(12, 333);
			this->commandOutcomeLabel->Name = L"commandOutcomeLabel";
			this->commandOutcomeLabel->Size = System::Drawing::Size(122, 13);
			this->commandOutcomeLabel->TabIndex = 5;
			this->commandOutcomeLabel->Text = L"commandOutcomeLabel";
			// 
			// outputBox2
			// 
			this->outputBox2->BackColor = System::Drawing::SystemColors::MenuText;
			this->outputBox2->ForeColor = System::Drawing::Color::White;
			this->outputBox2->HideSelection = false;
			this->outputBox2->Location = System::Drawing::Point(12, 70);
			this->outputBox2->Name = L"outputBox2";
			this->outputBox2->ReadOnly = true;
			this->outputBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputBox2->Size = System::Drawing::Size(610, 251);
			this->outputBox2->TabIndex = 7;
			this->outputBox2->Text = L"";
			// 
			// HelpmenuStrip1
			// 
			this->HelpmenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpToolStripMenuItem });
			this->HelpmenuStrip1->Location = System::Drawing::Point(0, 0);
			this->HelpmenuStrip1->Name = L"HelpmenuStrip1";
			this->HelpmenuStrip1->Size = System::Drawing::Size(636, 24);
			this->HelpmenuStrip1->TabIndex = 9;
			this->HelpmenuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addingATaskToolStripMenuItem,
					this->deletingATaskToolStripMenuItem, this->editingATaskToolStripMenuItem, this->sortingScheduleToolStripMenuItem, this->miscellneousToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// addingATaskToolStripMenuItem
			// 
			this->addingATaskToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dateAndTimeVariationsToolStripMenuItem });
			this->addingATaskToolStripMenuItem->Name = L"addingATaskToolStripMenuItem";
			this->addingATaskToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->addingATaskToolStripMenuItem->Text = L"Adding a Task";
			this->addingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::addingATaskToolStripMenuItem_Click);
			// 
			// dateAndTimeVariationsToolStripMenuItem
			// 
			this->dateAndTimeVariationsToolStripMenuItem->Name = L"dateAndTimeVariationsToolStripMenuItem";
			this->dateAndTimeVariationsToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->dateAndTimeVariationsToolStripMenuItem->Text = L"Date and Time Variations";
			this->dateAndTimeVariationsToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::dateAndTimeVariationsToolStripMenuItem_Click);
			// 
			// deletingATaskToolStripMenuItem
			// 
			this->deletingATaskToolStripMenuItem->Name = L"deletingATaskToolStripMenuItem";
			this->deletingATaskToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->deletingATaskToolStripMenuItem->Text = L"Deleting a Task";
			this->deletingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::deletingATaskToolStripMenuItem_Click);
			// 
			// editingATaskToolStripMenuItem
			// 
			this->editingATaskToolStripMenuItem->Name = L"editingATaskToolStripMenuItem";
			this->editingATaskToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->editingATaskToolStripMenuItem->Text = L"Editing a Task";
			this->editingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::editingATaskToolStripMenuItem_Click);
			// 
			// sortingScheduleToolStripMenuItem
			// 
			this->sortingScheduleToolStripMenuItem->Name = L"sortingScheduleToolStripMenuItem";
			this->sortingScheduleToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->sortingScheduleToolStripMenuItem->Text = L"Sorting Schedule";
			this->sortingScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::sortingScheduleToolStripMenuItem_Click);
			// 
			// miscellneousToolStripMenuItem
			// 
			this->miscellneousToolStripMenuItem->Name = L"miscellneousToolStripMenuItem";
			this->miscellneousToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->miscellneousToolStripMenuItem->Text = L"Miscellneous";
			this->miscellneousToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::miscellneousToolStripMenuItem_Click);
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(636, 430);
			this->Controls->Add(this->outputBox2);
			this->Controls->Add(this->commandOutcomeLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->commandInputBox);
			this->Controls->Add(this->HelpmenuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->HelpmenuStrip1;
			this->MaximizeBox = false;
			this->Name = L"iPlannerUI";
			this->Text = L"iPlannerUI";
			this->Load += gcnew System::EventHandler(this, &iPlannerUI::iPlannerUI_Load);
			this->HelpmenuStrip1->ResumeLayout(false);
			this->HelpmenuStrip1->PerformLayout();
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
					 String^ output = "\t\t\t\t\t   SCHEDULE \r\n\r\n";
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
						 
						 String^ completionString;

						 if (iterItem.getCompletion() == true) {
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

						 output += indexString + ". " + nameString + "\t\t\t\t\t" + priorityString + "\t\t" + labelString + "\t\t" + completionString + "\r\n";

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
							 output += "";
							 outputBox2->Text = "";
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
							 output += "";
							 outputBox2->Text = "";
						 }
						 output += "\t" + descriptionString + "\r\n";
					 }

					 String^ outcomeString = gcnew String(outcome.c_str());
					 commandOutcomeLabel->Text = outcomeString;
					 outputBox2->Text = output;
					 //					 outputBox->Text = output;
					 commandInputBox->Clear();
				 }
				 /*
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
				 }*/

	}

	private: System::Void iPlannerUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 testLogic->retrieveDirectoryFromTextFile();
				 testLogic->readDataFromFile();
				 Item iterItem;
				 outputBox2->Font = gcnew System::Drawing::Font("Arial", 10);
				 String^ output = "\t\t\t\t\t   SCHEDULE \r\n\r\n";

				 //				 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 16);
				 outputBox2->ForeColor = Color::CadetBlue;
				 outputBox2->SelectedRtf;
				 outputBox2->SelectionRightIndent = 5;
				 outputBox2->SelectedText = output;

				 // outputBox2 - RichtextBox outputBox - normal textbox output - a system string to store output for display in outputBox
				 //Within the for loop I am not able to display text in outputTextBox2
				 //Also th above line SCHEDULE does not get displayed in outputTextBox2
				 //Code under this for loop is different from previous function Keydown. In KeyDown, colour of entire text changes which is not required.
				 for (unsigned int i = 0; i < testLogic->getScheduleSize(); i++) {
					 iterItem = testLogic->getDisplaySchedule()[i];
					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
					 
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
						 //						 outputBox2->SelectionColor = Color::Red;
						 outputBox2->SelectedText = "\t\t\t" + priorityString;
					 }
					 else if (iterItem.getPriority() == 'M') {
						 priorityString = "M";
						 //							 outputBox2->Font = System::Drawing::FontStyle::Bold;
						 //						 outputBox2->SelectionColor = Color::Yellow;
						 outputBox2->SelectedText = "\t\t\t" + priorityString;
					 }
					 else if (iterItem.getPriority() == 'L') {
						 priorityString = "L";
						 //							 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 //						 outputBox2->SelectionColor = Color::Green;
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
						 //						 outputBox2->SelectionColor = Color::Purple;
						 outputBox2->SelectedText = "\t\t\t" + labelString;
					 }
					 else if (iterItem.getLabel() == 'O') {
						 labelString = "Official";
						 //outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 //						 outputBox2->SelectionColor = Color::LightPink;
						 outputBox2->SelectedText = "\t\t\t" + labelString;
					 }
					 else if (iterItem.getLabel() == 'M') {
						 labelString = "Milestone";
						 //						 outputBox2->SelectionFont = System::Drawing::FontStyle::Bold;
						 //						 outputBox2->SelectionColor = Color::Maroon;
						 outputBox2->SelectedText = "\t\t\t" + labelString;

					 }
					 else {
						 labelString = gcnew String("");
						 outputBox2->Text = "\t\t\t" + labelString;
					 }

					 String^ completionString;
//					 
					 if (iterItem.getCompletion() == true) {
						 completionString = "Done";
						 //	 outputBox2->SelectionColor = Color::Gold;
						 outputBox2->SelectedText = "\t\t\t  Done\r\n";
					 }
					 else {
						 completionString = "Not Done";
						 //						 outputBox2->SelectionColor = Color::Silver;
						 outputBox2->SelectedText = "\t\t\tNot Done\r\n";
					 }
					 // = gcnew String(charString3.c_str());

					 String^ descriptionString = gcnew String(iterItem.getDescription().c_str());
					 //						 outputBox2->Font = System::Drawing::FontStyle::Italic;
					 //					 outputBox2->SelectionColor = Color::BlueViolet;
					 outputBox2->SelectedText = "\r\n" + descriptionString;



					 output += indexString + ". " + nameString + "\t\t\t\t\t" + priorityString + "\t\t" + labelString + "\t\t" + completionString + "\r\n";

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
						 output += "";
						 outputBox2->Text = "";
					 }
					 //				 outputBox2->SelectionColor = Color::Crimson;
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
						 output += "";
						 outputBox2->Text = "";
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

	private: System::Void addingATaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuAdd = "\t\tAdding a Task Command List\r\n";
				 
				 helpMenuAdd += "\r\nadd <taskName> followed by task entities\r\n\r\n";
				 helpMenuAdd += "The task entities could be one or more of the following : \r\n";
				 helpMenuAdd += "Starting Time of Task : -start <DateTime> or -date <DateTime>\r\n";
				 helpMenuAdd += "Ending Time of Task :  -end <DateTime> or -due <DateTime>\r\n";
				 helpMenuAdd += "Task Description : -desc <Description>\r\n";
				 helpMenuAdd += "Task Priority : -priority <High/Medium/Low>  or -priority <H/M/L>\r\n";
				 helpMenuAdd += "Task Label : -label <taskLabel>\r\n";
				 helpMenuAdd += "\r\nNote : For <DateTime> variations, Help -> Adding a Task -> Date and Time Variations";

				 MessageBox::Show(helpMenuAdd);

	}

	private: System::Void dateAndTimeVariationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuDT;

				 helpMenuDT += "\t\t<DateTime> Variations\r\n";
				 helpMenuDT += "<Date>, <Time>\r\n";
				 helpMenuDT += "<Time>, <Date>\r\n";
				 helpMenuDT += "<Date>\r\n";
				 helpMenuDT += "<Time> - Today's date is set as Date\r\n";
				 
				 helpMenuDT += "\r\nDate Variations\r\n";
				 helpMenuDT += "DD/MM/YYYY\r\n";
				 helpMenuDT += "DD MonthName/MonthShortForm YYYY\r\n";
				 helpMenuDT += "DD/MM - Year set to Current Year\r\n";
				 helpMenuDT += "DD MonthName - Year set to Current Year\r\n";
				 helpMenuDT += "MonthName - Year set to Current Year\r\n";

				 helpMenuDT += "\r\nTime Variations\r\n";
				 helpMenuDT += "HH:MM\r\n";
				 helpMenuDT += "HH:MM<AM/PM>\r\n";
				 helpMenuDT += "HHMM<AM/PM> - Must have suffix if no colon between hours & minutes\r\n";

				 MessageBox::Show(helpMenuDT);
	}
	private: System::Void deletingATaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuDel = "      Deleting a Task Command List\r\n";

				 helpMenuDel += "\r\ndelete <Display index of task to be deleted\r\n";
				 helpMenuDel += "del <Display index of task to be deleted\r\n";

				 MessageBox::Show(helpMenuDel);
	}
	private: System::Void editingATaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuEdit = "\t\tEditing a Task Command List\r\n";

				 helpMenuEdit += "\r\nedit <Display index of task to be edited> <Task entity to be edited>";
				 helpMenuEdit += "Task entities can be edited with the same commands as Add\r\n";
				 helpMenuEdit += "Task Name : -name <newTaskName>";
				 helpMenuEdit += "Starting Time of Task : -start <newDateTime> or -date <newDateTime>\r\n";
				 helpMenuEdit += "Ending Time of Task :  -end <newDateTime> or -due <newDateTime>\r\n";
				 helpMenuEdit += "Task Description : -desc <newDescription>\r\n";
				 helpMenuEdit += "Task Priority : -priority <newPriority>\r\n";
				 helpMenuEdit += "Task Label : -label <newLabel>\r\n";

				 MessageBox::Show(helpMenuEdit);
	}

	private: System::Void sortingScheduleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuSort = "\t\tSorting the Schedule Command List\r\n";

				 helpMenuSort += "\r\nThe Schedule can be sorted by the following attributes : \r\n";
				 helpMenuSort += "By Task Name : sort name - Sorts Tasks by Name in alphabetical order\r\n";
				 helpMenuSort += "By Task Date : sort date - Sorts Tasks by Date in ascending order\r\n";
				 helpMenuSort += "By Task Priority : sort priority - Sorts Tasks by Priority in the order of High, Medium, Low\r\n";
				 helpMenuSort += "By Task Completion : sort completion - Sorts Tasks by completed Tasks\r\n";
				 helpMenuSort += "Task Updated Order : sort update - Sorts Tasks by the order in which Tasks were added\r\n";

				 MessageBox::Show(helpMenuSort);
	}
	private: System::Void miscellneousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuMisc = "\t\t\tOther Commands\r\n";

				 helpMenuMisc += "\r\nSearch\r\n";
				 helpMenuMisc += "search <keyword to be searched> - Keyword can be either a Task Name or Task Description\r\n";
				 helpMenuMisc += "\r\nIndicate Task Completion\r\n";
				 helpMenuMisc += "done <Display index of completed task>\r\n";
				 helpMenuMisc += "\r\nUndo Last Action\r\n";
				 helpMenuMisc += "undo\r\n";
				 helpMenuMisc += "\r\nExit Application\r\n";
				 helpMenuMisc += "exit\r\n";

				 MessageBox::Show(helpMenuMisc);
	}
};
}