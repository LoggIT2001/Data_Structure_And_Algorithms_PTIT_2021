#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

/**********fuction**********/

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        int n;
        cin >> n;
        list<int> ls;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        bool chuaxet[n+5];
        memset(chuaxet,false,sizeof(chuaxet));
        while(!ls.empty()){
            int top=ls.front();
            if(chuaxet[top]==false){
                cout << top << " ";
                chuaxet[top]=true;
            }
            ls.pop_front();
        }
    //}
    return 0;
}