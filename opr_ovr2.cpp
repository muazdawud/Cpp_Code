#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
private:
public:
   vector<vector<int>> a;

   friend Matrix operator + (const Matrix& m1, const Matrix& m2);
};

Matrix operator + (const Matrix& m1, const Matrix& m2){
   Matrix temp;

   vector<int> resl;
   
   int principal = m1.a.size();

   for(int i = 0; i < principal; i++){
      int main = m1.a[i].size();
      for(int j = 0; j < main; j++){
         int x = m1.a[i][j] + m2.a[i][j];

         resl.push_back(x);
      }

      temp.a.push_back(resl);
      resl.clear();
   }

   return temp;
}

int main () {
   int cases, k;
   cin >> cases;

   for(k = 0; k < cases ; k++) {
      Matrix x;
      Matrix y;
      Matrix result;

      int n,m,i,j;
      cin >> n >> m;

      for(i = 0; i < n; i++) {
         vector<int> b;
         int num;

         for(j = 0; j < m; j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }

      for( i = 0; i < n; i++) {
         vector<int> b;
         int num;

         for(j = 0; j < m; j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }

      result = x+y;

      for(i = 0; i < n; i++) {
         for(j = 0; j < m; j++) {
            cout << result.a[i][j] << " ";
         }

         cout << endl;
      }
   }  

   return 0;
}
