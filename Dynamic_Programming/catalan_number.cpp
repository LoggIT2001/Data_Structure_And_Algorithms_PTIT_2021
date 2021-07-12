/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

string s[111];

/**********DTL**********/

string add(string a, string b){
    string res="";
    while(a.length()<b.length()) a = "0" + a;
    while(a.length()>b.length()) b = "0" + b;
    int nho=0;
    FORD(i,a.length()-1,0){
        int tmp= (int)(a[i] -'0') + (int)(b[i] -'0') + nho;
        nho=tmp/10;
        tmp%=10;
        res=(char)(tmp+'0')+res;
    }
    if(nho>=0){
        res=(char)(nho+'0')+res;
    }
    return res;
}

string mul(string a, string b){
    vector<int> vt1,vt2;
    int len=a.size()+b.size();
    FOR(i,0,a.size()){
        vt1.push_back((int)(a[i]-'0'));
    }
    FOR(i,0,b.size()){
        vt2.push_back((int)(b[i]-'0'));
    }
    vector< vector<int> > vt(b.size());
    int index=0;
    FORD(i,b.size()-1,0){
        int nho=0,so=0,t=0;
        while(t<index){
            vt[index].push_back(0);
            t++;
        }
        FORD(j,a.size(),0){
            so=vt1[j]*vt2[j] + nho;
            vt[index].push_back(so%10);
            nho=so/10;
        }
        if(nho>0){
            vt[index].push_back(nho);
        }
        while(vt[index].size()<len){
            vt[index].push_back(0);
        }
        reverse(vt[index].begin(),vt[index].end());
        index++;
    }
    int nho=0;
    string res="";
    FORD(i,vt[0].size()-1,0){
        int so=nho;
        FOR(j,0,vt.size()){
            so+=vt[i][j];
        }
        res=(char)(so%10+'0')+res;
        nho=so/10;
    }
    if(nho>0){
        res=(char)(nho+'0')+res;
    }
    while(res[0]==0){
        res.erase(res.begin());
    }
    return res;
}

void solve(){
    s[0]="1";
    s[1]="1";
    FOR(i,2,103){
        string tmp="";
        FOR(j,0,i){
            string temp="0";
            tmp=add(tmp,mul(s[j],s[i-j-1]));
        }
        s[i]=tmp;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    solve();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << s[n] << endl;
    }
    return 0;
}