class Solution {
public:
    int reverse(int x) {
        int y = 0, sgn = x > 0 ? 1 : -1;
        x = sgn * x;
        while(x){
        	y *= 10;
        	y += x % 10;
        	x /= 10;
        }
        return sgn * y;
    }
};