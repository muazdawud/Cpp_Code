#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream my_file("C:\\Users\\KIBRIS ORDER\\Desktop\\Example.txt", ios::out);

    if(my_file.fail()){
        cout << "Error opening file\n" << endl;
        my_file.close();
        return 1;
    }

    my_file << "First, There's nothing to write here" << endl;
    my_file << "Second, There's also nothing to write here" << endl;
    my_file << "But thirdly, sadly, nothing is to be written here" << endl;
    my_file << "But regardless, we've got nothing to say" << endl;
    my_file << "So good bye." << endl;

    my_file.close();

    my_file.open("C:\\Users\\KIBRIS ORDER\\Desktop\\Example.txt", ios::app);

    if(my_file.fail()){
        cout << "Error opening file\n" << endl;
        my_file.close();
        return 1;
    }

    my_file << ".............................................................................." << endl;
    my_file << "First, There's nothing to write here" << endl;
    my_file << "Second, There's also nothing to write here" << endl;
    my_file << "But thirdly, sadly, nothing is to be written here" << endl;
    my_file << "But regardless, we've got nothing to say" << endl;
    my_file << "So good bye." << endl;

    my_file.close();

    my_file.open("C:\\Users\\KIBRIS ORDER\\Desktop\\Example.txt", ios::in);

    if(my_file.fail()){
        cout << "Error opening file\n" << endl;
        my_file.close();
        return 1;
    }

    string line;

    while(getline(my_file, line)){
        
        cout << line << endl;
    }
    
    my_file.close();

    return 0;
}