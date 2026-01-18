#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int s_count = 0; 
int p_count = 0;

class Person {
protected:
    string name;
    int age;

public:
    virtual void getdata(){}
    virtual void putdata(){}
};

class Professor : public Person {
public:
    int publication, cur_id;

    virtual void getdata(){ 
        p_count++;
        cin >> name >> age >> publication;
        
        cur_id = p_count;
    }

    virtual void putdata(){
        cout << name << " " << age << " " << publication << " " << cur_id << "\n";
    }
};

class Student : public Person {
public:
    vector<int> marks = vector<int>(6);
    int cur_id;

    virtual void getdata(){
        s_count++;     
        cin >> name >> age;

        for(int i = 0; i < 6; i++){
            cin >> marks[i];
        } 

        cur_id = s_count;
    }

    virtual void putdata(){
        int sum = 0;

        for(int i = 0; i < 6; i++){
            sum += marks[i];
        }

        cout << name << " " << age << " " << sum << " " << cur_id << "\n";
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }else{
            per[i] = new Student; // Else the current object is of type Student
        }

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++){
        per[i]->putdata(); // Print the required output for each object.
    }

    return 0;

}
