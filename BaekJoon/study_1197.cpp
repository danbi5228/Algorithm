#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V = 0, E = 0; // Vertex, Edge
int tmp1 = 0, tmp2 = 0, tmp3 = 0;
int parent[100001] = { 0, }; // 0��°�� �Ⱦ��� 1������ 1���������� ���~~
int sum = 0;


//���� ����
class Edge {
public:
	int node[2]; // node[0] �� node[1] �� ����Ǿ��ִ�
	int distance;

	Edge(int a, int b, int dis) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = dis;
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
bool isSameParent(int x, int y) {
	x = GetParent(x);
	y = GetParent(y);

	if (x == y) { // �θ� ����
		return true;
	}
	else return false; // �θ� �ٸ���
}

void UnionParent(int x, int y) {
	x = GetParent(x);
	y = GetParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else
		parent[x] = y;
}

int main() {
	vector <Edge> Vertex;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		Vertex.push_back(Edge(tmp1, tmp2, tmp3));
	}

	sort(Vertex.begin(), Vertex.end());

	//�ʱ�ȭ
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	//for (int i = 0; i < Vertex.size(); i++) {
	//	cout << Vertex[i].node[0] << " " << Vertex[i].node[1] << " " << Vertex[i].distance << endl;
	//}
	
	for (int i = 0; i < Vertex.size(); i++) {
		if (!isSameParent(Vertex[i].node[0], Vertex[i].node[1])) {
			sum += Vertex[i].distance;
			UnionParent(Vertex[i].node[0], Vertex[i].node[1]);
		}
	}

	cout << sum << endl;

	return 0;
}