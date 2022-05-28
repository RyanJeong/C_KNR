int findmax(int, ...);
void minprintf(char *fmt, ...);

int main(void)
{
  int max;

  max = findmax(5, 23, 1, 52, -3, 7);
  minprintf("The largest value is %d.\n", max);
  minprintf("Test %\n");
  minprintf("Test %%\n");

  return 0;
}
