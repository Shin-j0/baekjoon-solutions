/*
[BOJ] 1541 - 잃어버린 괄호
https://www.acmicpc.net/problem/1541
- Algorithm: greedy
- Data Structure: String, Vector
- Time: O(N)
- Space: O(N)
- Trick:
  *  입력된 수식에서 '-' 연산자를 기준으로 분리
  *  각 분리된 부분에서 '+' 연산자를 사용하여 값을 더한 후, 첫 번째 부분을 제외한 나머지 부분들을 모두 빼줌으로써 최소값을 도출
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<string> v;    
    vector<int> num;
    string temp = "";
    for (char c : s) {
        if (c == '-') {
            v.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    v.push_back(temp);

    for(string &part : v) {
        string subTemp = "";
        int sum = 0;
        for(char c : part){
            if(c=='+'){
                sum+=stoi(subTemp);
                subTemp = "";
            }
            else subTemp+=c;
        }
        sum+=stoi(subTemp);
        num.push_back(sum);
    }
    int result = num[0];
    for (size_t i = 1; i < num.size(); i++) {
        result -= num[i];
    }
    cout << result << "\n";
    return 0;
}