// check if there exist a subarray whoose sum is x .

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
#define S second
#define F first
#define all(a) a.begin(),a.end()
#define gaurav main
#define prec(n) fixed<<setprecision(n)

/*
n = 5, x = 7
a[5] = {2, 4, 1, 2, 7}

there exist three subarray's whose sum is x
1st subarray {2, 4, 1}
2nd subarray {4, 1, 2}
3rd subarray {7}
*/

void solve() {
	int n, x;cin >> n >> x;
	vector<int> a(n);

	for(auto &i : a) {
		cin >> i;
	}

	int left = 0, right = 0, sum = 0;
	for(int right = 0; right < n; ++right) {
		sum += a[right];
		while(sum > x and left < right) {
			sum -= a[left++];
		}
		if(sum == x) {
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
}
 
int gaurav() {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(t--) {
		solve();
	}
	return 0;
} 
