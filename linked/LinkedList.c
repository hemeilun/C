#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedNode
{
    int data;
    struct LinkedNode * next;
}LinkedNode,*LinkedList;


//尾插法
void tailInsert(LinkedList L , int arr[] , int len){

    LinkedNode *tailPoint = L;

    for (int i = 0; i < len; i++)
    {
        LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
        node->next = NULL;
        node->data = arr[i];

        tailPoint->next = node;
        tailPoint = node;

    }
    
}


//打印链表
void printLinkedList(LinkedList L){

  LinkedNode* node = L->next;
  while(node!=NULL){
     printf("%d  ",node->data);
     node = node->next;
  }
  printf("\n");

}


//从尾到头输出一个链表
void oneProblem(LinkedList L){


    LinkedNode* p = L->next;  //用于从前到后遍历链表
    LinkedNode* temp;
    
    if(p!=NULL){
        temp=p;
        p=p->next;
        temp->next=NULL;
        }

    while(p!=NULL){
        LinkedNode* s = (LinkedNode*)malloc(sizeof(LinkedNode));
        s->next = L->next;
        s->data = p->data;
        L->next = s;

        temp = p;
        p = p->next;
        free(temp);

    }

    printLinkedList(L);

}


//6
void sixProblem(LinkedList L){


    //pre的作用是当前遍历节点在排序列表中对应位置的前驱节点
    //r的作用是遍历节点
    LinkedNode *p = L->next ,*pre,*r;
    if(p!=NULL){
         r=p->next;
    }

    p->next=NULL;
    p=r;

    while(p!=NULL){
        r=p->next;
        pre = L;
        while(pre->next!=NULL && p->data>pre->next->data ){
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p=r;
    }


    printLinkedList(L);


}



//10
void tenProblem(LinkedList L){
      LinkedNode *pre = L;
      LinkedNode *p = L->next;

      LinkedList B = (LinkedList)malloc(sizeof(LinkedNode));
      LinkedNode *tailB = B;

      while(p!=NULL){
          if(p->data%2==0){
             pre->next = p->next;
             tailB->next = p;
             p->next = NULL;
             tailB = tailB->next; 
             p=pre->next;

          }else{
             p=p->next;
             pre=pre->next;
          }
      }

      printLinkedList(L);
      printLinkedList(B);
}


int main(){

  //初始化头节点
  LinkedNode* L = (LinkedNode*)malloc(sizeof(LinkedNode));   //头节点
  L->next = NULL;

  int arr[7] = {2,4,1,2,11,7,10};
  int len = sizeof(arr) / sizeof(int);
  tailInsert(L,arr,len);

  printLinkedList(L);

  //oneProblem(L);

  //sixProblem(L);

  tenProblem(L);

}

