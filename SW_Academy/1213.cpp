#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int num_10 = 10;
	while (num_10 > 0) {
		int idx, result = 0, tmp = 0, position = 0;
		string a;
		string input;
		cin >> idx;
		cin >> a;
		cin >> input;
		

		while ( position != string::npos && tmp >= 0) {
			tmp = input.find(a, position);
			result++;
			position = tmp + 1;
		}
			
		cout << "#" << idx << " " << result-1 << endl;
		num_10--;
	}
}




//if (search(input[0],input[input.size()-1],result) == a) {
//	cout << "wow" << endl;
//}


//for (int i = 0; i < input.size()-a.size(); i++) {
//	for(int k = 0; k<)
//	for (int j = 0; j < a.size();j++) {
//		if (a[0] != input[i]) break;
//		else if(a[j] != input[i + j]) break;
//		else result++;
//	}
//}
