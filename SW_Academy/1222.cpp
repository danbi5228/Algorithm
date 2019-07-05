#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


int main(void) {
	int caseNum = 10, idx = 0;

	while (caseNum > 0) {
		int length, flag = 0;
		char tmp;
		stack <char> S;
		stack <int> result_S;
		queue <char> Q; 
		vector <char> V;

		cin >> length;
	
		for (int i = 0; i < length; i++) {
			cin >> tmp;
			V.push_back(tmp);
		}

		for (int i = 0; i < length; i++) {
			if (V[i] != '+') Q.push(V[i]);
			else {
				if (S.size() == 0) S.push(V[i]);
				else {
					Q.push(S.top());
					S.pop();
					S.push(V[i]);
				}
			}
		}


		Q.push(S.top());
		S.pop();


		for (int i = 0; i < length; i++) {
			if (Q.front() != '+') {
				result_S.push((int)Q.front());
				Q.pop();
			}
			else {

				int result = 0;
				if (flag == 0) {
					flag = 1;
					result += (int)result_S.top() - 48;
					result_S.pop();


					result += (int)result_S.top() - 48;
					result_S.pop();
				}
				else {
					result += (int)result_S.top() - 48;
					result_S.pop();


					result += (int)result_S.top();
					result_S.pop();
				}

				result_S.push(result);

				Q.pop();
			}
				
		}

		idx++;
		cout << "#" << idx << " " << result_S.top() << endl;
		caseNum--;
	}
}