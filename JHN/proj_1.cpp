//#include<iostream>
//#include<string>
//using namespace std;
//
//class student{
//public:
//	student(string name, string section, int years, int cla){
//		nm = name;
//		sc = section; 
//		yr = years;
//		cl = cla;
//	}
//	void print();
//private:
//	string nm;
//	string sc;
//	int cl;
//	int yr;
//};
//int main(){
//	student stu("Alice", "Pirmary", 9, 4);
//	
//	//stu.student;
//	stu.print();
//
//	system("pause");
//	return 0;
//}
//void student::print(){
//		cout << "My name is " << nm << ". I am in " << sc << " " << cl << ". I am " << yr << " years old.\nThank you. " << endl;
//	}

//#include <iostream>
//using namespace std;
//class Ratio
//{ public:
// Ratio(int n=0, int d=1) : num(n), den(d) { }
// //Ratio(const Ratio& r) : num(r.num), den(r.den) {}
// //Ratio(Ratio& m, int n) : num(m.num), den(m.den), mul(n) {}
// void print(){ cout << num << "/" << den << endl; }
// void prin(){ cout << "(" << num << "/" << den << ")" << "*" << mul << endl; }
// private:
// int num, den, mul;
//};
//int main()
//{ Ratio x(22,7);
// Ratio y(x); // calls the copy constructor, copying x to y
// //Ratio m(y, 10);
// x.print();
// y.print();
// //m.prin();
// system("pause");
// return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class circle{
//private:
//	float radius;
//	double y;
//public:
//	circle(float x, double z) : radius(x), y(z) {}
//
//	float area(){
//		return y * pow(radius, 2);
//	}
//	float circumference(){
//		return 2 * y * radius;
//	}
//};
//
//int main(){
//	double y = 3.142;
//	circle c(5.0, y);
//	cout << c.area() << endl;
//	cout << c.circumference() << endl;
//
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//class rectangle{
//private:
//	double length;
//	double breadth;
//public:
//	rectangle(double x, double y) : length(x), breadth(y) {}
//
//	double area(){
//		return length * breadth;
//	}
//	double peirmeter(){
//		return (2*length) + (2*breadth);
//	}
//};
//
//int main(){
//	rectangle rec(3.0, 4.0);
//
//	cout << rec.area() << endl;
//	cout << rec.peirmeter() << endl;
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person{
//private:
//	string name;
//	int age;
//	string country;
//public:
//	Person(string a, int b, string c) : name(a), age(b), country(c) {}
//
//	void print(){
//		cout << "Name: " << name << '\n' << "Age: " << age << '\n' << "Country: " << country << endl;
//	}
//};
//int main(){
//	Person p1("Adam", 23, "Namibia");
//
//	p1.print();
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Major;
//
//class Minor{
//private:
//	int a;
//	string b;
//
//	friend int func(Minor, Major);
//	friend string fun(Minor);
//
//public:
//	Minor() : a(15), b("Adam") {}
//};
//
//class Major{
//private:
//	int c;
//	char d;
//	
//	friend int func(Minor, Major);
//	friend char fu(Major);
//
//public:
//	Major() : c(10), d('A') {}
//};
//
//int func(Minor e, Major f){
//	return e.a + f.c;
//}
//string fun(Minor g){
//	return g.b;
//}
//char fu(Major h){
//	return h.d;
//}
//
//int main(){
//	Minor a;
//	Major b;
//	Minor c;
//	Major d;
//
//	cout << "Minor a + Major b = " << func(a, b) << endl;
//	cout << fun(c) << " also has " << "'" << fu(d) << "'" << " grade in his exams." << endl;
//
//	system("pause");
//	return 0;
//}

