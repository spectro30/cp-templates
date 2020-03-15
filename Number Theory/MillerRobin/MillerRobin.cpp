#define ll long long
#include<bits/stdc++.h>
using namespace std;



ll Mul(ll a,ll b,ll Mod) {
    ll Ans=0;
    while(b) {
        if(b&1) {
            Ans+=a;
            if(Ans>=Mod) Ans-=Mod;
        }
        a+=a;
        if(a>=Mod) a-=Mod;
        b>>=1;
    }
    return Ans;
}

ll bigMod(ll n,ll r,ll Mod) {
    if(r==0)
        return 1LL;
    ll ret=bigMod(n,r/2,Mod);
    ret=Mul(ret,ret,Mod);
    if(r%2==1)
        ret=Mul(ret,n,Mod);
    return ret;
}

//Miller-Rabin
bool witness(ll wit,ll n) {
    if(wit>=n) return false;

    int s=0;
    ll t=n-1;
    while(t%2==0) s++,t/=2;

    wit=bigMod(wit,t,n);
    if(wit==1 || wit==n-1) return false;

    for(int i=1; i<s; i++) {
        wit=Mul(wit,wit,n);
        if(wit==1) return true;
        if(wit==n - 1) return false;
    }
    return true;
}

//Is n prime?
bool miller(ll n){
    if(n==2) return true;
    if(n%2==0 || n<2) return false;
    if(witness(2,n) || witness(7,n) || witness(61,n)) return false;
    return true;
}
