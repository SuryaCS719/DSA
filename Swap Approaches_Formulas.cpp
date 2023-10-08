ex: int a = 5 ; int b = 3;

// Approach-1: Using a temp variable
step 1: int temp = a;
step 2: a = b;
step 3: b = temp;

// Approach-2: Using a arithmetic operators (+,-)
step 1: a = a + b;
step 2: b = a - b;
step 3: a = a - b;

// Approach-3: Using a XOR bitwise operator
step 1: a = a ^ b;
step 2: b = a ^ b;
step 3: a = a ^ b;

Note: XOR is faster as bitwise operators are more close to computer hardware representation thus less work for computer where as (+,-) are more of a work.
