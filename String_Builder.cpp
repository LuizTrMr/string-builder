#include "String_Builder.h"

String_Builder::String_Builder(size_t initial_cap) {
    buf  = (char*)malloc(initial_cap);
    size = 0;
    cap  = initial_cap;
}

String_Builder::String_Builder(const char* string, size_t string_size) {
    buf  = (char*)malloc(string_size);
    size = string_size;
    cap  = string_size;
    memcpy(buf, string, string_size);
}

String_Builder::~String_Builder() {
    free(buf);
}

void sb_write_byte(String_Builder& sb, char c) {
    if ( sb.size == sb.cap ) sb_realloc(sb, sb.cap*2);
    sb.buf[sb.size] = c;
    sb.size += 1;
}

void sb_write_string(String_Builder& sb, const char* string, size_t len) {
    if ( len >= sb_space(sb) ) sb_realloc(sb, (sb.cap + len)*2);
    memcpy(sb.buf+sb.size, string, len);
    sb.size += len;
}

void sb_write_int(String_Builder& sb, int i) {
    if ( i == 0 ) {
        if ( sb.size == sb.cap ) sb_realloc(sb, sb.cap*2);
        sb_write_byte(sb, '0');
        return;
    }

    if ( i < 0 ) {
        if ( sb.size == sb.cap ) sb_realloc(sb, sb.cap*2);
        sb_write_byte(sb, '-');
        i = -i;
    }

    int n = log10(i) + 1;
    if ( n >= sb_space(sb) ) sb_realloc(sb, (sb.cap + n)*2);

    char number[n];
    for (int j = 0; j < n; j++) {
        number[j] = i % 10;
        i /= 10;
    }

    for (int j = n-1; j >= 0; j--) sb_write_byte(sb, number[j]+48);
}
