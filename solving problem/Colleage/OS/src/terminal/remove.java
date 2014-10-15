package terminal;

import java.util.*;
import java.io.*;

public class remove {
	public static void removeFL(File file) { // to remove file
		try {
			if (file.delete()) {
				System.out.println(file.getName() + " DoNe");
			} else {
				System.out.println("failed!!! please check the file name :)");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void removeDic(File file) throws IOException {
		if (file.isDirectory()) {
			// directory is empty, then delete it
			if (file.list().length == 0) {
				if (file.delete()) {
					System.out.println(file.getName() + " DoNe");
				} else {
					System.out.println("failed!!! please check the file name");
				}
			} else {
				// list all the directory contents
				String files[] = file.list();
				for (String temp : files) {
					// construct the file structure
					File fileDelete = new File(file, temp);
					// recursive delete
					removeDic(fileDelete);
				}
				// check the directory again, if empty then delete it
				if (file.list().length == 0) {
					file.delete();
					System.out.println("Directory is deleted : "
							+ file.getAbsolutePath());
				}
			}
		} else {
			// if file, then delete it
			file.delete();
			System.out.println("File is deleted : " + file.getAbsolutePath());
		}
	}

}
