#include<stdio.h>

int myAtoi(char * s){

    char maxIntPositive[11] = "2147483647";
    char maxIntNegative[11] = "2147483648";

    //int num = 0;          //记录读取的数字
    int len = strlen(s);  //记录字符串的长度

    int index=0;
    //排除前导空格
    while(len>0 && s[index] == ' '){
       s = s+1;
       len--;
    }  
    //如果字符串全为空格，直接返回0
    if(len == 0){ return 0;}


    //判断符号位
    int tag = 1;   //记录num的正负，1为正，0为负
    if(s[0]=='+'){
        tag = 1;
        s = s+1;
        len--;
    }else if(s[0]=='-'){
        tag = 0;
        s = s+1;
        len--;
    }else if (s[0]>='0'&&s[0]<='9')
    {
        tag = 1;
    }else{
        return 0;
    }


    index=0;
    //排除前导0
    while(len>0 && s[index] == '0'){
       s = s+1;
       len--;
    }
    //如果字符串全为0，直接返回0
    if(len == 0){ return 0;}



    //将数字读取到num数组中
    char num[11];   //记录读取的数字
    int lennum = 0; //记录数字的位数，最多为10位
    for (int i = 0; i < len; i++)
    {
        if(s[i]>='0'&&s[i]<='9'){

            if(lennum>9){
                if(tag == 0){
                    return -2147483648;
                }else{
                    return 2147483647;
                } 
            }
          num[i] = s[i];
          lennum++;
        }else{
            break;
        }
    }


    //判断数字是否大于32位int的范围
    int boolen = 0;      //-1表示小于，1表示大于
    if(lennum<10){
        boolen = -1;
    }else if(tag==0){
        boolen = strcmp(num, maxIntNegative);
    }else{
        boolen = strcmp(num,maxIntPositive);
    }

    //大于int的范围直接返回
    if(tag == 0 && boolen == 1){
        return -2147483648;
    }
    if(tag == 1 && boolen == 1){
        return 2147483647;
    }

    int resNum = 0;
    if (tag==0)
    {
        for (int j = 0; j < lennum; j++)
        {
            if(resNum>0){
                resNum = -resNum;
            }
                resNum= resNum*10-(num[j]-'0');
            }
            return resNum;
     }else{
        for (int j = 0; j < lennum; j++)
        {
            resNum= resNum*10+(num[j]-'0');
        }
        return resNum;
    }

   //return 0;
}



int main(){
    char s[30] = "   +000023112sdkjl";
    printf("%d",myAtoi(s));
}