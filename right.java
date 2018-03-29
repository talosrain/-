package ruan;

public class right {
    public static int right(int array[],int k){
            //杩樺師鎸囬拡
            int negativePointer = 0;
            //鏈�澶у��
            int max = 0;
            //缁勭疮鍔犲拰
            int accumulation = 0;
            for(int i = 0; i < k ; i++){
                accumulation += array[i];
                max = Math.max(max,accumulation - negativePointer);
                //鎸囬拡绉昏繘
                negativePointer = Math.min(negativePointer,accumulation);
            }
            if(max >= 0){
                return max;
            }else {
                return 0;
            }
        }


}

