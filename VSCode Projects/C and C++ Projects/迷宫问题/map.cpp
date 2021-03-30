#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;
class Grid{
private:
    int x, y;
    bool visible;
public:
    Grid(int x, int y){
        this->x = x;
        this->y = y;
        visible = true;
    }
    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }
    void print(){
        cout << this->x << ", " << this->y<<endl;
    }
};

template<class T>
class Stack{
private:
    T* base;
    T* top;
    int size;
public:
    Stack(int size){
        this->size = size;
        base = (T *)malloc(size * sizeof(T));
        top = base;
    }
    bool isEmpty(){
        if(top == base){
            return true;
        }
        else{
            return false;
        }
    }
    bool push(T e){
        if((top-base)/sizeof(T) >= size){
            return false;
        }
        else{
            top ++;
            * top = e;
            return true;
        }
    }
    T* pop(){
        if(top == base){
            return (T*)nullptr;
        }
        else{
            return top --;
        }
    }
    T getTop(){
        T temp = *top;
        return temp;
    }
};
int main(){
    bool visited[8][8] = {false};
    int map[8][8];
    Stack<Grid> stack(64);
    FILE *fp = fopen("data","r");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j ++){
            fscanf(fp,"%d",&map[i][j]);
        }
    }
    int i = 1,j = 1;
    stack.push(*(new Grid(i , j)));
    do{
        if(visited[i][j + 1] == false && map[i][j + 1] != 0 && j < 7){
            visited[i][j + 1] = true;
            stack.push(*(new Grid(i , j + 1)));
            j ++;
        }
        else if(visited[i + 1][j] == false && map[i + 1][j] != 0 && i < 7){
            visited[i + 1][j] = true;
            stack.push(*(new Grid(i + 1 , j)));
            i ++;
        }
        else if(visited[i][j - 1] == false && map[i][j - 1] != 0 && j >= 2){
            visited[i][j - 1] = true;
            stack.push(*(new Grid(i , j - 1)));
            j --;
        }
        else if(visited[i - 1][j] == false && map[i - 1][j] && i >= 2){
            visited[i - 1][j] = true;
            stack.push(*(new Grid(i - 1, j )));
            i --;
        }
        else{
            stack.pop();
            i = stack.getTop().getX();
            j = stack.getTop().getY();
        }
        if(stack.isEmpty()){
            cout<<"no way to out!";
            break;
        }
    }while(i != 6 || j != 6);
    while(!stack.isEmpty()){
        stack.pop()->print();
    }
} 
