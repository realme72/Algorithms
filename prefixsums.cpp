#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)


void solve() {
	int n; cin >> n; // number of elements in an array
	vector<int> a(n), prefixsum(n+1, 0);

	for(int &i : a) cin >> i; // array
	
	// calculating prefix sums
	for(int i = 1; i <= n; ++i) {
		prefixsum[i] = prefixsum[i - 1] + a[i - 1];
	}
	
	
	for(auto i : prefixsum) cout << i << " ";
	cout << "\n";
	
	//queries
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		cout << prefixsum[r]- prefixsum[l] << "\n";
	}
}
 
int gaurav() {
	ios_base::sync_with_stdio(false);
	
	// clock_t begin, end;
	// double time_spent;
	// begin = clock();

	int t = 1;
	while(t--) {
		solve();
	}
 
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// cout << "Time Taken " << prec(10) << time_spent;
	// cout << "\n";
	return 0;
} 
