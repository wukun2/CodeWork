#include<iostream>
using namespace std;
#define INF 1000000.0
int main(){
    int m ,n;
    cin >> m >> n;
    double data[n][n] = {INF};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            data[i][j] = INF;
        }
    }
    for(int i=0; i < m ; i++){
        int x = 0;
        int y = 0;
        cin >> x >> y;
        cin>> data[x][y];
        data[y][x] = data[x][y];
    }
    bool visited[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    double distance[n];
    for(int i=0; i < n ; i++){
        distance[i] = INF;
    }
    visited[0] = true;
    distance[0] = 0.0;
    int currentNode = 0;
    double currentDistance = 0.0;
    while(true){
        if(currentNode == n - 1){
            break;
        }
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == false){
                if(data[currentNode][i] != INF && data[currentNode][i] + currentDistance < distance[i]){
                    distance[i] = data[currentNode][i] + currentDistance;
                }
            }
        }
        int tempNode = -1;
        double tempDistance = INF;
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == false){
                if(distance[i] < tempDistance){
                    tempDistance = distance[i];
                    tempNode = i;
                }
            }
        }
        currentNode = tempNode;
        currentDistance = tempDistance;
        visited[currentNode] = true;
    }
    cout<<distance[n - 1];
}