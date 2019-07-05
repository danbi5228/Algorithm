#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int minArray[1000000] = { 0, }; // 1까지 가는 최소의 값

int dp(int inputN) {
	int tmp = 0;

	if (inputN == 1) return 0;
	if (minArray[inputN] > 0) {
		return minArray[inputN];
	}
	else {
		if (inputN % 2 == 0) {
			if (inputN % 3 == 0) {
				tmp = min(dp(inputN / 2), dp(inputN / 3));
			}
			else tmp = min(dp(inputN / 2), dp(inputN - 1));
		}
		else {
			if (inputN % 3 == 0) {
				tmp = min(dp(inputN / 3), dp(inputN - 1));
			}
			else tmp = dp(inputN - 1);
		}

		minArray[inputN] = tmp + 1;

		//if (inputN % 3 == 0) {
		//	minArray[inputN] = min(dp(inputN / 3), dp(inputN - 1));
		//}
		//minArray[inputN] = min(dp(inputN - 1),minArray[inputN]) + 1;

	}
	return minArray[inputN];
}
int main() {
	
	int inNum = 0;
	cin >> inNum;

	minArray[1] = 0;
	minArray[2] = 1;
	minArray[3] = 1;

	cout<<dp(inNum);

	return 0;
}


/*if (inputN % 2 == 0) {
if (inputN % 3 == 0) {
tmp = min(dp(inputN/2), dp(inputN/3));
tmp = min(tmp, dp(inputN - 1));
minArray[inputN] = tmp + 1;
}
else if(inputN % 3 >0){
tmp = min(dp(inputN/2), dp(inputN - 1));
minArray[inputN] = tmp + 1;
}
}
else if (inputN % 2 != 0 && inputN % 3 == 0) {
tmp = min(dp(inputN/3), dp(inputN - 1));
minArray[inputN] = tmp + 1;
}
else if(inputN % 2 && inputN % 3!= 0){
tmp = dp(inputN - 1);
minArray[inputN] = tmp + 1;
}*/