#include "String_Builder.h"

#include <iostream>
#define COUT std::cout
#define ENDL std::endl

int main() {
    String_Builder sb = String_Builder(128);
    sb_write_string(sb, "Value", 5);
    sb_write_byte(sb, ':');
    sb_write_byte(sb, ' ');
    sb_write_int(sb, -189);

    COUT << sb_to_string(sb) << ENDL;

    sb_clear(sb);
    const char* text = "Hello people of the world";
    sb_write_string(sb, text, strlen(text));

    COUT << sb_slice(sb, 0, 5) << ENDL;

    return 0;
}
