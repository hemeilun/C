#include"adjacencyList.c"

typedef struct StackNode
{
    Vertex * data;
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
void push(LinkedStackList L,Vertex * e){

  LinkedStackNode* addData = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
  addData->data = e;
  addData->next = L->next;
  L->next = addData;

}

/**
 * @brief 出栈
 * 
 * @param L 
 * @return Vertex *  返回出栈元素的值 
 */
Vertex * pop(LinkedStackList L){
    
    if(L->next == NULL){
        //prVertex *f("栈为空");
        return NULL;
    }

    LinkedStackNode* p = L->next;
    L->next = L->next->next;

    Vertex * e = p->data;

    //如果先free会导致空指针异常
    free(p);
    return e;
}


/**
 * @brief 返回栈顶元素
 * 
 * @param L 
 * @return Vertex * 返回-1表示栈为空，返回其他表示栈不空
 */
Vertex * stackTop(LinkedStackList L){

    if(L->next == NULL){
        //prVertex *f("栈为空");
        return NULL;
    }

    return L->next->data;
    
}

/**
 * @brief 判断栈是否为空
 * 
 * @param L 
 * @return int 当返回值为0时，栈为空，否则栈不空
 */
int  isStackEmpty(LinkedStackList L){

    if(L->next == NULL){
        //prVertex *f("栈为空");
        return 0;
    }else{
        return 1;
    }
    
}











