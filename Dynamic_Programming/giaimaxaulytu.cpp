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

/**********DTL**********/

string Solution(string s){
    stack<int> st;
    stack<char> sta;
    string tmp="";
    string res="";
    FOR(i,0,s.size()){
        int count=0;
        if(s[i]>=0 && s[i]<=9){
            while(s[i]>=0 && s[i]<=9){
                count=count*10 + (s[i]-'0');
                i++;
            }
            i--;
            st.push(count);
        }else if(s[i]==']'){
            tmp="";
            count=0;
            if(!st.empty()){
                count=st.top();
                st.pop();
            }
            while(!sta.empty() && sta.top()!='['){
                tmp=sta.top();
                sta.pop();
            }
            if(!sta.empty() && sta.top()=='['){
                sta.pop();
            }
            FOR(j,0,count){
                res=res+tmp;
            }
            FOR(j,0,res.length()){
                sta.push(res[i]);
            }
            res="";
        }else if(s[i]=='['){
            if(s[i-1]>=0 && s[i-1]<=9){
                sta.push(s[i]);
            }else{
                sta.push(s[i]);
                st.push(1);
            }
        }else{
            sta.push(s[i]);
        }
    }
    while(!sta.empty()){
        res=sta.top() + res;
        sta.pop();
    }
    return res;
}

/**********main function**********/

int main(){
    FastIO; IN; OUT;

    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << Solution(s) << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

string result(string str) {
    stack <int> numbers;
    stack <char> ch;

    string tmp = "", res = "";

    for (int i = 0; i < str.length(); i++) {
        int count = 0;

        if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            numbers.push(count);
        }

        else if (str[i] == ']') {
            tmp = "";
            count = 0;

            if (!numbers.empty()) {
                count = numbers.top();
                numbers.pop();
            }

            while (!ch.empty() && ch.top() != '[') {
                tmp = ch.top() + tmp;
                ch.pop();
            }
            
            if (!ch.empty() && ch.top() == '[')
                ch.pop();

            for (int j = 0; j < count; j++)
                res = res + tmp;

            for (int j = 0; j < res.length(); j++)
                ch.push(res[j]);

            res = "";
        }

        else if (str[i] == '[') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
                ch.push(str[i]);

            else {
                ch.push(str[i]);
                numbers.push(1);
            }
        }

        else 
            ch.push(str[i]);
    }

    while (!ch.empty()) {
        res = ch.top() + res;
        ch.pop();
    }

    // cout << res << endl;
    return res;
}

int main() {
    int t;
    string str;
    cin >> t;
    // cin.ignore();
    while (t--) {
        cin >> str;
        // result(str);
        cout << result(str) << endl;
    }
    return 0;
}
*/