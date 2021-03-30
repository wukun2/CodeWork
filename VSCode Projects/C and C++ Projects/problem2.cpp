#include <iostream>
#include <cmath>
using namespace std;
double minDistance = 100.0;
class conon{
private:
    int x;
    int y;
public:
    conon(){}
    conon(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }
    bool operator > (const conon temp){
        if(this->x > temp.x){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator < (const conon temp){
        if(this->x < temp.x){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator == (const conon temp){
        if(this->x == temp.x){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        cout<<this->x<<" "<<this->y<<endl;
    }
};
double distance(conon a, conon b){
    return sqrt(pow(a.getX() - b.getX(),2) + pow(a.getY() - b.getY(),2));
}
void merge(conon *data[] , int begin , int mid , int end , conon * temp[]){
    int p1 = begin , p2 = mid + 1 , index = 0;
    while(p1 <= mid && p2 <= end){
        if(*data[p1] < *data[p2]){
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
    for(int i = 0 ; i <= end ; i ++){
        data[begin + i] = temp[i];
    }
}
void sort(conon *data[],int begin,int end , conon *temp[]){
    if(begin < end){
        int mid = (begin + end)/2;
        sort(data , begin , mid , temp);
        sort(data , mid + 1 , end , temp);
        merge(data , begin , mid , end , temp);
    }
}
void find(conon *data[] , int begin , int end){
    if(end - begin > 1){
        int mid = (end - begin)/2;
        find(data , begin , mid);
        find(data , mid + 1 , end);
        for(int i = begin ; i <= mid ; i++){
            for(int j = mid + 1 ; j <= end ; j++){
                if(data[j]->getX() - data[i]->getX() > minDistance){
                    break;
                }
                minDistance = distance(*data[i] , *data[j]) > minDistance ? minDistance : distance(*data[i] , *data[j]);
            }
        }
    }
    else if(begin - end == -1){
        double temp = distance(*data[begin] , *data[end]);
        minDistance =  temp > minDistance ? minDistance : temp;
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    conon *data[n] = {0};
    conon *temp[n] = {0};
    for(int i ; i < n ; i++){
        int x,y;
        scanf("%d", &x);
        scanf("%d", &y);
        data[i] = new conon(x,y);
    }
    sort(data , 0 , n - 1 , temp);
    find(data , 0 , n - 1);
    printf("%.2f",minDistance);
}