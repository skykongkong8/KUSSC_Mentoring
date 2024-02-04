// 마법사 상어와 블리자드

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef enum e_dir {
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
} t_dir;

void blizzard(int dir, int s, int map[50][50], int n) { // dir 방향으로 거리 s 이하의 구슬 모두 파괴
	int shark = n / 2;
	if (dir == UP) { // (r,c)에서 {N / 2 - s <= c < N / 2}인 구슬 0으로 .. 하  
		for (int i = shark - s; i < shark; i++) {
			map[i][shark] = 0;
		}
	}
	else if (dir == DOWN) { // (r,c)에서 {N / 2 < c <= N / 2 + s}인 구슬 0으로
		for (int i = shark + 1; i <= shark + s; i++) {
			map[i][shark] = 0;
		}
	}
	else if (dir == LEFT) { // (r,c)에서 {N / 2 - s <= r < N / 2} 0으로
		for (int i = shark - s; i < shark; i++) {
			map[shark][i] = 0;
		}
	}
	else if (dir == RIGHT) { // (r,c)에서 {N / 2 < r <= N / 2 + s} 0으로
		for (int i = shark + 1; i <= shark + s; i++) {
			map[shark][i] = 0;
		}
	}
	else
		return ;
}

// 나선형 배열 1차원으로 바꾸는 코드 => 악 ㅠㅠ 블리자드해놓고 상어아닌데 0이 왜나와 !! 했는데 . . 구슬 사라졌었던거임
int *mapTo1D(int map[50][50], int n) {
	int *map1D = calloc(2500, sizeof(int));
	int idx = 0;
	int	i = n / 2;
	int j = n / 2;
	map1D[idx++] = map[i][j];

	int amount = 1;
	int dir = LEFT;

	while (amount < n) {
		if (dir == LEFT) {
			for (int count = 0; count < amount; count++) {
				j--;
				map1D[idx++] = map[i][j];
			}
			dir = DOWN;
		}
		else if (dir == DOWN) {
			for (int count = 0; count < amount; count++) {
				i++;
				map1D[idx++] = map[i][j];
			}
			dir = RIGHT;
			amount++;
		}
		else if (dir == RIGHT) {
			for (int count = 0; count < amount; count++) {
				j++;
				map1D[idx++] = map[i][j];
			}
			dir = UP;
		}
		else if (dir == UP) {
			for (int count = 0; count < amount; count++) {
				i--;
				map1D[idx++] = map[i][j];
			}
			dir = LEFT;
			amount++;
		}
	}
	return (map1D);
}

// 1차원을 2차원으로 바꾸는 함수도 만들귀 . . !
int **mapTo2D(int map[2500], int n) {
	int **map2D = calloc(50, sizeof(int *));
	int shark = n / 2;
	int dx = 0;
	int dy = 0;
	int dir = 1;
	return (map2D);
}

void move(int map1D[2500], int n) {
	for (int i = 0; i < n * n; i++) {
		if (map1D[i] == 0 && i != 0) {
			for (int j = i; j < n * n; j++) {
				map1D[j] = map1D[j + 1];
			}
		}
	}
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

void test_printMap1D(int map[2500], int n) {
	for (int i = 0; i < n * n; i++) {
		printf("%d", map[i]);
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
	printf("initial map in 2D\n");
	test_printMap(map, n);

	for (int i = 0; magic[i + 1]; i++) {
		int *map1D;
		blizzard(magic[i], magic[i + 1], map, n);
		map1D = mapTo1D(map, n);
		printf("\n\n\nmap changed into 1D\n");
		test_printMap1D(map1D, n);
		move(map1D, n);
		printf("\n\n\nmap after filling zero in 1D\n");
		test_printMap1D(map1D, n);		
		// explode(map, n);
		// update(map, n);
		free(map1D);
	}

	// printf("");

	return 0;
}