#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
//#define endl '/n'

int n,k;
string s;
bool check=false;

/*********DTL********/

int init(){
	int dem=0,c=0;
	bool check = false;
	for(int i=0;i<n;i++){
		if(s[i]=='A'){
			dem++;
			if(dem>=k) c++;
		}else dem=0;
	}
	if(c==1) return 1;
	return 0;
}

void GenNext(){
	int i=n-1;
	while(i>=0 && s[i]!='A'){
		s[i]='A';
		i--;
	}
	if(i>=0) s[i]='B';
	else check=true;
}

/**********main function**********/

int main(){
	FastIO; IN; OUT;

	//int test;
	//cin >> test;
	//while(test--){
		vector<string> res;
		cin >> n >> k;
		for(int i=0;i<n;i++) s.push_back('A');
		while(!check){
			if(init()) res.push_back(s);
			GenNext();
		}
		cout << res.size() << endl;
		for(int i=0;i<res.size();i++){
			cout << res[i] << endl;
		}
	//}
	return 0;
}