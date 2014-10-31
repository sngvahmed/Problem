package OS;

import java.io.Writer;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Buffer {

	static ArrayList<String> WriteBuff = new ArrayList<String>();
	static ArrayList<String> ReadBuff = new ArrayList<String>();
	static ArrayList<String> write = new ArrayList<String>();
	static String Word;
	static int RD, WT;
	static Scanner Cin = new Scanner(System.in);

	public static void main(String[] args) {

		System.out.println("Enter Initial Buffer Content :: ");
		Word = Cin.next();

		Semaphore Sm = new Semaphore();

		System.out.println("Enter Numbers of writer threads :: ");
		WT = Cin.nextInt();
		System.out.println("Enter Numbers of Reader threads :: ");
		RD = Cin.nextInt();

		System.out.println("Enter the writer threads ");
		for (int i = 0; i < WT; i++) {
			String x = Cin.next();
			WriteBuff.add(x);
			String tmp = Cin.next();
			write.add(tmp);

		}
		WRITER T1 = new WRITER(Sm, WriteBuff);

		System.out.println("Enter the Reader threads ");
		for (int i = 0; i < RD; i++) {

			String x = Cin.next();
			ReadBuff.add(x);

		}
		READER T2 = new READER(Sm, ReadBuff);

		try {
			T1.start();
		} catch (Exception e) {
		}
		try {
			T2.start();
		} catch (Exception e) {
		}

	}
}

class Semaphore {
	private String CONT;
	boolean AVL = false;

	public synchronized String read() {
		if (AVL == false) {
			System.out.println("BLOCKED");
			try {
				wait();
			} catch (Exception e) {
			}
		}
		AVL = false;
		notify();
		return CONT;
	}

	public synchronized void write(String value) {
		if (AVL == true) {
			System.out.println("BLOCKED");
			try {
				wait();
			} catch (Exception e) {
			}
		}
		CONT = value;
		AVL = true;
		notify();
	}

}

class READER extends Thread {

	private Semaphore Sem;
	private ArrayList<String> Vec = new ArrayList<String>();

	public READER(Semaphore c, ArrayList<String> number) {
		Sem = c;
		this.Vec = number;
	}

	public void run() {
		String value = "";
		for (int i = 0; i < Buffer.RD; i++) {

			System.out.println(this.Vec.get(i) + "---->" + "Ready TO Read");
			value = Sem.read();
			System.out.println(this.Vec.get(i) + "---->" + " read: " + value);
			System.out.println(this.Vec.get(i) + "---->" + "Finshed reading");
		}
	}
}

class WRITER extends Thread {
	private Semaphore Sem;
	private ArrayList<String> Vec = new ArrayList<String>();

	public WRITER(Semaphore c, ArrayList<String> number) {
		Sem = c;
		this.Vec = number;
	}

	public void run() {
		String wr = Buffer.Word;

		for (int i = 0; i < Buffer.WT; i++) {

			System.out.println(this.Vec.get(i) + " --->" + "Ready writing");
			wr += Buffer.write.get(i);
			Sem.write(wr);
			System.out.println(this.Vec.get(i) + "--->" + " write: " + wr);
			System.out.println(this.Vec.get(i) + "--->" + "Finshed writing");
		}
	}
}
