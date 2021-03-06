#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main(int argc, TCHAR* argv[])
{
	MessageBoxW(nullptr, L"1. Creating a child process (notepad) using CreateProcess", L"Ways To Create a Process", 0);
	STARTUPINFOW startUpInfow;
	memset(&startUpInfow, 0, sizeof(startUpInfow));
	startUpInfow.cb = sizeof(startUpInfow);

	PROCESS_INFORMATION processInformation;
	memset(&processInformation, 0, sizeof(processInformation));
	
	WCHAR cmd[] = L"notepad.exe  a.txt";
	//CreateProcessW(nullptr, cmd , nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr, &startUpInfow, &processInformation);
	if (!CreateProcess(NULL,   // No module name (use command line)
		cmd, //argv[1],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&startUpInfow,            // Pointer to STARTUPINFO structure
		&processInformation)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		std::cout << "CreateProcess failed" << GetLastError() << std::endl;
		return 1;
	}
	std::cout << "Child Process Id is:: " << GetProcessId(processInformation.hProcess) << std::endl;
	MessageBoxW(nullptr, L"Waiting for child process (notepad) to exit", L"Ways To Create a Process", 0);
	WaitForSingleObject(processInformation.hProcess, INFINITE);	//Wait until child process exits.

	CloseHandle(processInformation.hProcess);
	CloseHandle(processInformation.hThread);

	MessageBoxW(nullptr, L"2. Creating a child process (cmd) using WinExec", L"Ways To Create a Process", 0);
	WinExec("cmd.exe", SW_SHOW); //old way

	MessageBoxW(nullptr, L"3. Creating a child process (notepad) using ShellExecuteW", L"Ways To Create a Process", 0);
	auto hcurrentWindow = GetActiveWindow();
	ShellExecuteW(hcurrentWindow, L"open", L"notepad.exe", nullptr, nullptr, SW_SHOW);

	MessageBoxW(nullptr, L"4. Creating a child process (notepad) using system", L"Ways To Create a Process", 0);
	system("notepad.exe");
	return 0;
}
