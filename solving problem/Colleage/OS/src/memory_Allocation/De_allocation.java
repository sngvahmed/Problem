package memory_Allocation;

import java.util.Scanner;

public class De_allocation {

	static Scanner cin = new Scanner(System.in);

	static Boolean Deallocation(int indx) {
		if (memory_allocation.MEM.size() > indx && indx >= 0) {
			memory_allocation.MEM.get(indx).size_allocation = 0;
			memory_allocation.MEM.get(indx).status = 'f';
			return true;
		}
		return false;
	}
}
