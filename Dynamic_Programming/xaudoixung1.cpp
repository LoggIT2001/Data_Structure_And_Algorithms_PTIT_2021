#include<bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		string s;
		cin >> s;
		int n=s.size();
		int dp[n+1][n+1];
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
		}
		for(int k=2;k<=n-1;k++){
			for(int i=1;i<=n-k;i++){
				int j=i+k;
				if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
				else if(s[i]>s[j] || s[i]<s[j])
					dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			}
		}
		cout << dp[n][n] << endl;
	}
	return 0;	
}