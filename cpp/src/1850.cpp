/*
[BOJ] 1850 - 최대공약수
https://www.acmicpc.net/problem/1850
- Algorithm: GCD
- Data Structure: Integer
- Time: O(N)
- Space: O(1)
- Trick:
  *  두 수의 최대공약수를 구한 후, 그 최대공약수만큼 '1'을 출력하면 됨
*/

#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long g = GCD(a, b);

    for (long long i = 0; i < g; i++) {
        cout << '1';
    }

    return 0;
}