import java.lang.Math;
public class ComplexNumber {
    private double real, imag;

    public ComplexNumber(double real,double imag) {
        this.real = real;
        this.imag = imag;
    }

    public ComplexNumber add(ComplexNumber c2) {
        real = real + c2.real;
        imag = imag + c2.imag;
        return new ComplexNumber(real, imag);
    }

    public ComplexNumber squared(){
        ComplexNumber square = new ComplexNumber(1, 1);
        square.real = (Math.pow(real,2)-Math.pow(imag,2));
        square.imag = (2*real*imag);
        return square;
    }
    public double abs(){
        double magnitude = Math.sqrt(real*real+imag*imag);
        return magnitude;
    }
}