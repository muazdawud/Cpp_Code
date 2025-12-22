//A Banking System Simulator...

#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<fstream>
#include<set>
#include<random>

set<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void intro(){
    cout << "Hello;\n";
    cout << "How is your day\nChoose an option below;\n";
}

bool u_check(string name){
    fstream my_file;
    string ext = ".txt";
    name.append(ext);
    my_file.open(name, ios::out);
    string line;
    int linenum = 0;

    while(getline(my_file, line)){
        linenum++;
    }
    my_file.close();
    if(linenum == 0){
        return 0;
    }else{
        return 1;
    }
}

void acc_info(){
    int acc_num;
    string acc_type;
    int balance;
    string DOC;
    string status;

}

int acc_correction(int num){
    string s = to_string(num);

    // Pad with leading zeros until length = 10
    while (s.length() < 10) {
        s = "0" + s;
    }

    return s;
}

void balance(string acc_name){
    name = "Dbank" + name + "balance.txt";

    fstream my_file;
    my_file.open(name, ios::out);

    string line;
    while(getline(my_file, line)){
        cout << line << endl;
    }
}

void transfer(int acc_name, int to_add){
    fstream myfile;

}

void registration(){
	fstream myfile;
    random_device rd; // Non-deterministic random number generator
    mt19937 gen(rd()); // Seed the Mersenne Twister engine

    // Generate random integers between 1 and 100
    uniform_int_distribution<> distrib_int(1, 100000000);
    long long acc_num = distrib_int(gen);
	string ext = ".txt";
    string ext2 = "_balance.txt";
    string ext3 = "_history.txt";
    string ext4 = "_info.txt";
    string bank_name = "Dbank_";
    string temp;

	string name;
    int dob_day;
    string dob_month;
    int dob_year;
    string address;
    int phone_num;
    string email;
    string username;
    string password;
    string cp;
    cout << "Enter your name: ";
    //cin.ignore();
    getline(cin, name);
    dc:
    cout << "Enter the day you were born: ";
    cin >> dob_day;
    if(dob_day > 31 || dob_day < 1){
    	cout << "Invalid month!\n";
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
    uc:
    cout << "Enter your username: ";
    cin >> username;
    while(username.size() == 0){
    	cout << "Username can't be empty\n";
    	//goto uc;
        cout << "Enter your username: ";
        cin >> username;
    }
    bool check_file = u_check(username);
    while(check_file == 1){
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
    while(cp != password){
    	cout << "Password does'nt match\n";
    	//goto pt;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Confirm your Password: ";
        cin >> cp;
    }

    // string temp = username;
    // temp.append(ext);

    string account_n = acc_correction(acc_num);
    universal_file(username, account_n, password);
    
    temp = username;
    temp.append(ext)

    bank_name.append(account_n);
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
}

void login(){
    fstream my_file;
    string username;
    string password;
    string temp;
    string ext = ".txt";

    uc:
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool lc = u_check(username);
    
    if(lc != 1){
        cout << "Invalid login details. Try again.\n";
        goto uc;
    }

    temp = username;
    temp.append(ext);
    myfile.open(temp, ios::out);
    cout << "Acess granted\n";


    operation();
}

void acc_display(string name){
    fstream my_file;
    my_file.open(name, ios::in);
    cout << "Access Granted\n";

    string liner;
    while(getline(my_file, liner)){
        cout << lner << endl;
    }
}

void operation(string name){
    fstream my_file;
    my_file.open(name, ios::out);
    cout << "What operation do you want to carry out?\n\t1. Withdraw\n\t2. Transfer\n\t3. Check Balance\n\t4. Exit\n";
    int ans;
    cin >> ans;
    if(ans == 1){
        cout << "Enter the amount you want to withdraw.\n";
        int w_amount;
        cout << "Amount: ";
        cin >> w_amount;

    }else if(ans == 2){
        cout << "Enter the amount you want to transfer.\n";
        int t_amount;
        cout << "Amount: ";
        cin >> t_amount;
        int receipent;
        cout << "Enter the receipent's account number: ";
        cin >> receipent;

        transfer(receipent, amount);

    }else if(ans == 3){
        
    }else{
        return 0;
    }
}

void User_info(){

}

void User_acc_info(){}

void User_acc_history(){}

int main(){
    registration();

    return 0;
}
