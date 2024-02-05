# 2024-02-05
# 17143 낚시왕
# 이차원 배열에 내에서 특정 조건을 만족하는 상어를 잡는다
# https://velog.io/@sunkyuj/python-%EB%B0%B1%EC%A4%80-17143-%EB%82%9A%EC%8B%9C%EC%99%95 참고(cycle)

import sys

sys.setrecursionlimit(10 ** 8)

# 전역변수
row, col, sharks = 0, 0, 0
mat = []
sharklist = []

class Shark:
    def __init__(self, pos_r, pos_c, speed, dir, size):
        self.pos_r = pos_r
        self.pos_c = pos_c
        self.speed = speed
        self.dir = dir
        self.size = size

def fish(iter):

    # 해당 열에서 가장 가까운 애 삭제
    for i in range(row):
        if mat[i][iter] >= 0:
            del_shark = sharklist[mat[i][iter]]
            mat[i][iter] = -1

            return del_shark.size
    return 0

def move():
    global mat
    newMat = [ [ -1 for _ in range(col) ] for _ in range(row) ]

    for i in range(row):
        for j in range(col):
            if mat[i][j] >= 0:
                new_r, new_c = newPosition(sharklist[mat[i][j]])

                if newMat[new_r][new_c] >= 0:
                    if sharklist[mat[i][j]].size > sharklist[newMat[new_r][new_c]].size:
                        # 새로운 shark의 크기가 더 크다면 대체
                        newMat[new_r][new_c] = mat[i][j]

                else: 
                    newMat[new_r][new_c] = mat[i][j]
    
    mat = newMat

def newPosition(shark):
    global row, col, sharklist

    if shark.dir == 1 or shark.dir == 2:
        cycle = 2 * (row - 1)
        if shark.dir == 1: #UP
            speed = shark.speed + (2 * (row-1) - shark.pos_r)
        else: #DOWN
            speed = shark.speed + shark.pos_r 

        speed %= cycle

        if speed >= row:
            shark.pos_r = 2 * (row-1) - speed
            shark.dir = 1
        else:
            shark.pos_r = speed
            shark.dir = 2
        
    else: 
        cycle = 2 * (col - 1)
        if shark.dir == 3: #RIGHT
            speed = shark.speed + shark.pos_c
        else: #LEFT
            speed = shark.speed + (2 * (col-1) - shark.pos_c)
        
        speed %= cycle

        if speed >= col:
            shark.pos_c = 2 * (col-1) - speed
            shark.dir = 4
        else:
            shark.pos_c = speed
            shark.dir = 3

    return shark.pos_r, shark.pos_c

if __name__ == '__main__':
    total = 0

    row, col, sharks = map(int, input().split())
    mat = [[ -1 for _ in range(col) ] for _ in range(row)]

    # 상어 객체 생성 및 초기 위치 세팅
    for i in range(sharks):
        pos_r, pos_c, speed, dir, size = map(int, input().split())
        pos_r -= 1
        pos_c -= 1
        shark = Shark(pos_r, pos_c, speed, dir, size)
        sharklist.append(shark)

        mat[pos_r][pos_c] = i
        
    # 실행 함수
    for i in range(col):
        total += fish(i)
        move()
    
    
    print(total)

