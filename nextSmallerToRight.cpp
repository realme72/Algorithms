stack<int> s;
vector<int> nsr(n);
for(int i = n - 1; i >= 0; --i) {
		if(!s.empty()) {
			while(!s.empty() and s.top() >= a[i]) {
				s.pop();
			}
		}
		nsr[i] = s.empty() ? -1 : s.top();
		s.push(a[i]);
}
