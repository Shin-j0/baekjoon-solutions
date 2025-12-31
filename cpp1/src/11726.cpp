#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    long long dp[1001] = {}, i=3;
    dp[1] = 1;
    dp[2] = 2;

    for(;i<=n;++i){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 10007;
    }
    cout << dp[n];
}
