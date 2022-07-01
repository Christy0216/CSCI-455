import java.awt.Color;
import java.util.ArrayList;
import java.util.Random;

public class ColorList {
  public ArrayList <java.awt.Color> colList = new ArrayList <java.awt.Color> ();

  ColorList() {
    Random rng = new Random(); // rand num generator 

    for (int i = 0; i <256 ; i++) {
      int r= rng.nextInt(255);
      int g = rng.nextInt(255);
      int b = rng.nextInt(255);
      Color c = new Color(r,g,b);
      colList.add(c);
    }
  }// constructor
}// ColorList