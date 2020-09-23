// @Author :- Gaurav Bharti
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
#define lcm(a,b) a*b/(__gcd(a,b))
#define all(a) a.begin(),a.end()
#define test int t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

// it will count the number of coprime integers from 1 to n(inclusive) which are coprime to n;
ll euler(ll n) {
	ll res = n;
	for(ll i = 2; i * i <= n; ++i) {
		if(n%i == 0) {
			while (n%i == 0) n /= i;
			res -= res/i;
		}
	}
	if(n>1) res = res - res/n;
	return res;
}

// this is very similar to sieve , you can store the values of coprimes till ith
vii eulerForEach(int n ) {
	vector<int> phi(n+1);
	phi[0] = 0;
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) phi[i] = i;

	for(int i = 2; i <= n; ++i) {
		if(phi[i] == i) {
			for(int j = i; j<= n; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}

	return phi;
}

int main(){
	ItsFUN;

	ll n; cin >> n;
	cout << euler(n) << "\n";
	vii ans = eulerForEach(n);
	for(auto i : ans) cout << i << " ";
	cout << "\n";

	return 0;
}
