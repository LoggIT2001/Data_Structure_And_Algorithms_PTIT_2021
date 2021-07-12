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

int chuaxet[10005];
char ch[105][105];
int dinh[105][105];
int n,m;
int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={1,1,0,-1,-1,-1,0,1};

/**********DTL**********/

void init(){
    FOR(i,1,10001){
        chuaxet[i]=1;
    }
}

void data(){
    cin >> n >> m;
    int st=0;
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            cin >> ch[i][j];
            st++;
            dinh[i][j]=st; // khoi tao dinh
        }
    }
}

void DFS(int a, int b){
    FOR(i,0,8){
        int x=b+X[i];
        int y=a+Y[i];
        if((x>=1 && x<=m) && (y>=1 && y<=n) && chuaxet[dinh[y][x]]==1 && ch[y][x]=='W'){
            chuaxet[dinh[y][x]]==0;
            DFS(y,x);
        }
    }
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    //int test;
    //cin >> test;
    //while(test--){
        data();
        init();
        int dem=0;
        FOR(i,1,n+1){
            FOR(j,1,m+1){
                if(ch[i][j]=='W' && chuaxet[dinh[i][j]]==1){
                    dem++;
                    chuaxet[dinh[i][j]]=0;
                    DFS(i,j);
                }
            }
        }
        cout << dem;
    //}
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
 
int chuaxet[10005];
char pond[105][105];
int dinh[105][105];
int N, M;
int xqX[]={0, -1, -1, -1, 0, 1, 1, 1};
int xqY[]={1, 1, 0, -1, -1, -1, 0, 1};

void khoitao (){
	for (int i=1; i<=10000; i++){
		chuaxet[i]=1;
	}
}
 
void nhap (){
	int stt=0;
	cin>>N>>M;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			cin>>pond[i][j];
			stt++;
			dinh[i][j]=stt;	//khoi tao dinh
		}
	}
}
 
void DFS_RA (int r, int c){
	for (int i=0; i<8; i++){
		int X=c+xqX[i];
		int Y=r+xqY[i];
		if ((X>=1 && X<=M) && (Y>=1 && Y<=N) && chuaxet[dinh[Y][X]]==1 && pond[Y][X]=='W'){
			chuaxet[dinh[Y][X]]=0;	//Dinh da duyet
			DFS_RA (Y, X);
		}
	}
}
 
int main (){
	nhap ();
	khoitao();
	int dem=0;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			if (pond[i][j]=='W' && chuaxet[dinh[i][j]]==1){
				dem++;
				chuaxet[dinh[i][j]]=0;	//Dinh da duyet
				DFS_RA (i, j);
			}
		}
	}
	cout<<dem;
	return 0;
}
Bài này mình s? d?ng phuong pháp DFS de quy tìm so thành ph?n liên thông. 
So lu?c qua v? kh?i t?o ban d?u: 
- T?o dinh[R][C]: v?i l?n lu?t các d?nh t? 1->R*C; 
- Duyet theo 8 huong (lên, lên trái, trái, xu?ng trái, xu?ng, xu?ng ph?i, ph?i, lên ph?i) và dánh d?u; 
Các b?n cung có th? s? d?ng BFS.
*/
