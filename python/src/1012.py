"""
[BOJ] 1012 - 유기농 배추
https://www.acmicpc.net/problem/1012
- Algorithm: BFS
- Data Structure: Array
- Time: O(V+E)
- Space: O(V)
- Trick:
  * 
  * 
"""


from collections import deque
def bfs(arr,x,y):
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    q = deque()
    arr[y][x] = 0
    q.append((x,y))
    while q:
        nx, ny = q.pop()
        for i in range(4):
            a = nx+dx[i]
            b = ny+dy[i]
            if(0>a or a>=X or 0>b or b>=Y):
                continue
            if(arr[b][a]==1):
                q.append((a,b))
                arr[b][a] = 0



Test_N = int(input())

for _ in range(Test_N):
    data = input().split()
    X = int(data[0])
    Y = int(data[1])
    N = int(data[2])
    arr = [[0]*(X) for y in range(Y)]
    sum = 0
    
    for _ in range(N):
        A =  input().split()
        int_x = int(A[0])
        int_y = int(A[1])
        arr[int_y][int_x] = 1
    for y in range(Y):
        for x in range(X):
            if(arr[y][x]==1):
                bfs(arr,x,y)
                sum+=1
    print(sum)