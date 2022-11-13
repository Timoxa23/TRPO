#include <stdio.h>

int main(int argc, char* argv[])
{
  double Xn, Xk, dX, a, b, c, y;
  
  printf("Xn, Xk, dX, a, b, c: ");
  scanf("%lf%lf%lf%lf%lf%lf", &Xn, &Xk, &dX, &a, &b, &c);

  double x = Xn;

  printf("----------------------\n");
  printf("|    X     |   Y     |\n");
  printf("----------------------\n");

  for(;x <= Xk; x += dX)
  {
    if(c < 0 && a != 0)
    {
      y = (-a * x * x) ;
    }
    else
    {
      if(c > 0 && a == 0)
      {
        y = (a-x)/c*x;
      }
      else
      {
        y = x/c; 
      }
    }
    
    if((int(a) | int(b)) ^ (int(b) & int(c)))
      printf("|%.2f      |%.2f     |\n", x, y);
    else
      printf("|%.2f      |%d       |\n", x, int(y));

  }
  
  printf("----------------------\n");

	return 0;
}