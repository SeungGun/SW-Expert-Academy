#include <stdio.h>
#define TEST_CASE 10
int getMin(int a[]) {
	int min = a[0];
	for (int i = 1; i < 4; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	return min;
}
int main() {
	int b[1000];
	int com[4];
	int N;
	int result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 2; i < N - 2; i++) {
		if ((b[i] > b[i - 1] && b[i] > b[i - 2]) && (b[i] > b[i + 1] & b[i] > b[i + 2])) {
			com[0] = b[i] - b[i - 1];
			com[1] = b[i] - b[i - 2];
			com[2] = b[i] - b[i + 1];
			com[3] = b[i] - b[i + 2];
			result += getMin(com);
		}
	
	}
	printf("%d", result);

}