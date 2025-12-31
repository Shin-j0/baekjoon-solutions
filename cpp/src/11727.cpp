/*
[BOJ] 11727 - 2×n 타일링
https://www.acmicpc.net/problem/11727
- Algorithm: Dynamic Programming
- Data Structure: vector
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(1001,0);
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; ++i){
        dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
    }
    cout << dp[n];
}