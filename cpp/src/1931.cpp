#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Time{
public:
	int start;
	int end;
	int dif;
};
int compare1(Time t1, Time t2){
	return t1.end>t2.end;
}

int compare2(Time t1, Time t2){
	return t1.start>t2.start;
}

int main(){

	int num;
	cin >> num;
	vector<Time> vec;
	Time temp;
	int start, count = 1;
	for(int i = 0; i<num; ++i){
		cin >> temp.start >>temp.end;
		temp.dif = temp.end - temp.start;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),compare1);
	sort(vec.begin(),vec.end(),compare2);

	start=vec[0].start;
	for(int i = 1; i<num; ++i){
		if(start >= vec[i].end){
			start = vec[i].start;
			count++;
		}
	}
	cout << count <<endl;


}
