#define KE_IMPL
#include "ke.h"

#include <stdio.h>

int main(void) {
  ke_init();

  ke_push_scope(true);

  char *a = malloc(sizeof(char) * 16);
  int i; for (i = 0; i <= 9; ++i) a[i] = '0' + i;
  a[i] = '\0';

  printf("%s\n", a);

  ke_push_elem(a, NULL);

  {
    ke_push_scope(false);

    char *b = malloc(sizeof(char) * 16);
    int i; for (i = 0; i <= 9; ++i) b[i] = '9' - i;
    b[i] = '\0';

    printf("%s\n", b);

    ke_push_elem(b, NULL);

    {
      ke_push_scope(false);

      KE_ERROR("Test");

      //ke_pop_scope();
    }

    ke_pop_scope();
  }

  //ke_pop_scope();

  ke_free();
  return 0;
}
