import java.math.BigInteger;
import java.util.Scanner;
class julka{
    public static void main(String args[])
    {
        int t=10;
        BigInteger tot,m,x,y;
        Scanner sc= new Scanner(System.in);
        while(t-->0){
            tot= sc.nextBigInteger(); // total no of apples
            m= sc.nextBigInteger(); // no of apples Klaudia has more
            x=(tot.add(m)).divide(BigInteger.valueOf(2));
            y=x.subtract(m);
            System.out.println(x);
            System.out.println(y);
        }

    }
}
/*
 * Say user enters tot followed by m
 * */
