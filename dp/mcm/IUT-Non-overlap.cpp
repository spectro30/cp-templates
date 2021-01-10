// https://toph.co/p/non-overlapping-ranges/

#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int dp[maxn][maxn];
int A[maxn];

int rec(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(l>=r) return 0;
    if( (l+1) == r){
        if(A[l] == A[r]) return 1;
        return 0;
    }
    int mx = 0;
    for(int i=l+1;i<r;i++){
        mx = max(mx, rec(l, i) + rec(i, r));
    }
    if(A[l] == A[r]) mx ++;
    return dp[l][r] = mx;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--){
        memset(dp, -1, sizeof dp);
        memset(A, 0, sizeof A);
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &A[i]);
        }
        printf("%d\n", rec(0, n-1));
    }
}

