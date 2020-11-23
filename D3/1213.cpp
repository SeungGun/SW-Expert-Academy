#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		char sub[11];
		char main[1001];
		int N;
		int count = 0;
		int i = 0, j = 0;
		scanf("%d", &N);
		scanf("%s", sub);
		scanf("%s", main);
		while (main[i] != NULL) {
			if (main[i] == sub[j]) {
				while (sub[j] != NULL) {
					if (main[i] == sub[j]) {
						i++;
						j++;
					}
					else break;
				}
				if (sub[j] == NULL) {
					count++;
				}
				j = 0;
			}
			else {
				i++;
			}
		}
		printf("#%d %d\n", test_case, count);
	}
	return 0;
}