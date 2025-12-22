#include <iostream>
#include <cstdio> // For std::rename
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

int main(){
    set<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string dob_month;

    mc:
    cout << "Enter the month you were born: ";
    cin >> dob_month;
    //bool test = ;
    if(months.count(dob_month) != 1){
        cout << "Invalid month. First letter is always capital.\n";
        goto mc;
    }
}

//  // void clearConsole() {
//  // #ifdef _WIN32
//  //   system("cls");
//  // #endif
//  // }



// int main() {
//     back:

//     cout << "Hello User.\n";
//     cout << "Do you want to clear the console?\n";
//     cout << "\t1. Yes.\n";
//     cout << "\t2. No.\n";
//     int ans;
//     cin >> ans;
//     if(ans == 1){
//         clearConsole();
//         cout << "Successfully cleared the console\n";
//         goto back;
//     }
//     // string oldFileName = "input.txt";
//     // string newFileName;
//     // string ext = ".txt";
    
//     // cout << "Enter the new name for the file (e.g., newname.txt): ";
//     // getline(cin, newFileName); // Get the new file name from user input

//     // newFileName.append(ext);
//     // cout << newFileName << endl;

//     // if (rename(oldFileName.c_str(), newFileName.c_str()) == 0) {
//     //     cout << "File renamed successfully!" << endl;
//     // } else {
//     //     cerr << "Error renaming file." << endl;
//     // }

//     return 0;
// }

// // #include <iostream>
// // #include <cstdio> // For std::rename
// // using namespace std;

// // int main() {
// //     string oldFileName = "inpu.txt";
// //     string newFileName;

// //     cout << "Enter the new name for the file (without extension): ";
// //     getline(cin, newFileName);

// //     newFileName += ".txt"; // only one ".txt"

// //     if (rename(oldFileName.c_str(), newFileName.c_str()) == 0) {
// //         cout << "File renamed successfully to " << newFileName << endl;
// //     } else {
// //         perror("Error renaming file"); // better error message
// //     }

// //     return 0;
// // }
