#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 10

typedef struct
{
    /* data */
    int* data;
    int length;
    int MAXSIZE;
}SQList;


/**
 * @brief  初始化线性表 
 * 
 * @param L    要初始化的线性表 
 * @return
 */
int initList(SQList *L){

    L->data = (int*)malloc(sizeof(SQList)*INITSIZE);
    L->length = 0;
    L->MAXSIZE = INITSIZE;
    return 0;
}


/**
 * @brief  为线性表添加元素
 * 
 * @param L 
 * @param i   要添加的位置
 * @param e   要添加的数据 
 */
void insertList(SQList *L , int i ,int e){
     
     //输入位置错误
     if(i<1 || i > L->length+1){
         return;
     }

     //线性表已满
     if (L->length == L->MAXSIZE )
     {
        return;
     }

     for(int m = L->length; m>=i ; m--){
         L->data[m]=L->data[m-1];

     }

     L->data[i-1] = e;
     L->length++;
     
}



void printList(SQList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d  ",L.data[i]);
    }

    printf("\n");
}






//题目所需代码

//1
int fristProblem(SQList *L){
  
    if(L->length==0){
        printf("顺序表为空");
        return 0;
    }

    int mmin=L->data[0];
    int mminIndex = 0;

    for (int i = 1; i < L->length; i++)
    {
        if(mmin > L->data[i]){
            mmin = L->data[i];
            mminIndex = i;
        }
    }

    if(mminIndex == L->length-1){
        L->length--;
        return mmin;
    }

    L->data[mminIndex] = L->data[L->length-1];
    L->length--;
    /* for (int i = mminIndex; i < L->length-1; i++)
    {
        L->data[i] = L->data[i+1];
    }
    L->length--; */

    return mmin;
    
    

}


//2
void secondProblem(SQList *L){

   int temp;

   for (int i = 0; i < L->length/2; i++)
   {
       temp = L->data[i];
       L->data[i] = L->data[L->length-i-1];
       L->data[L->length-i-1] = temp;
       L->data[L->length-i-1]; 
   }
   

}



//3
//这个方法真不错，时间复杂度为O(n),空间复杂度为O(1)
void thirdProblem(SQList *L,int e){

   int num = 0;          //记录要删除的个数
   int after = 0;        //指向后继节点
   int flag = 0;

   for (int i = 0; i < L->length; i++,after++)
   {
         
         
       while (L->data[after] == e && after < L->length)
       {
           if(flag == 0){
               flag = 1;
            }

           after++;
           num++;

       }

       if(after >= L->length){
            L->length-=num;
            return;
       }

        if(flag != 0){
          int temp;
          temp = L->data[i];
          L->data[i] = L->data[after];
          L->data[after] = temp;

        }
  

   }
   

}


//7
SQList sevenProblem(SQList *L1,SQList *L2){

       SQList L;
       L.data = (int*)malloc(sizeof(SQList)*(L1->length+L2->length));
       L.length = L1->length+L2->length;
       L.MAXSIZE = L1->length+L2->length;


       int index1 = 0;    //记录L1的索引
       int index2 = 0;    //记录L2的索引
       int lIndex = 0;    //记录L2的索引

       while(index1 < L1->length && index2 < L2->length){
           
           if(L1->data[index1] <= L2->data[index2]){
                L.data[lIndex++] = L1->data[index1++];
           }else{
                L.data[lIndex++] = L2->data[index2++];
           }

       }


       if(index1 == L1->length){
           while(index2 < L2->length){
               L.data[lIndex++] = L2->data[index2++];
           }    

           return L;
       }

       if(index2 == L2->length){
           while(index1 < L1->length){
               L.data[lIndex++] = L1->data[index1++];
           }    

           return L;
       }
}




//9.二分查找
//不用递归
void eightProblem1(SQList *L,int e){
    

    int flag = 0; //记录是否找到，0表示没找到
    if(e<L->data[0] || e>L->data[L->length-1]){
        
    }
    
    int left = 0;
    int right = L->length - 1;
    int mid = (left + right)/2;

    int index;    //记录对应值的索引
    

    /* while(left <= right){

        if(e<L->data[left] || e>L->data[right]){
           break;
        }

        if(L->data[left] <= e && L->data[mid] >e){
            right = mid-1;
            mid = (left + right)/2;
        }else if(L->data[mid] <e && L->data[right] >=e){
            left = mid+1;
            mid = (left + right)/2;

        }else{

            index = mid;
            flag = 1;
            break;
        }

    } */

    while(left <= right){

        /* if(e<L->data[left] || e>L->data[right]){
           break;
        } */

        if( L->data[mid] >e){
            right = mid-1;
            mid = (left + right)/2;
        }else if(L->data[mid] <e ){
            left = mid+1;
            mid = (left + right)/2;

        }else{

            index = mid;
            flag = 1;
            break;
        }

    }


    if(flag == 1){

        printf("找到了\n");
        if(index != L->length-1){
            int temp = L->data[index];
            L->data[index] = L->data[index+1];
            L->data[index+1] = temp;
        }
    }else{
        
        printf("没找到\n");
        if(L->data[0]>e){
            for (int i = L->length; i > 0; i--)
            {
                L->data[i] = L->data[i-1];
            }
            L->data[0] = e;
            L->length++;
            return;
        }

        /* if(L->data[L->length-1] < e){
            L->data[L->length++] = e;
            return;
        } */

        int m=0;
        while(m<L->length){
            if(L->data[m]<e && L->data[m+1]>e)
            {
                m++;
                break;
            }
            m++;
        }

        for (int i = L->length; i > m; i--)
            {
                L->data[i] = L->data[i-1];
            }
        L->data[m] =e;

        L->length++;
    }
 
}

int midGet(int num1[],int start1,int end1,int num2[],int start2,int end2,int k);

void elevenProblem(int num1[],int len1 , int num2[],int  len2){
       

    int mid;
    int k;          //需要找的对应数的编号

    //当为奇数时
    if((len1+len2)%2){

        k = (len1+len2)/2+1;
        mid = midGet(num1,0,len1-1,num2,0,len2-1,k);
        printf("mid = %d", mid);
    }else{
        //如果是偶数
        k = (len1+len2)/2;
        mid = midGet(num1,0,len1-1,num2,0,len2-1,k);
        printf("mid = %d", mid);
    }
}


int midGet(int num1[],int start1,int end1,int num2[],int start2,int end2,int k){

     int len1 = end1-start1+1;
     int len2 = end2-start2+1;

     //保证数组1长于数组2
     if(len1<len2){
         return midGet(num2,start2,end2,num1,start1,end1,k);
     }

     if(len2 == 0){return num1[start1+k-1];};

     if(k == 1){
         return num2[start2]>num1[start1]?num1[start1]:num2[start2];
     }

     int mmin = k/2>len2?len2:k/2;

     if(num1[start1+mmin-1]>num2[start2+mmin-1]){
         return midGet(num1,start1,end1,num2,start2+mmin,end2,k-mmin);
     }else{
         return midGet(num1,start1+mmin,end1,num2,start2,end2,k-mmin);
     }


}




int main(){

    int frist[7] = {3,5,3,5,7,4,0};

    int seven1[7] = {1,3,4,5,7,9,12};
    int seven2[4] = {2,4,6,9};

    SQList list;
    initList(&list);

    SQList list7_1;
    SQList list7_2;
    initList(&list7_1);
    initList(&list7_2);

    for (int i = 0; i < 4; i++)
    {
        insertList(&list7_2,i+1,seven2[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        //insertList(&list,i+1,i+2);
        //insertList(&list,i+1,frist[i]);
        insertList(&list7_1,i+1,seven1[i]);
    }



   /* int ff = fristProblem(&list);
   printf("%d\n",ff); */

   //secondProblem(&list);

   //thirdProblem(&list,4);

   /* SQList sevenList = sevenProblem(&list7_2,&list7_1);
   printList(sevenList); */

   /* eightProblem1(&list7_1,1);
   printList(list7_1); */



    int ele1[1] = {2};
    int ele2[1] = {3};
    int el1 = sizeof(ele1) / sizeof(int);
    int el2 = sizeof(ele2) / sizeof(int);

    elevenProblem(ele1,el1,ele2,el2);

   //printList(list);
    

}




