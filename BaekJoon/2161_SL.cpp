#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue <int> arr;

	for (int i = 0; i < N; i++) {
		arr.push(i+1);
	}
	for (int i = 0; i < N; i++) {
		cout << arr.front() << " ";
		arr.pop();

		arr.push(arr.front());
		arr.pop();
		
	}
	return 0;
}

// �տ��� ��������, �ڿ��� �߰��Ǵϱ� -> queue �� ����!!!!!!!!!!�Ϳ�