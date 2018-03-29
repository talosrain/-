package ruan;

public class nepo {
    public static int neg(int[] a,int k) {
        int i,max=-99;
        boolean negative= true;
        for(i=0;i<k;i++)
        {
            if(a[i]>0){negative= false;max=0;}
        }
        if(negative){
            for(i=0;i<k;i++)
            {
                if(max<=a[i]){max=a[i];}
            }
            //cout<<max<<endl;
            return max;
        }
        return max;
    }
    public static int na(int a[], int k) {
        int i,max_0=0;
        boolean positive= true;
        for(i=0;i<k;i++)
        {
            if(a[i]<0){positive= false;
                max_0=0;}
        }
        if(positive){
            for(i=0;i<k;i++)
            {
                max_0+=a[i];
            }
            //cout<<max_0<<endl;
            return max_0;
        }
        return max_0;
    }
    public static int d(int a[],int k) {
            int b[]=null;b=new int[100];
            int max,i;
            b[0]=a[0];max=b[0];
            for(i=1; i<k; i++) {
                if(b[i-1]>0)
                    b[i]=b[i-1]+a[i];
                else
                    b[i]=a[i];
                if(b[i]>max)
                    max=b[i];
            }
            return max;
}

}
