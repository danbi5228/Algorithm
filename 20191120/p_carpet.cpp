#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
	vector<pair<int, int>> divisor;
	int all = brown + red;

	for (int i = 2; i*i <= all; i++) {
		if (all % i == 0) {
			divisor.push_back(make_pair(all/i, i));
		}
	}

	for (int i = 0; i < divisor.size(); i++) {
		int perimeter = (divisor[i].first * 2) + ((divisor[i].second - 2) * 2);
		if (perimeter == brown) {
			answer.push_back(divisor[i].first);
			answer.push_back(divisor[i].second);
			break;
		}
	}

	return answer;
}