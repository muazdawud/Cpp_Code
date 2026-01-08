//----------------------THIS IS LIKE A MAX_MIN FINDER----------------------------

#include<bits/stdc++.h>
using namespace std;

vector<int> breakingRecord(vector<int> score){
	int max = score[0];
	int max_count = 0;
	for(int sco : score){
		if(max < sco){
			max_count++;
			max = sco;
		}
	}

	cout << "MAX = " << max << "\nCOUNT = " << max_count << endl;

	int min = score[0];
	int min_count = 0;
	for(int sco : score){
		if(min > sco){
			min_count++;
			min = sco;
		}
	}

	cout << "MIN = " << min << "\nCOUNT = " << min_count << endl;

	vector<int> res;
	res.push_back(max_count);
	res.push_back(min_count);

	return res;
}

int main(){
	int num;
	cin >> num;
	vector<int> scores;

	for(int i = 0; i < num; i++){
		int input;
		cin >> input;
		scores.push_back(input);
	}

	vector<int> result = breakingRecord(scores);

	for(int rec : result){
		cout << rec << " ";
	}
}