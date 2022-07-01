import java.awt.Color;
import java.awt.GridLayout;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Graphics;

public class SinglePanel {
  final static int row = 256, col = 1;
  // "psvm" - our static "launcher" function (starting point for execution)
  public static void main(String[] args) {

    ColorList cols = new ColorList(); // generate colors, to use for populating strips below

    JFrame frame = new JFrame(); // our outer window
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    frame.setLayout(new GridLayout(row,col)); 

    JPanel p;
    Color c;
    p = new JPanel();
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 100; i++){
        p = new JPanel();
        c = cols.colList.get(i);
        p.setBackground(c);
        p.setPreferredSize(new Dimension(i,j));
        frame.add(p);
      }
    }
      // all done
      frame.pack(); // arrange all the panels 
      frame.setVisible(true); // show to the world :) 
  }// main()
}// ColorStrips
