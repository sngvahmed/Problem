package terminal;

import java.util.*;
import java.io.*;

public class readfile {
	public static void args() {
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"E:\\args.txt"));
			String sCurrentLine;
			while ((sCurrentLine = br.readLine()) != null) {
				System.out.println(sCurrentLine);
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
