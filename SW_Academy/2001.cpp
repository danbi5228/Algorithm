#include <iostream>
using namespace std;

int main(void) {
	int caseN,idx = 0;
	cin >> caseN;

	while (caseN > 0) {
		int M, N, result=0, arr[15][15] = { 0 };
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i <= N-M; i++) {
			for (int j = 0; j <= N-M; j++) {
				int tmp = 0;

				for (int z = 0; z < M; z++) {
					for (int k = 0; k < M; k++) {
						tmp += arr[i + z][j + k];
						//cout << arr[i + z][j + k] << endl;
					}
				}

				if (tmp > result) result = tmp;
			}
		}

		idx++;
		cout << "#" << idx << " " << result << endl;
		caseN--;
	}
}