//#include <iostream>
//#include <string>
//using namespace std;
//
//class BankAccount{
//private:
//	int accnum;
//	int balance;
//public:
//	BankAccount(int* a, int b = 100) : accnum(*a), balance(b) {}
//
//	void withdraw(int x){
//		if(x < balance){
//			cout << x << " has successfully being withdrawn and your remaining balance is " << balance - x << endl;
//		} else {
//			cout << "Insufficient balance" << endl;
//		}
//	}
//	int deposit(int y){
//		return balance + y;
//	}
//};
//
//int main(){
//	int* a = new int[10];
//	int b, c;
//	cout << "Choose from the options below; " << '\n' << "1. Withdraw" << '\n' << "2. Deposit" << endl;
//	cin >> c;
//	if(c == 1){
//		cout << "Enter your account number" << endl;
//		for(int x = 0; x < 1; x++){ 
//			cin >> a[10];
//		}
//		cout << "Enter the amount you want to withdraw" << endl;
//		cin >> b;
//		BankAccount acc1(a);
//		acc1.withdraw(b);
//	}else if(c == 2){
//		cout << "Enter your account number" << endl;
//		for(int x = 0; x < 1; x++){ 
//			cin >> a[10];
//		}
//		cout << "Enter the amount you want to deposit" << endl;
//		cin >> b;
//		BankAccount acc1(a);
//		cout << b << " has successfully deposited and your new balance is " << acc1.deposit(b) << endl;
//
//	}else{
//		cout << "Option not available" << endl;
//	}
//	delete[] a;
//
//	system("pause");
//	return 0;
//}