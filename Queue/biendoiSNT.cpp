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
#define reset(A) memset(A,true,sizeof(A))
#define FILEIN freopen("inputDTL.txt","r",stdin)
#define FILEOUT freopen("outputDTL.txt","w",stdout)
#define FORX(i,n,m) for(int i=n;i<m;++i)

/**********DTL**********/

long long const mod=1e9+7;
int const MAX=1e5+5;

/**********DTL**********/

int d[]={1,10,100,1000};
int a[10005];
bool prime[10005];

/**********DTL**********/

void sangNT(){
	reset(prime);
	int i,j;
	prime[i]=false;
	FOR(i,2,101){
		if(prime[i]){
			for(j=2;i*j<=10000;prime[i*j++]=false);
		}
	}
}

int result(int s, int t){
	queue<int> qe;
	int a[10005]={0};
	if(s==t){
		return 0;
	}
	qe.push(s);
	a[s]=1;
	while(!qe.empty()){
		int u=qe.front(); qe.pop();
		FORX(i,0,4){
			FOR(j,0,10){
				int v=d[i]*((u/d[i]/10)*10+j)+u%d[i];
				if(v>1000 && prime[v] && a[v]==0){
					qe.push(v);
					a[v]=a[u]+1;
					if(v==t) return (a[t]-1);
				}
			}
		}
	}
	return -1;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    sangNT();
    int test;
    cin >> test;
    while(test--){
        int s,t;
		cin >> s >> t;
		cout << result(s,t) << endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int d[]={1,10,100,1000};
int a[10005];
bool prime[10005];
void sangNT(){
	memset(prime,true,sizeof(prime));
	int i,j;
	prime[i]=false;
	for(i=2;i<=100;++i){
		if(prime[i]){
			for(j=2;i*j<=10000;prime[i*j++]=false);
		}
	}
}

int result(int s, int t){
	queue<int> qe;
	int a[10005]={0};
	if(s==t){
		return 0;
	}
	qe.push(s);
	a[s]=1;
	while(!qe.empty()){
		int u=qe.front(); qe.pop();
		for(int i=0;i<4;++i){
			for(int j=0;j<10;j++){
				int v=d[i]*((u/d[i]/10)*10+j)+u%d[i];
				if(v>1000 && prime[v] && a[v]==0){
					qe.push(v);
					a[v]=a[u]+1;
					if(v==t) return (a[t]-1);
				}
			}
		}
	}
	return -1;
}

int main(){
	sangNT();
	int test;
	cin >> test;
	while(test--){
		int s,t;
		cin >> s >> t;
		cout << result(s,t) << endl;
	}
	return 0;
}
*/