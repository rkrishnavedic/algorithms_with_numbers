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

int32_t main(){

    int n, b;
    cin>>n>>b;

    map<int,int> pr;

    int k = b;
    for(int d=2;d*d<=k;d++){
        while(k%d==0){
            pr[d]++;
            k/=d;
        }
        // cout<<d<<";"<<pr[d]<<endl;
    }

    if(k>1) pr[k]++;

    map<int,int> cpr;

    for(int i=1;i<=n;i++){
        int k = i;
        for(auto x: pr){
            while(k%x.first==0){
                k/=x.first;
                cpr[x.first]++;
            }
            // cout<<x.first<<":"<<cpr[x.first]<<" ";
        }
    }

    int mn = 1e9;
    for(auto x: pr){
        mn = min(mn, cpr[x.first]/x.second);
    }


    cout<<mn<<endl;


    return 0;
}
