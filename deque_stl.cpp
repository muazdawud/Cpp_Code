#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> myInt;

	for(int i = 0; i < n; i++){
		if(!myInt.empty() && myInt.front() == i-k){
			myInt.pop_front();
		}

		while(!myInt.empty() && arr[i] >= arr[myInt.back()]){
			myInt.pop_back();
		}

		myInt.push_back(i);

		if(i >= k-1){
			cout << arr[myInt.front()] << (i == n-1? "" : " ");
		}
	}

	cout << "\n";
}

int main(){  
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}