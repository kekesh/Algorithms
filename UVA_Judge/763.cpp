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

		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			BigInteger a = scan.nextBigInteger();


			BigInteger b = scan.nextBigInteger();

			if (a.compareTo(BigInteger.ZERO) == 0) {
				System.out.println(b);
				System.out.println();
			} else if (b.compareTo(BigInteger.ZERO) == 0) {
				System.out.println(a);
				System.out.println();
			} else {

			int i = 2;
			BigInteger sum_one = BigInteger.ZERO;
			while (a.compareTo(BigInteger.ZERO) > 0) {
				BigInteger num = a.mod(BigInteger.valueOf(10));
				a = a.divide(BigInteger.valueOf(10));
				sum_one = sum_one.add(fib[i++].multiply(num));
			}
			BigInteger sum_two = BigInteger.ZERO;
			i = 2;
			while (b.compareTo(BigInteger.ZERO) > 0) {
				BigInteger num = b.mod(BigInteger.valueOf(10));
				b = b.divide(BigInteger.valueOf(10));
				sum_two = sum_two.add(fib[i++].multiply(num));
			}
			BigInteger sum = sum_one.add(sum_two);

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
			if (test_case != 0) {
				System.out.println();
			}
			while (!rep.isEmpty()) {
				System.out.print(rep.poll());
			}
			test_case++;
			System.out.println();
		}
	}
}
}
