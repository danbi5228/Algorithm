#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> schedule;

int func(int day, vector<bool> consults, int value) {
	if (day > N) {
		return value;
	}

	int possible = 0, impossible = 0;

	impossible = func(day + 1, consults, value);
	if (!consults[day] && day + schedule[0][day] - 1 <= N) {
		for (int num = 0; num < schedule[0][day]; num++)
			consults[day + num] = true;
		possible = func(day + 1, consults, value + schedule[1][day]);

	}

	return max(possible, impossible);
}

int main() {
	cin >> N;

	schedule = vector<vector<int>>(2, vector<int>(N + 1));
	vector<bool> consults(N + 1, false);

	for (int idx = 1; idx <= N; idx++)
		cin >> schedule[0][idx] >> schedule[1][idx];

	// 첫번째 날 부터, value는 0
	cout << func(1, consults, 0) << endl;


	return 0;
}