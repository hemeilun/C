#include"LinkedQueue.c"

int main(){
      LinkedQueueList L = initQueue();
      int aa = isQueueEmpty(L);
      printf("aa=%d\n",aa);

      enQueue(L,1);
      enQueue(L,2);
      enQueue(L,7);
      enQueue(L,5);

      int bb = isQueueEmpty(L);
      printf("bb=%d\n",bb);

      int cc = queueTop(L);
      printf("cc=%d\n",cc);

      while(isQueueEmpty(L)){
          printf("%d\n",deQueue(L));
      }
}