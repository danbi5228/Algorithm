#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V = 0, E = 0; // Vertex, Edge;
int tmp1 = 0, tmp2 = 0, tmp3 = 0;
int parent[1001] = { 0, };
int sum = 0;
class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int dis) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = dis;
	}

	bool operator < (const Edge &edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int node) {
	if (parent[node] == node) {
		return node;
	}
	return getParent(parent[node]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	cin >> V;
	cin >> E;
	vector<Edge> Vertex;

	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		Vertex.push_back(Edge(tmp1, tmp2, tmp3));
	}

	sort(Vertex.begin(), Vertex.end());

	for (int i = 1; i <= V;i++) {
		parent[i] = i;
	}

	for (int i = 0; i < Vertex.size(); i++) {
		if (getParent(Vertex[i].node[0]) != getParent(Vertex[i].node[1])) {
			sum += Vertex[i].distance;
			unionParent(Vertex[i].node[0], Vertex[i].node[1]);
		}
	}

	cout << sum << endl;

	return 0;
}