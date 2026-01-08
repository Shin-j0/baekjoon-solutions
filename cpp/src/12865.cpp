/*
[BOJ] 12865 - 평범한 배낭
https://www.acmicpc.net/problem/12865
- Algorithm: Dynamic Programming
- Data Structure: Vector
- Time: O(N * K)
- Space: O(K)
- Trick:
  *  다이나믹 프로그래밍을 사용하여 배낭 문제를 해결
  *  각 물건을 고려하면서 배낭의 무게 제한에 따라 최대 가치를 계산
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        int W, V;
        cin >> W >> V;
        for (int w = K; w >= W; --w) {
            dp[w] = max(dp[w], dp[w - W] + V);
        }
    }

    cout << dp[K] << "\n";
    return 0;
}