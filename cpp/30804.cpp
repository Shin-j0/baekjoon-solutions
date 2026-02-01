/*
[BOJ] 30804 - 과일 탕후루
https://www.acmicpc.net/problem/30804

- Algorithm: Two Pointer (Sliding Window)
- Data Structure: Array, Map(or Count Array)
- Time: O(N)
- Space: O(N)

- Trick:
  * 연속된 구간에서 서로 다른 과일의 종류가 최대 2개가 되도록 유지
  * 오른쪽 포인터를 늘리며 윈도우 확장
  * 과일 종류가 3개 이상이 되면 왼쪽 포인터를 이동시키며 축소
  * 항상 "서로 다른 과일 ≤ 2개" 조건을 만족하는 최대 길이를 갱신
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> fruits(N);
    for (int i = 0; i < N; ++i) {
        cin >> fruits[i];
    }

    int left = 0, right = 0;
    int maxLength = 0;
    int count[200001] = {0};
    int distinctCount = 0;

    while(right < N){
        if(count[fruits[right]] == 0){
            distinctCount++;
        }
        count[fruits[right]]++;
        right++;
        while(distinctCount > 2){
            count[fruits[left]]--;
            if(count[fruits[left]] == 0){
                distinctCount--;
            }
            left++;
        }
        maxLength = max(maxLength, right - left);
    }

    cout << maxLength << "\n";
    return 0;
}