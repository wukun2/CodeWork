package JavaProjects;
import java.util.Scanner;
public class map {
public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int m ,n;
    n = scanner.nextInt();
    m = scanner.nextInt();
    double[][] data = new double[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            data[i][j] = Double.MAX_VALUE;
        }
    }
    for(int i=0; i < m ; i++){
        int x = 0;
        int y = 0;
        x = scanner.nextInt();
        y = scanner.nextInt();
        data[x][y] = scanner.nextDouble();
        data[y][x] = data[x][y];
    }
    boolean[] visited = new boolean[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    double[] distance = new double[n];
    for(int i=0; i < n ; i++){
        distance[i] = Double.MAX_VALUE;
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
                if(data[currentNode][i] != Double.MAX_VALUE && data[currentNode][i] + currentDistance < distance[i]){
                    distance[i] = data[currentNode][i] + currentDistance;
                }
            }
        }
        int tempNode = -1;
        double tempDistance = Double.MAX_VALUE;
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
        System.out.println(distance[n - 1]);
    }
}
