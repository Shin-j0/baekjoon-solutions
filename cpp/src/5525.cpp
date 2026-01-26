/*
[BOJ] 5525 - IOIOI
https://www.acmicpc.net/problem/5525
- Algorithm: string matching
- Data Structure: string
- Time: O(N)
- Space: O(N)
- Trick:
  *  문자열 매칭 알고리즘을 사용하여 패턴 "IOI"가 몇 번 연속으로 나타나는지 계산
*/
#include<iostream>
#include<string>
using namespace std;

/* 1차 코드 
int main(){
    int n;
    cin >> n;
    string ioi = "IOI";
    for(int i=1; i<n; ++i){
        ioi+="OI";
    }
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    size_t start = 0;
    while(1){
        size_t pos = s.find(ioi, start);
        if(pos == string::npos) break;
        count++;
        start = pos + 1;
    }
    cout << count << "\n";
}
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int count = 0;
    int c = 0;
   for(int i=1; i<m-1;++i){
        if(s[i-1] == 'I' && s[i] == 'O' && s[i+1] == 'I')
        {
            c++;
            if(c >= n) count++;
            i++;
        }
        else {
            c=0;
        }
    }
cout << count << "\n";
}