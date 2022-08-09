#include<stdio.h>


void len(char *arr){
    int m = strlen(arr);
    printf("%d ",m);
}

int main(){
    char arr[11] = "asg12dcr";
    len(arr);

}