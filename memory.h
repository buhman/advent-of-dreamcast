#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void memory_set_char(char * buf, char c, int length);
void memory_set_int(int * buf, int c, int length);
void memory_copy_char(char * src, int length, char * dst);

#ifdef __cplusplus
}
#endif
