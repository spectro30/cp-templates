#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define maxn 1000006
#define mod 998244353
using namespace std;


ll read_int(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg)
        return ret;
    else
        return -ret;
}



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



int main(){
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        ll x = read_int();
        if(miller(x)) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
