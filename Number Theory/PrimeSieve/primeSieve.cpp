#include<bits/stdc++.h>
#define maxn 1000006
#define ll long long
using namespace std;

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

int main(){
    sieve(100);
    vector<int> v;
    for(int i=1;i<=100;i++){
        if(isPrime(i)) v.push_back(i);
    }
    for(auto x: v) cout << x << endl;
}

