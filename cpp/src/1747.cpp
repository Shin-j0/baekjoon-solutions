/*
[BOJ] 1747 - 소수 팰린드롬
https://www.acmicpc.net/problem/1747
- Algorithm: Prime, Palindrome
- Data Structure: Integer
- Time: O(N * sqrt(N))
- Space: O(1)
- Trick:
  *  홀수 자리 팰린드롬만 생성하여 소수 판별
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// x를 이용해 홀수 자리 팰린드롬 생성
int makePalindrome(int x) {
    int result = x;
    x /= 10;  // 가운데 숫자는 중복되면 안 되니까 마지막 자리 제거

    while (x > 0) {
        result = result * 10 + (x % 10);
        x /= 10;
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    // 한 자리 소수들 먼저 처리
    int smallPrimes[] = {2, 3, 5, 7, 11};
    for (int p : smallPrimes) {
        if (p >= N) {
            cout << p << '\n';
            return 0;
        }
    }

    // 홀수 자리 팰린드롬만 생성
    // 짝수 자리 팰린드롬은 11을 제외하면 모두 11의 배수이므로 소수가 될 수 없음
    for (int i = 1; ; i++) {
        int pal = makePalindrome(i);

        if (pal >= N && isPrime(pal)) {
            cout << pal << '\n';
            return 0;
        }
    }

    return 0;
}