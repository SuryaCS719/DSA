// 10.1 Dividing of 2 numbers using Binary Search

int getQuotient(int divisor, int dividend){
    int start = 0;
    int end = dividend;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mid * divisor == dividend)
            return mid;
        else if(mid * divisor < dividend){
            ans = mid;
            start = mid + 1;
        }
        // else if(mid * divisor > divident)
        else
            end = mid - 1;
    }
    return ans;
}

int main(){
    int divisor = 7;
    int dividend = 29; // taking dividend as zero gives the answer as 0 so it works.
    int ans = getQuotient(abs(divisor), abs(dividend));

    // special case where if the divisor = 0
    if(!divisor){
        cout << "undefined" << endl;
        return 0;
    }

    if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
        cout << 0 - ans;
    // else if((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
    else
        cout << ans;
}

// 10.2 Dividing of 2 numbers and to produce the o/p with n precision values.

#include <iostream>
#include <assert.h>
using namespace std;

int getQuotient(int divisor, int divident){
  int s = 0;
  int e = divident;
  int ans = -1;
  while(s <= e){
    int mid = s + (e-s)/2;
    if(mid*divisor > divident)
      e = mid - 1;
    else if(mid*divisor < divident){
      ans = mid;
      s = mid + 1; 
    }
  }
  return ans;
}

double preciseQuotient(int divisor, int divident, int precision){
  double integerAns = getQuotient(divisor, divident);
  double step = 0.1;
  for(int i = 0; i < precision; i++){
    double j = integerAns;
    while(j * divisor <= divident){
      integerAns = j;
      j += step;
    }
    step /= 10;
  }
  return integerAns;
}

int main(){
  int divisor = 0; 
  int divident = 51; // if divident = 0 then o/p gives 0 by dft.
  int precision = 4;

   //sp. case if divisor == 0
   if(divisor == 0)
    assert(divisor != 0); // assert activates if the condition is false.

  double finalAns = preciseQuotient(abs(divisor) ,abs(divident), precision);
  
  if((divisor > 0 && divident < 0) || (divisor < 0 && divident > 0))
    cout << 0 - finalAns << endl;
  else 
    cout << finalAns << endl;

  return 0;
}
