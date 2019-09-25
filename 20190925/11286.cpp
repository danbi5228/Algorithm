#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

class AbsHeap {
public:
	bool operator()(int a, int b) {
		// 절대값 비교
		if (abs(a) > abs(b)){
			return true;
		}
		// 양수 음수 비교
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
	// priority_queue <자료형, vector<자료형>, 비교 class/struct> pq_name
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
