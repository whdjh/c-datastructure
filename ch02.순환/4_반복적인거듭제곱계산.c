double power(double x, int n)
{
	double result = 1.0;

	for(int i = 0; i < n; i++)
		result = result * x;
	return result;
}