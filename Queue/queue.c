#include <stdilb.h>
#include <stdio.h>
#include <limits.h>

struct Queue
{
  int front,rear,size;
  unsigned capacity;
  int* array;
};

//function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity) {
  //memory allocation
  struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
  newQueue->capacity = capacity;
  newQueue->front = newQueue->size = 0;
  newQueue->rear = capacity -1;
  newQueue->array = (int*)malloc(sizeof(int)*newQueue->capacity);
  return newQueue;
}

int isFull(struct Queue* queue) {
  return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
  return (queue->size == 0);
}

//function to add an item to the queue
//it changes rear and size too
void enqueue(struct Queue* queue, int item) {
  if (isFull(queue))
    return
  queue->rear = (queue->rear + 1)%(queue->capacity);
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n",item);
}

//function to remove an item from queues
//It changes front and size
int dequeue(struct Queue* queue) {
  if(isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1)%queue->capacity;
  queue->size = queue->size -1;
  return item;
}

//function to get front of the queue
int front(struct Queue* queue) {
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}

//to get the rear
int rear(struct Queue* queue) {
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}

//driver program for testing

int main() {
  struct Queue* queue = createQueue(100);
  enqueue(queue,10);
  enqueue(queue,20);
  enqueue(queue,30);
  enqueue(queue,40);

  printf("%d dequeued from queue\n", dequeue(queue));

  printf("Front item is %d\n", front(queue));
  printf("Rear item is %d\n", rear(queue));

  return 0;
}
