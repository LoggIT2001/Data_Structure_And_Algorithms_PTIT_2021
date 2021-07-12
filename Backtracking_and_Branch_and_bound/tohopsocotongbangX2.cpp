/******<CODE NEVER DIE>******/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
#define CIG cin.ignore()
#define pb push_back
#define pa pair<int,int>
#define f first
#define s second
#define FOR(i,n,m) for(int i=n;i<m;i++)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

vector<string> vt[105];
int n,sum, testcase;
int a[100],b[100],temp;

/**********DTL**********/

void Output(){
    testcase++;
    string res="";
    res+="{";
    FOR(i,1,temp){
        res+=string(1,b[i]);
        if(i<temp-1) res+=" ";
    }
    res+="}";
    vt.pb(res);
}

void Try(int i, int sum){
    if(i<=n && sum==0) Output();
    while(i<=n && sum-a[i]>=0){
        b[temp]=a[i];
        temp++;
        Try(i,sum-a[i]);
        i++;
        temp--;
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        vt.clear();
        testcase=0;
        temp=1;
        cin >> n >> sum;
        FOR(i,1,n+1) cin >> a[i];
        FOR(i,1,n){
            FOR(j,i+1,n+1){
                if(a[i]==a[j]){
                    swap(a[i],a[j]);
                    --n;
                }
            }
        }
        sort(a+1,a+n+1);
        if(sum<a[1]);
        else{
            Try(1,sum);
            if(vt.size()>0){
                cout << vt.size() << " ";
                FOR(i,0,vt.size()){
                    cout << vt[i] << " ";
                }
            }
        }
        if(!testcase){
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}