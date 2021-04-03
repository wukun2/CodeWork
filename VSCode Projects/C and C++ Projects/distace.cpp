#include<iostream>
#include<cmath>
using namespace std;
double minDistance = 10000000.0;
class pos{
public:
    int x,y;
    pos(int x, int y){
        this->x = x;
        this->y = y;
    }
    bool operator > (const pos& b){
        if(this->x <= b.x){
            return false;
        }
        else{
            return true;
        }
    }
};
double distance(pos a, pos b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
void sort(int start, int end , pos *data[] , pos * temp[]){
    if(start < end){
        int mid = (start + end)/2;
        sort(start , mid , data , temp);
        sort(mid + 1 , end , data , temp);
        int p1 = start , p2 = mid + 1 , index = 0;
        while(p1 <= mid && p2 <= end){
            if(*data[p1] > *data[p2]){
                temp[index ++] = data[p2 ++];
            }
            else{
                temp[index ++] = data[p1 ++];
            }
        }
        while(p1 <= mid){
            temp[index ++] = data[p1 ++];
        }
        while(p2 <= end){
            temp[index ++] = data[p2 ++];
        }
        for(int i = 0 ; i < index; i ++){
            data[start + i] = temp[i];
        }
    }
}
void findMinDistance(int start, int end , pos *data[]){
    if(start < end){
        int mid = (start + end)/2;
        findMinDistance(start , mid , data);
        findMinDistance(mid + 1, end , data);
        for(int i = start; i <= mid; i ++){
            for(int j = mid + 1; j <= end; j ++){
                if( data[j] -> x - data[i] -> x >= minDistance){
                    continue;
                }
                else{
                    double temp = distance(*data[i] , *data[j]);
                    if(temp < minDistance && temp != 0){
                        minDistance = temp;
                    }
                }
            }
        }
    }
}
int main(){
    int n = 0;
    cin>>n;
    pos *data[n] , *temp[n];
    for(int i = 0 ; i < n ; i++){
        int x = 0;
        int y = 0;
        cin >> x >> y;
        data[i] = new pos(x,y);
    }
    sort(0 , n - 1 , data , temp);
    findMinDistance(0 , n - 1 , data);
    printf("%.2lf" , minDistance);
}