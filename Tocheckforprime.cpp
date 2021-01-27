#include"bits/stdc++.h"
using namespace std;

int main() {
  	int n; cin >> n;
	
	auto chk = [&](int n) {
		if(n < 2) {
			return 0;
		}
		if(n == 2) {
			return 1;
		}
		
		for(int i = 3; i*i <= n; ++i ) {
			if( n % i == 0) return 0;
		}
		return 1;
	};	

	if(chk(n)) {
		cout << "YES\n";
	}
	else cout << "NO\n";
	
  	return 0;
}
