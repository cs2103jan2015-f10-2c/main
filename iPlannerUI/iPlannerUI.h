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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::PeachPuff;
			this->label1->Location = System::Drawing::Point(184, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 21);
			this->label1->TabIndex = 4;
			this->label1->Text = L"SCHEDULE";
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
			// outputBox2
			// 
			this->outputBox2->BackColor = System::Drawing::SystemColors::MenuText;
			this->outputBox2->ForeColor = System::Drawing::Color::White;
			this->outputBox2->HideSelection = false;
			this->outputBox2->Location = System::Drawing::Point(15, 70);
			this->outputBox2->Name = L"outputBox2";
			this->outputBox2->ReadOnly = true;
			this->outputBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->outputBox2->Size = System::Drawing::Size(425, 401);
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
			this->addingATaskToolStripMenuItem->Size = System::Drawing::Size(150, 22);
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
			this->deletingATaskToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->deletingATaskToolStripMenuItem->Text = L"Delete a Task";
			this->deletingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::deletingATaskToolStripMenuItem_Click);
			// 
			// editingATaskToolStripMenuItem
			// 
			this->editingATaskToolStripMenuItem->Name = L"editingATaskToolStripMenuItem";
			this->editingATaskToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->editingATaskToolStripMenuItem->Text = L"Edit a Task";
			this->editingATaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::editingATaskToolStripMenuItem_Click);
			// 
			// sortingScheduleToolStripMenuItem
			// 
			this->sortingScheduleToolStripMenuItem->Name = L"sortingScheduleToolStripMenuItem";
			this->sortingScheduleToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->sortingScheduleToolStripMenuItem->Text = L"Sort Schedule";
			this->sortingScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::sortingScheduleToolStripMenuItem_Click);
			// 
			// viewScheduleToolStripMenuItem
			// 
			this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
			this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
			this->viewScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::viewScheduleToolStripMenuItem_Click);
			// 
			// miscellneousToolStripMenuItem
			// 
			this->miscellneousToolStripMenuItem->Name = L"miscellneousToolStripMenuItem";
			this->miscellneousToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->miscellneousToolStripMenuItem->Text = L"Miscellneous";
			this->miscellneousToolStripMenuItem->Click += gcnew System::EventHandler(this, &iPlannerUI::miscellneousToolStripMenuItem_Click);
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(452, 595);
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
			this->Text = L"iPlanner";
			this->Load += gcnew System::EventHandler(this, &iPlannerUI::iPlannerUI_Load);
			this->HelpmenuStrip1->ResumeLayout(false);
			this->HelpmenuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//@author A0105180W 
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void displayPriorityAndName(String^ priority, String^ name) {
			outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
			if (priority == "H") {
				outputBox2->SelectionColor = Color::Red;
			} else if (priority == "M") {
				outputBox2->SelectionColor = Color::Yellow;;
			} else if (priority == "L") {
				outputBox2->SelectionColor = Color::LawnGreen;
			} else {
				outputBox2->SelectionColor = Color::CadetBlue;
			}
			outputBox2->SelectedText = "   " + priority;
			outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
			outputBox2->SelectionColor = Color::CadetBlue;
			outputBox2->SelectedText = "    " + name;
		}

		void displayCompletion(String^ completion) {
			if (completion == "(D)") {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::Gold;
				outputBox2->SelectedText = " " + completion + "\r\n";
			}
			else {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::Silver;
				outputBox2->SelectedText = " " + completion + "\r\n";
			}
		}

		void displayStartTime(String^ startTime) {
			if (startTime != "") {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::LightGoldenrodYellow;
				outputBox2->SelectedText = "\t     Start : " + startTime + "\r\n";
			}
			else {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::LightGoldenrodYellow;
				outputBox2->SelectedText = "";
			}
		}

		void displayEndTime(String^ endTime) {
			if (endTime != "") {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::LightSalmon;
				outputBox2->SelectedText = "\t     End  : " + endTime + "\r\n";
			}
			else {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
				outputBox2->SelectionColor = Color::LightSalmon;
				outputBox2->SelectedText = "";
			}
		}

		void displayDescription(String^ description) {
			if (description != ""){
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Italic);
				outputBox2->SelectionColor = Color::BlueViolet;
				outputBox2->SelectedText = "\t     " + description + "\r\n\r\n";
			}
			else {
				outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Italic);
				outputBox2->SelectionColor = Color::BlueViolet;
				outputBox2->SelectedText = "\r\n";
			}

		}

	private: System::Void commandInputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 MESSAGE_AND_SCHEDULE displayMessage;
				 iParser testParser;
				 String^ userInput;
				 userInput = commandInputBox->Text;
				 string stdUserInput;
				 MarshalString(userInput, stdUserInput);
				 vector<Item> tempItem;

				 if (e->KeyCode == Keys::Enter) {
					 displayMessage = testLogic->initiateCommandAction(testParser, stdUserInput);
					 outputBox2->Clear();
					 
					 tempItem = testLogic->getDisplaySchedule();
					 vector<Item>::iterator iterItem;
					 int displayIndex = 0;
					 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
						 
						 String ^indexString = (++displayIndex).ToString();
						 outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
						 outputBox2->SelectionColor = System::Drawing::Color::CadetBlue;
						 outputBox2->SelectedText = indexString + ". ";

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
					 outputBox2->SelectionStart = 0;
					 outputBox2->ScrollToCaret();
					 commandInputBox->Clear();
				 }

	}
			 
	private: System::Void iPlannerUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 Log newLog;
				 newLog.clearLogFile();
				 newLog.writeToLogFile("\nLog file created");
				 
				 testLogic->retrieveBasicInformationFromTextFile();
				 testLogic->readDataFromFile();
				 
				 outputBox2->Clear();			
				 vector<Item> tempItem;
				 vector<Item>::iterator iterItem;
				 int displayIndex = 0;
				 				 				 
				 for (iterItem = tempItem.begin(); iterItem != tempItem.end(); iterItem++) {
					 
					 String ^indexString = (++displayIndex).ToString();
					 outputBox2->SelectionFont = gcnew System::Drawing::Font("Segoe UI", 10);
					 outputBox2->SelectionColor = Color::CadetBlue;
					 outputBox2->SelectedText = indexString + ". ";

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
				 outputBox2->SelectionStart = 0;
				 outputBox2->ScrollToCaret();
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
				 helpMenuEdit += "\r\nPreviously entered Date & Time and Description can be removed\r\n";
				 helpMenuEdit += "edit <Display index of task to be edited> rmv <date> - Start and End Times of the task are removed\r\n";
				 helpMenuEdit += "edit <Display index of task to be edited> rmv <desc> - Description of the task is removed\r\n";

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
				 helpMenuMisc += "\r\nChange Save Direcotry\r\n";
				 helpMenuMisc += "save <Address of new location to store the .txt file>\r\n";
				 helpMenuMisc += "\r\nExit Application\r\n";
				 helpMenuMisc += "exit\r\n";

				 MessageBox::Show(helpMenuMisc);
	}
	
	private: System::Void viewScheduleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ helpMenuView = "\t\t\tView Schedule - Command List\r\n";

				 helpMenuView += "\r\nUser can view All tasks, Completed tasks or tasks with a specific Priority\r\n";
				 helpMenuView += "\r\nview all - All tasks in the Schedule are displayed\r\n";
				 helpMenuView += "view done - Tasks which are completed are displayed\r\n";
				 helpMenuView += "view undone - Tasks which are not completed are displayed\r\n";
				 helpMenuView += "view priority <H/M/L> - Tasks which have the priority specified are displayed\r\n";
				 
				 MessageBox::Show(helpMenuView);

	}
	
};
}