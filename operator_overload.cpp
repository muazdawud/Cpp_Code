#include <iostream>
using namespace std;

class Fraction{
private:
	int num;
	int den;
public:
	explicit Fraction(int a, int b) : num{a}, den{b} {}

	void print(){
		cout << num << "/" << den << endl;
	}

	friend Fraction operator * (const Fraction& num1, const Fraction& num2);
	friend Fraction operator * (const Fraction& num1, int value);
	friend Fraction operator * (int value, const Fraction& num1);
};

Fraction operator * (const Fraction& num1, const Fraction& num2){
	int n_temp = num1.num * num2.num;
	int d_temp = num1.den * num2.den;

	return Fraction {n_temp, d_temp};
}

Fraction operator * (const Fraction& num1, int value){
	int n_temp = num1.num * value;

	return Fraction {n_temp, num1.den};
}

Fraction operator * (int value, const Fraction& num1){
	int n_temp = num1.num * value;

	return Fraction {n_temp, num1.den};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}




// ||||| Rubbish Trial |||||

// class Money{
// private:
// 	int amt;
// public:
// 	Money(int amount) : amt{amount} {}

// 	friend Money operator*(const Money& m1, const Money& m2);

// 	int getM() {
// 		return amt;
// 	}
// };

// Money operator*(const Money& m1, const Money m2){
// 	return Money {m1.amt * m2.amt};
// }

// Money mo1{3};
// Money mo2{4};

// Money mon {mo1 * mo2};


// #include <iostream>

// class Money{
// private:
// 	int amt;
// 	int amt2;
// public:
// 	explicit Money(int amount1, int amount2) : amt{amount}, amt2{amount2} {}

// 	friend Money operator*(const Money& m1, const Money& m2);

// 	int getM() {
// 		return ans;
// 	}
// };

// // note: this function is not a member function!
// Money operator*(const Money& m1, const Money& m2){

// 	return Money {m1.amt*m2.amt};
// }

// int main()
// {
// 	Money mo1{5};
// 	Money mo2{4};

// 	Money mon {mo1*mo2};
// 	std::cout << "I have " << mon.getM() << " cents.\n";

// 	return 0;
// }