#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int block[21][21] = { 0, };
int tmp_stack1[11] = { 0, }; // result ���� �� stack
int tmp_stack2[11] = { 0, };
vector <int> result;

int N = 0;
int count_num = 0; // N/2. �� ���� ������ ��� ��
int tmp_count_num = 0;
int team_energy = 0;
int tmp1 = 0;
int tmp2 = 0;

int min_num = 1e9;

int duplicate[100] = { 0, };

void team(int idx,int item) {

	tmp_stack1[idx] = item;
	idx++;

	if (idx == count_num) {
		for (int i = 0; i < idx; i++) {
			//result.push_back(tmp_stack1[i]);
			//cout << tmp_stack1[i];
			duplicate[tmp_stack1[i]] = 1;
		}
		//cout << endl;


		for (int i = 0; i < count_num; i++) { // �ٷ� �ش� ��� �ɷ�ġ ���
			for (int j = 0; j < count_num; j++) {
				if (i == j) continue;
				tmp1 += block[tmp_stack1[i]][tmp_stack1[j]];
				//cout << tmp_stack1[i]<<tmp_stack1[j]<<"/";
			}
		}
		//cout << endl;
		//cout << "tmp2------------" << endl;

		int tmp2_idx = 0;

		for (int i = 0; i < N; i++) { // �ߺ� �ƴ� �� ã��
			if (duplicate[i] != 1) {
				tmp_stack2[tmp2_idx] = i;
				//cout << tmp_stack2[tmp2_idx];
				tmp2_idx++;
			}
			else duplicate[i] = 0;
		}
		//cout << endl;

		for (int i = 0; i < count_num; i++) { // �ٷ� �ش� ��� �ɷ�ġ ���
			for (int j = 0; j < count_num; j++) {
				if (i == j) continue;
				tmp2 += block[tmp_stack2[i]][tmp_stack2[j]];
				//cout << tmp_stack2[i] << tmp_stack2[j] << "/";
			}
		}
		
		//cout << endl;
		min_num = min(min_num, int(fabs(tmp1 - tmp2)));

		tmp2_idx = 0;
		tmp1 = 0;
		tmp2 = 0;

		if (item < N-1) {
			//item = result.back();
			tmp_stack1[idx] = 0;
			//return;
		}
		else {
			idx--;
			item = tmp_stack1[idx];
		}
		//return;
	}

	for (int i = item+1; i < N; i++) {
		team(idx, i);
	}
}

int main() {
	int case_Num = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> block[i][j];
		}
	}
	
	//---------1. ����� �� �� ���� ���ϱ� (�ߺ��ǰ� �׳� ����... ������ 20��)
	for (int i = N; i > N / 2; i--) {
		case_Num = case_Num * i;
	}
	for (int i = (N / 2); i > 0; i--) {
		case_Num = case_Num / i;
	}

	//---------2. �� ����� �� ���ϱ�
	
	count_num = N / 2;
	for (int i = 0; i < N; i++) {
		team(0, i);
	}

	//--------3. ����� ���� ���� �ɷ�ġ ���

	int sibal = 0;
	for (int i = 0; i < result.size(); i++) {
		if (count_num == sibal) {
			cout << endl;
			sibal = 0;
			}
			cout << result[i] << " ";
			sibal++;
		}

		cout << min_num ;


		//for (int i = 0; i < result.size(); i++) {
		//	for (int j = i; j < count_num; j++) { // �� ���� ��� �� ��ŭ Ȯ��
		//		for (int x = 0; x < count_num; x++) {
		//			tmp1 = block[result[j]][result[j]]
		//		}
		//		block[result[j]][]
		//		for (int x = result[j+tmp_idx]; x < count_num; x++) {
		//			for (int y = result[j+tmp_idx]; y < count_num; y++) {

		//			}
		//		}

		//		duplicate[result[j]] = 1;
		//	}
		//	for (int z = 0; z < N; z++) {��
		//		if (duplicate[z] == 0) {
		//			tmp2 += 
		//		}
		//	}
		//}

		return 0;

	}
