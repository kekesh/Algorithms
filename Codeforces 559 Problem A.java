import java.io.*;
import java.util.*;
public class Example {

    public static void main(String[] args) {
        
        // We want the key to be an integer, and it should map to a string.
        HashMap<Integer, String> hmap = new HashMap<Integer, String>();
        Scanner scan = new Scanner(System.in);
        int N = Integer.parseInt(scan.nextLine());
//        System.out.println("N is " + N);
        String operations = scan.nextLine();
//        System.out.println("operations is " + operations);
        
        for (int i = 0 ; i < N; i++) {
            String temp = operations.substring(i, i + 1);
            hmap.put(i, temp);
        }
        
        int answer = 0;
        for (Integer i : hmap.keySet()) {
            if (hmap.get(i).equals("-")) {
                answer = Math.max(0, answer-1); 
            } else if (hmap.get(i).equals("+")) {
                answer++;
            }
        }
        
        System.out.println(answer);
        
        
    }

}
