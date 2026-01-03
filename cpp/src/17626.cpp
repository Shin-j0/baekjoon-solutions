/*
[BOJ] 17626 - Four Squares
https://www.acmicpc.net/problem/17626
- Algorithm: DP
- Data Structure: DP
- Time: O(N√N)
- Space: O(N)
- Trick:
  * dp[i] = i를 제곱수들의 합으로 표현할 때 필요한 최소 개수
  * dp[i] = min(dp[i - j*j] + 1) (j*j ≤ i)
  * 라그랑주 4제곱 정리에 의해 답은 최대 4

*/

#include <iostream>
using namespace std;
int dp[50001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = 1e9;
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << endl;
}