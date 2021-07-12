#include<bits/stdc++.h>
using namespace std;

void MinNumber(int s, int d){
    stack<int> st;
    while(s>0){
        d--;
        if(s>9){
            st.push(9);
            s-=9;
        }else{
            st.push(s);
            break;
        }
    }
    if(d<0) cout << -1;
    else{
        if(d>0){
            int top=st.top(); st.pop();
            st.push(top-1);
            while(d>1){
                st.push(0);
                d--;
            }
            st.push(1);
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }
}
int main(){
    int test;
    cin >> test;
    while(test--){
        int s,d;
        cin >> s >> d;
        MinNumber(s,d);
        cout << endl;
    }
    return 0;
}