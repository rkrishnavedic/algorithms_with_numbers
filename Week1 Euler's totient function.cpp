#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long 
#define pb push_back

int gcd(int a, int b){
    if(a<b) swap(a,b);
    return b==0? a: gcd(a%b, b);
}

int modexp(int a, int p, int mod){
    if(p<=0) return 1;
    int res = modexp(a, p/2, mod);
    int ans = (int)res*res;
    ans%=mod;
    if(p%2==1) ans = (ans*a)%mod;

    return ans;
}

int32_t main(){

    int n,m,p;cin>>n>>m>>p;
    map<int,int> pr;

    for(int i=1;i<=n;i++){
        int k=i;
        for(int d=2;d*d<=k;d++){
            while(k%d==0){
                pr[d]++;
                k/=d;
            }
        }
        if(k>1) pr[k]++;
    }

    for(int i=1;i<=m;i++){
        int k=i;
        for(int d=2;d*d<=k;d++){
            while(k%d==0){
                pr[d]--;
                k/=d;
            }
        }
        if(k>1) pr[k]--;
    }
    for(int i=1;i<=n-m;i++){
        int k=i;
        for(int d=2;d*d<=k;d++){
            while(k%d==0){
                pr[d]--;
                k/=d;
            }
        }
        if(k>1) pr[k]--;
    }

    int ans = 1;

    for(auto x: pr){
        if(x.second){
            int el = modexp(x.first, x.second-1, p);
            ans = ((long long)ans*((long long)el*x.first - el)%p)%p;
        }
    }

    cout<<ans<<endl;


    return 0;
}
