#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 200005
#include <bits/stdc++.h>
using namespace std;

#define MX 100000100
long long marked[MX / 64 + 100];
int primes[5761558], primeCount;

void sieve_with_bit_masking(){

	for (long long i = 3; i*i <= MX; i += 2) {
		if(!(marked[i/64]&(1LL<<(i%64)))) {
			for(long long j = i * i; j <= MX; j += 2 * i) {
				marked[j/64] |= (1LL<<(j%64));
			}
		}
	}
	primes[primeCount++] = 2;
	for (long long i = 3; i <= MX; i += 2) {
		if(!(marked[i / 64] & (1LL << (i % 64)))) {
			primes[primeCount++] = i;
		}
	}
}
int main() {
    sieve_with_bit_masking();
    return 0;
}
