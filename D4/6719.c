#include <stdio.h>
#include <stdlib.h>
int com(int *a, int *b) {
	if (*a > *b)
		return -1;
	else
		return 1;
}
int main() {
	int N, K;
	double res = 0;
	int M[201] = { 0 };
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M[i]);
	}
	qsort(M, N, sizeof(int), com);

	for (int i = K - 1; i >= 0; i--) {
		res = (res + M[i]) / 2.0;
	}
	printf("result : %lf", res);
}