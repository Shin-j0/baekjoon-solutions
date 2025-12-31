#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <deque>

using namespace std;

int main(){
	int num;
	cin >> num;
	for(int x = 0; x<num; ++x){
		string str;
		int index_num, D_count;
		string index;
		bool reverse_bool = false;

		cin >> str >> index_num >> index;
		D_count = count(str.begin(), str.end(), 'D');

		if( index_num < D_count) {
			cout << "error"<<endl;
			continue;
		}
		deque<int> str_to_int;
		string temp;
		for (char c : index) {
			if (isdigit(c)) {
				temp += c;
			} else if (!temp.empty()) {
				str_to_int.push_back(stoi(temp));
				temp.clear();
			}
		}

		for(char c: str){
			if(c == 'R'){
				reverse_bool = !reverse_bool;
			}
			else{
				index_num--;
				if(reverse_bool)
					str_to_int.pop_back();
				else
					str_to_int.pop_front();
			}

		}
		if(reverse_bool)
			reverse(str_to_int.begin(),str_to_int.end());

		cout << '[';
		for (auto it = str_to_int.begin(); it != str_to_int.end(); ++it) {
			if (it != str_to_int.begin()) cout << ",";
			cout << *it;
		}
		cout << ']' << endl;
	}

    return 0;
}
