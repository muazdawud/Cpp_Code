// #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	int num1, num2;
// 	cin >> num1;

// 	vector<int> arr;
// 	for(int i = 0; i < num1; i++){
// 		int inp;
// 		cin >> inp;
// 		arr.push_back(inp);
// 	}

// 	sort(arr.begin(), arr.end());

// 	cin >> num2;

// 	for(int i = 0; i < num2; i++){
// 		int inp;
// 		cin >> inp;
// 		auto it = find(arr.begin(), arr.end(), inp);
// 		if(it != arr.end()){
// 			cout << "Yes " << distance(arr.begin(), it)+1 << endl;
// 		}else{
// 			it = upper_bound(arr.begin(), arr.end(), inp);
// 			cout << "No " << (int)(it - arr.begin())+1 << endl;
// 		}
// 	}

// 	return 0;
// }


////------------------------OPTIMIZED------------------------////

#include <bits/stdc++.h>
using namespace std;

int main(){
	int num1;
	cin >> num1;

	vector<int> arr(num1);
	for(int i = 0; i < num1; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> num1;

	for(int i = 0; i < num1; i++){
		int inp;
		cin >> inp;
		auto it = lower_bound(arr.begin(), arr.end(), inp);
		if(it != arr.end() && *it == inp){
			cout << "Yes " << (int)(it - arr.begin())+1 << endl;
		}else{
			cout << "No " << (int)(it - arr.begin())+1 << endl;
		}
	}

	return 0;
}