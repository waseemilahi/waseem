//The Header file.

# ifndef MYPROJECTHEADER1_H
# define MYPROJECTHEADER1_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int n=0;
char query[500]="",querylanguage[100]="";
char sequence[500][500] ;
char sequencelanguage[500][100];

  struct Sequence{

                  char* sentences;

                  int time;

                  int relevence;

						};

  struct Relevent{

  						char name;

                  int value;

                  };


#endif
