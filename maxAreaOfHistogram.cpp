#include"bits/stdc++.h"
using namespace std;

int maxAreaOfHistogram(vector<int> &v) {
	v.push_back(0);
    	int n = v.size(), area = 0;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && v[s.top()] > v[i]) {
			int h = v[s.top()]; s.pop();
			int l = s.empty() ? -1 : s.top();
			area = max(area, h * (i - l - 1));
		}
		s.push(i);
	}
	return area;
}

int main() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	for(int &i : a) cin >> i;

	int res = maxAreaOfHistogram(a);

	cout << res << "\n";

	return 0;
}
