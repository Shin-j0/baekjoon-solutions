/*
[BOJ] 9019 - DSLR
https://www.acmicpc.net/problem/9019
- Algorithm: BFS
- Data Structure: Queue, String
- Time: O(N)
- Space: O(N)
- Trick:
  *  BFS를 사용하여 숫자를 변환하는 과정을 탐색
  *  각 숫자에 대해 D, S, L, R 연산을 적용하여 다음 상태로 이동
  *  목표 숫자에 도달할 때까지 BFS 탐색을 진행
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool visited[10000];

int D(int n) {
    return (2 * n) % 10000;
}
int S(int n) {
    return (n == 0) ? 9999 : n - 1;
}
int L(int n) {
    return (n % 1000) * 10 + n / 1000;
}
int R(int n) {
    return (n % 10) * 1000 + n / 10;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int A, B;
        cin >> A >> B;

        fill(visited, visited + 10000, false);
        queue<pair<int, string>> q;
        q.push({A, ""});
        visited[A] = true;
        while(!q.empty()){
            int cur = q.front().first;
            string cmd = q.front().second;
            q.pop();

            if(cur == B){
                cout << cmd << "\n";
                break;
            }

            int d = D(cur);
            if(!visited[d]){
                visited[d] = 1;
                q.push({d, cmd + "D"});
            }
            
            int s = S(cur);
            if(!visited[s]){
                visited[s] = 1;
                q.push({s, cmd + "S"});
            }

            int l = L(cur);
            if(!visited[l]){
                visited[l] = 1;
                q.push({l, cmd + "L"});
            }

            int r = R(cur);
            if(!visited[r]){    
                visited[r] = 1;
                q.push({r, cmd + "R"});
            }
        }
    }
    return 0;
}