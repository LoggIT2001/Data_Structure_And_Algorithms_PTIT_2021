#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int n,X,a[1000],b[100];
vector<string> vt;
void result(int k){
	string s="";
    s+='{';
    for(int i=0;i<=k;i++){
        s+=(a[b[i]]+'0');
        if(i<k) s+=' ';
    }
    s+='}';
    vt.push_back(s);
}
void output(){
	if(vt.size()>0){
		cout << vt.size() << " ";
		for(int i=0;i<vt.size();i++){
			cout << vt[i] << " ";
		}
	}else cout << -1;
}
void Try(int v, int i, int k){
    for(int j=0;j<n;j++){
        if(v>=a[j] && j>=i){
            v-=a[j];
            b[k]=j;
            if(v==0){
                result(k);
            }else
                Try(v,j,k+1);
            b[k]=0;
            v+=a[j];
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        vt.clear();
        cin >> n >> X;
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        Try(X,0,0);
        output();
        cout << endl;
    }
    return 0;
}
