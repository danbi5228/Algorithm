#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int CaseNum;
	int Port[40001] = { 0, };
	int all_max = 1;
	cin >> CaseNum;
	vector <int> max_port(CaseNum+1);

	for (int i = 1; i <= CaseNum; i++) {
		cin >> Port[i];
	}

	max_port[1] = 1;
	int pt = 2;
	while (CaseNum >= pt) {
		vector <bool> b_pt(CaseNum+1);
		for (int i = pt; i > 1; i--) {
			if (Port[pt] < Port[i - 1]) {
				b_pt[i - 1] = false;
			}
			else {
				b_pt[i - 1] = true;
			}
		}
		if (max_port[pt - 1] > all_max)
			all_max = max_port[pt - 1];

		int max_num = 0;
		for (int j = pt-1; j >= 1; j--) {
			if (b_pt[j] == true && max_port[j] > max_num) {
				max_num = max_port[j];
			}
			if (max_num == all_max)
				break;
		}

		max_port[pt] = max_num+1;
		pt += 1;
	}

	sort(max_port.begin(), max_port.end());
	cout << max_port[CaseNum] << endl;
	
	return 0;
}