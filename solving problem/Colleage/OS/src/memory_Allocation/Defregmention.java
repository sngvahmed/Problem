package memory_Allocation;

import java.util.*;

public class Defregmention {
	static Scanner cin = new Scanner(System.in);

	public static int defregmantion(String in) {
		String input = in;
		if (input.equals("case-1")) {
			int sz = memory_allocation.MEM.size();
			for (int i = 0; i < sz; i++) {
				if (memory_allocation.MEM.get(i).size_allocation < memory_allocation.MEM
						.get(i).size
						&& memory_allocation.MEM.get(i).size_allocation != 0) {
					memory tmp = new memory(
							memory_allocation.MEM.get(i).st
									+ memory_allocation.MEM.get(i).size_allocation,
							memory_allocation.MEM.get(i).size
									- memory_allocation.MEM.get(i).size_allocation,
							0, 'f');
					memory_allocation.MEM.get(i).size = memory_allocation.MEM
							.get(i).size_allocation;
					memory_allocation.MEM.add(i + 1, tmp);
				}
			}
			return 1;
		} else if (input.equals("case-2")) {
			int sz = memory_allocation.MEM.size();
			for (int i = 0; i < sz - 1; i++) {
				memory m1 = memory_allocation.MEM.get(i);
				memory m2 = memory_allocation.MEM.get(i + 1);
				if (m1.size_allocation == 0 && m2.size_allocation == 0) {
					m1.size += m2.size;
					memory_allocation.MEM.remove(i + 1);
					i--;
				}
			}
			return 2;
		} else if (input.equals("case-3")) {
			int sz = memory_allocation.MEM.size();
			int free = 0;
			for (int i = 0; i < memory_allocation.MEM.size(); i++) {
				memory m1 = memory_allocation.MEM.get(i);
				if (m1.size_allocation == 0) {
					free = free + m1.size;
					memory_allocation.MEM.remove(i);
					i--;
				}
			}
			if (free > 0) {
				sz = memory_allocation.MEM.size();
				int s = 0;
				for (int i = 0; i < sz; i++) {
					memory m1 = memory_allocation.MEM.get(i);
					m1.st = s;
					s = s + m1.size;
				}
				memory tmp = new memory(s, free, 0, 'f');
				memory_allocation.MEM.add(tmp);
			}
			return 3;
		}
		return 0;
	}
}
// memory_allocation.MEM