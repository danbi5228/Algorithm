/*
���α׷��ӽ� - ���ڿ� ������������ ��ġ�ϱ�
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	sort(s.begin(), s.end(), greater<char>());
	return s;
}

//python
//def solution(s) :
//	s = sorted(s, reverse = True)
//	s = ''.join(s)
//	return s