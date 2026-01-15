#include<bits/stdc++.h>
using namespace std;

int divSumPair(vector<int> arr, int k){
	int count = 0;
	int i = 0;

	for(int a : arr){
		int sum = 0;

		for(int j = i+1; j < (int)arr.size(); j++){
			sum = a+arr[j];
			if(sum%k == 0){
				count++;
			}
		}
		i++;
	}

	return count;
}

int main(){
	int a, k;
	cin >> a >> k;
	vector<int> arr;

	for(int i = 0; i < a; i++){
		int input;
		cin >> input;
		arr.push_back(input);
	}

	cout << divSumPair(arr, k) << endl;
}