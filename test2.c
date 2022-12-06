#include <stdio.h>
#include <string.h>
struct __data_Numeric {
const char *kind;
union {
int d_int;
float d_float;
unsigned d_unsigned;
long d_long;
} data;
};
;
int main(void)
{
  struct __data_Numeric nt;
  (nt).kind = "float";
  (nt).data.d_float = 3.1415;
  ;
  if (!strcmp((nt).kind, "int")) { int i = (nt).data.d_int;   {
    printf("val is an int: %d\n", i);
  }
 } else   {
    puts("it's who knows");
  }

  ;
}


