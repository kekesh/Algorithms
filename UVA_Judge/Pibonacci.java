import java.util.*;
import java.math.*;
import java.io.*;


public class Main {

	public static void main(String[] args) {


		Scanner scan = new Scanner(System.in);
		BigInteger P0 = BigInteger.valueOf(1);
		BigInteger P1 = BigInteger.valueOf(1);
		BigInteger P2 = BigInteger.valueOf(1);
		BigInteger P3 = BigInteger.valueOf(1);
		BigInteger[] arr = new BigInteger[1000];
		arr[0] = P0;
		arr[1] = P1;
		arr[2] = P2;
		arr[3] = P3;

		int x = scan.nextInt();

		for (int i = 4; i <= 999; i++) {
			arr[i] = arr[i-1].add(arr[i-3]);
		}

		while (x != -1) {
			System.out.println(arr[x]);
			x = scan.nextInt();
		}
	}
}
