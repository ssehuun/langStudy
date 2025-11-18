# 419. Battleships in a Board
# https://leetcode.com/problems/battleships-in-a-board/description/
# deque popleft => O(1), list pop(0) => O(n)

# Input1: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
# output1: 2
# Input2: board = [["."]]
# Output2: 0

from typing import List
from collections import deque

nx = [1, 0, -1, 0]
ny = [0, 1, 0, -1]
global chk_mat, m, n

class Solution:
    def bfs(self, y, x, board):
        q = deque()
        q.append((x, y))

        while len(q) > 0:
            sx, sy = q.popleft()
            # print("sx: ", sx, "sy: ", sy)
            chk_mat[sy][sx] = True

            if board[sy][sx] == ".":
                continue

            for i in range(4):
                x = sx + nx[i]
                y = sy + ny[i]
                # print("new x: ", x, "new y: ", y)
                if x < 0 or y >= m or y < 0 or x >= n:
                    continue
                if chk_mat[y][x] == False:
                    chk_mat[y][x] = True
                    q.append((x, y))

    def countBattleships(self, board: List[List[str]]) -> int:
        global chk_mat, m, n
        m = len(board) # y축
        n = len(board[0]) # x축
        cnt = 0
        chk_mat = [[False] * n for _ in range(m)]
        # print("chk_mat: ", chk_mat)
        for y in range(m):
            for x in range(n):
                # print("y: ", y, "x: ", x)
                if board[y][x] == "." or chk_mat[y][x] == True:
                    continue
                if board[y][x] == "X":
                    self.bfs(y, x, board)
                    cnt += 1
        return cnt
