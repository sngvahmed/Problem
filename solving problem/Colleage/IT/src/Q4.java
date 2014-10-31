import java.math.BigInteger;

//( P XOR k0 ) + k1 % 2^32
// 2^32 = 4294967296

public class Q4 {

	static BigInteger mod = new BigInteger("4294967296");
	String PlainText, Key, k0, k1;
	BigInteger C, P, K0, K1, Dec;

	public Q4() {
	}

	public Q4(String p, String k) {
		PlainText = p;
		Key = k;

		k0 = Key.substring(0, 32);
		k1 = Key.substring(32);
		System.out.println();
		System.out.println(k0 + " :: " + k1);
		P = new BigInteger(PlainText, 2);
		K0 = new BigInteger(k0, 2);
		K1 = new BigInteger(k1, 2);

		System.out.println(Key.length());
		System.out.println(PlainText.length());
	}

	public String Encryption() {

		System.out.println(P + " " + K0 + " " + K1);
		BigInteger temp = P.xor(K0);
		C = temp.add(K1);
		C = C.mod(mod);
		return C.toString(2);

	}


	public String Decryption() {

		BigInteger temp = C.subtract(K1);
		temp = temp.mod(mod);
		Dec = temp.xor(K0);
		return Dec.toString(2);
	}
}
