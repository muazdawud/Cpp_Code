
	
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


void universal_file(string fname, int accountnum, string password){
	fstream myfile;
	string bankname = "Dbank_";
	string ext = ".txt";
	string temp = fname;

	//bankname.appenD(fname);
	bankname.append(temp);
	bankname.append(ext);

	myfile.open(temp, ios::out);

	myfile << accountnum << endl;
	myfile << password << endl;

	myfile.close();
}

void user_info(string name){
	fstream myfile;
	string bankname = "Dbank_";
	string ext = ".txt";
	string ext2 = "_info.txt";
	string bankname2 = "Dbank_";

	bankname2.append(name);
	bankname2.append(ext);

	myfile.open(bankname, ios::in);

	string line;
	int linenum = 0;
	while(getline(myfile, line)){
		linenum++;
		if(linenum == 1){
			myfile.close();
			break;
		}
	}

	bankname.append(line);
	bankname.append(ext2);

	myfile.open(bankname, ios::in);

	
	while(getline(myfile, line)){
		linenum++;
		if(linenum == 2){
			cout << "loading...." << endl;
			break;
		}
	}
	myfile.close();

	bankname.append(line);
	bankname.append(ext);

	myfile.open(bankname);

	while(getline(myfile, line)){
		cout << line << endl;
	}
}

void acc_balance(string name){
	fstream myfile;
	string line;
	string ext = ".txt"
	string bankname = "Dbank_";
	string ext2 = "_balance.txt";
	int balance;
	string temp = bankname;
	name.append(ext);

	// string passw;
	// cout << "Enter your password: ";
	// cin >> passw;

	myfile.open(name, ios::in);
	int linecount = 0;
	while(getline(myfile, line)){
		linecount++;
		if(linecount == 1){
			myfile.close();
			break;
		}
	}

	bankname.append(line);
	bankname.append(ext2);

	myfile.open(bankname, ios::in);

	while(getline(myfile, line)){
		cout << line << endl;
	}
	cout << "\n";
	cout << ".......................................";
}

void transfer(int r_acc_num, int amount, string s_name){
	fstream myfile;
	string ext = "_balance.txt";
	string bankname = "Dbank_";
	string line;
	int linenum = 0;
	long new_balance;

	bankname.append(acc_num);
	bankname.append(ext);

	myfile.open(bankname, ios::out);

	while(getline(myfile, line)){
		new_balance = stol(line);
	}

	myfile.close();

	new_balance = new_balance + amount;

	myfile.open(bankname, ios::in);

	myfile << new_balance << endl;

	myfile.close();

	update_history(s_acc_num, r_acc_num, amount);
}

void update_history(string s_a_n, string r_a_n, string ampunt){
	fstream myfile;
	string ext = "history.txt";
	string bankname = "Dbank";
	string temp = bankname;
	string dt = date_time();
	
	bankname.append(s_a_n);
	bankname.append(ext);

	myfile.open(bankname, ios::app);

	myfile << "History: Account was Debited." << endl;
	myfile << "Amount = " << amount << endl;
	myfile << "Date & Time: " << dt << endl;
	myfile << ".........." << endl;

	myfile.close();

	temp.append(r_a_n);
	temp.append(ext);

	myfile.open(temp, ios::app);

	myfile << "History: Account was Credited." << endl;
	myfile << "Amount = " << amount << endl;
	myfile << "Date & Time: " << dt << endl;
	myfile << ".........." << endl;

	myfile.close();
}

void confirm_exit(){
    cout << "Do you want to exit?\n\t1. Yes\n\t2. No\n";
    int ans;
    while(cin >> ans){
        if(ans == 1){
            cout << "Bye-bye\n";
            cout << "..............................................................................\n";
            exit(0);
        }
        if(ans == 2){
            login();
        }
        cout << "Invalid options\n";
    }
}

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
}

void take_password(){
	cout << "Enter your Transaction pin: ";

	string pin;
	cin >> pin;
	
	check_input Pin;
	
	Pin.assign(pin);
	bool check_correct = Pin.check();

	if(check_correct == false){
		cout << "Incorrect Password\n";
		return false;
	}

	return true;
}



Sleep(5000);
FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

#ifdef _WIN32
#include <windows.h>
#endif

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