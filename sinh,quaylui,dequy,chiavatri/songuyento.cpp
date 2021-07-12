#include<iostream>
#include<vector>
using namespace std;

vector <int> a;
vector < vector <int> > res;
int n,p,s,vt;
bool ok[300];
void SangNT(){
    for(int i=1;i<=200;i++){
        if(!ok[i]){
            a.push_back(i);
            for(int j=i*i;j<=200;j+=i){
                ok[j]=true;
            }
        }
    }
}
void init(){
    cin >> n >> p >> s;
    vt=lower_bound(a.begin(),a.end(),p)-a.begin(); //tim vi tri so p trong mang a
    for(int i=0;i<300;i++){
        ok[i]=false;
    }               // gan cac phan tu mang ok la false
    res.clear();
}
void Try(int i, vector <int> v, int sum){
    if(sum>s){
        return;
    }
    if(sum==s && v.size()==n){
        res.push_back(v);
        return;
    }
    for(int j=i;j<a.size();j++){
        if(ok[j]==false && sum+a[j]<=s && v.size()<n){
            v.push_back(a[j]);
            ok[j]=true;
            Try(j+1,v,sum+a[j]);
            v.pop_back();
            ok[j]=false;
        }
    }
}
void result(){
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] <<" ";
        }
        cout <<endl;
    }
}
int main(){
    SangNT();
    int t;
    cin >> t;
    while(t--){
        init();
        vector <int> v;
        v.clear();
        Try(vt,v,0);
        result();
    }
    return 0;
}