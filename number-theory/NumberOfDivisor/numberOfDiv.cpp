#define ll long long
#define maxn 1000005
#include<bits/stdc++.h>
using namespace std;


/*  No of Divisor in O(N^(1/3))
    O(N^(1/3)) Memory
    primes[] = primes up to n^(1/3)

    call sieve()
    save primes

*/

bool marked[maxn];
vector<ll> primes;


void sieve(){
    for(int i=3;i*i<=1000000;i+=2){
        if(marked[i]) continue;
        for(int j=i*i;j<=1000000;j+=i+i){
            marked[j] = true;
        }
    }
}

bool isPrime(ll x){
    if(x == 2) return true;
    if(x < 2 || (x%2) == 0) return false;
    return !marked[x];
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

ll noOfDiv(ll num){
    ll res = 1;
    for(auto x: primes){
        ll cnt = 1;
        while(num%x == 0){
            cnt ++;
            num /= x;
        }
        res *= cnt;
    }
    ll x = sqrt(num);
    if(miller(num)) res *= 2;
    else if((x*x) == num && miller(x)) res *= 3;
    else if(num != 1) res *= 4;

    return res;
}


