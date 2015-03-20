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
	public ref class iPlannerUI : public System::Windows::Forms::Form
	{
	public:
		iPlannerUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			}
		}
	private: System::Windows::Forms::TextBox^  commandInputBox;
	private: System::Windows::Forms::TableLayoutPanel^  ScheduleListTable;
	private: System::Windows::Forms::TextBox^  CommandListDisplayBox;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^  commandOutputBox;


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
			this->ScheduleListTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CommandListDisplayBox = (gcnew System::Windows::Forms::TextBox());
			this->commandOutputBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// commandInputBox
			// 
			this->commandInputBox->Location = System::Drawing::Point(12, 288);
			this->commandInputBox->Name = L"commandInputBox";
			this->commandInputBox->Size = System::Drawing::Size(656, 20);
			this->commandInputBox->TabIndex = 0;
			// 
			// ScheduleListTable
			// 
			this->ScheduleListTable->AutoScroll = true;
			this->ScheduleListTable->ColumnCount = 5;
			this->ScheduleListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				9.305994F)));
			this->ScheduleListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				90.69401F)));
			this->ScheduleListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				101)));
			this->ScheduleListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				98)));
			this->ScheduleListTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				60)));
			this->ScheduleListTable->Location = System::Drawing::Point(12, 33);
			this->ScheduleListTable->Name = L"ScheduleListTable";
			this->ScheduleListTable->RowCount = 2;
			this->ScheduleListTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.70588F)));
			this->ScheduleListTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 85.29412F)));
			this->ScheduleListTable->Size = System::Drawing::Size(655, 238);
			this->ScheduleListTable->TabIndex = 1;
			// 
			// CommandListDisplayBox
			// 
			this->CommandListDisplayBox->Location = System::Drawing::Point(12, 342);
			this->CommandListDisplayBox->Multiline = true;
			this->CommandListDisplayBox->Name = L"CommandListDisplayBox";
			this->CommandListDisplayBox->Size = System::Drawing::Size(655, 71);
			this->CommandListDisplayBox->TabIndex = 2;
			// 
			// commandOutputBox
			// 
			this->commandOutputBox->Location = System::Drawing::Point(12, 314);
			this->commandOutputBox->Name = L"commandOutputBox";
			this->commandOutputBox->Size = System::Drawing::Size(409, 20);
			this->commandOutputBox->TabIndex = 3;
			// 
			// iPlannerUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 438);
			this->Controls->Add(this->commandOutputBox);
			this->Controls->Add(this->CommandListDisplayBox);
			this->Controls->Add(this->ScheduleListTable);
			this->Controls->Add(this->commandInputBox);
			this->Name = L"iPlannerUI";
			this->Text = L"iPlannerUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
