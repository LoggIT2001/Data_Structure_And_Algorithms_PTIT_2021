#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)

/**********fuction**********/

void Swap(vector<int> &vt, int l, int r){
    int tmp=vt[l];
    vt[l]=vt[r];
    vt[r]=tmp;
}

int MinSwap(vector<int> vt){
    int res=0;
    map<int,int> mp;
    vector<int> vc=vt;
    sort(vc.begin(),vc.end());
    for(int i=0;i<vt.size();i++){
        mp[vt[i]]=i;
    }
    for(int i=0;i<vt.size();i++){
        if(vt[i]!=vc[i]){
            res++;
            int x=vt[i];
            Swap(vt,i,mp[vc[i]]);
            mp[x]=mp[vc[i]];
            mp[vc[i]]=i;
        }
    }
    return res;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> vt;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            vt.push_back(x);
        }
        cout << MinSwap(vt) << endl;
    }
    return 0;
}