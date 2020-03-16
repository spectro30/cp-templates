#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 100005
#include <bits/stdc++.h>
using namespace std;

/*
    Given range A to B: (B-A)<=1e5
    Prime Number in range of A to B
    Tested on LightOJ 1197
*/

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

//----------Sieve starts here-------------
bool marked[maxn];
void sieve(int n){
    for(int i=3;i*i<=n;i+=2){
        if(marked[i]) continue;
        for(int j=i*i;j<=n;j+=i+i){
            marked[j]=true;
        }
    }
}
bool isPrime(int n){
    if(n==2)return true;
    if(n<2 || n%2==0)return false;
    return !marked[n];
}
//----------------------------

bool visited[maxn];

vector<int> primes;

ll countPrime(ll a, ll b){
    ll res = 0;
    for(auto x: primes){
        ll cur = ((a+x-1)/x) * x;
        for(ll i=cur;i<=b;i+=x){
            if(visited[i-a] || i == x) continue;
            visited[i-a] = true;
        }
    }
    for(ll i=0;i<=b-a;i++){
        if( (a+i) == 1) continue;
        res += !visited[i];
    }
    return res;
}

int main(int argc, char const *argv[]) {
    sieve(100000);
    for(int i=1;i<=100000;i++){
        if(isPrime(i)) primes.pb(i);
    }
    int TC = read_int();
    for(int ii=1;ii<=TC;ii++){
        memset(visited, 0, sizeof visited);
        ll res = 0;
        ll a, b;
        a = read_int();
        b = read_int();
        res = countPrime(a, b);
        printf("Case %d: %lld\n", ii, res);
    }

    return 0;
}
