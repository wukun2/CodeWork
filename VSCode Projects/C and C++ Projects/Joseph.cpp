#include <iostream>
#include <stdio.h>
#include <cmath>
typedef struct node {
    int num;
    struct node * next;
    int id;
}Node;
using namespace std;
int main(){
    int n = 0;
    int m = 0;
    scanf("%d %d", &m, &n);
    Node *head = (Node *)malloc(sizeof(Node));
    Node * temp = head;
    Node * temp2 = head;
    for(int i = 0 ; i < n ; i++){
       temp = (Node *)malloc(sizeof(Node));
       int a = 0;
       cin >> a;
       temp->num = a;
       temp->id = i + 1;
       temp2->next = temp;
       temp2 = temp;
    }
    temp->next = head->next;
    temp = temp->next;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j < m ; j ++){
            temp2 = temp2->next;
            temp = temp -> next;
        }
        cout<<temp->id<<" ";
        m = temp ->num;
        temp2->next = temp->next;
        temp = temp -> next;
    }
}
