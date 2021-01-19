#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define gaurav main

vector<vector <int> >g;
vector<bool> vis;

int dfs(int v, int par) {
	vis[v] = true;
	for(auto u : g[v]) {
		if(!vis[u]) {
			if(dfs(u, v)) return 1;
		}

		else if(u != par) {
			return true;
		}
	}

	return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	g.resize(n);

	for(int i = 0 ; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vis.assign(n , false);

	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			if(dfs(i, -1)) {
				cout << "There exists a cycle\n";
				return ;
			}
		}
	}

	cout << "there is no cycle\n";

}
 
int gaurav() {
	ios_base::sync_with_stdio(false);
	
	int t  = 1;
	while(t--) {
		solve();
	}
	return 0;
} 
  
