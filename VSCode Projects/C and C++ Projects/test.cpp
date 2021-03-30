#include <iostream>
using namespace std;
void divide(int data[],int begin,int end,int temp[]);
void merge(int data[],int begin,int mid,int end,int temp[]);
int myCount = 0;

int main(){
    int n = 0;
    cin>>n;
    int data[n]={0};
    int temp[n] = {0};
    for(int i=0 ; i < n ; i++){
        cin >> data[i];
    }
    divide(data , 0 , n - 1 , temp);
    cout << myCount;
}
void divide(int data[],int begin,int end,int temp[]){
    if(begin < end){
        int mid = (begin + end)/2;
        divide(data,begin,mid,temp);
        divide(data,mid + 1,end,temp);
        merge(data,begin,mid,end,temp);
    }
}

void merge(int data[],int begin,int mid,int end,int temp[]){
    int p1 = begin,p2 = mid + 1;
    int index = 0;
    while(p1 <= mid && p2 <= end){
        if(data[p1] < data[p2]){
            temp[index ++] = data[p1 ++];
        }
        else{
            temp[index ++] = data[p2 ++];
            myCount += mid - p1 + 1;
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