vector<vector<int>> g;
vector<int> color, par;
int start_point, End_point;

int n, m;

bool forUndirected_graph(int v, int p) {
 	color[v] = 1; // 1 stands for that we are entering at this vertex
	for(auto u :g[v] ) {
		if(u == p) continue;
		if(color[u] == 0) {
			par[u] = v;
			if(dfs(u, v)) return true;
		}
		else if(color[u] == 1) {
			start_point = u;
			End_point = v;
			return true;
		}
 	}
	
	color[v]  = 2; // 2 stands for we are coming out of the vertex.
	return false;
}	


bool fordirected_graph(int v) {
	color[v] = 1;
	for(auto u : g[v]) {
		if(color[u] == 0) {
			par[u] = v;
			if(dfs(u)) {
				return true;;
			}
		}
		else if(color[u] == 1) {
			start_point = u;
			End_point = v;
			return true;
		}
	}
	color[v] = 2;
	return false;
}


int main( )  {
	cin >> n >> m;
	g.resize(n+1);
	color.assign(n+1, 0);
	par.assign(n+1, -1);
	
	for(int i = 0, u , v; i < m; ++i) {
		cin >> u >> v;
		g[u].pb(v);// line 1
		g[v].pb(u);// line 2
		
		//if you are dealing with directed graph you only need to write line 1 
		// else write both lines if graph is undirected
	}
	
	
	// for directed graph
	for(int i = 1; i <= n; ++i) {
		if(color[i] == 0 and fordirected_graph(i)) {
			break;
		}
	}
	
	// for undirected graph
	for(int i  = 1; i <= n; ++i ) {
		if(color[i] == 0 and forundirected_graph(i, par[i])) {
			break;
		}
	}
	
	vector<int> path;
	path.pb(start_point);
	for(int i = End_point; i != start_point; i = par[i]) {
		path.pb(i);
	}
	path.pb(start_point);
	reverse(path.begin(), path.end());
	
	if(path.size() < 2) {
		cout << "The graph has no cycles\n";
	} 
	else {
		cout << path.size() << endl;
		for(auto u : path) cout << u << " ";
		cout << endl;
	}
	
	return 0;
}
