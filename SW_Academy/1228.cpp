// �����δ� ����Ʈ�� Ǫ�� �� �� ������ ���� �迭�� Ǭ��.
// vector insert �� �ڵ����� �� ���� ���ҵ��� �ڷ� ���� �о��ش�!

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
		int input_p = 0, input_n = 0;// �����Ϸ��� ��ġ(+1 �������), �����Ϸ��� ���� ����
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