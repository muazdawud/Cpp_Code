#include<bits/stdc++.h>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
	int apple_count = 0, orange_count = 0, i = 0;

	for(int apple : apples){
		int temp = apple;
		temp = apple + a;
		apples[i] = temp;
		i++;
	}
	i = 0;
	for(int orange : oranges){
		int temp = orange;
		temp = orange + b;
		oranges[i] = temp;
		i++;
	}

	for(int apple : apples){
		if(apple >= s && apple <= t){
			apple_count++;
		}
	}

	for(int orange : oranges){
		if(orange >= s && orange <= t){
			orange_count++;
		}
	}

	cout << apple_count << "\n" << orange_count << endl;
}

int main(){
	int sam_s, sam_t, tree_a, tree_b, apple, orange;
	vector<int> apples, oranges;

	cin >> sam_s >> sam_t >> tree_a >> tree_b >> apple >> orange;

	for(int i = 0; i < apple; i++){
		int input;
		cin >> input;
		apples.push_back(input);
	}

	for(int i = 0; i < orange; i++){
		int input;
		cin >> input;
		oranges.push_back(input);
	}

	countApplesAndOranges(sam_s, sam_t, tree_a, tree_b, apples, oranges);

	return 0;
}