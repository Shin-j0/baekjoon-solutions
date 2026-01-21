/*
[BOJ] 1043 - 거짓말
https://www.acmicpc.net/problem/1043
- Algorithm: BFS
- Data Structure: Queue, vector
- Time: O(N*M)
- Space: O(N*M)
- Trick:
  *  진실을 아는 사람과 파티를 양방향 그래프로 보고 BFS로 전파.
  *  어떤 파티든 진실 아는 사람이 포함되면 그 파티는 진실 파티가 되고, 그 파티 참석자 모두가 진실을 알게 됨.
  *  방문 표시 후 남은 파티 수가 거짓말을 칠 수 있는 파티 개수.
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	int True_person_num;
	cin >> True_person_num;
	bool True_person[n+1];
	fill(True_person, True_person + n + 1, false);
	if(!True_person_num){
		cout << m <<endl;
		return 0;
	}
	queue<int> q;
	for(int i=0; i<True_person_num; ++i){
		int tp;
		cin >> tp;
		True_person[tp] = true;
		q.push(tp);
	}
	vector<int> party[m];
	for(int i=0; i<m; ++i){
		int party_num;
		cin >> party_num;
		party[i].resize(party_num);
		for(int j=0; j<party_num; ++j){
			cin >> party[i][j];
		}
	}
	bool visited_party[m];
	fill(visited_party, visited_party + m, false);
	while(!q.empty()){
		int cur_person = q.front();
		q.pop();
		for(int i=0; i<m; ++i){
			if(visited_party[i]) continue;

			bool isExist = false;

			for(int j=0; j<party[i].size(); ++j){
				if(party[i][j] == cur_person){
					isExist = true;
					break;
				}
			}

			if(isExist){
				visited_party[i] = true;
				for(int j=0; j<party[i].size(); ++j){
					int next_person = party[i][j];
					if(!True_person[next_person]){
						True_person[next_person] = true;
						q.push(next_person);
					}
				}
			}
		}
	}
	int result = 0;
	for(int i=0; i<m; ++i){
		if(!visited_party[i]) result++;
	}
	cout << result << endl;
}
