#include <iostream>
#include <vector>
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

    int n;cin>>n;

    seive[0]=1;
    for(int i=2;i<N;i++){
        if(!seive[i]) {
            for(int j=2*i;j<N;j+=i){
                seive[j]=1;
            }
        }
    }

    int ans = 0;

    for(int j=0;j<1e3;j++){
        if(n-j>=1 and checkPrime(n-j)) ans = n-j;
        if(checkPrime(n+j)) ans = n+j;
        if(ans) break;
    }

    cout<<ans<<endl;

    return 0;
}
