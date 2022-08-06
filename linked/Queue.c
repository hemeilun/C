#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct Queue
{
    int data[MAXSIZE];
    int front,rear;
    int tag;
}Queue;



void initQueue(Queue *Q){
    
  Q->front = Q->rear = 0;
  Q->tag=0;
}


//入队
int Enqueue(Queue *Q , int e){

    //判断队是否已满
    if(Q->front == Q->rear && Q->tag == 1){
        return 0;
    }

    Q->rear = ((*Q).rear+1);
    Q->tag = 1;
    return 1;

}


//出队
int Delqueue(Queue *Q){


    if(Q->front == Q->data && Q->tag == 0){
        return 0;
    }
   // Q->front = (*(Q->front)+1)%MAXSIZE;
    Q->tag = 0;
    return 1;


}


int main(){

    Queue *Q = (Queue*)malloc(sizeof(Queue));
    initQueue(Q);

    for(int i = 0;i<11;i++){
    Enqueue(Q,i+1);
    }

    for (int i = 0; i < 3; i++)
    {
        Delqueue(Q);
    }

    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("%d  ",Q->data[i]);
    }
    
    

}

