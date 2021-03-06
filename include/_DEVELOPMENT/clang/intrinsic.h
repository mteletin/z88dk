
// automatically generated by m4 from headers in proto subdir


#ifndef _INTRINSIC_H
#define _INTRINSIC_H

#ifdef __SDCC

// disable warnings connected to intrinsics

#pragma disable_warning 84
#pragma disable_warning 112

#endif

#ifdef __CLANG

#define intrinsic_label(name)  { extern void intrinsic_label_##name(void); intrinsic_label_##name(); }
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#define intrinsic_in8(port)  ((unsigned char)intrinsic_in8_port_##port())
#define intrinsic_out8(port,value)  ((unsigned char)(intrinsic_out8_port_##port(),intrinsic_out8_value_##value()))
#define intrinsic_in16(port)  ((unsigned char)intrinsic_in16_port_##port())
#define intrinsic_out16(port,value)  ((unsigned char)(intrinsic_out16_port_##port(),intrinsic_out16_value_##value()))

#endif

#ifdef __SDCC

#define intrinsic_label(name)  { extern void intrinsic_label_##name(void) __preserves_regs(a,b,c,d,e,h,l); intrinsic_label_##name(); }
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#define intrinsic_in8(port)  ((unsigned char)intrinsic_in8_port_##port())
#define intrinsic_out8(port,value)  ((unsigned char)(intrinsic_out8_port_##port(),intrinsic_out8_value_##value()))
#define intrinsic_in16(port)  ((unsigned char)intrinsic_in16_port_##port())
#define intrinsic_out16(port,value)  ((unsigned char)(intrinsic_out16_port_##port(),intrinsic_out16_value_##value()))

#endif

#ifdef __SCCZ80

#define intrinsic_label(name)  asm(#name":")
#define intrinsic_load16(address)  ((unsigned int)intrinsic_load16_##address())
#define intrinsic_store16(address,value)  ((unsigned int)(intrinsic_store16_address_##address(),intrinsic_store16_value_##value()))

#define intrinsic_in8(port)  ((unsigned char)intrinsic_in8_port_##port())
#define intrinsic_out8(port,value)  ((unsigned char)(intrinsic_out8_port_##port(),intrinsic_out8_value_##value()))
#define intrinsic_in16(port)  ((unsigned char)intrinsic_in16_port_##port())
#define intrinsic_out16(port,value)  ((unsigned char)(intrinsic_out16_port_##port(),intrinsic_out16_value_##value()))

#endif

extern void intrinsic_stub(void);



extern void intrinsic_di(void);


extern void intrinsic_ei(void);


extern void intrinsic_halt(void);


extern void intrinsic_reti(void);


extern void intrinsic_retn(void);


extern void intrinsic_im_0(void);


extern void intrinsic_im_1(void);


extern void intrinsic_im_2(void);


extern void intrinsic_nop(void);


extern void intrinsic_push_af(void);


extern void intrinsic_push_bc(void);


extern void intrinsic_push_de(void);


extern void intrinsic_push_hl(void);


extern void intrinsic_push_ix(void);


extern void intrinsic_push_iy(void);


extern void intrinsic_pop_af(void);


extern void intrinsic_pop_bc(void);


extern void intrinsic_pop_de(void);


extern void intrinsic_pop_hl(void);


extern void intrinsic_pop_ix(void);


extern void intrinsic_pop_iy(void);



extern void intrinsic_ex_de_hl(void);


extern void intrinsic_exx(void);



extern void *intrinsic_return_bc(void);


extern void *intrinsic_return_de(void);



extern unsigned int intrinsic_swap_endian_16(unsigned long n);


extern unsigned long intrinsic_swap_endian_32(unsigned long n);


extern unsigned long intrinsic_swap_word_32(unsigned long n);



#endif
