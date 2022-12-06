struct st {
  int val;
  const char *str;
};

data SimpleType int | float | struct st;

void match_printer_ptr(SimpleType *ptr) {
  match *ptr
  float f {
    printf("the *ptr is a float: %f\n", f);
    dataset *ptr <- float f * 2;
  }
  | int i { printf("the *ptr is an int: %d\n", i); }
  | struct st s { printf("the *ptr is a struct st: %d, %s\n", s.val, s.str); }
  | ... { puts("ptr is something else!\n"); };

}

void match_printer(SimpleType val) {
  match val
  int i { printf("the value is an int: %d\n", i); }
  | float f { printf("the value is a float: %f\n", f); }
  | struct st s { printf("the value is a struct st: %d, %s\n", s.val, s.str); };
}

int main(void) {
  SimpleType one, two, three, four;

  dataset one <- int 10;
  dataset two <- float 123.2 + 1;
  dataset three <- struct st (struct st){ .val = 256, .str = "Hello World!" };

  match_printer_ptr(&one);
  match_printer_ptr(&two);
  match_printer_ptr(&two);
  match_printer(three);
  match_printer(four);
}
