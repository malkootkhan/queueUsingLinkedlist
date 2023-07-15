
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* basic queue implementation using likned list in C */
/*
basic queue implementation using linked list in C
File: Main.c
Author: Malkoot Khan
Date: 15/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Node {
	int data;
	struct Node* next;
};
struct Queue {
	struct Node* front;
	struct Node* rear;
};
bool isEmpty(struct Queue *q) {
	return q->rear == NULL;
}
struct Node* createNode(int dataItem) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = dataItem;
	temp->next = NULL;
	return temp;
}
void insert(struct Queue *q, int dataItem) {
	struct Node* newNode = createNode(dataItem);
	if (isEmpty(q)) {
		q->rear = newNode;
		q->front = newNode;
		return;
	}
	q->rear->next = newNode;
	q->rear = newNode;

}
void deleteFront(struct Queue *q) {
	if (isEmpty(q)) {
		printf("The queue is empty!\n");
		return;
	}
	struct Node* temp = q->front;
	q->front = temp->next;
	free(temp);
}
int getFront(struct Queue *q) {
	if (isEmpty(q)) {
		printf("The queue is empty!\n");
		return -1;
	}
	return q->front->data;
}
int getRear(struct Queue *q) {
	if (isEmpty(q)) {
		printf("The queue is empty!\n");
		return -1;
	}
	return q->rear->data;

}
void releaseMem(struct Queue *q) {
	while(!isEmpty(q))
		deleteFront(q);
}
void display(struct Queue *q){
	if (isEmpty(q)) {
		printf("The queue is empty!\n");
		return;
	}
	struct Node* temp = q->front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {

	struct Queue q;
	q.front = NULL;
	q.rear = NULL;

	insert(&q, 12);
	insert(&q, 13);
	insert(&q, 14);
	insert(&q, 15);
	display(&q);
	deleteFront(&q);
	display(&q);
	printf("Front: %d\n", getFront(&q));
	printf("Rear: %d\n", getRear(&q));
	return 0;
}

