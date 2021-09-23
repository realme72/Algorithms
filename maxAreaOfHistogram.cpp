#include"bits/stdc++.h"
using namespace std;

int maxAreaOfHistogram(vector<int> &v) {
	int n = v.size();
	stack<int> s;
	int h, w, ans = 0;


	for(int i = 0; i < n; ++i) {
		while(!s.empty() and (v[i] <= v[s.top()] || i == n)) {
			h = v[s.top()];
			s.pop();
			w = s.empty() ? i : i - s.top() - 1;
			ans = max(ans, h * w);
		}

		s.push(i);
	}

	return ans;
}

int main() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	for(int &i : a) cin >> i;

	int res = maxAreaOfHistogram(a);

	cout << res << "\n";

	return 0;
}
