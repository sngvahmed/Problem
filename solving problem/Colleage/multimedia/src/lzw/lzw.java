package lzw;
import java.util.ArrayList;
import java.util.Scanner;

public class lzw {
	static ArrayList<String> dc = new ArrayList();

	public static void main(String[] args) {

		Scanner cin = new Scanner(System.in);
		for (int i = 0; i <= 127; i++) {
			char tmp = (char) i;
			dc.add(tmp + "");
		}
		String num = cin.nextLine();
		String tmp;
		int r = 0;
		for (int i = 0; i < num.length();) {
			if (i != 0)
				i--;
			int t = i;
			r = 0;
			while (r != -1 && i < num.length()) {
				tmp = num.substring(t, i + 1);
				r = dc.indexOf(tmp);
				i++;
			}
			if (i == num.length()) {
				int s = dc.indexOf(num.substring(t, i));
				// System.out.println(num.substring(t, i));
				if (s > -1) {
					System.out.println(dc.indexOf(num.substring(t, i)));
				} else {
					System.out.println(dc.indexOf(num.substring(t, i - 1)));
					System.out.println(dc.indexOf(num.substring(i - 1, i)));
				}
			} else {
				System.out.println(dc.indexOf(num.substring(t, i - 1)));
			}
			dc.add(num.substring(t, i));

		}
	}
}