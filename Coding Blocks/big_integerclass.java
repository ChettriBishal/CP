import java.util.Scanner;
import java.math.BigInteger;

public class biginteger{
    static void check(){
        Scanner bis=new Scanner(System.in);
        System.out.println("Enter a number:");
        String s=bis.next(); // reading input
        BigInteger a= new BigInteger(s);
        BigInteger b=new BigInteger("12222333433534343");
        //a=a.add(b); 
        a=a.multiply(b);
        System.out.println(a);
        // to count the total no of set bits
        System.out.println("No of set bits: "+ a.bitCount());
        // to count the total no of bits
        System.out.println("Bits length: "+ a.bitLength());
        System.out.println("Enter two numbers to find gcd: ");
        int c=bis.nextInt();
        int d=bis.nextInt();
        BigInteger a1= BigInteger.valueOf(c);
        BigInteger b1= BigInteger.valueOf(d);
        System.out.println("GCD: "+a1.gcd(b1));
        // Base conversion
        System.out.println("decimal form of 1001");
        BigInteger num= new BigInteger("1001",2);
        System.out.println(num);
        // power of some number
            System.out.println(a1+"^20  "+a1.pow(20));

    }
    public static void main(String args[]){
        check();



    }


}
