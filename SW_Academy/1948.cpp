#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int lastday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0) {
		int result = 0;
		int a, a_n, b, b_n;
		cin >> a >> a_n >> b >> b_n;

		if (a == b) {
			result = b_n - a_n +1;
		}
		else {
			result += lastday[a - 1] - a_n;
			a++;
			while (1) {
				result += lastday[a - 1];
				a++;
				if (a == b) {
					result += b_n+1;
					break;
				}
			}
		}
		idx++;
		cout << "#" << idx <<" "<< result << endl;
		testNum--;
	}
}