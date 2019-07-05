#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

int N = 0, B = 0, Num_min = 0, Num_find = 0;
double C = 0, tmp1 = 0, tmp2 = 0;
long long A[1000001] = { 0, };

//vector <int> tmpV;
vector <int> result;

void find_min(int num_A) {

	if (num_A - B > 0) {
		Num_min++;
		num_A -= B;

		tmp1 = num_A / C;
		tmp2 = num_A % int(C);

		if (tmp2 == 0) {
			Num_min += tmp1;
			result.push_back(Num_min);
		}
		else if (tmp1 < 1) {
			Num_min++;
			result.push_back(Num_min);
		}
		else {
			Num_min += ceil(tmp1);
			result.push_back(Num_min);
		}
	}
	else {
		Num_min++;
		result.push_back(Num_min);
	}

	Num_min = 0;
	tmp1 = 0;
	tmp2 = 0;

}
int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	
	for (int i = 0; i < N; i++) {
		find_min(A[i]);
		Num_find += result[i];
		//cout << "-------------" << endl;
		//cout << result[i] << endl;
	}

	cout << Num_find;

	return 0;
}