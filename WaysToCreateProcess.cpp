// Dummy aap to be virtualized by AAV DEV2647.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main(int argc, TCHAR* argv[])
{
	MessageBoxW(nullptr, L"Hello World!!", L"Greetings", 0);
	std::cout << "1. Creating a child process (notepad) using CreateProcess" << std::endl;
	STARTUPINFOW startUpInfow;
	memset(&startUpInfow, 0, sizeof(startUpInfow));
	//pInfow, sizeof(startUpInfow));
	startUpInfow.cb = sizeof(startUpInfow);

	PROCESS_INFORMATION processInformation;
	memset(&processInformation, 0, sizeof(processInformation));
	
	//WCHAR cmd[] = L"notepad.exe  \"c:\\Users\\jaya.saxena\\Desktop\\Sample  AAV\\AAV.clc\"";
	WCHAR cmd[] = L"\"C:\\Windows\\system32\\java\\java.exe\" -Ddass.config=DASS-config.xml -Xmx1280M -Xms1280M -Djava.library.path=\"./wrapper\" -classpath \"./wrapper/wrapper.jar;./DASS.jar;./Strategies/BureauSc.jar\" -Dwrapper.key=\"3Xtij9l_9IftlpQh\" -Dwrapper.port=32000 -Dwrapper.jvm.port.min=31000 -Dwrapper.jvm.port.max=31999 -Dwrapper.pid=4552 -Dwrapper.version=\"3.5.15\" -Dwrapper.native_library=\"wrapper\" -Dwrapper.cpu.timeout=\"10\" -Dwrapper.jvmid=1 org.tanukisoftware.wrapper.WrapperSimpleApp com.experian.co.za.jnidainterface.tcpserver.DaSocketServer";
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
	//Wait until child process exits.
	WaitForSingleObject(processInformation.hProcess, INFINITE);

	CloseHandle(processInformation.hProcess);
	CloseHandle(processInformation.hThread);

	/*
	std::cout << "2. Creating a child process (cmd) using WinExec" << std::endl;
	//WinExec("\"C:\\Users\\jaya.saxena\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\System Tools\\Command Prompt\"", SW_SHOW);
	WinExec("cmd.exe", SW_SHOW); //old way

	std::cout << "3. Creating a child process (notepad) using ShellExecuteW" << std::endl;
	auto hcurrentWindow = GetActiveWindow();
	ShellExecuteW(hcurrentWindow, L"open", L"notepad.exe", nullptr, nullptr, SW_SHOW);

	std::cout << "4. Creating a child process (notepad) using system" << std::endl;
	system("notepad.exe");
	
	MessageBoxW(nullptr, L"Hello World!!", L"Greetings", 0);
	std::cout << "5. Creating a child process (notepad.exe) using CreateProcess and passing a file which has space in its path" << std::endl;
	STARTUPINFOW si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);

	PROCESS_INFORMATION pi;
	memset(&pi, 0, sizeof(pi));

	WCHAR appName[] = L"C:\\Windows\\System32\\notepad.exe";
	WCHAR arguments[] = L"\"\\\"C:\\\\Users\\\\jaya.saxena\\\\Desktop\\\\Sample  AAV\\\\AAV.clc\\\"\"";
	//CreateProcessW(nullptr, cmd , nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr, &startUpInfow, &processInformation);
	if (!CreateProcess(appName,   // No module name (use command line)
		arguments, //argv[1],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		std::cout << "CreateProcess failed. LastError:  " << GetLastError() << std::endl;
		return 1;
	}

	std::cout << "Child Process Id is:: " << GetProcessId(pi.hProcess) << std::endl;
	//Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	*/
	//MessageBoxW(nullptr, L"Hello World!!", L"Greetings", 0);
	return 0;
}


