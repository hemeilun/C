#include<stdlib.h>
#include<stdio.h>


int palindromeLen(char *s,int left ,int right,int len){

    while(left>=0&&right<len&&s[left]==s[right]){
        left--;
        right++;
    }

    return right-left-1;
  
}

char * longestPalindrome(char * s){
    int len = strlen(s);

    int start = 0;
    int end = 0;

    //int index = 0;

    for (int i = 0; i < len; i++)
    {
        int odd = palindromeLen(s,i,i,len);
        int even = palindromeLen(s,i,i+1,len);

        int maxLen = odd>even?odd:even;
        if(maxLen>end-start+1){
            if(odd>=even){
              start = i-(odd-1)/2;
              end = i+(odd-1)/2;
            }else{
              start = i-even/2+1;
              end = i+even/2;
            }
        }
    
    }

    int mlen = end-start+2;
    //printf("start=%d \n",start);
    //printf("end=%d \n",end);
    //char *chars = (char*)malloc(sizeof(char)*mlen);
    // for (int i = 0; i < mlen-1; i++)
    // {
    //     //printf("%c ",s[start+i]);
    //     chars[i] = s[start+i];
    // }
    //printf("\n");


    
    s[end+1] = '\0';
    s = s+start;

    // char chars[end-start+2];
    // strncpy(chars,s+start-1,end-start+1);
    // int mm =1;
    return s;
    
    
    
}

int main(){

    char chars[30] = "babaddasbcehecbskdjfkeij"; 
    char* cc = longestPalindrome(chars);

    for (int i = 0; i < strlen(cc); i++)
    {
        printf("%c ",cc[i]);
    }
    printf("\n");
    printf("%s",cc);

}