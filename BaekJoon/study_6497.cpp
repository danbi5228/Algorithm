#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long M = 0, N = 0;
long long x = 0, y = 0;
long long z = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0, sum_z = 0, min_z = 0;
long long result = 0;
int parent[200001] = { 0, };

int k1 = 0, k2 = 0;

class Edge {
public:
	long long node[2];
	long long distance;

	Edge(int a, int b, int c) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = c;
	}

	bool operator < (Edge &edge) {
		return this->distance < edge.distance;
	}
};

int GetParent(int node) {
	if (parent[node] == node) {
		return node;	
	}
	return GetParent(parent[node]);
}

bool isSameP(int x_s, int y_s) {
	x_s = GetParent(x_s);
	y_s = GetParent(y_s);

	if (x_s == y_s) return true;
	else return false;
}

void UnionParent(int x, int y) {
	x = GetParent(x);
	y = GetParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int main() {

	while (1) {
		vector <Edge> Vertex;
		cin >> M >> N;
		if (M == 0 && N == 0) {
			cout << sum_z - min_z << endl;
			return 0;
		}
		else {
			if (sum_z != 0 && min_z != 0) {
				cout << sum_z - min_z << endl;
			}
			sum_z = 0;
			min_z = 0;
			Vertex.clear();

			for (int i = 0; i < N; i++) {
				cin >> tmp1 >> tmp2 >> tmp3;
				Vertex.push_back(Edge(tmp1, tmp2, tmp3));
				parent[i] = i;
				sum_z += tmp3;
			}

			sort(Vertex.begin(), Vertex.end());

			for (int i = 0; i < Vertex.size(); i++) {
				if (!isSameP(Vertex[i].node[0], Vertex[i].node[1])) {
					min_z += Vertex[i].distance;
					UnionParent(Vertex[i].node[0], Vertex[i].node[1]);
				}
			}

		}
	}
}