/*QUestion somewhat similar to the below one:


Consider the right angled triangle with sides a=7, b=24 and c=25. The area of this triangle is 84, which is divisible by the perfect numbers 6 and 28.
Moreover it is a primitive right angled triangle as gcd(a,b)=1 and gcd(b,c)=1.
Also c is a perfect square.

We will call a right angled triangle perfect if
-it is a primitive right angled triangle
-its hypotenuse is a perfect square

We will call a right angled triangle super-perfect if
-it is a perfect right angled triangle and
-its area is a multiple of the perfect numbers 6 and 28.

How many perfect right-angled triangles with c≤1016 exist that are not super-perfect?

*/

#include <stdio.h>

int gcd(int a, int b) {
    int i, gcd = 0;
    for(i = 1; i<=a && i<= b; i++) {
        if (a%i==0 && b%i==0)
            gcd = i;
    }
    return gcd;
}

int main() {
    int n, i, perfect = 0, super_perfect = 0, z[10];
    long long int a, b, c, j, k;
    scanf("%d", &n);
    for(i = 0; i<n; i++) {
        scanf("%lld", &c);
        for(j=1; j<c; j++) {
            for(k = 1; k<j+c; k++){
                if( ((j*j)+(k*k)) == (c*c)){
                    a=j;
                    b=k;
                    if(gcd(a,b) && gcd(b,c) == 1) {
                        perfect++;
                    }
                    else if ((((a*b)/2)%6 || ((a*b)/2)%28 || ((a*b)/2)%496 || ((a*b)/2)%8128) == 0) {
                        super_perfect++;
                    }
                }
            }
        }
        perfect = perfect/2;
        if(super_perfect != 0)
            printf("%d", perfect);
        else
            printf("0");
    }
    return 0;
}
