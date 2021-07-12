#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s;
ll a[25],b[25],c[25],close,open;
ll parentheses[25],character[205];
ll len;
string res[5215];
ll id=0;

void update(){
	for(ll i=0;i<len;i++){
		character[i]=1;
	}
	for(ll i=1;i<=close;i++){
		if(parentheses[i]==0){
			character[a[i]]=0;
			character[b[i]]=0;
		}
	}
	id++;
	res[id]="";
	for(ll i=0;i<len;i++){
		if(character[i]){
			res[id]+=s[i];
		}
	}
}

void Try(ll i){
	for(ll j=0;j<=1;j++){
		parentheses[i]=j;
		if(i==close){
			update();
		}else{
			Try(i+1);
		}
	}
}

void solution(){
	cin >> s;
	open=0;
	close=0;
	len=s.length();
	for(ll i=0;i<len;i++){
		if(s[i]=='('){
			open++;
			c[open]=i;
		}else if(s[i]==')'){
			close++;
			a[close]=c[open];
			b[close]=i;
			open--;
		}
	}
	Try(1);
	id--;
	sort(res+1,res+1+id);
	res[0]="*";
	for(ll i=1;i<=id;i++){
		if(res[i]!=res[i-1]){
			cout << res[i] << endl;
		}
	}
}

int main(){
	solution();
	return 0;
}