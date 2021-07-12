#include<bits/stdc++.h>
using namespace std;

void dem(string s){
    stack<int> st;
    int count=0,xoa=0;
    for(int i=0;i<s.size();i++){
        if(st.size()==0){
            st.push(s[i]);
        }else if(st.top()=='[' && s[i]==']'){
            st.pop();
            xoa+=2;
        }else if(st.top()==']' && s[i]=='['){
            count+=st.size()+xoa;
            st.pop();
        }else if(s[i]=='['){
            st.push(s[i]);
        }else if(st.top()==']' && s[i]==']'){
            st.push(s[i]);
        }
        if(st.size()==0) xoa=0;
    }
    cout << count << endl;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        dem(s);
    }
    return 0;
}