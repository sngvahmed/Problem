package arthmetic;

import java.util.*;
import java.io.*;

public class arthmetic {
	static Scanner input;
	static Scanner cin = new Scanner(System.in);
	static ArrayList<String> wd = new ArrayList<String>();
	static ArrayList<pair> pb = new ArrayList<pair>();
	static ArrayList<pair> tm = new ArrayList<pair>();
	static String wod = "", num = "";

	static public String readInput() {
		try {
			input = new Scanner(new File("arthinput.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
			return "";
		}
		String Line = "";
		while (input.hasNext()) {
			Line = input.next();
		}
		input.close();
		return Line;
	}

	static public double bond(double l, double u, double x) {
		return l + ((u - l) * x);
	}

	public static void copy() {
		tm.clear();
		for (int i = 0; i < pb.size(); i++) {
			pair pp = new pair();
			pp.x = pb.get(i).x;
			pp.y = pb.get(i).y;
			tm.add(pp);
		}
	}

	static public void writeInputdcomp(String Kelma) {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("arthmetic_decomp_out.txt"), "utf-8"));
			writer.write(Kelma);
		} catch (IOException ex) {
			// report
		} finally {
			try {
				writer.close();
			} catch (Exception ex) {
			}
		}
	}

	static public void writeInputcomp(String Kelma) {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("arthmetic_comp_out.txt"), "utf-8"));
			writer.write(Kelma);
		} catch (IOException ex) {
			// report
		} finally {
			try {
				writer.close();
			} catch (Exception ex) {
			}
		}
	}

	public static String dec(double cod) {
		copy();
		String ret = "";
		for (int i = 0; i < wod.length(); i++) {
			int rr = 0;
			for (int e = 0; e < tm.size(); e++) {
				if (tm.get(e).y >= cod && tm.get(e).x <= cod) {
					rr = e;
					break;
				}
			}
			ret += wd.get(rr);
			double x1 = tm.get(rr).x;
			double y1 = tm.get(rr).y;
			for (int j = 0; j < wd.size(); j++) {
				tm.get(j).x = bond(x1, y1, tm.get(j).x);
				tm.get(j).y = bond(x1, y1, tm.get(j).y);
			}
		}
		writeInputdcomp(ret);
		return ret;
	}

	public static double comp() {
		copy();
		for (int i = 0; i < wod.length(); i++) {
			for (int n = 0; n < pb.size(); n++) {
				System.out.println(wd.get(n) + " l :: " + tm.get(n).x
						+ " U :: " + tm.get(n).y + " ");
			}
			System.out.println();
			double x1 = tm.get(wd.indexOf(wod.charAt(i) + "")).x;
			double y1 = tm.get(wd.indexOf(wod.charAt(i) + "")).y;
			for (int j = 0; j < wd.size(); j++) {
				tm.get(j).x = bond(x1, y1, tm.get(j).x);
				tm.get(j).y = bond(x1, y1, tm.get(j).y);
				// System.out.println(tm.get(i).x + " :: " + tm.get(i).x);
			}
		}
		double xx = tm.get(wd.indexOf(wod.charAt(wod.length() - 1) + "")).x;
		double yy = tm.get(wd.indexOf(wod.charAt(wod.length() - 1) + "")).y;
		System.out.println((xx + yy) / 2);
		xx = (xx + yy) / 2;
		String total2 = Double.toString(xx);
		writeInputcomp(total2);
		return ((xx + yy) / 2);
	}

	static public boolean ch(char x, String num) {
		for (int i = 0; i < num.length(); i++) {
			if (num.charAt(i) == x)
				return true;
		}
		return false;
	}

	static public void showPb() {
		for (int i = 0; i < pb.size(); i++) {
			System.out.println(pb.get(i).x + " " + pb.get(i).y);
		}
	}

	static public void main(String[] args) {
		wod = readInput();
		for (int i = 0; i < wod.length(); i++) {
			if (num.indexOf(wod.charAt(i)) == -1) {
				num += wod.charAt(i) + "";
			}
		}
		char[] ar = num.toCharArray();
		Arrays.sort(ar);
		num = String.valueOf(ar);
		ArrayList<Double> tmp = new ArrayList<Double>();
		for (int i = 0; i < num.length(); i++)
			tmp.add(0.0);
		for (int i = 0; i < wod.length(); i++) {
			tmp.set(num.indexOf(wod.charAt(i)),
					tmp.get(num.indexOf(wod.charAt(i))) + 1);
		}
		for (int i = 0; i < num.length(); i++) {
			double tmp2 = tmp.get(i) / wod.length();
			wd.add(num.charAt(i) + "");
			if (i == 0) {
				pair tp = new pair();
				tp.x = 0;
				tp.y = tmp2;
				pb.add(tp);
			} else if (i == num.length() - 1) {
				pair tp = new pair();
				tp.y = 1;
				tp.x = 1 - tmp2;
				pb.add(tp);
			} else {
				pair tp = new pair();
				tp.x = pb.get(pb.size() - 1).y;
				tp.y = tp.x + tmp2;
				pb.add(tp);
			}
		}
		showPb();
		// comprission ::
		System.out.println();
		System.out.println();
		System.out.println();
		// decomprission
		dec(comp());
	}
}
