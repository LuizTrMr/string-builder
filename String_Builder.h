#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include <string>
#include <stdlib.h>
#include <assert.h>
#include <cmath>

#define SB_DEFAULT_CAPACITY 1024
struct String_Builder {
    char*  buf;
    size_t size;
    size_t cap;

    String_Builder(size_t initial_cap);
    String_Builder(const char* string, size_t string_size);
    ~String_Builder();
};

inline size_t sb_len(const String_Builder& sb) {
    return sb.size;
}

inline size_t sb_space(const String_Builder& sb) {
    return sb.cap - sb.size;
}

inline void sb_clear(String_Builder& sb) {
    sb.size = 0;
}

inline void sb_realloc(String_Builder& sb, size_t new_cap) {
    sb.cap = new_cap;
    sb.buf = (char*)realloc(sb.buf, sb.cap);
}

inline std::string_view sb_to_string(const String_Builder& sb) {
    return std::string_view(sb.buf, sb.size);
}

inline std::string_view sb_slice(const String_Builder& sb, size_t start, size_t end) {
    return std::string_view(sb.buf+start, end-start);
}

void sb_write_byte(String_Builder& sb, char b);
void sb_write_string(String_Builder& sb, const char* string, size_t len);
void sb_write_int(String_Builder& sb, int i);

#endif // STRING_BUILDER_H
