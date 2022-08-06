#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode* next;
}LinkedStackNode,*LinkedStackList;


/**
 * @brief 初始化一个栈
 * 
 * @return LinkedStackList 返回初始化的栈
 */
LinkedStackList initStack(){

    LinkedStackList L = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    L->next = NULL;
    return L;
}


/**
 * @brief 压栈
 * 
 * @param L 要加数据的栈
 * @param e 要加的数据
 */
void push(LinkedStackList L,int e){

  LinkedStackNode* addData = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
  addData->data = e;
  addData->next = L->next;
  L->next = addData;

}

/**
 * @brief 出栈
 * 
 * @param L 
 * @return int  返回出栈元素的值 
 */
int pop(LinkedStackList L){
    
    if(L->next == NULL){
        //printf("栈为空");
        return -1;
    }

    LinkedStackNode* p = L->next;
    L->next = L->next->next;

    int e = p->data;

    //如果先free会导致空指针异常
    free(p);
    return e;
}


/**
 * @brief 返回栈顶元素
 * 
 * @param L 
 * @return int 返回-1表示栈为空，返回其他表示栈不空
 */
int stackTop(LinkedStackList L){

    if(L->next == NULL){
        //printf("栈为空");
        return -1;
    }

    return L->next->data;
    
}

/**
 * @brief 判断栈是否为空
 * 
 * @param L 
 * @return int 当返回值为0时，栈为空，否则栈不空
 */
int isStackEmpty(LinkedStackList L){

    if(L->next == NULL){
        //printf("栈为空");
        return 0;
    }else{
        return 1;
    }
    
}











