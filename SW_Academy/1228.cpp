// 실제로는 리스트로 푸는 게 더 낫지만 몰라 배열로 푼다.
// vector insert 는 자동으로 그 뒤의 원소들을 뒤로 쭉죽 밀어준다!

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int num10 = 10, idx = 0;
	while (num10--) {
		int origin_num, tmp;
		char tmp_c;
		cin >> origin_num;
		vector <int> arr;

		for (int i = 0; i < origin_num; i++) {
			cin >> tmp;
			arr.push_back(tmp);
		}

		int order_num;
		int input_p = 0, input_n = 0;// 삽입하려는 위치(+1 해줘야함), 삽입하려는 원소 개수
		cin >> order_num;

		for (int i = 0; i < order_num; i++) {
			cin >> tmp_c >> input_p >> input_n;

			for (int j = 0; j < input_n; j++) {
				cin >> tmp;
				arr.insert(arr.begin() + input_p + j, tmp);
			}
			
		}

		idx++;
		cout << "#" << idx << " ";
		for (int i = 0; i < 10; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}