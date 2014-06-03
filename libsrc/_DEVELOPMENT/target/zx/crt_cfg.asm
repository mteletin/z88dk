
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; CRT_CFG ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;--------------------------------------------------------------
;-- segment options -------------------------------------------
;--------------------------------------------------------------

; define non-zero segment addresses if you want the segments to
; be located separately from the binary at that address.

; the bss segment is always zeroed by the crt at startup

defc __crt_segment_bss_address = 0

; the data segment is initialized according to the next option

defc __crt_segment_data_address = 0

; specify how the data segment is initialized by the crt

defc __crt_cfg_segment_data = 0

; bit 0 = $01 = data segment is initialized from a stored copy.
;               If this bit is zero, the data segment is not
;               initialized and there is no stored copy.
;
;               If the data segment is attached to the binary,
;               it will be stored with the expected initial
;               values for the first run of the program.
;
; bit 1 = $02 = data segment is initialized from a compressed
;               stored copy.  You must manually supply the
;               compressed data segment separately; details on
;               how to do this can be found in the wiki.


;--------------------------------------------------------------
;-- file options ----------------------------------------------
;--------------------------------------------------------------

defc __crt_cfg_fopen_max = 8

; bit 7 = $80 = set if you don't want any available FILE
;               structs and you don't want fopen to work.

; Otherwise set to zero if you don't want any extra FILE
; structs to be made available.  The actual number of FILE
; structs is always three less than this number because stdin,
; stdout, stderr count as three, and this is the case regardless
; of whether those files are created as part of the crt or not.


;--------------------------------------------------------------
;-- input terminal driver -------------------------------------
;--------------------------------------------------------------

defc __crt_cfg_edit_buflen = 128

; size of the edit buffer when the input terminal is in line
; mode.  setting to zero will disable line mode.


;--------------------------------------------------------------
;-- exit stack size options -----------------------------------
;--------------------------------------------------------------

; set to zero if you don't want an exit stack
; comment out to get the C standard's requirement of 32

defc __crt_cfg_exit_stack_size      = 4
defc __crt_cfg_quickexit_stack_size = 4


;--------------------------------------------------------------
;-- balloc's queue table --------------------------------------
;--------------------------------------------------------------

; set to zero if you don't want a queue table

; your program can still supply a queue table but it must
; supply a word "__qtbl" to hold a pointer to the table.

defc __crt_cfg_qtbl_size = 4


;--------------------------------------------------------------
;-- malloc's heap ---------------------------------------------
;--------------------------------------------------------------

; set to zero if you don't want a heap

; your program can still supply a heap but it must declare
; a word "__heap" to hold a pointer to the heap block.

defc __crt_cfg_heap_size = 2048


;--------------------------------------------------------------
;-- host ------------------------------------------------------
;--------------------------------------------------------------

; supply the address of the host's system() function
; set to zero to return an error

defc __crt_cfg_system_address = 0


;--------------------------------------------------------------
;-- locale ----------------------------------------------------
;--------------------------------------------------------------

; supply the address of locale functions
; set to zero for defaults

defc __crt_cfg_lc_char_ordinal_address = 0
defc __crt_cfg_lc_char_cmp_bc_address = 0
