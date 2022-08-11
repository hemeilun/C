//#include"LinkedStackTree.c"
#include"LinkedQueueTree.c"


//递归实现中序遍历
void midOrder(treeNode *t)
{
     if(t!=NULL){
         midOrder(t->lchild);
         printf("%d ",t->data);
         midOrder(t->rchild);
     }
}

//递归实现后序遍历
void postOrder(treeNode *t)
{
     if(t!=NULL){
         postOrder(t->lchild);
         postOrder(t->rchild);
         printf("%d ",t->data);
     }
}


//非递归方式实现中序遍历
void midOrderNonrecursive(treeNode *t){
  
   LinkedStackList L = initStack();
   treeNode *p = t;

   while( p || isStackEmpty(L)){

       //如果p不为空，就往左子树找
      if(p){
          push(L,p);
          p=p->lchild;
      }else{
          p = pop(L);   
          printf("%d ",p->data);
          p=p->rchild;
      }
   }

}



//非递归方式实现后序遍历
void postOrderNonrecursive(treeNode *t){
  
    LinkedStackList L = initStack();

    treeNode *p = t;
    treeNode *r = NULL;  //指向刚出栈的节点

    while( p || isStackEmpty(L)){

       //先左 
       if(p){
           push(L,p);
           p = p->lchild;

           //进行到else就说明以p为根节点的左子树都被访问完了，所以只能向右走
       }else{

           p = stackTop(L);

           //后右
           //只要栈顶节点有右子树且未被访问就会向右走一步
           if(p->rchild && p->rchild != r){
               p = p->rchild;
           }else{
               //再根
               //由于是后序遍历，所以是先左后右再根，当走到这个里面时，说明栈顶元素的左右子树都已经被访问完了
               p = pop(L);
               printf("%d ",p->data);
               r = p;
               p = NULL;     //p已经被访问完了，回到先前的节点
           }
       }
    }
}




//找到一个节点的所有祖先,利用后序遍历
void findOnesAncestor(treeNode *t,int x){

    LinkedStackList L = initStack();
    treeNode *p = t;
    treeNode *r = NULL;  //指向刚出栈的节点

    while(p !=NULL || isStackEmpty(L)){
        if(p){

             push(L,p);
             p = p->lchild;

        }else{
            p = stackTop(L);

            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }else{
                p = pop(L);
                if(p->data == x){
                //    printf("%d ",x);
                   while (isStackEmpty(L)){
                    printf("%d ",pop(L)->data);
                   }
                   break;
                }
                r=p;
                p=NULL; 
            }
        }
    }


}





//层次遍历
void hierarchicalTraversal(treeNode *t){

    LinkedQueueList L = initQueue();
    treeNode *p = t;

    enQueue(L,p);

    while(isQueueEmpty(L)){

        p = deQueue(L);
        printf("%d ",p->data);

        if(p->lchild){
            enQueue(L,p->lchild);
        }
        if(p->rchild){
            enQueue(L,p->rchild);
        }

    }
}





//非递归方式计算树的高度
//采用层次遍历的方式，每次遍历记录一次层中节点的数量，每在队列中出队对应数量高度加1
int heightNonrecursive(treeNode *t){

    if(!t){
        return 0;
    }

    LinkedQueueList L = initQueue();
    int num = 1;       //记录每一层节点的数量
    int height = 0;    //记录树的高度
    int tempnum = 0;   //临时记录每一层的节点数
    treeNode *p = t;
    enQueue(L,p);

    while(isQueueEmpty(L)){


        height++;
        for (int i = 0; i < num; i++)
        {
            p = deQueue(L);

            if(p->lchild){
                enQueue(L,p->lchild);
                tempnum++;
            }
            if(p->rchild){
                enQueue(L,p->rchild);
                tempnum++;
            }
            
        }
        
        num = tempnum;
        tempnum = 0;

    }

    return height;


}



//递归方式计算树的高度
int height(treeNode *t){

   if(t==NULL){
    return 0;
   }

   int leftHeight = height(t->lchild);
   int rightHeight = height(t->rchild);

   return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
}




void midAndPreToTreeAccomplish(int l,int r,treeNode*t,int tag,int *pre,int *mid,int *index);

//给定一个前序，一个中序均放在数组中，构造一棵树
treeNode* midAndPreToTree(int *pre,int lenp,int *mid,int lenm){

    //初始化树

    if(lenp==0){
        return NULL;
    }

    treeNode *t = (treeNode*)malloc(sizeof(treeNode));
    t->data = pre[0];
    t->lchild = t->rchild = NULL;

    int index=1;  //遍历前序所需的索引

    for (int i = 0; i < lenm; i++)
    {
        if(pre[0] == mid[i] ){
            midAndPreToTreeAccomplish(0,i-1,t,1,pre,mid,&index);
            midAndPreToTreeAccomplish(i+1,lenm-1,t,2,pre,mid,&index);
            break;
        }
    }
    
    return t;
}


/**
 * @brief 具体实现
 * 
 * @param l      记录数组最左边的序号
 * @param r 
 * @param t     
 * @param tag    当为1时，表明左子树，2时，表明右子树
 * @param pre 
 * @param mid 
 * @param index  遍历pre的索引
 */
void midAndPreToTreeAccomplish(int l,int r,treeNode*t,int tag,int *pre,int *mid,int *index){

    // if(l>r){
    //     return;
    // }

    for (int i = l; i <= r; i++)
    {
        if(pre[(*index)] == mid[i]){
            treeNode *p= (treeNode*)malloc(sizeof(treeNode));
            p->data = pre[*index];
            p->lchild = p->rchild = NULL;
           if(tag == 1){   
               t->lchild = p;
           }else{
               t->rchild = p;
           }
           *index = *index + 1;

           midAndPreToTreeAccomplish(l,i-1,p,1,pre,mid,index);
           midAndPreToTreeAccomplish(i+1,r,p,2,pre,mid,index);
           break;
        }
    }
    

}





//交换一颗树的全部左右子树
void swabChildTree(treeNode *t){
    if(t == NULL){
        return;
    }

    swabChildTree(t->lchild);
    swabChildTree(t->rchild);

    if(t->lchild!=NULL || t->rchild!=NULL){
        treeNode *temp = t->lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
    }


}





//求先序遍历的第k个数对应的值
int preOrderForK(treeNode *t,int k,int *i){
    

        if(!t){
            return 0;
        }

        *i = *i + 1;
        if(*i == k){
            return t->data;
        }

        int mm = preOrderForK(t->lchild,k,i);
        if(mm != 0){
           return mm;
        }

        return preOrderForK(t->rchild,k,i);
    
}

   


//满二叉树的后序转为先序
void postToPre(int *post,int tstart,int tend,int *pre,int estart,int eend){
    int half;
    if(tstart <= tend){
        pre[estart] = post[tend];
        half = (tend - tstart) / 2 ;
        postToPre(post,tstart,tstart+half-1,pre,estart+1,estart+half);
        postToPre(post,tstart+half,tend-1,pre,estart+half+1,eend); 
    }
}







//判断两棵树是否相似
int isTwoTreeSimlar(treeNode *t1,treeNode *t2){

   if(t1!=NULL&&t2!=NULL){

       int tt = isTwoTreeSimlar(t1->lchild,t2->lchild);
       if(tt != 1){
            return tt;
       }
       return isTwoTreeSimlar(t1->rchild,t2->rchild);
   }else if(t1 == NULL && t2 == NULL){
       return 1;
   }else{
       return 0;
   }

}







int main(){

    treeNode* node1 = (treeNode*)malloc(sizeof(treeNode));
    node1->data = 1;
    node1->lchild = node1->rchild = NULL;

    treeNode* node2 = (treeNode*)malloc(sizeof(treeNode));
    node2->data = 2;
    node2->lchild = node2->rchild = NULL;
    
    treeNode* node3 = (treeNode*)malloc(sizeof(treeNode));
    node3->data = 3;
    node3->lchild = node3->rchild = NULL;

    treeNode* node4 = (treeNode*)malloc(sizeof(treeNode));
    node4->data = 4;
    node4->lchild = node4->rchild = NULL;
 
    treeNode* node5 = (treeNode*)malloc(sizeof(treeNode));
    node5->data = 5;
    node5->lchild = node5->rchild = NULL;

    treeNode* node6 = (treeNode*)malloc(sizeof(treeNode));
    node6->data = 6;
    node6->lchild = node6->rchild = NULL;

    treeNode* node7 = (treeNode*)malloc(sizeof(treeNode));
    node7->data = 7;
    node7->lchild = node7->rchild = NULL;

    // treeNode* node8 = (treeNode*)malloc(sizeof(treeNode));
    // node8->data = 8;
    // node8->lchild = node8->rchild = NULL;

    // treeNode* node9 = (treeNode*)malloc(sizeof(treeNode));
    // node9->data = 9;
    // node9->lchild = node9->rchild = NULL;

    // treeNode* node10 = (treeNode*)malloc(sizeof(treeNode));
    // node10->data = 10;
    // node10->lchild = node10->rchild = NULL;

    // treeNode* node11 = (treeNode*)malloc(sizeof(treeNode));
    // node11->data = 11;
    // node11->lchild = node11->rchild = NULL;


    node1->lchild = node2;
    node1->rchild = node3;
    node3->rchild = node6;
    node2->rchild = node5;
    node2->lchild = node4;
    node5->lchild = node7;



//    中序遍历
//    midOrder(node1);
   //midOrderNonrecursive(node1);
   //postOrderNonrecursive(node1);
   //hierarchicalTraversal(node1);

   //printf("height = %d ",heightNonrecursive(node1));

//    int arrp[10] = {4,1,0,2,3,7,6,5,8,9};
//    int arrm[10] = {0,1,2,3,4,5,6,7,8,9};
//    treeNode*t  =  midAndPreToTree(arrp,10,arrm,10);
//    postOrder(t);

//    swabChildTree(node1);
//    midOrder(node1);

// int ii = 0;
// printf("%d ",preOrderForK(node1,6,&ii));

// int li = -1;
// printf("%d ",li);

// findOnesAncestor(t,9);

//    int arrp[15] = {1,2,4,8,9,5,10,11,3,6,12,13,7,14,15};
//    int arrm[15] = {8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};
//    treeNode*t  =  midAndPreToTree(arrp,15,arrm,15);
   


//    int arr[15] = {8,9,4,10,11,5,2,12,13,6,14,15,7,3,1};
//    int arr1[15];

//    postToPre(arr,0,14,arr1,0,14);
//    for (int i = 0; i < 15; i++)
//    {
//        printf("%d ",arr1[i]);
//    }

//    int arrp[10] = {4,1,0,2,3,7,6,5,8,9};
//    int arrm[10] = {0,1,2,3,4,5,6,7,8,9};

  printf("%d",height(node2));

   
}
