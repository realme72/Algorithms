#include"bits/stdc++.h"
using namespace std;

int main() {
	int n; cin >> n;
  vector<int> a(n), nsr(n);
  for(int &i : a) cin >> i;
  
  stack<int> s;
  	for(int i = 0; i < n; ++i) {
		if(!s.empty()) {
			while(!s.empty() and s.top() >= a[i]) {
				s.pop();
			}
		}
		nsl[i] = s.empty() ? -1 : s.top();
		s.push(a[i]);
	}
  
  return 0;
}
