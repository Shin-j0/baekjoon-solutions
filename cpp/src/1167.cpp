/*
[BOJ] 1167 - 트리의 지름
https://www.acmicpc.net/problem/1167

- Algorithm: Tree DFS/BFS (Two-phase search)
- Data Structure: Adjacency List (vector<pair<int,int>>), Queue/Recursion
- Time: O(V)
- Space: O(V)

- Trick:
  * 트리의 지름은 "아무 정점에서 가장 먼 정점 A"를 찾고,
    A에서 다시 "가장 먼 정점까지의 거리"를 구하면 그 값이 지름이 된다.
  * 1) 임의의 노드(보통 1)에서 DFS/BFS → 가장 먼 노드 A
    2) A에서 DFS/BFS → 최대 거리 = 트리의 지름
  * 간선에 가중치가 있으므로 거리 누적을 함께 관리한다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> tree[100001];
int dist[100001];
bool visited[100001];

pair<int,int> bfs(int start){
    fill(visited, visited+100001,false);
    fill(dist, dist+100001,0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    pair<int,int> Max = {dist[start],start};
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0;i<tree[cur].size();++i){
            int v = tree[cur][i].first;
            int w = tree[cur][i].second;
            if(visited[v]) continue;
            visited[v] = true;
            dist[v] = dist[cur]+w;
            if(dist[v]>Max.first) {
                Max.first = dist[v];
                Max.second = v;
            }
            q.push(v);
        }
    }
    return Max;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        int u,v,w;
        cin >> u;
        for(;;){
            cin >> v;
            if(v==-1) break;
            cin >> w;
            tree[u].push_back({v,w});
        }
    }
    
    auto [d1, A] = bfs(1);
    auto [diameter, B] = bfs(A);
    cout << diameter << "\n";
}