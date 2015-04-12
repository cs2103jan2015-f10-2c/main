//@author A0105180W
//	GUI
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#pragma once

#include "..\iLogic\Logic.h"
#include "..\iStorage\Item.h"
#include "..\iPlanner Log\Log.h"
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;

//@author generated
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
		iPlannerUI(void) {
			
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
		~iPlannerUI() {

			if (components)
			{
				delete components;
				delete testLogic;
			}
		}

	private: System::Windows::Forms::TextBox^  commandInputBox;
	private: System::Windows::Forms::Label^  scheduleLabel;



	private: System::Windows::Forms::Label^  commandOutcomeLabel;
	private: System::Windows::Forms::RichTextBox^  outputBox;


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
	private: System::Windows::Forms::ToolStripMenuItem^  addModifyATaskEntityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeATaskEntityToolStripMenuItem;









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
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(iPlannerUI::typeid));
			this->commandInputBox = (gcnew System::Windows::Forms::TextBox());
			this->scheduleLabel = (gcnew System::Windows::Forms::Label());
			this->commandOutcomeLabel = (gcnew System::Windows::Forms::Label());
			this->outputBox = (gcnew System::Windows::Forms::RichTextBox());
			this->HelpmenuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->basicCommandsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dateAndTimeVariationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editingATaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addModifyATaskEntityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeATaskEntityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miscellneousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpmenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->BackColor = System::Drawing::Color::Black;
			this->commandInputBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commandInputBox->ForeColor = System::Drawing::Color::Silver;
			this->commandInputBox->Location = System::Drawing::Point(12, 532);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(428, 25);
			this->commandInputBox->TabIndex = 0;
			this->commandInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &iPlannerUI::commandInputBox_KeyDown);
			// 
			// scheduleLabel
			// 
			this->scheduleLabel->AutoSize = true;
			this->scheduleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scheduleLabel->ForeColor = System::Drawing::Color::PeachPuff;
			this->scheduleLabel->Location = System::Drawing::Point(184, 38);
			this->scheduleLabel->Name = L"scheduleLabel";
			this->scheduleLabel->Size = System::Drawing::Size(91, 21);
			this->scheduleLabel->TabIndex = 4;
			this->scheduleLabel->Text = L"SCHEDULE";
			// 
			// commandOutcomeLabel
			// 
			this->commandOutcomeLabel->AutoSize = true;
			this->commandOutcomeLabel->BackColor = System::Drawing::Color::Black;
			this->commandOutcomeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commandOutcomeLabel->ForeColor = System::Drawing::Color::IndianRed;
			this->commandOutcomeLabel->Location = System::Drawing::Point(12, 493);
			this->commandOutcomeLabel->Name = L"commandOutcomeLabel";
			this->commandOutcomeLabel->Size = System::Drawing::Size(150, 17);
			this->commandOutcomeLabel->TabIndex = 5;
			this->commandOutcomeLabel->Text = L"commandOutcomeLabel";
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::Color::Black;
			this->outputBox->ForeColor = System::Drawing::Color::Black;
			this->outputBox->HideSelection = false;
			this->outputBox->Location = System::Drawing::Point(15, 70);
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(425, 401);
			this->outputBox->TabIndex = 7;
			this->outputBox->Text = L"";
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
			this->editingATaskToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addModifyATaskEntityToolStripMenuItem,
					this->removeATaskEntityToolStripMenuItem
			});
			this->editingATaskToolStripMenuItem->Name = L"editingATaskToolStripMenuItem";
			this->editingATaskToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->editingATaskToolStripMenuItem->Text = L"Edit a Task";
			// 
			// addModifyATaskEntityToolStripMenuItem
			// 
			this->addModifyATaskEntityToolStripMenuItem->Name = L"addModifyATaskEntityToolStripMenuItem";
			this->addModifyATaskEntityToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->addModifyATaskEntityToolStripMenuItem->Text = L"Add/Modify a Task entity";
			this->addModifyATaskEntityToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::addModifyATaskEntityToolStripMenuItem_Click);
			// 
			// removeATaskEntityToolStripMenuItem
			// 
			this->removeATaskEntityToolStripMenuItem->Name = L"removeATaskEntityToolStripMenuItem";
			this->removeATaskEntityToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->removeATaskEntityToolStripMenuItem->Text = L"Remove a task entity";
			this->removeATaskEntityToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::removeATaskEntityToolStripMenuItem_Click);
			// 
			// sortingScheduleToolStripMenuItem
			// 
			this->sortingScheduleToolStripMenuItem->Name = L"sortingScheduleToolStripMenuItem";
			this->sortingScheduleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sortingScheduleToolStripMenuItem->Text = L"Sort Schedule";
			this->sortingScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::sortingScheduleToolStripMenuItem_Click);
			// 
			// viewScheduleToolStripMenuItem
			// 
			this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
			this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
			this->viewScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::viewScheduleToolStripMenuItem_Click);
			// 
			// miscellneousToolStripMenuItem
			// 
			this->miscellneousToolStripMenuItem->Name = L"miscellneousToolStripMenuItem";
			this->miscellneousToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->miscellneousToolStripMenuItem->Text = L"Miscellneous";
			this->miscellneousToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::miscellneousToolStripMenuItem_Click);
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(452, 595);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->commandOutcomeLabel);
			this->Controls->Add(this->scheduleLabel);
			this->Controls->Add(this->commandInputBox);
			this->Controls->Add(this->HelpmenuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->HelpmenuStrip1;
			this->MaximizeBox = false;
			this->Name = L"iPlannerUI";
			this->Text = L"iPlanner";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &iPlannerUI::iPlannerUI_FormClosed);
			this->Load += gcnew System::EventHandler(this, &iPlannerUI::iPlannerUI_Load);
			this->HelpmenuStrip1->ResumeLayout(false);
			this->HelpmenuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//@author A0105180W 
		// Function to convert System string entered by user to std string for Logic to process
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void displayPriorityAndName(String^ priority, String^ name) {
			outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
			if (priority == "H") {
				outputBox->SelectionColor = Color::Red;
			} else if (priority == "M") {
				outputBox->SelectionColor = Color::Yellow;;
			} else if (priority == "L") {
				outputBox->SelectionColor = Color::LawnGreen;
			} else {
				outputBox->SelectionColor = Color::CadetBlue;
			}
			outputBox->SelectedText = "   " + priority;
			outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
			outputBox->SelectionColor = Color::CadetBlue;
			outputBox->SelectedText = "    " + name;
		}

		void displayCompletion(String^ completion) {
			if (completion == "(D)") {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::Gold;
				outputBox->SelectedText = " " + completion + "\r\n";
			} else {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::Silver;
				outputBox->SelectedText = " " + completion + "\r\n";
			}
		}

		void displayStartTime(String^ startTime) {
			if (startTime != "") {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::LightGoldenrodYellow;
				outputBox->SelectedText = "\t     Start : " + startTime + "\r\n";
			} else {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::LightGoldenrodYellow;
				outputBox->SelectedText = "";
			}
		}

		void displayEndTime(String^ endTime) {
			if (endTime != "") {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::LightSalmon;
				outputBox->SelectedText = "\t     End  : " + endTime + "\r\n";
			} else {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox->SelectionColor = Color::LightSalmon;
				outputBox->SelectedText = "";
			}
		}

		void displayDescription(String^ description) {
			if (description != ""){
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Italic);
				outputBox->SelectionColor = Color::BlueViolet;
				outputBox->SelectedText = "\t     " + description + "\r\n\r\n";
			} else {
				outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Italic);
				outputBox->SelectionColor = Color::BlueViolet;
				outputBox->SelectedText = "\r\n";
			}

		}

    // Function to display the Schedule when the user inputs a command
	private: System::Void commandInputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 MESSAGE_AND_SCHEDULE displayMessage;
				 Log newLog;
				 String^ userInput;
				 userInput = commandInputBox->Text;
				 string stdUserInput;
				 MarshalString(userInput, stdUserInput);
				 vector<Item> tempItem;

				 //Command entered by user is passed to Logic only when the Enter key is pressed
				 if (e->KeyCode == Keys::Enter) {
					 newLog.writeToLogFile(stdUserInput);
					 displayMessage = testLogic->initiateCommandAction(stdUserInput);
					 outputBox->Clear();
					 
					 tempItem = testLogic->getDisplaySchedule();
					 vector<Item>::iterator iterItem;
					 int displayIndex = 0;
					 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
						 
						 String ^indexString = (++displayIndex).ToString();
						 outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
						 outputBox->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox->SelectedText = indexString + ". ";

						 String^ nameString = gcnew String(iterItem->getItemName().c_str());
						 if (iterItem->getPriority() == 72) {
							 displayPriorityAndName("H", nameString);
                         } else if (iterItem->getPriority() == 77) {
							 displayPriorityAndName("M", nameString);
						 } else if (iterItem->getPriority() == 76) {
							 displayPriorityAndName("L", nameString);
						 } else {
							 displayPriorityAndName("-", nameString);
						 }
						 
						 if (iterItem->getCompletion() == true) {
							 displayCompletion("(D)");
						 } else {
							 displayCompletion("(ND)");
						 }

						 String^ startString = gcnew String(iterItem->displayStartTimeForUser().c_str());
						 displayStartTime(startString);

						 String^ endString = gcnew String(iterItem->displayEndTimeForUser().c_str());
						 displayEndTime(endString);

						 String^ descriptionString = gcnew String(iterItem->getDescription().c_str());
						 displayDescription(descriptionString);

					 }

					 String^ outcomeString = gcnew String(displayMessage.message.c_str());
					 commandOutcomeLabel->Text = outcomeString;
					 outputBox->SelectionStart = 0;
					 newLog.writeToLogFile("");
					 commandInputBox->Clear();
				 }

	}
	
    // Function to display Schedule when the program is opened
	private: System::Void iPlannerUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 Log newLog;
				 newLog.clearLogFile();
				 newLog.writeToLogFile("Log file opened");
				 
				 testLogic->retrieveBasicInformationFromTextFile();
				 testLogic->readDataFromFile();
				 
				 outputBox->Clear();			
				 vector<Item> tempItem = testLogic->getDisplaySchedule();
				 vector<Item>::iterator iterItem;
				 int displayIndex = 0;
				 
				 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
					 
					 String ^indexString = (++displayIndex).ToString();
					 outputBox->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
					 outputBox->SelectionColor = System::Drawing::Color::CadetBlue;
					 outputBox->SelectedText = indexString + ". ";

					 String^ nameString = gcnew String(iterItem->getItemName().c_str());
					 if (iterItem->getPriority() == 72) {
						 displayPriorityAndName("H", nameString);
					 }
					 else if (iterItem->getPriority() == 77) {
						 displayPriorityAndName("M", nameString);
					 }
					 else if (iterItem->getPriority() == 76) {
						 displayPriorityAndName("L", nameString);
					 }
					 else {
						 displayPriorityAndName("-", nameString);
					 }

					 if (iterItem->getCompletion() == true) {
						 displayCompletion("(D)");
					 }
					 else {
						 displayCompletion("(ND)");
					 }

					 String^ startString = gcnew String(iterItem->displayStartTimeForUser().c_str());
					 displayStartTime(startString);

					 String^ endString = gcnew String(iterItem->displayEndTimeForUser().c_str());
					 displayEndTime(endString);

					 String^ descriptionString = gcnew String(iterItem->getDescription().c_str());
					 displayDescription(descriptionString);
				 }
				 outputBox->SelectionStart = 0;
				 commandOutcomeLabel->Text = "Enter the command";

	}

	// Below functions display the list of commands for the user's reference
	private: System::Void basicCommandsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuAdd = "\t\t            Add a Task Commands\r\n";

				 helpMenuAdd += "\r\nadd <taskName> followed by task entities\r\n\r\n";
				 helpMenuAdd += "The task entities could be entered with the following sub-commands : \r\n";
				 helpMenuAdd += "Starting Time of Task : -start <DateTime> or -date <DateTime>\r\n";
				 helpMenuAdd += "Ending Time of Task :  -end <DateTime> or -due <DateTime>\r\n";
				 helpMenuAdd += "Task Description : -desc <Description>\r\n";
				 helpMenuAdd += "Task Priority : -priority <High/Medium/Low>  or -priority <H/M/L>\r\n";
				 helpMenuAdd += "\r\nNote : For adding or editing start and end times simultaneously, only -start and -end can be used together\r\n";
				 helpMenuAdd += "\r\nTo refer possible <DateTime> variations, Help -> Adding a Task -> Date and Time Variations";

				 MessageBox::Show(helpMenuAdd);
	}

	private: System::Void dateAndTimeVariationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuDT;
				 
				 helpMenuDT += "\t\t           <DateTime> Variations\r\n";
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
				 String^ helpMenuDel = "                 Delete a Task Commands\r\n";

				 helpMenuDel += "\r\ndelete <Display index of task to be deleted>\r\n";
				 helpMenuDel += "del <Display index of task to be deleted>\r\n";
				 helpMenuDel += "\r\nDelete all tasks in the Schedule : clear\r\n";
				 
				 MessageBox::Show(helpMenuDel);
	}

	private: System::Void addModifyATaskEntityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuEditAdd = "\t\tEditing a Task - Add or Modify a Task Entity\r\n";

				 helpMenuEditAdd += "\r\nedit <Display index of task to be edited> sub-command <New value of entity>";
				 helpMenuEditAdd += "Task entities can be edited with the same sub-commands that function with Add\r\n";
				 helpMenuEditAdd += "Task Name : -name <newTaskName>";
				 helpMenuEditAdd += "Starting Time of Task : -start <newDateTime> or -date <newDateTime>\r\n";
				 helpMenuEditAdd += "Ending Time of Task :  -end <newDateTime> or -due <newDateTime>\r\n";
				 helpMenuEditAdd += "Task Description : -desc <newDescription>\r\n";
				 helpMenuEditAdd += "Task Priority : -priority <newPriority>\r\n";

				 MessageBox::Show(helpMenuEditAdd);
	}

	private: System::Void removeATaskEntityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuEditRmv = "\t\t    Editing a Task - Remove a Task Entity\r\n";

				 helpMenuEditRmv += "\r\nPreviously entered Date & Time, Description and Priority can be removed with \nedit, preceeded by the sub-command -remove or -rmv\r\n";
				 helpMenuEditRmv += "\r\nRemove Start and End times of task : edit <Display index of task to be edited> -rmv date\r\n";
				 helpMenuEditRmv += "Remove Start Time of task : edit <Display index of task to be edited> -rmv start\r\n";
				 helpMenuEditRmv += "Remove End Time of task : edit <Display index of task to be edited> -rmv end\r\n";
				 helpMenuEditRmv += "Remove Description of Task : edit <Display index of task to be edited> -rmv description or desc\r\n";
				 helpMenuEditRmv += "Remove Priority of Task : edit <Display index of task to be edited> -rmv priority or <p>\r\n";
				 MessageBox::Show(helpMenuEditRmv);
	}

	private: System::Void sortingScheduleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuSort = "\t\t       Sort Schedule Commands\r\n";

				 helpMenuSort += "\r\nThe Schedule can be sorted by the following attributes : \r\n";
				 helpMenuSort += "By Task Name : sort name - Sorts Tasks by Name in alphabetical order\r\n";
				 helpMenuSort += "By Task Date : sort date - Sorts Tasks by Date in ascending order\r\n";
				 helpMenuSort += "By Task Priority : sort priority - Sorts Tasks by Priority in the order of High, Medium, Low\r\n";
				 helpMenuSort += "By Task Completion : sort completion - Sorts Tasks by completed Tasks\r\n";
				 helpMenuSort += "Task Updated Order : sort update - Sorts Tasks by the order in which Tasks were added\r\n";

				 MessageBox::Show(helpMenuSort);
	}

	private: System::Void viewScheduleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuView = "\t\t       View Schedule Commands\r\n";

				 helpMenuView += "\r\nUser can view All tasks, Tasks within a given range of dates, Completed tasks or tasks with a specific Priority\r\n";
				 helpMenuView += "\r\nview all - All tasks in the Schedule are displayed\r\n";
				 helpMenuView += "view <date1> <date2> - All tasks in the specified date range are displayed\r\n";
				 helpMenuView += "view done - Tasks which are completed are displayed\r\n";
				 helpMenuView += "view undone - Tasks which are not completed are displayed\r\n";
				 helpMenuView += "view <H/M/L> - Tasks which have the priority specified are displayed\r\n";

				 MessageBox::Show(helpMenuView);

	}

	private: System::Void miscellneousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuMisc = "\t\t\tOther Commands\r\n";

				 helpMenuMisc += "\r\nSearch\r\n";
				 helpMenuMisc += "Search a single keyword : search <keyword to be searched> - Keyword can be either a Task Name or Task Description\r\n";
				 helpMenuMisc += "Search multiple keywords : search <keyword1> + <keyword2> + ...\r\n";
				 helpMenuMisc += "\r\nMark Task as Completed\r\n";
				 helpMenuMisc += "done <Display index of completed task>\r\n";
				 helpMenuMisc += "\r\nMark Task as Not Completed\r\n";
				 helpMenuMisc += "undone <Display index of completed task>\r\n";
				 helpMenuMisc += "\r\nUndo Last Action\r\n";
				 helpMenuMisc += "undo\r\n";
				 helpMenuMisc += "\r\nChange Save Directory\r\n";
				 helpMenuMisc += "save <Address of new location to store the .txt file>\r\n";
				 helpMenuMisc += "\r\nExit Application\r\n";
				 helpMenuMisc += "exit\r\n";

				 MessageBox::Show(helpMenuMisc);
	}
		
	// Function to write to log file that that the user has exited if the user closes using the close button
	private: System::Void iPlannerUI_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 Log closeLog;
				 closeLog.writeToLogFile("exit");
	}

};
}