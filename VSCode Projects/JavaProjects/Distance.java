package JavaProjects;

import java.util.Arrays;
import java.util.Scanner;

class pos implements Comparable<pos>{
    public int x;
    public int y;
    public pos(int x,int y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public int compareTo(pos pos){
        if(this.x > pos.x){
            return 1;
        }
        else{
            return 0;
        }
    }
}
public class Distance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        n = scanner.nextInt();
        pos[] data = new pos[n];
        for (int i = 0; i < n; i++){
            data[i] = new pos(scanner.nextInt(), scanner.nextInt());
        }
        Arrays.sort(data);
        for(int i = 0; i < n ; i++){
            System.out.println(data[i]);
        }
    }
    /*public static void sort(pos[] data , int start , int end , pos[] temp){
        if(start < end){
            int mid = (start + end) / 2;
            sort(data , start , mid , temp);
            sort(data , mid + 1 , end , temp);
            int p1 = start , p2 = mid + 1 , index = 0;
            while(p1 <= mid && p2 <= end){
                ;
            }
        }
    }*/
}
