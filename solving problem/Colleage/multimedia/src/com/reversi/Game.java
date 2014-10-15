package com.reversi;

import java.util.*;

public class Game {
	static Vector<Vector<Character>> grid = new Vector<Vector<Character>>();
	static int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	static int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

	static public void intialize() { // change it to Game
		grid.setSize(8);
		for (int i = 0; i < 8; i++) {
			grid.set(i, new Vector<Character>(8));
			for (int j = 0; j < 8; j++) {
				grid.get(i).add(' ');
			}
		}
		grid.get(3).set(3, 'W');
		grid.get(3).set(4, 'B');
		grid.get(4).set(3, 'B');
		grid.get(4).set(4, 'W');
	}

	static public void fun() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (grid.get(i).get(j) == ' ')
					System.out.print("(" + i + "," + j + ")" + " ");
				else
					System.out.print("  " + grid.get(i).get(j) + "   ");
			}
			System.out.println();
		}
	}

	// to check border
	static public int BORD(int dx, int dy, int x, int y, char turn) {
		/*
		 * dx -> current x , dy -> current y , x,y ->move value cordinate ,
		 * turn->color
		 */
		int count = 0;
		while (true) {
			dx = dx + x;
			dy = dy + y;
			if (dx >= 8 || dy >= 8 || dx < 0 || dy < 0)
				return -1;
			if (grid.get(dx).get(dy) == turn)
				return count;
			if (grid.get(dx).get(dy) == ' ')
				return -1;
			count++;
		}

	}

	// change corinate to the officet value
	static public void CHANGE(int dx, int dy, int x, int y, char turn) {
		/*
		 * dx -> current x , dy -> current y , x,y ->move value cordinate ,
		 * turn->color
		 */
		grid.get(dx).set(dy, turn);
		while (true) {
			dx = dx + x;
			dy = dy + y;
			if (grid.get(dx).get(dy) == turn)
				return;
			grid.get(dx).set(dy, turn);
		}
	}

	// flage - > true if you play , false - > if you want olny to check
	static public boolean Validate(int x, int y, char turn, boolean flag) {
		if (grid.get(x).get(y) != ' ')
			return false;
		boolean ch = false;
		for (int i = 0; i < 8; i++) {
			if (!flag && BORD(x, y, di[i], dj[i], turn) > 0) {
				return true;
			} else if (BORD(x, y, di[i], dj[i], turn) > 0) {
				ch = true;
				break;
			}
		}

		if (!ch)
			return false;
		for (int i = 0; i < 8; i++) {
			if (BORD(x, y, di[i], dj[i], turn) > 0) {
				CHANGE(x, y, di[i], dj[i], turn);
			}
		}
		return true;
	}

	static public char game_over(char turn) {
		char other_turn = 'W';
		if (turn == 'W')
			other_turn = 'B';
		int count_W = 0, count_B = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Validate(i, j, other_turn, false))
					return ' ';
				if (grid.get(i).get(j) == 'W')
					count_W++;
				else
					count_B++;
			}
		}
		if (count_W > count_B)
			return 'W';
		else if (count_B > count_W)
			return 'B';
		else
			return 'T';
	}

	static public void main(String[] args) {
		intialize();
		Scanner cin = new Scanner(System.in);
		String n;
		while (true) {
			fun();
			int dx, dy;
			dx = cin.nextInt();
			dy = cin.nextInt();
			n = cin.next();
			Validate(dx, dy, n.charAt(0), true);
			System.out.println("DONE");
		}
	}
}
