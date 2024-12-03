#pragma once

#ifdef __cplusplus
extern "C" {
#endif

const char * parse_skip(const char * s, char c);
const char * parse_base10(const char * s, int * n);
const char * parse_match(const char * s, const char * m);

#ifdef __cplusplus
}
#endif
