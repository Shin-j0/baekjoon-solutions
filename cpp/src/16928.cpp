/*
[BOJ] 16928 - 뱀과 사다리 게임
https://www.acmicpc.net/problem/16928

- Algorithm: BFS
- Data Structure: Queue, Array
- Time: O(N)
- Space: O(N)

- Trick:
  * 각 칸(1~100)을 노드로 보고 주사위(1~6)를 간선으로 생각하는 그래프 문제
  * 모든 이동의 비용이 동일하므로 최단 이동 횟수는 BFS로 해결
  * 사다리/뱀은 도착 즉시 강제 이동 처리
  * 방문 배열(dist)을 사용해 처음 도달한 경우만 큐에 삽입
*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int ladder[101];
    int dist[101];
    fill(ladder,ladder+101,0);
    fill(dist,dist+101,1e9);

    for(int i=0; i<n+m; ++i){
      int temp;
      cin >> temp >> ladder[temp];
    }
    dist[0] = dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(int i=1; i<=6; ++i){
        int nc = cur + i;
        if(nc>100) continue;
        if(ladder[nc]) nc = ladder[nc];
        if(dist[cur]+1 > dist[nc]) continue;
        q.push(nc);
        dist[nc] = dist[cur]+1;
      }
    }
    cout<<dist[100];
}