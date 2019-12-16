import java.util.*;
import java.math.*;
import java.io.*;


public class Main {

	public static void main(String[] args) {


		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			BigInteger ans = BigInteger.ZERO;
			BigInteger prev = BigInteger.ZERO;
			BigInteger curr = BigInteger.valueOf(1);

			int N = scan.nextInt();
			for (int i = 1; i < N; i++) {
				ans = prev.add(curr);
				prev = curr;
				curr = ans;
			}
			System.out.println("The Fibonacci number for " + N + " is " + ans);
		}
	}
}
