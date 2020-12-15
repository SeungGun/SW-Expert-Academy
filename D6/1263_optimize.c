#include <stdio.h>
#define MAX_INDEX 1001
typedef struct node {
	int vertex;
	int level;
}Node;
Node queue[MAX_INDEX];
int visited[MAX_INDEX];
int matrix[MAX_INDEX][MAX_INDEX];
int front = -1;
int rear = -1;
int nodes;
void initQueue() {
	front = -1;
	rear = -1;
	for (int i = 0; i < nodes; i++) {
		visited[i] = 0;
	}
}
int isEmpty() {
	if (front == rear)
		return 1;
	else
		return 0;
}
void enqueue(int idx, int lvl) {
	rear = (rear + 1) % nodes;
	queue[rear].vertex = idx;
	queue[rear].level = lvl;
}
Node dequeue() {
	if (!isEmpty()) {
		front = (front + 1) % nodes;
		return queue[front];
	}
}
int main() {
	int min = 100000000;
	scanf("%d", &nodes);
	for (int i = 0; i < nodes; i++)
		for (int j = 0; j < nodes; j++)
			scanf("%d", &matrix[i][j]);

	for (int i = 0; i < nodes; i++) {
		initQueue();
		int count = 0;
		enqueue(i,0);
		visited[i] = 1;
		while (!isEmpty()) {
			Node curr = dequeue();
			count += curr.level;
			for (int j = 0; j < nodes; j++) {
				if (!visited[j] && matrix[curr.vertex][j]) {
						visited[j] = 1;
						enqueue(j, curr.level + 1);
				}
			}
		}
		if (min > count) min = count;
	}
	printf("min : %d", min);
}