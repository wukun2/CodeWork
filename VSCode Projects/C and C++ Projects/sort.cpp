#include<iostream>
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;
void sort(int a[] , int n){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void sort1(int data[], int begin , int end){
    if(begin < end){
        int mid = (begin + end) / 2;
        sort1(data, begin , mid);
        sort1(data, mid + 1 , end);
        int index = 0;
        int temp[end - begin + 1];
        int p1 = begin , p2 = mid + 1;
        while(p1 <= mid && p2 <= end){
            if(data[p1] < data[p2]){
                temp[index ++] = data[p1 ++];
            }
            else{
                temp[index ++] = data[p2 ++];
            }
        }
        while(p1 <= mid){
            temp[index ++] = data[p1 ++];
        }
        while(p2 <= end){
            temp[index ++] = data[p2 ++];
        }
        for(int i = 0; i < index; i ++){
            data[begin + i] = temp[i];
        }
    }
}
void QuickSort(int R[], int lo, int hi){
    int i = lo, j = hi;
    int temp;
    if(i < j){
        temp = R[i];
        while (i != j)
        {
            while(j > i && R[j] >= temp)-- j;
            R[i] = R[j];
            while(i < j && R[i] <= temp)++ i;
            R[j] = R[i];
        }
        R[i] = temp;
        QuickSort(R, lo, i - 1);
        QuickSort(R, i + 1, hi);
    }
}
int main(){
    clock_t t1,t2;
    int n = 0;
    scanf("%d",&n);
    int data[n];
    for(int i = 0; i < n; i ++){
        data[i] = (int) rand();
    }
    t1 = clock();
    QuickSort(data , 0 , n - 1);
    t2 = clock();
    cout<< (double) (t2 - t1) / CLOCKS_PER_SEC << " ";
    system("pause");
}