#include "sanitize_string.h"

void c_identifier(char *s) {

    for (char *c = s; *c != '\0'; c++) {

        bool is_legal = isalnum(*c) || *c == '_';

        bool c1_is_digit = isdigit(*c) && (c == s);
        
        if (!is_legal || c1_is_digit) {
            *c = '_';
        }
    }
}

