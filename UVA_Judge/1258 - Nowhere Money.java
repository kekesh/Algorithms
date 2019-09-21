import java.util.*;
import java.math.*;
import java.io.*;


public class Main {

	public static void main(String[] args) throws IOException {
		int test_case = 0;
		BigInteger fib[] = new BigInteger[150];
		BigInteger T[] = new BigInteger[150];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.valueOf(1);
		for (int i = 2; i <= 145; i++) {
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}
		T[0] = BigInteger.valueOf(-1); // Sentinel
		for (int i = 1; i <= 110; i++) {
			T[i] = fib[i + 1];
		}
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			//  Zeckendorf's Theorem
			BigInteger a = scan.nextBigInteger();
			System.out.println(a);

			int start_index = 145;

			while (start_index > 0 && fib[start_index].compareTo(a) > 0) {
				start_index--;
			}
			start_index--;


			Queue<Integer> indices = new LinkedList<Integer>();
			Queue<BigInteger> values = new LinkedList<BigInteger>();

			while (a.compareTo(BigInteger.ZERO) != 0) {
				if (T[start_index].compareTo(a) <= 0) {
					a = a.subtract(T[start_index]);
					indices.add(start_index);
					values.add(T[start_index]);
					start_index -= 2;
				} else {
					start_index--;
				}
			}
			int flag = 1;
			while (!indices.isEmpty()) {
				System.out.print(indices.poll() + " ");
				flag = 0;
			}

			System.out.println();
			flag = 1;
			while (!values.isEmpty()) {
				System.out.print(values.poll() + " ");
				flag = 0;
			}
			System.out.println();
			System.out.println();
		}
	}
}
