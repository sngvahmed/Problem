package linear_quantizer;

import java.util.*;
import java.io.*;
// decoutq.txt for dec output
// qin.txt for comp input
// qindc.txt for dec input
// qout.txt for comp output

public class linear_quantizer {
	static int n_bits = 0, step;
	static ArrayList<Integer> num = new ArrayList<Integer>();
	static ArrayList<String> word = new ArrayList<String>();
	static ArrayList<range> rang = new ArrayList<range>();
	static ArrayList<Integer> qun = new ArrayList<Integer>();
	static String Dec = "";

	public static void BuildString1(String nm, int count, int des) {
		if (nm.length() == des * 2) {
			word.add(nm);
		}
		if (count >= des * 2)
			return;
		BuildString1(nm + "1", count = count + 1, des);
		BuildString1(nm + "0", count = count + 1, des);
	}

	public static void BuildString2(String nm, int count, int des) {
		if (nm.length() == des * 2) {
			word.add(nm);
		}
		if (count >= des * 2)
			return;
		BuildString2(nm + "0", count = count + 1, des);
		BuildString2(nm + "1", count = count + 1, des);
	}

	public static void readInput_comp() {
		Scanner input = null;
		try {
			input = new Scanner(new File("qin.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
			return;
		}
		n_bits = input.nextInt();
		while (input.hasNext()) {
			int x = input.nextInt();
			// System.out.println(x);
			num.add(x);
		}
		return;
	}

	public static String readInput_dec() {
		Scanner input = null;
		try {
			input = new Scanner(new File("qindc.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
		}
		String line = "";
		while (input.hasNext()) {
			line = input.next();
		}
		return line;
	}

	static void Show(ArrayList<range> num) {
		for (int i = 0; i < rang.size(); i++)
			System.out.println(rang.get(i).up + " :: " + rang.get(i).down);
		System.out.println();
	}

	static public String check(int x) {
		for (int i = 0; i < rang.size(); i++) {
			if (x >= rang.get(i).down && x <= rang.get(i).up) {
				return word.get(i);
			}
		}
		return "";
	}

	static public void writeInput_comp() {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("qout.txt"), "utf-8"));
			for (int i = 0; i < num.size(); i++) {
				writer.write(check(num.get(i)));
			}
		} catch (IOException ex) {
			// report
		} finally {
			try {
				writer.close();
			} catch (Exception ex) {
			}
		}
	}

	static public void writeinput_dec(String dec) {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("decoutq.txt")));
			for (int i = 0; i < dec.length(); i = i + 2) {
				String tm = dec.substring(i, i + 2);
				System.out.println(tm + " " + qun.get(word.indexOf(tm)));
				writer.write(qun.get(word.indexOf(tm)).toString());
			}
		} catch (IOException ex) {
			// report
		} finally {
			try {
				writer.close();
			} catch (Exception ex) {
			}
		}
	}

	static public void builtQ() {
		// System.out.println("in");
		for (int i = 0; i < rang.size(); i++)
			qun.add((rang.get(i).up + rang.get(i).down) / 2);
		// System.out.println("out");
	}

	static public void main(String[] args) {
		readInput_comp();
		int pwr = (int) Math.pow(2, n_bits);
		Collections.sort(num);
		step = num.get(num.size() - 1) - num.get(0);
		step = step / pwr;
		BuildString1("", 0, n_bits / 2);
		BuildString2("", 0, n_bits / 2);
		int low = 0;
		while (low < num.get(num.size() - 1)) {
			range rng = new range();
			if (low == 0) {
				rng.down = low;
				rng.up = low + step;
			} else {
				rng.down = rang.get(rang.size() - 1).up + 1;
				rng.up = rng.down + step;
			}
			low = rng.up;
			rang.add(rng);
		}
		for (int i = 0; i < rang.size(); i++) {
			System.out.println(rang.get(i).down + " -> " + rang.get(i).up);
		}
		// System.out.println(word.size() + " " + rang.size());
		builtQ();
		// System.out.println("1");
		writeInput_comp();
		// System.out.println("2");
		Dec = readInput_dec();
		// System.out.println("3");
		writeinput_dec(Dec);
		// System.out.println("4");
	}
}
