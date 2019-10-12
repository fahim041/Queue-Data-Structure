#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void* dataPtr;
    struct node* next;
} QUEUE_NODE;

typedef struct{
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
    int count;
}QUEUE;

int main();

QUEUE* createQueue(){
    QUEUE* queue = (QUEUE* )malloc(sizeof(QUEUE));
    if(queue){
        queue->front = NULL;
        queue->rear = NULL;
        queue->count =0;
    }
    return queue;
}

bool enqueue(QUEUE* queue, void* itemPtr){
    QUEUE_NODE* newPtr;
    newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if(!newPtr)
        return false;

    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;

    if(queue->count==0)
        queue->front = newPtr;
    else
        queue->rear->next = newPtr;

    (queue->count)++;
    queue->rear = newPtr;
    return true;
}

void insert(QUEUE* queue){
  bool done = false;
  int * dataPtr;
  while(!done){
      dataPtr = (int*)malloc(sizeof(int));
      printf("Enter numbers (-1 to end input):");
      scanf("%d", dataPtr);
      if((*dataPtr)== EOF){
          done = true;
      }
      else{
      enqueue(queue, dataPtr);
    }
  }
}

void dequeue(QUEUE* queue){
    void* dataOutPtr;
    QUEUE_NODE* temp;
    if(queue->count == 0){
      printf("Error!!NO queue has been created!Create a queue first and enter some data!\n\n");
      main();
    }
    else{
      temp = queue->front;
      dataOutPtr = queue->front->dataPtr;
      queue->front = queue->front->next;
      free(temp);
      (queue->count)--;
    }
    printf("Deleteing data--> %d\n", *(int*)dataOutPtr);
    //return dataOutPtr;
}

QUEUE* destroyQueue(QUEUE* queue){
  QUEUE_NODE* deletePtr;

  if(queue){
    while(queue->front != NULL){
      free(queue->front->dataPtr);
      deletePtr = queue->front;
      queue->front = queue->front->next;
      free(queue);
    }
  }
  return NULL;
}

void print(QUEUE_NODE* node, QUEUE* queue){
  if(queue->count == 0){
    printf("Error!!No data in the queue\n\n");
  }
  else{
  QUEUE_NODE* temp;
  temp = node;
  while(temp != NULL){
    printf("%d-->", *(int*)temp->dataPtr);
    temp = temp->next;
  }
  printf("\n\n");
 }
}

void queueTop(QUEUE* queue){
  if(queue->count ==0){
    printf("Error!!There is no data in the queue\n\n");
  }
  else{
    printf("Top data in the queue is: %d\n",*(int*)queue->front->dataPtr );
  }
}

void queueRear (QUEUE* queue){
  if(queue->count == 0){
    printf("Error!!There is no data in the queue\n\n");
  }
  else{
    printf("Rear data in the queue is:%d\n", *(int*)queue->rear->dataPtr);
  }
}

void queueCount(QUEUE* queue){
  if(queue->count == 0){
    printf("Error!!No data in the queue\n\n\n");
  }
  else{
    printf("Numbers of data in the queue is:%d\n\n",queue->count );
  }
}

int summ(QUEUE_NODE* node,QUEUE* queue){
  int sum =0;
  if(queue->count == 0){
    printf("Error!!There is no data in the queue\n\n");
  }
  else{
  QUEUE_NODE* temp;
  temp = node;
  while(temp != NULL){
    sum+= *(int*)temp->dataPtr;
    temp = temp->next;
  }
  printf("Sum of the given data in the queue is :%d\n\n", sum);
 }
  return sum;
}

void average(QUEUE_NODE* node,QUEUE* queue){
  if(queue->count == 0){
    printf("Error!!There is no data in the queue\n\n");
  }
  else{
  float avg;
  int sum = summ(node, queue);

  avg = sum / queue->count;

  printf("Average of the given data in the queue is:%.3f\n\n", avg);
 }
}

int main(){
  QUEUE* queue;
  queue = createQueue();
  int a;
  printf("Queue Application user interface--------->\n");
  while(1){
  printf("1.Push:\n");
  printf("2.Pop:\n");
  printf("3.Display:\n");
  printf("4.First data of the queue:\n");
  printf("5.Last data of the queue:\n");
  printf("6.Number of data in the queue:\n");
  printf("7.Sum of the data in the queue:\n");
  printf("8.Average of the data in the queue:\n");
  printf("9.Exit\n");

  printf("Enter your choice:\n");
  scanf("%d", &a);
  switch(a){
    case 1:
      insert(queue);
      break;

    case 2:
      dequeue(queue);
      break;

    case 3:
      print(queue->front, queue);
      break;

    case 4:
      queueTop(queue);
      break;

    case 5:
      queueRear(queue);
      break;

    case 6:
      queueCount(queue);
      break;

    case 7:
      summ(queue->front, queue);
      break;

    case 8:
      average(queue->front, queue);
      break;

    case 9:
      exit(1);
      break;

    default:
      printf("Please,Enter the current input-->\n\n");
    }
  }

}
