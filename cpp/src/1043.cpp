#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int main(void){
	int person;
	int party;
	cin >> person >> party;
	int True_person_num;
	cin >> True_person_num;
	if(!True_person_num){
		cout << party <<endl;
		return 0;
	}
	bool True_person[person+1] = {0};
	int temp;
	for(int i = 0; i<True_person_num; ++i){
		cin >> temp;
		True_person[temp] = true;
	}
	int person_arr[party][person];



}
