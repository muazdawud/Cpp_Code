#include<bits/stdc++.h>
using namespace std;

vector<int> gradingStudents(vector<int> grades) {
	vector<int> result;

	for(int grade : grades){
		if(grade < 38){
			result.push_back(grade);
		}else{
			int temp = grade/5;
			temp = temp*5+5;
			if((temp-grade) < 3){
				grade = temp;
			}

			result.push_back(grade);
		}
	}

	return result;
}

int main(){
	int num;
	cin >> num;

	vector<int> grade;
	for(int i = 0; i < num; i++){
		int input;
		cin >> input;
		grade.push_back(input);
	}

	grade = gradingStudents(grade);

	for(int grd : grade){
		cout << grd << endl;
	}

	return 0;
}