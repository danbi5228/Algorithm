#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
// insertion sort�� ������ input�� ���ؼ�, ���� �� �ִ� ���ڰ� ������ ��� ������ ���� �ΰ��� swap �ϸ鼭 Ƚ��--;
using namespace std;
bool desc(double a, double b) {
	return a > b;
}
int main(void) {
	int testNum, idx = 0;
	cin >> testNum;
	while (1) {
		int Num, change;
		int tmp, Num10 = 1000000;

		vector <char> charNum;
		vector <int> intNum;
		vector <int> maxNum;

		cin >> Num >> change;
		
		while (1) {
			tmp = Num / Num10;
			
			if (tmp < 1) {
				Num10 /= 10;
			}
			else {
				intNum.push_back(tmp);
				maxNum.push_back(tmp);
				Num %= Num10;
			}
			if (Num == 0) break;
		}

		sort(maxNum.begin(), maxNum.end(),desc);
		
		int max = intNum[intNum.size() - 1];
		while (change > 0) {

			//case 1. ������ ���� ū ���� ã�Ƽ� �ٲ��ֱ�~!
			for (int i = intNum.size() - 1; i >= 0; i--) {
				if (max > intNum[i]) max = intNum[i];
			}
		}

		idx++;
		cout << "#" << idx << " "<< max;
		testNum--;
	}
}