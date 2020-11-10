#include <stdio.h>
int getLength(char *s) {
	int i = 0;
	while (s[i] != NULL) i++;
	return i;
}
int main() {
	char str[10001];
	char sub[10001];
	int main = 0;
	int s = 0;
	int i = 0;
	int j = 0;
	int cnt = 0;
	scanf("%s", str);
	scanf("%s", sub);

	while (str[i] != NULL) {
		if (str[i] == sub[j]) {
			while (sub[j] != NULL) {
				if (str[i] == sub[j]) {
					i++;
					j++;
				}
				else {
					break;
				}
			}
			if (sub[j] == NULL) {
				cnt++;
			}
			j = 0;
		}
		else {
			i++;
		}
	}
	main = getLength(str);
	s = getLength(sub);
	printf("%d", (main -cnt*s)+ cnt);
}

