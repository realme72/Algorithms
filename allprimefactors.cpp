#include"bits/stdc++.h"
using namespace std;

int main() {
	int n;cin >> n; 

	vector<int> primefactors;
	for(int i = 2; i * i <= n; ++i) {
		while(n % i == 0) {
			primefactors.push_back(i);
			n /= i;
		}
	}

	if( n > 1)  primefactors.push_back(n);

	for(auto i : primefactors) cout << i << " ";
	cout << "\n";

  	return 0;
}
