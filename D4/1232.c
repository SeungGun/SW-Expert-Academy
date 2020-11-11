#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char val[5];
	int left_child;
	int right_child;
}Tree;
Tree trees[1000];
double CalcInorder(Tree t[], int index) {
	double operand1;
	double operand2;
	if (t[index].left_child == 0 && t[index].right_child == 0) {
		return (double)atoi(t[index].val);
	}
	operand1 = CalcInorder(t, t[index].left_child - 1);
	operand2 = CalcInorder(t, t[index].right_child - 1);
	switch (t[index].val[0]) {
	case '+':
		return operand1 + operand2;	
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	}
	return 0;
}
int main() {
	int node;
	scanf("%d", &node);
	int splitLength = 0;
	char query[20];
	int count = 0;
	for (int i = 0; i < node; i++) {
		if(i == 0)gets(query);
		gets(query);
		char *ptr = strtok(query, " ");
			while (ptr != NULL) {
				if(count == 1) strcpy(trees[i].val, ptr);
				if (count == 2) trees[i].left_child = atoi(ptr);
				else if (count == 3) trees[i].right_child = atoi(ptr);
				ptr = strtok(NULL, " ");
				count++;
			}
			if (count < 3) {
				trees[i].left_child = 0;
				trees[i].right_child = 0;
		}
			//printf("%s, %d, %d\n", trees[i].val, trees[i].left_child, trees[i].right_child);
			count = 0;
	}
	
	printf("%.0lf", CalcInorder(trees, 0));
}