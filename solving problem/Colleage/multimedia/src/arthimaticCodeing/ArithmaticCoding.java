package arthimaticCodeing;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Arrays;

public class ArithmaticCoding {

	private int count[] = new int[129];
	private ArrayList<Double> prob = new ArrayList<Double>();
	private ArrayList<Byte> symbol = new ArrayList<Byte>();
	private ArrayList<Double> cum = new ArrayList<Double>();
	private ArrayList<Double> updated = new ArrayList<Double>();

	ArithmaticCoding() {
		Arrays.fill(count, 0);
	}

	private void build_prob_table(File file) throws IOException {

		RandomAccessFile r = new RandomAccessFile(file, "r");

		int file_size = 0;
		while (r.getFilePointer() != r.length()) {
			byte c = r.readByte();
			count[c]++;
			file_size++;
		}

		for (int i = 0; i < 129; i++) { // calculate prob
			if (count[i] > 0) {
				symbol.add((byte) i);
				prob.add((double) count[i] / (double) file_size);
			}
		}
		double cumulative = 0;
		for (int i = 0; i < prob.size(); i++) { // calculate cumulative prob
			cum.add(prob.get(i) + cumulative);
			System.out.println(symbol.get(i) + " " + prob.get(i));
			cumulative += prob.get(i);
		}
		r.close();
	}

	public void compress(File file) throws IOException {
		build_prob_table(file);

		RandomAccessFile r = new RandomAccessFile(file, "r");
		RandomAccessFile w = new RandomAccessFile(new File(file.getParent()
				+ "\\output.txt"), "rw");
	
		double lower = 0, upper = 1, prev_symbol_prob = 0, cur_symbol_prob = 0;
		int cur = 0, file_size = 0;
		while (r.getFilePointer() != r.length()) { // compress

			byte c = r.readByte();

			cur = symbol.indexOf(c);
			cur_symbol_prob = cum.get(cur);

			if (cur - 1 == -1) { // first time
				prev_symbol_prob = 0;
			} else {
				prev_symbol_prob = cum.get(cur - 1);
			}
			
			double l = lower , u = upper;
			lower = l + (u - l) * prev_symbol_prob;
			upper = l + (u - l) * cur_symbol_prob;
			file_size++;
		}
		double last = (lower + upper) / 2;
		System.out.println(last);
		w.writeInt(symbol.size()); // write the size of the table

		for (int i = 0; i < symbol.size(); i++) { // write table
			w.writeByte(symbol.get(i));
			w.writeDouble(cum.get(i));
		}

		w.writeInt(file_size); // write data length
		w.writeDouble(last);// write the compression prob result

		r.close();
		w.close();
		clear();
	}

	public void Decompress(File file) throws IOException {

		RandomAccessFile r = new RandomAccessFile(file, "r");
		RandomAccessFile w = new RandomAccessFile(file.getParent()
				+ "\\original.txt", "rw");
		
		int table_size = r.readInt();

		for (int i = 0; i < table_size; i++) { // initialize table
			byte s = r.readByte();
			double c = r.readDouble();
			symbol.add(s);
			cum.add(c);
			updated.add(c);
		}

		int len = r.readInt();
		double prob = r.readDouble();
		double lower = 0, upper = 1, prev_symbol_prob = 0, cur_symbol_prob = 0;
		int cur = 0;
		for (int i = 0; i < len; i++) { // number of symbol
			cur = get_cur(prob);
			byte c = symbol.get(cur);
			w.writeByte((char) c);
			cur_symbol_prob = cum.get(cur);
			if (cur == 0)
				prev_symbol_prob = 0;
			else
				prev_symbol_prob = cum.get(cur - 1);
			
			
			double l = lower , u = upper;
			lower = l + (u - l) * prev_symbol_prob;
			upper = l + (u - l) * cur_symbol_prob;

			update_table(lower, upper);

		}
		r.close();
		w.close();
		clear();
	}

	private void update_table(double lower, double upper) {

		for (int i = 0; i < updated.size(); i++) {
			updated.set(i, lower + (upper - lower) * cum.get(i));
		}

	}

	private int get_cur(double p) {

		for (int i = 0; i < updated.size(); i++) {
			if (p <= updated.get(i))
				return i;
		}
		return -1; // for return only (usually found)
	}
	void clear(){
		Arrays.fill(count, 0);
		symbol.clear();
		prob.clear();
		updated.clear();
		cum.clear();
	}
}
