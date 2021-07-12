#include<iostream>
#include<vector>
using namespace std;

bool a[10000];
int n,p,s;
vector<int> kq;
vector<vector<int> > KQ;
void Try(vector<int> v, int pos, int vt, int sum){
	int i;
	if(sum>s || pos>n) return;
	else if(sum==s && pos==n) KQ.push_back(kq);
	for( i=vt;i<v.size();i++){
		kq.push_back(v[i]);
		Try(v,pos+1,i+1,sum+v[i]);
		kq.pop_back();
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> s;
		vector<int> v;
		kq.clear();
		KQ.clear();
		for(int i=0;i<=s;i++) a[i]=true;
		a[0]=false;
		a[1]=false;
		for(int i=2;i<=s;i++){
			if(a[i]){
				for(int j=i*2;j<=s;j+=i) a[j]=false;
			}
		}
		for(int i=p+1;i<=s;i++){
			if(a[i]) v.push_back(i);
		}
		Try(v,0,0,0);
		cout << KQ.size() << endl;
		for(int i=0;i<KQ.size();i++){
			for(int j=0;j<KQ[i].size();j++)
			 	cout << KQ[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}