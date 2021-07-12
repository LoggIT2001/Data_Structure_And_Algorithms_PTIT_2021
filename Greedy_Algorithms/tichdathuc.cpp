#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

/**********fuction**********/

struct data{
    int hso, mu;
};

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        vector< vector<data> > res;
        int n,m;
        cin >> n >> m;
        data a[n+5],b[m+5];
        for(int i=0;i<n;i++){
            cin >> a[i].hso;
            a[i].mu=i;
        }
        for(int i=0;i<m;i++){
            cin >> b[i].hso;
            b[i].mu=i;
        }
        for(int i=0;i<n;i++){
            vector<data> tmp;
            for(int j=0;j<m;j++){
                tmp.push_back({a[i].hso * b[j].hso, a[i].mu + b[j].mu});
            }
            res.push_back(tmp);
        }
        int mu=0;
        while(mu<n+m-1){
            int heso=0;
            for(int i=0;i<res.size();i++){
                for(int j=0;j<res[i].size();j++){
                    if(res[i][j].mu==mu) heso+=res[i][j].hso;
                }
            }
            cout << heso << " ";
            mu++;
        }
        cout << endl;
    }
    return 0;
}