// binaryTree4
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
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FORD(i,n,m) for(int i=m;i>=n;i--)
#define reset(A) memset(A,0,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int n;
int Inorder[1005], levelOrder[1005], a[1005];

/**********DTL**********/

void PostOder(int x, int y){
    if(x>y) return;
    else if(x==y){
        cout << Inorder[x] << " ";
    }else{
        int tmp;
        FOR(i,1,n){
            if(a[levelOrder[i]]>=x && a[levelOrder[i]]<=y){
                tmp=i;
                break;
            }
        }
        tmp=a[levelOrder[tmp]];
        PostOder(x,tmp-1);
        PostOder(tmp+1,y);
        cout << Inorder[tmp] << " ";
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        cin >> n;
        FOR(i,1,n){
            cin >> Inorder[i];
            a[Inorder[i]]=i;
        }
        FOR(i,1,n){
            cin >> levelOrder[i];
        }
        PostOder(1,n);
        cout << endl;
    }
    return 0;
}