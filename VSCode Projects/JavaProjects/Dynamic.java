import java.util.Scanner;
class Dynamic{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int n = scanner.nextInt();
        int[] weighs = new int[n + 1];
        int[] values = new int[n + 1];
        for(int i = 1 ; i <= n; i++){
            weighs[i] = scanner.nextInt();
            values[i] = scanner.nextInt();
        }
        int[] dp = new int[capacity + 1];
        values[0] = 0;
        weighs[0] = 0;
        for(int i = 1 ; i <= n; i ++){
            for(int j = capacity ; j >= 0 ; j --){
                if(j >= weighs[i]){
                    dp[j] = Math.max(dp[j], dp[j - weighs[i]] + values[i]);

                }
            }
        }
        System.out.println(dp[capacity]);
        scanner.close();
    }
}