/*
프로그래머스 - 문자열 내 마음대로 정렬하기
*/

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<pair<char, int>> tmp;
	vector<string> answer;
	sort(strings.begin(), strings.end());

	for (int i = 0; i < strings.size(); i++) {
		tmp.push_back(make_pair(strings[i][n], i));
	}

	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		answer.push_back(strings[tmp[i].second]);
	}
	return answer;
}


//python
//def solution(strings, n) :
//	strings = sorted(strings)
//	strings = sorted(strings, key = lambda word : word[n])
//	return strings