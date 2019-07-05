#include <iostream>
using namespace std;

int main() {
	int num1;
	cin >> num1;

	while (num1 > 0) {
		int arr[101] = { 0 }, num2 = 0, result = 0, max = 0, tmp = 0;
		cin >> num2;

		for (int i = 1; i <= 1000; i++) {
			cin >> tmp;
			arr[tmp]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (arr[i] >= max) {
				max = arr[i];
				result = i;
			}
			arr[i] = 0;
		}
		cout << "#" << num2 << " " << result << endl;
		num1--;

	}

	return 0;
}