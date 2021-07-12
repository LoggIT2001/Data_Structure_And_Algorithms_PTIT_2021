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

    int test;
    cin >> test;
    while(test--){
        int k;
        string s;
        cin >> k >> s;
        priority_queue<ll, vector<ll> > pq;
        ll d[100];
        memset(d,0,sizeof(d));
        for(int i=0;i<s.size();i++){
            d[s[i]]++;
        }
        for(int i=0;i<100;i++){
            if(d[i]>0) pq.push(d[i]);
        }
        while(k>0 && !pq.empty()){
            ll top=pq.top(); pq.pop();
            k--;
            top--;
            pq.push(top);
        }
        ll final=0;
        while(!pq.empty()){
            ll top=pq.top();
            pq.pop();
            final+= top*top;
        }
        cout << final  << endl;
    }
    return 0;
}