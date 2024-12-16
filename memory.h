#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void memory_set_char(char * buf, char c, int length);
void memory_set_int(int * buf, int c, int length);
void memory_copy_char(const char * src, int length, char * dst);
void memory_copy_u32(const void * _src, int length, void * _dst);

#ifdef __cplusplus
}
#endif
