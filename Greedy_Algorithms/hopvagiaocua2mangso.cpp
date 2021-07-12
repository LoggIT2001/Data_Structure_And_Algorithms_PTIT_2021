#include<iostream>
#include<cstring>
using namespace std;


int main(){
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        int a;
        int check[1000];
        memset(check,0,sizeof(check));
        for(int i=0;i<n;i++){
            cin >> a;
            check[a]++;
        }
        for(int i=0;i<m;i++){
            cin >> a;
            check[a]++;
        }
        // hop 2 mang so
        for(int i=0;i<1000;i++){
            if(check[i]>0) cout << i << " ";
        }
        cout << endl;
        // giao 2 mang so
        for(int i=0;i<1000;i++){
            if(check[i]>1) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}