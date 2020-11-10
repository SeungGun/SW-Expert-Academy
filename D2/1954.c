#include <stdio.h>
int snail[10][10] = { 0 };

void printIt(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", snail[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	int N;
	int floor_count = 0;
	int cur_num = 1;
	int state = 0;
	scanf("%d", &N);
	int i = 0, j = 0;
	while (cur_num-1 != N * N) {
		if (state == 0) {
			if (j + floor_count+1 == N) {
				state = 1;
				snail[i][j] = cur_num++;
				i++;
			}
			else {
				snail[i][j++] = cur_num++;
			}
		}
		else if (state == 1) {
			if (i + floor_count + 1 ==  N) {
				state = 2;
				snail[i][j] = cur_num++;
				j--;
			}
			else {
				snail[i][j] = cur_num++;
				i++;
			}
		}
		else if (state == 2) {
			if (N - j + floor_count == N) {
				state = 3;
				snail[i][j] = cur_num++;
				i--;
			}
			else {
				snail[i][j] = cur_num++;
				j--;
			}
		}
		else if (state == 3) {
			if (N - i + floor_count == N-1) {
				floor_count++;
				state = 0;
				snail[i][j] = cur_num++;
				j++;
			}
			else {
				snail[i][j] = cur_num++;
				i--;
			}
		}

	}
	printIt(N);

}