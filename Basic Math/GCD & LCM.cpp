// GFG - GCD of two numbers

// Method 1: Euclid's algorithm

class Solution
{
	public:
    int gcd(int A, int B) 
	{
	    if(A == 0) return B;
	    if(B == 0) return A;
	    
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
