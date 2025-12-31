#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> graph;
vector<int> numHouse;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
class position{
public:
	int i,j;
	position(int i,int j):i(i),j(j){}
};

void Print(int n){
	for(int i=0; i<n;++i){
		for(int j=0; j<n; ++j){
			cout<<graph[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

void bfs(int i, int j,int n){
	position start(i,j);
	queue<position> q;
	q.push(start);
	int cnt = 1;
	graph[i][j] = 0;
	while(!q.empty()){
		position cur = q.front();
		q.pop();
		for(int i=0; i<4; ++i){
			int ni,nj;
			ni = cur.i + di[i];
			nj = cur.j + dj[i];
			if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
			if(graph[ni][nj]==0) continue;
			graph[ni][nj] = 0;
			cnt++;
			q.push(position(ni,nj));
			//Print(n);
		}
	}
	numHouse.push_back(cnt);
}

int main(){
	int n;
	cin >> n;
	graph.assign(n,vector<int>(n));
	for(int i = 0; i<n; ++i){
		string s;
		cin >> s;
		for(int j=0; j<n; ++j)
			graph[i][j] = s[j]-'0';
	}

	int count=0;
	for(int i=0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			if(graph[i][j]==1){
				bfs(i,j,n);
				count++;
			}
		}
	}
	sort(numHouse.begin(), numHouse.end());
	cout<<count<<endl;
	for(int i=0 ;i<count; ++i)
		cout<<numHouse[i]<<endl;
}
