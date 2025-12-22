#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

int main() {
    long long num;
    redo:
    cout << "Enter a number: ";
    cin >> num;

    string s = to_string(num);

    // Pad with leading zeros until length = 10
    while (s.length() < 10) {
        s = "0" + s;
    }

    cout << s << endl;

    cout << "Do you want to try again? ";
    string ans;
    cin >> ans;
    if(ans == "y" || ans == "Y" || ans == "yes" || ans == "Yes"){
    	goto redo;
    }
    return 0;
}

// void read_input(fstream& myfile){
// 	string inp;
//     getline(cin, inp);

//     myfile << inp << endl;
// }

// int main(){
// 	fstream my_file;
// 	my_file.open("C:\\Users\\KIBRIS ORDER\\New_Sublime\\t2t.txt", ios::out);
    
//     if(!my_file.fail()){
//     	read_input(my_file);
//     	my_file.close();
//     }
    
//     my_file.open("C:\\Users\\KIBRIS ORDER\\New_Sublime\\t2t.txt", ios::in);
//     string line;
// 	while(getline(my_file, line)){
// 		cout << line << endl;
// 	}

//     my_file.close();
//    	return 0;
// }