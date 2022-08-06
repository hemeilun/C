#include<stdio.h>
#include<stdlib.h>
#include"LinkedStackTree.c"




typedef struct QueueNode
{
    treeNode* data;
    struct QueueNode* next;
}LinkedQueueNode,*LinkedQueueList;


/**
 * @brief 初始化一个队列
 * 
 * @return LinkedQueueList 
 */
LinkedQueueList initQueue(){
    
    LinkedQueueList L = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    L->next = NULL;
    return L;
}


/**
 * @brief 入队
 * 
 * @param L 
 * @param e 要添加的数据
 */
void enQueue(LinkedQueueList L,treeNode* e){

    LinkedQueueNode* addData = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    addData->data = e;
    addData->next = NULL;

    LinkedQueueNode * queueHead = L;
    while(queueHead->next!=NULL){
        queueHead = queueHead->next;
    }
    queueHead->next = addData;

}


/**
 * @brief 出队
 * 
 * @param L 
 * @return int 
 */
treeNode* deQueue(LinkedQueueList L){
    if(L->next == NULL){
        return NULL;
    }

    LinkedQueueNode* p = L->next;
    L->next = L->next->next;

    treeNode* e = p->data;
    free(p);

    return e;
}


/**
 * @brief 返回队首元素
 * 
 * @param L 
 * @return int 
 */
treeNode* queueTop(LinkedQueueList L){
    if(L->next == NULL){
        return NULL;
    }

    return L->next->data;
}


/**
 * @brief 判断队列是否为空
 * 
 * @param L 
 * @return int 返回0时，表示队列为空，返回1时，队列不为空
 */
int isQueueEmpty(LinkedQueueList L){
    if(L->next == NULL){
        return 0;
    }else{
        return 1;
    }
}





