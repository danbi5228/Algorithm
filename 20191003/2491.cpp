#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int caseNum;
	int increase_ = 1;
	int decrease_ = 1;
	int result = 1;

	bool isBigger = 1;
	int arr[100001] = { 0, };

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++)
		cin >> arr[i];

	for (int i = 1; i < caseNum; i++) {
		if (arr[i - 1] == arr[i]) {
			increase_++;
			decrease_++;
		}
		else if (arr[i - 1] > arr[i]) {
			increase_++;
			result = max(decrease_, result);
			decrease_ = 1;
		}
		else {
			decrease_++;
			result = max(increase_, result);
			increase_ = 1;
		}
	}
	int temp = max(increase_, decrease_);
	result = max(temp, result);
	cout << result << endl;
}





//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(void) {
//	int caseNum, result = 0;
//	int isBigger = 3;
//	int arr[100001] = { 0, };
//	vector <int> v;
//
//	cin >> caseNum;
//
//	for (int i = 0; i < caseNum; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < caseNum; i++) {
//		if (arr[i] == arr[i + 1]) {
//			isBigger = 3;
//			result++;
//		}
//		else if (arr[i] < arr[i + 1]) {
//			if (isBigger == 0) {
//				isBigger = 1;
//				v.push_back(result);
//				result = 1;
//			}
//			else {
//				result++;
//			}
//		}
//		else {
//			if (isBigger == 1 && isBigger == 3) {
//				isBigger = 0;
//				v.push_back(result);
//				result = 1;
//			}
//			else {
//				result++;
//			}
//		}
//	}
//	v.push_back(result);
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i];
//	}
//	cout << "-----------" << endl;
//	cout << v[v.size() - 1] << endl;
//}