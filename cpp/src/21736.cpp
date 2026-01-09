/*
[BOJ] 21736 - 헌내기는 친구가 필요해
https://www.acmicpc.net/problem/21736
- Algorithm: bfs, dfs
- Data Structure: Queue, Stack
- Time: O(V + E)
- Space: O(V)
- Trick:
  *  BFS 또는 DFS를 사용하여 시작 정점에서 각 정점까지의 최단 경로를 계산
  *  큐 또는 스택을 사용하여 방문한 정점을 효율적으로 관리 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m,0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == 'I') {
                graph[i][j] = 1; // 시작점 표시
                q.push({i, j});
            } else if(temp == 'O') {
                graph[i][j] = 1;
            } else if(temp == 'P') {
                graph[i][j] = 2; // 친구 표시
            }
            else {
                graph[i][j] = 0; // 벽 표시
            }
        }
    }
    int friend_count = 0;
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // 상하좌우 이동
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] != 0) {
                if(graph[nx][ny] == 1) {
                    graph[nx][ny] = -1; // 방문 표시
                    q.push({nx, ny});
                } else if(graph[nx][ny] == 2) {
                    graph[nx][ny] = -1; // 친구 방문 표시
                    friend_count++;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(friend_count == 0) cout << "TT" << endl;
    else{
        cout << friend_count << endl;
    }
}