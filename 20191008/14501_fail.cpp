//// ��� , bottom up ����� �̿��ϴ� ���� ����??

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> meeting_arr;

// main �Լ� Ȯ��
// meeting_case �Լ��� �ۼ� �߿� ���� ��_��
/*
�� �����Լ��� for���� ���, ���� ������ڸ� ������ ��
����� ������ '�ϴ�' ��츸 �����Ѵ�.

����)
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

���� �� ó�� 5 10�� ����� �ϰ� ���� 5 6 �� ������ ����� �ϴ� ��츸 ����.
5 6�� ����� ���� �ʰ� ���� ����� Ȯ���ϴ� �۾��� ���� ������
��� ��� max ���� 20�� ���;������� 10�� ������ �ȴ�.
*/

//int meeting_case(int startday, vector <bool> choice) {
//	//a = O, b = X
//	int a = 0, b = 0;
//
//	for (int i = startday; i <= meeting_arr.size(); i++) {
//		// ���� ���� ��
//		if (i + meeting_arr[i].first <= meeting_arr.size()) {
//			a = meeting_case(i + meeting_arr[i].first, choice);
//		}
//		// �������� �ʾ��� ��
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

	// meeting_arr<day, profit> . index 1����.
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