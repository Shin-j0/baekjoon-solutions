/*
[BOJ] 1753 - 최단 경로
https://www.acmicpc.net/problem/1753
- Algorithm: Dijkstra
- Data Structure: Priority Queue
- Time: O((V + E) log V)
- Space: O(V)
- Trick:
  *  다익스트라 알고리즘을 사용하여 시작 정점에서 각 정점까지의 최단 경로를 계산
  *  우선순위 큐를 사용하여 현재까지 발견된 최단 경로 중 가장 짧은 경로를 가진 정점을 효율적으로 선택
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, int>> v[20001];
int Dijk[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


void DijkStra() {
	while (!pq.empty()) {
	
		pair<int, int> nowNode = pq.top();
		pq.pop();

		int weightSum = nowNode.first;
		int node = nowNode.second;

		if (Dijk[node] < weightSum) continue;

		for (int i = 0; i < v[node].size(); i++) {
			int weight = v[node][i].first;
			int nextNode = v[node][i].second;

			if (Dijk[nextNode] > weight + weightSum) {
				Dijk[nextNode] = weight + weightSum;

				pq.push({Dijk[nextNode], nextNode});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, start;
    cin >> V >> E >> start;

    fill(Dijk, Dijk + V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, vtx, w;
        cin >> u >> vtx >> w;
        v[u].push_back({w, vtx});
    }

    pq.push({0, start});
    Dijk[start] = 0;

    DijkStra();

    for (int i = 1; i <= V; i++) {
        if (Dijk[i] == INF) cout << "INF\n";
        else cout << Dijk[i] << "\n";
    }
}