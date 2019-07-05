#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr;
int caseNum = 10, idx = 1, dumpN, tmp;
int maxBox, minBox, cntMAX = 1, cntMIN = 1, cmpMax, cmpMin;

int main(void) {

	while (caseNum > 0) {
		int Pflag = 0;

		cin >> dumpN;
		for (int i = 0; i < 100; i++) {
			cin >> tmp;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end()); // �������� ����

		while (dumpN > 0) {
			//FindMax();
			//FindMin();

			cntMAX = 1, cntMIN = 1;
			// �ִ밪, �ּҰ�, �ִ밪 ���� ����, �ּҰ� ���� ����, �ٷ� ���� ���ڿ��� ����,���� ���� �� �����ſ� ���缭 dump ����.

			//Max ã��
			maxBox = arr[99];
			for (int i = 98; i > 0; i--) {
				if (arr[i] == maxBox) cntMAX++;
				else {
					cmpMax = maxBox - arr[i];
					break;
				}
			}

			//Min ã��
			minBox = arr[0];
			for (int i = 1; i < 100; i++) {
				if (minBox == arr[i]) cntMIN++;
				else {
					cmpMin = arr[i] - minBox;
					break;
				}
			}

			if (min(cntMAX,cntMIN) > dumpN) {
				sort(arr.begin(), arr.end());
				Pflag = 1;
				cout << "#" << idx << " " << arr[99] - arr[0] << endl;
				idx++;
				break;
			}
			else {
				tmp = min(cntMAX,cntMIN);
				dumpN -= tmp;
				for (int i = 0; i < tmp; i++) {
					arr[99 - i]--;
					arr[i]++;
				}
				
				sort(arr.begin(), arr.begin() + cntMIN);
				sort(arr.end() - cntMAX, arr.end());

			}
		}
		if (Pflag == 0) {
			sort(arr.begin(), arr.end());
			cout << "#" << idx << " " << arr[99] - arr[0] << endl;
			idx++;
		}
		arr.clear();
		caseNum--;
	}
}