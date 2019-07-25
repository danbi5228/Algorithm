#include <iostream>
using namespace std;

int main(void) {
	int testNum, idx = 0;
	cin >> testNum;

	while (testNum > 0) {
		testNum--;

		int caseNum, a = 0, b = 0, c = 0, d = 0, e = 0;
		cin >> caseNum;

		while (caseNum != 1) {
			if (caseNum % 11 == 0) {
				caseNum /= 11;
				e++;
			}
			if (caseNum % 7 == 0) {
				caseNum /= 7;
				d++;
			}
			if (caseNum % 5 == 0) {
				caseNum /= 5;
				c++;
			}
			if (caseNum % 3 == 0) {
				caseNum /= 3;
				b++;
			}
			if (caseNum % 2 == 0) {
				caseNum /= 2;
				a++;
			}
		}
		idx++;
		cout << "#" << idx << " " << a <<" "<< b << " " << c << " " << d << " " << e << endl;
	}
}