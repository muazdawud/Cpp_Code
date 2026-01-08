// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <set>
// #include <map>
// #include <algorithm>
// using namespace std;

// class student{
// private:
//     map<string, int> students;

// public:
//     void extract(string sentence);

//     void add(string name, int mark){
//         int temp = 0;
//         auto it = students.find(name);
//         if(it != students.end()){
//             temp = it->second;
//             students.at(name) = mark+temp;
//         }else{
//             students.insert({name, mark});
//         }
//     }

//     void erase(string name){
//         students.erase(name);
//     }

//     void print(string name){
//         auto it = students.find(name);
//         if(it != students.end()){
//             cout << students.at(name) << endl;
//         }else{
//             cout << "0" << endl;
//         }
//     }
// };

// void student::extract(string sentence){
//     int type = 0;
//     string name = "";
//     int mark = 0;

//     int i = 0;

//     while(sentence[i] != ' '){
//         type = type*10+sentence[i]-'0';
//         i++;
//     }

//     i++;

//     while((i < (int)sentence.length())  && (sentence[i] != ' ')){
//         name += sentence[i];
//         i++;
//     }

//     i++;

//     while(i < (int)sentence.length()){
//         mark = mark*10+sentence[i]-'0';
//         i++;
//     }

//     if(type == 1){
//         add(name, mark);
//     }else if(type == 2){
//         erase(name);
//     }else if(type == 3){
//         print(name);
//     }
// }

// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     student s1;
//     int query;
//     cin >> query;
//     cin.ignore();
//     for(int i = 0; i < query; i++){
//         string input;
//         getline(cin, input);
//         s1.extract(input);
//     }

//     return 0;
// }


// #include <vector>
// #include <iostream>
// #include <map>
// using namespace std;

// class student{
// private:
//     map<string, int> students;
//     vector<string> inputs;
// public:
//     void add(string sentence){
//         inputs.push_back(sentence);
//     }

//     void extract();

//     void add(string name, int mark){
//         int temp = 0;
//         auto it = students.find(name);
//         if(it != students.end()){
//             temp = it->second;
//             students.at(name) = mark+temp;
//         }else{
//             students.insert({name, mark});
//         }
//     }

//     void erase(string name){
//         students.erase(name);
//     }

//     void print(string name){
//         int temp = 0;
//         auto it = students.find(name);

//         if(it != students.end()){
//             temp = it->second;
//             cout << temp << endl;
//         }else{
//             cout << temp << endl;
//         }
//     }
// };

// void student::extract(){
//     for(auto sentence : inputs)
//     {   
//         int type = 0;
//         string name = "";
//         int mark = 0;
    
//         int i = 0;
    
//         while(sentence[i] != ' '){
//             type = type*10+sentence[i]-'0';
//             i++;
//         }
    
//         i++;
    
//         while((i < (int)sentence.length())  && (sentence[i] != ' ')){
//             name += sentence[i];
//             i++;
//         }
    
//         i++;
    
//         while(i < (int)sentence.length()){
//             mark = mark*10+sentence[i]-'0';
//             i++;
//         }
    
//         if(type == 1){
//             add(name, mark);
//         }else if(type == 2){
//             erase(name);
//         }else if(type == 3){
//             print(name);
//         }
//     }
// }

// int main() {
//      student s1;
//     int query;
//     cin >> query;
//     cin.ignore();
//     for(int i = 0; i < query; i++){
//         string input;
//         getline(cin, input);
//         s1.add(input);
//     }

//     s1.extract();

//     return 0;
// }

#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main(){
    int q;
    cin >> q;
    map<string, int> student;

    for(int i = 0; i < q; i++){
        int type;
        string key;
        cin >> type >> key;

        // switch(type){
        // case 1:
            if(type == 1){
                int value;
                cin >> value;
                auto it = student.find(key);
                if(it != student.end()){
                    value += it->second;
                    student.at(key) = value;
                }else{
                    student.insert({key, value});
                }
            }
        // case 2:
            else if(type == 2){
                student.erase(key);
            }
        // case 3:
            else if(type == 3){
                int temp = 0;
                auto it = student.find(key);
                if(it != student.end()){
                    temp = it->second;
                    cout << temp << endl;
                }else{
                    cout << temp << endl;
                }
            }
        }
    //}
}