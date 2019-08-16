#include "pch.h"
#include <iostream>

using namespace std;

int main(void) {
	int testNum, idx = 0; 
	cin >> testNum;
	while (testNum--) {
		int result = 0;
		int L, U, X;
		cin >> L >> U >> X;

		if (X >= L & X <= U) result = 0;
		else if (X < L) result = L - X;
		else if (X > U) result = -1;

		idx++;
		cout << "#" << idx << " " << result << endl;
	}
}