#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[20][20], b[20][20], m, d = 0;
int determinant (int f[20][20], int a);
float cramer_rule (int t[20][20], int q[20][20]);
int
main ()
{
  int i, j;
  printf ("\n\nEnter order of matrix : ");
  scanf ("%d", &m);
  printf ("\nEnter the elements of matrix\n");
  for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= m; j++)
	{
	  printf ("a[%d][%d] = ", i, j);
	  scanf ("%d", &a[i][j]);
	}
    }
  printf ("\n\n---------- Matrix A is --------------\n");
  for (i = 1; i <= m; i++)
    {
      printf ("\n");
      for (j = 1; j <= m; j++)
	{
	  printf ("\t%d \t", a[i][j]);
	}
    }
  printf ("\nEnter the elements of matrix\n");
  for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= 1; j++)
	{
	  printf ("b[%d][%d] = ", i, j);
	  scanf ("%d", &b[i][j]);
	}
    }
  printf ("\n\n---------- Matrix B is --------------\n");
  for (i = 1; i <= m; i++)
    {
      printf ("\n");
      for (j = 1; j <= 1; j++)
	{
	  printf ("\t%d \t", b[i][j]);
	}
    }
  printf ("\n \n");
  printf ("\n Determinant of Matrix A is %d .", determinant (a, m));
  if (determinant (a, m) == 0)
    {
      printf ("\n As Determinant of Matrix A is 0, cannot proceed.");
    }
  else
    {
      cramer_rule (a, b);
    }

  getch ();
}

int
determinant (int f[20][20], int x)
{
  int pr, c[20], b[20][20], j, p, q, t;
  if (x == 2)
    {
      d = 0;
      d = (f[1][1] * f[2][2]) - (f[1][2] * f[2][1]);
      return (d);
    }
  else
    {
      for (j = 1 ; j <= x; j++)
	{
	  int r = 1, s = 1;
	  for (p = 1; p <= x; p++)
	    {
	      for (q = 1; q <= x; q++)
		{
		  if (p != 1 && q != j)
		    {
		      b[r][s] = f[p][q];
		      s++;
		      if (s > x - 1)
			{
			  r++;
			  s = 1;
			}
		    }
		}
	    }
	  for (t = 1, pr = 1; t <= (1 + j); t++)
	    pr = (-1) * pr;
	  c[j] = pr * determinant (b, x - 1);
	}
      for (j = 1, d = 0; j <= x; j++)
	{
	  d = d + (f[1][j] * c[j]);
	}
      return (d);
    }
}

float
cramer_rule (int t[20][20], int q[20][20])
{
  int i, tempi, tempj;
  int j;
  int a,b=d; 
  float  values;
  int temp[20][20];
  for (j = 1; j <= m; j++)
    {
      for (tempi = 1; tempi <= m; tempi++)
	{
	  for (tempj = 1; tempj <= m; tempj++)
	    {
	      temp[l][o] = t[l][o];
	    }
	}
      for (i = 1; i <= m; i++)
	{
	  temp[i][j] = q[i][1];
	}
      a = determinant (temp, m);
      values = (float)a / (float)b;
      printf ("\nx[%d] is %f", j, values);

    }
}

