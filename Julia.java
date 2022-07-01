import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.awt.GridLayout;
import javax.swing.BorderFactory;

public class Julia {
    public int xRes, yRes;
    public double zxMin;
    public double zxMax; 
    public double zyMin; 
    public double zyMax;
    public int xtable[][];
    ColorList colors;

    public Julia(int xRes, int yRes, double zxMin, double zxMax, double zyMin, double zyMax)
    {
        xtable = new int[yRes][xRes];
        colors = new ColorList();
        this.xRes = xRes;
        this.yRes = yRes;
        this.zxMin = zxMin;
        this.zxMax = zxMax;
        this.zyMin = zyMin;
        this.zyMax = zyMax;
        int maxIter = 200, iter = 0;
        for (int i = 0; i < yRes; i++)
	    {
            for (int j = 0; j < xRes; j++)
            {
                iter = 0;
                ComplexNumber c = new ComplexNumber(-0.7,0.27015);
                ComplexNumber z = new ComplexNumber(zxMin + (double)j/(double)(xRes-1)*(zxMax-zxMin), zyMin + (double)i/(double)(yRes-1)*(zyMax-zyMin));

                while ((iter < maxIter) && (z.abs() < 2))
                {
                    z = (z.squared()).add(c);
                    iter++;
                }
                if (z.abs() >= 2)
                {
                    xtable[i][j] = iter;
                }
                else
                {
                    xtable[i][j] = 0;
                }
            }
	    }
    }//constructor
    public void setPixel(Graphics g, int x, int y, int red, int grn, int blu)
    {
        Color c = new Color(red,grn,blu);
        g.setColor(c);
        g.drawLine(x,y,x,y);

    }// setPixel()
    public void displayFractal(Graphics g)
    {
        Color c;
        int red, grn, blu;
        for (int i = 0; i < yRes; i++)
	    {
            for (int j = 0; j < xRes; j++)
            {
                c = colors.colList.get(xtable[i][j]);
                red = c.getRed();
                grn = c.getGreen();
                blu = c.getBlue();
                setPixel(g, j, i, red, grn, blu);
            }
        }

    }//displayFractal()
    public void saveFractal(String filename)throws IOException
    {
        File f = new File(filename);
        FileOutputStream fout = new FileOutputStream(f);
        PrintStream out = new PrintStream(fout);
        // header
        out.println("P3\r\n" + xRes + " " + yRes + "\r\n255\r\n");
        Color c;
        int red, grn, blu, iter;
        for (int i = 0; i < yRes; i++)
	    {
            for (int j = 0; j < xRes; j++)
            {
                iter = xtable[i][j];
                c = colors.colList.get(iter);
                red = c.getRed();
                grn = c.getGreen();
                blu = c.getBlue();
                out.println(red + " " + grn + " " + blu);
            }
        }
        out.close();
    }//saveFractal()
    
            
    public static void main(String[] args)throws IOException
    {
        Julia pic = new Julia(640, 480,-1.5,1.5,-1,1);
        int a = pic.xRes;
        int b = pic.yRes;

        JFrame frame = new JFrame(); // our outer window
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        GridLayout gl = new GridLayout(1,1);
        gl.setVgap(0);
        gl.setHgap(0);
        frame.setLayout(gl);

        JPanel p;
        p = new JPanel();
        p.setPreferredSize(new Dimension(a,b));
        frame.add(p);

        BufferedImage pb1 = new BufferedImage(a,b,BufferedImage.TYPE_INT_RGB);
        JLabel pi1 = new JLabel(new ImageIcon(pb1));
        pi1.setPreferredSize(new Dimension(a,b));
        pi1.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
        p.add(pi1);

        Graphics g1 = pb1.createGraphics();
        pic.displayFractal(g1);

        frame.setVisible(true);
        frame.setResizable(false);
        frame.pack();
        pic.saveFractal("Julia.ppm");
    
    }//main()
}
