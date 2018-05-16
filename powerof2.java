import java.math.BigDecimal; 
public class Solution {
    public int power(String A) {
        	BigDecimal val = new BigDecimal(A);
        	if(val.compareTo(BigDecimal.ONE)==0){
        	    return 0;
        	}
    		while(val.remainder(new BigDecimal(2)).compareTo(BigDecimal.ZERO) == 0 ){
    			val = val.divide(new BigDecimal("2"));
    			//System.out.println(val);
    		}
    		if(val.compareTo(BigDecimal.ONE)==0){
    			return 1;
    		}
    		else{
    			return 0;
    		}
    }
}
