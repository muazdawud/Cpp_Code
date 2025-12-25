#include<iostream>
using namespace std;

void miniMaxSum(long long *arr, short size){
	long long miniSum = 0;
	long long maxSum = 0; 

	long long* end = arr + size;

	for(long long* i = arr; i < end; i++){
		for(long long* j = arr; j < end; j++){
			if(*i > *j){
				maxSum += (long long)*i;
				break;
			}
		}
	}

	for(long long* i = arr; i < end; i++){
		for(long long* j = arr; j < end; j++){
			if(*i < *j){
				miniSum += (long long)*i;
				break;
			}
		}
	}

	if(miniSum == 0 && maxSum == 0){
		long long* i = arr;
		for(short k = 0; k < 4; k++){
				miniSum += (long long)*i;
				i++;
		}

		maxSum = miniSum;
	}

	cout << miniSum << " " << maxSum << endl;
}

int main(){
	long long arr[5];

	for(int i = 0; i < 5; i++){
		cin >> arr[i];
	}

	miniMaxSum(arr, 5);

	return 0;
}



// #include <iostream>
// using namespace std;
// int main()
// {
// 	 const int SIZE = 3;
// 	 short a[SIZE] = {22, 33, 44};
// 	 short* clone = a;
// 	 short* end = clone + SIZE;
// 	 cout << a << endl;
// 	 cout << clone << endl;
// 	 short sum = 0;
// 	 for (short* p = a; p < end; p++)
// 	 { 
// 	 	cout << p << endl;
// 	 	cout << *p << endl;
// 	 	sum += *p;
// 	 }
// 	 cout << sum << endl;
// }
