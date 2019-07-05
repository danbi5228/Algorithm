//앞에서 부터 max 값 찾기
//main 안은 stack 공간이라 크기가 작음ㅜㅜ. 메인 밖은 힙 영역이라 더 넓음.
#include <iostream>
using namespace std;

int arr[1000000] = { 0, };
long long profit, max_value, inputNum, testCase;
int main(void) {
	int index = 1;
	cin >> testCase;

	while (testCase > 0) {
		max_value = 0;
		profit = 0;
		cin >> inputNum;
		for (int i = 0; i < inputNum; i++) {
			cin >> arr[i];
		}
		while (inputNum > 0) {
			if (arr[inputNum - 1] > max_value) max_value = arr[inputNum - 1];
			else if (max_value > arr[inputNum - 1]) profit = profit - arr[inputNum - 1] + max_value;
			inputNum--;
		}

		cout << "#" << index << " " << profit << endl;

		index++;
		testCase--;
	}
}



//시간초과 ㅜㅜ
//#include <iostream>
//using namespace std;
//
//int arr[1000000] = { 0 };
//bool findMax = false;
//int main(void) {
//	int testNum, resultNum = 1, profitNum = 0;
//	cin >> testNum;
//	while (testNum > 0) {
//		int dayNum = 0;
//		cin >> dayNum;
//
//		for (int i = 0; i < dayNum; i++) {
//			cin >> arr[i];
//		}
//		
//		for (int i = 0; i < dayNum-1; i++) {
//			int max = 0;
//			for (int j = i+1; j < dayNum; j++) {
//				if (arr[i] < arr[j] && max < arr[j]) {
//					max = arr[j];
//					findMax = true;
//				}
//			}
//			if (findMax) {
//				profitNum = profitNum - arr[i] + max;
//				findMax = false;
//			}
//		}
//
//		cout << "#" << resultNum << " " << profitNum << endl;
//
//		testNum--;
//		resultNum++;
//		profitNum = 0;
//	
//	}
//}