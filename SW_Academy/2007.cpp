#include <iostream>
#include <vector>
#include <string> // string ; char 형 vector 를 클래스화 한 것. 따라서 vector처럼 사용 가능
using namespace std;

int main(void) {
	int testCase,indexNum = 1;
	cin >> testCase;

	while (testCase > 0) {
		vector <char> result;
		string inputValue;
		cin >> inputValue;

		int inputP = 1, resultP = 0; // inputValue index , result index;
		bool isSame = false;
		bool isAdd = false;
		result.push_back(inputValue[0]);

		for (int i = inputP; i < inputValue.size(); i++) {
			for (int j = resultP; j < result.size(); j++) {
				if (isAdd) {
					isAdd = false;
					break;
				}
				if (result[j] != inputValue[i]) {
					result.push_back(inputValue[i]);
					break;
				}
				else {
					for (int x = 0; x < result.size(); x++) {
						if (result[x] == inputValue[i + x]) {
							isSame = true;
						}
						else {
							result.push_back(inputValue[i]);
							isSame = false;
							isAdd = true;
							break;
						}
					}
				}
				if (isSame) break;
			}
			if (isSame) break;
		}

		//for (int i = 0; i < result.size(); i++) cout << result[i];
		//cout << endl;

		cout << "#" << indexNum << " " << result.size()<<endl;
		testCase--;
		indexNum++;
	}
}