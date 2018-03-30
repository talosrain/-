package ruan;

import static org.junit.Assert.*;

import org.junit.Test;

public class nepoTest1 {
/*
	@Test
	public void testNeg() {
		int a[]=new int[100],k=5,i;
        for(i=0;i<k;i++){
            a[i]=ruan.random.nn();
        }
        assertEquals(ruan.right.right(a,k),ruan.nepo.neg(a,k));
	}
*/
	@Test
	public void testNa() {
		int a[]=new int[100],k=5,i;
        for(i=0;i<k;i++){
            a[i]=ruan.random.aa();
        }
        assertEquals(ruan.right.right(a,k),ruan.nepo.na(a,k));
    }


	@Test
	public void testD() {
		boolean nekl=true;
        int a[]=new int[100],k=5,i;
        for(i=0;i<k;i++){
            if(nekl){a[i]=ruan.random.nn();nekl=false;}
            else{
            a[i]=ruan.random.aa();}
        }
        assertEquals(ruan.right.right(a,k),ruan.nepo.d(a,k));

}
}
