// ó����... �ڿ����� �޴���... ���ø�����...������������
// ������ ���� �ܼ��� for�� �ι� ���鼭 Ȯ���ϰ� break �ϴ� �۾��� �ð��ʰ��� ����
// ����Ž�� ������ ���� map stl ���
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