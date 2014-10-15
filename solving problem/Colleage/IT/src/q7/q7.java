package q7;

public class q7 {
	static int arrI[][] = new int[4][4];
	static int ret[] = new int[4];

	public static void intialize() {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++, count++)
				arrI[i][j] = count;
		}
		for (int i = 0; i < 4; i++)
			ret[i] = 0;
	}

	static void GetRMD() {
		for (int i = 0; i < 4; i++) {
			int tot = 0;
			for (int j = 0; j < 4; j++) {
				tot = tot + arrI[j][i];
			}
			ret[i] = (ret[i] + tot) % 26;
		}
	}

	static void shifting() {
		int shift = 1;
		for (int i = 0; i < 4; i++) {
			int tmp[] = new int[4];
			if (shift == 4) {
				shift = 0;
				for (int j = 0; j < 4; j++) {
					tmp[j] = arrI[i][j];
				}
				int jj = 0;
				for (int j = 3; j >= 0; j--, jj++) {
					arrI[i][jj] = tmp[j];
				}
			} else {
				for (int j = 0; j < 4; j++) {
					tmp[j] = arrI[i][(j + shift) % 4];
				}
				for (int j = 0; j < 4; j++) {
					arrI[i][j] = tmp[j];
				}
			}
			shift++;
		}
	}

	static void showArrI() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(arrI[i][j] + " ");
			}
			System.out.println();
		}
	}

	static void retrn() {
		for (int i = 0; i < 4; i++) {
			System.out.print(ret[i] + " ");
			ret[i] = ret[i] + 'A';
			char tmp = (char) ret[i];
			System.out.print(ret[i] + " " + tmp);
			System.out.println();
		}
	}

	static void showRet() {
		for (int i = 0; i < 4; i++)
			System.out.print(ret[i] + " :: ");
		System.out.println();
	}

	public static void main(String[] args) {
		intialize();
		GetRMD();
		 showRet();
		shifting();
		// showArrI();
		GetRMD();
		 showRet();
		retrn();
	}
}
