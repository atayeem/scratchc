#ifndef _SANITIZE_STRING_H
#define _SANITIZE_STRING_H

#include <ctype.h>
#include <stdbool.h>

// Makes the input safe to use as an identifier in C
// Ex: "12as3ca-=+_a3;;a" ---> "_2as3ca_a3a"
void c_identifier(char *s);


#endif