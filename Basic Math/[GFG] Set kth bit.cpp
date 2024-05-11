// GFG: https://www.geeksforgeeks.org/problems/set-kth-bit3724/1

class Solution
{
public:
    int setKthBit(int N, int K)
    {
        // 1. Value: left shift 1 by kth time
        // i.e 1 << K
        // 2. BitWise OR: N | Value.
        // ex: K = 2; val = 1 << 2 = 100 (4)
        // N | val = 1010 | 100 = 1110 (14)
        int mask = 1 << K;
        return N | mask;
    }
    
};
