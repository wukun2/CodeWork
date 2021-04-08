#include<iostream>
using namespace std;
int main(){
    int capacity = 0;
    int volume = 0;
    int n = 0;
    cin>>capacity>>volume>>n;
    int w[n + 1] = {0};
    int v[n + 1] = {0};
    int value[n + 1] = {0};
    int count[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin>>w[i] >>v[i] >>value[i] >>count[i];
    }
    
}