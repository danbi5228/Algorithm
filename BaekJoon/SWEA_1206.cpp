#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int caseNum = 0;
	int buildNum = 0;
	int height[1001] = { 0, };
	int result[10] = { 0, };
	int sum = 0;
	int buildPt = 2;
	int tmpMax = 0;
	int flag = 0;
	int caseTmp = 0;

	while (caseTmp < 10) {
		flag = 0;
		tmpMax = 0;
		sum = 0;
		buildPt = 0;
		cin >> buildNum;
		for (int i = 0; i < buildNum; i++) {
			height[i] = 0;
		}


		for (int i = 0; i < buildNum; i++) {
			cin >> height[i];
		}

		while (buildNum >= buildPt) {
			tmpMax = 0;
			flag = 0;
			//if (buildPt == buildNum - 3) { // 맨 마지막 빌딩일 경우
			//}

			for (int i = buildPt - 2; i < buildPt + 3; i++) {
				if (buildPt == i) continue;
				if (height[i] < height[buildPt]) {
					tmpMax = max(tmpMax, height[i]);
				}
				else if (height[i] == height[buildPt]) {
					buildPt += 1;
					flag = 1;
					break;
				}
				else {
					buildPt += 1;
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				sum += (height[buildPt] - tmpMax);
				buildPt += 3;
			}
		}
		result[caseTmp] = sum;
		caseTmp++;
		sum = 0;
	}

	for (int j = 0; j < 10; j++) {
		cout << "#" << j+1 << " " << result[j] << endl;
	}
	return 0;
}