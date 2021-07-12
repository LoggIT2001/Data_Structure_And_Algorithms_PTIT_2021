#include<bits/stdc++.h>
using namespace std;

int a[100001],n;

void solution(){
	sort(a,a+n);
	int mid=n/2 + n%2 -1;
	int i=n-1;
	int j=mid;
	int count=0;
	while(mid<i && j>=0){
		if(a[i]>=2*a[j]){
			count++;
			i--;
			j--;
		}else{
			j--;
		}
	}
	cout << count+(n-2*count) << endl;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		solution();
	}
	return 0;
}