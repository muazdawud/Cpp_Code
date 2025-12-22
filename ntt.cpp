//Continue testing and return all the function calls into main function, and bring the clear screen function and stabilixe it where possible.

#include<bits/stdc++.h>
#include<cstdlib>
#include<filesystem>
#include<string>
#include<stdexcept>
using namespace std;

set<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void universal_file(string fname, string accountnum, string password);
void deposit(string accountnum);
void registration();
string acc_correction(int num);
bool u_check(string name);
bool acc_num_check(string acc_num);
void options(string);
void  intro();
string date_time();
void transfer(string);
void transfer_update_history(string, string, int, int, int);
void login();
void withdraw(string);
void operation_check();
void withdrawal_update_history(string, int, int);
void deposit_update_history(string a_number, int amount, int bal);


int main(){
    intro();

    return 0;
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

void add_universal_file(string fname, string accountnum, string password){
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

    myfile.close();
}

void intro(){
    cout << "Hello, How's your  day?\n";
    //cout << "What operation do you want to do today?\n";
    cout << "\t1. Login.\n\t2. Register.\n";
    int ans;
    cin >> ans;
    if(ans == 1){
        login();
    }else if(ans == 2){
        registration();
    }
    if(ans != 1 || ans != 2){
        intro();
    }
}

string universal_extract(string name){
    fstream myfile;
    string ext = "Major_";
    string ext2 = ".txt";

    ext.append(name);
    ext.append(ext2);
    myfile.open(ext);

    string line;
    //int linenum;

    getline(myfile, line);

    myfile.close();
    return line;
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

    string filename = bankname;

    string line;
    int linenum = 0;

    myfile.open(bankname, ios::in);
    getline(myfile, line);
    myfile.close();
    
    if(line.size() == 0){
        filesystem::remove(filename);
        return false;
    }else{
        return true;
    }
}

void operation_check(){
    cout << "Do you want to perform another transaction?\n\t1. Yes\n\t2. No\n";
    int ans;
    while(cin >> ans){
        if(ans == 1){
            login();
        }
        if(ans == 2){
            cout << "Bye-bye.\n";
            cout << "..............................................................................\n";
            exit(0);
        }
        cout << "Invalid opotion.\n";
    }
}

void login(){
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
    
    while(lc == false){
        cout << "Invalid login details. Try again.\n";
        login();
    }

    temp = username;
    ext.append(temp);
    ext.append(ext2);
    myfile.open(temp, ios::out);
    int linenum = 0;
    string line;

    while(getline(myfile, line)){
        linenum++;
        if(linenum == 2 && line != password){
            cout << "Invalid Password.\n";
                for(int i = 0; i < 3; i++){
                    cout << "\t...............................\n";
                }
                myfile.close();
                intro();
        }
    }
    myfile.close();
    

    options(username);
}

void options(string name){
    cout << "\tACCESS GRANTED ^_^\n\n";
    string acc_num = universal_extract(name);

    int ans;
    cout << "\t1. Withdraw\n\t2. Transfer\n\t3. Deposit\n\t4. Exit\n";
    cin >> ans;
    if(ans == 1){
        withdraw(acc_num);
    }else if(ans == 2){
        transfer(acc_num);
    }else if(ans == 3){
        deposit(acc_num);
    }else if(ans == 4){
        cout << "Bye-bye\n";
        cout << "..............................................................................\n";
        exit(0);
    }else{
        operation_check();
    }
}

void withdraw(string a_num){
    fstream myfile;
    string ext = "Dbank_";
    string ext2 = "_balance.txt";
    string temp = a_num;

    ext.append(a_num);
    ext.append(ext2);

    myfile.open(ext, ios::in);
    int line;
    string balance;

    getline(myfile, balance);
    myfile.close();

    try{
        line = stoi(balance);
    }catch(...){
        line = 0;
    }

    cout << "How much do you want to withdraw?\n";
    int ans;
    cin >> ans;
    if(line > ans){
        line = line-ans;
        myfile.open(ext, ios::out);
        myfile << line << endl;
        myfile.close();
        withdrawal_update_history(temp, ans, line);
        cout << "Withdrawal Successful.\n";
        operation_check();
    }else{
        cout << "Insufficient balance.\n";
        operation_check();
    }
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

void transfer(string s_name){
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
        cout << "Invalid reciever's detail.\n";
        operation_check();
    }

    bankname.append(s_name);
    bankname.append(ext);
    string line;
    int balance;

    myfile.open(bankname, ios::in);
    getline(myfile, line);
    myfile.close();

    try{
        balance = stoi(line);
    }catch(...){
        balance = 0;
    }
    int temp_balance = balance;

    if(balance < amount){
        cout << "Insufficient balance.\n";
        operation_check();
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
    myfile << balance << endl;
    myfile.close();

    transfer_update_history(s_name, r_a_n, amount, temp_balance, balance);
    operation_check();
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
    myfile << "Balance: " << r_balance;
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

    cout << "Deposit Successful ^_^\n";

    intro();
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

void registration(){
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

    add_universal_file(username, account_n, password);

    bank_name.append(temp);
    bank_name.append(ext4);

    myfile.open(bank_name, ios::out);

    myfile << account_n << endl;
    myfile << "Name: " << name << endl;
    myfile << "DOB: " << dob_day << ", " << dob_month << ", " << dob_year  << endl;
    myfile << "Address: " << address << endl;
    myfile << "Phone Number: " << phone_num << endl;
    myfile << "Email: " << email << endl;
    myfile << username << endl;
    myfile << password << endl;

    myfile.close();

    cout << "\nYOUR ACCOUNT NUMBER IS: " << account_n << ".\n\t\t*Copy it down somewhere.\n";

    cout << "\nDo you want to make a Deposit?\n\t1. Yes\n\t2.No\n";
    int ans;
    cin >> ans;
    if(ans == 1){
       deposit(account_n);
    }else{
        cout << "Bye-bye\n";
        cout << "..............................................................................\n";
        exit(0);
    }
} 