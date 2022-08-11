#include<stdlib.h>
#include<stdio.h>


char * convert(char * s, int numRows){

if(numRows == 1){
    return s;
   }

    int len = strlen(s);
    char m[len+1]; 
    m[len] = '\0';

    int mNUm = 0;
    int row = 2*numRows - 2;

    for (int j = 0; j < numRows; j++)
    {
        for (int i = 0; i < len; i++)
        {
            if(j==0){
                if(i%row == 0){
                    m[mNUm++] = s[i];
                }
            }else if(j!=(numRows-1)){
                if(i%row==j||i%row==(row-j)){
                    m[mNUm++] = s[i];
                }
            }else{
                if(i%row == j){
                    m[mNUm++] = s[i];
                }
            }

            if(mNUm==len){
                break;
            }
        }
    }

    strcpy(s,m);
    //free(m);
    //s[len] = '\0';
    return s;
}


// P   A   H   N
// A P L S I I G
// Y   I   R





int main(){

    char chars[30] = "PAYPALISHIRING"; 
    char* cc = convert(chars,4);

    for (int i = 0; i < strlen(cc); i++)
    {
        printf("%c ",cc[i]);
    }
    printf("\n");
    //printf("%s",cc);

}

//PAHNAPLSIIGYIR   PINALSIGYAHRPI

