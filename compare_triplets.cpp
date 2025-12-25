#include<bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
	int s1 = 0, s2 = 0;

	for(int i = 0; i < 3; i++){
		if(a[i] < b[i]){
			s2++;
		}else if(a[i] > b[i]){
			s1++;
		}
	}

	vector<int> result;
	result.push_back(s1);
	result.push_back(s2);

	return result;
}

int main(){
	vector<int> arr1;
	vector<int> arr2;

	int input;

	for(int i = 0; i < 3; i++){
		cin >> input;
		arr1.push_back(input);
	}

	for(int i = 0; i < 3; i++){
		cin >> input;
		arr2.push_back(input);
	}

	vector<int> result = compareTriplets(arr1, arr2);

	for(int i = 0; i < 2; i++){
		cout << result[i] << " ";
	}

	return 0;
}