

#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char * s);

int main(){
    char arr[14] = "aabaab!bb";
    printf("%d",lengthOfLongestSubstring(arr));
}


int lengthOfLongestSubstring(char * s){
   int length = 0;    //记录链表的长度
   struct node
   {
    char data;
    struct node *next;
   };

   struct node* head = (struct node*)malloc(sizeof(struct node));
   head->next = NULL;
   struct node* first = head;
   struct node* tail = head;
   
   int i = 0;
   //int num = 0;  //记录每一次遍历结点的数量
   int maxLength = 0;  //记录最大长度

   while(s[i] != '\0'){
    // if(!head->next){
    //     struct node* p = (struct node*)malloc(sizeof(struct node));
    //     p->next = NULL;
    //     tail->next = p;
    //     length++;
    //     continue;
    // }

    
    first = first->next;
    while(first && first->data != s[i] ){
        first = first->next;
        //num++;
    }

    if(!first){
        struct node* p = (struct node*)malloc(sizeof(struct node));
        p->data = s[i];
        p->next = NULL;

        tail->next = p;
        tail = p;
        //num = 0;
        length++;

        if(length > maxLength){
            maxLength = length;
        }

    }else{
        struct node* p, *q;
        p = head->next;
        q = p->next;

        while(p->data!=s[i]){
          head->next = q;
          free(p);
          p = q;
          q = p->next;
          length--;  
        }
        head->next = q;
        free(p);
        length--;
        p = q;

        if(!p){
           tail = head;
        }

        struct node* pp = (struct node*)malloc(sizeof(struct node));
        pp->data = s[i];
        pp->next = NULL;

        tail->next = pp;
        tail = pp;
        //num = 0;
        length++;

    }

    first = head;
    i++;

  
   }
   

   return maxLength;
}