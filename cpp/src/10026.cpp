#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

int n;
vector<string> g0,g1;
vector<vector<int>> visit;

void dfs(int i,int j,const vector<string>&g){
	visit[i][j] = 1;
	char color = g[i][j];
	for(int dir=0;dir<4;++dir){
		int ni = i + di[dir];
		int nj = j + dj[dir];
		if(ni < 0 || ni >= n || nj<0 || nj >= n) continue;
		if(visit[ni][nj] || g[ni][nj]!=color) continue;

		dfs(ni,nj,g);
	}
}

int countArea(const vector<string>&g){
	int cnt = 0;
	visit.assign(n,vector<int>(n,0));
	for(int i=0;i<n;++i) for(int j=0;j<n;++j){
			if(!visit[i][j]){
				cnt++;
				dfs(i, j, g);
			}
	}
	return cnt;
}

int main(){
	cin >> n;
	g0.assign(n,"");
	g1.assign(n,"");

	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		g0[i] = s;
		g1[i] = g0[i];
		for(char &c:g1[i])
			if(c=='G') c ='R';
	}

	cout<<countArea(g0)<<" "<<countArea(g1)<<endl;

}

/* 
bfs로 구현

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

int bfs(const vector<string>& g){
	int n = g.size();
	vector<vector<int>> v(n,vector<int>(n,0));
	int cnt = 0;
	for(int si=0;si<n;++si) for(int sj=0;sj<n;++sj){
		if(v[si][sj]) continue;
		queue<pair<int,int>> que;
		cnt++;
		que.push({si,sj});
		v[si][sj]=1;
		char color = g[si][sj];

		while(!que.empty()){
			pair<int,int> cur = que.front(); que.pop();
			for(int dir=0;dir<4; ++dir){
				int ni = cur.first + di[dir];
				int nj = cur.second + dj[dir];
				if(ni < 0 || ni >= n || nj<0 || nj >= n) continue;
				if(v[ni][nj] || g[ni][nj]!=color) continue;
				v[ni][nj] = 1;
				que.push({ni,nj});
			}
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	vector<string> v1(n);
	vector<string> v2(n);

	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		v1[i] = s;
		v2[i] = v1[i];
		for(char &c:v2[i])
			if(c=='G') c ='R';
	}

	cout<<bfs(v1)<<" "<<bfs(v2)<<endl;

}
*/