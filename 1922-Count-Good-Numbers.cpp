class Solution {
public:
    const long long MOD = 1000000007;
    int power(long long x, long long n){
        if(n==0){
            return 1;
        }
        long long ans=power(x, n/2);
        if(n%2==0){
            return (ans*ans)% MOD;
        }
        else{
            return (x * ans % MOD * ans) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long a=(n+1)/2;
        long long b=n/2;

        long long even=power(5,a);
        long long odd=power(4,b);

        return (even*odd)% MOD;
    }
};