/*
题目：https://www.nowcoder.com/practice/dd0c6b26c9e541f5b935047ff4156309
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h> // sort() need

using namespace std;

int main() {
    int num;
    int order;
	while (cin >> num) {
	    vector<int> num_vec(num);
	    for (int i = 0; i < num; i++) {
	        cin >> num_vec[i];
	    }
	    cin >> order;
	    
	    if (order)
	        sort(num_vec.begin(), num_vec.end(), greater<int>());
	    else
	        sort(num_vec.begin(), num_vec.end());
        
	    for (int i = 0; i < num - 1; i++) {
	        cout << num_vec[i] << " ";
	    }
	    cout << num_vec[num - 1] << endl;
	}
	
	return 0;
}