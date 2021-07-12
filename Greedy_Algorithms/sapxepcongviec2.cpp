#include<bits/stdc++.h>
using namespace std;

struct data{
    int jobld,deadline,profit;
};
data a[1005];
bool cmp(data x, data y){
    return x.profit > y.profit;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i].jobld >> a[i].deadline >> a[i].profit;
        }
        sort(a,a+n,cmp);
        int res=0,count=0;
        int f[1005]={0};
        for(int i=0;i<n;i++){
            while(f[a[i].deadline] && a[i].deadline>0) a[i].deadline -=1;
            if(!f[a[i].deadline] && a[i].deadline>0){
                count++;
                res+=a[i].profit;
                f[a[i].deadline]=1;
            }
        }
        cout << count << " " << res << endl;
    }
    return 0;
}