// 坦製殖... 切尻呪幻 閤澗匝... 森獣幻左壱...せせせせせせ
// 舛呪稽 左壱 舘授備 for庚 砧腰 宜檎辞 溌昔馬壱 break 馬澗 拙穣精 獣娃段引亜 蟹身
// 戚遭貼事 庚薦稽 左壱 map stl 紫遂
#include "pch.h"
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
	int num1=0, num2=0, tmp=0;
	map <int, int> m;

	scanf_s("%d", &num1);
	for (int i = 0; i < num1; i++) {
		scanf_s("%d", &tmp);
		m.insert(make_pair(tmp, 1));
	}

	scanf_s("%d", &num2);
	for (int i = 0; i < num2; i++) {
		scanf_s("%d", &tmp);
		bool flag = 0;
		map <int, int>::iterator iter;

		iter = m.find(tmp);
		if (iter != m.end()) {
			printf("1\n");
		}
		else printf("0\n");
	}
	return 0;
}