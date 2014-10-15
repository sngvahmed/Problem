package terminal;

import java.io.File;
import java.io.Console;
import java.io.IOException;
import java.util.Scanner;

public class terminal {
	public static Scanner cin = new Scanner(System.in);

	public static void copy(String x, String y) {
		File srcFolder = new File(x);
		File destFolder = new File(y);
		if (!srcFolder.exists()) {
			System.out.println("Directory does not exist.");
			// just exit
			System.exit(0);
		}
		try {
			cpy.cp(srcFolder, destFolder);
		} catch (Exception e) {
			// TODO: handle exception
		}
	}

	public static String cdfun(String path) {
		String nex = cin.next();
		if (nex.equals("..")) {
			path = cd.cdBK(path);
		} else {
			String tmp = "";
			if (path.length() == 1)
				tmp = path + nex;
			else
				tmp = path + "/" + nex;
			nex = path;
			path = cd.cdfun(tmp, new File(path));
			if (nex.equals(path)) {
				System.out.println("error distanation try again");
			}
		}
		return path;
	}

	public static void lsfun(String path) {
		ls.displayIt(new File(path));
	}

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

	public static String movefn(String path) {
		lsfun(path);
		String s = path;
		String d = "";
		System.out.println();
		System.out.print("enter your folder name :: ");
		String tmp = cin.next();
		s += "/";
		s += tmp;
		System.out.println();
		System.out.print("enter your des :: ");
		d = cin.next();
		System.out.println("S :: " + s);
		System.out.println("D :: " + d);
		move.Movenew(s, d);
		return path;
	}

	public static String copyfn(String path) {
		lsfun(path);
		String s = path;
		String d = "";
		System.out.println();
		System.out.print("enter your folder name :: ");
		String tmp = cin.next();
		s += "/";
		s += tmp;
		System.out.println();
		System.out.print("enter your des :: ");
		d = cin.next();
		System.out.println();
		copy(s, d);
		return path;
	}

	static public void main(String[] args) throws IOException {
		int curline = 0;
		String path = "/home/ahmed";
		while (true) {
			System.out.print("enter your command :: ");
			String command = cin.next();
			if (command.equals("copy")) {
				path = copyfn(path);
			} else if (command.equals("data") || command.equals("Data")) {
				data.Date();
			} else if (command.equals("ls")) {
				lsfun(path);
			} else if (command.equals("pwd")) {
				System.out.println(new File(path).getAbsolutePath());
			} else if (command.equals("cd")) {
				path = cdfun(path);
			} else if (command.equals("clear")) {
				clearConsole();
			} else if (command.equals("more")) {
				curline = more.mor(new File(path), curline);
			} else if (command.equals("move")) {
				path = movefn(path);
			} else if (command.equals("less")) {
				curline = Less.les(new File(path), curline);
			} else if (command.equals("rmvfile")) {
				remove.removeFL(new File(path));
			} else if (command.equals("rmvFolder")) {
				remove.removeDic(new File(path));
			} else {
				System.out.println("error command try again");
			}
		}
	}
};