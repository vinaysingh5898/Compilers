// Test Everything
int test = 5;
double d = 2.3;
int i;
int a = 4, *p, b;
void func(int i, double d);
char c;
int main () {
	a = 10;
	int *x, y;
	x = &y;
	*x = y;
	y = *x;
	int a=1, b=2, c;
	c = a + b;
	a++;
	int check = a+b*c;
	if (check < c) 
		c = a|b;
	i = ++a;
	int n = 6;
	int fn;
	fn = factorial(n);
	int i, v = 5;
	double d;
	if (i&&v) i = 1;
	return;
}
int factorial (int n) {
	int m = n-1;
	int r = 1;
	if (m) {
		int fn = factorial(m-1);
		r = n*fn;
	}
	return r;
}
int add (int a, int b) {
	a = 10;
	int *x, y;
	x = &y;
	*x = y;
	y = *x;
}