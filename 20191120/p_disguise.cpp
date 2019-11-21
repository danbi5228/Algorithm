#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	vector <string> category;
	// <key, value>
	map <string, int> closet;
	map <string, int>::iterator iter;

	//insert
	for (int i = 0; i < clothes.size(); i++) {
		//cout << clothes[i][1] << clothes[i][0] << endl;
	
		iter = closet.find(clothes[i][1]);
		if ( iter == closet.end()) {
			closet.insert(make_pair(clothes[i][1], 1));

			// if (find(category.begin(), category.end(), 
		 //                  clothes[i][1]) != category.end()){
		 //    category.push_back(clothes[i][1]);
			//}	

			int conf = 1;
			for (int j = 0; j < category.size(); j++) {
				if (category[j] == clothes[i][1]) {
					conf = 3;
					break;
				}
			}
			if (conf != 3) {
				category.push_back(clothes[i][1]);
			}
		}
		else {
			iter->second += 1;
		}
		answer += 1;
	}
	//cout << closet.size() << endl;
	//cout << answer << endl;

	if (category.size() != 1) {
		int tmp_answer = 1;
		for (int i = 0; i < category.size(); i++) {
			iter = closet.find(category[i]);
			tmp_answer *= iter->second;
		}
		answer += tmp_answer;
	}

	return answer;
}
