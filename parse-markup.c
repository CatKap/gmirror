#include<stdio.h>


enum TAGS {DEFAULT=0, BOLD=1, UNDERLINE=2};

char* SPAN_PARAMS[] = {
"font-family=\"serif\" font-size=14",
"weight=\"bold\"",
"underline=\"single\""};




int parse_text(char* text)
{
  int pt = 0;
  while(text[pt] != '\0')
  {
    if(text[pt] == 0x1b)
    {
      pt += 2;

      
    }

  }
}


int main(int argc, char** argv)
{
  FILE* f;
  if(argc < 2)
  {
    printf("Using stdin\n");
    f = stdin; 
  } else {
    f = fopen(arg[1], "r");
    if(!f)
    {
      printf("Cannot open file %s\n", argv[1]);
      return 1;
    }
  }

  int counter = 0; 
  char string[1024];
  while(fgets(string, 1024, f))
  {
    int i = 0;
    char s, c;
    do {
      s = string[i];
      if(s == 0x1B)
      {
        printf("\n\nSequence\n");
        counter++;
        i += 2;
        do {
          c = string [i];
          printf("%c", c);
          printf("{%x}", c & 0xff);
          i++;
        
        } while(c >= 0x30 && c <= 0x3F);
        printf("\n");
      }
      
      i++;
    }while(s != '\0');
  }
  printf("Total: %d\n", counter);
  return 0;
}
