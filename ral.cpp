//No Comments; Just See and Run

 #include<bits/stdc++.h>
 #include<string>
 #include<cstdio>
 #include<windows.h>
 using namespace std;

 void intro();
 void clearConsole();
 bool detail_check(string name);
 bool invalid_acc();
 void to_register();
 int check();
 void to_login();
 void options();
 int cond_check();
 
 int main(){
 	intro();
 	options();
     
     return 0;
 }

 void intro(){
     cout << "Hello;" << endl;
     cout << "This is a registration console.\n" << "So choose an option;\n";
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

bool detail_check(string name){
	fstream my_file;

	name.append(".txt");
	my_file.open(name, ios::in);

	int linec = 0;
	string line;
	while(getline(my_file, line)){
		linec++;
	}

	my_file.close();
	if(linec > 0){
		return 1;
	}else{
		return 0;
	}
}

bool invalid_acc(){
	clearConsole();
	cout << "Invalid option!\n";
	cout << "Do you want to register?\n";
	cout << "\t1. Yes.\n";
	cout << "\t2. No.\n";

	int ans;
	cin >> ans;
	bool check;

	if(ans == 1){
		check = true;
		return check;
	}else if(ans == 2){
		check = false;
		return check;
	}else{
		cout << "Bye-bye.\n";
    	cout << "..............................................................................\n";
		exit(0);
	}
}

void to_register(){
	clearConsole();

	fstream given;

		//string rest = to_register(st_call);
		//st_call.close();
	int cval;
	string gen_name;
	int dob_day;
	string dob_month;
	int dob_year;
	string  user_name;
	string password;
	string cp;
	
	cout << "Enter your Full name: ";
	cin.ignore();
	getline(cin, gen_name);
	cval = cond_check();
	if(cval == 1){
		cout << "\n";
	}
	if(cval != 1){
		cout << "Enter your Full name: ";
		cin.ignore();
		getline(cin, gen_name);
		cout << "\n";
	}
	dday:
	cout << "Enter the day you were born (0<day<31): ";
	cin >> dob_day;
	if(dob_day > 31 || dob_day < 0){
		cout << "Invalaid day; Try Again\n\n";
		goto dday;
	}
	cval = cond_check();
	if(cval == 1){
		cout << "\n";
	}
	if(cval != 1){
		cout << "Enter the day you were born (0<day<31): ";
		cin >> dob_day;
		cout << "\n";
	}
	dmonth:
	cout << "Enter the month (E.g 'January, February' with 1st letter capital): ";
	//cin.ignore();
	cin >> dob_month;
	
	if(dob_month != "January" && dob_month != "February" && dob_month != "March" && dob_month != "April" && dob_month != "May" && dob_month != "June" && dob_month != "July" && dob_month != "August" && dob_month != "September" && dob_month != "October" && dob_month != "November" && dob_month != "December"){
		cout << "Invalid month; Try Again '" << dob_month << "'\n\n";
		//cout <<  << endl;
		goto dmonth;
	}
	cval = cond_check();
	if(cval == 1){
		cout << "\n";
	}
	if(cval != 1){
		cout << "Enter the month (E.g 'January, February' with 1st letter capital): ";
		cin >> dob_month;
		cout << "\n";
	}
	dyear:
	cout << "Enter the year (1900<year<2025): ";
 	cin >> dob_year;
 	
	if(dob_year > 2025 || dob_year <1900){
 		cout << "Invalid year; Try Again\n\n";
 		goto dyear;
 	}
 	cval = cond_check();
 	if(cval == 1){
 		cout << "\n";
 	}
 	if(cval != 1){
		cout << "Enter the year (1900<year<2025): ";
 		cin >> dob_year;
 		cout << "\n";
	}

 	trialU:
 	cout << "Enter your desired username (Can't be left empty & without spaces): ";
 	cin >> user_name;
 	if(user_name.size() <= 0){
 		cout << "Username can't be empty\n";
 		goto trialU;
 	}
 	bool sain = detail_check(user_name);
	if(sain == 1){
		cout << "Username already exists, try another one\n";
		goto trialU;
	}
 	trial:
	cout << "Enter your password (Can't be left empty & without spaces): ";
	//cin.ignore();
	//getline(cin, password);
	cin >> password;
	if(password.size() < 8){
		cout << "Password cannot  be less than 8.\nTry again!\n";
		goto trial;
	}
	cout << "Comfirm your password: ";
	//cin.ignore();
	//getline(cin, cp);
	cin >> cp;
	

	if(cp != password){
		cout << "Password does'nt match!!" << endl;
		goto trial;
	}
    
    string temp = user_name;
 	string ext = ".txt";
	temp.append(ext);
     
    given.open(temp, ios::out);
 
 	given << "Name: " << gen_name << endl;
 	given << "DOB: " << dob_day << ", " << dob_month << ", " << dob_year << endl;
 	given << user_name << endl;
 	given << password << endl;
 
 	given.close();

 	cout << "Registration Successful. ^-^\n";
 	for(int i = 0; i < 10; i++){
		cout << "\n";
	}
	cout << "Type 'Back' to go back || Press any key to exit.\n";
	string bck;
	cin >> bck;
	if(bck == "Back" || bck == "back"){
		clearConsole();
		options();
	}else{
		cout << "Bye-bye\n";
       	cout << "..............................................................................\n";
 		exit(0);
	}
 	// for(int i = 0; i < 3000; i++){i;}
 	// clearConsole();
 	// options();
 }
 
 int check(){
     int che;
     cin >> che;
 
     return che;
 }

 int cond_check(){
 	cout << "Are you sure your input is correct; Yes or No? ";
 	string ans;
 	cin >> ans;
 	if(ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes"){
 		return 1;
 	}else{
 		return 0;
 	}
 }
 
 void to_login(){
	clearConsole();

	fstream my_file;

 	string pw;
 	string user;
 	int linenum = 0;
 	cout << "Enter your username: ";
 	//cin.ignore();
 	cin >> user;
 	cout << "Enter your password: ";
 	//cin.ignore();
 	cin >> pw;
    
    string temp = user;
    string ext = ".txt";
    temp.append(ext);
    
    my_file.open(temp, ios::in);

    if(my_file.fail()){
    	cout << "No such account registered.\n";
    	cout << "Type 'R' to re-check your details OR Press any key to Exit.\n";
    	char inp;
    	cin >> inp;
    	if(inp == 'r' || inp == 'R'){
    		to_login();
    	}else{
	    	bool ans = invalid_acc();
	    	if(ans == true){
	    		to_register();
	    	}else{
	    		cout << "Bye-bye\n";
	    		cout << "..............................................................................\n";
				exit(0);
	    	}
	    }
    }

 	string line;
    while(getline(my_file, line)){
		linenum++;
		if((linenum == 3 && line != user) || line == ""){
			cout << "Incorrect username or password!\n";
			string bbk;
			while(cin >> bbk){}
			 my_file.close();
			 clearConsole();
			options();
			break;
		}
		if(linenum == 4 && line != pw){
			cout << "Incorrect username or password!\n";
			my_file.close();
			clearConsole();
			options();
			break;
		}
		if(linenum == 4 && line == pw){
			cout << "Access granted. ^_^" << endl;
			my_file.close();
			for(int i = 0; i < 10; i++){
				cout << "\n";
			}
			cout << "Type 'Back' to go back || Press any key to exit.\n";
			string bck;
			cin >> bck;
			if(bck == "Back" || bck == "back"){
				clearConsole();
				options();
			}else{
				cout << "Bye-bye\n";
		       	cout << "..............................................................................\n";
		 		exit(0);
			}
			// for(int i = 0; i < 3000; i++){i;}
			// clearConsole();
			// options();
			// break;
		}
	}
 }
 
 void options(){
 	cout << "\t1. Register.\n" << "\t2. Login.\n\t3. Exit\n";
 
 	int che = check();
 
 	if(che == 1){
     	back:
     	to_register();		
    }else if(che == 2){
     	to_login();
 	}else if(che == 3){
		cout << "Bye-bye\n";
       	cout << "..............................................................................\n";
 		exit(0);
 	}else{
 		// clearConsole();
 		// cout << "Invalid option!\n";
 		// cout << "Do you want to register?\n";
 
 		bool ans = invalid_acc();
 		if(ans == true){
 			goto back;
 		}else{
 			cout << "Bye-bye\n";
         	cout << "..............................................................................\n";
 			exit(0);
 		}
 	}
 }