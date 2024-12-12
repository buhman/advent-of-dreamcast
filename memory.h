#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void memory_set_char(char * buf, char c, int length);
void memory_set_int(int * buf, int c, int length);

#ifdef __cplusplus
}
#endif
