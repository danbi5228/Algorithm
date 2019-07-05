#include <iostream>
using namespace std;

bool flag = 0;
int max_num = 0;
int tmp = 0;
int max_index = 0;
int N = 0;

int incresArr[1001] = { 0, };
int decresArr[1001] = { 0, };
int inputArr[1001] = { 0, };

int setting(int index) {
	max_num = 0;
	if (flag == 0) { // increase
		for (int i = 0; i < index; i++) {
			if (incresArr[i] > max_num && inputArr[i] <= inputArr[index]) {
				max_num = incresArr[i];
			}
		}
		return  max_num + 1;
	}
	else { //decrease
		for (int i = N-1; i > index; i--) {
			if (decresArr[i] > max_num && inputArr[i] <= inputArr[index]) {
				max_num = decresArr[i];
			}
		}
		return  max_num + 1;
	}
}

int main() {

	int tmp = 1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> inputArr[i];
	}

	incresArr[0] = 1;
	decresArr[N-1] = 1;

	for (int i = 1; i < N; i++) {
		if (inputArr[i - 1] == inputArr[i]) {
			incresArr[i] = incresArr[i - 1];
		}
		else {
			incresArr[i] = setting(i);
		}
		if (incresArr[i] > tmp) {
			max_index = i;
			tmp = incresArr[i];
		}
	}

	flag = 1;
	
	for (int i = N-2; i >= 0; i--) {
		if (inputArr[i + 1] == inputArr[i]) {
			decresArr[i] = decresArr[i + 1];
		}
		else {
			decresArr[i] = setting(i);
		}
	}
	//cout << endl;
	//
	//cout << "-----------------------" << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << incresArr[i] << " ";
	//}


	//cout << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << decresArr[i] << " ";
	//}
	//cout << endl;

	//cout << tmp << endl;
	//cout << max_index<<endl;

	cout << incresArr[max_index] + decresArr[max_index] - 1 << endl;
	


	return 0;
}