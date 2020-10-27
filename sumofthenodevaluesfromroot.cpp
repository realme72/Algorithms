//sum of the node values from root node.
#include"bits/stdc++.h"
using namespace std;

const int N = 101;
vector<int> t[N];
int d[N], n, a[N];

void dfs(int u = 1, int par = 0) {
	d[u] = a[u];
	int mx = 0;
	for(auto v : t[u]) {
		if( v == par ) continue;
		dfs(v, u);
		mx = max(mx, d[v]);
	}
	d[u] += mx;
}

int main() {
	cin >> n;

	for(int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		t[x].push_back(y);
		t[y].push_back(x);
	}

	for(int i = 0; i < n; ++i) cin >> a[i+1];
	dfs();

	cout << d[1] << "\n";
}
