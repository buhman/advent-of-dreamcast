#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void open_input(int ix, char ** buf, int * length);
void open_sample(int ix, int part, char ** buf, int * length);

#ifdef __cplusplus
}
#endif
