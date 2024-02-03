// 마법사 상어와 블리자드

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void blizzard(int dir, int s, int map[50][50], int n) { // dir 방향으로 거리 s 이하의 구슬 모두 파괴
	int shark = n / 2;
	if (dir == 1) { //w -> (r,c)에서 {N / 2 - s <= c < N / 2}인 구슬 0으로 .. 하  
		for (int i = shark - s; i < shark; i++) {
			map[i][shark] = 0;
		}
	}
	else if (dir == 2) { //s -> (r,c)에서 {N / 2 < c <= N / 2 + s}인 구슬 0으로
		for (int i = shark + 1; i <= shark + s; i++) {
			map[i][shark] = 0;
		}
	}
	else if (dir == 3) { //a -> (r,c)에서 {N / 2 - s <= r < N / 2} 0으로
		for (int i = shark - s; i < shark; i++) {
			map[shark][i] = 0;
		}
	}
	else if (dir == 4) { //d -> (r,c)에서 {N / 2 < r <= N / 2 + s} 0으로
		for (int i = shark + 1; i <= shark + s; i++) {
			map[shark][i] = 0;
		}
	}
	else
		return ;
}

int *mapTo1D(int map[50][50], int n) {
	int *map1D = calloc(2500, sizeof(int));
	int shark = n / 2;
	int idx = 0;

	// 나선형 배열 1차원으로 바꾸는 코드
	// 1차원을 2차원으로 바꾸는 함수도 만들귀 . . ! 

	return (map1D);
}

void move(int map1D[2500], int n) {

}

void explode(int map1D[2500], int n) {

}

void update(int map1D[2500], int n) {

}

void test_printMap(int map[50][50], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main () {
	int	n; // 3 <= n <= 49, 항상 홀수
	int m; // 1 <= m <= 100
	scanf("%d %d", &n, &m);

	// 1, 2, 3번 구슬. 같은 번호 구슬이 연속하는 칸에 있으면, 연속하는 구슬.

	// 맵을 해체했다 재조립하기 ? 어차피 N 알면 구슬개수 알자늠 (초기 격자에서 0 빼야함 !)

	// 빈 칸 생기면 옆 칸 구슬 모두 이동 => 이동 함수
	// 연속하는 구슬 4개 이상 시 폭발 => 폭발 함수
	// 다시 이동, 다시 폭발, ..

	// 구슬 재분배

	int map[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int magic[200]; // ㅎㅎㅎ 매직 짝수번째 인덱스는 방향 홀수번째 인덱스는 거리 !! ♡
	for (int i = 0; i < m * 2; i++) {
		scanf("%d", &magic[i]);
	}

	for (int i = 0; magic[i + 1]; i++) {
		int *map1D;
		blizzard(magic[i], magic[i + 1], map, n);
		map1D = mapTo1D(map, n);
		move(map, n);
		explode(map, n);
		update(map, n);
	}

	// test_printMap(map, n);
	// printf("");

	return 0;
}