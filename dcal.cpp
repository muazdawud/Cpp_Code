#include <bits/stdc++.h>
using namespace std;

void intro(string name){
    cout << "Hello " << name << ";" << endl;
    cout << "What operation do you want to carry out today?\n";
}
void opt(){
    cout << endl;
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
}
string check(){
    cout << "Do you want to perform another operation?\n";
    string answer;
    cin >> answer;
    if(answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y"){
        return "yep";
    }else if(answer == "No" || answer == "no" || answer == "n" || answer == "N"){
        return "nop";
    }else{
        cout << "Invalid Option\n";
        return 0;
    }
}

double add(double a, double b){
    return a+b;
}
double sub(double a, double b){
    return a-b;
}
double mult(double a, double b){
    try{
        double num;
        num = a*b;
        //return num;
        if(num != 0){
            return num;
        }else if(isinf(num)){
            throw 0;
        }else{
            throw 0;
        }
    }
    catch(int a){
        cout << "One of the input was " << a << " and multiplication by 0 is not alowed." << endl;
        return 0;
    }
}
double divi(double a, double b){
    try{
        double num;
        num = a/b;
        //return num;
        if(isinf(num)){
            throw 0;
        }else{
            return num;
        }
    }
    catch(int a){
        cout << "One of the input was " << a << " and division by 0 is not alowed." << endl;
        return 0;
    }
}

int main(){
    string chek;
    string name;
    cout << "Enter your name; ";
    cin >> name;
    cout << endl;
    
    intro(name);

    Operation_Select:
    cout << endl;

    opt();
    int oper;
    cin >> oper;

    switch(oper){
    case 1:
        cout << "You choose addition\n" << "That is great\n";
        break;
    case 2:
        cout << "You choose subtraction\n" << "That is great\n";
        break;
    case 3:
        cout << "You choose multiplication\n" << "That is great\n";
        break;
    case 4:
        cout << "You choose division\n" << "That is great\n";
        break;
    case 5:
        cout << "Bye-bye\n";
        cout << "..............................................................................\n";
        goto Last_last;
        break;
    default:
        cout << "No valid Option!\n";
        cout << "Enter a valid option\n";
        goto Operation_Select;
    }

    cout << "Enter your numbers;\n";

    double num1, num2;
    cin >> num1 >> num2;

    switch(oper){
        double solu;
    case 1:
        solu = add(num1, num2);
        cout << "Answer = " << solu << endl;
        break;
    case 2:
        solu = sub(num1, num2);
        cout << "Answer = " << solu << endl;
        break;
    case 3:
        solu = mult(num1, num2);
        cout << "Answer = " << solu << endl;
        break;
    case 4:
        solu = divi(num1, num2);
        cout << "Answer = " << solu << endl;
        break;
    }

    chek = check();
    if(chek == "yep"){
        goto Operation_Select;
    }else if(chek == "nop"){
        cout << "Bye-bye\n";
        cout << "..............................................................................\n";
    }else{
        cout << "..............................................................................\n";
    }
   
    Last_last:
    return 0;
}