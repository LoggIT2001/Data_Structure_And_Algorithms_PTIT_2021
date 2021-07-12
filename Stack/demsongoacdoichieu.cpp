#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        stack<char> p;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]=='(' && p.size()==0){
                p.push(s[i]);
            }else{
                if(s[i]==')'){
                    if(p.size()>0 && p.top() == '('){
                        p.pop();
                    }else p.push(s[i]);
                }
            }
        }
        int d1=0,d2=0;
        while(p.size()>0){
            if(p.top()==')') d1++;
            else d2++;
            p.top();
        }
        cout << d1%2+d2%2+d1/2+d2/2 << endl;
    }
    return 0;
}