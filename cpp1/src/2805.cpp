#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int low,hi,ans;
    low = hi = ans = 0;
    vector<int> arr(n);

    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(hi<arr[i])
        	hi = arr[i];
    }


    while(low <= hi){
    	int mid = low + (hi-low)/2;
    	long long num = 0;
    	for(int i:arr)
    		if(i>mid) num += i-mid;

    	if(num>=m){
    		ans = mid;
    		low = mid +1;
    	}
    	else hi = mid -1;

    }
    cout<<ans;

    return 0;
}
