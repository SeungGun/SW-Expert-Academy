package prob_1256;

import java.util.Arrays;
import java.util.Scanner;

public class Prob_1256 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String str = sc.next();
		String[] arrs = new String[str.length()];

		int index = 0;
		for(int i=0; i<str.length(); i++) {
			arrs[i] = str.substring(i);
			index++;
		}
		Arrays.sort(arrs);
		
		try {
		System.out.println(arrs[N-1]);
		}
		catch(Exception e) {
			System.out.println("none");
		}
	}

}
