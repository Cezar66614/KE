# KE
My own C error handling library.\
Me trying to actually handle the errors not just returning and praying to god that weird edge case never happens.\
Thinking hard how to handle pointers best...\
Still in the designing process so lots of stuff may change.

How To Use:\
There is a single header file so add this to your code:\
  #define KE_IMPL\
  #include "ke.h"

Then in the main function, preferably right at the start, do:\
ke_init();\
and at the end do:\
ke_free();

Afterwards you can, every time you enter a new function context you need to manage:\
ke_push_scope(true);\
or an inner scope:\
ke_push_scope(false);

At the end of a defined scope it's best practice to do:
ke_pop_scope();

After that you can register a new element in that context:\
pointer:\
ke_push_elem(pointer, NULL);\
function:\
ke_push_elem(NULL, function);

If you want to trigger an error before returning from a function:\
KE_ERROR("Error message");\
or if you want to be able to exit() the program:\
KE_ERROR_KILL("Error message");
