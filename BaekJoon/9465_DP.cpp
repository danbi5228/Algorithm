#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int case_Arr[100001] = { 0, };
int sticker_Arr[2][100001];
int max_sticker[2][100001];

int main() {
	int case_num = 0,tmp = 0;
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		cin >> case_Arr[i];
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < case_Arr[i]; j++) {
				cin >> sticker_Arr[k][j];
			}
		}


		max_sticker[0][0] = sticker_Arr[0][0];
		max_sticker[1][0] = sticker_Arr[1][0];

		if (case_Arr[i] >= 2) {
			max_sticker[0][1] = sticker_Arr[0][1] + max_sticker[1][0];
			max_sticker[1][1] = sticker_Arr[1][1] + max_sticker[0][0];


			for (int l = 0; l < 2; l++) {
				if (l == 0) {
					for (int m = 2; m < case_Arr[i]; m++) {
						max_sticker[l][m] = max(max(max_sticker[l][m - 2], max_sticker[l + 1][m - 2]), max_sticker[l + 1][m - 1]);
						max_sticker[l][m] = max_sticker[l][m] + sticker_Arr[l][m];
					}
				}
				else {
					for (int m = 2; m < case_Arr[i]; m++) {
						max_sticker[l][m] = max(max(max_sticker[l][m - 2], max_sticker[l - 1][m - 2]), max_sticker[l - 1][m - 1]);
						max_sticker[l][m] = max_sticker[l][m] + sticker_Arr[l][m];
					}
				}
			}
		}

	}
	for (int l = 0; l < 2; l++) {
		for (int m = 0; m < case_Arr[0]; m++) {
			cout << max_sticker[l][m] << " ";
		}
		cout << endl;
	}

	return 0;
}