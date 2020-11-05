// Method 1 : using multiset

#include<bits/stdc++.h>
using namespace std;


int main(){
	int n; cin >> n;
	vector<int> v(n);

	for(int &i : v) cin >> i;

	multiset<int> s;
	s.insert(v[0]);

	int ans = 0;

	for(int i = 1; i <n; ++i) {
		s.insert(v[i]);
		auto it = s.upper_bound(v[i]);
		ans += distance(it, s.end());
	}

	cout << ans << "\n";

   return 0;
}

// method 2: using merge sort

#include<bits/stdc++.h>
using namespace std;

int n;

int merge(int ar[],int temp[],int l,int mid,int r){
    int i=l, j=mid, k=l;
    int count=0;

    while((i<=mid-1) && j <= r){
        if (ar[i]>ar[j]){
            temp[k++]=ar[j++];
            count+=mid-i;
        }
        else {
            temp[k++]=ar[i++];
        }
    }

    while (i <= mid - 1){
        temp[k++] = ar[i++];
    }
 
    while (j <= r){
        temp[k++] = ar[j++];
    }
 
    for (i = l; i <= r; i++){
        ar[i] = temp[i];
    }
 
    return count;

}

int mergesort(int ar[],int temp[],int l,int r){
    int invColunt=0;

    if (l<r){
        int mid=(r+l)/2;
        invCount+= mergesort(ar,temp,l,mid);
        invCount+= mergesort(ar,temp,mid+1,r);
        invCount+= merge(ar,temp,l,mid+1,r);
    }

    return invCount;
}


int main(){
	cin>>n;
    int ar[n];
    int temp[n];

    for (int i=0;i<n;i++){
        cin>>ar[i];
    }

    int c = mergesort(ar,temp,0,n-1);
    cout<<c<<endl;


    return 0;
}

// method 3 : using bit(binary indexed tree)

#include<bits/stdc++.h>
using namespace std;

int n; 
int bit[1000+1];


int sum(int id) {
	int s = 0;
	while(id > 0) {
		s += bit[id];
		id -= id & - id;
	}
	return s;
}

void update(int id, int val) {
	while(id <= n) {
		bit[id] += val;
		id += id & -id;
	}
}

void getConvert(int a[]) {
	int temp[n];

	for(int i = 0; i < n;++i) temp[i] = a[i];
	sort(temp, temp + n);

	for(int i = 0; i < n; ++i) {
		a[i] = lower_bound(temp, temp + n, a[i]) - temp + 1;
	}
}

int getInvCount(int a[]) {
	int invC = 0;
	getConvert(a);

	for(int i = n-1; i >=0; --i ) {
		invC += sum(a[i] - 1);
		update(a[i], 1); 
	}
	return invC;
}

int main() {
	cin >> n;
	int a[n];

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << getInvCount(a) << "\n";
	return 0;
}
