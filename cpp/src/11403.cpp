/*
[BOJ] 11403 - 경로 찾기
https://www.acmicpc.net/problem/11403
- Algorithm: BFS
- Data Structure: vector, queue
- Time: O(N^2)
- Space: O(N^2)
- Trick:
  * 
  * 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> answer(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int start = 0; start < n; ++start) {
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next = 0; next < n; ++next) {
                if (graph[cur][next] == 1 && !visited[next]) {
                    visited[next] = true;
                    answer[start][next] = 1;
                    q.push(next);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
