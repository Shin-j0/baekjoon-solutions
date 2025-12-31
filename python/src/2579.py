"""
[BOJ] 2579 - 계단 오르기
https://www.acmicpc.net/problem/2579
- Algorithm: Dynamic Programming
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
"""

n = int(input())
data = [0]*301
dp = [0]*301
for x in range(n): 
    data[x+1] = int(input())

dp[0] = 0
dp[1] = data[1]
dp[2] = data[1]+data[2]
dp[3] = max(data[1]+data[3],data[2]+data[3])

for x in range(4,n+1):
    dp[x] = max(dp[x-3]+data[x-1]+data[x],dp[x-2]+data[x])

print(dp[n])