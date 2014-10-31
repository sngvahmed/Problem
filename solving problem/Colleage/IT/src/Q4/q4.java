package Q4;

import java.math.BigInteger;

public class q4 {

	static BigInteger K1, K0, P, MOD;
	static String text, key;

	static public void set(String x, String y) {
		text = x;
		key = y;
		MOD = new BigInteger("4294967296");
		P = new BigInteger(text, 2);
		K0 = new BigInteger(key.substring(0, 32), 2);
		K1 = new BigInteger(key.substring(32), 2);
	}

	static public BigInteger encrypt() {
		BigInteger tmp = P.xor(K0);
		tmp = tmp.add(K1);
		tmp = tmp.mod(MOD);
		return tmp;
	}

	static public BigInteger Decryption(BigInteger C) {
		BigInteger tmp = C.subtract(K1);
		tmp = tmp.mod(MOD);
		tmp = tmp.xor(K0);
		return tmp;
	}

	public static void main(String[] args) {
		set("11010110111100011010110101011001",
				"1101011100010101101010111100101101011011011000110101101010111011");
		BigInteger x1 = encrypt();
		BigInteger x2 = Decryption(x1);
		System.out.println(x1.toString(2) + " " + x2.toString(2));
		//		1011101010001110110000101001101 11010110111100011010110101011001

	}

}
