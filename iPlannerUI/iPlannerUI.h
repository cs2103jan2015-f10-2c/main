//	GUI
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Shri Kishen Rajendran A0105180W

#pragma once

#include "..\iLogic\Logic.h"
#include "..\iStorage\Item.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^  basicCommandsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewScheduleToolStripMenuItem;







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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->commandOutcomeLabel = (gcnew System::Windows::Forms::Label());
			this->outputBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->HelpmenuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->basicCommandsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dateAndTimeVariationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miscellneousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpmenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->BackColor = System::Drawing::Color::Black;
			this->commandInputBox->ForeColor = System::Drawing::Color::Silver;
			this->commandInputBox->Location = System::Drawing::Point(12, 388);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(428, 20);
			this->commandInputBox->TabIndex = 0;
			this->commandInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &iPlannerUI::commandInputBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Salmon;
			this->label1->Location = System::Drawing::Point(184, 38);
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
			this->commandOutcomeLabel->Location = System::Drawing::Point(12, 359);
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
			this->outputBox2->Location = System::Drawing::Point(15, 70);
			this->outputBox2->Name = L"outputBox2";
			this->outputBox2->ReadOnly = true;
			this->outputBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputBox2->Size = System::Drawing::Size(425, 272);
			this->outputBox2->TabIndex = 7;
			this->outputBox2->Text = L"";
			// 
			// HelpmenuStrip1
			// 
			this->HelpmenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpToolStripMenuItem });
			this->HelpmenuStrip1->Location = System::Drawing::Point(0, 0);
			this->HelpmenuStrip1->Name = L"HelpmenuStrip1";
			this->HelpmenuStrip1->Size = System::Drawing::Size(452, 24);
			this->HelpmenuStrip1->TabIndex = 9;
			this->HelpmenuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->addingATaskToolStripMenuItem,
					this->deletingATaskToolStripMenuItem, this->editingATaskToolStripMenuItem, this->sortingScheduleToolStripMenuItem, this->viewScheduleToolStripMenuItem,
					this->miscellneousToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// addingATaskToolStripMenuItem
			// 
			this->addingATaskToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->basicCommandsToolStripMenuItem,
					this->dateAndTimeVariationsToolStripMenuItem
			});
			this->addingATaskToolStripMenuItem->Name = L"addingATaskToolStripMenuItem";
			this->addingATaskToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->addingATaskToolStripMenuItem->Text = L"Add a Task";
			// 
			// basicCommandsToolStripMenuItem
			// 
			this->basicCommandsToolStripMenuItem->Name = L"basicCommandsToolStripMenuItem";
			this->basicCommandsToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->basicCommandsToolStripMenuItem->Text = L"Basic Commands";
			this->basicCommandsToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::basicCommandsToolStripMenuItem_Click);
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
			this->deletingATaskToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->deletingATaskToolStripMenuItem->Text = L"Delete a Task";
			this->deletingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::deletingATaskToolStripMenuItem_Click);
			// 
			// editingATaskToolStripMenuItem
			// 
			this->editingATaskToolStripMenuItem->Name = L"editingATaskToolStripMenuItem";
			this->editingATaskToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->editingATaskToolStripMenuItem->Text = L"Edit a Task";
			this->editingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::editingATaskToolStripMenuItem_Click);
			// 
			// sortingScheduleToolStripMenuItem
			// 
			this->sortingScheduleToolStripMenuItem->Name = L"sortingScheduleToolStripMenuItem";
			this->sortingScheduleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sortingScheduleToolStripMenuItem->Text = L"Sort Schedule";
			this->sortingScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::sortingScheduleToolStripMenuItem_Click);
			// 
			// miscellneousToolStripMenuItem
			// 
			this->miscellneousToolStripMenuItem->Name = L"miscellneousToolStripMenuItem";
			this->miscellneousToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->miscellneousToolStripMenuItem->Text = L"Miscellneous";
			this->miscellneousToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::miscellneousToolStripMenuItem_Click);
			// 
			// viewScheduleToolStripMenuItem
			// 
			this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
			this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
			this->viewScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::viewScheduleToolStripMenuItem_Click);
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(452, 448);
			this->Controls->Add(this->outputBox2);
			this->Controls->Add(this->commandOutcomeLabel);
			this->Controls->Add(this->label1);
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
				 MESSAGE_AND_SCHEDULE display;
				 iParser testParser;
				 String^ userInput;
				 userInput = commandInputBox->Text;
				 string stdUserInput;
				 MarshalString(userInput, stdUserInput);
				 vector<Item> tempItem;
				 if (e->KeyCode == Keys::Enter) {
					 display = testLogic->initiateCommandAction(testParser, stdUserInput);

					 outputBox2->Clear();

					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 11, FontStyle::Bold);
					 outputBox2->SelectionColor = Color::Beige;
					 outputBox2->SelectedText = "\t\t\t    SCHEDULE\r\n\r\n";

					 tempItem = testLogic->getDisplaySchedule();
					 vector<Item>::iterator iterItem;
					 int index = 0;
					 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
						 String ^indexString = (++index).ToString();
						 String^ nameString = gcnew String(iterItem->getItemName().c_str());
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = indexString + ". ";


						 char pri = iterItem->getPriority();

						 if (pri == 72) {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
							 outputBox2->SelectionColor = Color::Red;
							 outputBox2->SelectedText = "\tH";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
							 outputBox2->SelectedText = "\t" + nameString;

						 }
						 else if (pri == 77) {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
							 outputBox2->SelectionColor = Color::Yellow;
							 outputBox2->SelectedText = "\tM";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
							 outputBox2->SelectedText = "\t" + nameString;
						 }
						 else if (pri == 76) {

							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
							 outputBox2->SelectionColor = Color::LawnGreen;
							 outputBox2->SelectedText = "\tL";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
							 outputBox2->SelectedText = "\t" + nameString;

						 }
						 else {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
							 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
							 outputBox2->SelectedText = "\t-";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
							 outputBox2->SelectedText = "\t" + nameString;
						 }



						 /*					 String^ labelString;
						 if (iterItem.getLabel() == 'E') {
						 labelString = gcnew String("");
						 }
						 else {
						 string charString1(1, iterItem.getPriority());
						 labelString = gcnew String(charString1.c_str());
						 }
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
						 }*/

						 String^ completionString;

						 if (iterItem->getCompletion() == true) {
							 completionString = "Done";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::Gold;
							 outputBox2->SelectedText = " (D)\r\n";
						 }
						 else {
							 completionString = "Not Done";
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::Silver;
							 outputBox2->SelectedText = " (ND)\r\n";
						 }

						 String^ startString = gcnew String(iterItem->displayStartTimeForUser().c_str());
						 if (startString != "") {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::LightGoldenrodYellow;
							 outputBox2->SelectedText = "\t\t   Start : " + startString + "\r\n";
						 }
						 else {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::LightGoldenrodYellow;
							 outputBox2->SelectedText = "";
						 }

						 String^ endString = gcnew String(iterItem->displayEndTimeForUser().c_str());
						 if (endString != "") {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::LightSalmon;
							 outputBox2->SelectedText = "\t\t   End  : " + endString + "\r\n";
						 }
						 else {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
							 outputBox2->SelectionColor = Color::LightSalmon;
							 outputBox2->SelectedText = "";
						 }

						 String^ descriptionString = gcnew String(iterItem->getDescription().c_str());
						 if (descriptionString != ""){
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Italic);
							 outputBox2->SelectionColor = Color::BlueViolet;
							 outputBox2->SelectedText = "\t\t   " + descriptionString + "\r\n\r\n";
						 }
						 else {
							 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Italic);
							 outputBox2->SelectionColor = Color::BlueViolet;
							 outputBox2->SelectedText = "\r\n";
						 }

					 }

					 String^ outcomeString = gcnew String(display.message.c_str());
					 commandOutcomeLabel->Text = outcomeString;

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

				 testLogic->retrieveBasicInformationFromTextFile();
				 testLogic->readDataFromFile();
				 vector<Item> tempItem;
				 outputBox2->Clear();
				 
				 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 11, FontStyle::Bold);
				 outputBox2->SelectionColor = Color::Beige;
				 outputBox2->SelectedText = "\t\t\t    SCHEDULE\r\n\r\n";
				 /*
				 outputBox2->SelectionColor = Color::;
				 outputBox2->SelectedText = "SCHEDULE2\r\n";
				 */
				 tempItem = testLogic->getDisplaySchedule();
				 vector<Item>::iterator iterItem;
				 int index = 0;
				 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
					 
					 String ^indexString = (++index).ToString();
					 String^ nameString = gcnew String(iterItem->getItemName().c_str());
					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
					 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
					 outputBox2->SelectedText = indexString + ". ";

					 
					 char pri = iterItem->getPriority();

					 if (pri == 72) {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
						 outputBox2->SelectionColor = Color::Red;
						 outputBox2->SelectedText = "\tH";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = "\t" + nameString;
						 
					 }
					 else if (pri == 77) {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
						 outputBox2->SelectionColor = Color::Yellow;
						 outputBox2->SelectedText = "\tM";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = "\t" + nameString;
					 }
					 else if (pri == 76) {

						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
						 outputBox2->SelectionColor = Color::LawnGreen;
						 outputBox2->SelectedText = "\tL";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = "\t" + nameString;

					 }
					 else {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = "\t-";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = "\t" + nameString;
					 }



					 /*					 String^ labelString;
					 if (iterItem.getLabel() == 'E') {
					 labelString = gcnew String("");
					 }
					 else {
					 string charString1(1, iterItem.getPriority());
					 labelString = gcnew String(charString1.c_str());
					 }
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
					 }*/
					 
					 String^ completionString;

					 if (iterItem->getCompletion() == true) {
						 completionString = "Done";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::Gold;
						 outputBox2->SelectedText = " (D)\r\n";
					 }
					 else {
						 completionString = "Not Done";
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::Silver;
						 outputBox2->SelectedText = " (ND)\r\n";
					 }
					 
					 String^ startString = gcnew String(iterItem->displayStartTimeForUser().c_str());
					 if (startString != "") {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::LightGoldenrodYellow;
						 outputBox2->SelectedText = "\t\t   Start : " + startString + "\r\n";
					 }
					 else {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::LightGoldenrodYellow;
						 outputBox2->SelectedText = "";
					 }

					 String^ endString = gcnew String(iterItem->displayEndTimeForUser().c_str());
					 if (endString != "") {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::LightSalmon;
						 outputBox2->SelectedText = "\t\t   End  : " + endString + "\r\n";
					 }
					 else {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10);
						 outputBox2->SelectionColor = Color::LightSalmon;
						 outputBox2->SelectedText = "";
					 }

					 String^ descriptionString = gcnew String(iterItem->getDescription().c_str());
					 if (descriptionString != ""){
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Italic);
						 outputBox2->SelectionColor = Color::BlueViolet;
						 outputBox2->SelectedText = "\t\t   " + descriptionString + "\r\n\r\n";
					 }
					 else {
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Italic);
						 outputBox2->SelectionColor = Color::BlueViolet;
						 outputBox2->SelectedText = "\r\n";
					 }
				 }

				 commandOutcomeLabel->Text = "Enter the command";

	}

	
	private: System::Void basicCommandsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuAdd = "\t\tAdd a Task - Command List\r\n";

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
				 String^ helpMenuDel = "      Deleting a Task - Command List\r\n";

				 helpMenuDel += "\r\ndelete <Display index of task to be deleted\r\n";
				 helpMenuDel += "del <Display index of task to be deleted\r\n";
				 helpMenuDel += "\r\nclear - Deletes all tasks in the Schedule\r\n";
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
				 String^ helpMenuSort = "\t\tSort Schedule - Command List\r\n";

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
	
	private: System::Void viewScheduleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuView = "\t\t\tView Schedule - Command List\r\n";

				 helpMenuView += "\r\nUser can view All tasks, Completed tasks or tasks with a specific Priority\r\n";
				 helpMenuView += "\r\nview all - All tasks in the Schedule are displayed\r\n";
				 helpMenuView += "view done - Tasks which are completed are displayed\r\n";
				 helpMenuView += "view priority <H/M/L> - Tasks which have the priority specified are displayed\r\n";

				 MessageBox::Show(helpMenuView);
	}
	
};
}