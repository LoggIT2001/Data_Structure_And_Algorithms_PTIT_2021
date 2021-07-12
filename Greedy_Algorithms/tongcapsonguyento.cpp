#include<iostream>
#include<vector>
using namespace std;

vector<bool> ok(1e5,false);
// sang nguyen to
void Eratosthenes(long long n){
    ok[0]=ok[1]=true;
    for(int i=2;i<=n;i++){
        if(!ok[i]){
            for(int j=i*i;j<=n;j+=i){
                ok[j]=true;
            }
        }
    }
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        bool stop=false;
        Eratosthenes(n);
        for(int i=2;i<=n;i++){
            if(ok[i]==false && ok[n-i]==false){
                cout << i <<" " << n-i;
                stop=true;
                break;
            }
        }
        if(stop==false) cout << -1;
        cout << endl;
    }
    return 0;
}