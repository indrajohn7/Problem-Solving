#include <cstddef>
#include<bits/stdc++.h>


template<typename T, size_t SIZE>
size_t getSize(T (&)[SIZE]) {
    return SIZE;
}

struct foo_t {
    int ball;
};

int main()
{
    foo_t foos3[] = {{1},{2},{3}};
    foo_t foos5[] = {{1},{2},{3},{4},{5}};
    printf("%u\n", getSize(foos3));
    printf("%u\n", getSize(foos5));
    printf("%u\n", sizeof(foos3)/sizeof(foo_t));
    printf("%u\n", sizeof(foos5)/sizeof(foo_t));

    return 0;
}

