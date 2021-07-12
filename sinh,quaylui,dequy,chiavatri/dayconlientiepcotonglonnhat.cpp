#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+5];
        int Max;
        bool sd=false;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]>0) sd=true;
            if(i==0) Max=a[0];
            else{
                if(Max<a[i]) Max=a[i];
            }
        }
        if(!sd) cout << Max << endl;
        else{
            int sum=0,res=a[0];
            for(int i=0;i<n;i++){
                if(a[i]+sum <0){
                    sum=0;
                    continue;
                }
                sum+=a[i];
                if(res<sum) res=sum;
            }
            cout << res << endl;
        }
    }
    return 0;
}