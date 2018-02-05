#include<stdio.h>
#include<conio.h>
#include<math.h>
float a[20][20], b[20][20], det = 0; 
int order;
float determinant (float A[20][20], int order);
float cramer_rule (float t[20][20], float q[20][20]);
int
main ()
{
  int i, j;
  printf ("\n\nEnter order of matrix A : ");
  scanf ("%d", &order);
  printf ("\nEnter the elements of matrix\n");
  for (i = 1; i <= order; i++)
    {
      for (j = 1; j <= order; j++)
	{
	  printf ("a[%d][%d] = ", i, j);
	  scanf ("%f", &a[i][j]);
	}
    }
  printf ("\n\n---------- Matrix A is --------------\n");
  for (i = 1; i <= order; i++)
    {
      printf ("\n");
      for (j = 1; j <= order; j++)
	{
	  printf ("\t%0.2f \t", a[i][j]);	//Printing A array
	}
    }
  printf ("\nEnter the elements of matrix\n");
  for (i = 1; i <= order; i++)
    {
      for (j = 1; j <= 1; j++)
	{
	  printf ("b[%d][%d] = ", i, j);
	  scanf ("%f", &b[i][j]);
	}
    }
  printf ("\n\n---------- Matrix B is --------------\n");
  for (i = 1; i <= order; i++)
    {
      printf ("\n");
      for (j = 1; j <= 1; j++)
	{
	  printf ("\t%0.2f \t", b[i][j]);	//Printing B array
	}
    }
  printf ("\n \n");
  printf ("\n Determinant of Matrix A is %0.2f .", determinant (a, order));
  if (determinant (a, order) == 0)
    {
      printf ("\n As Determinant of Matrix A is 0, cannot proceed.");
    }
  else
    {
      cramer_rule (a, b);
    }

  getch ();
}

float
determinant (float A[20][20], int order)
{
  float sign, c[20], minorA[20][20];
  int j, row, col, s;
  if (order == 1)    
  {      
   det = A[1][1];                           //If order is 1, Determinant is 0     
   return (det);    
  }
	else
  if (order == 2)
    {
      det = 0;			                        //If order is 1, Determinant is 0
      det = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);	//If order is 2, then simply calculate the Determinant
      return (det);
    }
  else
    {
      for (j = 1; j <= order; j++)
	{
	  int minori = 1, minorj = 1;
	  for (row = 1; row <= order; row++)
	    {
	      for (col = 1; col <= order; col++)
		{
		  if (row != 1 && col != j)	//Condition for Matrix of miniors
		    {
		      minorA[minori][minorj] = A[row][col];
		      minorj++;
		      if (minorj > order - 1)
			{
			  minori++;
			  minorj = 1;
			}
		    }
		}
	    }
	  for (s = 1, sign = 1; s <= (1 + j); s++)
	    sign = (-1) * sign;
	  c[j] = sign * determinant (minorA, order - 1);	//Sign assining for Cofactor matrix
	}
      for (j = 1, det = 0; j <= order; j++)
	{
	  det = det + (A[1][j] * c[j]);
	}
      return (det);
    }
}

float
cramer_rule (float t[20][20], float q[20][20])
{
  int i, j, tempi, tempj;
  float eachDet, realDet = det;
  float values;
  float temp[20][20];
  for (j = 1; j <= order; j++)
    {
      for (tempi = 1; tempi <= order; tempi++)
	{
	  for (tempj = 1; tempj <= order; tempj++)
	    {
	      temp[tempi][tempj] = t[tempi][tempj];	//Storing in Temporary array without changing orginal array
	    }
	}
      for (i = 1; i <= order; i++)
	{
	  temp[i][j] = q[i][1];
	}
      eachDet = determinant (temp, order);
      values = (float) eachDet / (float) realDet;
      printf ("\nx[%d] is %f", j, values);

    }
}
