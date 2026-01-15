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


// #include <bits/stdc++.h>
// #include <ios>
// #include <map>
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;
 
// class HRML{
// private:
//     vector<string> program;
//     //vector<string> tags;
//     multimap<string, string> tag_att;
//     vector<string> att;
//     vector<string> val;
//     int itr_master;
// public:
//     friend class QUERY;
//     void add(string prog_pass){ program.push_back(prog_pass); cout << "Added Successfully\n";}

//     void addTag();
//     void display(){
//         cout << "Displaiyng all the programs in program vector\n";
//         for(auto p : program){
//             cout << p << endl;
//         }
//         cout << endl;
//         cout << "Displaiyng all the tags in the tag_att map\n";
//         for(const auto& p : tag_att){
//             cout << p.first << " " << p.second << endl;
//         }
//         cout << endl;
//         cout << "Displaiyng all the tags in the att_val map\n";
//         for(int i = 0; i < (int)att.size(); i++){
//             cout << att[i] << " " << val[i] << endl;
//         }
//         cout << endl;
//     }

//     // void process_program(){
//     //     cout << "Processing Program\n";
//     //     addTag();
//     // }

//     bool check_tag(string tg, string atr){
//         auto it = tag_att.find(tg);
//         if(it != tag_att.end()){
//             if(it->second == atr){ 
//                 itr_master = distance(tag_att.begin(), it);
//                 cout << "Tag found.\n";      
//                 return true;
//             }
//         }

//         return false;
//     }

//     string getValue(string a){
//         return val[itr_master];
//     }
// };

// void HRML::addTag(){
//     cout << "Processing Program\n";
//     cout << "Extracting and adding tags in HRML\n\n";
//     for(auto line : program){
//         int size = (int)line.size()-1;
//         if(line[0] == '<' && line[size] == '>'){
//             if(line.at(1) != '/'){
//                 cout << "Line = " << line << " Size = " << line.size() << endl;
//                 int i = 1;
//                 string tag;
//                 string attribute;
//                 string value;
            
//                 while(line.at(i) != ' ' && line[i] != '>'){
//                     tag += line.at(i);
//                     i++;
//                 }
//                 cout << "Tag= " << tag << endl;
//                 //tags.push_back(tag);
            
                
//                 while(i < (int)line.size()-2){
//                     while((line.at(i) == '=') || (line.at(i) == ' ') || (line.at(i) == '"')){
//                         i++;
//                     }

//                     while((line.at(i) != ' ') && (line.at(i) != '=')){
//                         attribute += line[i];
//                         i++;
//                     } 
//                     cout << "Attribute= " << attribute << endl;

//                     while((line.at(i) == '=') || (line.at(i) == ' ') || (line.at(i) == '"')){
//                         i++;
//                     }
            
//                     while(line.at(i) != '"'){
//                         if(i >= (int)line.size()){
//                             break;
//                         }
//                         value += line[i];
//                         i++;
//                     }           
//                     cout << "Value= " << value << endl; 

//                     if(attribute.size() > 0 && value.size() > 0){
//                         tag_att.insert(make_pair(tag, attribute));
//                         att.push_back(attribute);
//                         val.push_back(value);
//                         cout << "Attribute and value added\n\n";
//                         attribute.clear();
//                         value.clear();
//                     }
//                 }
//             }else{
//                 cout << "Prog. is a Closing Tag\n\n";
//             }
//         }else{
//             cout << "Prog. is invalid\n" << endl;
//         }
//     }
// }

// class QUERY{
// private:
//     vector<string> query;
//     vector<string> tag;
//     vector<string> atr;
// public:
//     void add(string prog_pass){ query.push_back(prog_pass); cout << "Added Successfully\n";}

//     void process_query(){
//         cout << "Processing Query\n\n";
//         for(auto q : query){
//             int i = 0;
//             string t, a;
//             while(q[i] != '~'){
//                 if(q[i] == '.'){
//                     t.clear();
//                     i++;
//                 }
//                 t += q[i];
//                 i++;
//             }

//             i++;

//             while(i < (int)q.size()){
//                 a += q[i];
//                 i++;
//             }
//             if(t.size() > 0 && q.size() > 0){
//                 tag.push_back(t);
//                 atr.push_back(a);
//             }
            
//         }
//     }

//     void output_query(HRML& get){
//         get.display();
//         for(int i = 0; i < (int)tag.size(); i++){
//             cout << "Tag and value to read = " << tag[i] << " & " << atr[i] << endl;
//             if(get.check_tag(tag[i], atr[i])){
//                 cout << get.getValue(atr[i]) << endl;
//             }else{
//                 cout << "Not Found!" << endl;
//             }
//         }
//     }
// };


// int main(){
//     HRML code1;
//     QUERY query1;
//     int n, m;
//     cin >> n >> m;

//     string input;
//     cout << "\nCollecting program and query\n";
//     cin.ignore();
//     for(int i = 0; i < n; i++){
//         getline(cin, input);
//         cout << "Program input" << i << " = " << input << endl;
//         code1.add(input);
//     }

//     for(int i = 0; i < m; i++){
//         getline(cin, input);
//         cout << "Query input" << i << " = " << input << endl;
//         query1.add(input);
//     }

//     cout << "Finished Collecting and Inserting Inputs\n\n";

//     code1.addTag();
//     query1.process_query();
//     query1.output_query(code1);

//     return 0;
// }


////----------------------CORRECT LANGUAGE TEMPLATE----------------------////

#include <bits/stdc++.h>
using namespace std;
 
class HRML{
private:
    vector<string> program;
    vector<string> tags;
    map<string, string> att_val;
public:
    friend class QUERY;
    void add(string prog_pass){ program.push_back(prog_pass);}

    void addTag();

    string getValue(string atrr){
        auto it = att_val.find(atrr);
        if(it != att_val.end()){
            return att_val[atrr];
        }

        return "Not Found!";
    }
};

void HRML::addTag(){
    for(auto line : program){
        if(line[0] == '<' && line[(int)line.size()-1] == '>'){
            if(line.at(1) != '/'){
                int i = 1;
                string tag;
                string attribute;
                string value;
            
                while(line.at(i) != ' ' && line[i] != '>'){
                    tag += line.at(i);
                    i++;
                }
                
                while(i < (int)line.size()-2){
                    while((line.at(i) == '=') || (line.at(i) == ' ') || (line.at(i) == '"')){
                        i++;
                    }

                    while((line.at(i) != ' ') && (line.at(i) != '=')){
                        attribute += line[i];
                        i++;
                    } 

                    while((line.at(i) == '=') || (line.at(i) == ' ') || (line.at(i) == '"')){
                        i++;
                    }
            
                    while(line.at(i) != '"'){
                        if(i >= (int)line.size()){
                            break;
                        }
                        value += line[i];
                        i++;
                    }           

                    if(attribute.size() > 0 && value.size() > 0){
                        string temp;
                        if(tags.size() > 0){
                            temp = tags[0];
                            for(int k = 1; k < (int)tags.size(); k++){
                                temp += "."+tags[k];
                            }
                            temp += ".";
                        }
                        attribute = temp+tag+"~"+attribute;
                        att_val.insert(make_pair(attribute, value));
                        attribute.clear();
                        value.clear();
                    }
                }

                tags.push_back(tag);
            }else{
                tags.pop_back();
            }
        }
    }
}

class QUERY{
private:
    vector<string> query;
public:
    void add(string prog_pass){ query.push_back(prog_pass);}

    void output_query(HRML& get){
        for(int i = 0; i < (int)query.size(); i++){
            cout << get.getValue(query[i]) << endl;
        }
    }
};


int main(){
    HRML code1;
    QUERY query1;
    int n, m;
    cin >> n >> m;

    string input;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, input);
        code1.add(input);
    }

    for(int i = 0; i < m; i++){
        getline(cin, input);
        query1.add(input);
    }

    code1.addTag();
    query1.output_query(code1);

    return 0;
}
