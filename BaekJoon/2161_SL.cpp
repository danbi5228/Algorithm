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

// 앞에서 버려지고, 뒤에서 추가되니까 -> queue 를 쓰자!!!!!!!!!!와우