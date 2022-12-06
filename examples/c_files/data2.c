data Numeric int | float | unsigned | long;

int main(void) {
  Numeric nt;
  dataset nt <- float 3.1415;

  match nt
    int i { printf("val is an int: %d\n", i); }
  | ... { puts("it's who knows"); };
}
