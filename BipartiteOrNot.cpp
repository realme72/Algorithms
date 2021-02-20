// Checking if the given graph is bipartite or not using bfs. 

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)

const ll MOD = 1e9 + 7;
vector<vector<int>> g;

void solve() {
	int n, m; cin >> n >> m;
	g.resize(n);

	for(int i = 0;i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> side(n, -1);
	queue<int> q;
	bool isbp = 1;

	for(int i = 0; i < n; ++i) {
		if(side[i] == -1) {
			side[i] = 0;
			q.push(i);
		}
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto u : g[v]) {
				if(side[u] == -1) {
					side[u] = side[v] ^ 1;
					q.push(u); 
				}
				else {
					isbp &= side[u] != side[v];
				}
			}
		}
	}

	if(isbp) {
		cout << "Graph is Bipartite\n";
	}
	else {
		cout << "No it's Not\n";
	}
}


int gaurav() {
	ios_base::sync_with_stdio(false);
	
	int t=1;
	while(t--) {
		solve();
	}

	return 0;
} 

  
