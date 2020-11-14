#include <stdio.h>
#include <stdlib.h>
int com(const int* a, const int *b) {
	if (*a > *b) return 1;
	if (*a < *b) return -1;
}
int main(void)
{
	int t, T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		int p;
		scanf("%d", &p);
		printf("#%d ", t);
		int a[50];
		for (int i = 0; i < p; i++) scanf("%d", &a[i]);
		qsort(a, p, sizeof(int), com);
		printf("%d\n", a[0] * a[p - 1]);
	}
	return 0;
}