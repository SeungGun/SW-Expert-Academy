#include <stdio.h>
char s[1001];
char r[1001];
int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int l = 0;
		int j = 0;
		scanf("%s", s);
		int i = 0;
		while (s[i] != NULL) {
			i++;
		}
		l = i;
		l--;
		printf("#%d ", test_case);
		while (l >= 0) {
			if (s[l] == 'b') {
				r[j] = 'd';
			}
			else if (s[l] == 'd') {
				r[j] = 'b';
			}
			else if (s[l] == 'p') {
				r[j] = 'q';
			}
			else if (s[l] == 'q') {
				r[j] = 'p';
			}
			j++;
			l--;
		}
		r[j] = NULL;
		printf("%s", r);
		printf("\n");
	}
	return 0;
}