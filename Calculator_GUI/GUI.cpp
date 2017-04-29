#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calculator_GUI::GUI form;
	Application::Run(%form);
}