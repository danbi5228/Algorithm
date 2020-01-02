// 처음엔... 자연수만 받는줄... 예시만보고...ㅋㅋㅋㅋㅋㅋ
// 정수로 보고 단순히 for문 두번 돌면서 확인하고 break 하는 작업은 시간초과가 나옴
// 이진탐색 문제로 보고 map stl 사용
#include "pch.h"
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
	int num1=0, num2=0, tmp=0;
	map <int, int> m;

	scanf_s("%d", &num1);
	for (int i = 0; i < num1; i++) {
		scanf_s("%d", &tmp);
		m.insert(make_pair(tmp, 1));
	}

	scanf_s("%d", &num2);
	for (int i = 0; i < num2; i++) {
		scanf_s("%d", &tmp);
		bool flag = 0;
		map <int, int>::iterator iter;

		iter = m.find(tmp);
		if (iter != m.end()) {
			printf("1\n");
		}
		else printf("0\n");
	}
	return 0;
}