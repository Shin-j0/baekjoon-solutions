#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int dk[] = {1,-1};
int n,m,f;

class position{
public:
	int i,j,k;
	position(int i,int j,int k):i(i),j(j),k(k){}
};


int main(){
	vector<vector<vector<int>>> graph;
	queue<position> que;
	int x,y,z;
	cin >> x >> y >> z;
	graph.assign(z, vector<vector<int>>(y, vector<int>(x)));
	for(int i=0; i<z;++i){
		for(int j=0; j<y; ++j){
			for(int k=0; k<x; ++k){
				cin>>graph[i][j][k];
				if(graph[i][j][k]==1)
					que.push(position(i,j,k));
			}
		}
	}
	int count = 0;
	while(!que.empty()){
		position cur = que.front();
		que.pop();
		for(int i=0; i<4; ++i){
			int nk = cur.k + di[i];
			int nj = cur.j + dj[i];
			if(nk<0 || nk>=x ||nj<0 || nj>=y ) continue;
			if(graph[cur.i][nj][nk]!=0) continue;
			graph[cur.i][nj][nk] = graph[cur.i][cur.j][cur.k]+1;
			que.push(position(cur.i,nj,nk));
		}
		for(int i=0; i<2; ++i){
			int ni = cur.i + dk[i];
			if(ni<0||ni>=z) continue;
			if(graph[ni][cur.j][cur.k]!=0) continue;
			graph[ni][cur.j][cur.k] = graph[cur.i][cur.j][cur.k]+1;
			que.push(position(ni,cur.j,cur.k));
		}

	}
	int max = 0;
	for(int i=0; i<z;++i){
		for(int j=0; j<y; ++j){
			for(int k=0; k<x; ++k){
				if(!graph[i][j][k]){
					cout<<-1<<endl;
					return 0;
				}
				max = max<graph[i][j][k]? graph[i][j][k]:max;
			}
		}
	}
	cout << max-1 <<endl;
}
