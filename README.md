##C Pointer Examples

Here are some examples of pointers and their usage, contrasting them with other methods.

```c
#include <stdio.h>

void get_sum_vals(int * sum, int a, int b) //sum using pointer
{
  *sum = a + b;
}

int sum_vals(int a, int b) //sum without pointer
{
  return a + b;
}

int main()
{
  int sum, * sum_p;

  get_sum_vals(sum_p, 2, 3);

  printf("\nValue of sum pointer %d\n", *sum_p);

  sum = sum_vals(2, 3);

  printf("\nValue of sum %d\n", sum);
}
```

Here is an example of using pointers to allocate memory on the heap.  This is what they are primarily used for and the concept I am trying to get you exposed to is the concept of heap vs stack.  Don't worry if you don't get it right away, when it clicks it clicks.

```c
#include <stdio.h> //printf, sprintf, fprintf
#include <stdlib.h> //malloc
#include <string.h> //memset

void get_greeting(char buff[64], char * name)
{
  sprintf(buff, "Hello %s from the stack!", name);
}

char * get_greeting_pointer(char * name)
{
  char * buff;

  if( ! ( buff = malloc( sizeof(char) * 64 ) ) ) //allocate memory for the pointer and check 
    fprintf(stderr, "\nFailed to allocate memory\n"); //print message to stderr if failure
  memset(buff, 0, sizeof(char) * 64 ); //I like to zero out the memory you just allocated

  sprintf(buff, "Hello %s from the heap!", name);

  return buff;
}

int main()
{
  char greeting[64], * greeting_p;
  memset(greeting, 0, sizeof(char) * 64); //set the contents of the array equal to 0

  get_greeting(greeting, "John"); //Fill buffer allocated on the stack with greeting

  printf("%s\n", greeting);

  greeting_p = get_greeting_pointer("John"); //allocate greeting on the heap

  printf("%s\n", greeting_p);

  free(greeting_p); //You need to free heap resources when you are done
}
```
