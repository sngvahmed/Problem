package lzw;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.io.*;
import javax.swing.JFrame;

public class NewJFrame extends javax.swing.JFrame {


	public NewJFrame() {
		initComponents();
	}

	@SuppressWarnings("unchecked")
	// <editor-fold defaultstate="collapsed" desc="Generated Code">
	private void initComponents() {

		jButton1 = new javax.swing.JButton();

		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

		jButton1.setText("Compress");
		jButton1.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				jButton1ActionPerformed(evt);
			}
		});

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(
				getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(
				javax.swing.GroupLayout.Alignment.LEADING).addGroup(
				layout.createSequentialGroup().addGap(159, 159, 159)
						.addComponent(jButton1)
						.addContainerGap(160, Short.MAX_VALUE)));
		layout.setVerticalGroup(layout.createParallelGroup(
				javax.swing.GroupLayout.Alignment.LEADING).addGroup(
				layout.createSequentialGroup().addGap(128, 128, 128)
						.addComponent(jButton1)
						.addContainerGap(143, Short.MAX_VALUE)));

		pack();
	}// </editor-fold>

	static HashMap<Integer, String> n = new HashMap<Integer, String>();
	static boolean f = true;
	static Scanner input;
	static PrintWriter writer;
	static HashMap<String, String> WK = new HashMap<String, String>();
	static String kelma;

	static public void BBS(ArrayList<Integer> value, int valk, int vals) {
		if (value.size() == 1)
			return;
		Collections.sort(value);
		vals = value.get(1);
		value.set(1, value.get(0) + value.get(1));
		valk = value.get(1);
		value.remove(0);
		BBS(value, valk, vals);
		if (f == true) {
			f = false;
			n.put(valk, "");
		}
		int ve = valk - vals;
		value.set(value.indexOf(valk), ve);
		n.put(ve, n.get(valk) + "0");
		n.put(vals, n.get(valk) + "1");
		value.add(vals);
		Collections.sort(value);
		n.put(valk, "");
	}

	static public void writeInput() {
		Writer writer = null;
		try {
			writer = new BufferedWriter(new OutputStreamWriter(
					new FileOutputStream("out.txt"), "utf-8"));
			for (int i = 0; i < kelma.length(); i++) {
				writer.write(WK.get(kelma.charAt(i) + "") + " ");
			}
		} catch (IOException ex) {
			// report
		} finally {
			try {
				writer.close();
			} catch (Exception ex) {
			}
		}

	}

	static public String readInput() {

		try {
			input = new Scanner(new File("input.txt"));
		} catch (Exception e) {
			System.out.println("Error Opening the File");
		}
		String Line = "";
		while (input.hasNext()) {
			Line = input.next();
		}
		return Line;
	}

	static public void DO() {
		ArrayList<Integer> num = new ArrayList<Integer>();
		HashMap<String, Integer> FNL = new HashMap<String, Integer>();

		String numms = "";
		kelma = readInput();
		for (int i = 0; i < kelma.length(); i++) {
			FNL.put(kelma.charAt(i) + "", 0);
			if (numms.indexOf(kelma.charAt(i)) == -1) {
				numms += kelma.charAt(i) + "";
			}
		}
		for (int i = 0; i < kelma.length(); i++) {
			int r = FNL.get(kelma.charAt(i) + "") + 1;
			FNL.put(kelma.charAt(i) + "", r);
		}
		for (int i = 0; i < numms.length(); i++) {
			num.add(FNL.get(numms.charAt(i) + ""));
		}
		BBS(num, 0, 0);
		for (int i = 0; i < numms.length(); i++)
			WK.put(numms.charAt(i) + "", n.get(FNL.get(numms.charAt(i) + "")));
		for (int i = 0; i < numms.length(); i++) {
			System.out.println(numms.charAt(i) + " "
					+ WK.get(numms.charAt(i) + ""));
		}
		writeInput();
	}

	private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {
		DO();
	}

	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String args[]) {
		/* Set the Nimbus look and feel */
		// <editor-fold defaultstate="collapsed"
		// desc=" Look and feel setting code (optional) ">
		/*
		 * If Nimbus (introduced in Java SE 6) is not available, stay with the
		 * default look and feel. For details see
		 * http://download.oracle.com/javase
		 * /tutorial/uiswing/lookandfeel/plaf.html
		 */
		try {
			for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager
					.getInstalledLookAndFeels()) {
				if ("Nimbus".equals(info.getName())) {
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch (ClassNotFoundException ex) {
			java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (InstantiationException ex) {
			java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (IllegalAccessException ex) {
			java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (javax.swing.UnsupportedLookAndFeelException ex) {
			java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		}
		// </editor-fol
		/* Create and display the form */
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new NewJFrame().setVisible(true);
			}
		});
	}

	// Variables declaration - do not modify
	private javax.swing.JButton jButton1;
	// End of variables declaration
}
