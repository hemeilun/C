#include<stdio.h>


int reverse(int x){

    //-2147483648~2147483647
    char maxIntPositive[11] = "2147483647";
    char maxIntNegative[11] = "2147483648";

    int quotient,remainder;
    char num[12];             //存储传的整数
    int i = 0;                //记录数的位数
    int tag = 1;              //记录传的数是正还是负，1为正，0为负

    if(x>=0){
        tag = 1;
    }else{
        tag = 0;
        x = (-1)*x;
    }


    int len = 0;
    int temp = x;
    while(temp>0){
       len++;
       temp/=10;
    }
    temp = x;
    int lentemp = len;

    while(temp>0){ 
       num[--lentemp] = '0'+(temp%10);
       temp/=10;
    }
    num[len] = '\0';

    int boolen;
    for (int j = 0; j < len/2; j++)
    {
            char tt = num[j];
            num[j] = num[len-j-1];
            num[len-j-1] = tt;
    }

    if(len<10){
        boolen = -1;
    }else if(tag==0){
        boolen = strcmp(num, maxIntNegative);
    }else{
        boolen = strcmp(num,maxIntPositive);
    }

    int resNum = 0;
    if(boolen>0){
        return 0;
    }else{
        
        if (tag==0)
        {
            for (int j = 0; j < len; j++)
            {
                if(resNum>0){
                    resNum = -resNum;
                }
                resNum= resNum*10+(num[j]-'0');
            }
            return resNum;
        }else{
            for (int j = 0; j < len; j++)
            {
            resNum= resNum*10+(num[j]-'0');
            }
            return resNum;
        }

    }


}


int main(){

    int x =-2147483648;
    printf("%d",reverse(x));

}