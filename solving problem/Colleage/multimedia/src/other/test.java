//package linear_quantizer;
//
//import java.io.BufferedReader;
//import java.io.FileReader;
//import java.io.IOException;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Scanner;
//
//public class Linear_quantizer {
//
//	public static class pair {
//		public int upper, lower;
//	}
//
//	static int n;
//	static ArrayList<String> num = new ArrayList<String>();
//	static String max;
//	static String min;
//
//	public static void readfile() {
//		try {
//			min = num.get(0);
//			BufferedReader br = new BufferedReader(
//					new FileReader("J:\\qin.txt"));
//			String sCurrentLine;
//			while ((sCurrentLine = br.readLine()) != null) {
//				String data = sCurrentLine;
//				num.add(data);
//				System.out.println(" :: " + data);
//				for (int i = 0; i < num.size(); i++) {
//					if (i == num.size() - 1) {
//						break;
//					}
//					if ((num.get(i) < min)) {
//
//						min = num.get(i);
//
//					}
//					System.out.print("min=");
//					System.out.println(min);
//
//				}
//
//			}
//
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//	}
//
//	public static void main(String[] args) {
//		System.out.println("enter the number of bits");
//		Scanner in = new Scanner(System.in);
//		n = in.nextInt();
//		readfile();
//
//	}
// }
