#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

/**********fuction**********/

bool Nhohon5(int x){
    while(x>0){
        int tmp=x%10;
        if(tmp>5) return false;
        x/=10;
    }
    return true;
}

bool Chuso(int x){
    while(x>0){
        int tmp=x%10;
        int temp=x%100;
        if(tmp==temp) return false;
        x/=10;
    }
    return true;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int L,R;
        cin >> L >> R;
        queue<int> qe;
        for(int i=L;i<=R;i++){
            if(Chuso(i) && Nhohon5(i)){
                cout << i << " ";
                //qe.push(i);
            }
        }
        //while(!qe.empty()){
            //cout << qe.front() << " ";
            //qe.pop();
        //}
        cout << endl;
    }
    return 0;
}