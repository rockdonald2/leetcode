class Solution {
public:
    double _pow(double x, long long n) {
        if (n == 1) {
            return x;
        } else {
            double k = myPow(x, n / 2);
            
            if (n % 2) {
                return k * k * x;
            } else {
                return k * k;
            }
        }
    }
    
    double myPow(double x, long long n) {
        if (x == 0) return 0;
        else if (n == 0) return 1;
        else if (n < 0) return _pow(1/x, n * -1);
        else return _pow(x, n);
    }
};