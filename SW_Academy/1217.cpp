#include "pch.h"
#include <iostream>
using namespace std;
int result = 1;
int main(void) {
	int idx, num_10 = 10;
	while (num_10 > 0) {
		cin >> idx;
		result = 1;
		int a, b;
		cin >> a >> b;

		for (int i = 0; i < b; i++) {
			result *= a;
		}

		cout << "#" << idx << " " << result << endl;
		num_10--;
	}
}