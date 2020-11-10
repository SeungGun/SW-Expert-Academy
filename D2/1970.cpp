#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		scanf("%d", &N);
		if (N % 10 != 0) N -= N % 10;
		int arr[8] = { 0 };
		printf("#%d\n", test_case);
		while (N > 0) {
			if (!(N % 50000)) { N -= 50000; arr[0]++; }
			else if (!(N % 10000)) { N -= 10000; arr[1]++; }
			else if (!(N % 5000)) { N -= 5000; arr[2]++; }
			else if (!(N % 1000)) { N -= 1000; arr[3]++; }
			else if (!(N % 500)) { N -= 500; arr[4]++; }
			else if (!(N % 100)) { N -= 100; arr[5]++; }
			else if (!(N % 50)) { N -= 50; arr[6]++; }
			else { N -= 10; arr[7]++; }
		}
		for (int i = 0; i < 8; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

	}
	return 0;
}