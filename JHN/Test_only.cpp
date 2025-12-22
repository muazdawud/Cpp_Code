//#include <iostream>
//using namespace std;
//
//class Room{
//private:
//	int door;
//	int width;
//	int breadth;
//public:
//	Room(int x, int y, int z) : door(x); width(y); breadth(z) {}
//	mul(int door, int width, int bredth);
//};
//int Room::mul(int door, int width, int bredth){
//	return width*breadth;
//}
//
//int main(){
//	Room* room1 = new Room;
//	(*room1.door) = 2;
//	(*room1.width) = 20;
//	(*room1.breadth) = 30;
//	cout << room1.mul() << endl;
//
//#include<iostream>
//using namespace std;
//
//class X{
//private:
//	int x;
//public:
//	X(static int y) : x(y) {}
//
//	void print();
//};
//void X::print(){
//	cout << x << endl;
//}
//int main(){
//	X y(5);
//	y.print();
//	X m(10);
//	m.print();
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//class B;
//class C;
//class A
//{ 
//private:
//	int a;
//public:
//	A(int a_arg) {a = a_arg;}
//	friend void Display(A a_disp, B b_disp, C c_disp);
//};
//class B
//{ 
//private:
//	int b;
//public:
//	B(int b_arg) {b = b_arg;}
//	friend void Display(A a_disp, B b_disp, C c_disp);
//};
//class C
//{
//private:
//	int c;
//public:
//	C(int c_arg) {c = c_arg;}
//	friend void Display(A a_disp, B b_disp, C c_disp);
//};
//
//void Display(A a_disp, B b_disp, C c_disp)
// {
//	 cout << a_disp.a << " " << b_disp.b << " " << c_disp.c << endl; 
//}
//int main()
//{
//	A a_main(1);
//	B b_main(2);
//	C c_main(3);
//	Display(a_main,b_main,c_main);
//	
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//class salary{
//public:
//	void init (int b){ 
//		b_sal = b; 
//		your_bonus = 0; 
//	}
//	void calc_bonus (double perc){ 
//		your_bonus = b_sal * perc; 
//	}
//	static void reset_all (int p){ 
//		all_bonus = p; 
//	}
//	int comp_tot( ) const{
//		return b_sal + your_bonus + all_bonus;
//	}
// 
//private:
//	int b_sal;
//	double your_bonus;
//	static int all_bonus;
//};
//
//int salary::all_bonus = 100;
//
//int main( ){
//	salary w1, w2; 
//	w1.init(1000);
//	w2.init(2000);
//	w1.calc_bonus(0.2);
//	w2.calc_bonus(0.15);
//	
//	salary::reset_all(400);
// 
//	cout << " w1: " << w1.comp_tot( ) << '\n'<< " w2: " << w2.comp_tot( ) << endl;
//	
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Student{
//private:
//	string name;
//	string clas;
//	int roll_no;
//	int marks;
//public:
//	Student(string a, string b, int c, int d) : name(a), clas(b), roll_no(c), marks(d) {}
//
//	char grade(){
//		if(marks >= 70){
//			return 'A';
//		} else if(marks >= 60){
//			return 'B';
//		} else if(marks >= 50){
//			return 'C';
//		} else if(marks >= 40){
//			return 'D';
//		} else{
//			return 'F';
//		}
//	}
//	void print(){
//		cout << "Name = " << name << endl;
//		cout << "Class = " << clas << endl;
//		cout << "Roll_no = " << roll_no << endl;
//		cout << "Marks = " << marks << endl;
//		cout << "Grade = " << grade() << endl;
//	}
//};
//
//int main(){
//	string a,b;
//	cout << "Enter your name; " << endl;
//	getline(cin, a);
//	cout << "Enter your class; " << endl;
//	getline(cin, b);
//	int c, d;
//	cout << "Enter your Roll_no; " << endl;
//	cin >> c;
//	cout << "Enter your mark; " << endl;
//	cin >> d;
//	cout << '\n' << '\n';
//
//	Student stu1(a, b, c, d);
//	stu1.print();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int main() {
//	stack<string> cars;
//
//	// Add elements to the stack
//	cars.push("Volvo");
//	cars.push("BMW");
//	cars.push("Ford");
//	cars.push("Mazda");
// 
//	cout << cars.top() << endl;
//
//	cars.pop();
//	cout << cars.top() << endl;
//
//	cars.push("Porsche");
//	cout << cars.top() << endl;
//	/*for(int i = 0; i < cars.size(); i++){
//		cout << cars[i] << endl;
//	}*/
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main() {
//    std::vector<int> numbers;  // Declare a vector of integers
//
//    numbers.push_back(10);
//    numbers.push_back(20);
//    numbers.push_back(30);
//
//    std::cout << "Vector elements: ";
//    for (size_t i = 0; i < numbers.size(); i++) {
//        std::cout << numbers[i] << " ";
//    }
//
//    return 0;
//}
//
//#include <iostream>     
//#include <map> 
//#include <string>
//using namespace std;
//   
//int main () {
//
//	// Create a map that will store the name and age of different people
//	map<string, int> people;
//
//	people.insert({"John", 32});
//	people.insert({"Adele", 45};
//	people.insert({"Bo", 29});
//
//	// Get the value associated with the key "Adele"
//	cout << "Adele is: " << people.at("Adele") << '\n';
//
//	// Get the value associated with the key "Bo"
//	cout << "Bo is: " << people.at(" Bo") << '\n';
//
//	system("pause");
//    return 0;
//}

//#include <iostream>
//#include <map>
//using namespace std;
//
//int main(){
//	map<int, string> cars;/* = {{1, }, {2, }, {3, }, {4, }, {5, }};*/
//
//	cars[1] = "BMW";
//	cars[2] = "Mercedes";
//	cars[3] = "Volvo";
//	cars[4] = "Citroen";
//	cars[5] = "Volkswagen";
//
//	cout << "Map size = " << cars.size() << endl;
//
//	cars[6] = "Peugeot";
////int i = 1; i <= cars.size(); ++i
//	for(auto i : cars){
//		//cout << "Car[" << i << "] = " << cars.at(i) << endl;
//		cout << i.first << "." << i.second << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <map>
//using namespace std;
//
//int main(){
//	map <int, string> cars = {{1, "Koenigsegg"}, {2, "Bugatti"}, {3, "Ferrari"}, {4, "Lamborghini"}, {5, "Rimac"}};
//	/*cars[6] = "Ferrari";
//	cars[7] = "Bugatti"; 
//	cars[8] = "Mclaren";*/
//	
//	for (auto it = cars.begin(); it != cars.end(); ++it){
//	    cout << it->first << ". " << it->second << endl;
//	}
//	
//	return 0;
//}

//#include<iostream>
//#include<map>
//using namespace std;
//
//int name(){
//    multimap<int, string> cars = {
//        {1, "Bugatti"},
//        {1, "Ferrari"},
//        {2, "Lamborghini"},
//        {1, "Koenigsegg"},
//        {2, "Rimac"}, 
//        {3, "Peugeot"}
//    };
//    
//    /*multimap<int, string>::iterator it;
//    for(it = cars.begin(); it != cars.end(); ++it){
//        cout << it->first << ". " << it->second << endl;
//    }*/
//    for (const auto& it : cars){
//        int key = it.first;
//        string value = it.second;
//        cout << key << ". " << value << endl;
//    }
//    
//    return 0;
//}
	
//#include<iostream>
//#include<set>
//using namespace std;
//
//int main(){
//    set<int> num = {1, 2, 3, 4, 5, 3, 4, 6, 2, 7};
//    cout << "Set example" << endl;
//    for(int car :num ){
//        cout << car << endl;
//    }
//    
//    multiset<int> nrum = {1, 2, 3, 4, 5, 3, 4, 6, 2, 7};
//    cout << '\n' << "Multiset example" << endl;
//    for(int car : nrum){
//        cout << car << endl;
//    }
//    
//    return 0;
//}	
	
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//int main(){
//    unordered_map<int, string> cars = {
//        {1, "Bugatti"}, 
//        {2, "Koenigsegg"}, 
//        {3, "Ferrari"}
//    };
//    cout << "Initial vehicles" << endl;
//    for(auto car : cars){
//        cout << car.first << ". " << car.second << endl;
//    }
//    cars.insert({4, "Rimac"});
//    cars.insert({5, "Lamborghini"});
//    cout << "After adding two more" << endl;
//    for(auto car : cars){
//        cout << car.first << ". " << car.second << endl;
//    }
//    cout << "To find the 3rd car" << '\n' << cars[3] << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//int main(){
//    unordered_map<int, string> cars = {
//        {1, "Ferrari"},
//        {2, "Lamborghini"},
//        {3, "Bugatti"},
//        {4, "Koenigsegg"},
//        {5, "Rimac"}
//    };
//    for(const auto& it : cars){
//        cout << it.first << ". " << it.second << endl;
//    }
//    cout << '\n' << "Let's add more elements" << endl;
//    cars[6] = "BMW";
//    cars[7] = "Porsche";
//    cars[8] = "Mercedes";
//    for(const auto& it : cars){
//        cout << it.first << ". " << it.second << endl;
//    }
//    cout << '\n' << "Let's delete one elements" << endl;
//    cars.erase(5);
//    for(const auto& it : cars){
//        cout << it.first << ". " << it.second << endl;
//    }
//}

//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    
//    map < string, int> phonebook;
//    int n;
//    cin >> n;   
//    for(int i = 0; i < n; i++){
//        string a;
//        int b;
//        cin >> a >> b;
//        phonebook.insert(make_pair(a, b));
//    }
//    string c[10];
//    for(int i = 0; i < n; i++){
//        cin >> c[i];
//    }
//    for(int i = 0; i < n; i++){
//        //map <string, int>::iterator it;
//        map <string, int>::iterator itr;
//        itr = phonebook.find(c[i]);
//        if(c[i] == itr->first){
//            cout << itr->first << "=" << itr->second << endl; 
//        }else{
//            cout << "Not found" << endl;
//        }
//    }
//    /*for(int i = 0; i < n; i++){
//        cout << phonebook[c[i]] << endl;
//    }    */
//    
//    return 0;
//}

