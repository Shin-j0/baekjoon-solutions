/*
[BOJ] 14500 - 테트로미노
https://www.acmicpc.net/problem/14500
- Algorithm: DFS(4칸 경로 탐색) + 'ㅗ' 예외 처리
- Data Structure: 2D array, visited
- Time: O(N*M)+ T-check O(N*M)
- Space: O(N*M)
- Trick:
  * 'ㅗ' 모양은 DFS 경로로 만들 수 없어서 따로 체크
*/

#include<iostream>
using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int result = 0;
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        result = max(result, sum);
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

int check_T_shape(int x, int y){
    // 4가지 T 모양 확인
    int center = board[x][y];
    int max_shape = 0;
    // 위
    if(x - 1 >= 0 && y - 1 >= 0 && y + 1 < m){
        int sum = center + board[x-1][y] + board[x][y-1] + board[x][y+1];
        max_shape = max(max_shape, sum);
    }
    // 아래
    if(x + 1 < n && y - 1 >= 0 && y + 1 < m){
        int sum = center + board[x+1][y] + board[x][y-1] + board[x][y+1];
        max_shape = max(max_shape, sum);
    }
    // 왼쪽
    if(y - 1 >= 0 && x - 1 >= 0 && x + 1 < n){
        int sum = center + board[x][y-1] + board[x-1][y] + board[x+1][y];
        max_shape = max(max_shape, sum);
    }
    // 오른쪽
    if(y + 1 < m && x - 1 >= 0 && x + 1 < n){
        int sum = center + board[x][y+1] + board[x-1][y] + board[x+1][y];
        max_shape = max(max_shape, sum);
    }
    return max_shape;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            result = max(result, check_T_shape(i, j));
        }
    }
    cout << result << "\n";
}