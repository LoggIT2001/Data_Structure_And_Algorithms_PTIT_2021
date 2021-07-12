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

struct data{
	string father;
	string son;
	int agefather;
	int ageson;
}typedef data;
int x;
data link[105];

/**********DTL**********/

int cmp(data a, data b){
	if(a.ageson < b.ageson) return 0;
	else if(a.ageson==b.ageson){
		if(a.son > b.son) return 0;
	}
	return 1;
}

void backtrack(string fa, int kc){
	FOR(i,1,x+1){
		if(fa==link[i].father){
			if(fa=="Ted"){
				link[i].ageson=100-link[i].agefather;
				kc=100-link[i].agefather;
				backtrack(link[i].son,kc);
			}else{
				link[i].ageson=kc-link[i].agefather;
				backtrack(link[i].son,kc-link[i].agefather);
			}
		}
	}
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    int t=test;
    while(test--){
		cin >> x;
		FOR(i,1,x+1){
			cin >> link[i].father >> link[i].son >> link[i].agefather;
		}
		backtrack("Ted",0);
		sort(link+1, link+x+1, cmp);
		cout << "DATASET " << t-test << endl;
		FOR(i,1,x+1){
			cout << link[i].son << " " << link[i].ageson << endl;
		}
    }
    return 0;
}