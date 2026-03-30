/*
[BOJ] 1987 - 알파벳
https://www.acmicpc.net/problem/1987

- Algorithm: Backtracking / DFS
- Data Structure: 2D Array, Set
- Time: O(2^(R*C))
- Space: O(R*C)

- Trick:
  * 알파벳이 26개로 제한되어 있으므로, 방문한 알파벳을 비트마스크로 관리할 수 있다.
  * DFS로 이동하면서 현재까지 방문한 알파벳을 비트마스크로 표현한다.
  * 각 단계에서 이동할 수 있는 방향으로 이동하면서, 해당 알파벳이 이미 방문한 알파벳인지 확인한다.
  * 최대 이동 거리를 갱신하면서 DFS를 진행한다.
*/
#include <iostream>
#include <vector>

using namespace std;

int R,C;
char board[20][20];
bool visited[26];
int maxDist = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y, int dist){
    maxDist = max(maxDist, dist);
    for(int i=0; i<4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
        int alphaIndex = board[nx][ny] - 'A';
        if(visited[alphaIndex]) continue;
        visited[alphaIndex] = true;
        dfs(nx, ny, dist+1);
        visited[alphaIndex] = false;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxDist << "\n";
    return 0;
}
