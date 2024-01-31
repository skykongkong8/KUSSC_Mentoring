// 마법사 상어와 블리자드

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main () {
	int	n;
	int m;
	scanf("%d %d", &n, &m);
	// N은 항상 홀수, (r, c)는 격자의 r행 c열. 
	// 격자의 가장 왼쪽 윗 칸은 (1, 1), 가장 오른쪽 아랫 칸은 (N, N)
	// 1, 2, 3번 구슬. 같은 번호 구슬이 연속하는 칸에 있으면, 연속하는 구슬. 
	// 블리자드 방향 : wsad, 정수 1234로 표기
	// 블라자드 거리 s 이하인 모든 칸의 구슬 파괴. 벽은 파괴 x
	// => 블리자드 마법 함수

	// 빈 칸 생기면 옆 칸 구슬 모두 이동 => 이동 함수
	// 연속하는 구슬 4개 이상 시 폭발 => 폭발 함수
	// 다시 이동, 다시 폭발, ..

	int map[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int 
	for (int i = 0; i < m; i++) {
		scanf("%d %d", )
	}

	int sharkX = n / 2;
	int sharkY = n / 2;

	for (int i = 0; i < m; i++) {
		
	}

	return 0;
}