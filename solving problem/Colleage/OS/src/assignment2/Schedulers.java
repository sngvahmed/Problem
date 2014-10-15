package assignment2;

import java.util.*;

class process {
	String Name;
	int Arival, Burst, Response;

	process() {
		Name = null;
		Arival = Burst = Response = 0;
	}

	process(String nm, int ar, int bur) {
		Name = nm;
		Arival = ar;
		Burst = bur;
	}

	static void FIFC(Vector<process> V) {
		int i, j, n = V.size(), cur = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (V.get(i).Arival > V.get(j).Arival) {
					process tmp = V.get(i);
					V.set(i, V.get(j));
					V.set(j, tmp);
				}
			}
		}
		cur = V.get(0).Arival;
		for (i = 0; i < n; i++) {
			cur += V.get(i).Burst;
			System.out.println(V.get(i).Name + " " + cur);
			if (i < n - 1) {
				if (cur < V.get(i + 1).Arival)
					cur = V.get(i).Arival;
			}
		}
		System.out.println("Average Response time = "
				+ Math.ceil((double) cur / (double) n));
	}

	static void SJF(Vector<process> V) {
		int i, j, n = V.size(), cur = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (V.get(i).Burst > V.get(j).Burst) {
					process tmp = V.get(i);
					V.set(i, V.get(j));
					V.set(j, tmp);
				}
			}
		}
		for (i = 0; i < n; i++) {
			cur += V.get(i).Burst;
			System.out.println(V.get(i).Name + " " + cur);
		}
		System.out.println("Average Response time = "
				+ Math.ceil((double) cur / (double) n));
	}

	static void RR(Vector<process> V, int Quantum) {
		int i, j, n = V.size(), cur = 0;

		while (true) {
			for (i = 0; i < V.size(); i++) {
				for (j = i + 1; j < V.size(); j++) {
					if (V.get(i).Arival > V.get(j).Arival) {
						process tmp = V.get(i);
						V.set(i, V.get(j));
						V.set(j, tmp);
					}
				}
			}
			cur += Quantum;
			if (cur == n)
				break;
		}
		System.out.println("Average Response time = "
				+ Math.ceil((double) cur / (double) n));
	}
}

public class Schedulers {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int i, n = cin.nextInt();
		String name;
		int arrival, burst;
		Vector<process> V = new Vector<process>();
		for (i = 0; i < n; i++) {
			name = cin.next();
			arrival = cin.nextInt();
			burst = cin.nextInt();
			V.add(new process(name, arrival, burst));
		}
		System.out.println("Choose the type of Scheduling: (FIFC, SJF, RR)");
		name = cin.next();
		if (name.equals("FIFC"))
			process.FIFC(V);
		else if (name.equals("SJF"))
			process.SJF(V);
		else {
			int quantum = cin.nextInt();
			process.RR(V, quantum);
		}
	}
}
