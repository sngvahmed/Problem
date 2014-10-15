package terminal;

import java.util.*;
import java.io.*;

public class Less {
	public static void clearConsole() {
		for (int i = 0; i < 50; ++i)
			System.out.println("");

		try {
			String os = System.getProperty("os.name");

			if (os.contains("Windows")) {
				Runtime.getRuntime().exec("cls");
			} else {
				Runtime.getRuntime().exec("clear");
			}
		} catch (Exception exception) {
			// Handle exception.
		}
	}

	public static int les(File src, int curline) throws IOException {
		int i = 0, c = 0;
		String str = null;
		Scanner cin;
		try {
			cin = new Scanner(new FileInputStream(src));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.err.println("Error 404 !");
			return -1;
		}
		clearConsole();
		while (cin.hasNext()) {
			str = "";
			str = cin.nextLine();
			if (i >= Math.max(curline - 20, 0) && c < 20) {
				c++;
				System.out.println(str + "\n");
			} else if (c == 20)
				break;
			i++;
		}
		return i;
	}
}
