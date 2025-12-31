#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> arr;
int blue = 0;
int white = 0;

bool isSameColor(int p,int q,int size){
	int color = arr[p][q];
	for(int i=p; i<p+size; ++i){
		for(int j=q; j<q+size; ++j){
			if(arr[i][j]!=color) return 0;
		}
	}
	return 1;

}

void partition(int p,int q,int size){

	if(isSameColor(p,q,size)){
		if(!arr[p][q]) {
			white++;
		}
		else {
			blue++;
		}
		return;
	}

	int newsize = size /2;

	partition(p,q,newsize);
	partition(p,q+newsize,newsize);
	partition(p+newsize,q,newsize);
	partition(p+newsize,q+newsize,newsize);
}

int main(){

    int n;
    cin >> n;
    arr.assign(n, vector<int>(n));

    for(int i=0;i<n;++i){
    	for(int j=0; j<n; ++j){
    		cin >> arr[i][j];
    	}
    }

    partition(0,0,n);
    cout<<white<<"\n"<<blue<<endl;
}
