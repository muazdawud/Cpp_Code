//Continue testing and return all the function calls into main function, and bring the clear screen function and stabilixe it where possible.

#include<bits/stdc++.h>
#include<cstdlib>
#include<filesystem>
#include<string>
#include<stdexcept>
#include<windows.h>
#ifdef _WIN32 
#endif
using namespace std;

set<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class check_input{
private:
    string input;
public:
    void assign(string inp){input = inp;}

    bool check(){
        for(int i = 0; i < input.size(); i++){
            if(!isdigit(input[i])){
                return false;
            }
        }
        return true;
    }
};

void add_universal_file(string fname, string accountnum, string password, string pin);
void deposit(string accountnum);
string registration();
string acc_correction(int num);
bool u_check(string name);
bool acc_num_check(string acc_num);
char options();
char  intro();
string date_time();
int transfer(string, string);
void transfer_update_history(string, string, int, int, int);
bool login(string* name);
bool withdraw(string, string);
int operation_check();
void withdrawal_update_history(string, int, int);
void deposit_update_history(string a_number, int amount, int bal);
void clearConsole();
string universal_extract(string);
string check_balance(string acc_num, string);
void balance_update_history(string, string);
void enableVTMode();
void clearUserInputOnly();
bool check_check_input(string pin);
bool check_pin(string, string);

int main(){
    clearConsole();
    char ans = intro();

    if(ans == '1'){
        lc:
        clearConsole();
        string username;
        bool login_check = login(&username);
        clearConsole();
        if(login_check == true){
            string acc_num = universal_extract(username);
            cout << "Login Successful\n";
            cout << "\tACCESS GRANTED ^_^\n\n";
            char option_check = options();
            clearConsole();
            if(option_check == 1){
                bool withdraw_check = withdraw(acc_num, username);
                clearConsole();
                if(withdraw_check == true){
                    cout << "Transaction Successful.\n";
                }else{
                    cout << "\tInsufficient balance/Invalid PIN!\n";
                    for(int i = 0; i < 3; i++){
                        cout << "\t....................\n";
                    }
                    Sleep(3000);
                }
                int oc_check = operation_check();
                    if(oc_check == 1){
                        goto lc;
                    }else if(ans == 2){
                        main();
                    }
            }else if(option_check == 2){
                int transfer_check = transfer(acc_num, username);
                clearConsole();
                if(transfer_check == 1){
                    cout << "Transaction Successful.\n";
                }else if(transfer_check == 2){
                    cout << "Invalid reciever's detail.\n";
                }else if(transfer_check == 3){
                    cout << "Insufficient balance.\n";
                    for(int i = 0; i < 3; i++){
                        cout << "\t.....................\n";
                    }
                    Sleep(3000);
                }else if(transfer_check == 5){
                    cout << "Invalid Transaction PIN.\n";
                    for(int i = 0; i < 3; i++){
                        cout << "\t.....................\n";
                    }
                    Sleep(3000);
                }
                int oc_check = operation_check();
                    if(oc_check == 1){
                        goto lc;
                    }else if(ans == 2){
                        main();
                    }
            }else if(option_check == 3){
                deposit(acc_num);
                clearConsole();
                cout << "Transaction Successful.\n";
                
                int oc_check = operation_check();
                    if(oc_check == 1){
                        goto lc;
                    }else if(ans == 2){
                        main();
                    }
            }else if(option_check == 4){
                string balance_n = check_balance(acc_num, username);
                cout << "Your balance is " << balance_n << endl;
                Sleep(3000);

                clearConsole();
                int oc_check = operation_check();
                    if(oc_check == 1){
                        goto lc;
                    }else if(ans == 2){
                        main();
                    }
            }else if(option_check > 5){
                clearConsole();
                int oc_check = operation_check();
                    if(oc_check == 1){
                        goto lc;
                    }else if(ans == 2){
                        main();
                    }
            }
        }else{
            clearConsole();
            cout << "Invalid Login Details.\n";
            for(int i = 0; i < 3; i++){
                cout << "\t.....................\n";
            }
            Sleep(3000);
            main();
        }
    }
    if(ans == '2'){
        clearConsole();
        string account_n = registration();
        clearConsole();
        cout << "\nYOUR ACCOUNT NUMBER IS: " << account_n << ".\n\t\t*Copy it down somewhere.\n";

        cout << "\nDo you want to make a Deposit?\n\t1. Yes\n\t2.No\n";
        int ans;
        cin >> ans;
        if(ans == 1){
           deposit(account_n);
        }else{
            main();
        }
    }
    if(ans != '1' || ans != '2'){
        main();
    }
    return 0;
}

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

string date_time(){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime{};

    #ifdef _WIN32
        localtime_s(&localTime, &currentTime);
    #else
        localtime_r(&currentTime, &localTime);
    #endif
        ostringstream oss;
        oss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

string acc_correction(int num){
    string s = to_string(num);

    while (s.length() < 10) {
        s = "0" + s;
    }

    return s;
}

void add_universal_file(string fname, string accountnum, string password, string pin){
    fstream myfile;
    string bankname = "Major_";
    string ext = ".txt";
    //string temp = fname;

    //bankname.appenD(fname);
    bankname.append(fname);
    bankname.append(ext);

    myfile.open(bankname, ios::out);

    myfile << accountnum << endl;
    myfile << password << endl;
    mysile << pin << endl;

    myfile.close();
}

char intro(){
    cout << "\tHello, How's your  day?\n";
    cout << "\tWhat operation do you want to do today?\n";
    cout << "\t1. Login.\n\t2. Register.\n";
    char ans;
    cin >> ans;
    
    return ans;
}

string universal_extract(string name){
    fstream myfile;
    string ext = "Major_";
    string ext2 = ".txt";

    ext.append(name);
    ext.append(ext2);
    myfile.open(ext);

    string line; 

    getline(myfile, line);

    myfile.close();
    return line;
}

bool check_pin(string uname, string pin){
    fstream myfile;
    string ext1 = "Dbank_";
    string ext2 = ".txt";

    ext1.append(uname);
    ext1.append(ext2);

    myfile.open(ext1, ios::in);
    int linenum = 0;
    string line;

    while(getline(myfile, line)){
        linenum++;
        if(linenum == 3 && line == pin){
            return true;
        }
    }

    return false;
}

bool u_check(string name){
    fstream my_file;
    string bankname = "Major_";
    string ext = ".txt";
    bankname.append(name);
    bankname.append(ext);

    //string filename = bankname;
    my_file.open(bankname, ios::in);
    if(!my_file.is_open()){
        return false;
    }else{
        my_file.close();
        return true;
    }

    // string line;
    // int linenum = 0;

    // while(getline(my_file, line)){
    //     linenum++;
    // }
    // my_file.close();

    // if(linenum <= 1){
    //     filesystem::remove(bankname);
    //     return false;
    // }else{
    //     return true;
    // }
}

bool acc_num_check(string acc_num){
    fstream myfile;
    string ext = "_info.txt";
    string bankname = "Dbank_";

    //bool check = false;
    bankname.append(acc_num);
    bankname.append(ext); 

    myfile.open(bankname, ios::in); 
    
    if(myfile.fail()){
        return false;
    }

    return true; 
}

int operation_check(){
    cout << "Do you want to perform another transaction?\n\t1. Yes\n\t2. No\n";
    int ans;
    cin >> ans;

    while(ans > 2 || ans < 1){
        cout << "Invalid option.\n";
        cin >> ans;
    }

    return ans;
}

bool login(string* name){
    fstream myfile;
    string username;
    string password;
    string temp;
    string ext = "Major_";
    string ext2 = ".txt";

    //uc:
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool lc = u_check(username);
    
    if(lc == false){
        return false;
    }

    *name = username;
    ext.append(username);
    ext.append(ext2);
    myfile.open(ext, ios::in);
    int linenum = 0;
    string line;

    while(getline(myfile, line)){
        linenum++;
        if(linenum == 2 && line != password){ 
            myfile.close();
            return false;
        }
    }

    myfile.close();
    return true;
}

char options(){
    char ans;
    cout << "\t1. Withdraw\n\t2. Transfer\n\t3. Deposit\n\t4. Balance\n\t5. Exit\n";
    cin >> ans;
    
    int temp = 
    while(ans > 5 || ans < 0){
        cout << "Invalid option!\n";
        cin >> ans;
    }

    return ans;
}

bool withdraw(string a_num, string usern){
    fstream myfile;
    string ext = "Dbank_";
    string ext2 = "_balance.txt";
    string temp = a_num;

    ext.append(a_num);
    ext.append(ext2);

    myfile.open(ext, ios::in); 
    string balance;

    getline(myfile, balance);
    myfile.close();

    int line;

    try{
        line = stoi(balance);
    }catch(...){
        line = 0;
    }

    cout << "How much do you want to withdraw?\n";
    int ans;
    cin >> ans;
    if(line < ans){
        return false;
    }

    cpi:
    string pin;
    cout << "Enter your transaction PIN: ";
    cin >> pin;
    bool cpin = check_check_input(pin);
    if(cpin == false){ 
        clearUserInputOnly();
        return false;
    }
    cpin = check_pin(usern, pin);
    if(cpin == false){
        clearUserInputOnly();
        return false;
    }


    line = line-ans;
    myfile.open(ext, ios::out);
    myfile << line << endl;
    myfile.close();

    withdrawal_update_history(temp, ans, line);
    
    return true;
}

void withdrawal_update_history(string a_number, int amount, int bal){
    fstream myfile;
    string ext = "_history.txt";
    string bankname = "Dbank_";
    string dt = date_time();
    
    bankname.append(a_number);
    bankname.append(ext);

    myfile.open(bankname, ios::app);

    myfile << "History: Account was Debited." << endl;
    myfile << "Amount = " << amount << endl;
    myfile << "Date & Time: " << dt << endl;
    myfile << "Balance:  " << bal << endl;
    myfile << ".........." << endl;

    myfile.close();
}

int transfer(string s_num, string usern){
    fstream myfile;
    string ext = "_balance.txt";
    string bankname = "Dbank_";
    string ext2 = "_balance.txt";
    string bankname2 = "Dbank_";

    cout << "How much do you want to transfer?\n";
    int amount;
    cin >> amount;
    cout << "Enter the reciever's account number;\n";
    string r_a_n;
    cin >> r_a_n;
    
    //string send = to_string(r_a_n);
    bool check_a_n = acc_num_check(r_a_n);
    if(check_a_n == false){
        return 2;
    }

    cout << "Enter your transaction PIN: ";
    cin >> pin;
    bool cpin = check_check_input(pin);
    if(cpin == false){ 
        clearUserInputOnly();
        return 5;
    }
    cpin = check_pin(usern, pin);
    if(cpin == false){
        clearUserInputOnly();
        return 5;
    }

    bankname.append(s_num);
    bankname.append(ext);
    string line;
    int temp_balance;
    int balance;

    myfile.open(bankname, ios::in);
    getline(myfile, line);
    myfile.close();

    try{
        temp_balance = stoi(line);
    }catch(...){
        temp_balance = 0;
    }
    
    if(temp_balance < amount){
        return 3;
    }

    bankname2.append(r_a_n);
    bankname2.append(ext2);

    myfile.open(bankname2, ios::in);
    getline(myfile, line);
    myfile.close();
    
    try{
        balance = stoi(line);
    }catch(...){
        balance = 0;
    }

    balance = balance+amount;
    myfile.open(bankname2, ios::out);
    myfile << balance << endl;
    myfile.close();

    temp_balance = temp_balance-amount;
    myfile.open(bankname, ios::out);
    myfile << temp_balance << endl;
    myfile.close();

    transfer_update_history(s_num, r_a_n, amount, temp_balance, balance);
    
    return 1;
}

void transfer_update_history(string s_a_n, string r_a_n, int amount, int s_balance, int r_balance){
    fstream myfile;
    string ext = "_history.txt";
    string bankname = "Dbank_";
    string temp = bankname;
    string dt = date_time();
    
    bankname.append(s_a_n);
    bankname.append(ext);

    myfile.open(bankname, ios::app);

    myfile << "History: Account was Debited." << endl;
    myfile << "Amount = " << amount << endl;
    myfile << "Date & Time: " << dt << endl;
    myfile << "Balance: " << s_balance << endl;
    myfile << ".........." << endl;

    myfile.close();

    temp.append(r_a_n);
    temp.append(ext);

    myfile.open(temp, ios::app);

    myfile << "History: Account was Credited." << endl;
    myfile << "Amount = " << amount << endl;
    myfile << "Date & Time: " << dt << endl;
    myfile << "Balance: " << r_balance << endl;
    myfile << ".........." << endl;

    myfile.close();
}

void deposit(string accountnum){
    fstream myfile;
    string ext1 = "Dbank_";
    string ext2 = "_balance.txt";
    string line;
    int balance;

    ext1.append(accountnum);
    ext1.append(ext2);

    myfile.open(ext1, ios::in);
    getline(myfile, line);
    myfile.close();
    cout << line;

    try{
        balance = stoi(line);
    }catch(...){
        balance = 0;
    }

    cout << "How much do you want to deposit?\n";
    int ans;
    cin >> ans;

    balance = balance+ans;
    myfile.open(ext1, ios::out);
    myfile << balance << endl;
    myfile.close();

    deposit_update_history(accountnum, ans, balance); 
}

void deposit_update_history(string a_number, int amount, int bal){
    fstream myfile;
    string ext = "_history.txt";
    string bankname = "Dbank_";
    string dt = date_time();
    
    bankname.append(a_number);
    bankname.append(ext);

    myfile.open(bankname, ios::app);

    myfile << "History: Account was Credited." << endl;
    myfile << "Amount = " << amount << endl;
    myfile << "Date & Time: " << dt << endl;
    myfile << "Balance:  " << bal << endl;
    myfile << ".........." << endl;

    myfile.close();
}

string check_balance(string acc_num, string usern){
    fstream myfile;
    string ext = "_balance.txt";
    string bankname = "Dbank_";
    bankname.append(acc_num);
    bankname.append(ext);

    cout << "Enter your transaction PIN: ";
    cin >> pin;
    bool cpin = check_check_input(pin);
    if(cpin == false){ 
        clearUserInputOnly();
        cout << "Invalid PIN!\n";
        return 0;
    }
    cpin = check_pin(usern, pin);
    if(cpin == false){
        clearUserInputOnly();
        cout << "Invalid PIN!\n";
        return 0;
    }

    myfile.open(bankname, ios::in);
    string line;
    getline(myfile, line);
    myfile.close();

    balance_update_history(acc_num, line);

    return line;
}

void balance_update_history(string acc_num, string balance){
    fstream myfile;
    string bankname = "Dbank_";
    string ext = "_history.txt";
    string dt = date_time();

    bankname.append(acc_num);
    bankname.append(ext);

    myfile.open(bankname, ios::app);

    myfile << "History: Balance Checked." << endl;
    myfile << "Amount = " << endl;
    myfile << "Date & Time: " << dt << endl;
    myfile << "Balance:  " << balance << endl;
    myfile << ".........." << endl;
}

bool check_check_input(string pin){
    check_input cp;
    cp.assign(pin);
    bool cci = cp.check();

    return cci;
}

string registration(){
    fstream myfile;
    ac:
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> distrib_int(1, 100000000);
    long long acc_num = distrib_int(gen);

    string account_n = acc_correction(acc_num);
    
    bool check = acc_num_check(account_n);
    if(check == true){
        goto ac;
    }

    string ext = ".txt";
    string ext2 = "_balance.txt";
    string ext3 = "_history.txt";
    string ext4 = "_info.txt";
    string bank_name = "Dbank_";
    string bankname = "Dbank_";
    string temp = account_n;

    string name;
    int dob_day;
    string dob_month;
    int dob_year;
    string address;
    long long phone_num;
    string email;
    string username;
    string password;
    string cp;
    string pin;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    dc:
    cout << "Enter the day you were born: ";
    cin >> dob_day;
    if(dob_day > 31 || dob_day < 1){
        cout << "Invalid day!\n";
        goto dc;
    }
    mc:
    cout << "Enter the month you were born: ";
    cin >> dob_month;
    if(months.count(dob_month) != 1){
        cout << "Invalid month. First letter is always capital.\n";
        goto mc;
    }
    yc:
    cout << "Enter the year you were born: ";
    cin >> dob_year;
    if(dob_year > 2025 || dob_year < 1900){
        cout << "Invalid year.\n";
        goto  yc;
    }
    cout << "Enter your Home Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter your Phone Number: ";
    cin >> phone_num;
    cout << "Enter your Email: ";
    cin >> email;
    cout << "Enter your username: ";
    cin >> username;
    while(username.size() <= 5){
        cout << "Username can't be " << username.size() << " letters.\n";
        //goto uc;
        cout << "Enter your username: ";
        cin >> username;
    }
    bool check_file = u_check(username);
    while(check_file == true){
        cout << "It has been taken.\n";
        //goto uc;
        cout << "Enter your username: ";
        cin >> username;
        check_file = u_check(username);
    }
    pt:
    cout << "Enter your password: ";
    cin >> password;
    cout << "Confirm your Password: ";
    cin >> cp;
    if(cp != password){
        cout << "Password does'nt match\n";
        goto pt;
    }
    pc:
    cout << "Enter a 4 digit Transaction Pin: ";
    cin >> pin;
    bool ccii = check_check_input();
    if(ccii == false){
        cout << "This is a digit only PIN!\n";
        goto pc;
    } 

    add_universal_file(username, account_n, password, pin);

    bank_name.append(temp);
    bank_name.append(ext4);

    myfile.open(bank_name, ios::out);

    myfile << account_n << endl;
    myfile << "Name: " << name << endl;
    myfile << "DOB: " << dob_day << ", " << dob_month << ", " << dob_year  << endl;
    myfile << "Address: " << address << endl;
    myfile << "Phone Number: " << phone_num << endl;
    myfile << "Email: " << email << endl;
    myfile << "Username: " << username << endl;
    myfile << "Password: " << password << endl;
    myfile << "Transaction PIN: " << pin << endl;


    myfile.close();

    return account_n;
} 