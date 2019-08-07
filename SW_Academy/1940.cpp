#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int test_num, idx = 0;
	cin >> test_num;
	while (test_num--) {
		int case_num = 0;
		int speed = 0, result = 0;
		cin >> case_num;
		while (case_num--) {
			int a, b;
			cin >> a;
			if (a == 1) {
				cin >> b;
				speed += b;
				result += speed;
			}
			else if (a == 2) {
				cin >> b;
				if (speed >= b) {
					speed -= b;
				}
				else speed = 0;

				result += speed;
			}
			else {
				result += speed;
			}
		}

		idx++;
		cout << "#" << idx << " " << result << endl;
	}
}