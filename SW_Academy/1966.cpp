#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int testNum, idx = 0;
	cin >> testNum;
	while (testNum > 0) {
		int caseNum, tmp;
		vector<int> arr;

		testNum--;
		cin >> caseNum;

		for (int i = 0; i < caseNum; i++) {
			cin >> tmp;
			arr.push_back(tmp);
		}

		sort(arr.begin(), arr.end());

		idx++;
		cout << "#" << idx<<" ";
		for (int i = 0; i < caseNum; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}