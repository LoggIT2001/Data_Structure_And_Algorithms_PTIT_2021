#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
#define IN cin.tie(0)
#define OUT cout.tie(0)
//#define endl '/n'

/**********fuction**********/

void result(string s){
    string tmp;
    stack<int> st;
    for(int i=0;i<=s.size();i++){
        st.push(i+1);
        if(s[i]=='I' || i==s.size()){
            while(!st.empty()){
                tmp+=to_string(st.top());
                st.pop();
            }
        }
    }
    cout << tmp << endl;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        result(s);
    }
    return 0;
}