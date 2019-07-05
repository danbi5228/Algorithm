
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Street {
public:
	int begin, end, distance;

	Street() {}
	Street(int begin, int end, unsigned int distance) {
		this->begin = begin;
		this->end = end;
		this->distance = distance;
	}
};

bool operator<(const Street & a, const Street & b) {
	return a.distance > b.distance;
}

int house, street;
int visitCount;
unsigned int wholeDistance, minDistance;

priority_queue<Street> pq;
vector<int> parent;

int find(int x) {
	if (x == parent[x])
		return x;

	parent[x] = find(parent[x]);

	return parent[x];
}

void merge(int x, int y, int distance) {
	int parentX = find(x);
	int parentY = find(y);

	if (parentX == parentY)
		return;

	parent[parentX] = min(parentX, parentY);
	parent[parentY] = min(parentX, parentY);

	minDistance += distance;
	visitCount++;
}

int main()
{
	std::ios::sync_with_stdio(false);
	while (true) {
		cin >> house >> street;

		if (house == 0 && street == 0) {
			break;
		}

		int x, y, z;
		wholeDistance = minDistance = visitCount = 0;
		parent = vector<int>(house);

		for (int i = 0; i < house; i++) {
			//set house's parent
			parent[i] = i;
		}

		for (int i = 0; i < street; i++) {
			cin >> x >> y >> z;

			// set Street
			Street tmp(x, y, z);
			pq.push(tmp);


			wholeDistance += z;
		}

		while (visitCount != house - 1) {
			Street top = pq.top();
			pq.pop();

			merge(top.begin, top.end, top.distance);
		}

		cout << wholeDistance - minDistance << endl;
	}


	return 0;
}