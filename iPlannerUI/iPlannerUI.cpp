//@author A0105180W
#include "iPlannerUI.h"

using namespace System; 
using namespace System::Windows::Forms;

[STAThread] 
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false);
	iPlannerUI::iPlannerUI mainWindow; 
	Application::Run(%mainWindow);
}