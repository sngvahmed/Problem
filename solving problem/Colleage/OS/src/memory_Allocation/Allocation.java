package memory_Allocation;

import java.util.*;

public class Allocation {
	static Scanner cin = new Scanner(System.in);

	public static void Change(int indx, memory y) {
		memory_allocation.MEM.get(indx).size = y.size;
		memory_allocation.MEM.get(indx).size_allocation = y.size_allocation;
		memory_allocation.MEM.get(indx).st = y.st;
		memory_allocation.MEM.get(indx).status = y.status;
	}

	public static int Allocationfun() {
		String input;
		System.out.println("******Memory Allocation******");
		System.out.print("enter your Method :: ");
		input = cin.nextLine();
		int mx = 0;
		for (int i = 0; i < memory_allocation.MEM.size(); i++)
			mx = Math.max(mx, memory_allocation.MEM.get(i).size);
		if (input.equals("best fit")) {
			System.out.print("enter your size :: ");
			int HW = cin.nextInt();
			if (HW > mx)
				return 3;
			int DIff = 1000000000, indx = 0;
			for (int i = 0; i < memory_allocation.MEM.size(); i++) {
				if ((memory_allocation.MEM.get(i).size - HW) < DIff) {
					indx = i;
					DIff = (memory_allocation.MEM.get(i).size - HW);
				}
			}
			Change(indx, new memory(memory_allocation.MEM.get(indx).st,
					memory_allocation.MEM.get(indx).size, HW, 'O'));
			return 1;
		} else if (input.equals("worst fit")) {
			System.out.print("enter your size :: ");
			int HW = cin.nextInt();
			if (HW > mx)
				return 3;
			int DIff = 0, indx = 0;
			for (int i = 0; i < memory_allocation.MEM.size(); i++) {
				if ((memory_allocation.MEM.get(i).size - HW) > DIff) {
					indx = i;
					DIff = (memory_allocation.MEM.get(i).size - HW);
				}
			}
			Change(indx, new memory(memory_allocation.MEM.get(indx).st,
					memory_allocation.MEM.get(indx).size, HW, 'O'));
			return 1;
		} else if (input.equals("first fit")) {
			System.out.print("enter your size :: ");
			int SZ_INPUT = cin.nextInt();
			if (SZ_INPUT > mx)
				return 3;
			int i;
			for (i = 0; i < memory_allocation.MEM.size(); i++) {
				if (memory_allocation.MEM.get(i).status == 'f'
						&& memory_allocation.MEM.get(i).size >= SZ_INPUT)
					break;
			}
			Change(i, new memory(memory_allocation.MEM.get(i).st,
					memory_allocation.MEM.get(i).size, SZ_INPUT, 'O'));
			return 1;
		}
		return 2;
	}
}
