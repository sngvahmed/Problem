package loyad;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class loyad {
	static ArrayList<Integer> num = new ArrayList<Integer>();
	static String kelma = "", union = "";
	static ArrayList<ArrayList<Integer>> que = new ArrayList<ArrayList<Integer>>();
	static ArrayList<Integer> numdec = new ArrayList<Integer>();

	public static int getMid(ArrayList<Integer> nm) {
		int sum = 0;
		for (int i = 0; i < nm.size(); i++) {
			sum += nm.get(i);
		}
		sum = sum / (nm.size());
		return sum;
	}

	public static void BFS(int d) {
		que.add(num);
		int lvl = 0;
		while (que.size() != 0) {
			lvl++;
			int siz = que.size();
			while (true) {
				if (siz == 0)
					break;
				int mid = getMid(que.get(0));
				ArrayList<Integer> tmp1 = new ArrayList<Integer>();
				ArrayList<Integer> tmp2 = new ArrayList<Integer>();
				for (int i = 0; i < que.get(0).size(); i++) {
					if (que.get(0).get(i) > mid)
						tmp1.add(que.get(0).get(i));
					else
						tmp2.add(que.get(0).get(i));
				}
				que.remove(0);
				que.add(tmp2);
				que.add(tmp1);
				siz--;
			}
			if (lvl == d)
				break;
		}
	}

	// 1 2 3 4 :: 4
	// 5 6 7 8 9:: 5
	// 9 10 11 :: 3
	// 11 22 30 :: 3

	public static boolean ch(ArrayList<Integer> sz) {
		for (int i = 0; i < que.size(); i++) {
			if (que.get(i).size() != sz.get(i))
				return false;
		}
		return true;
	}

	public static void LST() {
		ArrayList<Integer> sz = new ArrayList<Integer>();
		do {
			for (int i = 0; i < que.size(); i++) {
				sz.add(que.get(i).size());
			}
			for (int i = 0; i < que.size(); i++) {
				if (i == 0) {
					for (int e = 0; e < que.get(i).size(); e++) {
						if (Math.abs(getMid(que.get(i)) - que.get(i).get(e)) >= Math
								.abs(getMid(que.get(i + 1)) - que.get(i).get(e))) {
							int re = que.get(i).get(e);
							que.get(i).remove(e);
							que.get(i + 1).add(re);
						}
					}
				} else if (i == que.size() - 1) {
					for (int e = 0; e < que.get(i).size(); e++) {
						if (Math.abs(getMid(que.get(i)) - que.get(i).get(e)) >= Math
								.abs(getMid(que.get(i - 1)) - que.get(i).get(e))) {
							int re = que.get(i).get(e);
							que.get(i).remove(e);
							que.get(i - 1).add(re);
						}
					}
				} else {
					for (int e = 0; e < que.get(i).size(); e++) {
						if (Math.abs(getMid(que.get(i)) - que.get(i).get(e)) >= Math
								.abs(getMid(que.get(i + 1)) - que.get(i).get(e))) {
							int re = que.get(i).get(e);
							que.get(i).remove(e);
							que.get(i + 1).add(re);
						} else if (Math.abs(getMid(que.get(i))
								- que.get(i).get(e)) >= Math.abs(getMid(que
								.get(i - 1)) - que.get(i).get(e))) {
							int re = que.get(i).get(e);
							que.get(i).remove(e);
							que.get(i - 1).add(re);
						}
					}
				}
			}
		} while (ch(sz));
	}

	public static int ind(int n) {
		vec tm = new vec();
		for (int i = 0; i < que.size(); i++) {
			if (i == 0) {
				tm.x = -1000000000;
				tm.y = (getMid(que.get(i)) + getMid(que.get(i + 1))) / 2;
			} else if (i == que.size() - 1) {
				tm.x = tm.y;
				tm.y = 10000000;
			} else {
				tm.x = tm.y;
				tm.y = (getMid(que.get(i)) + getMid(que.get(i + 1))) / 2;
			}
			if (n >= tm.x && n <= tm.y)
				return i;
		}
		return 0;
	}

	public static void readInput_comp() {
		Scanner input = null;
		try {
			input = new Scanner(new File("in.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
			return;
		}
		while (input.hasNext()) {
			int x = input.nextInt();
			// System.out.println(x);
			num.add(x);
		}
		return;
	}

	static public void writeInput_comp() {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("qout.txt"), "utf-8"));
			for (int i = 0; i < num.size(); i++) {
				writer.write(num.get(i) + " :: " + ind(num.get(i)) + "\n");
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

	static void dec() {
		for (int i = 0; i < que.size(); i++) {
			numdec.add(getMid(que.get(i)));
		}
		for (int i = 0; i < num.size(); i++) {
			System.out.println(num.get(i) + " :: "
					+ numdec.get(ind(num.get(i))));
		}

	}

	public static void main(String[] args) {
		readInput_comp();
		BFS(2);
		LST();
		writeInput_comp();
		dec();
	}
}
/*
 * 2 20 7 6 12 8 3 4 7 14 3
 */