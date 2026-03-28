/*
[BOJ] 1309 - 동물원
https://www.acmicpc.net/problem/1309
- Algorithm: Dynamic Programming
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  *  동물원의 각 칸에 동물을 배치하는 경우의 수를 계산하기 위해, 세 가지 상태로 나누어 DP 배열을 정의
  *  DP[i][0]: i번째 칸에 동물이 없는 경우의 수
  *  DP[i][1]: i번째 칸에 왼쪽에 동물이 있는 경우의 수
  *  DP[i][2]: i번째 칸에 오른쪽에 동물이 있는 경우의 수
*/

#include <iostream>

using namespace std;

int main(){
    
}