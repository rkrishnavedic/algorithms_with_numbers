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

    int p, q;
    cin>>p>>q;
    int d = gcd(p,q);
    p /=d;
    q /=d;

    if(p%q==0) cout<<p/q<<endl;
    else{
        map<int,int> mp;
        int left = p/q;
        int rem = p%q;
        string s;
        int st = -1;
        while(rem>0){
            if(mp[rem]){
                st = mp[rem]-1;
                break;
            }
            s+='0'+(rem*10)/q;
            mp[rem] = s.size();
            rem = (rem*10)%q;
        }

        if(st==-1){
            cout<<left<<"."<<s<<endl;
        }
        else{
            cout<<left<<"."<<s.substr(0,st)<<"("<<s.substr(st, s.size())<<")"<<endl;
        }
    }


    return 0;
}
