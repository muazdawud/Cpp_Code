#include <iostream>
using namespace std;

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