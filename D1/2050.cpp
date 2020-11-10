#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int i = 0;
	char a[201];
	scanf("%s", a);
	while (a[i] != NULL) {
		printf("%d ", a[i++] - 'A' + 1);
	}
	return 0;
}