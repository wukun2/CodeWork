#include<iostream>
using namespace std;
class item{
private:
    double value;
    double pervalue;
    int weight;
public:
    item(double value , double pervalue , int weight){ this -> value = value ; 
        this -> pervalue = pervalue ; 
        this -> weight = weight ; 
        this -> weight = weight;}
    double getvalue() const { return value; }
    double getpervalue() const { return pervalue; }
    double getweight() const { return weight; }
    void setvalue(double value) { this -> value = value;}
    void setpervalue(double pervalue) { this -> pervalue = pervalue;}
    void setweight(int weight) { this -> weight = weight;}
    bool operator == (const item* a ){
        return this -> getpervalue() == a -> getpervalue() ? true : false;
    }
    bool operator > (const item* a ){
        return this -> getpervalue() > a -> getpervalue() ? true : false;
    }
    bool operator < (const item* a ){
        return this -> getpervalue() < a -> getpervalue() ? true : false;
    }
};
void merge(item* data[] , int start, int mid , int end , item* temp[]){
    int p1 = start , p2 = mid + 1 , index = 0;
    while(p1 <= mid && p2 <= end){
        if(data[p1] -> getpervalue() > data[p2] -> getpervalue()){
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
    for(int i = 0 ; i < index ; i++){
        data[i + start] = temp[i];
    }
}
void sort(item* data[] , int start , int end , item* temp[]){
    if(start < end){
        int mid = (start + end)/2;
        sort(data , start , mid , temp);
        sort(data , mid + 1, end , temp);
        merge(data , start , mid , end , temp);
    }
}
int main(){
    double res = 0.0;
    int W = 0;
    scanf("%d", & W);
    int n = 0;
    scanf("%d",&n);
    item *data[n];
    item *temp[n];
    for(int i=0;i<n;i++){
        double value;
        scanf("%lf" , & value);
        int weight;
        scanf("%d" , & weight);
        double pervalue = value / weight;
        data[i] = new item(value , pervalue , weight);
    }
    sort(data , 0 , n - 1, temp);
    int index = 0;
    while(W != 0){
        if(W >= data[index] -> getweight()){
            res += data[index] -> getvalue();
            W -= data[index] -> getweight();
            index ++;
        }
        else{
            res += W * data[index] -> getpervalue();
            W = 0;
        }
    }
    printf("%.2f",res);
}