#include"LinkedStack.c"

int main(){

      LinkedStackList L = initStack();
      int aa = isEmpty(L);
      printf("aa=%d\n",aa);

      push(L,1);
      push(L,2);
      push(L,8);
      push(L,5);

      int bb = isEmpty(L);
      printf("bb=%d\n",bb);

      int cc = top(L);
      printf("cc=%d\n",cc);

      while(isEmpty(L)){
          printf("%d\n",pop(L));
      }


}