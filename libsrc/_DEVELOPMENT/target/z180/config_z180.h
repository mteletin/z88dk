





#ifndef __CONFIG_Z88DK_H_
#define __CONFIG_Z88DK_H_

// Automatically Generated at Library Build Time














#undef  __Z88DK
#define __Z88DK  1992












#undef  __EMBEDDED_Z180
#define __EMBEDDED_Z180  1












#undef  __Z180
#define __Z180  0x04

#define __Z180_Z80180  0x01
#define __Z180_Z8L180  0x02
#define __Z180_Z8S180  0x04

#define __CPU_CLOCK  33000000

#define __CPU_INFO  0x00

#define __CPU_INFO_ENABLE_SLL  0x01

#define __IO_VECTOR_BASE  128

#define __IO_BASE_ADDRESS  0

#ifdef __SCCZ80


   ; Z8S180 / Z8L180 CLASS

   #define CNTLA0  0
   #define CNTLA1  1
   #define CNTLB0  2
   #define CNTLB1  3
   #define STAT0  4
   #define STAT1  5
   #define TDR0  6
   #define TDR1  7
   #define RDR0  8
   #define RDR1  9
   #define ASEXT0  18
   #define ASEXT1  19
   #define ASTC0L  26
   #define ASTC0H  27
   #define ASTC1L  28
   #define ASTC1H  29

   #define CNTR  10
   #define TRD  11

   #define TMDR0L  12
   #define TMDR0H  13
   #define RLDR0L  14
   #define RLDR0H  15
   #define TCR  16
   #define TMDR1L  20
   #define TMDR1H  21
   #define RLDR1L  22
   #define RLDR1H  23

   #define FRC  24
   #define CMR  30
   #define CCR  31

   #define SAR0L  32
   #define SAR0H  33
   #define SAR0B  34
   #define DAR0L  35
   #define DAR0H  36
   #define DAR0B  37
   #define BCR0L  38
   #define BCR0H  39
   #define MAR1L  40
   #define MAR1H  41
   #define MAR1B  42
   #define IAR1L  43
   #define IAR1H  44
   #define IAR1B  45
   #define BCR1L  46
   #define BCR1H  47
   #define DSTAT  48
   #define DMODE  49
   #define DCNTL  50

   #define IL  51
   #define ITC  52

   #define RCR  54

   #define CBR  56
   #define BBR  57
   #define CBAR  58

   #define OMCR  62
   #define ICR  63


ENDIF

IFDEF __SDCC


   ; Z8S180 / Z8L180 CLASS

   __sfr __at 0 CNTLA0;
   __sfr __at 1 CNTLA1;
   __sfr __at 2 CNTLB0;
   __sfr __at 3 CNTLB1;
   __sfr __at 4 STAT0;
   __sfr __at 5 STAT1;
   __sfr __at 6 TDR0;
   __sfr __at 7 TDR1;
   __sfr __at 8 RDR0;
   __sfr __at 9 RDR1;
   __sfr __at 18 ASEXT0;
   __sfr __at 19 ASEXT1;
   __sfr __at 26 ASTC0L;
   __sfr __at 27 ASTC0H;
   __sfr __at 28 ASTC1L;
   __sfr __at 29 ASTC1H;

   __sfr __at 10 CNTR;
   __sfr __at 11 TRD;

   __sfr __at 12 TMDR0L;
   __sfr __at 13 TMDR0H;
   __sfr __at 14 RLDR0L;
   __sfr __at 15 RLDR0H;
   __sfr __at 16 TCR;
   __sfr __at 20 TMDR1L;
   __sfr __at 21 TMDR1H;
   __sfr __at 22 RLDR1L;
   __sfr __at 23 RLDR1H;

   __sfr __at 24 FRC;
   __sfr __at 30 CMR;
   __sfr __at 31 CCR;

   __sfr __at 32 SAR0L;
   __sfr __at 33 SAR0H;
   __sfr __at 34 SAR0B;
   __sfr __at 35 DAR0L;
   __sfr __at 36 DAR0H;
   __sfr __at 37 DAR0B;
   __sfr __at 38 BCR0L;
   __sfr __at 39 BCR0H;
   __sfr __at 40 MAR1L;
   __sfr __at 41 MAR1H;
   __sfr __at 42 MAR1B;
   __sfr __at 43 IAR1L;
   __sfr __at 44 IAR1H;
   __sfr __at 45 IAR1B;
   __sfr __at 46 BCR1L;
   __sfr __at 47 BCR1H;
   __sfr __at 48 DSTAT;
   __sfr __at 49 DMODE;
   __sfr __at 50 DCNTL;

   __sfr __at 51 IL;
   __sfr __at 52 ITC;

   __sfr __at 54 RCR;

   __sfr __at 56 CBR;
   __sfr __at 57 BBR;
   __sfr __at 58 CBAR;

   __sfr __at 62 OMCR;
   __sfr __at 63 ICR;


ENDIF












#define __CLIB_OPT_MULTITHREAD  0x00

#define __CLIB_OPT_MULTITHREAD_LOCK_HEAPS  0x01
#define __CLIB_OPT_MULTITHREAD_LOCK_FILES  0x02
#define __CLIB_OPT_MULTITHREAD_LOCK_FLIST  0x04
#define __CLIB_OPT_MULTITHREAD_LOCK_FDTBL  0x08
#define __CLIB_OPT_MULTITHREAD_LOCK_FDSTR  0x10

#define __CLIB_OPT_IMATH  0

#define __CLIB_OPT_IMATH_FAST  0x0f

#define __CLIB_OPT_IMATH_FAST_DIV_UNROLL  0x01
#define __CLIB_OPT_IMATH_FAST_DIV_LZEROS  0x02
#define __CLIB_OPT_IMATH_FAST_MUL_UNROLL  0x04
#define __CLIB_OPT_IMATH_FAST_MUL_LZEROS  0x08
#define __CLIB_OPT_IMATH_FAST_LIA  0x80

#define __CLIB_OPT_IMATH_SELECT  0x00

#define __CLIB_OPT_IMATH_SELECT_FAST_ASR  0x01
#define __CLIB_OPT_IMATH_SELECT_FAST_LSR  0x02
#define __CLIB_OPT_IMATH_SELECT_FAST_LSL  0x04

#define __CLIB_OPT_TXT2NUM  0x04

#define __CLIB_OPT_TXT2NUM_INT_BIN  0x01
#define __CLIB_OPT_TXT2NUM_INT_OCT  0x02
#define __CLIB_OPT_TXT2NUM_INT_DEC  0x04
#define __CLIB_OPT_TXT2NUM_INT_HEX  0x08

#define __CLIB_OPT_TXT2NUM_LONG_BIN  0x10
#define __CLIB_OPT_TXT2NUM_LONG_OCT  0x20
#define __CLIB_OPT_TXT2NUM_LONG_DEC  0x40
#define __CLIB_OPT_TXT2NUM_LONG_HEX  0x80

#define __CLIB_OPT_TXT2NUM_SELECT  0x00

#define __CLIB_OPT_TXT2NUM_SELECT_FAST_BIN  0x01
#define __CLIB_OPT_TXT2NUM_SELECT_FAST_OCT  0x02
#define __CLIB_OPT_TXT2NUM_SELECT_FAST_DEC  0x04
#define __CLIB_OPT_TXT2NUM_SELECT_FAST_HEX  0x08

#define __CLIB_OPT_NUM2TXT  0x00

#define __CLIB_OPT_NUM2TXT_INT_BIN  0x01
#define __CLIB_OPT_NUM2TXT_INT_OCT  0x02
#define __CLIB_OPT_NUM2TXT_INT_DEC  0x04
#define __CLIB_OPT_NUM2TXT_INT_HEX  0x08

#define __CLIB_OPT_NUM2TXT_LONG_BIN  0x10
#define __CLIB_OPT_NUM2TXT_LONG_OCT  0x20
#define __CLIB_OPT_NUM2TXT_LONG_DEC  0x40
#define __CLIB_OPT_NUM2TXT_LONG_HEX  0x80

#define __CLIB_OPT_NUM2TXT_SELECT  0x00

#define __CLIB_OPT_NUM2TXT_SELECT_FAST_BIN  0x01
#define __CLIB_OPT_NUM2TXT_SELECT_FAST_OCT  0x02
#define __CLIB_OPT_NUM2TXT_SELECT_FAST_DEC  0x04
#define __CLIB_OPT_NUM2TXT_SELECT_FAST_HEX  0x08

#define __CLIB_OPT_STDIO  0x00

#define __CLIB_OPT_STDIO_VALID  0x01

#define CHAR_CR  13
#define CHAR_LF  10
#define CHAR_BS  12
#define CHAR_ESC  27
#define CHAR_CAPS  6
#define CHAR_BELL  7
#define CHAR_CTRL_C  3
#define CHAR_CTRL_D  4
#define CHAR_CTRL_Z  26
#define CHAR_CURSOR_UC  45
#define CHAR_CURSOR_LC  95
#define CHAR_PASSWORD  42

#define __CLIB_OPT_PRINTF  0x002ff6ff

#define __CLIB_OPT_PRINTF_d  0x00000001
#define __CLIB_OPT_PRINTF_u  0x00000002
#define __CLIB_OPT_PRINTF_x  0x00000004
#define __CLIB_OPT_PRINTF_X  0x00000008
#define __CLIB_OPT_PRINTF_o  0x00000010
#define __CLIB_OPT_PRINTF_n  0x00000020
#define __CLIB_OPT_PRINTF_i  0x00000040
#define __CLIB_OPT_PRINTF_p  0x00000080
#define __CLIB_OPT_PRINTF_B  0x00000100
#define __CLIB_OPT_PRINTF_s  0x00000200
#define __CLIB_OPT_PRINTF_c  0x00000400
#define __CLIB_OPT_PRINTF_I  0x00000800
#define __CLIB_OPT_PRINTF_ld  0x00001000
#define __CLIB_OPT_PRINTF_lu  0x00002000
#define __CLIB_OPT_PRINTF_lx  0x00004000
#define __CLIB_OPT_PRINTF_lX  0x00008000
#define __CLIB_OPT_PRINTF_lo  0x00010000
#define __CLIB_OPT_PRINTF_ln  0x00020000
#define __CLIB_OPT_PRINTF_li  0x00040000
#define __CLIB_OPT_PRINTF_lp  0x00080000
#define __CLIB_OPT_PRINTF_lB  0x00100000
#define __CLIB_OPT_PRINTF_a  0x00400000
#define __CLIB_OPT_PRINTF_A  0x00800000
#define __CLIB_OPT_PRINTF_e  0x01000000
#define __CLIB_OPT_PRINTF_E  0x02000000
#define __CLIB_OPT_PRINTF_f  0x04000000
#define __CLIB_OPT_PRINTF_F  0x08000000
#define __CLIB_OPT_PRINTF_g  0x10000000
#define __CLIB_OPT_PRINTF_G  0x20000000

#define __CLIB_OPT_PRINTF_2  0x00

#define __CLIB_OPT_PRINTF_2_lld  0x01
#define __CLIB_OPT_PRINTF_2_llu  0x02
#define __CLIB_OPT_PRINTF_2_llx  0x04
#define __CLIB_OPT_PRINTF_2_llX  0x08
#define __CLIB_OPT_PRINTF_2_llo  0x10
#define __CLIB_OPT_PRINTF_2_lli  0x40

#define __CLIB_OPT_SCANF  0x002ff6ff

#define __CLIB_OPT_SCANF_d  0x00000001
#define __CLIB_OPT_SCANF_u  0x00000002
#define __CLIB_OPT_SCANF_x  0x00000004
#define __CLIB_OPT_SCANF_X  0x00000008
#define __CLIB_OPT_SCANF_o  0x00000010
#define __CLIB_OPT_SCANF_n  0x00000020
#define __CLIB_OPT_SCANF_i  0x00000040
#define __CLIB_OPT_SCANF_p  0x00000080
#define __CLIB_OPT_SCANF_B  0x00000100
#define __CLIB_OPT_SCANF_s  0x00000200
#define __CLIB_OPT_SCANF_c  0x00000400
#define __CLIB_OPT_SCANF_I  0x00000800
#define __CLIB_OPT_SCANF_ld  0x00001000
#define __CLIB_OPT_SCANF_lu  0x00002000
#define __CLIB_OPT_SCANF_lx  0x00004000
#define __CLIB_OPT_SCANF_lX  0x00008000
#define __CLIB_OPT_SCANF_lo  0x00010000
#define __CLIB_OPT_SCANF_ln  0x00020000
#define __CLIB_OPT_SCANF_li  0x00040000
#define __CLIB_OPT_SCANF_lp  0x00080000
#define __CLIB_OPT_SCANF_lB  0x00100000
#define __CLIB_OPT_SCANF_BRACKET  0x00200000
#define __CLIB_OPT_SCANF_a  0x00400000
#define __CLIB_OPT_SCANF_A  0x00800000
#define __CLIB_OPT_SCANF_e  0x01000000
#define __CLIB_OPT_SCANF_E  0x02000000
#define __CLIB_OPT_SCANF_f  0x04000000
#define __CLIB_OPT_SCANF_F  0x08000000
#define __CLIB_OPT_SCANF_g  0x10000000
#define __CLIB_OPT_SCANF_G  0x20000000

#define __CLIB_OPT_SCANF_2  0x00

#define __CLIB_OPT_SCANF_2_lld  0x01
#define __CLIB_OPT_SCANF_2_llu  0x02
#define __CLIB_OPT_SCANF_2_llx  0x04
#define __CLIB_OPT_SCANF_2_llX  0x08
#define __CLIB_OPT_SCANF_2_llo  0x10
#define __CLIB_OPT_SCANF_2_lli  0x40

#define __CLIB_OPT_FASTCOPY  0x00

#define __CLIB_OPT_FASTCOPY_MEMCPY  0x01
#define __CLIB_OPT_FASTCOPY_MEMSET  0x02
#define __CLIB_OPT_FASTCOPY_LDIR  0x20
#define __CLIB_OPT_FASTCOPY_LDIR_SMC  0x40
#define __CLIB_OPT_FASTCOPY_MEMCPY_SMC  0x80

#define __CLIB_OPT_STRTOD  0x00

#define __CLIB_OPT_STRTOD_NAN  0x01
#define __CLIB_OPT_STRTOD_INF  0x01
#define __CLIB_OPT_STRTOD_HEX  0x02

#define __CLIB_OPT_SORT  1

#define __CLIB_OPT_SORT_INSERTION  0
#define __CLIB_OPT_SORT_SHELL  1
#define __CLIB_OPT_SORT_QUICK  2

#define __CLIB_OPT_SORT_QSORT  0x0c

#define __CLIB_OPT_SORT_QSORT_PIVOT  0x3
#define __CLIB_OPT_SORT_QSORT_PIVOT_MID  0x0
#define __CLIB_OPT_SORT_QSORT_PIVOT_RAN  0x1
#define __CLIB_OPT_SORT_QSORT_ENABLE_INSERTION  0x04
#define __CLIB_OPT_SORT_QSORT_ENABLE_EQUAL  0x08

#define __CLIB_OPT_ERROR  0x00

#define __CLIB_OPT_ERROR_ENABLED  0x01
#define __CLIB_OPT_ERROR_VERBOSE  0x02
















#define __EOK  0
#define __EACCES  1
#define __EBADF  2
#define __EBDFD  3
#define __EDOM  4
#define __EFBIG  5
#define __EINVAL  6
#define __EMFILE  7
#define __ENFILE  8
#define __ENOLCK  9
#define __ENOMEM  10
#define __ENOTSUP  11
#define __EOVERFLOW  12
#define __ERANGE  13
#define __ESTAT  14
#define __EAGAIN  15
#define __EWOULDBLOCK  15

#define __ERROR_NEXT  50

#define STDIO_SEEK_SET  0
#define STDIO_SEEK_CUR  1
#define STDIO_SEEK_END  2

#define STDIO_MSG_PUTC  1
#define STDIO_MSG_WRIT  2
#define STDIO_MSG_GETC  3
#define STDIO_MSG_EATC  4
#define STDIO_MSG_READ  5
#define STDIO_MSG_SEEK  6
#define STDIO_MSG_ICTL  7
#define STDIO_MSG_FLSH  8
#define STDIO_MSG_CLOS  9

#define ITERM_MSG_GETC  15
#define ITERM_MSG_INTERRUPT  16
#define ITERM_MSG_PUTC  17
#define ITERM_MSG_PRINT_CURSOR  18
#define ITERM_MSG_ERASE_CURSOR  19
#define ITERM_MSG_ERASE_CURSOR_PWD  20
#define ITERM_MSG_BS  21
#define ITERM_MSG_BS_PWD  22
#define ITERM_MSG_READLINE_BEGIN  23
#define ITERM_MSG_READLINE_END  24
#define ITERM_MSG_BELL  25
      
#define __MESSAGE_ITERM_NEXT__  26

#define OTERM_MSG_PUTC  30
#define OTERM_MSG_TTY  31
#define OTERM_MSG_PRINTC  32
#define OTERM_MSG_SCROLL  33
#define OTERM_MSG_CLS  34
#define OTERM_MSG_PAUSE  35
#define OTERM_MSG_BELL  36
#define OTERM_MSG_PSCROLL  37
      
#define __MESSAGE_OTERM_NEXT__  38

#define ICHAR_MSG_GETC  15
#define OCHAR_MSG_PUTC_BIN  30
#define OCHAR_MSG_PUTC  32
  
#define __MESSAGE_NEXT__  45

#define mtx_plain  0x01
#define mtx_recursive  0x02
#define mtx_timed  0x04

#define thrd_success  0x00
#define thrd_error  0x01
#define thrd_nomem  0x02
#define thrd_busy  0x04
#define thrd_timedout  0x08

#define IOCTL_RESET  0x0000

#define IOCTL_ITERM_ECHO  0xc081
#define IOCTL_ITERM_PASS  0xc041
#define IOCTL_ITERM_LINE  0xc021
#define IOCTL_ITERM_COOK  0xc011
#define IOCTL_ITERM_CAPS  0xc009
#define IOCTL_ITERM_CRLF  0xc101
#define IOCTL_ITERM_CURS  0xc201
   
#define IOCTL_ITERM_TIE  0x0201
#define IOCTL_ITERM_GET_EDITBUF  0x0381
#define IOCTL_ITERM_SET_EDITBUF  0x0301

#define IOCTL_OTERM_PAGE  0xc082
#define IOCTL_OTERM_PAUSE  0xc042
#define IOCTL_OTERM_COOK  0xc022
#define IOCTL_OTERM_CRLF  0xc012
#define IOCTL_OTERM_CLEAR  0xe002
#define IOCTL_OTERM_SIGNAL  0xc202
#define IOCTL_OTERM_BELL  0xc102

#define IOCTL_OTERM_CLS  0x0102
#define IOCTL_OTERM_RESET_SCROLL  0x0202
#define IOCTL_OTERM_GET_WINDOW_COORD  0x0382
#define IOCTL_OTERM_SET_WINDOW_COORD  0x0302
#define IOCTL_OTERM_GET_WINDOW_RECT  0x0482
#define IOCTL_OTERM_SET_WINDOW_RECT  0x0402
#define IOCTL_OTERM_GET_CURSOR_COORD  0x0582
#define IOCTL_OTERM_SET_CURSOR_COORD  0x0502
#define IOCTL_OTERM_GET_OTERM  0x0602
#define IOCTL_OTERM_SCROLL  0x0702
#define IOCTL_OTERM_FONT  0x0802

#define IOCTL_OTERM_FZX_GET_PAPER_COORD  0x0a82
#define IOCTL_OTERM_FZX_SET_PAPER_COORD  0x0a02
#define IOCTL_OTERM_FZX_GET_PAPER_RECT  0x0b82
#define IOCTL_OTERM_FZX_SET_PAPER_RECT  0x0b02
#define IOCTL_OTERM_FZX_LEFT_MARGIN  0x0c02
#define IOCTL_OTERM_FZX_LINE_SPACING  0x0d02
#define IOCTL_OTERM_FZX_SPACE_EXPAND  0x0e02
#define IOCTL_OTERM_FZX_GET_FZX_STATE  0x0f82
#define IOCTL_OTERM_FZX_SET_FZX_STATE  0x0f02

#define IOCTL_ICHAR_CRLF  0xc103
   
#define IOCTL_OCHAR_CRLF  0xc014






















#endif



