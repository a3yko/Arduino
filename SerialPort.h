#pragma once

namespace Arduino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SerialPort
	/// </summary>
	public ref class SerialPort : public System::Windows::Forms::Form
	{
	public:
		SerialPort(void)
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
		~SerialPort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM15";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(139, 118);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SerialPort::button1_Click);
			// 
			// SerialPort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->button1);
			this->Name = L"SerialPort";
			this->Text = L"SerialPort";
			this->Load += gcnew System::EventHandler(this, &SerialPort::SerialPort_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->serialPort1->PortName = "\\\\.\\COM15";  // Replace with your COM port!
		this->serialPort1->Open(); // In the future,  you'll expand on this
		// to write your custom data to the board
		this->serialPort1->Close();
	}
	private: System::Void SerialPort_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
