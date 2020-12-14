#include <stdio.h>
int matrix[1001][1001];
int CC[1001] = { 0 };
int nodes;
int visit[1001] = { 0 };
int queue[1001];
int front = -1;
int rear = -1;
void initQueue() {
	front = -1;
	rear = -1;
	for (int i = 0; i < nodes; i++) {
		queue[i] = 0;
		visit[i] = 0;
	}
}
int isEmpty() {
	if (front == rear)
		return 1;
	else
		return 0;
}
void enqueue(int index) {
	rear = (rear + 1) % nodes;
	queue[rear] = index;
}
int dequeue() {
	if (!isEmpty()) {
		front = (front + 1) % nodes;
		return queue[front];
	}
	else
		return -1;
}
int main() {
	scanf("%d", &nodes);
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < nodes; i++) {
		enqueue(i);
		visit[i] = 1;
		int level = 0;
		int count = 0;
		while (!isEmpty()) {
			int qSize = rear - front;
			count += level * qSize;
			for (int j = 0; j < qSize; j++) {
				int curr = dequeue();
				for (int k = 0; k < nodes; k++) {
					if (matrix[curr][k]) {
						if (!visit[k]) {
							visit[k] = 1;
							enqueue(k);
						}
					}
				}
			}
			level++;
		}
		initQueue();
		CC[i] = count;
	}
	int min = CC[0];
	for (int i = 1; i < nodes; i++) {
		if (min > CC[i]) {
			min = CC[i];
		}
	}
	printf("Min : %d", min);
}
