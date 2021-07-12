#include<iostream>
#include<algorithm>
using namespace std;

int v[]={2,3,5,7,11,13,17,19,23,29,31};
int n;
long long res;
void back_Track(int i, long long ans, long long uoc){
    if( uoc > n ) return;
    if(uoc==n) res= min (res,ans);
    for(int j=1;;j++){
        if(ans*v[i]>res) break;
        ans*=v[i];
        back_Track(i+1,ans,uoc*(j+1));
    } 
}

void slove(){
    res=1e18;
    back_Track(0,1,1);
    cout << res << endl;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        slove();
    }
    return 0;
}