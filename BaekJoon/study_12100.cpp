#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//true 1 false 0
// 또 다른 방법 ; 전부 다 해보고 케이스에 맞는 것 중 최대값 return
//우선순위; 위, 오, 아래, 왼 (위 부터 시계방향)

vector < vector <int> > block;
int max_change = 5;
int tmp = 0;

bool isBlock(int a, int b,int block_size) {
	if (a < 0 || a >= block_size || b < 0 || b >= block_size) return 0;
	else return 1;
}

void upup(int b_size) {
	//위로 이동
	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (isBlock(i + 1, j, b_size)) {
				if (block[i][j] == 0) {
					block[i][j] = block[i + 1][j];
					block[i + 1][j] = 0;
					tmp++;
				}
				else if (block[i][j] == block[i + 1][j]) {
					block[i][j] += block[i + 1][j];
					block[i + 1][j] = 0;
					tmp++;
				}
				else if (block[i][j] == 0 && block[i + 1][j] != 0) {
					block[i][j] = block[i + 1][j];
					block[i + 1][j] = 0;
					tmp++;
				}

			}
		}
	}

}
void rightright(int b_size) {
	//오른쪽으로 이동
	for (int i = b_size-1; i >= 0 ; i--) {
		for (int j = b_size-1; j >= 0 ; j--) {
			if (isBlock(i, j-1, b_size)) {
				if (block[i][j] == 0) {
					block[i][j] = block[i][j - 1];
					block[i][j - 1] = 0;
					tmp++;
				}

				//더할 수 있는 경우
				else if (block[i][j] == block[i][j-1]) {
					block[i][j] += block[i][j-1];
					block[i][j-1] = 0;
					tmp++;
				}
				//빈 칸 채우기
				else if (block[i][j] == 0 && block[i][j-1] != 0) {
					block[i][j] = block[i][j-1];
					block[i][j - 1] = 0;
					tmp++;
				}
				
			}
			
		}
	}
}
void downdown(int b_size) {
	//아래로 이동
	for (int i = b_size-1; i >=0 ; i--) {
		for (int j = b_size-1; j >=0 ; j--) {
			if (isBlock(i-1, j, b_size)) {

				 if (block[i][j] == 0) {
					 block[i][j] = block[i - 1][j];
					 block[i - 1][j] = 0;
					 tmp++;
				}

				else if (block[i][j] == block[i-1][j]) {
					block[i][j] += block[i-1][j];
					block[i-1][j] = 0;
					tmp++;
				}
				else if (block[i][j] == 0 && block[i + 1][j] != 0) {
					block[i][j] = block[i-1][j];
					block[i-1][j] = 0;
					tmp++;
				}

			}
		}
	}

}


void leftleft(int b_size) {
	//왼쪽으로 이동
	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (isBlock(i, j + 1, b_size)) {

				if (block[i][j] == 0) {
					block[i][j] = block[i][j + 1];
					block[i][j + 1] = 0;
					tmp++;
				}

				else if (block[i][j] == block[i][j + 1]) {
					block[i][j] += block[i][j + 1];
					block[i][j + 1] = 0;
					tmp++;
				}
				else if (block[i][j] == 0 && block[i][j + 1] != 0) {
					block[i][j] = block[i][j + 1];
					block[i][j + 1] = 0;
					tmp++;
				}
			}
		}
	}

}


int main() {
	int size = 0;

	int max_element = 0;

	cin >> size;
	for (int i = 0; i < size; i++) {
		vector <int> element(size);
		block.push_back(element);
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> block[i][j];
		}
	}

	int i = 0;
	int j = 0;

	while (max_change > 0) {

		if (!isBlock(i, j, size)) break;

		if (isBlock(i - 1, j, size)) {
			max_change--;
			upup(size);
			if (tmp == 0) max_change++;
			tmp = 0;
		}
		if (isBlock(i, j + 1, size)) {
			max_change--;
			rightright(size);
			if (tmp == 0) max_change++;
			tmp = 0;
		}
		if (isBlock(i + 1, j, size)) {
			max_change--;
			downdown(size);
			if (tmp == 0) max_change++;
			tmp = 0;
		}
		if (isBlock(i, j - 1,size)) {
			max_change--;
			leftleft(size);
			if (tmp == 0) max_change++;
			tmp = 0;
		}

		if (max_change == 5) {
			max_change = 0;
			break;
		}
		i++;
		j++;
		
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (max_element <= block[i][j]) {
				max_element = block[i][j];
			}
			//cout<< block[i][j]<<" ";
		}
		//cout << endl;
	}

	cout << max_element << endl;;



	return 0;
}

