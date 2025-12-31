"""
[BOJ] 1697 - 숨바꼭질
https://www.acmicpc.net/problem/1697
- Algorithm: BFS
- Data Structure: Array
- Time: O(V+E)
- Space: O(V)
- Trick:
  * 
  * 
"""


from collections import deque
def BFS():
    q = deque()
    q.append(n)
    while q:
        x = q.popleft()
        if(x==k): 
            print(arr[x])
            break
        for nx in (x-1,x+1,x*2):
            if(0 <= nx <= max and not arr[nx]):
                arr[nx] = arr[x] + 1
                q.append(nx) 

n,k = map(int,input().split())

max = 10**5
arr = [0]*(max+1)
BFS()