#include <iostream>
using namespace std;
int main(){
    const volatile int a = 1;
    int *p = (int *)&a;
    *p = 2;
    cout<<a;
}