
SECTION code_font_fzx

PUBLIC asm_fzx_glyph_width

EXTERN asm_fzx_char_metrics

asm_fzx_glyph_width:

   ; enter :  a = char
   ;         hl = struct fzx_font *
   ;
   ; exit  : hl = bitmap address
   ;          a = glyph width - 1
   ;          c = vertical shift
   ;          b = width - 1
   ;
   ; ueses : af, bc, hl
   
   call asm_fzx_char_metrics
   
   neg
   add a,b                     ; a = width - 1 - kern
   
   ret