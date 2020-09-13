Question Link : https://www.spoj.com/problems/LCA

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
	return (a.second < b.second) ;
}

int parent[1234];
bool visited[1234];
int root_node;

int LCA(int u,int v){
 	memset(visited,false,sizeof(visited));
 	int lca;
 	while(true){
  		visited[u]=true;
  		if(u==root_node){
   			break;
  		}
  		u=parent[u];
 	}
	while(true){
 		if(visited[v]==true){
  			lca=v;
  			break;
 		}
 		v=parent[v];
	}
	return lca;
}

int main(){
	ItsFUN;

	int t; cin >> t;
 	int val=1;
 	while(t--){
	 	int n;cin >> n;
  		memset(parent,-1,sizeof(parent));
  		for(int i=1;i<=n;i++){
   			int x; cin >> x;
   			while(x--){
   				int node;cin >> node;
       			parent[node]=i;
   			}
 	 	}

  		for(int i=1;i<=n;i++){
   			if(parent[i]==-1){
   				root_node=i;
   				break;
  			}
 		}
  		int q;cin >> q;
   		cout << "Case " << val << ":" << "\n";
  		for(int i=1;i<=q;i++){
   			int u,v;cin >> u >> v;
   			int ans=LCA(u,v);
   			cout << ans << endl;
  		}
  		val++;
 	}

	return 0;
}
