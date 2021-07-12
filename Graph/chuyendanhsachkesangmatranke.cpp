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

int a[1005][1005];

/**********DTL**********/

void Solution(string s, int hang){
    int len=s.size(), flat=0, cot=0;
    FOR(i,0,len){
        if(s[i] != ' '){
            if(!flat){
                flat=1;
            }
            cot=cot*10+(s[i]-48);
        }else if(flat=1){
            flat=0;
            a[cot][hang]=1;
            a[hang][cot]=1;
            cot=0;
        }
        if(i==len-1 && cot!=0){
            a[hang][cot]=1;
            a[cot][hang]=1;
        }
    }
}


/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        int n;
        cin >> n;
        CIG;
        string s;
        FOR(i,1,n+1){
            s="";
            getline(cin,s);
            Solution(s,i);
        }
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    //}
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int mat[1005][1005] = { 0 };

void tach(string s, int row) {
    int n = s.size(), flag = 0, col = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            if (!flag)
                flag = 1;
            col = col * 10 + (s[i] - 48);
        }

        else if (flag == 1) {
            flag = 0;
            mat[row][col] = 1;
            mat[col][row] = 1;
            col = 0;
        }

        if (i == n - 1 && col != 0) {
            mat[row][col] = 1;
            mat[col][row] = 1;
        }
    }
}

int main() {
    string s;
    int n;

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        s = " ";
        getline(cin, s);
        tach(s, i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
*/