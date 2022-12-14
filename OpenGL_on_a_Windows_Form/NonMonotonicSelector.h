#pragma once
#include <string>
#include <vector>

using namespace std;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class NonMonotonicSelector : public System::Windows::Forms::Form
	{
	public: NonMonotonicSelector(vector<int>* avalibleCoordinates)
	{
		InitializeComponent();
		avalibleCoords = avalibleCoordinates;
		buildTable();
	}

	protected:~NonMonotonicSelector()
	{
		if (components)
		{
			delete components;
		}
	}

	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ confirmButton;
	private: System::ComponentModel::Container^ components;
	private: vector<int>* avalibleCoords;
	private: vector<int>* selectedCoordinates;

#pragma region

		   void InitializeComponent(void)
		   {
			   this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->confirmButton = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // dataGridView
			   // 
			   this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView->Location = System::Drawing::Point(12, 12);
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->Size = System::Drawing::Size(346, 428);
			   this->dataGridView->TabIndex = 0;
			   this->dataGridView->AllowUserToAddRows = false;
			   // 
			   // confirmButton
			   // 
			   this->confirmButton->Location = System::Drawing::Point(12, 446);
			   this->confirmButton->Name = L"confirmButton";
			   this->confirmButton->Size = System::Drawing::Size(75, 23);
			   this->confirmButton->TabIndex = 1;
			   this->confirmButton->Text = L"Confirm";
			   this->confirmButton->UseVisualStyleBackColor = true;
			   this->confirmButton->Click += gcnew System::EventHandler(this, &NonMonotonicSelector::onConfirm);
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(370, 479);
			   this->Controls->Add(this->confirmButton);
			   this->Controls->Add(this->dataGridView);
			   this->Name = L"Non-Monotonic Dimenson Selection";
			   this->Text = L"Non-Monotonic Dimenson Selection";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			   this->ResumeLayout(false);

		   }

#pragma endregion

	private: System::Void onConfirm(System::Object^ sender, System::EventArgs^ e);
	private: void buildTable();
	public: vector<int>* getSelectedCoordinates();
	};
}