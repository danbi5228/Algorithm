#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int caseN, idx = 1;
	cin >> caseN;

	while (caseN > 0) {
		string input;
		int flag = 1;

		cin >> input;
		

			int amount = input.size() / 2;
			for (int i = 0; i < amount; i++) {
				if (input[i] != input[input.size() - 1 - i]) flag = 0;
			}


		cout << "#" << idx << " " << flag << endl;
		idx++;
		caseN--;
	}
}