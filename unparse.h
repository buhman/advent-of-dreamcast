#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int unparse_base10(char * s, uint32_t n, int len, char fill);
int unparse_base16(char * s, uint32_t n, int len, char fill);

#ifdef __cplusplus
}
#endif
