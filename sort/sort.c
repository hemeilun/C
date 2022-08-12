#include<stdio.h>




void showArr(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

}



/**
 * @brief 插入排序
 * 
 * @param arr  数组
 * @param n    数组长度
 */
void insertSort(int *arr,int n){

    int num;            //记录正在插入的数字
    int temp;           //用于交换的临时变量

    int i,j;

    for (i = 1; i < n; i++)
    {
        num = arr[i];

        int tt = i-1;
        while(tt>=0 && arr[tt]>num){
            arr[tt+1] = arr[tt];
            tt--;
        }
        arr[tt+1] = num;
    }

    showArr(arr,n);
    

}




/**
 * @brief 希尔排序
 * 
 * @param arr 
 * @param n 
 */
void shellSort(int *arr,int n){
     
     int num;
     int temp,tempNum;

     int i,j;
     int len = n;


     for ( i = len/2; i >0; i/=2)
     {
        for ( j = i; j < len; j++)
        {
            temp = j-i;     //记录每次前进的距离
            tempNum = arr[j];

            while(temp>=0 && tempNum<arr[temp])
            {
                 arr[temp+i] = arr[temp];
                 temp = temp - i;
            }

            arr[temp+i] = tempNum;
        }      
     }

     showArr(arr,n);
     
}






/**
 * @brief 快速排序
 * 
 * @param arr 
 * @param left       指向左边的索引值
 * @param right      指向右边的索引值
 */
void quickSort(int *arr,int left,int right){
      

      if(left>right){return;}

      int num = arr[left];    //记录分界值

      int l = left;     //指向左边的指针
      int r = right;    //指向右边的指针


    while(l<r){

      while(l<r && arr[r]>=num){
        r--;
      }

      arr[l] = arr[r];

      while(l<r && arr[l]<=num){
        l++;
      }

      arr[r] = arr[l];

    }

    arr[l] = num;


    quickSort(arr,left,l-1);
    quickSort(arr,l+1,right);

}




/**
 * @brief 将堆变为大顶堆
 * 
 * @param arr 
 * @param n 
 * @param k     判断以k顶点为根的子树是否为大顶堆
 */
void isHeap(int *arr,int n,int k){

      /*  
      //这个方法虽然也可以算出来，但相对繁琐，可以简化为下方无注释的内容
      while(2*k+1<n-1){

      //由于传经来的数组是以序号0为根节点，所以是2*k+1，如果是以1为根节点就是2*k
      int left = 2*k+1;          //左孩子的序号
      int right = 2*k+2;         //右孩子的序号

      int max = k;                   //记录子树最大值的序号
      if(left>n-1){
        return;
      }else if (arr[max] < arr[left])
      {
        max = left;
      }
      
      if(right<=n-1 && arr[max] < arr[right]){
            max = right;
      }

      if(max == k){
        return;
      }else{
        int temp = arr[k];
        arr[k] = arr[max];
        arr[max] = temp;
      }

      k = max;

      }

      */


     int num = arr[k];

     //这个地方是i<n，表示有左子树
     for (int i = 2*k+1; i < n; i=2*i+1)
     {

        //这个地方是i<n-1,i<n-1表示有右子树
        if(i<n-1 && arr[i+1]>arr[i]){

            //i++就是让指向左子树的指针指向右子树
            i++;
        }

        //由于没有改变对应的值，这个地方不能用num不能arr[k]，初始没改变k不会问题，k一变但arr[k]的值没变就会出问题
        if(arr[i] < num){
            break;
        }else{
            arr[k] = arr[i];
            k = i;
        }
     }

     arr[k] = num;
    

}





/**
 * @brief 堆排序的实现
 * 
 * @param arr 
 * @param n 
 */
void heapSort(int *arr,int n){

    //初始化建立堆
    for (int i = n/2-1; i >= 0 ; i--)
    {
        isHeap(arr,n,i);
    }

    //进行堆排序
    for (int i = n; i > 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;

        isHeap(arr,i-1,0);
    }
    
    showArr(arr,n);

}






int main(){

    int arr[13] = {4,5,2,6,4,2,9,5,6,3,8,5,1};
    //insertSort(arr,9);
    //shellSort(arr,9);

    // quickSort(arr,0,8);
    // showArr(arr,9);

    heapSort(arr,13);

}




