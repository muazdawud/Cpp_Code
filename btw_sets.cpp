//--------------------ROUGH--------------------

// // #include<bits/stdc++.h>
// // using namespace std;

// // int getTotalX(vector<int> a, vector<int> b) { 
// // 	int term1 = a[a.size()-1];
// // 	int count = 0;
// // 	int i = 0;

// // 	bool check = true; 

// // 	while(check){ 
// // 		for(int bs : b){
// // 			if(!check){
// // 				return count;
// // 			}
// // 			if(bs%term1 != 0){
// // 				check = false;
// // 			}
// // 		} 

// // 		if(check){count++;}
// // 		try{
// // 			term1 *= a.at(0);
// // 		}catch(...){
// // 			i++;
// // 			term1 *= a.at(0);
// // 		} 
// // 	}

// // 	return count;
// // }

// // int main(){
// // 	int a, b;
// // 	cin >> a >> b;
// // 	vector<int> arr1, arr2;

// // 	for(int i = 0; i < a; i++){
// // 		int input;
// // 		cin >> input;
// // 		arr1.push_back(input);
// // 	}

// // 	for(int i = 0; i < b; i++){
// // 		int input;
// // 		cin >> input;
// // 		arr2.push_back(input);
// // 	}

// // 	cout << getTotalX(arr1, arr2) << endl;

// // 	return 0;
// // }


//--------------------ROUGH--------------------


// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // int getTotalX(vector<int> a, vector<int> b) { 
// // //     int term1 = a[a.size()-1];
// // //     int count = 0;
// // //     int i = a.size()-1;

// // //     bool check = true; 

// // //     while(check){ 
// // //         for(int bs : b){
// // //             if(!check){
// // //                 return count;
// // //             }
// // //             if(bs%term1 != 0){
// // //                 check = false;
// // //             }
// // //         } 

// // //         i--;
// // //         if(check){count++;}
// // //         try{
// // //             term1 *= a.at(0);
// // //         }catch(...){
// // //             i++;
// // //             term1 *= a.at(0);
// // //         } 
// // //     }

// // //     return count;
// // // }

// // // int main(){
// // //     int a, b;
// // //     cin >> a >> b;
// // //     vector<int> arr1, arr2;

// // //     for(int i = 0; i < a; i++){
// // //         int input;
// // //         cin >> input;
// // //         arr1.push_back(input);
// // //     }

// // //     for(int i = 0; i < b; i++){
// // //         int input;
// // //         cin >> input;
// // //         arr2.push_back(input);
// // //     }

// // //     cout << getTotalX(arr1, arr2) << endl;

// // //     return 0;
// // // }

//________________________CORRECT VERSION, WITH DEBUG OUTPUT___________________________

// #include<iostream>
// #include<vector>
// using namespace std;

// bool check_multiple(int num, vector<int> a){
// 	bool check = false;
// 	for(int n : a){
// 		if(num%n == 0){
// 			check = true;
// 		}else{
// 			return false;
// 		}
// 	}

// 	return check;
// }

// int getTotalX(vector<int> a, vector<int> b){
// 	int count = 0;
// 	int high = 0;
// 	int low = b[0];

// 	for(int num : a){
// 		if(num > high){
// 			high = num;
// 		}
// 		for(int comp : a){
// 			if(comp >= high){
// 				high = comp;
// 			}
// 		}
// 	}

// 	cout << "Highest of A_ARR = " << high << endl;

// 	for(int num : b){
// 		if(num <= low){
// 			low = num;
// 		}
// 	}

// 	cout << "Lowest of B_ARR = " << low << endl;

// 	int v_count = 1;
// 	int major_check = 0;
// 	bool checkram = false;	
		
// 	while(!checkram){
// 		int temp = high*v_count;
// 		cout << "Temp = " << temp << endl;
// 		cout << "V_COUNT = " << v_count << endl;
// 		if(check_multiple(temp, a)){
// 			for(int n : b){			
// 				if(n%temp == 0){
// 					cout << "Mod Good\n";
// 					major_check++;
// 				}else{
// 					cout << "Breaked\n";
// 					break;
// 				}
// 			}
// 		}
// 		cout << "MAJOR_CHECK = " << major_check << "\nB_ARR_SIZE = " << b.size() << endl;
// 		if(major_check == (int)b.size()){
// 			count++;
// 		}
// 		major_check = 0;
// 		v_count++;
// 		if(temp >= low){
// 			checkram = true;
// 		}
// 		cout << endl;
// 	}
	

// 	return count;
// }

// int main(){
// 	vector<int> arr1, arr2;
// 	int a, b;
// 	cin >> a >> b; 
 
// 	for(int i = 0; i < a; i++){
// 		int inp;
// 		cin >> inp;
// 		arr1.push_back(inp);
// 	}

// 	for(int i = 0; i < b; i++){
// 		int inp;
// 		cin >> inp;
// 		arr2.push_back(inp);
// 	}

// 	cout << getTotalX(arr1, arr2) << endl;

// 	return 0;
// }

//--------------------ROUGH--------------------

// #include<bits/stdc++.h>
// using namespace std;

// int getTotalX(vector<int> a, vector<int> b) { 
// 	int term1 = a[a.size()-1];
// 	int count = 0;
// 	int i = 0;

// 	bool check = true; 

// 	while(check){ 
// 		for(int bs : b){
// 			if(!check){
// 				return count;
// 			}
// 			if(bs%term1 != 0){
// 				check = false;
// 			}
// 		} 

// 		if(check){count++;}
// 		try{
// 			term1 *= a.at(0);
// 		}catch(...){
// 			i++;
// 			term1 *= a.at(0);
// 		} 
// 	}

// 	return count;
// }

// int main(){
// 	int a, b;
// 	cin >> a >> b;
// 	vector<int> arr1, arr2;

// 	for(int i = 0; i < a; i++){
// 		int input;
// 		cin >> input;
// 		arr1.push_back(input);
// 	}

// 	for(int i = 0; i < b; i++){
// 		int input;
// 		cin >> input;
// 		arr2.push_back(input);
// 	}

// 	cout << getTotalX(arr1, arr2) << endl;

// 	return 0;
// }


//--------------------ROUGH--------------------


// // #include<bits/stdc++.h>
// // using namespace std;

// // int getTotalX(vector<int> a, vector<int> b) { 
// //     int term1 = a[a.size()-1];
// //     int count = 0;
// //     int i = a.size()-1;

// //     bool check = true; 

// //     while(check){ 
// //         for(int bs : b){
// //             if(!check){
// //                 return count;
// //             }
// //             if(bs%term1 != 0){
// //                 check = false;
// //             }
// //         } 

// //         i--;
// //         if(check){count++;}
// //         try{
// //             term1 *= a.at(0);
// //         }catch(...){
// //             i++;
// //             term1 *= a.at(0);
// //         } 
// //     }

// //     return count;
// // }

// // int main(){
// //     int a, b;
// //     cin >> a >> b;
// //     vector<int> arr1, arr2;

// //     for(int i = 0; i < a; i++){
// //         int input;
// //         cin >> input;
// //         arr1.push_back(input);
// //     }

// //     for(int i = 0; i < b; i++){
// //         int input;
// //         cin >> input;
// //         arr2.push_back(input);
// //     }

// //     cout << getTotalX(arr1, arr2) << endl;

// //     return 0;
// // }

//________________________CORRECT VERSION, WITHOUT DEBUG OUTPUT___________________________

// #include <iostream>
// #include <vector>
// using namespace std;

// bool check_multiple(int num, vector<int> a){
// 	bool check = false;
// 	for(int n : a){
// 		if(num%n == 0){
// 			check = true;
// 		}else{
// 			return false;
// 		}
// 	}

// 	return check;
// }

// int getTotalX(vector<int> a, vector<int> b){
// 	int count = 0;
// 	int high = 0;
// 	int low = b[0];

// 	// if(a.size() == 1){
// 	// 	return 1;
// 	// }

// 	for(int num : a){
// 		if(num > high){
// 			high = num;
// 		}
// 		for(int comp : a){
// 			if(comp >= high){
// 				high = comp;
// 			}
// 		}
// 	}

// 	for(int num : b){
// 		if(num <= low){
// 			low = num;
// 		}
// 	}

// 	int v_count = 1;
// 	int major_check = 0;
// 	bool checkram = false;

// 	while(!checkram){
// 		int temp = high*v_count;
// 		if(check_multiple(temp, a)){
// 			for(int n : b){			
// 				if(n%temp == 0){
// 					major_check++;
// 				}else{
// 					break;
// 				}
// 			}
// 		}
// 		if(major_check == (int)b.size()){
// 			count++;
// 		}
// 			major_check = 0;
// 		v_count++;
// 		if(temp >= low){
// 			checkram = true;
// 		}
// 	}

// 	return count;
// }

// int main(){
// 	vector<int> arr1, arr2;
// 	int a, b;
// 	cin >> a >> b; 
 
// 	for(int i = 0; i < a; i++){
// 		int inp;
// 		cin >> inp;
// 		arr1.push_back(inp);
// 	}

// 	for(int i = 0; i < b; i++){
// 		int inp;
// 		cin >> inp;
// 		arr2.push_back(inp);
// 	}

// 	cout << getTotalX(arr1, arr2) << endl;

// 	return 0;
// }