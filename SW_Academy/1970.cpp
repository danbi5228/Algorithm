#include <iostream>
using namespace std;

int main(void) {
	int caseNum, idx=1, N, tmp;

	cin >> caseNum;

	while (caseNum > 0) {
		cin >> N;
		cout << "#" << idx <<endl;

		int num4 = 4;
		int maxNum = 50000;
		while (num4 > 0) {
			cout << N / maxNum << " ";
			N %= maxNum;
			maxNum /= 5;

			cout << N / maxNum << " ";
			N %= maxNum;
			maxNum /= 2;
			num4--;

		}
		cout << endl;

		caseNum--;
		idx++;
	}
}