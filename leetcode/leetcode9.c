#include<stdio.h>

int isPalindrome(int x){

    if(x<0){
        return 0;
    }else if (!x){
        return 1;
    }else{

        char num[11];
        int index = 0;

        while(x>0){
           num[index++] = x%10;
           x = x/10;
        }

        for (int i = 0; i < index/2; i++)
        {
            if(num[i] == num[index-i-1]){
                i++;
            }else{
                return 0;
            }
        }
        return 1;  
    }
    

}


int main(){
      int aa=121111;
      printf("%d",isPalindrome(aa));
}