#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> weight;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
class position{
public:
	int i,j;
	position(int i, int j): i(i), j(j) {}
};

int main(){
	int n,m;
	cin>>n>>m;
	graph.assign(n,vector<int>(m));
	weight.assign(n,vector<int>(m,1e9));

	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) graph[i][j] = s[j] - '0';

	}
	stack<position> stack;

	weight[0][0] = 1;
	stack.push(position(0,0));
	while(!stack.empty()){
		position cur = stack.top();
		stack.pop();

		for(int k=0;k<4;++k){
			int ni = cur.i + di[k];
			int nj = cur.j + dj[k];

			if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
			if(graph[ni][nj] == 0) continue;

			if(weight[ni][nj] > weight[cur.i][cur.j] + 1){
				weight[ni][nj] = weight[cur.i][cur.j] + 1;
				stack.push(position(ni,nj));

			}
		}
	}
	cout << weight[n-1][m-1] << endl;
}
