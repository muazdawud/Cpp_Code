// #include <cstdio>
// #include <vector>
// #include <iostream>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int a, b;
//     cin >> a >> b;

//     int size_arr;

//     vector<vector<int>> arr_major(a);
        
//     for(int i = 0; i < a; i++){
//         cin >> size_arr;
//         arr_major[i].resize(size_arr);
//         for(int j = 0; j < size_arr; j++){
//             cin >> arr_major[i][j];
//         }
//     }
        
//     int q1, q2;

//     while(b > 0){
//         cin >> q1 >> q2;

//         cout << arr_major[q1][q2] << endl;

//         b--;
//     }
    
//     return 0;
// }


// // //Almost C and Assembly style of memory allocation, but there are other ways to increase it's speed.

// // int main(){
// //     int a, b, arr_size, input;
// //     cin >> a >> b;

// //     int** arr = new int*[a];
    
// //     for(short i = 0; i < a; i++){
// //         cin >> arr_size;
// //         arr[i] = new int[arr_size];
// //         assert(arr[i] != NULL);
// //         for(int j = 0; j < arr_size; j++){
// //             cin >> input;
// //             arr[i][j] = input;
// //         }
// //     }

// //     for(int i = 0; i < a; i++){
// //         delete [] arr[i];
// //     }
// //     delete [] arr;

// //     return 0;
// // }