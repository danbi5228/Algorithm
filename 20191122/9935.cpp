// �Ϻ������� ����� : map �� �� ���� �� �� ó�� ��� �ܿ� �� ������ ����� ��¡?? �װ� ���� ����Ʈ�� �װǰ�??
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ����
// pop back !!
int main() {
	string input;
	string bomb;
	vector <char> input_string;
	int bomb_size = 0;
	cin >> input;
	cin >> bomb;
	bomb_size = bomb.size();
	
	for (int i = 0; i < input.size(); i++) {
		input_string.push_back(input[i]);
		if (input[i] == bomb[bomb_size - 1]) {
			// ��ź���� ���� ���� ���� ũ���� i�� bomb�� �� ������ ���
			// ��ź ���� ���� ���ٴ� input_string ũ�Ⱑ ũ����
			if (input_string.size() > bomb_size-1) {
				int bomb_point = 0;
				bool isBomb = true;
				for (int j = input_string.size() - bomb_size; j < input_string.size(); j++) {
					if (input_string[j] == bomb[bomb_point]) {
						bomb_point += 1;
						continue;
					}

					isBomb = false;
					break;
				}

				if (isBomb == true) {
					for (int k = 0; k < bomb_size; k++) {
						input_string.pop_back();
					}
				}
			}
		}
	}
	

	if (input_string.size() == 0) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = 0; i < input_string.size(); i++) {
			cout << input_string[i];
		}
		cout << endl;
	}
	return 0;
}




// �ð��ʰ� - 47%
//int main() {
//	string input;
//	string bomb;
//	int bomb_size = 0;
//	cin >> input;
//	cin >> bomb;
//	bomb_size = bomb.size();
//	string::size_type n;
//	while (1) {
//		vector <int> n_num;
//		int erase_size = 0;
//		n = input.find(bomb);
//		if (n == string::npos) {
//			break;
//		}
//
//		while (n != string::npos) {
//			n_num.push_back(n);
//			n = input.find(bomb, n+1);
//		}
//		
//		
//		for (int i = 0; i < n_num.size(); i++) {
//			input.erase(n_num[i]-erase_size, bomb_size);
//			erase_size += bomb_size;
//		}
//		
//	}
//
//	if (input.size() == 0) {
//		cout << "FRULA" << endl;
//	}
//	else {
//		cout << input << endl;
//	}
//	return 0;
//}



// �ð��ʰ� - 12%
//int main() {
//	string input;
//	string bomb;
//	cin >> input;
//	cin >> bomb;
//
//	string::size_type n;
//	while (1) {
//		n = input.find(bomb);
//
//		if (n == string::npos) {
//			break;
//		}
//		else {
//			input.erase(n, bomb.size());
//		}
//	}
//	
//	if (input.size() == 0) {
//		cout << "FRULA" << endl;
//	}
//	else {
//		cout << input << endl;
//	}
//	return 0;
//}