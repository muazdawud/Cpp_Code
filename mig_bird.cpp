#include<bits/stdc++.h>
using namespace std;

int frequency(vector<int> arr){
	vector<int> counts;
	int count = 0; 
	int num;
	int position = 0;

	for(int i = 0; i < (int)arr.size(); i++){
		for(int j : arr){
			if(arr[i] == j){
				count++;
			}
		}

		counts.push_back(count);
		count = 0;
	}

	num = counts[0];

	for(int i = 0; i < (int)counts.size(); i++){
		if(counts[i] > num){
			num = counts[i];
			position = i;
		}else if(counts[i] == num){
			if(arr[i] < arr[position]){
				num = arr[i];
				position = i;
			}
		}
	}

	return arr[position];
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

	cout << frequency(arr) << endl;
}



#include <iostream>
#include <vector>
#include <map>

using namespace std;

int frequency(const vector<int>& arr) {
    if (arr.empty()) return -1; 
    
    map<int, int> counts;
    for (int num : arr) {
        counts[num]++;
    }

    int mostFrequent = arr[0];
    int maxCount = 0;

    for (auto const& [val, freq] : counts) {
        if (freq > maxCount) {
            maxCount = freq;
            mostFrequent = val;
        }
    }

    return mostFrequent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << frequency(arr) << endl;
    return 0;
}