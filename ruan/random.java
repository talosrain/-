package ruan;

import java.util.Random;

public class random {
    public static int nn(){
        Random rand = new Random();
        int randNum = rand.nextInt(20);
        int ron=randNum;
        return (ron-(ron*2));
    }
    public static int aa(){
        Random rand = new Random();
        int randNum = rand.nextInt(20);
        return randNum;
    }
    public static int ll(){
        Random rand = new Random();
        int randNum = rand.nextInt(100);
        return randNum;
    }
}
