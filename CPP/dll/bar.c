#include <dlfcn.h>
#include<stdio.h>
#include<stdlib.h>

typedef void (*foo_t)( const char* text );

void foo(const char* text)
{
	printf("Inside actual implementation:%s\n",text);
}

int main() {
  void* lib = dlopen("./libfoo.so", RTLD_LAZY);
  foo_t foo = (foo_t)dlsym( lib, "foo" );

  foo("World!");

  dlclose(lib);
}

