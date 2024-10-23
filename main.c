#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


struct String {
    uint64_t length; // strlen -> one less than total characters
    char* contents; // has space for length + null terminator
};

typedef struct String String;


String new_String(char* initial_contents) {
    uint64_t size = strlen(initial_contents);
    String r = { size, initial_contents };

    return r;
}


String plus(String s1, String s2) {
    uint64_t new_size = s1.length + s2.length + 1;
    char new_contents[new_size]; // THIS IS VERY WRONG because of line 33. NOT REAL IMPLEMENTATION!

    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length); // Adds s1.length to the starting pointer of new_contents

    new_contents[new_size - 1] = 0;

    String r = { new_size - 1, new_contents };
    return r;
}


int main() {
    String s = new_String("hello");
    printf("%s\n", s.contents);

    String s2 = new_String("cse29");

    String hello_cse = plus(s, s2);
    String hello_bang = plus(s, new_String("!!!!"));

    printf("%s\n", hello_cse.contents);
    printf("%s\n", hello_bang.contents);

    return 0;
}
