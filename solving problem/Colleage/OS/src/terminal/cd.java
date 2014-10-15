package terminal;

import java.util.*;
import java.io.*;

public class cd {
	public static String cdBK(String to) {
		if (to.length() == 1)
			return to;
		int i = 0;
		for (i = to.length() - 1; i >= 0; i--) {
			if (to.charAt(i) == '/')
				break;
		}
		if (i == 0) {
			to = to.substring(0, i + 1);
		} else
			to = to.substring(0, i);
		return to;
	}

	public static String cdfun(String to, File srcFile) {
		if (to.length() == 1)
			return to;
		if (srcFile.isDirectory()) {
			String files[] = srcFile.list();
			for (String file : files) {
				// construct the src and dest file structure
				File src = new File(srcFile, file);
				if (src.getPath().equals(to))
					return to;
			}
		}
		to = cdBK(to);
		return to;
	}
}
