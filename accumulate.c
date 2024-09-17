/**
 * Adds or multiplies the values given on the command line.
 *
 * add/multiply is determined by the first argument -s or -p
 * 
 * subsequent arguments are floating point values to be added or
 * multiplies.  The result is output to standard output.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      fprintf(stderr, "USAGE: %s {-s|-p} numbers...\n", argv[0]);
      return 1;
    }

  // check first "real" command-line argument (after program name)
  bool adding_mode = (strcmp(argv[1], "-s") == 0);
  double total = adding_mode ? 0.0 : 1.0;
  
  // iterate through other arguments
  for (size_t i = 2; i < argc; i++)
    {
      // convert argument to double
      double term = atof(argv[i]); // or strtod for error checking
      if (adding_mode)
	{
	  total += term;
	}
      else
	{
	  total *= term;
	}
    }

  fprintf(stdout, "%lf\n", total);
}

      
