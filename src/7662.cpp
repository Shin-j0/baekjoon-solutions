#include<iostream>
#include<algorithm>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
unordered_map<int,int> cnt;

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		q1 = priority_queue<int>();
		q2 = priority_queue<int, vector<int>, greater<int>>();

		int m, count=0;
		cin >> m;

		for(int j=0; j<m; ++j){

			char s;
			int x;
			cin >> s >> x;
			switch(s){
				case 'I':
					cnt[x]++;
					q1.push(x);
					q2.push(x);
					count ++;
					break;
				case 'D':
					if(count==0) continue;
					if(q1.empty() || q2.empty()) continue;
					if(x==1){
						while(!q1.empty()&&cnt[q1.top()]==0) q1.pop();
						if(q1.empty() || q2.empty()) continue;
						cnt[q1.top()]--;
						q1.pop();
					}
					else{
						while(!q2.empty()&&cnt[q2.top()]==0) q2.pop();
						if(q1.empty() || q2.empty()) continue;
						cnt[q2.top()]--;
						q2.pop();
					}
					count--;
					break;
			}
		}
		while(!q1.empty()&&cnt[q1.top()]==0) q1.pop();
		while(!q2.empty()&&cnt[q2.top()]==0) q2.pop();
		if(q1.empty() || q2.empty()) cout<<"EMPTY"<<endl;
		else cout<<q1.top()<<" "<<q2.top()<<endl;
		cnt.clear();
	}
}
