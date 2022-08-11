#include<stdio.h>


void len(char *arr){
    int m = strlen(arr);
    printf("%d ",m);
}


void len1(int *arr){
    int m = strlen(arr);
    printf("%d ",m);
}

int main(){
    char arr[11] = "asg12dcr";
    //len(arr);

    int arrInt[10] = {1,2,5,74,6};
    len1(arrInt);

}