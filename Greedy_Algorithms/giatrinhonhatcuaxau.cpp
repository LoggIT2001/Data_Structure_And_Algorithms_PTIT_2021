#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        int k;
        cin >> k >> s;
        int d[100];
        memset(d,0,sizeof(d));
        priority_queue<int, vector<int> > p;
        for(int i=0;i<s.size();i++){
            d[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(d[s[i]] >0){
                p.push(d[s[i]]);
                d[s[i]]=0;
            }
        }
        while(k>0 && p.size()>0){
            k-=1;
            int t=p.top(); p.pop();
            t--;
            p.push(t);
        }
        long long sum=0;
        while(p.size()>0){
            int t=p.top();
            p.pop();
            sum+=t*t;
        }
        cout << sum << endl;
    }
    return 0;
}