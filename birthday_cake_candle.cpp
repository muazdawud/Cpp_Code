#include<bits/stdc++.h>
using namespace std;

int birthdayCakeCandles(vector<int> candles) {
	int count = 0;
	int buf;

	auto max = max_element(candles.begin(), candles.end());

	buf = *max;

	for(int candle : candles){
		if(candle == buf){
			count++;
		}
	}

	return count;
}

int main(){
	int num;
	cin >> num;

	vector<int> candle;

	for(int i = 0; i < num; i++){
		int input;
		cin >> input;
		candle.push_back(input);
	}

	cout << birthdayCakeCandles(candle) << endl;

	return 0;
}