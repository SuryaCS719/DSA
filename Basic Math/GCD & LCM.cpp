// GFG - GCD of two numbers

// Method 1: Euclid's algorithm ; TC: O(log(min(A,B))) ; SC: O(1)

class Solution
{
	public:
    int gcd(int A, int B) 
	{
	    // Not needed cuz of the return statement condition.
	    // if(A == 0) return B;
	    // if(B == 0) return A;
	    
	    while(A > 0 && B > 0){
	        if(A > B){
	            A = A - B;
	        }
	        else{
	            B = B - A;
	        }
	    }
	   // if(A!=0)
	   //     return A;
	   // else
	   //     return B;
	   return A != 0 ? A : B;
	} 
};

/* To Calculate LCM:
LCM * HCF = a * b
So, LCM = (a*b) / gcd(a, b)
*/
