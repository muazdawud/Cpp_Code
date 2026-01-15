//__________________________CODE WITH DEBUG OUTPUT__________________________

// #include <bits/stdc++.h>
// using namespace std;

// int birthday(vector<int> choc, int d, int m){
// 	vector<int> temp_vec;
// 	int count = 0; 

// 	cout << "\nCHOC_ARR_SIZE = " << choc.size() << endl;

// 	for(int i = 0; i < (int)choc.size(); i++){

// 		cout << endl;
// 		int j = i;
// 		int sum = 0;

// 		for(int n = 0; n < m; n++){
// 			if(j < (int)choc.size()){
// 				sum += choc.at(j);
// 				cout << "CHOC[" << j << "] = " << choc.at(j) << endl;
// 			}
// 			j++;
// 		}

// 		cout << "SUM @ i[" << i << "] = " << sum << endl;

// 		if(sum == d){
// 			count++; 
// 		}
// 		cout << "COUNT = " << count << endl;
// 		cout << endl;
// 	}

// 	return count;
// }

// int main(){
// 	int a;
// 	cin >> a;
// 	vector<int> arr;

// 	for(int i = 0; i < a; i++){
// 		int input;
// 		cin >> input;
// 		arr.push_back(input);
// 	}

// 	int d, m;
// 	cin >> d >> m;

// 	cout << birthday(arr, d, m);
// }



//_____________________WITHOUT DEBUG OUTPUT________________________

#include <bits/stdc++.h>
using namespace std;

int birthday(vector<int> choc, int d, int m){
	int count = 0; 

	for(int i = 0; i < (int)choc.size(); i++){
		int j = i;
		int sum = 0;

		for(int n = 0; n < m; n++){
			if(j < (int)choc.size()){
				sum += choc.at(j);
			}
			j++;
		}

		if(sum == d){
			count++; 
		}
	}

	return count;
}

int main(){
	int a;
	cin >> a;
	vector<int> arr;

	for(int i = 0; i < a; i++){
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int d, m;
	cin >> d >> m;

	cout << birthday(arr, d, m);
}