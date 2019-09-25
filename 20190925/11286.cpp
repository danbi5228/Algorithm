#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

class AbsHeap {
public:
	bool operator()(int a, int b) {
		// ���밪 ��
		if (abs(a) > abs(b)){
			return true;
		}
		// ��� ���� ��
		else if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return false;
		}
	}
};

int main() {
	int caseNum;
	cin >> caseNum;
	// priority_queue <�ڷ���, vector<�ڷ���>, �� class/struct> pq_name
	priority_queue<int, vector<int>, AbsHeap> pq;


	while (caseNum--) {
		int inputNum;
		cin >> inputNum;

		if (inputNum == 0) {
			if (pq.size() == 0) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(inputNum);
		}
	}
	return 0;
}
