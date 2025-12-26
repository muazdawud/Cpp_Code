#include<bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
	int count = 0;
	
	while(x1 != x2){
		x1 += v1;
		x2 += v2;
		count++;
		if(x1 == x2){
			return "YES";
		}
		if(count == 32768){
			break;
		}
	}

	return "NO";

}

int main()
{
    int x1, v1, x2, v2;

    cin >> x1 >> v1 >> x2 >> v2;

    string result = kangaroo(x1, v1, x2, v2);

    cout << result << "\n";

    return 0;
}