package esraa;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class arithmetic {

	public static class pair {
		public int upper, lower;
	}

	static int n;
	static ArrayList<Integer> num = new ArrayList<Integer>();
	static ArrayList<String> word = new ArrayList<String>();
	static ArrayList<pair> rang = new ArrayList<pair>();
	static ArrayList<Integer> qun = new ArrayList<Integer>();
	static String Dec = "";
	static int step;
	static int max;
	static int min;

	// static int level;

	public static void prob1(String nm, int count, int des) {
		if (nm.length() == des) {
			word.add(nm);
		}
		if (count >= des)
			return;
		prob1(nm + "0", count = count + 1, des);
		prob1(nm + "1", count = count + 1, des);
	}

	public static void prob2(String nm, int count, int des) {
		if (nm.length() == des) {
			word.add(nm);
		}
		if (count >= des)
			return;
		prob2(nm + "1", count = count + 1, des);
		prob2(nm + "0", count = count + 1, des);
	}

	public static void compression(int level) {
		try {
			Scanner input = null;
			input = new Scanner(new File("J:\\qin.txt"));
			while (input.hasNext()) {

				int data = input.nextInt();
				num.add(data);
				// System.out.println(" :: " + data);
				min = num.get(0);
				max = num.get(0);

			}
			for (int i = 0; i < num.size(); i++) {
				if (i == num.size() - 1) {
					break;
				}
				if ((num.get(i) < min)) {

					min = num.get(i);

				}
			}
			// System.out.print("min=");
			// System.out.println(min);
			for (int i = 0; i < num.size(); i++) {
				if (i == num.size() - 1) {
					break;
				}
				if ((num.get(i) > max)) {

					max = num.get(i);

				}
			}
			// System.out.print("max=");
			// System.out.println(max);
			step = (max - min) / level;
			// System.out.print("step=");
			// System.out.println(step);

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		int level;
		System.out.println("enter the number of bits");
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		level = (int) Math.pow(2, n);
		System.out.print("level=");
		System.out.println(level);
		compression(level);
		int low = 0;
		while (low < max) {
			pair tmp = new pair();
			tmp.lower = low;
			tmp.upper = tmp.lower + step;
			rang.add(tmp);
			low = tmp.upper + 1;
		}
		for (int i = 0; i < rang.size(); i++) {
			System.out.print(rang.get(i).lower);
			System.out.print(":");
			System.out.print(rang.get(i).upper);
			System.out.println();
		}

		for (int i = 0; i < rang.size(); i++) {
			if (num.get(i) >= rang.get(i).lower
					&& num.get(i) <= rang.get(i).upper) {
				System.out.println(word.get(i));
			}
		}

	}

}
