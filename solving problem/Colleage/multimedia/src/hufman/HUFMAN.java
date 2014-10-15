package hufman;

import java.util.*;
import java.io.*;

public class HUFMAN {
	static HashMap<Integer, String> n = new HashMap<Integer, String>();
	static HashMap<String, String> dec = new HashMap<String, String>();
	static boolean f = true;
	static Scanner input;
	static PrintWriter writer;
	static HashMap<String, String> WK = new HashMap<String, String>();
	static String kelma;

	static public void BBS(ArrayList<Integer> value, int valk, int vals) {
		if (value.size() == 1)
			return;
		Collections.sort(value);
		vals = value.get(1);
		value.set(1, value.get(0) + value.get(1));
		valk = value.get(1);
		value.remove(0);
		BBS(value, valk, vals);
		if (f == true) {
			f = false;
			n.put(valk, "");
		}
		int ve = valk - vals;
		value.set(value.indexOf(valk), ve);
		n.put(ve, n.get(valk) + "0");
		n.put(vals, n.get(valk) + "1");
		value.add(vals);
		Collections.sort(value);
		n.put(valk, "");
	}

	static public void writeInput() {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("out.txt"), "utf-8"));
			for (int i = 0; i < kelma.length(); i++) {
				writer.write(WK.get(kelma.charAt(i) + ""));
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

	static public String readInput() {

		try {
			input = new Scanner(new File("compinput.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
			return "";
		}
		String Line = "";
		while (input.hasNext()) {
			Line = input.next();
		}
		return Line;
	}

	static void decompression() {
		try {
			input = new Scanner(new File("decinput.txt"));
		} catch (Exception e) {
			System.out.println("Error !!!!");
			return;
		}
		String Line = "";
		while (input.hasNext()) {
			Line = input.next();
		}

		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("decout.txt"), "utf-8"));
			System.out.println(Line);
			for (int i = 0; i < Line.length(); i++) {
				int r = i + 1;
				while (r <= Line.length()) {
					if (dec.get(Line.substring(i, r) + "") != null) {
						writer.write(dec.get(Line.substring(i, r)) + "");
						break;
					}
					r++;
				}
				i = r - 1;
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

	static public void main(String[] args) {
		ArrayList<Integer> num = new ArrayList<Integer>();
		HashMap<String, Integer> FNL = new HashMap<String, Integer>();
		String numms = "";
		kelma = readInput();
		for (int i = 0; i < kelma.length(); i++) {
			FNL.put(kelma.charAt(i) + "", 0);
			if (numms.indexOf(kelma.charAt(i)) == -1) {
				numms += kelma.charAt(i) + "";
			}
		}
		for (int i = 0; i < kelma.length(); i++) {
			int r = FNL.get(kelma.charAt(i) + "") + 1;
			FNL.put(kelma.charAt(i) + "", r);
		}
		for (int i = 0; i < numms.length(); i++) {
			num.add(FNL.get(numms.charAt(i) + ""));
		}
		BBS(num, 0, 0);
		for (int i = 0; i < numms.length(); i++) {
			WK.put(numms.charAt(i) + "", n.get(FNL.get(numms.charAt(i) + "")));
			dec.put(n.get(FNL.get(numms.charAt(i) + "")), numms.charAt(i) + "");
		}
		for (int i = 0; i < numms.length(); i++) {
			System.out.println(numms.charAt(i) + " "
					+ WK.get(numms.charAt(i) + ""));
		}
		writeInput();
		decompression();
	}
}
