#include<iostream>
#include<algorithm>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int> pq;

int main(){
	int n;
	cin >> n;
	string sul = "";
	pq = priority_queue<int>();
	for(int i=0; i<n; ++i){
		int x;
		cin >> x;
		if(x==0){
			if(pq.empty()) sul+="0\n";
			else{
				sul+=to_string(pq.top())+"\n";
				pq.pop();
			}
		}
		else pq.push(x);
	}
	cout << sul<<endl;
}
