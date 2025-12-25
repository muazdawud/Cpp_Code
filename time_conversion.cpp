#include<bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
	int a = 0, b = 0, c = 0, i = 0;
	string last_param = "";

	while(s[i] != ':'){
		a = a*10+s[i]-'0';
		i++;
	}

	i++;

	while(s[i] != ':'){
		b = b*10+s[i]-'0';
		i++;
	}

	i++;

	while(i < (int)s.length()-2){
		c = c*10+s[i]-'0';
		i++;
	}

	while(i < (int)s.length()){
		last_param += s[i];
		i++;
	}

	s = "";

 	if(last_param == "AM"){
		if(a == 12){
			a = a - 12;
			s = "0" + to_string(a) + ":";
		}else if(a < 10){
			s = "0" + to_string(a) + ":";
		}else{
			s = to_string(a) + ':';
		}

		if(b < 10){
			s += "0" + to_string(b) + ":";
		}else{
			s += to_string(b) + ':';
		}

		if(c < 10){
			s += "0" + to_string(c);
		}else{
			s += to_string(c);
		}
	}else if(last_param == "PM"){
		if(a < 12){
			a += 12;
			s = to_string(a) + ":";
		}else{
			s = to_string(a) + ":";
		}

		if(b < 10){
			s += "0" + to_string(b) + ":";
		}else{
			s += to_string(b) + ":";
		}

		if(c < 10){
			s += "0" + to_string(c);
		}else{
			s += to_string(c);
		}
	}

	return s;
}

int main(){
	string input;
	cin >> input;
	
	cout << timeConversion(input) << endl;
	
	return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// string timeConversion(string s){
// 	int a = stoi(s.substr(0, 2));
// 	int b = stoi(s.substr(3, 2));
// 	int c = stoi(s.substr(6, 2));
// 	string last_param = s.substr(8, 2);

// 	if(last_param == "AM"){
// 		if(a == 12){
// 			a = a - 12;
// 			s = "0" + to_string(a) + ":";
// 		}else if(a < 10){
// 			s = "0" + to_string(a) + ":";
// 		}else{
// 			s = to_string(a) + ':';
// 		}

// 		if(b < 10){
// 			s += "0" + to_string(b) + ":";
// 		}else{
// 			s += to_string(b) + ':';
// 		}

// 		if(b < 10){
// 			s += "0" + to_string(c);
// 		}else{
// 			s += to_string(c);
// 		}
// 	}else if(last_param == "PM"){
// 		if(a < 12){
// 			a += 12;
// 			s = to_string(a) + ":";
// 		}else if(a == 12){
// 			s = to_string(a) + ":";
// 		}

// 		if(b < 10){
// 			s += "0" + to_string(b) + ":";
// 		}else{
// 			s += to_string(b) + ":";
// 		}

// 		if(c < 10){
// 			s += "0" + to_string(c);
// 		}else{
// 			s += to_string(c);
// 		}
// 	}

// 	return s;
// }

// int main(){
// 	string input;
// 	cin >> input;

// 	cout << timeConversion(input) << endl;

// 	return 0;
// }