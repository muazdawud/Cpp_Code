#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int n;
	int pri_sum = 0;
	int sec_sum = 0;
	cin >> n;

	int arr[n][n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	int num = 0;

	for(int i = 0; i < n; i++){
		pri_sum += arr[i][num];
		num++;
	}

	num = n-1;

	for(int i = 0; i < n; i++){
		sec_sum += arr[i][num];
		num--;
	}

	cout << abs(pri_sum - sec_sum) << endl;
}