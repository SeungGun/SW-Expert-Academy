#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree{
	char alphabet;
	int left_chd;
	int right_chd;
	int index;
}Tree;
void inorder(Tree r[],int idx) {
	if (r[idx].left_chd != 0) 
		inorder(r, r[idx].left_chd - 1);

	printf("%c", r[idx].alphabet);
	
	if (r[idx].right_chd != 0) 
		inorder(r, r[idx].right_chd - 1);
}
int getLength(char *s) {
	int i = 0;
	while (s[i] != NULL) {
		i++;
	}
	return i;
}
int splitQ(char *s) {
	int i = 0;
	int count = 0;
	int empty = 1;
	while (s[i] != NULL) {
		if (s[i] == ' ') {
			empty = 1;
		}
		else if (empty) {
			empty = 0;
			count++;
		}
		i++;
	}
	return count;
}
int main() {
	int N;
	Tree root[100];
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char one[3];
		char two[3];
		char three[3];
		char four[3];
		char query[100];
		if (i == 0) {
			gets(query);
		}
		gets(query);
		int k = 0;
		int state = 0;
		int z = 0;
		while (query[k] != NULL) {
			if (query[k] == ' ') {
				if (state == 0) one[z] = NULL;
				else if (state == 1) two[z] = NULL;
				else if (state == 2) three[z] = NULL;
				else four[z] = NULL;
				state++;				
				z = 0;
				k++;
			}
			if (state == 0) {
				one[z] = query[k];
			}
			else if (state == 1) {
				two[z] = query[k];
			}
			else if (state == 2) {
				three[z] = query[k];
			}
			else if(state = 3){
				four[z] = query[k];
			}
			z++;
			k++;
		}
		four[z] = NULL;
		int l = splitQ(query);
		root[i].alphabet = two[0];
		root[i].index = i+1;
		if (l == 4) {
			root[i].left_chd = atoi(three);
			root[i].right_chd = atoi(four);
		}
		else if (l == 3) {
				root[i].left_chd =atoi(three);
				root[i].right_chd = 0;
		}
		else {
			root[i].left_chd = 0;
			root[i].right_chd = 0;
		}
	}
	
	inorder(root,0);
	
}