package memory_Allocation;

import java.util.*;

public class memory_allocation {
	static ArrayList<memory> MEM = new ArrayList<memory>();
	static Scanner cin = new Scanner(System.in);
	static Allocation Alocate = new Allocation();
	static De_allocation dealocate = new De_allocation();
	static Defregmention Defgrament = new Defregmention();

	public static void show_MEM() {
		for (int i = 0; i < MEM.size(); i++) {
			System.out.println("INDX :: " + (i + 1));
			MEM.get(i).show();
			System.out.println("***************");
		}
	}

	public static void main(String[] args) {

		System.out.print("enter memory size :");
		int memory_size = cin.nextInt();
		MEM.add(new memory(0, memory_size, 0, 'f'));
		while (true) {
			System.out.println("1-Allocation && 2-De-allocation"
					+ " && 3-Defrgmention");
			System.out.print("enter Command ::");
			String input = cin.next();
			if (input.equals("exit")) {
				return;
			}
			if (input.equals("Allocation")) {
				Defgrament.defregmantion("case-1");
				Defgrament.defregmantion("case-2");
				int tmp = Alocate.Allocationfun();
				if (tmp == 1) {
					System.out.println("DONE ALLOCATION");
				} else if (tmp == 2) {
					System.out.println("ERROR COMMAND");
				} else if (tmp == 3) {
					System.out.println("wasn't space try Defrgmention");
				}
			} else if (input.equals("De-allocation")) {
				show_MEM();
				System.out.print("enter indx of it please :");
				int indx = cin.nextInt();
				System.out.println();
				if (dealocate.Deallocation(indx - 1)) {
					System.out.println("DONE DE_ALLOCATION");
				} else {
					System.out.println("THERE WAS ERROR :'(");
				}
			} else if (input.equals("show")) {
				show_MEM();
			} else if (input.equals("Defrgmention")) {
				String inputt;
				inputt = cin.next();
				int Def = Defgrament.defregmantion(inputt);
				if (Def == 1) {
					System.out.println("DONE with case 1");
				} else if (Def == 2) {
					System.out.println("DONE with case 2");
				} else if (Def == 3) {
					System.out.println("DONE with case 3");
				} else {
					System.out.println("ERROR");
				}
			}
		}
	}
}
