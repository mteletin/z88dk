
; ===============================================================
; Feb 2014
; ===============================================================
; 
; size_t p_forward_list_alt_size(p_forward_list_alt_t *list)
;
; Return number of items in list.  O(n).
;
; ===============================================================

XLIB asm_p_forward_list_alt_size

LIB asm_p_forward_list_size

asm_p_forward_list_alt_size:

   jp asm_p_forward_list_size

;defc asm_p_forward_list_alt_size = asm_p_forward_list_size

   ; enter : hl = p_forward_list_alt_t *list
   ;
   ; exit  : hl = number of items in list
   ;
   ; uses  : af, de, hl
