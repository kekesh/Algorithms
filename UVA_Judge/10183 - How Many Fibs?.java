import java.util.*;
import java.math.*;
import java.io.*;


public class Main {

	public static void main(String[] args) {


		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			BigInteger a = scan.nextBigInteger();
			BigInteger b = scan.nextBigInteger();
			BigInteger ans = BigInteger.ZERO;
			BigInteger prev = BigInteger.ZERO;
			if (ans.compareTo(a) == 0 && ans.compareTo(b) == 0) {
				System.exit(0);
			}
			BigInteger curr = BigInteger.valueOf(1);
			int count = 0;
			boolean flag = true;
			//int N = scan.nextInt();
			while (flag) {
				ans = prev.add(curr);
				if (ans.compareTo(b) <= 0 && ans.compareTo(a) >= 0) {
					count++;
				}
				if (ans.compareTo((b)) > 0) {
					flag = false;
				}
				prev = curr;
				curr = ans;
			}
			System.out.println(count);
		}
	}
}
