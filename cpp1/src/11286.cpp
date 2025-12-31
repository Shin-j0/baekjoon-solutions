#include<iostream>
#include<algorithm>
#include <queue>
#include <functional>

using namespace std;



int main(){
	int n;
	cin >> n;
	string sul = "";

	priority_queue<
	    pair<int,int>,
	    vector<pair<int,int>>,
	    greater<pair<int,int>>
	> pq;

	for(int i=0; i<n; ++i){
		int x;
		cin >> x;
		if(x==0){
			if(pq.empty()) sul+="0\n";
			else{
				sul+=to_string(pq.top().second)+"\n";
				pq.pop();
			}
		}
		else {
			if(x<0)
				pq.push({x*-1,x});
			else pq.push({x,x});
		}
	}
	cout << sul<<endl;
}
