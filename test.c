#include <stdio.h>
#include <string.h>
struct st
{
  int val;
  const char *str;
};
struct __data_SimpleType {
const char *kind;
union {
int d_int;
float d_float;
struct st d_s_st;
} data;
};
;
void match_printer_ptr(struct __data_SimpleType *ptr)
{
  if (!strcmp((*ptr).kind, "float")) { float f = (*ptr).data.d_float;   {
    printf("the *ptr is a float: %f\n", f);
    (*ptr).kind = "float";
    (*ptr).data.d_float = f * 2;
    ;
  }
 } else if (!strcmp((*ptr).kind, "int")) { int i = (*ptr).data.d_int;   {
    printf("the *ptr is an int: %d\n", i);
  }
 } else if (!strcmp((*ptr).kind, "struct st")) { struct st s = (*ptr).data.d_s_st;   {
    printf("the *ptr is a struct st: %d, %s\n", s.val, s.str);
  }
 } else   {
    puts("ptr is something else!\n");
  }

  ;
}

void match_printer(struct __data_SimpleType val)
{
  if (!strcmp((val).kind, "int")) { int i = (val).data.d_int;   {
    printf("the value is an int: %d\n", i);
  }
 } else if (!strcmp((val).kind, "float")) { float f = (val).data.d_float;   {
    printf("the value is a float: %f\n", f);
  }
 } else if (!strcmp((val).kind, "struct st")) { struct st s = (val).data.d_s_st;   {
    printf("the value is a struct st: %d, %s\n", s.val, s.str);
  }
 }
  ;
}

int main(void)
{
  struct __data_SimpleType one;
  struct __data_SimpleType two;
  struct __data_SimpleType three;
  struct __data_SimpleType four;
  (one).kind = "int";
  (one).data.d_int = 10;
  ;
  (two).kind = "float";
  (two).data.d_float = 123.2 + 1;
  ;
  (three).kind = "struct st";
  (three).data.d_s_st = (struct st){.val = 256, .str = "Hello World!"};
  ;
  match_printer_ptr(&one);
  match_printer_ptr(&two);
  match_printer_ptr(&two);
  match_printer(three);
  match_printer(four);
}


