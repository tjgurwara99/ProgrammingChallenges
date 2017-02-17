import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        BigInteger[] A = new BigInteger[510];
        BigInteger MIN_AMOUNT = BigInteger.valueOf(-999999);
        int N;
        
        while (scanner.hasNextInt()) {
        
            A[0] = BigInteger.valueOf(scanner.nextInt());
            N = 0;
            while (scanner.hasNextInt() && MIN_AMOUNT.compareTo(A[N]) != 0) {
                A[++N] = BigInteger.valueOf(scanner.nextInt());
            }
            if (N == 0) break;
            
            BigInteger maxProduct = MIN_AMOUNT;
            
            for (int i = 0; i < N; i++) {
                BigInteger prod = BigInteger.ONE;
                for (int j = i; j < N; j++) {
                    prod = prod.multiply(A[j]);
                    maxProduct = maxProduct.max(prod);
                }
            }
            
            System.out.println(maxProduct);
        }
    }
}