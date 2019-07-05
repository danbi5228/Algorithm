#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int cnt = 0, build;
	vector <int> result;
	int result_num = 0;
	cin >> cnt;
	int arr[1000001] = { 0, };

	for (int i = 0; i<cnt; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i<cnt; i++) {
		for (int j = i + 1; j<cnt; j++) {
			if (i > j) result_num++;
			else if (i == j && i<j) {
				result_num++;
				result.push_back(result_num);
				result_num = 0;
				break;
			}
		}
	}
	int max = 0;

	for (int z = 0; z < result.size(); z++) {
		if (result[z] > max) {
			max = result[z];
		}
	}
	cout << max << endl;

	return 0;
}