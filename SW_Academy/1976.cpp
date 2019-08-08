#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int test_num, idx = 0;
	cin >> test_num;
	while (test_num--) {
		int hour_1, hour_2, m_1, m_2, result_h,result_m;
		cin >> hour_1 >> m_1 >> hour_2 >> m_2;

		result_h = hour_1 + hour_2;
		result_m = m_1 + m_2;

		if (result_h > 12) result_h -= 12;
		if (result_m >= 60) {
			result_h += 1;
			result_m -= 60;
		}

		idx++;
		cout << "#" << idx << " " << result_h << " " << result_m << endl;
	}
}