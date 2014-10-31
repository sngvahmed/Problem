import java.lang.Character.Subset;
import java.util.Scanner;

public class Main {
	public int longestRep(String input) {
		int longest = 0;
		for (int i = 0; i < input.length(); i++) {
			for (int q = i + 1; q <= input.length(); q++) {
				String seacrh = input.substring(i, q);
				if (input.indexOf(seacrh, q) > 0)
					longest = Math.max(longest, q - i);
			}
		}
		return longest;
	}
}
