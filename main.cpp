#define BANNER "--------------------------------"
#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>

int main()
{

    int numTimes = 0;

    // Thank you Stack Overflow. Could not figure out how to set console window on top
    HWND consoleWindowHandle = GetConsoleWindow();

    if( consoleWindowHandle ){
    SetWindowPos(
        consoleWindowHandle,
        HWND_TOPMOST,

        0, 0,
        0, 0,
        SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW
    );


    // Some beginning messages...
    std::cout << "Console window position set successfully.." << std::endl;
    std::cout << "The Ctrl-Z Counter" << std::endl;
    std::cout << "A crazy simple program from intTJ" << std::endl;
    std::cout << BANNER << std::endl;


    if (RegisterHotKey( NULL, 1, MOD_CONTROL, 0x5A))
    {
        std::cout << "CTRL-Z successfully registered as global hotkey!" << std::endl;
        std::cout << BANNER << std::endl;
    }
    else
    {
        std::cout << "There was an error assigning Ctrl-Z as a global hotkey: " << GetLastError();
    }


    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
       std::cout << "CTRL+Z was pressed " << numTimes << " times." << std::endl;
       numTimes++;
    }

        return 0;
    }
}
