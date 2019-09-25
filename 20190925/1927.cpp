#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main(void) {
	int caseNum;
	scanf_s("%d", &caseNum);
	priority_queue<int, vector<int>, greater<int>> pq;

	while (caseNum--) {
		int inputNum;
		scanf_s("%d", &inputNum);

		if (inputNum == 0) {
			if (pq.size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(inputNum);
		}
	}
}