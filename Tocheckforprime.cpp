#include"bits/stdc++.h"
using namespace std;

// A better and efficient method to just use sieve
int N = 1e5 + 10;
bool prime[N];

void sieve() {
	memset(prime, 1, sizeof(bool));
	prime[0] = prime[1] = 0;
	
	for(int i = 2; i*i <= N; ++i) {
		if(prime[i]) {
			for(int j = 2 * i; j <= N: ++j) {
				prime[j] = false;
			}
		}	
	}	
}	


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
