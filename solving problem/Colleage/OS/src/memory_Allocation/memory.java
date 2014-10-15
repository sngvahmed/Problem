package memory_Allocation;

class memory {

	public int st, size, size_allocation;
	public char status;

	public memory(int st, int size, int szAllocation, char status) {
		this.st = st;
		this.size = size;
		this.size_allocation = szAllocation;
		this.status = status;
	}

	public void show() {
		System.out.println("Start Mem addrs " + st + " Size " + size);
		System.out.println("Size of allocat " + size_allocation + " Status "
				+ status);

	}
	// st = Starting Memory address
	// size = Size of whole partition
	// size_allocation = Size of allocated memory within the partition
	// status = Status of partition (either occupied or free)
};
