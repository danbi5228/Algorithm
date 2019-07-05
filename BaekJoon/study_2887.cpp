#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N = 0;
long long tmp1 = 0, tmp2 = 0, tmp3 = 0;
long long parent[100001] = { 0, };
long long sum = 0;

class Planet {
public:
	int P_Num;
	long long site[3];

	Planet(int num, long long a, long long b, long long c) {
		this->P_Num = num;
		this->site[0] = a;
		this->site[1] = b;
		this->site[2] = c;
	}
};

class ResultP {
public:
	int node[2];
	long long distance;

	ResultP(int a, int b, long long dis) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = dis;
	}

	bool operator < (ResultP resultp) {
		return this->distance < resultp.distance;
	}
};

int Getparent(int a) {
	if (parent[a] == a) {
		return a;
	}
	else return Getparent(parent[a]);
}
bool isSameP(int x_s, int y_s) {
	x_s = Getparent(x_s);
	y_s = Getparent(y_s);

	if (x_s == y_s) return true;
	else return false;
}

void UnionP(int x_u, int y_u){
	x_u = Getparent(x_u);
	y_u = Getparent(y_u);

	if (x_u < y_u) {
		parent[y_u] = x_u;
	}
	else parent[x_u] = y_u;
}

bool cmp_x(Planet a, Planet b){
	return abs(a.site[0]) < abs(b.site[0]);
}
bool cmp_y(Planet a, Planet b) {
	return abs(a.site[1]) < abs(b.site[1]);
}
bool cmp_z(Planet a, Planet b) {
	return abs(a.site[2]) < abs(b.site[2]);
}

int main() {
	vector<Planet> P; 
	vector<ResultP> result_P;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		P.push_back(Planet(i,tmp1, tmp2, tmp3));
		parent[i] = i;
	}

	sort(P.begin(), P.end(), cmp_x);

	//for(int i = 0; i < P.size(); i++) {
	//	cout << P[i].site[0] <<" "<< endl;
	//}
	for (int i = 0; i < N-1; i++) {
		result_P.push_back(ResultP(P[i].P_Num,P[i + 1].P_Num, abs(P[i].site[0] - P[i + 1].site[0])));
	}


	sort(P.begin(), P.end(), cmp_y);
	for (int i = 0; i < N-1; i++) {
		result_P.push_back(ResultP(P[i].P_Num, P[i + 1].P_Num, abs(P[i].site[1] - P[i + 1].site[1])));
	}

	sort(P.begin(), P.end(), cmp_z);
	for (int i = 0; i < N-1; i++) {
		result_P.push_back(ResultP(P[i].P_Num, P[i + 1].P_Num, abs(P[i].site[2] - P[i + 1].site[2])));
	}


	sort(result_P.begin(), result_P.end());
	

	for (int i = 0; i < result_P.size(); i++) {
		if (!isSameP(result_P[i].node[0], result_P[i].node[1])) {
			sum += result_P[i].distance;
			UnionP(result_P[i].node[0], result_P[i].node[1]);
		}
	}

	cout << sum << endl;

	return 0;
}