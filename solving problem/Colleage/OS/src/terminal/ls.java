package terminal;

import java.util.*;
import java.io.*;

public class ls {
	// public static void main(String args[]) {
	//
	// displayIt(new File("C:\\Downloads"));
	// }
	// mats2lnesh gaybha mnen 3shan kolo men el net :D
	public static void displayIt(File node) {
		if (node.isDirectory()) {
			String[] subNote = node.list();
			for (String filename : subNote) {
				System.out.println(filename);
//				System.out.println(node.getAbsoluteFile());
			}
		} else {
			// System.out.println("don't exist");
		}
	}
}
