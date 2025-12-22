#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// Enable ANSI escape codes on Windows 10+
void enableVTMode() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}

// Deletes the typed input after Enter, keeping prompt intact
void clearUserInputOnly() {
    // Move cursor up, go to end of prompt, clear from there
    std::cout << "\x1b[1A"     // Move cursor up one line
              << "\x1b[s"      // Save cursor position
              << "\x1b[999C"   // Move far right (max columns)
              << "\x1b[1K"     // Clear from cursor to start of line
              << "\x1b[u";     // Restore cursor to saved position
    std::cout.flush();
}


void clearConsole(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (hConsole == INVALID_HANDLE_VALUE) return;

    // Get console buffer info
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count)) return;

    // Fill with the current colors and attributes
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) return;

    // Move the cursor home
    SetConsoleCursorPosition(hConsole, homeCoords);
}

int main() {
    enableVTMode();

    std::string input;

    // Display the prompt (cursor ends right after ': ')
    cout << "Insufficient balance.\n";
    for(int i = 0; i < 3; i++){
        cout << "\t....................\n";
    }
    ucl:
    std::cout << "Type something and press Enter: ";
    std::cout.flush();

    // Save cursor position right after the prompt
    std::cout << "\x1b[s"; 
    std::cout.flush();

    std::getline(std::cin, input);

    // Clear only the user’s typed input
    clearUserInputOnly();
    goto ucl;

    // Cursor is restored to right after the prompt
    //std::cout << "You entered: [" << input << "]" << std::endl;

    //clearConsole();
    //main();

    return 0;
} 