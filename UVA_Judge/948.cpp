import java.util.*;
import java.math.*;
import java.io.*;


public class Main {

	public static void main(String[] args) {
		int test_case = 0;
		BigInteger fib[] = new BigInteger[150];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.valueOf(1);
		for (int i = 2; i <= 145; i++) {
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}
		int N;
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		while (N > 0) {

			BigInteger sum = scan.nextBigInteger();
			BigInteger copy = sum;
			int sum_rep[] = new int[105];
			int start_index = 140;

			while (fib[start_index].compareTo(sum) > 0) {
				if (fib[start_index - 1].compareTo(sum) < 0) {
					start_index--;
					break;
				} else {
					start_index--;
				}
			}

			Queue<Integer> rep = new LinkedList<>();

			while (sum.compareTo(BigInteger.ZERO) >= 0 && start_index > 1) {
				if (sum.compareTo(fib[start_index]) >= 0) {
					sum = sum.subtract(fib[start_index]);

					if (start_index > 2) {
						rep.add(1);
						start_index -= 2;
						rep.add(0);
					} else {
						rep.add(1);
						start_index--;
					}
				} else {
					rep.add(0);
					start_index--;
				}
			}
			System.out.print(copy + " = ");
			while (!rep.isEmpty()) {
				System.out.print(rep.poll());
			}
			System.out.println(" (fib)");
			N--;
			test_case++;
		}
	}
}
