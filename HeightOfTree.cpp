//the maximum height of tree when any node in the tree is considered as the root of the tree. 
#include"bits/stdc++.h"
using namespace std;

const int N = 1000;
vector<int> t[N];
int in[N], out[N], n;

void dfsforin(int u, int parent) {
	in[u] = 0;
	for (int child : t[u]) {	
		if (child == parent)
			continue;	
		dfsforin(child, u); 
		in[u] = max(in[u], 1 + in[child]); 
    } 
}
void dfsforout(int u, int parent) {
    int mx1 = -1, mx2 = -1;
    for (int child : t[u]) {
    	if (child == parent)
    		continue;
    	if (in[child] >= mx1) {
    		mx2 = mx1;
    		mx1 = in[child]; 
        }
        else if (in[child] > mx2) 
            mx2 = in[child]; 
    }
    for (int child : t[u]) {
    	if (child == parent)
    		continue;
    	int longest = mx1; 
  
  		if (mx1 == in[child]) 
            longest = mx2; 
  		out[child] = 1 + max(out[u], 1 + longest); 
  		dfsforout(child, u); 
    } 
} 

void Heights() {
	dfsforin(1, 0);
	dfsforout(1, 0);

	for(int i = 1; i <= n; ++i) {
		cout << max(in[i], out[i]) << " ";
	}
	cout << "\n";
}

int main() {
	cin >> n;

	for(int i = 0; i < n-1; ++i) {
		int v, u; cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	Heights();

	return 0;
}
