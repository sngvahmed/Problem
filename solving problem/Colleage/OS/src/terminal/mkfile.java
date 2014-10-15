package terminal;

import java.util.*;
import java.io.*;

public class mkfile {
	public static void MKdir(File file) {
		if (!file.exists()) {
			if (file.mkdir()) {
				System.out.println("created success");
			} else {
				System.out.println("Failed ");
			}
		}
	}
}
