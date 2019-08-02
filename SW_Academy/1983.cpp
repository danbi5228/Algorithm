#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace  std;

bool desc(double a, double b) {
	return a > b;
}
int main(void) {
	int testNum, idx = 0;
	cin >> testNum;

	string result_print[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
	// 등수 찾아서 (N/10)을 한 값을 idx로 하는 result_print 하면 끝...ㅅㅂㅋㅋㅋㅋㅋㅋㅋㅋ

	while (testNum > 0) {
		int caseNum, stgroup, stgroup_origin;
		double studentNum;
		vector <double> st;
		cin >> caseNum >> studentNum;

		for (int i = 0; i < caseNum; i++) {
			double a, b, c,tmp;
			cin >> a >> b >> c;
			tmp = (a*0.35) + (b*0.45) + (c*0.2);
			st.push_back(tmp);
			if (i == studentNum - 1) {
				studentNum = st[i];
			}
		}

		sort(st.begin(),st.end(),desc);
		stgroup_origin = caseNum / 10;
		stgroup = stgroup_origin;
		for (int i = 0; i < caseNum; i++) {

			if (st[i] == studentNum) {
				double tmp;
				int result = 0;
				while (1) {
					tmp = (double(i)+1) / stgroup;
					if (tmp > 1) {
						stgroup += stgroup_origin;
						result++;
					}
					else {
						idx++;
						cout << "#" << idx << " " << result_print[result] << endl;;
						testNum--;
						break;
					}
				}
				break;
			}
		}
	}
}