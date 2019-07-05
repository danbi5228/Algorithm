#include <iostream>
using namespace std;

int main(void) {
	int caseNum, P, Q, R, S, W, feeA, feeB, idx = 1;
	cin >> caseNum;

	while (caseNum > 0) {
		cin >> P >> Q >> R >> S >> W;
		feeA = W*P;
		if (R >= W) feeB = Q;
		else feeB = Q + (W - R)*S;

		if (feeA > feeB) cout << "#" << idx << " " << feeB << endl;
		else cout << "#" << idx << " " << feeA << endl;

		caseNum--;
		idx++;
	}
}