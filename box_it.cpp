#include<bits/stdc++.h>
#include <tuple>

using namespace std;

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
 
class Box{
private:
	int l, b, h;
public:
	Box() : l{0}, b{0}, h{0} {}
	Box(int len, int bre, int hei) : l{len}, b{bre}, h{hei} {}
	Box(const Box& box) : l{box.l}, b{box.b}, h{box.h} {}

	int getLength() const {
		return l;
	}
	int getBreadth() const {
		return b;
	}
	int getHeight() const {
		return h;
	}

	long long CalculateVolume(){ 

		return (long long)l*b*h;
	}

	friend ostream& operator << (ostream& out, const Box& box);
	friend bool operator < (const Box& box1, const Box& box2);
	friend bool operator > (const Box& box1, const Box& box2);
};

ostream& operator << (ostream& out, const Box& box){
	out << box.l << " " << box.b << " " << box.h;

	return out;
}

bool operator > (const Box& b1, const Box& b2) {
    if (b1.l > b2.l) return true;
    if (b1.l < b2.l) return false;

    if (b1.b > b2.b) return true;
    if (b1.b < b2.b) return false;

    return b1.h > b2.h;
}

bool operator < (const Box& b1, const Box& b2) {
    if (b1.l < b2.l) return true;
    if (b1.l > b2.l) return false;

    if (b1.b < b2.b) return true;
    if (b1.b > b2.b) return false;

    return b1.h < b2.h;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type == 1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type == 3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type == 4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type == 5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}