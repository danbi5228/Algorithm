// string�� �����ؼ� A 5���� AAAAAA �ϰ� B�� char�� �����ؼ� �����൵ ��
//

#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0)
	{
		int caseNum, allAlpha_num = 0;
		char Alpha[11];
		int Alpha_num[20] = { 0 };

		cin >> caseNum;


		for (int i = 0; i < caseNum; i++) {
			cin >> Alpha[i] >> Alpha_num[i];
			allAlpha_num += Alpha_num[i];
		}
		
		idx++;
		cout << "#" << idx << endl;

		int tmp = 0;
		for (int i = 0; i < caseNum; i++) {
			for (int j = 0; j < Alpha_num[i];j++) {
				if (tmp % 10 == 0) cout << endl;
				cout << Alpha[i];
				tmp++;
			}
		}
	
		testNum--;
	}
}