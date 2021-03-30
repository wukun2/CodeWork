package JavaProjects;

import java.util.Scanner;

public class Count {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] data = new int[n];
        for (int i = 0; i < n ; i++) {
            data[i] = scanner.nextInt();
        }
        int[] temp = new int[n];
        scanner.close();
    }
    public static void sort(int[] data , int begin, int end , int[] temp) {
        if(begin < end){
            int mid = (begin + end) / 2;
            sort(data, begin, mid, temp);
            sort(data , mid + 1, end, temp);
            int p1 = begin , p2 = mid + 1 , index = 0;
            while(p1 <= mid && p2 <= end){
                if(data[p1] < data[p2]){
                    temp[index ++] = data[p1 ++];
                }
                else{
                    temp[index ++] = data[p2 ++];
                }
            }
            while(p1 <= mid){
                temp[index ++] = data[p1 ++];
            }
        }
    }
}
