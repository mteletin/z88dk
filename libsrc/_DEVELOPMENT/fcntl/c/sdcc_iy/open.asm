
; int open(const char *path, int oflag, ...)

SECTION seg_code_fcntl

PUBLIC _open

_open:
   
   INCLUDE "fcntl/z80/asm_open.asm"