#define maxn 105
#include<bits/stdc++.h>
int dp[maxn][maxn], arr[maxn];

using namespace std;

int Merge(int beg, int ed){
    int res = arr[ed] - arr[beg-1];
    res += 100;
    res %= 100;
    return res;
}

int rec(int beg, int ed){
    if(beg>=ed) return 0;
    if(dp[beg][ed] != -1) return dp[beg][ed];
    //cout << beg << " " << ed << endl;
    dp[beg][ed] = INT_MAX;
    for(int i=beg;i<ed;i++){
        dp[beg][ed] = min(dp[beg][ed], rec(beg, i) + rec(i+1, ed) + Merge(beg, i) * Merge(i+1, ed));
        //cout << dp[beg][ed] << endl;
    }

    return dp[beg][ed];
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(arr, 0, sizeof arr);
        memset(dp, -1, sizeof dp);
        for(int i=1;i<=n;i++){
            scanf("%d", &arr[i]);
            arr[i] += arr[i-1];
            arr[i] %= 100;
        }
        printf("%d\n", rec(1, n));
    }
    return 0;
}
