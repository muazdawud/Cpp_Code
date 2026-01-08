// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include<string>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

//     int n, q;
//     cin >> n >> q;

//     vector<string> major;
//     vector<string> quers;
//     vector<string> attribute;

//     for(int i = 0; i < n; i++){
//         string input;
//         getline(cin, input);
//         major.push_back(input);
//     }

//     for(int i = 0; i < q; i++){
//         string query;
//         cin >> query;
//         int j = 0;
//         string extract = "";
//         while(query[j] != '~'){
//             extract = extract+query[j];
//             j++;
//             if(query[j] == '.'){
//                 extract.clear();
//             }
//         }

//         quers.push_back(extract);
//     }

//     for(auto tag : quers){
//         for(auto sentence : major){
//             size_t pos = sentence.find(tag);
//             if(pos != string::npos){

//             }
//         }
//     }

//     return 0;
// }



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

class tag{

};

class attribute{

};

