#include <iostream>
using namespace std;

int main() {
	int M = 0, x = 0, y = 0, tmp = 0, flag = 0;
	int map[3] = { 1,2,3 };
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		flag = 0;

		for (int t = 0; t < 3; t++) {
			if (map[t] == x) {
				for (int t2 = 0; t2 < 3; t2++) {
					if (map[t2] == y && t2 != t) {
						map[t] = y;
						map[t2] = x;
						flag = 1;
					}
				}
			}

			if (flag == 1) break;
		}
	}

	cout << map[0];
	return 0;
}

// �׳� �� ��ġ�� �����صΰ� �� ��ġ���� �ƴ����� Ȯ��...
// ball == x || ball == y ����... ball ��ġ�� x�� ball �� y�� �ٲ��ְ�... �ݴ�� x�� �ٲ��ְ�..
// �Ѵ� �ƴϸ� ����... ���ϵ縻�� ����...��