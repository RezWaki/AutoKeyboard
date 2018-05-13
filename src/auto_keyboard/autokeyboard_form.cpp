#include <Windows.h>
#include "autokeyboard_form.h"
using namespace System;
using namespace System::Windows::Forms;
BOOL WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	Application::EnableVisualStyles();
	Application::Run(gcnew auto_keyboard::autokeyboard_form());
	return TRUE;
}

