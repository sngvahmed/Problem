package arthimaticCodeing;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

import javax.swing.*;

public class Compressor extends JFrame {

	private JButton Brows, Arithmatic, decompres_Arithmatic;
	private JFileChooser chooser = new JFileChooser();
	private JTextField file_name;
	private JPanel panel;
	private File file;
	private ArithmaticCoding c;

	class handler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			try{
			c = new ArithmaticCoding();
			if (e.getSource().equals(Arithmatic)) { // standard huffman
													// button pressed
				c.compress(file);

			} else if (e.getSource().equals(decompres_Arithmatic)) {
				c.Decompress(file);
			}
			}catch(IOException e1){
				e1.printStackTrace();
			}
		}
	}

	public Compressor() {

		super("compressor");
		panel = new JPanel();
		panel.setLayout(null);
		add(panel);

		file_name = new JTextField("Select a file");
		panel.add(file_name);

		file_name.setEditable(false);
		file_name.setSize(0, 0);
		Brows = new JButton("Brows");
		panel.add(Brows);

		Arithmatic = new JButton("Compress Arithmatic");
		panel.add(Arithmatic);

		decompres_Arithmatic = new JButton("deCompress Arithmatic");
		panel.add(decompres_Arithmatic);

		Arithmatic.setBounds(60, 60, 220, 30);
		decompres_Arithmatic.setBounds(60, 90, 220, 30);
		Brows.setBounds(180, 20, 100, 30);
		file_name.setBounds(70, 20, 100, 30);

		handler action = new handler();
		Arithmatic.addActionListener(action);
		decompres_Arithmatic.addActionListener(action);

		Brows.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				int choice = chooser.showOpenDialog(Brows); // brows the caller
				if (choice != JFileChooser.APPROVE_OPTION)
					return;
				File chosenFile = chooser.getSelectedFile();
				file_name.setText(chosenFile.getPath());
				file = chosenFile;
			}
		});

	}

}
