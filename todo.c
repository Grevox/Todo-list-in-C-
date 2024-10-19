#include <stdio.h>
#include <stdlib.h>
#define maxsize = 91298126;

void newfile();
void readfile();
void overwrite();
int inputsize = 100000;
int main()
{
  puts("\n\n TO DO list \n\n");
  printf("1) create a new file\n2) read a file \n\n");
  int choosing;
  scanf ("\n\n%d\n\n",&choosing);
  if (choosing == 1)
  {
    
    newfile();
  }
else if(choosing == 2)
  {
    
    readfile();
  }

  else
  {
    
   puts("\n something was wrong");
    return 104;
  }
  return 0;
}
void newfile()
{
  char filename [9999];
  //scanf("%s",&filename);
  fgets(filename, inputsize, stdin);
  FILE *newfile;
  newfile = fopen(filename, "w");
  char text [9999];
  fgets(text,inputsize,stdin);
  fprintf(newfile, "%s", &text);
  fclose(newfile);
  system("clear");
}
void readfile()
{
  char what [9999];
  //scanf ("%s",&what);
  fgets(what,inputsize, stdin);
  FILE *readfile;
  readfile = fopen(what, "r");
  char lllol [9999];
  //scanf("%s",&lllol);
  fgets(lllol, inputsize, stdin);
  fclose(readfile);
  system("clear");
}
