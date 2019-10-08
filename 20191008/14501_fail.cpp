//// 재귀 , bottom up 방식을 이용하는 것이 좋다??

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> meeting_arr;

// main 함수 확인
// meeting_case 함수는 작성 중에 막힘 ㅜ_ㅜ
/*
이 메인함수의 for문의 경우, 다음 상담일자를 지목할 때
상담을 무조건 '하는' 경우만 선택한다.

예시)
10
5 10
5 9
5 8
5 7
5 6
5 10
5 9
5 8
5 7
5 6

에서 맨 처음 5 10에 상담을 하고 다음 5 6 에 무조건 상담을 하는 경우만 본다.
5 6에 상담을 하지 않고 다음 상담을 확인하는 작업이 없기 때문에
출력 결과 max 값이 20이 나와야하지만 10이 나오게 된다.
*/

//int meeting_case(int startday, vector <bool> choice) {
//	//a = O, b = X
//	int a = 0, b = 0;
//
//	for (int i = startday; i <= meeting_arr.size(); i++) {
//		// 선택 했을 때
//		if (i + meeting_arr[i].first <= meeting_arr.size()) {
//			a = meeting_case(i + meeting_arr[i].first, choice);
//		}
//		// 선택하지 않았을 때
//		if (i + 1 <= meeting_arr.size()) {
//			b = meeting_case(i + 1, choice);
//		}
//	}
//	return max(a, b);
//}

int main() {
	int dayNum;
	int tmp_day, tmp_profit;
	int result = 0;
	vector <bool> isChoice;
	cin >> dayNum;

	// meeting_arr<day, profit> . index 1부터.
	meeting_arr.push_back(make_pair(0, 0));

	for (int i = 1; i <= dayNum; i++) {
		cin >> tmp_day >> tmp_profit;
		meeting_arr.push_back(make_pair(tmp_day, tmp_profit));
		isChoice.push_back(0);
	}



	//for (int i = 1; i <= dayNum; i++) {
	//	int tmp_result = 0;
	//	if (i + meeting_arr[i].first <= dayNum) {
	//		tmp_result = meeting_arr[i].second;
	//	}
	//	else
	//		continue;
	//	if (i + meeting_arr[i].first < dayNum) {
	//		for (int j = i + meeting_arr[i].first; j <= dayNum;) {
	//			if (j == dayNum && meeting_arr[j].first == 1) {
	//				tmp_result += meeting_arr[j].second;
	//				break;
	//			}
	//			if (j + meeting_arr[j].first <= dayNum) {
	//				tmp_result += meeting_arr[j].second;
	//			}
	//			j += meeting_arr[j].first;
	//		}
	//	}
	//	result = max(result, tmp_result);
	//}

	cout << result << endl;
	return 0;
}