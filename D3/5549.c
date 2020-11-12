#include <stdio.h>
int getLength(char *s) {
	int i = 0;
	while (s[i] != NULL) {
		i++;
	}
	return i;
}
int main() {
	char num[101];
	scanf("%s", num);
	int length = getLength(num);
	
	if ((int)num[length - 1] % 2 != 0) {
		printf("ODD");
	}
	else {
		printf("EVEN");
	}
}