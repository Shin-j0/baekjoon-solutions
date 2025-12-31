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
