#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int A, B, C;
bool AB[201][201] = { 0, };
bool result[201] = { 0, };

struct Bottles { // 클래스로는 어떻게 하지..?
	int a, b, c;
};

void bfs() {
	queue < Bottles > q;
	q.push({ 0, 0, C });

	while (!q.empty()) {
		Bottles cur = q.front();
		q.pop();

		if (AB[cur.a][cur.b] == 1)
			continue;
		AB[cur.a][cur.b] = 1;
		
		if (cur.a == 0 and result[cur.c] == 0)
			result[cur.c] = 1;

		//c->a
		if (cur.a + cur.c > A)
			q.push({ A, cur.b, (cur.c + cur.a) - A });
		else
			q.push({ cur.c + cur.a, cur.b, 0 });
			
		//c->b
		if (cur.b + cur.c > B)
			q.push({ cur.a, B, (cur.c + cur.b) - B});
		else
			q.push({ cur.a, cur.c + cur.b, 0});

		//a->b
		if (cur.a + cur.b > B)
			q.push({ (cur.a + cur.b) - B, B, cur.c });
		else
			q.push({ 0, cur.b + cur.a, cur.c });

		//a->c
		if (cur.a + cur.c > C)
			q.push({ (cur.a+cur.c) - C, cur.b, C});
		else
			q.push({ 0, cur.b, cur.a + cur.c });

		//b->a
		if (cur.a + cur.b > A)
			q.push({ A, (cur.b + cur.a) - A, cur.c });
		else
			q.push({ cur.a + cur.b, 0, cur.c });

		//b->c
		if (cur.b + cur.c > C)
			q.push({ cur.a, ( cur.b + cur.c ) - C, C });
		else
			q.push({ cur.a, 0, cur.b + cur.c });
	}
	// if find(v.begin(), v.end(), num) == v.end() then push
}
int main(void) {
	cin >> A >> B >> C;
	bfs();

	for (int i = 0; i < 201; i++) {
		if(result[i])
			cout << i << " ";
	}
	cout << endl;

}