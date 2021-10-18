
/* Purpose: Test exericise from Met Office
 * Usage:  calc-shielding-wiring file.txt
 * date: 15-10.21 */

 /*  compilation on gcc
 *  gcc calc-shielding-wiring.c -o calc-shielding-wiring
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define DBG 1
#define MAX_LINE 100

/* integer comparison function for sort */
int
compare_int(const void *val1, const void *val2)
{

  const int * const ip1=(const int *)val1;
  const int * const ip2=(const int *)val2;
  return *ip1 < *ip2 ? -1 : (*ip1 > *ip2);
}

/* Total area of shield required is box surface area plus slack
 * slack is the area of the smallest face
 * nb the array is sorted so slack is multiple of first two array members */

double
calc_shield_area(int alwh[])
{
   double total=0.0;

   total= 3 * alwh[0] * alwh[1] + 2 * alwh[1] * alwh[2] + 2 * alwh[0] * alwh[2] ;

   return total;
}

/* Length of wire is  volume of box + minimium box perimeter.
 * Since the sides of the box are sorted minimum perimeter is the
 * twice the sum of the first two members */

double
calc_wire_length(int alwh[])
{

  double total_length=0.0;

  total_length= alwh[0] * alwh[1] * alwh[2] + 2 * (alwh[0] + alwh[1]);

  return total_length;

}


int main(int argc, char *argv[])
{

  int line_nbr=0;
  double total_area=0.0;
  double total_length=0.0;
  char cline[MAX_LINE]={0};
  FILE *fp=NULL;


  if((fp=fopen(argv[1],"r"))==NULL)
  {
    fprintf(stderr, "Unable to open for reading the file \"%s\"\n", argv[1]);
    exit(1);
  }


  while( (fgets(cline, MAX_LINE ,fp)) != NULL)
  {

    int cnv_nbr = 0;
    /* array holds Length, Width, Height */
    int alwh[3]={0, 0, 0};

    double area = 0.0;
    double slength = 0.0;


    line_nbr++;

    /* read Length, Width, Height into array */
    if ((cnv_nbr=sscanf(cline, "%dx%dx%d", &alwh[0], &alwh[1], &alwh[2] )) <3 )
    {
      fprintf(stderr, "Skipping line(%d)- \"%s\" only %d integers read in\n",line_nbr, cline, cnv_nbr);
      continue;
    }

    /* sort int array */
    qsort(alwh, 3, sizeof(int), compare_int );

    area = calc_shield_area(alwh);
    slength = calc_wire_length(alwh);

    total_area+=area;
    total_length+=slength;

    if(DBG)
      fprintf(stdout, "%dx%dx%d area=%0.2f length=%0.2f\n", alwh[0], alwh[1], alwh[2], area, slength);
  }



  fprintf(stdout, "total shielding=%.2f (mm2) wiring=%.2f mm\n", total_area, total_length);

  fclose(fp);
  exit(0);

}
