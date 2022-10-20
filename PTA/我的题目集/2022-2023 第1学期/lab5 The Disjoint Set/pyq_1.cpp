#include<iostream>
#include<algorithm>
using namespace std;
int a[30005];
int b[30005];
int find(int x) {
	if (x == a[x]) return x;
	else return a[x] = find(a[x]);
}
void merge(int p1, int p2) {
	int root1 = find(p1);
	int root2 = find(p2);
	if (root1 != root2)
		a[root2] = root1;
}
int main() {
	int N,M,num;
	cin >> N>>M;
	for (int i = 1; i <=N; i++) {
		a[i] = i;
	}//节点初始化
	for (int i = 0; i < M; i++) {
		cin >> num;
		int m1, m2;
		cin >> m1;
		for (int j = 1; j < num; j++) {
			cin >> m2;
			merge(m1, m2);
		}
	}
	int maxc = 0;
	for (int i = 1; i <=N; i++) {
		int father = find(i);
		b[father]++;
		maxc = max(maxc, b[father]);
	}
	cout << maxc << endl;
	return 0;
}
