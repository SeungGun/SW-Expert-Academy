#include <stdio.h>
int main() {
	int farm[50][50];
	int N;
	int result = 0;
	int j = 0;
	int differ = 0;
	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			scanf("%1d", &farm[a][b]);
		}
	}
	for (int i = 0; i < N; i++) {
		differ = 2 * (i + 1) - 1;
		if (i == 0|| i == N-1) {
			j = N / 2;
			result += farm[i][j];
		}
		else {
			if (differ > N) {
				for (int k = i-j; k < 2*N - 2*j - i + j-1; k++) {
					result += farm[i][k];
				}
			}
			else {
				for (int k = j - i; k < j + i + 1; k++) {
					result += farm[i][k];
				}
			}
			printf("\n");
		}
		printf("%d", result);
	}
}