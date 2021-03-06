#pragma once

/*
Author: Shane Vance
Last Update: 2018/29/01
Purpose: CS 481 Project
*/

#include "OpenGL.h"
#include <string>
#include "Settings.h"

namespace VisCanvas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// Summary for VisCanvas
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class VisCanvas : public System::Windows::Forms::Form {

	public:

		VisCanvas(void) {
			InitializeComponent();		
			/* Setup OpenGL for this Parent Window */
			OpenGL = gcnew COpenGL(this, this->Width, this->Height);
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VisCanvas() {
			if (components) {
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;
	protected: 

		// TIMER FOR PAINTING OPENGL
	private: System::Windows::Forms::Timer^  timer1;

			 // STATUS STRIP
	private: System::Windows::Forms::StatusStrip^  statusStrip1;

			 // PANELS
	private: System::Windows::Forms::Panel^  Tools;
	private: System::Windows::Forms::Panel^  Options;

			 // CHECK LIST ITEMS
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;

			 // LABELS
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

			 // COLOR SELECTOR
			 // CLASS SELECTOR
	private: Nevron::Nov::WinFormControls::NColorBoxControl^  nColorBoxControl1; // BACKGROUND SELECTOR

			 // I DO NOT KNOW WHAT THIS IS FOR
	private: System::Windows::Forms::TextBox^  textBox1;	

			 // MENU BAR ITEMS
	private: System::Windows::Forms::MenuStrip^  menubar;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;	
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  reorderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  descendSortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorblindFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ascendSortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;	
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  meanLevelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medianLevelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  originalDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  dimensionShiftingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortOriginalToolStripMenuItem;


			 // TOOL BUTTONS
	private: Nevron::Nov::WinFormControls::NButtonControl^  sortDescendingButtonControl2;
	private: Nevron::Nov::WinFormControls::NButtonControl^  sortOriginalButtonControl3;
	private: Nevron::Nov::WinFormControls::NButtonControl^  meanButtonControl1;
	private: Nevron::Nov::WinFormControls::NToggleButtonControl^  manualShiftToggleButtonControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  sortAscendingButtonControl1;
	private: Nevron::Nov::WinFormControls::NToggleButtonControl^  manualSortToggleButtonControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  originalDataButtonControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  medianButtonControl1;

	private: Nevron::Nov::WinFormControls::NHsbColorPickerControl^  nHsbColorPickerControl1;
	private: Nevron::Nov::WinFormControls::NButtonControl^  hypercubeButtonControl1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  hypercubeToolStripMenuItem;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VisCanvas::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menubar = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->colorblindFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reorderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dimensionShiftingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ascendSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descendSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortOriginalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->meanLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medianLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->originalDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tools = (gcnew System::Windows::Forms::Panel());
			this->hypercubeButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->originalDataButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->medianButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->meanButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->manualShiftToggleButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NToggleButtonControl());
			this->sortOriginalButtonControl3 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->nColorBoxControl1 = (gcnew Nevron::Nov::WinFormControls::NColorBoxControl());
			this->sortDescendingButtonControl2 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->sortAscendingButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NButtonControl());
			this->manualSortToggleButtonControl1 = (gcnew Nevron::Nov::WinFormControls::NToggleButtonControl());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Options = (gcnew System::Windows::Forms::Panel());
			this->nHsbColorPickerControl1 = (gcnew Nevron::Nov::WinFormControls::NHsbColorPickerControl());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->hypercubeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menubar->SuspendLayout();
			this->Tools->SuspendLayout();
			this->Options->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &VisCanvas::timer1_Tick);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 667);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1184, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menubar
			// 
			this->menubar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->viewToolStripMenuItem, this->toolsToolStripMenuItem1, this->helpToolStripMenuItem});
			this->menubar->Location = System::Drawing::Point(0, 0);
			this->menubar->Name = L"menubar";
			this->menubar->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menubar->Size = System::Drawing::Size(1184, 24);
			this->menubar->TabIndex = 1;
			this->menubar->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->toolStripMenuItem4, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(149, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolsToolStripMenuItem, 
				this->optionsToolStripMenuItem, this->toolStripMenuItem3, this->colorblindFilterToolStripMenuItem, this->toolStripMenuItem1, 
				this->settingsToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Checked = true;
			this->toolsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::T));
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->toolsToolStripMenuItem->Text = L"Tools Panel";
			this->toolsToolStripMenuItem->ToolTipText = L"Tools Panel";
			this->toolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::toolsToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Checked = true;
			this->optionsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt) 
				| System::Windows::Forms::Keys::O));
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->optionsToolStripMenuItem->Text = L"Options Panel";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::classesToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(211, 6);
			// 
			// colorblindFilterToolStripMenuItem
			// 
			this->colorblindFilterToolStripMenuItem->Name = L"colorblindFilterToolStripMenuItem";
			this->colorblindFilterToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->colorblindFilterToolStripMenuItem->Text = L"Colorblind Filter";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(211, 6);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(214, 22);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::settingsToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem1
			// 
			this->toolsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->reorderToolStripMenuItem, 
				this->dimensionShiftingToolStripMenuItem, this->toolStripMenuItem6, this->ascendSortToolStripMenuItem, this->descendSortToolStripMenuItem, 
				this->sortOriginalToolStripMenuItem, this->toolStripMenuItem2, this->hypercubeToolStripMenuItem, this->toolStripMenuItem5, this->meanLevelToolStripMenuItem, 
				this->medianLevelToolStripMenuItem, this->originalDataToolStripMenuItem});
			this->toolsToolStripMenuItem1->Name = L"toolsToolStripMenuItem1";
			this->toolsToolStripMenuItem1->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem1->Text = L"Tools";
			// 
			// reorderToolStripMenuItem
			// 
			this->reorderToolStripMenuItem->Name = L"reorderToolStripMenuItem";
			this->reorderToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->reorderToolStripMenuItem->Text = L"Manual Sort";
			// 
			// dimensionShiftingToolStripMenuItem
			// 
			this->dimensionShiftingToolStripMenuItem->Name = L"dimensionShiftingToolStripMenuItem";
			this->dimensionShiftingToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->dimensionShiftingToolStripMenuItem->Text = L"Manual Shift";
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(157, 6);
			// 
			// ascendSortToolStripMenuItem
			// 
			this->ascendSortToolStripMenuItem->Name = L"ascendSortToolStripMenuItem";
			this->ascendSortToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->ascendSortToolStripMenuItem->Text = L"Sort Ascending";
			this->ascendSortToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::sortingToolStripMenuItem_Click);
			// 
			// descendSortToolStripMenuItem
			// 
			this->descendSortToolStripMenuItem->Name = L"descendSortToolStripMenuItem";
			this->descendSortToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->descendSortToolStripMenuItem->Text = L"Sort Descending";
			this->descendSortToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::descendSortToolStripMenuItem_Click);
			// 
			// sortOriginalToolStripMenuItem
			// 
			this->sortOriginalToolStripMenuItem->Name = L"sortOriginalToolStripMenuItem";
			this->sortOriginalToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->sortOriginalToolStripMenuItem->Text = L"Sort Original";
			this->sortOriginalToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::sortOriginalToolStripMenuItem_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(157, 6);
			// 
			// meanLevelToolStripMenuItem
			// 
			this->meanLevelToolStripMenuItem->Name = L"meanLevelToolStripMenuItem";
			this->meanLevelToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->meanLevelToolStripMenuItem->Text = L"Mean Level";
			this->meanLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::meanLevelToolStripMenuItem_Click);
			// 
			// medianLevelToolStripMenuItem
			// 
			this->medianLevelToolStripMenuItem->Name = L"medianLevelToolStripMenuItem";
			this->medianLevelToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->medianLevelToolStripMenuItem->Text = L"Median Level";
			this->medianLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::medianLevelToolStripMenuItem_Click);
			// 
			// originalDataToolStripMenuItem
			// 
			this->originalDataToolStripMenuItem->Name = L"originalDataToolStripMenuItem";
			this->originalDataToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->originalDataToolStripMenuItem->Text = L"Reset";
			this->originalDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::originalDataToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->aboutToolStripMenuItem, 
				this->helpToolStripMenuItem1});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisCanvas::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// Tools
			// 
			this->Tools->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Tools->Controls->Add(this->hypercubeButtonControl1);
			this->Tools->Controls->Add(this->originalDataButtonControl1);
			this->Tools->Controls->Add(this->medianButtonControl1);
			this->Tools->Controls->Add(this->meanButtonControl1);
			this->Tools->Controls->Add(this->manualShiftToggleButtonControl1);
			this->Tools->Controls->Add(this->sortOriginalButtonControl3);
			this->Tools->Controls->Add(this->nColorBoxControl1);
			this->Tools->Controls->Add(this->sortDescendingButtonControl2);
			this->Tools->Controls->Add(this->sortAscendingButtonControl1);
			this->Tools->Controls->Add(this->manualSortToggleButtonControl1);
			this->Tools->Controls->Add(this->label4);
			this->Tools->Dock = System::Windows::Forms::DockStyle::Left;
			this->Tools->Location = System::Drawing::Point(0, 24);
			this->Tools->Name = L"Tools";
			this->Tools->Size = System::Drawing::Size(69, 643);
			this->Tools->TabIndex = 2;
			// 
			// hypercubeButtonControl1
			// 
			this->hypercubeButtonControl1->AutoSize = false;
			this->hypercubeButtonControl1->DesignTimeState = resources->GetString(L"hypercubeButtonControl1.DesignTimeState");
			this->hypercubeButtonControl1->Location = System::Drawing::Point(15, 332);
			this->hypercubeButtonControl1->Name = L"hypercubeButtonControl1";
			this->hypercubeButtonControl1->Size = System::Drawing::Size(40, 40);
			this->hypercubeButtonControl1->TabIndex = 21;
			this->hypercubeButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::hypercubeButtonControl1_Click);
			// 
			// originalDataButtonControl1
			// 
			this->originalDataButtonControl1->AutoSize = false;
			this->originalDataButtonControl1->DesignTimeState = resources->GetString(L"originalDataButtonControl1.DesignTimeState");
			this->originalDataButtonControl1->Location = System::Drawing::Point(7, 514);
			this->originalDataButtonControl1->Name = L"originalDataButtonControl1";
			this->originalDataButtonControl1->Size = System::Drawing::Size(54, 40);
			this->originalDataButtonControl1->TabIndex = 20;
			this->originalDataButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::nButtonControl1_Click);
			// 
			// medianButtonControl1
			// 
			this->medianButtonControl1->AutoSize = false;
			this->medianButtonControl1->DesignTimeState = resources->GetString(L"medianButtonControl1.DesignTimeState");
			this->medianButtonControl1->Location = System::Drawing::Point(7, 452);
			this->medianButtonControl1->Name = L"medianButtonControl1";
			this->medianButtonControl1->Size = System::Drawing::Size(55, 40);
			this->medianButtonControl1->TabIndex = 19;
			this->medianButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::medianButtonControl1_Click);
			// 
			// meanButtonControl1
			// 
			this->meanButtonControl1->AutoSize = false;
			this->meanButtonControl1->DesignTimeState = resources->GetString(L"meanButtonControl1.DesignTimeState");
			this->meanButtonControl1->Location = System::Drawing::Point(6, 390);
			this->meanButtonControl1->Name = L"meanButtonControl1";
			this->meanButtonControl1->Size = System::Drawing::Size(56, 40);
			this->meanButtonControl1->TabIndex = 17;
			this->meanButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::meanButtonControl1_Click);
			// 
			// manualShiftToggleButtonControl1
			// 
			this->manualShiftToggleButtonControl1->AutoSize = false;
			this->manualShiftToggleButtonControl1->DesignTimeState = resources->GetString(L"manualShiftToggleButtonControl1.DesignTimeState");
			this->manualShiftToggleButtonControl1->Location = System::Drawing::Point(15, 98);
			this->manualShiftToggleButtonControl1->Name = L"manualShiftToggleButtonControl1";
			this->manualShiftToggleButtonControl1->Size = System::Drawing::Size(40, 40);
			this->manualShiftToggleButtonControl1->TabIndex = 16;
			// 
			// sortOriginalButtonControl3
			// 
			this->sortOriginalButtonControl3->AutoSize = false;
			this->sortOriginalButtonControl3->DesignTimeState = resources->GetString(L"sortOriginalButtonControl3.DesignTimeState");
			this->sortOriginalButtonControl3->Location = System::Drawing::Point(15, 274);
			this->sortOriginalButtonControl3->Name = L"sortOriginalButtonControl3";
			this->sortOriginalButtonControl3->Size = System::Drawing::Size(40, 40);
			this->sortOriginalButtonControl3->TabIndex = 15;
			this->sortOriginalButtonControl3->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::sortOriginalButtonControl3_Click);
			// 
			// nColorBoxControl1
			// 
			this->nColorBoxControl1->AutoSize = false;
			this->nColorBoxControl1->DesignTimeState = resources->GetString(L"nColorBoxControl1.DesignTimeState");
			this->nColorBoxControl1->Location = System::Drawing::Point(6, 575);
			this->nColorBoxControl1->Name = L"nColorBoxControl1";
			this->nColorBoxControl1->Size = System::Drawing::Size(56, 40);
			this->nColorBoxControl1->TabIndex = 13;
			this->nColorBoxControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::nColorBoxControl1_SelectedColorChanged);
			// 
			// sortDescendingButtonControl2
			// 
			this->sortDescendingButtonControl2->AutoSize = false;
			this->sortDescendingButtonControl2->DesignTimeState = resources->GetString(L"sortDescendingButtonControl2.DesignTimeState");
			this->sortDescendingButtonControl2->Location = System::Drawing::Point(15, 216);
			this->sortDescendingButtonControl2->Name = L"sortDescendingButtonControl2";
			this->sortDescendingButtonControl2->Size = System::Drawing::Size(40, 40);
			this->sortDescendingButtonControl2->TabIndex = 12;
			this->sortDescendingButtonControl2->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::sortDescendingButtonControl2_Click);
			// 
			// sortAscendingButtonControl1
			// 
			this->sortAscendingButtonControl1->AutoSize = false;
			this->sortAscendingButtonControl1->DesignTimeState = resources->GetString(L"sortAscendingButtonControl1.DesignTimeState");
			this->sortAscendingButtonControl1->Location = System::Drawing::Point(15, 156);
			this->sortAscendingButtonControl1->Name = L"sortAscendingButtonControl1";
			this->sortAscendingButtonControl1->Size = System::Drawing::Size(40, 40);
			this->sortAscendingButtonControl1->TabIndex = 11;
			this->sortAscendingButtonControl1->Click += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NEventArgs^ >(this, &VisCanvas::sortAscendingButtonControl1_Click);
			// 
			// manualSortToggleButtonControl1
			// 
			this->manualSortToggleButtonControl1->AutoSize = false;
			this->manualSortToggleButtonControl1->DesignTimeState = resources->GetString(L"manualSortToggleButtonControl1.DesignTimeState");
			this->manualSortToggleButtonControl1->Location = System::Drawing::Point(15, 38);
			this->manualSortToggleButtonControl1->Name = L"manualSortToggleButtonControl1";
			this->manualSortToggleButtonControl1->Size = System::Drawing::Size(40, 40);
			this->manualSortToggleButtonControl1->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(52, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"x";
			this->label4->Click += gcnew System::EventHandler(this, &VisCanvas::label4_Click);
			this->label4->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::leavingToolBoxHoverColor1);
			this->label4->MouseHover += gcnew System::EventHandler(this, &VisCanvas::toolBoxExitHoverColor1);
			// 
			// Options
			// 
			this->Options->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Options->BackColor = System::Drawing::SystemColors::Control;
			this->Options->Controls->Add(this->nHsbColorPickerControl1);
			this->Options->Controls->Add(this->checkedListBox1);
			this->Options->Controls->Add(this->label5);
			this->Options->Controls->Add(this->textBox1);
			this->Options->Dock = System::Windows::Forms::DockStyle::Right;
			this->Options->Location = System::Drawing::Point(1039, 24);
			this->Options->Name = L"Options";
			this->Options->Size = System::Drawing::Size(145, 643);
			this->Options->TabIndex = 3;
			this->Options->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisCanvas::Classes_Paint);
			// 
			// nHsbColorPickerControl1
			// 
			this->nHsbColorPickerControl1->AutoSize = false;
			this->nHsbColorPickerControl1->DesignTimeState = nullptr;
			this->nHsbColorPickerControl1->Location = System::Drawing::Point(8, 199);
			this->nHsbColorPickerControl1->Name = L"nHsbColorPickerControl1";
			this->nHsbColorPickerControl1->Size = System::Drawing::Size(130, 115);
			this->nHsbColorPickerControl1->TabIndex = 17;
			this->nHsbColorPickerControl1->SelectedColorChanged += gcnew Nevron::Nov::Function<Nevron::Nov::Dom::NValueChangeEventArgs^ >(this, &VisCanvas::nHsbColorPickerControl1_SelectedColorChanged);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Class 1", L"Class 2", L"Class 3", L"Class 4", 
				L"Class 5"});
			this->checkedListBox1->Location = System::Drawing::Point(8, 63);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(130, 106);
			this->checkedListBox1->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(128, 2);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 17);
			this->label5->TabIndex = 16;
			this->label5->Text = L"x";
			this->label5->Click += gcnew System::EventHandler(this, &VisCanvas::label5_Click);
			this->label5->MouseLeave += gcnew System::EventHandler(this, &VisCanvas::label5_MouseLeave);
			this->label5->MouseHover += gcnew System::EventHandler(this, &VisCanvas::label5_MouseHover);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(8, 320);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(130, 27);
			this->textBox1->TabIndex = 12;
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(157, 6);
			// 
			// hypercubeToolStripMenuItem
			// 
			this->hypercubeToolStripMenuItem->Name = L"hypercubeToolStripMenuItem";
			this->hypercubeToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->hypercubeToolStripMenuItem->Text = L"Hypercube";
			// 
			// VisCanvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(1184, 689);
			this->Controls->Add(this->Options);
			this->Controls->Add(this->Tools);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menubar);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menubar;
			this->MinimumSize = System::Drawing::Size(900, 600);
			this->Name = L"VisCanvas";
			this->Text = L"VisCanvas";
			this->Load += gcnew System::EventHandler(this, &VisCanvas::VisCanvas_Load);
			this->Resize += gcnew System::EventHandler(this, &VisCanvas::ResizeMe);
			this->menubar->ResumeLayout(false);
			this->menubar->PerformLayout();
			this->Tools->ResumeLayout(false);
			this->Tools->PerformLayout();
			this->Options->ResumeLayout(false);
			this->Options->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/* PAINTS TO THE VIEWING WINDOW */
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 // display our OpenGL to the Parent Form

				 if (this->Options->Visible) {
					 OpenGL->ReshapeToPanels(this->Width - (this->Options->Width), this->Height);
				 } else {
					 OpenGL->ReshapeToPanels(this->Width, this->Height);
				 }

				 OpenGL->Render();	
				 OpenGL->SwapOpenGLBuffers();				 
			 }
			 /* THIS WILL RESIZE THE SCREEN */
	private: System::Void ResizeMe(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->Resize(0, 0, this->Width, this->Height, SWP_NOSENDCHANGING | SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
			 }
			 /* CREATES A CHECKED OR UNCHECKED STATE - OPTIONS PANEL */
	private: System::Void classesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 optionPanel();
			 }
			 /* TODO: UPDATE THIS MAYBE? */
	private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

			 /* THIS IS FOR THE OPEN DIALOGBOX */
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 openFile();
			 }

			 /* NOT USING ANYMORE */
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

			 }

	private: System::Void Classes_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }

			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void toolBoxExitHoverColor1(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label4->ForeColor = System::Drawing::Color::LightGray;		 
			 }
			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void leavingToolBoxHoverColor1(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label4->ForeColor = System::Drawing::Color::Black;		 
			 }
			 /* TOOLS PANEL HIDE BUTTON */
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 toolPanel();
			 }
			 /* PUT A CHECK IN THE MENU BAR FOR THE TOOL PANEL VIEW */
	private: System::Void toolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 toolPanel();
			 }
			 /* OPTIONS PANEL HIDE BUTTON */
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 optionPanel();
			 }
			 /* WHEN THE USER HOVERS OVER THE EXIT COMMAND IT WILL HIGHLIGHT GRAY (OPTIONS PANEL) */
	private: System::Void label5_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label5->ForeColor = System::Drawing::Color::LightGray;
			 }
			 /* WHEN THE USER LEAVES THE HOVER STATE OF THE EXIT COMMAND IT WILL GO BACK TO THE DEFAULT COLOR (OPTIONS PANEL) */
	private: System::Void label5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->label5->ForeColor = System::Drawing::Color::Black;
			 }
			 /* ABOUT DIALOG */
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 MessageBox::Show("Design by Shane Vance, Daniel Ortyn, Nico Espitia and Brennan Barni\r                                         "
					 + "For Dr. Boris Kovalerchuk\r                                                 2018 ? VisCanvas");
			 }
	private: System::Void nHsbColorPickerControl1_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;
				 System::String^ hex = selectedColor.GetHEX();
				 std::string s = toStandardString(hex); // convert HEX to std::string
				 s = s.substr(1, s.length()); // remove the "#" from the front of the string
				 char* str = (char*)s.c_str(); // convert back to a dynamic char array
				 int R, G, B;
				 sscanf_s(str, "%02x%02x%02x", &R, &G, &B); // convert HEX to RGB	
				 setColorBox(R, G, B);
			 }



			 /* Exits the program */
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 this->Close();
			 }
			 /* Ascending Sort */ 
	private: System::Void sortAscendingButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->ascendingSort();
			 }
			 /* Descending Sort */
	private: System::Void sortDescendingButtonControl2_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->descendingSort();
			 }
			 /* Original Sort */
	private: System::Void sortOriginalButtonControl3_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->originalSort();
			 }
			 /* Mean */
	private: System::Void meanButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->mean();
			 }
			 /* Median */
	private: System::Void medianButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->median();
			 }
			 /* Reset to the original data */
	private: System::Void nButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->originalData();
			 }
			 /* Sort ascending (menu item) */
	private: System::Void sortingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->ascendingSort();
			 }
			 /* Sort descending (menu item) */
	private: System::Void descendSortToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->descendingSort();
			 }
			 /* Sort original (menu item) */
	private: System::Void sortOriginalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalSort();
			 }
			 /* Mean level (menu item) */
	private: System::Void meanLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->mean();
			 }
			 /* Median level (menu item) */
	private: System::Void medianLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->median();
			 }
			 /* Original data (menu item) */
	private: System::Void originalDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 UNREFERENCED_PARAMETER(sender);
				 UNREFERENCED_PARAMETER(e);
				 OpenGL->originalData();
			 }
			 /* Background color */
	private: System::Void nColorBoxControl1_SelectedColorChanged(Nevron::Nov::Dom::NValueChangeEventArgs^  arg) {
				 Nevron::Nov::Graphics::NColor selectedColor = (Nevron::Nov::Graphics::NColor)arg->NewValue;
				 System::String^ hex = selectedColor.GetHEX();
				 std::string s = toStandardString(hex); // convert HEX to std::string
				 s = s.substr(1, s.length()); // remove the "#" from the front of the string
				 char* str = (char*)s.c_str(); // convert back to a dynamic char array
				 int R, G, B;
				 sscanf_s(str, "%02x%02x%02x", &R, &G, &B); // convert HEX to RGB	
				 OpenGL->Background(R, G, B);
			 }

			 /* Show the settings dialog */
	private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Settings^ settingsWindow = gcnew Settings(OpenGL);
				 settingsWindow->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				 settingsWindow->ShowDialog();

			 }

	private: System::Void hypercubeButtonControl1_Click(Nevron::Nov::Dom::NEventArgs^  arg) {
				 UNREFERENCED_PARAMETER(arg);
				 OpenGL->hypercube();
			 }




	protected:

		/* HOTKEYS: GET THE KEY COMBINATION AND THEN WE'LL SEND A MESSAGE TO THE OTHER CLASS */
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {

			UNREFERENCED_PARAMETER(msg);

			// Open File Dialog
			if (keyData == (Keys::Control | Keys::O)) {
				openFile();				 
			}
			// Save File Dialog
			if (keyData == (Keys::Control | Keys::S)) {
				// TODO: add the savefiledialog stuff here
				//OpenGL->save();
			}
			// Tools Panel
			if (keyData == (Keys::Control | Keys::Alt | Keys::T)) {
				toolPanel();				
			}
			// Options Panel
			if  (keyData == (Keys::Control | Keys::Alt | Keys::O)) {
				optionPanel();
			}		
			if (keyData == (Keys::W) || keyData == (Keys::Up))
			{
				OpenGL->incrementSelectedSet();
			}
			if (keyData == (Keys::S) || keyData == (Keys::Down))
			{
				OpenGL->decrementSelectedSet();
			}
			return true;
		}

	private:

		/* Converts from System::String^ to std::string */
		std::string toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( str ).ToPointer();
			std::string temp(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}

		System::Void openFile(System::Void) {
			// TODO: last used directory method
			OpenFileDialog^ ofd = gcnew OpenFileDialog;
			ofd->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			ofd->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text"; // we can add this later if needed (needs error handling if so) |All Files (*.*)|*.*";
			ofd->FilterIndex = 1;
			ofd->RestoreDirectory = true;

			if(ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				/* Convert System::String^ to a std::string */
				System::String^ path = ofd->FileName;

				std::string FILE_PATH = toStandardString(path); // convert to std::string

				/* Pass the FILE_PATH to OpenGL for reading the file */
				OpenGL->SetFilePath(FILE_PATH);
			}
		}

		System::Void toolPanel(System::Void) {
			// is it checked 
			if (this->toolsToolStripMenuItem->Checked) {
				this->Tools->Dock = System::Windows::Forms::DockStyle::None;
				this->toolsToolStripMenuItem->Checked = false;
			} else {
				this->Tools->Dock = System::Windows::Forms::DockStyle::Left;
				this->toolsToolStripMenuItem->Checked = true;
			}
			this->Tools->Visible = this->toolsToolStripMenuItem->Checked;
		}

		System::Void optionPanel(System::Void) {
			// is it checked
			if (this->optionsToolStripMenuItem->Checked) {
				this->Options->Dock = System::Windows::Forms::DockStyle::None;
				this->optionsToolStripMenuItem->Checked = false;
			} else {
				this->Options->Dock = System::Windows::Forms::DockStyle::Right;
				this->optionsToolStripMenuItem->Checked = true;
			}
			this->Options->Visible = this->optionsToolStripMenuItem->Checked;
		}		
		// This is for the color palette
		System::Void setColorBox(int R, int G, int B) {
			OpenGL->SetRGB((GLdouble)R, (GLdouble)G, (GLdouble)B);
			/* update the textbox color on RGB update */
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(R, G, B);
		}

	private: System::Void VisCanvas_Load(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::ToolTip^ toolTip = gcnew System::Windows::Forms::ToolTip;
				 // Set up the delays for the ToolTip.
				 toolTip->AutoPopDelay = 5000;
				 toolTip->InitialDelay = 1000;
				 toolTip->ReshowDelay = 500;
				 // Force the ToolTip text to be displayed whether or not the form is active.
				 toolTip->ShowAlways = true;

				 // Set up the ToolTip text for the Button and Checkbox.
				 toolTip->SetToolTip(this->label4, "hide");
				 toolTip->SetToolTip(this->label5, "hide");
			 }
	};

}