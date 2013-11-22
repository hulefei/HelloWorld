#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

//#include <stdarg.h>
#include <stdio.h>

#define LOGSTRINGS(fm, ...) printf(fm,__VA_ARGS__)
/*
int main() {
    LOGSTRINGS("hello, %d %d", 10,100);
    
    printf("\n");
    printf("%s",__FILE__);
    printf("\n");
    printf("%d",__LINE__);
    printf("\n");
    printf("%s",__FUNCTION__);
    
    printf("\n");
    
    return 0;
}
*/