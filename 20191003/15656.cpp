#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
vector <int> v;
vector <int> result;

void print_n(int n, int m) {
	if (result.size() == m) {
		for (int k = 0; k < result.size(); k++) {
			printf("%d ", result[k]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		result.push_back(v[i]);
		print_n(n, m);
		result.pop_back();
	}
}

int main(void) {
	int N, M, tmp_input;
	scanf_s("%d %d", &N, &M);
	

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &tmp_input);
		v.push_back(tmp_input);
	}
	sort(v.begin(), v.end());
	print_n(N, M);
}