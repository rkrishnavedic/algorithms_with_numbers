#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long 
#define pb push_back

string removeleadingzeros(string a){
    string ans = a;
    while(ans.size()>1 and ans[ans.size()-1]=='0') ans.pop_back();
    return ans;
}

string decrement(string a){
    if(a=="0") return "-1";
    int n = a.size();
    if(a[n-1]!='0') {
        a[n-1]--;
        return a;
    }

    for(int i=n-1;i>=0;i--){
        if(a[i]!='0'){
            a[i]--;
            for(int j=i+1;j<n;j++){
                a[j]='9';
            }
            break;
        }
    }
    return a;
}

string stringsum(string a, string b){
    int rem = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a=removeleadingzeros(a);
    b=removeleadingzeros(b);

    string ans;
    for(int i=0;i<min(b.size(),a.size());i++){
        rem = rem+ (a[i]-'0')+(b[i]-'0');
        ans.pb((rem%10)+'0');
        rem/=10;
    }
    for(int j=min(a.size(),b.size());j<max(a.size(),b.size());j++){
        if(j<b.size()) rem+=(b[j]-'0');
        else rem+=(a[j]-'0');
        ans.pb((rem%10)+'0');
        rem/=10;
    }
    while(rem>0){
        ans.pb((rem%10)+'0');
        rem/=10;
    }

    ans = removeleadingzeros(ans);
    

    reverse(ans.begin(), ans.end());
    
    return ans;
}

string stringintmult(string a, int x){
    int rem = 0;
    reverse(a.begin(), a.end());
    a=removeleadingzeros(a);
    string ans;
    for(int i=0;i<a.size();i++){
        rem += (a[i]-'0')*x;
        ans.pb((rem%10)+'0');
        rem/=10;
    }
    while(rem>0){
        ans.pb((rem%10)+'0');
        rem/=10;
    }

    ans = removeleadingzeros(ans);
    reverse(ans.begin(), ans.end());

    return ans;
}

string stringmult(string a, string b){
    if(a.size()<b.size()) return stringmult(b,a);
    //a.size()>=b.size();
    reverse(b.begin(), b.end());

    string ans = "0";
    
    for(int i=0;i<b.size();i++){
        string t = stringintmult(a, b[i]-'0');
        for(int j=0;j<i;j++) t.pb('0');
        // cout<<t<<endl;
        ans = stringsum(t, ans);
        // cout<<ans<<endl;
    }

    return ans;
}

string rangemult(int l, int r){
    string ans="1";
    for(int i=l;i<=r;i++){
        ans = stringmult(ans, to_string(i));
    }

    return ans;
}

string solve(int n, int m){
    if(n==m) {
        return "0";
    }
    if(n<m) return "-"+solve(m,n);
    //n>=m

    string ans = decrement(rangemult(m+1,n));
    ans = stringmult(rangemult(1,m), ans);
    return ans;
}

int32_t main(){

    int n,m;cin>>n>>m;
    if(n+m==1){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<solve(n,m)<<endl;

    return 0;
}
