// #include <iostream>
// using namespace std;
// class Ratio
// { public:
//  void assign(int, int);
//  double convert();
//  void invert();
//  void print();
//  private:
//  int num, den;
// };
// int main()
// { Ratio x;
//  x.assign(22,7);
//  cout << "x = ";
//  x.print();
//  cout << " = " << x.convert() << endl;
//  x.invert();
//  cout << "1/x = "; x.print();
//  cout << endl;
// }
// void Ratio::assign(int numerator,int denominator)
// { num = numerator;
//  den = denominator;
// }
// double Ratio::convert()
// { return double(num)/den;
// }
// void Ratio::invert()
// { int temp = num;
//  num = den;
//  den = temp;
// }
// void Ratio::print()
// { cout << num << '/' << den;
// } 

// #include<iostream>
// #include<cctype>
// #include<windows.h>
// #include<string>

// using namespace std;

// int main(){
// 	//cin.flush();
// 	cout << "Enter a string: ";
// 	string num;
// 	cin >> num;

// 	//vector<char> input;

// 	for(long i = 0; i < num.size(); i++){
// 		cout << num[i] << endl;
// 		if(isalpha(num[i])){
// 			cout << "It is an alphabet.\n";
// 		}else{
// 			cout << "It is not.\n";
// 		}
// 	}

    
//     main();
// 	return 0;
// }


// #include <iostream>
// #include <vector>
// #include <cctype>
// using namespace std;

// int main() {
//   vector<char> num {'1', '2', '3', '4', '5'};

//   cout << "Initial Vector: ";

//   for (const int& i : num) {
//     if(isdigit(i)){
//         cout << "Yes\n";
//     }else{
//         cout << "No\n";
//     }
//   }
  
//   // add the integers 6 and 7 to the vector
//   num.push_back(6);
//   num.push_back(7);

//   cout << "\nUpdated Vector: ";

//   for (const int& i : num) {
//     if(isalnum(i)){
//         cout << "Yes\n";
//     }else{
//         cout << "No\n";
//     }
//   }
  
//   string alpha;
  
//   for(int i = 0; i < num.size(); i++){
//       if(!isdigit(num[i])){
//           continue;
//       }
//       alpha = alpha + num[i];
//   }
  
//   cout << endl;
//   cout << alpha << endl;

//   return 0;
// }


cout << "Enter your Transaction pin: ";

	string pin;
	cin >> pin;
	
	check_input Pin;
	
	Pin.assign(pin);
	bool check_correct = Pin.check();

	if(check_correct == false){
		cout << "Incorrect Password\n";
		return false;
	}else{
		cout << "Correct Password\n";
	}