
; float log10(float x) __z88dk_fastcall

SECTION code_fp_math48

PUBLIC cm48_sdccix_log10

EXTERN cm48_sdccixp_dx2m48, am48_log10, cm48_sdccixp_m482d

cm48_sdccix_log10:

   call cm48_sdccixp_dx2m48
   
   call am48_log10
   
   jp cm48_sdccixp_m482d