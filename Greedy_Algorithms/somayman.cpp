#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue <int, vector<int> , greater<int> > p;
void Luckynumber(int n){
    bool ok=true;
    while(n){
        if(n%4==0 && n<28){
            for(int i=1;i<=n/4;i++){
                p.push(4);
            }
            n=0;
        }else if(n%7==0 && n>0){
            for(int i=1;i<=n/7;i++){
                p.push(7);
            }
            n=0;
        }else if(n>=7){
            p.push(7);
            n-=7;
        }else if(n>=4){
            p.push(4);
            n-=4;
        }else{
            ok=false;
            break;
        }
    }
    if(ok==true){
        while(!p.empty()){
            cout << p.top();
            p.pop();
        }
    }else cout << -1;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        Luckynumber(n);
        cout << endl;
    }
    return 0;
}