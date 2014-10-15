package terminal;

import java.util.*;
import java.io.*;

public class move {
	public static void Movenew(String S, String D) {
		File file = new File(S);
		File dir = new File(D);
		boolean success = file.renameTo(new File(dir, file.getName()));
		if (!success)
			System.out.print("not good");
	}
}
