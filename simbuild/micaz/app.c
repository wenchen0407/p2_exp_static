#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 150 "/opt/local/lib/gcc46/gcc/x86_64-apple-darwin12/4.6.4/include/stddef.h" 3
typedef long int ptrdiff_t;
#line 212
typedef long unsigned int size_t;
#line 324
typedef int wchar_t;
# 8 "/opt/nesc/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 37 "/usr/include/i386/_types.h" 3
typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
#line 70
typedef int __darwin_ct_rune_t;








#line 76
typedef union __nesc_unnamed4242 {
  char __mbstate8[128];
  long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;





typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
# 58 "/usr/include/sys/_types.h" 3
struct __darwin_pthread_handler_rec {

  void (*__routine)(void *arg_0x108752738);
  void *__arg;
  struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t {
#line 64
  long __sig;
#line 64
  char __opaque[56];
};
#line 65
struct _opaque_pthread_cond_t {
#line 65
  long __sig;
#line 65
  char __opaque[40];
};
#line 66
struct _opaque_pthread_condattr_t {
#line 66
  long __sig;
#line 66
  char __opaque[8];
};
#line 67
struct _opaque_pthread_mutex_t {
#line 67
  long __sig;
#line 67
  char __opaque[56];
};
#line 68
struct _opaque_pthread_mutexattr_t {
#line 68
  long __sig;
#line 68
  char __opaque[8];
};
#line 69
struct _opaque_pthread_once_t {
#line 69
  long __sig;
#line 69
  char __opaque[8];
};
#line 70
struct _opaque_pthread_rwlock_t {
#line 70
  long __sig;
#line 70
  char __opaque[192];
};
#line 71
struct _opaque_pthread_rwlockattr_t {
#line 71
  long __sig;
#line 71
  char __opaque[16];
};
#line 72
struct _opaque_pthread_t {
#line 72
  long __sig;
#line 72
  struct __darwin_pthread_handler_rec *__cleanup_stack;
#line 72
  char __opaque[1168];
};
#line 94
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;

#line 112
typedef struct _opaque_pthread_attr_t 
__darwin_pthread_attr_t;

#line 114
typedef struct _opaque_pthread_cond_t 
__darwin_pthread_cond_t;

#line 116
typedef struct _opaque_pthread_condattr_t 
__darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;

#line 119
typedef struct _opaque_pthread_mutex_t 
__darwin_pthread_mutex_t;

#line 121
typedef struct _opaque_pthread_mutexattr_t 
__darwin_pthread_mutexattr_t;

#line 123
typedef struct _opaque_pthread_once_t 
__darwin_pthread_once_t;

#line 125
typedef struct _opaque_pthread_rwlock_t 
__darwin_pthread_rwlock_t;

#line 127
typedef struct _opaque_pthread_rwlockattr_t 
__darwin_pthread_rwlockattr_t;

#line 129
typedef struct _opaque_pthread_t *
__darwin_pthread_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];
# 39 "/usr/include/_types.h" 3
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;
# 29 "/opt/local/lib/gcc46/gcc/x86_64-apple-darwin12/4.6.4/include-fixed/stdint.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef int int32_t;




typedef long long int64_t;




typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned int uint32_t;




typedef unsigned long long uint64_t;



typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;






typedef long intptr_t;




typedef unsigned long uintptr_t;







typedef long int intmax_t;








typedef long unsigned int uintmax_t;
# 244 "/usr/include/inttypes.h" 3
#line 241
typedef struct __nesc_unnamed4243 {
  intmax_t quot;
  intmax_t rem;
} imaxdiv_t;
# 281 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;
#line 303
static __inline int8_t __nesc_hton_int8(void * target, int8_t value)  ;






static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;
#line 340
static __inline uint32_t __nesc_ntoh_uint32(const void * source)  ;






static __inline uint32_t __nesc_hton_uint32(void * target, uint32_t value)  ;
#line 431
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 81 "/usr/include/string.h" 3
int memcmp(const void *arg_0x1088f9970, const void *arg_0x1088f9c48, size_t arg_0x1088f7020);





int strcmp(const char *arg_0x108902af8, const char *arg_0x108902dd0);




size_t strlen(const char *arg_0x108904628);




char *strrchr(const char *arg_0x10890e5e0, int arg_0x10890e848);


char *strtok(char *arg_0x10890b858, const char *arg_0x10890bb30);
#line 155
typedef __darwin_ssize_t ssize_t;
# 58 "/usr/include/secure/_string.h" 3
static __inline void *
__inline_memcpy_chk(void *__dest, const void *__src, size_t __len);
#line 80
static __inline void *
__inline_memset_chk(void *__dest, int __val, size_t __len);









static __inline char *
__inline_strcpy_chk(char *__dest, const char *__src);
# 83 "/usr/include/sys/wait.h" 3
#line 79
typedef enum __nesc_unnamed4244 {
  P_ALL, 
  P_PID, 
  P_PGID
} idtype_t;






typedef __darwin_pid_t pid_t;




typedef __darwin_id_t id_t;
# 39 "/usr/include/i386/signal.h" 3
typedef int sig_atomic_t;
# 43 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_i386_thread_state {

  unsigned int __eax;
  unsigned int __ebx;
  unsigned int __ecx;
  unsigned int __edx;
  unsigned int __edi;
  unsigned int __esi;
  unsigned int __ebp;
  unsigned int __esp;
  unsigned int __ss;
  unsigned int __eflags;
  unsigned int __eip;
  unsigned int __cs;
  unsigned int __ds;
  unsigned int __es;
  unsigned int __fs;
  unsigned int __gs;
};
#line 89
struct __darwin_fp_control {

  unsigned short __invalid : 1, 
  __denorm : 1, 
  __zdiv : 1, 
  __ovrfl : 1, 
  __undfl : 1, 
  __precis : 1,  : 
  2, 
  __pc : 2, 





  __rc : 2,  : 






  1,  : 
  3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
#line 147
struct __darwin_fp_status {

  unsigned short __invalid : 1, 
  __denorm : 1, 
  __zdiv : 1, 
  __ovrfl : 1, 
  __undfl : 1, 
  __precis : 1, 
  __stkflt : 1, 
  __errsumm : 1, 
  __c0 : 1, 
  __c1 : 1, 
  __c2 : 1, 
  __tos : 3, 
  __c3 : 1, 
  __busy : 1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
#line 191
struct __darwin_mmst_reg {

  char __mmst_reg[10];
  char __mmst_rsrv[6];
};
#line 210
struct __darwin_xmm_reg {

  char __xmm_reg[16];
};
#line 232
struct __darwin_i386_float_state {

  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  char __fpu_rsrv4[14 * 16];
  int __fpu_reserved1;
};


struct __darwin_i386_avx_state {

  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  char __fpu_rsrv4[14 * 16];
  int __fpu_reserved1;
  char __avx_reserved1[64];
  struct __darwin_xmm_reg __fpu_ymmh0;
  struct __darwin_xmm_reg __fpu_ymmh1;
  struct __darwin_xmm_reg __fpu_ymmh2;
  struct __darwin_xmm_reg __fpu_ymmh3;
  struct __darwin_xmm_reg __fpu_ymmh4;
  struct __darwin_xmm_reg __fpu_ymmh5;
  struct __darwin_xmm_reg __fpu_ymmh6;
  struct __darwin_xmm_reg __fpu_ymmh7;
};
#line 402
struct __darwin_i386_exception_state {

  __uint16_t __trapno;
  __uint16_t __cpu;
  __uint32_t __err;
  __uint32_t __faultvaddr;
};
#line 422
struct __darwin_x86_debug_state32 {

  unsigned int __dr0;
  unsigned int __dr1;
  unsigned int __dr2;
  unsigned int __dr3;
  unsigned int __dr4;
  unsigned int __dr5;
  unsigned int __dr6;
  unsigned int __dr7;
};
#line 454
struct __darwin_x86_thread_state64 {

  __uint64_t __rax;
  __uint64_t __rbx;
  __uint64_t __rcx;
  __uint64_t __rdx;
  __uint64_t __rdi;
  __uint64_t __rsi;
  __uint64_t __rbp;
  __uint64_t __rsp;
  __uint64_t __r8;
  __uint64_t __r9;
  __uint64_t __r10;
  __uint64_t __r11;
  __uint64_t __r12;
  __uint64_t __r13;
  __uint64_t __r14;
  __uint64_t __r15;
  __uint64_t __rip;
  __uint64_t __rflags;
  __uint64_t __cs;
  __uint64_t __fs;
  __uint64_t __gs;
};
#line 509
struct __darwin_x86_float_state64 {

  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;


  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;

  __uint16_t __fpu_rsrv2;


  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;

  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  struct __darwin_xmm_reg __fpu_xmm8;
  struct __darwin_xmm_reg __fpu_xmm9;
  struct __darwin_xmm_reg __fpu_xmm10;
  struct __darwin_xmm_reg __fpu_xmm11;
  struct __darwin_xmm_reg __fpu_xmm12;
  struct __darwin_xmm_reg __fpu_xmm13;
  struct __darwin_xmm_reg __fpu_xmm14;
  struct __darwin_xmm_reg __fpu_xmm15;
  char __fpu_rsrv4[6 * 16];
  int __fpu_reserved1;
};


struct __darwin_x86_avx_state64 {

  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;


  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;

  __uint16_t __fpu_rsrv2;


  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;

  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  struct __darwin_xmm_reg __fpu_xmm8;
  struct __darwin_xmm_reg __fpu_xmm9;
  struct __darwin_xmm_reg __fpu_xmm10;
  struct __darwin_xmm_reg __fpu_xmm11;
  struct __darwin_xmm_reg __fpu_xmm12;
  struct __darwin_xmm_reg __fpu_xmm13;
  struct __darwin_xmm_reg __fpu_xmm14;
  struct __darwin_xmm_reg __fpu_xmm15;
  char __fpu_rsrv4[6 * 16];
  int __fpu_reserved1;
  char __avx_reserved1[64];
  struct __darwin_xmm_reg __fpu_ymmh0;
  struct __darwin_xmm_reg __fpu_ymmh1;
  struct __darwin_xmm_reg __fpu_ymmh2;
  struct __darwin_xmm_reg __fpu_ymmh3;
  struct __darwin_xmm_reg __fpu_ymmh4;
  struct __darwin_xmm_reg __fpu_ymmh5;
  struct __darwin_xmm_reg __fpu_ymmh6;
  struct __darwin_xmm_reg __fpu_ymmh7;
  struct __darwin_xmm_reg __fpu_ymmh8;
  struct __darwin_xmm_reg __fpu_ymmh9;
  struct __darwin_xmm_reg __fpu_ymmh10;
  struct __darwin_xmm_reg __fpu_ymmh11;
  struct __darwin_xmm_reg __fpu_ymmh12;
  struct __darwin_xmm_reg __fpu_ymmh13;
  struct __darwin_xmm_reg __fpu_ymmh14;
  struct __darwin_xmm_reg __fpu_ymmh15;
};
#line 751
struct __darwin_x86_exception_state64 {

  __uint16_t __trapno;
  __uint16_t __cpu;
  __uint32_t __err;
  __uint64_t __faultvaddr;
};
#line 771
struct __darwin_x86_debug_state64 {

  __uint64_t __dr0;
  __uint64_t __dr1;
  __uint64_t __dr2;
  __uint64_t __dr3;
  __uint64_t __dr4;
  __uint64_t __dr5;
  __uint64_t __dr6;
  __uint64_t __dr7;
};
# 48 "/usr/include/i386/_structs.h" 3
struct __darwin_mcontext32 {

  struct __darwin_i386_exception_state __es;
  struct __darwin_i386_thread_state __ss;
  struct __darwin_i386_float_state __fs;
};


struct __darwin_mcontext_avx32 {

  struct __darwin_i386_exception_state __es;
  struct __darwin_i386_thread_state __ss;
  struct __darwin_i386_avx_state __fs;
};
#line 86
struct __darwin_mcontext64 {

  struct __darwin_x86_exception_state64 __es;
  struct __darwin_x86_thread_state64 __ss;
  struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext_avx64 {

  struct __darwin_x86_exception_state64 __es;
  struct __darwin_x86_thread_state64 __ss;
  struct __darwin_x86_avx_state64 __fs;
};
#line 127
typedef struct __darwin_mcontext64 *mcontext_t;
# 75 "/usr/include/sys/_structs.h" 3
struct __darwin_sigaltstack {

  void *ss_sp;
  __darwin_size_t ss_size;
  int ss_flags;
};
#line 128
struct __darwin_ucontext {

  int uc_onstack;
  __darwin_sigset_t uc_sigmask;
  struct __darwin_sigaltstack uc_stack;
  struct __darwin_ucontext *uc_link;
  __darwin_size_t uc_mcsize;
  struct __darwin_mcontext64 *uc_mcontext;
};
#line 218
typedef struct __darwin_sigaltstack stack_t;








typedef struct __darwin_ucontext ucontext_t;
# 157 "/usr/include/sys/signal.h" 3
typedef __darwin_pthread_attr_t pthread_attr_t;




typedef __darwin_sigset_t sigset_t;









typedef __darwin_uid_t uid_t;


union sigval {

  int sival_int;
  void *sival_ptr;
};





struct sigevent {
  int sigev_notify;
  int sigev_signo;
  union sigval sigev_value;
  void (*sigev_notify_function)(union sigval arg_0x1089ad8d0);
  pthread_attr_t *sigev_notify_attributes;
};
#line 205
#line 194
typedef struct __siginfo {
  int si_signo;
  int si_errno;
  int si_code;
  pid_t si_pid;
  uid_t si_uid;
  int si_status;
  void *si_addr;
  union sigval si_value;
  long si_band;
  unsigned long __pad[7];
} siginfo_t;
#line 286
union __sigaction_u {
  void (*__sa_handler)(int arg_0x1089b49f8);
  void (*__sa_sigaction)(int arg_0x1089b30c8, struct __siginfo *arg_0x1089b3428, 
  void *arg_0x1089b36e8);
};


struct __sigaction {
  union __sigaction_u __sigaction_u;
  void (*sa_tramp)(void *arg_0x1089b25e0, int arg_0x1089b2848, int arg_0x1089b2ab0, siginfo_t *arg_0x1089b2db0, void *arg_0x1089bc0c8);
  sigset_t sa_mask;
  int sa_flags;
};




struct sigaction {
  union __sigaction_u __sigaction_u;
  sigset_t sa_mask;
  int sa_flags;
};
#line 348
typedef void (*sig_t)(int arg_0x1089bbb40);
#line 365
struct sigvec {
  void (*sv_handler)(int arg_0x1089ba608);
  int sv_mask;
  int sv_flags;
};
#line 384
struct sigstack {
  char *ss_sp;
  int ss_onstack;
};
# 100 "/usr/include/sys/_structs.h" 3
struct timeval {

  __darwin_time_t tv_sec;
  __darwin_suseconds_t tv_usec;
};
# 89 "/usr/include/sys/resource.h" 3
typedef __uint64_t rlim_t;
#line 151
struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;








  long ru_maxrss;

  long ru_ixrss;
  long ru_idrss;
  long ru_isrss;
  long ru_minflt;
  long ru_majflt;
  long ru_nswap;
  long ru_inblock;
  long ru_oublock;
  long ru_msgsnd;
  long ru_msgrcv;
  long ru_nsignals;
  long ru_nvcsw;
  long ru_nivcsw;
};
#line 222
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};
# 201 "/usr/include/sys/wait.h" 3
union wait {
  int w_status;



  struct __nesc_unnamed4245 {

    unsigned int w_Termsig : 7, 
    w_Coredump : 1, 
    w_Retcode : 8, 
    w_Filler : 16;
  } 






  w_T;





  struct __nesc_unnamed4246 {

    unsigned int w_Stopval : 8, 
    w_Stopsig : 8, 
    w_Filler : 16;
  } 





  w_S;
};
# 81 "/usr/include/stdlib.h" 3
typedef __darwin_ct_rune_t ct_rune_t;




typedef __darwin_rune_t rune_t;
#line 100
#line 97
typedef struct __nesc_unnamed4247 {
  int quot;
  int rem;
} div_t;




#line 102
typedef struct __nesc_unnamed4248 {
  long quot;
  long rem;
} ldiv_t;





#line 108
typedef struct __nesc_unnamed4249 {
  long long quot;
  long long rem;
} lldiv_t;
#line 149
int atoi(const char *arg_0x1089ed878);









void exit(int arg_0x1089f2370) __attribute((noreturn)) ;
void free(void *arg_0x1089f2c28);








void *malloc(size_t arg_0x1089f95a8);
# 80 "/usr/include/i386/types.h" 3
typedef unsigned char u_int8_t;




typedef unsigned short u_int16_t;




typedef unsigned int u_int32_t;




typedef unsigned long long u_int64_t;


typedef int64_t register_t;
#line 114
typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
# 258 "/usr/include/stdlib.h" 3
typedef __darwin_dev_t dev_t;




typedef __darwin_mode_t mode_t;
# 67 "/opt/local/lib/gcc46/gcc/x86_64-apple-darwin12/4.6.4/include-fixed/math.h" 3
typedef float float_t;
typedef double double_t;
#line 395
extern double log(double arg_0x108abc408);
#line 439
extern double fabs(double arg_0x108ad1020);
#line 451
extern double pow(double arg_0x108ada580, double arg_0x108ada7e8);



extern double sqrt(double arg_0x108ad8370);







extern double erfc(double arg_0x108ae4590);
#line 482
extern double floor(double arg_0x108aec968);
#line 652
struct exception {
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};
# 70 "/usr/include/runetype.h" 3
typedef __darwin_wint_t wint_t;
#line 86
#line 81
typedef struct __nesc_unnamed4250 {
  __darwin_rune_t __min;
  __darwin_rune_t __max;
  __darwin_rune_t __map;
  __uint32_t *__types;
} _RuneEntry;




#line 88
typedef struct __nesc_unnamed4251 {
  int __nranges;
  _RuneEntry *__ranges;
} _RuneRange;




#line 93
typedef struct __nesc_unnamed4252 {
  char __name[14];
  __uint32_t __mask;
} _RuneCharClass;
#line 127
#line 98
typedef struct __nesc_unnamed4253 {
  char __magic[8];
  char __encoding[32];

  __darwin_rune_t (*__sgetrune)(const char *arg_0x108b33d10, __darwin_size_t arg_0x108b32060, char const **arg_0x108b32370);
  int (*__sputrune)(__darwin_rune_t arg_0x108b32a68, char *arg_0x108b32d08, __darwin_size_t arg_0x108b31060, char **arg_0x108b31338);
  __darwin_rune_t __invalid_rune;

  __uint32_t __runetype[1 << 8];
  __darwin_rune_t __maplower[1 << 8];
  __darwin_rune_t __mapupper[1 << 8];






  _RuneRange __runetype_ext;
  _RuneRange __maplower_ext;
  _RuneRange __mapupper_ext;

  void *__variable;
  int __variable_len;




  int __ncharclasses;
  _RuneCharClass *__charclasses;
} _RuneLocale;
# 73 "/usr/include/stdio.h" 3
typedef __darwin_va_list va_list;
#line 85
typedef __darwin_off_t fpos_t;










struct __sbuf {
  unsigned char *_base;
  int _size;
};


struct __sFILEX;
#line 161
#line 130
typedef struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;


  void *_cookie;
  int (*_close)(void *arg_0x108b700c8);
  int (*_read)(void *arg_0x108b70730, char *arg_0x108b709d0, int arg_0x108b70c38);
  fpos_t (*_seek)(void *arg_0x108b6e338, fpos_t arg_0x108b6e5e0, int arg_0x108b6e848);
  int (*_write)(void *arg_0x108b6d020, const char *arg_0x108b6d2f8, int arg_0x108b6d560);


  struct __sbuf _ub;
  struct __sFILEX *_extra;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  fpos_t _offset;
} FILE;
#line 240
int fclose(FILE *arg_0x108b796b8);


int fflush(FILE *arg_0x108b760c8);






FILE *fopen(const char *arg_0x108b85a20, const char *arg_0x108b85cf8) __asm ("_""fopen");

int fprintf(FILE *arg_0x108b84ad8, const char *arg_0x108b84db0, ...) __attribute((__format__(__printf__, 2, 3))) ;
#line 267
int printf(const char *arg_0x108b97338, ...) __attribute((__format__(__printf__, 1, 2))) ;
#line 282
int vfprintf(FILE *arg_0x108b9c910, const char *arg_0x108b9cbe8, va_list arg_0x108b9a020) __attribute((__format__(__printf__, 2, 0))) ;
#line 306
FILE *fdopen(int arg_0x108bae840, const char *arg_0x108baeb18) __asm ("_""fdopen");

int fileno(FILE *arg_0x108bad930);
#line 414
typedef __darwin_off_t off_t;
#line 449
ssize_t getline(char **arg_0x108bc73c0, size_t *arg_0x108bc76a0, FILE *arg_0x108bc7970) __attribute((visibility("default"))) ;
# 57 "/opt/tinyos-2.x/tos/lib/tossim/tos.h"
typedef uint8_t bool;










enum __nesc_unnamed4254 {
#line 68
  FALSE = 0, TRUE = 1
};
extern uint16_t TOS_NODE_ID;
# 43 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.h"
typedef long long int sim_time_t;

void sim_init();

void sim_end();

void sim_random_seed(int seed);
int sim_random();

sim_time_t sim_time();
void sim_set_time(sim_time_t time);
sim_time_t sim_ticks_per_sec();

unsigned long sim_node();
void sim_set_node(unsigned long node);

int sim_print_time(char *buf, int bufLen, sim_time_t time);
int sim_print_now(char *buf, int bufLen);
char *sim_time_string();

void sim_add_channel(char *channel, FILE *file);
bool sim_remove_channel(char *channel, FILE *file);


int sim_run_next_event();
# 42 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.h"
struct sim_event;
typedef struct sim_event sim_event_t;

struct sim_event {
  sim_time_t time;
  unsigned long mote;
  bool force;

  bool cancelled;
  void *data;

  void (*handle)(sim_event_t *e);
  void (*cleanup)(sim_event_t *e);
};

static sim_event_t *sim_queue_allocate_event();

void sim_queue_init();
void sim_queue_insert(sim_event_t *event);
bool sim_queue_is_empty();
long long int sim_queue_peek_time();
sim_event_t *sim_queue_pop();

void sim_queue_cleanup_none(sim_event_t *e);
void sim_queue_cleanup_event(sim_event_t *e);
void sim_queue_cleanup_data(sim_event_t *e);
void sim_queue_cleanup_total(sim_event_t *e);
# 46 "/opt/tinyos-2.x/tos/lib/tossim/sim_mote.h"
long long int sim_mote_euid(int mote);
void sim_mote_set_euid(int mote, long long int euid);
long long int sim_mote_start_time(int mote);
void sim_mote_set_start_time(int mote, long long int t);

bool sim_mote_is_on(int mote);
void sim_mote_turn_on(int mote);
void sim_mote_turn_off(int mote);
int sim_mote_get_variable_info(int mote, char *name, void **addr, size_t *len);
void sim_mote_enqueue_boot_event(int mote);

bool sim_mote_set_radio_channel(int mote, uint8_t newRadioChannel);
uint8_t sim_mote_get_radio_channel(int mote);




int *sim_mote_getTcpMsg(int mote);
void sim_mote_setTcpMsg(int mote, int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8);
# 57 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.h"
static inline void sim_log_init();
static inline void sim_log_add_channel(char *output, FILE *file);
static inline bool sim_log_remove_channel(char *output, FILE *file);
static void sim_log_commit_change();

static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
# 89 "/opt/tinyos-2.x/tos/lib/tossim/tos.h"
struct __nesc_attr_atmostonce {
};
#line 90
struct __nesc_attr_atleastonce {
};
#line 91
struct __nesc_attr_exactlyonce {
};
# 40 "/opt/local/lib/gcc46/gcc/x86_64-apple-darwin12/4.6.4/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 9 "/opt/tinyos-2.x/tos/lib/tossim/hashtable.h"
struct hashtable;
typedef struct hashtable hashtable_t;
#line 78
struct hashtable *
create_hashtable(unsigned int minsize, 
unsigned int (*hashfunction)(void *arg_0x108c1d760), 
int (*key_eq_fn)(void *arg_0x108c1c020, void *arg_0x108c1c2c0));
#line 103
#line 102
int 
hashtable_insert(struct hashtable *h, void *k, void *v);
#line 120
void *
hashtable_search(struct hashtable *h, void *k);
# 39 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
enum __nesc_unnamed4255 {
  DEFAULT_CHANNEL_SIZE = 8
};




#line 43
typedef struct sim_log_output {
  int num;
  FILE **files;
} sim_log_output_t;






#line 48
typedef struct sim_log_channel {
  const char *name;
  int numOutputs;
  int size;
  FILE **outputs;
} sim_log_channel_t;

enum __nesc_unnamed4256 {
  SIM_LOG_OUTPUT_COUNT = 175U
};

sim_log_output_t outputs[SIM_LOG_OUTPUT_COUNT];
struct hashtable *channelTable = (void *)0;


inline static unsigned int sim_log_hash(void *key);
inline static int sim_log_eq(void *key1, void *key2);
#line 76
static void fillInOutput(int id, char *name);
#line 151
static inline void sim_log_init();
#line 164
static inline void sim_log_add_channel(char *name, FILE *file);
#line 204
static inline bool sim_log_remove_channel(char *output, FILE *file);
#line 226
static void sim_log_commit_change();
#line 238
static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
#line 253
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
#line 268
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
#line 298
inline static unsigned int sim_log_hash(void *key);










inline static int sim_log_eq(void *key1, void *key2);
# 54 "/opt/tinyos-2.x/tos/lib/tossim/heap.h"
#line 50
typedef struct heap {
  int size;
  void *data;
  int private_size;
} heap_t;

static inline void init_heap(heap_t *heap);

static inline int heap_is_empty(heap_t *heap);

static inline long long int heap_get_min_key(heap_t *heap);

static void *heap_pop_min_data(heap_t *heap, long long int *key);
static inline void heap_insert(heap_t *heap, void *data, long long int key);
# 47 "/opt/tinyos-2.x/tos/lib/tossim/heap.c"
const int STARTING_SIZE = 511;






#line 51
typedef struct node {
  void *data;
  long long int key;
} node_t;

static void down_heap(heap_t *heap, int findex);
static void up_heap(heap_t *heap, int findex);
static void swap(node_t *first, node_t *second);








static inline void init_heap(heap_t *heap);









static inline int is_empty(heap_t *heap);



static inline int heap_is_empty(heap_t *heap);



static inline long long int heap_get_min_key(heap_t *heap);
#line 103
static void *heap_pop_min_data(heap_t *heap, long long int *key);
#line 119
static inline void expand_heap(heap_t *heap);
#line 133
static inline void heap_insert(heap_t *heap, void *data, long long int key);
#line 147
static void swap(node_t *first, node_t *second);
#line 160
static void down_heap(heap_t *heap, int findex);
#line 186
static void up_heap(heap_t *heap, int findex);
# 36 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.c"
static heap_t eventHeap;

void sim_queue_init()   ;



void sim_queue_insert(sim_event_t *event)   ;




sim_event_t *sim_queue_pop()   ;




bool sim_queue_is_empty()   ;



long long int sim_queue_peek_time()   ;









void sim_queue_cleanup_none(sim_event_t *event)   ;




void sim_queue_cleanup_event(sim_event_t *event)   ;




void sim_queue_cleanup_data(sim_event_t *event)   ;





void sim_queue_cleanup_total(sim_event_t *event)   ;






static sim_event_t *sim_queue_allocate_event();
# 88 "/usr/include/sys/_structs.h" 3
struct timespec {

  __darwin_time_t tv_sec;
  long tv_nsec;
};
#line 186
#line 184
typedef struct fd_set {
  __int32_t fds_bits[1024 % (sizeof(__int32_t ) * 8) == 0 ? 1024 / (sizeof(__int32_t ) * 8) : 1024 / (sizeof(__int32_t ) * 8) + 1];
} fd_set;
# 82 "/usr/include/sys/time.h" 3
typedef __darwin_time_t time_t;




typedef __darwin_suseconds_t suseconds_t;






struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};
#line 144
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
#line 187
struct clockinfo {
  int hz;
  int tick;
  int tickadj;
  int stathz;
  int profhz;
};
# 77 "/usr/include/time.h" 3
typedef __darwin_clock_t clock_t;
#line 90
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long tm_gmtoff;
  char *tm_zone;
};
#line 127
struct tm;
struct tm;
struct tm;
#line 142
struct tm;
struct tm;
# 211 "/usr/include/sys/time.h" 3
int gettimeofday(struct timeval *arg_0x108d2aca8, void *arg_0x108d29020);
# 43 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.h"
enum __nesc_unnamed4257 {
  NOISE_MIN = -115, 
  NOISE_MAX = -5, 
  NOISE_MIN_QUANTIZE = -115, 
  NOISE_QUANTIZE_INTERVAL = 5, 
  NOISE_BIN_SIZE = (NOISE_MAX - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1, 
  NOISE_HISTORY = 20, 
  NOISE_DEFAULT_ELEMENT_SIZE = 8, 
  NOISE_HASHTABLE_SIZE = 128, 
  NOISE_MIN_TRACE = 128, 
  NOISE_NUM_VALUES = NOISE_MAX - NOISE_MIN + 1
};








#line 56
typedef struct sim_noise_hash_t {
  char key[NOISE_HISTORY];
  int numElements;
  int size;
  char *elements;
  char flag;
  float dist[NOISE_NUM_VALUES];
} sim_noise_hash_t;
#line 75
#line 65
typedef struct sim_noise_node_t {
  char key[NOISE_HISTORY];
  char freqKey[NOISE_HISTORY];
  char lastNoiseVal;
  uint32_t noiseGenTime;
  struct hashtable *noiseTable;
  char *noiseTrace;
  uint32_t noiseTraceLen;
  uint32_t noiseTraceIndex;
  bool generated;
} sim_noise_node_t;

void sim_noise_init();

char sim_noise_generate(uint16_t node_id, uint32_t cur_t, uint8_t channel_id);
void sim_noise_trace_add(uint16_t node_id, char val, uint8_t channel_id);
void sim_noise_create_model(uint16_t node_id, uint8_t channel_id);
# 41 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.c"
static sim_time_t sim_ticks;
static unsigned long current_node;
static int sim_seed;

static int __nesc_nido_resolve(int mote, char *varname, uintptr_t *addr, size_t *size);

void sim_init()   ;
#line 70
void sim_end()   ;





int sim_random()   ;
#line 92
void sim_random_seed(int seed)   ;







sim_time_t sim_time()   ;


void sim_set_time(sim_time_t t)   ;



sim_time_t sim_ticks_per_sec()   ;



unsigned long sim_node()   ;


void sim_set_node(unsigned long node)   ;
#line 199
int sim_run_next_event()   ;
#line 265
int sim_print_time(char *buf, int len, sim_time_t ftime)   ;
#line 288
int sim_print_now(char *buf, int len)   ;



char simTimeBuf[128];
char *sim_time_string()   ;




void sim_add_channel(char *channel, FILE *file)   ;



bool sim_remove_channel(char *channel, FILE *file)   ;
# 91 "/opt/tinyos-2.x/tos/lib/tossim/sim_csma.h"
int sim_csma_init_high();
int sim_csma_init_low();
int sim_csma_high();
int sim_csma_low();
int sim_csma_symbols_per_sec();
int sim_csma_bits_per_symbol();
int sim_csma_preamble_length();
int sim_csma_exponent_base();
int sim_csma_max_iterations();
int sim_csma_min_free_samples();
int sim_csma_rxtx_delay();
int sim_csma_ack_time();

void sim_csma_set_init_high(int val);
void sim_csma_set_init_low(int val);
void sim_csma_set_high(int val);
void sim_csma_set_low(int val);
void sim_csma_set_symbols_per_sec(int val);
void sim_csma_set_bits_per_symbol(int val);
void sim_csma_set_preamble_length(int val);
void sim_csma_set_exponent_base(int val);
void sim_csma_set_max_iterations(int val);
void sim_csma_set_min_free_samples(int val);
void sim_csma_set_rxtx_delay(int val);
void sim_csma_set_ack_time(int val);
# 36 "/opt/tinyos-2.x/tos/lib/tossim/sim_csma.c"
int csmaInitHigh = 640;
int csmaInitLow = 20;
int csmaHigh = 160;
int csmaLow = 20;
int csmaSymbolsPerSec = 65536;
int csmaBitsPerSymbol = 4;
int csmaPreambleLength = 12;
int csmaExponentBase = 1;
int csmaMaxIterations = 0;
int csmaMinFreeSamples = 1;
int csmaRxTxDelay = 11;
int csmaAckTime = 34;

int sim_csma_init_high()   ;


int sim_csma_init_low()   ;


int sim_csma_high()   ;


int sim_csma_low()   ;


int sim_csma_symbols_per_sec()   ;


int sim_csma_bits_per_symbol()   ;


int sim_csma_preamble_length()   ;


int sim_csma_exponent_base()   ;


int sim_csma_max_iterations()   ;


int sim_csma_min_free_samples()   ;


int sim_csma_rxtx_delay()   ;


int sim_csma_ack_time()   ;





void sim_csma_set_init_high(int val)   ;


void sim_csma_set_init_low(int val)   ;


void sim_csma_set_high(int val)   ;


void sim_csma_set_low(int val)   ;


void sim_csma_set_symbols_per_sec(int val)   ;


void sim_csma_set_bits_per_symbol(int val)   ;


void sim_csma_set_preamble_length(int val)   ;


void sim_csma_set_exponent_base(int val)   ;


void sim_csma_set_max_iterations(int val)   ;


void sim_csma_set_min_free_samples(int val)   ;


void sim_csma_set_rxtx_delay(int val)   ;


void sim_csma_set_ack_time(int val)   ;
# 53 "/opt/tinyos-2.x/tos/lib/tossim/sim_gain.h"
#line 48
typedef struct gain_entry {
  int mote;
  double gain;
  int channel;
  struct gain_entry *next;
} gain_entry_t;

void sim_gain_add(int src, int dest, double gain, int channel_id);
double sim_gain_value(int src, int dest, int channel_id);

bool sim_gain_connected(int src, int dest, int channel_id);
void sim_gain_remove(int src, int dest, int channel_id);

void sim_gain_set_noise_floor(int node, double mean, double range, int channel_id);
double sim_gain_sample_noise(int node, int channel_id);



void sim_gain_set_sensitivity(double value);
double sim_gain_sensitivity();

gain_entry_t *sim_gain_first(int src, int channnel_id);
gain_entry_t *sim_gain_next(gain_entry_t *e);
# 6 "/opt/tinyos-2.x/tos/lib/tossim/sim_gain.c"
#line 3
typedef struct sim_gain_noise {
  double mean;
  double range;
} sim_gain_noise_t;

gain_entry_t *connectivity[1000 + 1][16];
sim_gain_noise_t localNoise[1000 + 1][16];

double sensitivity = 4.0;
static inline gain_entry_t *sim_gain_allocate_link(int mote, int channel_id);
void sim_gain_deallocate_link(gain_entry_t *linkToDelete);

gain_entry_t *sim_gain_first(int src, int channel_id)   ;









gain_entry_t *sim_gain_next(gain_entry_t *currentLink)   ;



void sim_gain_add(int src, int dest, double gain, int channel_id)   ;
#line 56
double sim_gain_value(int src, int dest, int channel_id)   ;
#line 75
bool sim_gain_connected(int src, int dest, int channel_id)   ;
#line 91
void sim_gain_remove(int src, int dest, int channel_id)   ;
#line 125
void sim_gain_set_noise_floor(int node, double mean, double range, int channel_id)   ;
#line 149
double sim_gain_sample_noise(int node, int channel_id)   ;
#line 162
static inline gain_entry_t *sim_gain_allocate_link(int mote, int channel_id);








void sim_gain_deallocate_link(gain_entry_t *linkToDelete)   ;



void sim_gain_set_sensitivity(double s)   ;



double sim_gain_sensitivity()   ;
# 39 "/opt/tinyos-2.x/tos/lib/tossim/randomlib.c"
static double randU[97];
#line 39
static double randC;
#line 39
static double randCD;
#line 39
static double randCM;
static int i97;
#line 40
static int j97;
static int test = FALSE;
#line 55
static inline void RandomInitialise(int ij, int kl);
#line 103
static double RandomUniform(void );
# 46 "/opt/tinyos-2.x/tos/lib/tossim/randomlib.h"
static inline void RandomInitialise(int arg_0x108e3e770, int arg_0x108e3e9d8);
static double RandomUniform(void );
# 50 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
int numCase1 = 0;
int numCase2 = 0;
int numTotal = 0;


uint32_t FreqKeyNum = 0;
sim_noise_node_t noiseData[1000][16];
inline static unsigned int sim_noise_hash(void *key);
inline static int sim_noise_eq(void *key1, void *key2);
void makeNoiseModel(uint16_t node_id, uint8_t channel_id);
void makePmfDistr(uint16_t node_id, uint8_t channel_id);
uint8_t search_bin_num(char noise);

void sim_noise_init()   ;
#line 79
void sim_noise_create_model(uint16_t node_id, uint8_t channel_id)   ;
#line 94
void sim_noise_trace_add(uint16_t node_id, char noiseVal, uint8_t channel_id)   ;
#line 108
uint8_t search_bin_num(char noise)   ;









char search_noise_from_bin_num(int i)   ;






inline static unsigned int sim_noise_hash(void *key);









inline static int sim_noise_eq(void *key1, void *key2);



void sim_noise_add(uint16_t node_id, char noise, uint8_t channel_id)   ;
#line 202
void sim_noise_dist(uint16_t node_id, uint8_t channel_id)   ;
#line 261
void arrangeKey(uint16_t node_id, uint8_t channel_id)   ;









void makePmfDistr(uint16_t node_id, uint8_t channel_id)   ;
#line 301
int dummy;
static inline void sim_noise_alarm();



char sim_noise_gen(uint16_t node_id, uint8_t channel_id)   ;
#line 403
char sim_noise_generate(uint16_t node_id, uint32_t cur_t, uint8_t channel_id)   ;
#line 488
void makeNoiseModel(uint16_t node_id, uint8_t channel_id)   ;
# 51 "/opt/tinyos-2.x/tos/lib/tossim/sim_packet.h"
typedef struct sim_packet {
} 
#line 51
sim_packet_t;

void sim_packet_set_source(sim_packet_t *msg, uint16_t src);
uint16_t sim_packet_source(sim_packet_t *msg);

void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest);
uint16_t sim_packet_destination(sim_packet_t *msg);

void sim_packet_set_length(sim_packet_t *msg, uint8_t len);
uint16_t sim_packet_length(sim_packet_t *msg);

void sim_packet_set_type(sim_packet_t *msg, uint8_t type);
uint8_t sim_packet_type(sim_packet_t *msg);

uint8_t *sim_packet_data(sim_packet_t *msg);
void sim_packet_set_strength(sim_packet_t *msg, uint16_t str);

void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t);
uint8_t sim_packet_max_length(sim_packet_t *msg);

sim_packet_t *sim_packet_allocate();
void sim_packet_free(sim_packet_t *m);

void sim_packet_set_dsn(sim_packet_t *msg, uint8_t dsn);
uint8_t sim_packet_dsn(sim_packet_t *msg);
# 6 "/opt/tinyos-2.x/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4258 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4259 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 13 "/opt/tinyos-2.x/tos/lib/tossim/TossimRadioMsg.h"
#line 6
typedef nx_struct tossim_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_uint8_t dsn;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) tossim_header_t;



#line 15
typedef nx_struct tossim_footer {
  nxle_uint16_t crc;
} __attribute__((packed)) tossim_footer_t;
#line 29
#line 19
typedef nx_struct tossim_metadata {
  nx_int8_t strength;
  nx_uint8_t lqi;
  nx_uint8_t ack;
  nx_uint16_t time;
  nx_uint8_t destroyable;
} __attribute__((packed)) 



tossim_metadata_t;
# 72 "/opt/tinyos-2.x/tos/lib/serial/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4260 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4261 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4262 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 110
#line 98
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 112
typedef nx_struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) serial_header_t;




#line 120
typedef nx_struct serial_packet {
  serial_header_t header;
  nx_uint8_t data[];
} __attribute__((packed)) serial_packet_t;



#line 125
typedef nx_struct serial_metadata {
  nx_uint8_t ack;
} __attribute__((packed)) serial_metadata_t;
# 44 "/opt/tinyos-2.x/tos/lib/tossim/platform_message.h"
#line 41
typedef union message_header {
  tossim_header_t tossim;
  serial_header_t serial;
} message_header_t;



#line 46
typedef union message_footer {
  tossim_footer_t tossim;
} message_footer_t;



#line 50
typedef union message_metadata {
  tossim_metadata_t tossim;
} message_metadata_t;
# 19 "/opt/tinyos-2.x/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[156];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) message_t;
# 40 "/opt/tinyos-2.x/tos/lib/tossim/sim_packet.c"
void active_message_deliver(int node, message_t *m, sim_time_t t);

inline static tossim_header_t *getHeader(message_t *msg);



void sim_packet_set_source(sim_packet_t *msg, uint16_t src)   ;




uint16_t sim_packet_source(sim_packet_t *msg)   ;




void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)   ;




uint16_t sim_packet_destination(sim_packet_t *msg)   ;




void sim_packet_set_length(sim_packet_t *msg, uint8_t length)   ;



uint16_t sim_packet_length(sim_packet_t *msg)   ;




void sim_packet_set_type(sim_packet_t *msg, uint8_t type)   ;




uint8_t sim_packet_type(sim_packet_t *msg)   ;




uint8_t *sim_packet_data(sim_packet_t *p)   ;



void sim_packet_set_strength(sim_packet_t *p, uint16_t str)   ;




void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)   ;







uint8_t sim_packet_max_length(sim_packet_t *msg)   ;



sim_packet_t *sim_packet_allocate()   ;



void sim_packet_free(sim_packet_t *p)   ;




void sim_packet_set_dsn(sim_packet_t *msg, uint8_t dsn)   ;




uint8_t sim_packet_dsn(sim_packet_t *msg)   ;
# 40 "/opt/tinyos-2.x/tos/types/TinyError.h"
enum __nesc_unnamed4263 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 5 "TestNetworkC.h"
enum __nesc_unnamed4264 {
  AM_TESTNETWORKMSG = 0x05, 
  AM_TESTNETWORKMSGG = 0x06, 
  SAMPLE_RATE_KEY = 0x1, 
  CL_TEST = 0xee, 
  TEST_NETWORK_QUEUE_SIZE = 8, 
  MAXPARENTS = 4, 
  MAXCHILDREN = 10, 
  MAXSIBLINGS = 10, 
  TOTALNODES = 19
};
# 47 "TestNetwork.h"
#line 7
typedef nx_struct TestNetworkMsg {
  nx_uint8_t source;


  nx_am_addr_t parents[MAXPARENTS];
  nx_uint8_t totalParents;

  nx_am_addr_t children[MAXCHILDREN];
  nx_uint8_t totalChildren;

  nx_am_addr_t siblings[MAXSIBLINGS];
  nx_uint8_t totalSiblings;
  nx_uint8_t i_am_primary;

  nx_uint8_t message_type;




  nx_uint8_t self_data1;
  nx_uint8_t self_data2;

  nx_uint8_t  merged_data[TOTALNODES];
  nx_uint8_t  merged_index[TOTALNODES];

  nx_uint8_t childrenReceive[MAXCHILDREN];
  nx_uint8_t childrenHandle[MAXCHILDREN];
  nx_uint8_t curr_num;



  nx_uint8_t avg_link_prob;





  nx_uint8_t hopcount;
  nx_uint16_t sendCount;
  nx_uint16_t sendSuccessCount;
} __attribute__((packed)) TestNetworkMsg;
# 29 "/opt/tinyos-2.x/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4265 {
#line 29
  int notUsed;
} 
#line 29
TMilli;
typedef struct __nesc_unnamed4266 {
#line 30
  int notUsed;
} 
#line 30
T32khz;
typedef struct __nesc_unnamed4267 {
#line 31
  int notUsed;
} 
#line 31
TMicro;
# 25 "/opt/tinyos-2.x/tos/chips/atm128/sim/atm128_sim.h"
enum __nesc_unnamed4268 {

  ATM128_PINF = 0x00, 


  ATM128_PINE = 0x01, 


  ATM128_DDRE = 0x02, 


  ATM128_PORTE = 0x03, 


  ATM128_ADCW = 0x04, 

  ATM128_ADC = 0x04, 

  ATM128_ADCL = 0x04, 
  ATM128_ADCH = 0x05, 


  ATM128_ADCSR = 0x06, 
  ATM128_ADCSRA = 0x06, 


  ATM128_ADMUX = 0x07, 


  ATM128_ACSR = 0x08, 


  ATM128_UBRR0L = 0x09, 


  ATM128_UCSR0B = 0x0A, 


  ATM128_UCSR0A = 0x0B, 


  ATM128_UDR0 = 0x0C, 


  ATM128_SPCR = 0x0D, 


  ATM128_SPSR = 0x0E, 


  ATM128_SPDR = 0x0F, 


  ATM128_PIND = 0x10, 


  ATM128_DDRD = 0x11, 


  ATM128_PORTD = 0x12, 


  ATM128_PINC = 0x13, 


  ATM128_DDRC = 0x14, 


  ATM128_PORTC = 0x15, 


  ATM128_PINB = 0x16, 


  ATM128_DDRB = 0x17, 


  ATM128_PORTB = 0x18, 


  ATM128_PINA = 0x19, 


  ATM128_DDRA = 0x1A, 


  ATM128_PORTA = 0x1B, 




  ATM128_SFIOR = 0x20, 


  ATM128_WDTCR = 0x21, 


  ATM128_OCDR = 0x22, 


  ATM128_OCR2 = 0x23, 


  ATM128_TCNT2 = 0x24, 


  ATM128_TCCR2 = 0x25, 


  ATM128_ICR1 = 0x26, 
  ATM128_ICR1L = 0x26, 
  ATM128_ICR1H = 0x27, 


  ATM128_OCR1B = 0x28, 
  ATM128_OCR1BL = 0x28, 
  ATM128_OCR1BH = 0x29, 


  ATM128_OCR1A = 0x2A, 
  ATM128_OCR1AL = 0x2A, 
  ATM128_OCR1AH = 0x2B, 


  ATM128_TCNT1 = 0x2C, 
  ATM128_TCNT1L = 0x2C, 
  ATM128_TCNT1H = 0x2D, 


  ATM128_TCCR1B = 0x2E, 


  ATM128_TCCR1A = 0x2F, 


  ATM128_ASSR = 0x30, 


  ATM128_OCR0 = 0x31, 


  ATM128_TCNT0 = 0x32, 


  ATM128_TCCR0 = 0x33, 


  ATM128_MCUSR = 0x34, 
  ATM128_MCUCSR = 0x34, 


  ATM128_MCUCR = 0x35, 


  ATM128_TIFR = 0x36, 


  ATM128_TIMSK = 0x37, 


  ATM128_EIFR = 0x38, 


  ATM128_EIMSK = 0x39, 


  ATM128_EICRB = 0x3A, 


  ATM128_RAMPZ = 0x3B, 


  ATM128_XDIV = 0x3C, 




  ATM128_SREG = 0x3F, 




  ATM128_DDRF = 0x61, 


  ATM128_PORTF = 0x62, 


  ATM128_PING = 0x63, 


  ATM128_DDRG = 0x64, 


  ATM128_PORTG = 0x65, 


  ATM128_SPMCR = 0x68, 
  ATM128_SPMCSR = 0x68, 


  ATM128_EICRA = 0x6A, 


  ATM128_XMCRB = 0x6C, 


  ATM128_XMCRA = 0x6D, 


  ATM128_OSCCAL = 0x6F, 


  ATM128_TWBR = 0x70, 


  ATM128_TWSR = 0x71, 


  ATM128_TWAR = 0x72, 


  ATM128_TWDR = 0x73, 


  ATM128_TWCR = 0x74, 


  ATM128_OCR1C = 0x78, 
  ATM128_OCR1CL = 0x78, 
  ATM128_OCR1CH = 0x79, 


  ATM128_TCCR1C = 0x7A, 


  ATM128_ETIFR = 0x7C, 


  ATM128_ETIMSK = 0x7D, 


  ATM128_ICR3 = 0x80, 
  ATM128_ICR3L = 0x80, 
  ATM128_ICR3H = 0x81, 


  ATM128_OCR3C = 0x82, 
  ATM128_OCR3CL = 0x82, 
  ATM128_OCR3CH = 0x83, 


  ATM128_OCR3B = 0x84, 
  ATM128_OCR3BL = 0x84, 
  ATM128_OCR3BH = 0x85, 


  ATM128_OCR3A = 0x86, 
  ATM128_OCR3AL = 0x86, 
  ATM128_OCR3AH = 0x87, 


  ATM128_TCNT3 = 0x88, 
  ATM128_TCNT3L = 0x88, 
  ATM128_TCNT3H = 0x89, 


  ATM128_TCCR3B = 0x8A, 


  ATM128_TCCR3A = 0x8B, 


  ATM128_TCCR3C = 0x8C, 


  ATM128_UBRR0H = 0x90, 


  ATM128_UCSR0C = 0x95, 


  ATM128_UBRR1H = 0x98, 


  ATM128_UBRR1L = 0x99, 


  ATM128_UCSR1B = 0x9A, 


  ATM128_UCSR1A = 0x9B, 


  ATM128_UDR1 = 0x9C, 


  ATM128_UCSR1C = 0x9D
};
#line 673
enum __nesc_unnamed4269 {

  TWINT = 7, 
  TWEA = 6, 
  TWSTA = 5, 
  TWSTO = 4, 
  TWWC = 3, 
  TWEN = 2, 
  TWIE = 0, 


  TWA6 = 7, 
  TWA5 = 6, 
  TWA4 = 5, 
  TWA3 = 4, 
  TWA2 = 3, 
  TWA1 = 2, 
  TWA0 = 1, 
  TWGCE = 0, 


  TWS7 = 7, 
  TWS6 = 6, 
  TWS5 = 5, 
  TWS4 = 4, 
  TWS3 = 3, 
  TWPS1 = 1, 
  TWPS0 = 0, 


  SRL2 = 6, 
  SRL1 = 5, 
  SRL0 = 4, 
  SRW01 = 3, 
  SRW00 = 2, 
  SRW11 = 1, 


  XMBK = 7, 
  XMM2 = 2, 
  XMM1 = 1, 
  XMM0 = 0, 


  XDIVEN = 7, 
  XDIV6 = 6, 
  XDIV5 = 5, 
  XDIV4 = 4, 
  XDIV3 = 3, 
  XDIV2 = 2, 
  XDIV1 = 1, 
  XDIV0 = 0, 


  RAMPZ0 = 0, 


  ISC31 = 7, 
  ISC30 = 6, 
  ISC21 = 5, 
  ISC20 = 4, 
  ISC11 = 3, 
  ISC10 = 2, 
  ISC01 = 1, 
  ISC00 = 0, 


  ISC71 = 7, 
  ISC70 = 6, 
  ISC61 = 5, 
  ISC60 = 4, 
  ISC51 = 3, 
  ISC50 = 2, 
  ISC41 = 1, 
  ISC40 = 0, 


  SPMIE = 7, 
  RWWSB = 6, 
  RWWSRE = 4, 
  BLBSET = 3, 
  PGWRT = 2, 
  PGERS = 1, 
  SPMEN = 0, 


  INT7 = 7, 
  INT6 = 6, 
  INT5 = 5, 
  INT4 = 4, 
  INT3 = 3, 
  INT2 = 2, 
  INT1 = 1, 
  INT0 = 0, 


  INTF7 = 7, 
  INTF6 = 6, 
  INTF5 = 5, 
  INTF4 = 4, 
  INTF3 = 3, 
  INTF2 = 2, 
  INTF1 = 1, 
  INTF0 = 0, 


  OCIE2 = 7, 
  TOIE2 = 6, 
  TICIE1 = 5, 
  OCIE1A = 4, 
  OCIE1B = 3, 
  TOIE1 = 2, 
  OCIE0 = 1, 
  TOIE0 = 0, 


  OCF2 = 7, 
  TOV2 = 6, 
  ICF1 = 5, 
  OCF1A = 4, 
  OCF1B = 3, 
  TOV1 = 2, 
  OCF0 = 1, 
  TOV0 = 0, 


  TICIE3 = 5, 
  OCIE3A = 4, 
  OCIE3B = 3, 
  TOIE3 = 2, 
  OCIE3C = 1, 
  OCIE1C = 0, 


  ICF3 = 5, 
  OCF3A = 4, 
  OCF3B = 3, 
  TOV3 = 2, 
  OCF3C = 1, 
  OCF1C = 0, 


  SRE = 7, 
  SRW = 6, 
  SRW10 = 6, 
  SE = 5, 
  SM1 = 4, 
  SM0 = 3, 
  SM2 = 2, 
  IVSEL = 1, 
  IVCE = 0, 


  JTD = 7, 
  JTRF = 4, 
  WDRF = 3, 
  BORF = 2, 
  EXTRF = 1, 
  PORF = 0, 


  FOC = 7, 
  WGM0 = 6, 
  COM1 = 5, 
  COM0 = 4, 
  WGM1 = 3, 
  CS2 = 2, 
  CS1 = 1, 
  CS0 = 0, 


  FOC0 = 7, 
  WGM00 = 6, 
  COM01 = 5, 
  COM00 = 4, 
  WGM01 = 3, 
  CS02 = 2, 
  CS01 = 1, 
  CS00 = 0, 


  FOC2 = 7, 
  WGM20 = 6, 
  COM21 = 5, 
  COM20 = 4, 
  WGM21 = 3, 
  CS22 = 2, 
  CS21 = 1, 
  CS20 = 0, 


  AS0 = 3, 
  TCN0UB = 2, 
  OCR0UB = 1, 
  TCR0UB = 0, 


  COMA1 = 7, 
  COMA0 = 6, 
  COMB1 = 5, 
  COMB0 = 4, 
  COMC1 = 3, 
  COMC0 = 2, 
  WGMA1 = 1, 
  WGMA0 = 0, 


  COM1A1 = 7, 
  COM1A0 = 6, 
  COM1B1 = 5, 
  COM1B0 = 4, 
  COM1C1 = 3, 
  COM1C0 = 2, 
  WGM11 = 1, 
  WGM10 = 0, 


  COM3A1 = 7, 
  COM3A0 = 6, 
  COM3B1 = 5, 
  COM3B0 = 4, 
  COM3C1 = 3, 
  COM3C0 = 2, 
  WGM31 = 1, 
  WGM30 = 0, 


  ICNC = 7, 
  ICES = 6, 
  WGMB3 = 4, 
  WGMB2 = 3, 
  CSB2 = 2, 
  CSB1 = 1, 
  CSB0 = 0, 


  ICNC1 = 7, 
  ICES1 = 6, 
  WGM13 = 4, 
  WGM12 = 3, 
  CS12 = 2, 
  CS11 = 1, 
  CS10 = 0, 


  ICNC3 = 7, 
  ICES3 = 6, 
  WGM33 = 4, 
  WGM32 = 3, 
  CS32 = 2, 
  CS31 = 1, 
  CS30 = 0, 


  FOCA = 7, 
  FOCB = 6, 
  FOCC = 5, 


  FOC3A = 7, 
  FOC3B = 6, 
  FOC3C = 5, 


  FOC1A = 7, 
  FOC1B = 6, 
  FOC1C = 5, 


  IDRD = 7, 
  OCDR7 = 7, 
  OCDR6 = 6, 
  OCDR5 = 5, 
  OCDR4 = 4, 
  OCDR3 = 3, 
  OCDR2 = 2, 
  OCDR1 = 1, 
  OCDR0 = 0, 


  WDCE = 4, 
  WDE = 3, 
  WDP2 = 2, 
  WDP1 = 1, 
  WDP0 = 0, 


  TSM = 7, 
  ADHSM = 4, 
  ACME = 3, 
  PUD = 2, 
  PSR0 = 1, 
  PSR321 = 0, 


  SPIF = 7, 
  WCOL = 6, 
  SPI2X = 0, 


  SPIE = 7, 
  SPE = 6, 
  DORD = 5, 
  MSTR = 4, 
  CPOL = 3, 
  CPHA = 2, 
  SPR1 = 1, 
  SPR0 = 0, 


  UMSEL = 6, 
  UPM1 = 5, 
  UPM0 = 4, 
  USBS = 3, 
  UCSZ1 = 2, 
  UCSZ0 = 1, 
  UCPOL = 0, 


  UMSEL1 = 6, 
  UPM11 = 5, 
  UPM10 = 4, 
  USBS1 = 3, 
  UCSZ11 = 2, 
  UCSZ10 = 1, 
  UCPOL1 = 0, 


  UMSEL0 = 6, 
  UPM01 = 5, 
  UPM00 = 4, 
  USBS0 = 3, 
  UCSZ01 = 2, 
  UCSZ00 = 1, 
  UCPOL0 = 0, 


  RXC = 7, 
  TXC = 6, 
  UDRE = 5, 
  FE = 4, 
  DOR = 3, 
  UPE = 2, 
  U2X = 1, 
  MPCM = 0, 


  RXC1 = 7, 
  TXC1 = 6, 
  UDRE1 = 5, 
  FE1 = 4, 
  DOR1 = 3, 
  UPE1 = 2, 
  U2X1 = 1, 
  MPCM1 = 0, 


  RXC0 = 7, 
  TXC0 = 6, 
  UDRE0 = 5, 
  FE0 = 4, 
  DOR0 = 3, 
  UPE0 = 2, 
  U2X0 = 1, 
  MPCM0 = 0, 


  RXCIE = 7, 
  TXCIE = 6, 
  UDRIE = 5, 
  RXEN = 4, 
  TXEN = 3, 
  UCSZ = 2, 
  UCSZ2 = 2, 
  RXB8 = 1, 
  TXB8 = 0, 


  RXCIE1 = 7, 
  TXCIE1 = 6, 
  UDRIE1 = 5, 
  RXEN1 = 4, 
  TXEN1 = 3, 
  UCSZ12 = 2, 
  RXB81 = 1, 
  TXB81 = 0, 


  RXCIE0 = 7, 
  TXCIE0 = 6, 
  UDRIE0 = 5, 
  RXEN0 = 4, 
  TXEN0 = 3, 
  UCSZ02 = 2, 
  RXB80 = 1, 
  TXB80 = 0, 


  ACD = 7, 
  ACBG = 6, 
  ACO = 5, 
  ACI = 4, 
  ACIE = 3, 
  ACIC = 2, 
  ACIS1 = 1, 
  ACIS0 = 0, 


  ADEN = 7, 
  ADSC = 6, 
  ADFR = 5, 
  ADIF = 4, 
  ADIE = 3, 
  ADPS2 = 2, 
  ADPS1 = 1, 
  ADPS0 = 0, 


  REFS1 = 7, 
  REFS0 = 6, 
  ADLAR = 5, 
  MUX4 = 4, 
  MUX3 = 3, 
  MUX2 = 2, 
  MUX1 = 1, 
  MUX0 = 0, 


  PA7 = 7, 
  PA6 = 6, 
  PA5 = 5, 
  PA4 = 4, 
  PA3 = 3, 
  PA2 = 2, 
  PA1 = 1, 
  PA0 = 0, 


  DDA7 = 7, 
  DDA6 = 6, 
  DDA5 = 5, 
  DDA4 = 4, 
  DDA3 = 3, 
  DDA2 = 2, 
  DDA1 = 1, 
  DDA0 = 0, 


  PINA7 = 7, 
  PINA6 = 6, 
  PINA5 = 5, 
  PINA4 = 4, 
  PINA3 = 3, 
  PINA2 = 2, 
  PINA1 = 1, 
  PINA0 = 0, 


  PB7 = 7, 
  PB6 = 6, 
  PB5 = 5, 
  PB4 = 4, 
  PB3 = 3, 
  PB2 = 2, 
  PB1 = 1, 
  PB0 = 0, 


  DDB7 = 7, 
  DDB6 = 6, 
  DDB5 = 5, 
  DDB4 = 4, 
  DDB3 = 3, 
  DDB2 = 2, 
  DDB1 = 1, 
  DDB0 = 0, 


  PINB7 = 7, 
  PINB6 = 6, 
  PINB5 = 5, 
  PINB4 = 4, 
  PINB3 = 3, 
  PINB2 = 2, 
  PINB1 = 1, 
  PINB0 = 0, 


  PC7 = 7, 
  PC6 = 6, 
  PC5 = 5, 
  PC4 = 4, 
  PC3 = 3, 
  PC2 = 2, 
  PC1 = 1, 
  PC0 = 0, 


  DDC7 = 7, 
  DDC6 = 6, 
  DDC5 = 5, 
  DDC4 = 4, 
  DDC3 = 3, 
  DDC2 = 2, 
  DDC1 = 1, 
  DDC0 = 0, 


  PINC7 = 7, 
  PINC6 = 6, 
  PINC5 = 5, 
  PINC4 = 4, 
  PINC3 = 3, 
  PINC2 = 2, 
  PINC1 = 1, 
  PINC0 = 0, 


  PD7 = 7, 
  PD6 = 6, 
  PD5 = 5, 
  PD4 = 4, 
  PD3 = 3, 
  PD2 = 2, 
  PD1 = 1, 
  PD0 = 0, 


  DDD7 = 7, 
  DDD6 = 6, 
  DDD5 = 5, 
  DDD4 = 4, 
  DDD3 = 3, 
  DDD2 = 2, 
  DDD1 = 1, 
  DDD0 = 0, 


  PIND7 = 7, 
  PIND6 = 6, 
  PIND5 = 5, 
  PIND4 = 4, 
  PIND3 = 3, 
  PIND2 = 2, 
  PIND1 = 1, 
  PIND0 = 0, 


  PE7 = 7, 
  PE6 = 6, 
  PE5 = 5, 
  PE4 = 4, 
  PE3 = 3, 
  PE2 = 2, 
  PE1 = 1, 
  PE0 = 0, 


  DDE7 = 7, 
  DDE6 = 6, 
  DDE5 = 5, 
  DDE4 = 4, 
  DDE3 = 3, 
  DDE2 = 2, 
  DDE1 = 1, 
  DDE0 = 0, 


  PINE7 = 7, 
  PINE6 = 6, 
  PINE5 = 5, 
  PINE4 = 4, 
  PINE3 = 3, 
  PINE2 = 2, 
  PINE1 = 1, 
  PINE0 = 0, 


  PF7 = 7, 
  PF6 = 6, 
  PF5 = 5, 
  PF4 = 4, 
  PF3 = 3, 
  PF2 = 2, 
  PF1 = 1, 
  PF0 = 0, 


  DDF7 = 7, 
  DDF6 = 6, 
  DDF5 = 5, 
  DDF4 = 4, 
  DDF3 = 3, 
  DDF2 = 2, 
  DDF1 = 1, 
  DDF0 = 0, 


  PINF7 = 7, 
  PINF6 = 6, 
  PINF5 = 5, 
  PINF4 = 4, 
  PINF3 = 3, 
  PINF2 = 2, 
  PINF1 = 1, 
  PINF0 = 0, 


  PG4 = 4, 
  PG3 = 3, 
  PG2 = 2, 
  PG1 = 1, 
  PG0 = 0, 


  DDG4 = 4, 
  DDG3 = 3, 
  DDG2 = 2, 
  DDG1 = 1, 
  DDG0 = 0, 


  PING4 = 4, 
  PING3 = 3, 
  PING2 = 2, 
  PING1 = 1, 
  PING0 = 0
};
# 45 "/opt/tinyos-2.x/tos/chips/atm128/sim/atm128hardware.h"
uint8_t atm128RegFile[1000][0xa0];
#line 79
static __inline void __nesc_enable_interrupt();



static __inline void __nesc_disable_interrupt();




typedef uint8_t __nesc_atomic_t;



#line 91
__inline __nesc_atomic_t 
__nesc_atomic_start(void )  ;








#line 100
__inline void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)  ;
#line 114
typedef uint8_t mcu_power_t  ;





enum __nesc_unnamed4270 {
  ATM128_POWER_IDLE = 0, 
  ATM128_POWER_ADC_NR = 1, 
  ATM128_POWER_EXT_STANDBY = 2, 
  ATM128_POWER_SAVE = 3, 
  ATM128_POWER_STANDBY = 4, 
  ATM128_POWER_DOWN = 5
};
# 34 "/opt/tinyos-2.x/tos/chips/atm128/adc/Atm128Adc.h"
enum __nesc_unnamed4271 {
  ATM128_ADC_VREF_OFF = 0, 
  ATM128_ADC_VREF_AVCC = 1, 
  ATM128_ADC_VREF_RSVD, 
  ATM128_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4272 {
  ATM128_ADC_RIGHT_ADJUST = 0, 
  ATM128_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4273 {
  ATM128_ADC_SNGL_ADC0 = 0, 
  ATM128_ADC_SNGL_ADC1, 
  ATM128_ADC_SNGL_ADC2, 
  ATM128_ADC_SNGL_ADC3, 
  ATM128_ADC_SNGL_ADC4, 
  ATM128_ADC_SNGL_ADC5, 
  ATM128_ADC_SNGL_ADC6, 
  ATM128_ADC_SNGL_ADC7, 
  ATM128_ADC_DIFF_ADC00_10x, 
  ATM128_ADC_DIFF_ADC10_10x, 
  ATM128_ADC_DIFF_ADC00_200x, 
  ATM128_ADC_DIFF_ADC10_200x, 
  ATM128_ADC_DIFF_ADC22_10x, 
  ATM128_ADC_DIFF_ADC32_10x, 
  ATM128_ADC_DIFF_ADC22_200x, 
  ATM128_ADC_DIFF_ADC32_200x, 
  ATM128_ADC_DIFF_ADC01_1x, 
  ATM128_ADC_DIFF_ADC11_1x, 
  ATM128_ADC_DIFF_ADC21_1x, 
  ATM128_ADC_DIFF_ADC31_1x, 
  ATM128_ADC_DIFF_ADC41_1x, 
  ATM128_ADC_DIFF_ADC51_1x, 
  ATM128_ADC_DIFF_ADC61_1x, 
  ATM128_ADC_DIFF_ADC71_1x, 
  ATM128_ADC_DIFF_ADC02_1x, 
  ATM128_ADC_DIFF_ADC12_1x, 
  ATM128_ADC_DIFF_ADC22_1x, 
  ATM128_ADC_DIFF_ADC32_1x, 
  ATM128_ADC_DIFF_ADC42_1x, 
  ATM128_ADC_DIFF_ADC52_1x, 
  ATM128_ADC_SNGL_1_23, 
  ATM128_ADC_SNGL_GND
};







#line 85
typedef struct __nesc_unnamed4274 {

  uint8_t mux : 5;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm128Admux_t;




enum __nesc_unnamed4275 {
  ATM128_ADC_PRESCALE_2 = 0, 
  ATM128_ADC_PRESCALE_2b, 
  ATM128_ADC_PRESCALE_4, 
  ATM128_ADC_PRESCALE_8, 
  ATM128_ADC_PRESCALE_16, 
  ATM128_ADC_PRESCALE_32, 
  ATM128_ADC_PRESCALE_64, 
  ATM128_ADC_PRESCALE_128, 



  ATM128_ADC_PRESCALE
};


enum __nesc_unnamed4276 {
  ATM128_ADC_ENABLE_OFF = 0, 
  ATM128_ADC_ENABLE_ON
};


enum __nesc_unnamed4277 {
  ATM128_ADC_START_CONVERSION_OFF = 0, 
  ATM128_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4278 {
  ATM128_ADC_FREE_RUNNING_OFF = 0, 
  ATM128_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4279 {
  ATM128_ADC_INT_FLAG_OFF = 0, 
  ATM128_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4280 {
  ATM128_ADC_INT_ENABLE_OFF = 0, 
  ATM128_ADC_INT_ENABLE_ON
};










#line 141
typedef struct __nesc_unnamed4281 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adfr : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm128Adcsra_t;

typedef uint8_t Atm128_ADCH_t;
typedef uint8_t Atm128_ADCL_t;
# 48 "/opt/tinyos-2.x/tos/platforms/micaz/sim/platform_hardware.h"
enum __nesc_unnamed4282 {
  CHANNEL_RSSI = ATM128_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM128_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM128_ADC_SNGL_ADC7, 
  CHANNEL_BANDGAP = 30, 
  CHANNEL_GND = 31, 

  ATM128_TIMER0_TICKSPPS = 32768
};
# 33 "/opt/tinyos-2.x/tos/lib/tossim/SimMainP.nc"
static void __nesc_nido_initialise(int node);
# 4 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcher.h"
enum __nesc_unnamed4283 {
  TDMA_SLOT = 0, 
  CSMA_SLOT = 1, 
  BEACON_SLOT = 2, 
  NO_SLOT = 0xff
};
# 32 "/opt/tinyos-2.x/tos/types/Leds.h"
enum __nesc_unnamed4284 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
enum __nesc_unnamed4285 {
  SIMPLE_TDMA_SYNC = 123
};
# 7 "/opt/tinyos-2.x/tos/lib/tossim/sim_lqi.h"
#line 4
typedef struct lqi_dist {
  uint8_t lqi;
  double cdf;
} lqi_dist_t;





#line 9
typedef struct snr_lqi {
  double snr;
  uint8_t numLqi;
  lqi_dist_t *lqi;
} snr_lqi_t;

lqi_dist_t snr24[8] = { { 108, 49.5481927711 }, { 102, 49.9397590361 }, { 103, 50.9036144578 }, { 101, 51.0542168675 }, { 106, 63.7951807229 }, { 107, 92.3192771084 }, { 104, 94.2168674699 }, { 105, 100.0 } };
lqi_dist_t snr25[10] = { { 98, 0.0320204931156 }, { 108, 48.9593339737 }, { 102, 49.1514569324 }, { 103, 49.8879282741 }, { 100, 49.9199487672 }, { 101, 49.9839897534 }, { 106, 64.3932116555 }, { 107, 93.5638808838 }, { 104, 95.58117195 }, { 105, 100.0 } };
lqi_dist_t snr26[8] = { { 108, 49.9569583931 }, { 102, 50.3586800574 }, { 103, 51.1047345768 }, { 101, 51.1334289813 }, { 106, 63.6441893831 }, { 107, 93.68723099 }, { 104, 95.4662840746 }, { 105, 100.0 } };
lqi_dist_t snr27[9] = { { 108, 51.0854243022 }, { 102, 51.2545813363 }, { 103, 51.7056667606 }, { 100, 51.7338595997 }, { 101, 51.7620524387 }, { 106, 64.223287285 }, { 107, 94.051310967 }, { 104, 96.1093882154 }, { 105, 100.0 } };
lqi_dist_t snr20[10] = { { 99, 0.0332667997339 }, { 108, 37.9906852961 }, { 102, 38.5562208916 }, { 103, 40.0864936793 }, { 100, 40.119760479 }, { 101, 40.252827678 }, { 106, 56.3872255489 }, { 107, 89.5542248836 }, { 104, 92.7811044578 }, { 105, 100.0 } };
lqi_dist_t snr21[9] = { { 108, 40.3826787513 }, { 102, 40.953340047 }, { 103, 41.9268210809 }, { 100, 42.061094327 }, { 101, 42.2289358845 }, { 106, 58.4424303458 }, { 107, 89.7616649883 }, { 104, 92.2457200403 }, { 105, 100.0 } };
lqi_dist_t snr22[9] = { { 108, 44.0018966335 }, { 102, 44.4760550024 }, { 103, 45.4243717402 }, { 100, 45.4717875771 }, { 101, 45.6377430062 }, { 106, 60.6685633001 }, { 107, 90.9198672357 }, { 104, 93.6699857752 }, { 105, 100.0 } };
lqi_dist_t snr23[9] = { { 108, 46.3674104826 }, { 102, 46.8085106383 }, { 103, 47.6647638817 }, { 100, 47.7166580176 }, { 101, 47.8204462896 }, { 106, 61.6761805916 }, { 107, 91.64504411 }, { 104, 93.8764919564 }, { 105, 100.0 } };
lqi_dist_t snr28[8] = { { 108, 51.1636636637 }, { 102, 51.4264264264 }, { 103, 51.9144144144 }, { 100, 52.027027027 }, { 106, 64.3393393393 }, { 107, 94.3318318318 }, { 104, 96.2837837838 }, { 105, 100.0 } };
lqi_dist_t snr29[8] = { { 108, 53.434225844 }, { 102, 53.7834691502 }, { 103, 54.4819557625 }, { 101, 54.5401629802 }, { 106, 65.9487776484 }, { 107, 94.3538998836 }, { 104, 95.983701979 }, { 105, 100.0 } };
lqi_dist_t snr0[25] = { { 82, 7.20720720721 }, { 63, 8.10810810811 }, { 64, 10.8108108108 }, { 66, 12.6126126126 }, { 69, 16.2162162162 }, { 68, 19.8198198198 }, { 83, 24.3243243243 }, { 80, 28.8288288288 }, { 81, 34.2342342342 }, { 86, 36.9369369369 }, { 87, 37.8378378378 }, { 84, 40.5405405405 }, { 85, 42.3423423423 }, { 77, 50.4504504505 }, { 76, 60.3603603604 }, { 75, 65.7657657658 }, { 74, 72.0720720721 }, { 73, 74.7747747748 }, { 72, 78.3783783784 }, { 71, 81.0810810811 }, { 70, 81.981981982 }, { 92, 82.8828828829 }, { 79, 90.990990991 }, { 78, 99.0990990991 }, { 52, 100.0 } };
lqi_dist_t snr3[45] = { { 62, 0.0711743772242 }, { 67, 0.391459074733 }, { 60, 0.462633451957 }, { 102, 0.569395017794 }, { 88, 5.62277580071 }, { 89, 10.3558718861 }, { 64, 10.5693950178 }, { 65, 10.7473309609 }, { 66, 10.9964412811 }, { 69, 11.5658362989 }, { 82, 17.0818505338 }, { 83, 22.8825622776 }, { 80, 27.7224199288 }, { 81, 32.4555160142 }, { 86, 37.9003558719 }, { 87, 42.9893238434 }, { 84, 47.9359430605 }, { 85, 53.4163701068 }, { 92, 56.6903914591 }, { 79, 60.7117437722 }, { 104, 60.7473309609 }, { 78, 64.9822064057 }, { 68, 65.6583629893 }, { 99, 66.4412811388 }, { 98, 67.0462633452 }, { 75, 70.0 }, { 74, 71.6370106762 }, { 73, 73.5231316726 }, { 72, 75.0177935943 }, { 71, 76.2989323843 }, { 70, 76.975088968 }, { 91, 80.462633452 }, { 90, 84.2348754448 }, { 100, 84.590747331 }, { 101, 84.6619217082 }, { 95, 86.1209964413 }, { 94, 88.3629893238 }, { 97, 89.3950177936 }, { 96, 90.8540925267 }, { 77, 94.590747331 }, { 59, 94.6263345196 }, { 76, 97.3309608541 }, { 61, 97.4021352313 }, { 93, 99.8932384342 }, { 63, 100.0 } };
lqi_dist_t snr2[42] = { { 67, 1.42984807864 }, { 60, 1.51921358356 }, { 68, 2.32350312779 }, { 88, 4.7363717605 }, { 89, 7.14924039321 }, { 64, 7.86416443253 }, { 65, 8.57908847185 }, { 66, 9.29401251117 }, { 69, 12.0643431635 }, { 82, 18.1411974978 }, { 83, 24.3967828418 }, { 80, 29.2225201072 }, { 81, 33.8695263628 }, { 93, 34.763181412 }, { 87, 38.1590705987 }, { 84, 43.4316353887 }, { 85, 48.436103664 }, { 86, 51.8319928508 }, { 97, 51.9213583557 }, { 96, 52.2788203753 }, { 77, 58.3556747096 }, { 76, 64.164432529 }, { 75, 67.7390527256 }, { 74, 72.3860589812 }, { 73, 75.6032171582 }, { 72, 78.4629133155 }, { 71, 81.8588025022 }, { 70, 83.6461126005 }, { 91, 84.8078641644 }, { 90, 86.6845397676 }, { 100, 86.7739052726 }, { 92, 88.2037533512 }, { 95, 88.5612153709 }, { 94, 88.7399463807 }, { 79, 93.3869526363 }, { 78, 98.927613941 }, { 59, 99.0169794459 }, { 98, 99.1063449508 }, { 56, 99.1957104558 }, { 61, 99.4638069705 }, { 62, 99.7319034853 }, { 63, 100.0 } };
lqi_dist_t snr5[46] = { { 67, 0.153468385513 }, { 102, 1.01289134438 }, { 88, 6.1387354205 }, { 89, 11.6942909761 }, { 64, 11.9091467158 }, { 65, 11.9398403929 }, { 66, 11.97053407 }, { 103, 12.5230202578 }, { 100, 14.4260282382 }, { 83, 18.3241252302 }, { 80, 20.9023941068 }, { 81, 23.6955187231 }, { 86, 28.2688766114 }, { 87, 32.9957028852 }, { 84, 36.4333947207 }, { 85, 40.730509515 }, { 101, 41.9582565991 }, { 63, 42.0196439533 }, { 79, 44.1375076734 }, { 106, 44.1682013505 }, { 82, 47.0841006753 }, { 104, 47.3910374463 }, { 96, 51.6574585635 }, { 68, 51.9950890117 }, { 78, 53.8060159607 }, { 99, 56.0773480663 }, { 98, 59.4536525476 }, { 75, 60.8041743401 }, { 74, 61.4487415592 }, { 73, 61.97053407 }, { 72, 62.6764886433 }, { 71, 63.2903621854 }, { 70, 63.5972989564 }, { 91, 68.9993861265 }, { 90, 74.6777163904 }, { 93, 79.8956414979 }, { 92, 85.8809085328 }, { 95, 90.0859422959 }, { 94, 94.2909760589 }, { 97, 97.6672805402 }, { 105, 97.7593615715 }, { 77, 98.9257213014 }, { 76, 99.7851442603 }, { 56, 99.8158379374 }, { 61, 99.8465316145 }, { 69, 100.0 } };
lqi_dist_t snr7[45] = { { 67, 0.0192012288786 }, { 102, 5.04992319508 }, { 88, 8.25652841782 }, { 89, 12.1927803379 }, { 64, 12.2119815668 }, { 65, 12.2311827957 }, { 66, 12.2503840246 }, { 103, 16.9162826421 }, { 100, 22.1966205837 }, { 83, 24.3855606759 }, { 80, 25.5184331797 }, { 81, 27.1505376344 }, { 86, 30.222734255 }, { 87, 33.2373271889 }, { 84, 35.4070660522 }, { 85, 37.6920122888 }, { 101, 43.1643625192 }, { 63, 43.1835637481 }, { 79, 44.2396313364 }, { 106, 44.8732718894 }, { 82, 46.1789554531 }, { 107, 46.2749615975 }, { 104, 49.5007680492 }, { 105, 51.3248847926 }, { 78, 52.380952381 }, { 99, 57.2196620584 }, { 98, 62.1543778802 }, { 75, 62.5 }, { 74, 62.7112135177 }, { 73, 62.9992319508 }, { 72, 63.2680491551 }, { 71, 63.3448540707 }, { 70, 63.4792626728 }, { 91, 67.7995391705 }, { 90, 72.1006144393 }, { 93, 76.3056835637 }, { 92, 80.2995391705 }, { 95, 84.8502304147 }, { 94, 89.1321044547 }, { 97, 93.9132104455 }, { 96, 98.732718894 }, { 77, 99.366359447 }, { 59, 99.3855606759 }, { 76, 99.9615975422 }, { 69, 100.0 } };
lqi_dist_t snr6[45] = { { 67, 0.128238009746 }, { 102, 3.35983585535 }, { 88, 6.82226211849 }, { 89, 10.0538599641 }, { 64, 10.1820979738 }, { 65, 10.3103359836 }, { 66, 10.4642215953 }, { 103, 12.8238009746 }, { 82, 15.1064375481 }, { 83, 17.5173121313 }, { 80, 19.4152346756 }, { 81, 21.9286996666 }, { 86, 24.4934598615 }, { 93, 28.5714285714 }, { 84, 30.7771223391 }, { 85, 33.7778917671 }, { 101, 37.4967940498 }, { 79, 39.2151833804 }, { 95, 44.3959989741 }, { 87, 46.8325211593 }, { 104, 47.986663247 }, { 105, 48.473967684 }, { 68, 48.6535008977 }, { 78, 50.2436522185 }, { 99, 55.5270582201 }, { 98, 60.2462169787 }, { 75, 61.2977686586 }, { 74, 62.144139523 }, { 73, 62.9905103873 }, { 72, 63.8112336497 }, { 71, 64.2472428828 }, { 70, 64.4780713003 }, { 91, 68.0430879713 }, { 90, 71.5055142344 }, { 100, 76.6093870223 }, { 92, 80.3795845088 }, { 106, 80.4821749166 }, { 94, 85.4321620928 }, { 97, 91.5106437548 }, { 96, 96.9222877661 }, { 77, 98.2816106694 }, { 76, 99.6665811747 }, { 61, 99.7178763786 }, { 62, 99.7435239805 }, { 69, 100.0 } };
lqi_dist_t snr8[34] = { { 102, 6.99633699634 }, { 88, 9.06593406593 }, { 89, 11.0073260073 }, { 103, 17.9304029304 }, { 82, 18.2783882784 }, { 83, 18.7912087912 }, { 80, 19.0476190476 }, { 81, 19.2857142857 }, { 86, 20.3663003663 }, { 87, 22.0146520147 }, { 84, 22.7106227106 }, { 85, 23.6813186813 }, { 101, 31.0805860806 }, { 79, 31.1721611722 }, { 106, 33.0769230769 }, { 107, 33.2967032967 }, { 104, 39.1941391941 }, { 105, 43.3882783883 }, { 78, 43.4615384615 }, { 100, 50.293040293 }, { 99, 57.2527472527 }, { 98, 64.0842490842 }, { 75, 64.1208791209 }, { 74, 64.1391941392 }, { 91, 67.3626373626 }, { 90, 70.4761904762 }, { 93, 74.4505494505 }, { 92, 77.9120879121 }, { 95, 83.4249084249 }, { 94, 88.3882783883 }, { 97, 94.1025641026 }, { 96, 99.8901098901 }, { 77, 99.9816849817 }, { 76, 100.0 } };
lqi_dist_t snr11[20] = { { 91, 0.0598444045482 }, { 92, 0.179533213645 }, { 108, 0.239377618193 }, { 95, 0.957510472771 }, { 93, 1.25673249551 }, { 94, 1.7354877319 }, { 99, 6.40335128665 }, { 98, 8.73728306403 }, { 96, 9.99401555955 }, { 97, 11.6696588869 }, { 88, 11.7295032914 }, { 90, 11.7594254937 }, { 102, 24.7755834829 }, { 103, 40.9634949132 }, { 100, 47.0676241771 }, { 101, 55.5954518253 }, { 106, 65.4398563734 }, { 107, 67.9533213645 }, { 104, 84.5302214243 }, { 105, 100.0 } };
lqi_dist_t snr10[26] = { { 102, 10.8441850022 }, { 88, 11.2258643916 }, { 89, 11.5401885945 }, { 103, 23.3497979344 }, { 100, 32.8244274809 }, { 83, 32.8693309385 }, { 86, 32.9591378536 }, { 87, 33.2734620566 }, { 84, 33.3857207005 }, { 85, 33.4979793444 }, { 101, 43.578805568 }, { 79, 43.6012572968 }, { 106, 47.4854063763 }, { 107, 48.1814099686 }, { 104, 57.7009429726 }, { 105, 65.626403233 }, { 99, 74.5172878312 }, { 98, 81.2079030085 }, { 91, 81.9712617872 }, { 90, 82.5774584643 }, { 93, 84.1041760216 }, { 92, 85.4737314773 }, { 95, 88.6394252357 }, { 94, 90.7498877414 }, { 97, 96.273013022 }, { 96, 100.0 } };
lqi_dist_t snr13[13] = { { 96, 0.0612745098039 }, { 99, 0.816993464052 }, { 98, 1.14379084967 }, { 108, 2.51225490196 }, { 97, 2.61437908497 }, { 102, 7.96568627451 }, { 103, 16.5645424837 }, { 100, 17.7696078431 }, { 101, 20.1593137255 }, { 106, 45.5882352941 }, { 107, 63.8684640523 }, { 104, 78.8807189542 }, { 105, 100.0 } };
lqi_dist_t snr12[16] = { { 108, 0.241911097672 }, { 95, 0.423344420925 }, { 93, 0.483822195343 }, { 94, 0.514061082552 }, { 99, 1.96552766858 }, { 98, 2.6912609616 }, { 96, 2.81221651043 }, { 97, 3.26579981857 }, { 102, 10.9767160568 }, { 103, 23.4351375869 }, { 100, 26.0659207741 }, { 101, 30.9948593892 }, { 106, 51.1944360448 }, { 107, 60.5080133051 }, { 104, 78.7420622921 }, { 105, 100.0 } };
lqi_dist_t snr15[11] = { { 99, 0.064116264159 }, { 98, 0.085488352212 }, { 108, 6.79632400085 }, { 102, 8.20688181235 }, { 103, 11.8615088694 }, { 100, 12.2462064544 }, { 101, 12.9728574482 }, { 106, 39.0468048728 }, { 107, 75.1870057705 }, { 104, 83.1160504381 }, { 105, 100.0 } };
lqi_dist_t snr14[14] = { { 96, 0.0368935620734 }, { 93, 0.0553403431101 }, { 99, 0.239808153477 }, { 98, 0.442722744881 }, { 108, 3.37576092972 }, { 97, 3.41265449179 }, { 102, 6.32724589559 }, { 103, 12.543811105 }, { 100, 13.3185759085 }, { 101, 14.7389780483 }, { 106, 41.8926397344 }, { 107, 69.9501936912 }, { 104, 81.0367090943 }, { 105, 100.0 } };
lqi_dist_t snr17[11] = { { 99, 0.0569962952408 }, { 98, 0.071245369051 }, { 108, 24.5654032488 }, { 102, 25.2208606441 }, { 103, 27.0732402394 }, { 100, 27.2014819037 }, { 101, 27.6004559704 }, { 106, 47.976631519 }, { 107, 87.1900826446 }, { 104, 91.1655742377 }, { 105, 100.0 } };
lqi_dist_t snr16[11] = { { 99, 0.0779271381259 }, { 98, 0.116890707189 }, { 108, 15.0983830119 }, { 102, 16.0335086694 }, { 103, 18.9362945646 }, { 100, 19.0726670563 }, { 101, 19.4038573933 }, { 106, 41.3987921294 }, { 107, 81.9793493084 }, { 104, 87.6680303916 }, { 105, 100.0 } };
lqi_dist_t snr19[10] = { { 99, 0.0210039907582 }, { 108, 35.1816845201 }, { 102, 35.622768326 }, { 103, 37.0930476791 }, { 100, 37.1560596513 }, { 101, 37.3871035497 }, { 106, 53.8542323041 }, { 107, 88.615837009 }, { 104, 91.8504515858 }, { 105, 100.0 } };
lqi_dist_t snr18[11] = { { 99, 0.0137080191912 }, { 98, 0.0274160383825 }, { 108, 30.4043865661 }, { 102, 31.1583276217 }, { 103, 32.7484578478 }, { 100, 32.8169979438 }, { 101, 32.9403701165 }, { 106, 50.6374228924 }, { 107, 88.2933516107 }, { 104, 91.8026045236 }, { 105, 100.0 } };
lqi_dist_t snr31[3] = { { 108, 52.9411764706 }, { 106, 70.5882352941 }, { 107, 100.0 } };
lqi_dist_t snr30[7] = { { 108, 55.9880239521 }, { 103, 56.4371257485 }, { 101, 56.5868263473 }, { 106, 69.6107784431 }, { 107, 94.4610778443 }, { 104, 96.2574850299 }, { 105, 100.0 } };

snr_lqi_t allSnr[29] = { { 24, 8, snr24 }, { 25, 10, snr25 }, { 26, 8, snr26 }, { 27, 9, snr27 }, { 20, 10, snr20 }, { 21, 9, snr21 }, { 22, 9, snr22 }, { 23, 9, snr23 }, { 28, 8, snr28 }, { 29, 8, snr29 }, { 0, 25, snr0 }, { 3, 45, snr3 }, { 2, 42, snr2 }, { 5, 46, snr5 }, { 7, 45, snr7 }, { 6, 45, snr6 }, { 8, 34, snr8 }, { 11, 20, snr11 }, { 10, 26, snr10 }, { 13, 13, snr13 }, { 12, 16, snr12 }, { 15, 11, snr15 }, { 14, 14, snr14 }, { 17, 11, snr17 }, { 16, 11, snr16 }, { 19, 10, snr19 }, { 18, 11, snr18 }, { 31, 3, snr31 }, { 30, 7, snr30 } };
uint8_t allSnr_len = 29;
# 5 "/opt/tinyos-2.x/tos/lib/tossim/sim_lqi.c"
static uint8_t bi_search(lqi_dist_t *lqi, uint8_t low_i, uint8_t high_i, uint8_t coin);
#line 19
uint8_t sim_lqi_generate(double SNR)   ;
# 138 "/usr/include/sys/unistd.h" 3
struct accessx_descriptor {
  unsigned int ad_name_offset;
  int ad_flags;
  int ad_pad[2];
};
# 77 "/usr/include/unistd.h" 3
typedef __darwin_gid_t gid_t;
#line 114
typedef __darwin_useconds_t useconds_t;
#line 676
typedef __darwin_uuid_t uuid_t;
#line 763
struct fssearchblock;
struct searchstate;
typedef T32khz TestNetworkC__Alarm__precision_tag;
typedef uint32_t TestNetworkC__Alarm__size_type;
typedef T32khz /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__precision_tag;
typedef uint16_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__size_type;
typedef TMicro /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__precision_tag;
typedef uint16_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__size_type;
typedef TMicro /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__precision_tag;
typedef uint16_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__size_type;
typedef TMicro CounterMicro16P__Counter__precision_tag;
typedef uint16_t CounterMicro16P__Counter__size_type;
typedef T32khz /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_precision_tag;
typedef uint16_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type;
typedef TMicro /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_precision_tag;
typedef uint16_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_size_type;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_precision_tag /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__precision_tag;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__size_type;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_precision_tag /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__precision_tag;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__size_type;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_precision_tag /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__precision_tag;
typedef /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__size_type;
typedef T32khz /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_precision_tag;
typedef uint16_t /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type;
typedef TMicro /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_precision_tag;
typedef uint16_t /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_size_type;
typedef uint8_t /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__upper_count_type;
typedef /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_precision_tag /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__precision_tag;
typedef /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__size_type;
typedef /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_precision_tag /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__precision_tag;
typedef /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__size_type;
typedef T32khz GenericSlotterP__Alarm__precision_tag;
typedef uint32_t GenericSlotterP__Alarm__size_type;
typedef TMicro /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__precision_tag;
typedef uint16_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__size_type;
typedef TMicro /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__precision_tag;
typedef uint16_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__size_type;
typedef T32khz /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_precision_tag;
typedef uint32_t /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type;
typedef TMicro /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_precision_tag;
typedef uint16_t /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_size_type;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_precision_tag /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__precision_tag;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__size_type;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_precision_tag /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__precision_tag;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__size_type;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_precision_tag /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__precision_tag;
typedef /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__size_type;
typedef T32khz /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_precision_tag;
typedef uint32_t /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type;
typedef TMicro /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_precision_tag;
typedef uint16_t /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_size_type;
typedef uint16_t /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__upper_count_type;
typedef /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_precision_tag /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__precision_tag;
typedef /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__size_type;
typedef /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_precision_tag /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__precision_tag;
typedef /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__size_type;
typedef T32khz BeaconSlotP__SyncAlarm__precision_tag;
typedef uint32_t BeaconSlotP__SyncAlarm__size_type;
typedef TMicro /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__precision_tag;
typedef uint16_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__size_type;
typedef TMicro /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__precision_tag;
typedef uint16_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__size_type;
typedef T32khz /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_precision_tag;
typedef uint32_t /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type;
typedef TMicro /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_precision_tag;
typedef uint16_t /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_size_type;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_precision_tag /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__precision_tag;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__size_type;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_precision_tag /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__precision_tag;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__size_type;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_precision_tag /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__precision_tag;
typedef /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__size_type;
typedef uint16_t CpmModelC__ReadRssi__val_t;
enum AMQueueP____nesc_unnamed4286 {
  AMQueueP__NUM_CLIENTS = 1U
};
typedef TMicro /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__precision_tag;
typedef uint16_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__size_type;
typedef TMicro /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__precision_tag;
typedef uint16_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__size_type;
typedef T32khz /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_precision_tag;
typedef uint32_t /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_size_type;
typedef TMicro /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__from_precision_tag;
typedef uint16_t /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__from_size_type;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_precision_tag /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__precision_tag;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_size_type /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__size_type;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__from_precision_tag /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__AlarmFrom__precision_tag;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__from_size_type /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__AlarmFrom__size_type;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_precision_tag /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__precision_tag;
typedef /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_size_type /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__size_type;
typedef T32khz /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Alarm__precision_tag;
typedef uint32_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Alarm__size_type;
typedef TMicro /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Alarm__precision_tag;
typedef uint16_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Alarm__size_type;
typedef TMicro /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__precision_tag;
typedef uint16_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__size_type;
typedef T32khz /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_precision_tag;
typedef uint32_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_size_type;
typedef TMicro /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__from_precision_tag;
typedef uint16_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__from_size_type;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_precision_tag /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Alarm__precision_tag;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_size_type /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Alarm__size_type;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__from_precision_tag /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__AlarmFrom__precision_tag;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__from_size_type /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__AlarmFrom__size_type;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_precision_tag /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__precision_tag;
typedef /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_size_type /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__size_type;
typedef uint16_t RandomMlcgC__SeedInit__parameter;
# 53 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void TestNetworkC__CC2420Config__syncDone(error_t error);
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void TestNetworkC__Boot__booted(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



TestNetworkC__AMReceive__receive(
#line 60
message_t * msg, 
void * payload, 





uint8_t len);
# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void TestNetworkC__RadioControl__startDone(error_t error);
#line 117
static void TestNetworkC__RadioControl__stopDone(error_t error);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void TestNetworkC__Send__sendDone(
#line 92
message_t * msg, 






error_t error);
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void TestNetworkC__Alarm__fired(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



TestNetworkC__Receive__receive(
#line 60
message_t * msg, 
void * payload, 





uint8_t len);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__Init__init(void );
#line 51
static error_t MotePlatformP__PlatformInit__init(void );
# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void );
#line 29
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__set(void );





static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void );
#line 29
static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__set(void );





static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void );
#line 29
static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__set(void );



static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__makeInput(void );
#line 30
static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__clr(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t MeasureClockC__Init__init(void );
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SimSchedulerBasicP__TaskBasic__postTask(
# 41 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x108f83960);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP__TaskBasic__default__runTask(
# 41 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x108f83960);
# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void SimSchedulerBasicP__Scheduler__init(void );







static bool SimSchedulerBasicP__Scheduler__runNextTask(void );
# 36 "/opt/tinyos-2.x/tos/lib/tossim/SimMote.nc"
static void SimMoteP__SimMote__setEuid(long long int euid);


static int SimMoteP__SimMote__getVariableInfo(char *name, void **ptr, size_t *len);

static void SimMoteP__SimMote__turnOff(void );
#line 40
static void SimMoteP__SimMote__turnOn(void );
#line 35
static long long int SimMoteP__SimMote__getEuid(void );
#line 47
static int *SimMoteP__SimMote__getTcpMsg(void );
#line 43
static error_t SimMoteP__SimMote__setRadioChannel(uint8_t newRadioChannel);




static void SimMoteP__SimMote__setTcpMsg(int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8);
#line 38
static bool SimMoteP__SimMote__isOn(void );





static uint8_t SimMoteP__SimMote__getRadioChannel(void );
#line 37
static long long int SimMoteP__SimMote__getStartTime(void );
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void AsyncReceiveAdapterP__receiveDone_task__runTask(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



AsyncReceiveAdapterP__Receive__default__receive(
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
am_id_t arg_0x109375020, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void AsyncReceiveAdapterP__AsyncReceive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t AsyncSendAdapterP__AMSend__send(
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
am_id_t arg_0x109376c00, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 60
message_t * msg, 








uint8_t len);
#line 124
static 
#line 122
void * 

AsyncSendAdapterP__AMSend__getPayload(
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
am_id_t arg_0x109376c00, 
# 121 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void AsyncSendAdapterP__AsyncSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void AsyncSendAdapterP__sendDone_task__runTask(void );
# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t PureTDMASchedulerP__SplitControl__start(void );
# 32 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/Slotter.nc"
static void PureTDMASchedulerP__Slotter__slot(uint32_t num);
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void PureTDMASchedulerP__SubSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void PureTDMASchedulerP__SubReceive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 53 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void PureTDMASchedulerP__CC2420Config__syncDone(error_t error);
# 36 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
static void PureTDMASchedulerP__RadioPowerControl__startDone(error_t error);





static void PureTDMASchedulerP__RadioPowerControl__stopDone(error_t error);
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t PureTDMASchedulerP__Send__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

PureTDMASchedulerP__Send__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PureTDMASchedulerP__Init__init(void );
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void PureTDMASchedulerP__BeaconSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void PureTDMASchedulerP__Receive__updateBuffer(
#line 49
message_t * msg);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t LedsP__Init__init(void );
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Boot__booted(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__fired(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Init__init(void );
# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__size_type dt);
#line 77
static bool /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__isRunning(void );
#line 62
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__stop(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Init__init(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__overflow(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t CounterMicro16P__Init__init(void );
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static CounterMicro16P__Counter__size_type CounterMicro16P__Counter__get(void );






static bool CounterMicro16P__Counter__isOverflowPending(void );
# 98 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__getNow(void );
#line 92
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__size_type dt);
#line 55
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__start(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__size_type dt);
#line 67
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__fired(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__overflow(void );
#line 71
static void /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__overflow(void );
#line 53
static /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__get(void );
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void GenericSlotterP__Boot__booted(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void GenericSlotterP__Alarm__fired(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t GenericSlotterP__Init__init(void );
# 74 "/opt/tinyos-2.x/tos/interfaces/AsyncStdControl.nc"
static error_t GenericSlotterP__AsyncStdControl__start(void );
# 38 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/FrameConfiguration.nc"
static void GenericSlotterP__FrameConfiguration__setFrameLength(uint32_t numSlots);
#line 32
static void GenericSlotterP__FrameConfiguration__setSlotLength(uint32_t slotTimeBms);
# 39 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
static uint32_t GenericSlotterP__SlotterControl__getSlot(void );
#line 31
static error_t GenericSlotterP__SlotterControl__synchronize(uint8_t toSlot);




static uint32_t GenericSlotterP__SlotterControl__getRemaining(void );
static void GenericSlotterP__SlotterControl__stop(void );
# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__startAt(/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__size_type t0, /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__size_type dt);
#line 77
static bool /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__isRunning(void );
#line 62
static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__stop(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Init__init(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__overflow(void );
# 98 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__getNow(void );
#line 92
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__size_type t0, /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__size_type dt);
#line 55
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__start(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__size_type dt);






static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__stop(void );




static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__fired(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__overflow(void );
#line 71
static void /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__overflow(void );
#line 53
static /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__get(void );
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void SenderDispatcherP__SubSend__sendDone(
#line 44
message_t * msg, 



error_t error);
#line 40
static error_t SenderDispatcherP__Send__send(
# 39 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
uint8_t arg_0x10975a6d8, 
# 34 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

SenderDispatcherP__Send__getPayload(
# 39 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
uint8_t arg_0x10975a6d8, 
# 68 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
message_t * msg, 


uint8_t len);
#line 48
static void SenderDispatcherP__Send__default__sendDone(
# 39 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
uint8_t arg_0x10975a6d8, 
# 44 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
message_t * msg, 



error_t error);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t SenderDispatcherP__Init__init(void );
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void BeaconSlotP__SubSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void BeaconSlotP__SubReceive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void BeaconSlotP__SyncAlarm__fired(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t BeaconSlotP__Send__send(
#line 34
message_t * msg, 





uint8_t len);
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t BeaconSlotP__Init__init(void );
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void BeaconSlotP__Receive__updateBuffer(
#line 49
message_t * msg);
# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__startAt(/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__size_type dt);
#line 77
static bool /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__isRunning(void );
#line 62
static void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__stop(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Init__init(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__overflow(void );
# 98 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__getNow(void );
#line 92
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__size_type dt);
#line 55
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__start(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__size_type dt);
#line 67
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__fired(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__overflow(void );
# 59 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void CC2420ControlP__CC2420Config__setChannel(uint8_t channel);
#line 52
static error_t CC2420ControlP__CC2420Config__sync(void );





static uint8_t CC2420ControlP__CC2420Config__getChannel(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t CC2420ControlP__Init__init(void );
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void CC2420ControlP__syncDoneTask__runTask(void );
#line 64
static void CpmModelC__read_rssi_task__runTask(void );
# 63 "/opt/tinyos-2.x/tos/interfaces/Read.nc"
static void CpmModelC__ReadRssi__default__readDone(error_t result, CpmModelC__ReadRssi__val_t val);
# 40 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
static void CpmModelC__Model__putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain, 
uint8_t channel_id);


static bool CpmModelC__Model__clearChannel(void );
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC__stopDoneTask__runTask(void );
# 52 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimPacketModelC__Packet__send(int node, message_t *msg, uint8_t len);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC__sendDoneTask__runTask(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t TossimPacketModelC__Init__init(void );
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC__startDoneTask__runTask(void );
# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t TossimPacketModelC__Control__start(void );
# 74 "/opt/tinyos-2.x/tos/interfaces/PacketAcknowledgements.nc"
static bool TossimPacketModelC__PacketAcknowledgements__wasAcked(
#line 69
message_t * msg);
# 52 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC__GainRadioModel__receive(message_t *msg);
#line 51
static void TossimPacketModelC__GainRadioModel__acked(message_t *msg);

static bool TossimPacketModelC__GainRadioModel__shouldAck(message_t *msg);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



SyncReceiveAdapterP__Receive__receive(
# 3 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncReceiveAdapterP.nc"
am_id_t arg_0x109b441a0, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void SyncReceiveAdapterP__AsyncReceive__updateBuffer(
#line 49
message_t * msg);
# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void SyncSendAdapterP__SplitControl__startDone(error_t error);
#line 117
static void SyncSendAdapterP__SplitControl__stopDone(error_t error);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void SyncSendAdapterP__AMSend__sendDone(
# 3 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
am_id_t arg_0x109b386c0, 
# 92 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 35 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
static error_t SyncSendAdapterP__RadioPowerControl__start(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t SyncSendAdapterP__AsyncSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

SyncSendAdapterP__AsyncSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t TossimActiveMessageC__AMSend__send(
# 39 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b6daf0, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 60
message_t * msg, 








uint8_t len);
#line 124
static 
#line 122
void * 

TossimActiveMessageC__AMSend__getPayload(
# 39 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b6daf0, 
# 121 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



TossimActiveMessageC__Snoop__default__receive(
# 41 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b697c0, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static uint8_t TossimActiveMessageC__Packet__payloadLength(
#line 63
message_t * msg);
#line 115
static 
#line 112
void * 


TossimActiveMessageC__Packet__getPayload(
#line 110
message_t * msg, 




uint8_t len);
#line 95
static uint8_t TossimActiveMessageC__Packet__maxPayloadLength(void );
# 79 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
static void TossimActiveMessageC__Model__receive(message_t *msg);
#line 71
static void TossimActiveMessageC__Model__sendDone(message_t *msg, error_t error);








static bool TossimActiveMessageC__Model__shouldAck(message_t *msg);
# 77 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
static am_addr_t TossimActiveMessageC__AMPacket__source(
#line 73
message_t * amsg);
#line 57
static am_addr_t TossimActiveMessageC__AMPacket__address(void );









static am_addr_t TossimActiveMessageC__AMPacket__destination(
#line 63
message_t * amsg);
#line 110
static void TossimActiveMessageC__AMPacket__setSource(
#line 106
message_t * amsg, 



am_addr_t addr);
#line 92
static void TossimActiveMessageC__AMPacket__setDestination(
#line 88
message_t * amsg, 



am_addr_t addr);
#line 136
static am_id_t TossimActiveMessageC__AMPacket__type(
#line 132
message_t * amsg);
#line 151
static void TossimActiveMessageC__AMPacket__setType(
#line 147
message_t * amsg, 



am_id_t t);
#line 125
static bool TossimActiveMessageC__AMPacket__isForMe(
#line 122
message_t * amsg);
# 46 "/opt/tinyos-2.x/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC__amAddress(void );
# 124 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static 
#line 122
void * 

/*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(
#line 121
message_t * msg, 


uint8_t len);
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(
#line 85
message_t * msg, 



error_t error);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(
# 40 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x109c0c488, 
# 92 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 114 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static 
#line 112
void * 

/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(
# 38 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x109c0e318, 
# 111 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 


uint8_t len);
#line 89
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(
# 38 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x109c0e318, 
# 85 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void );
#line 64
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void );
# 77 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static bool /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__isRunning(void );
#line 62
static void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__stop(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Init__init(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__overflow(void );
# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__stop(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__overflow(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Init__init(void );
#line 51
static error_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Init__init(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__overflow(void );
#line 71
static void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__overflow(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RandomMlcgC__Init__init(void );
# 59 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void TestNetworkC__CC2420Config__setChannel(uint8_t channel);
#line 52
static error_t TestNetworkC__CC2420Config__sync(void );
# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t TestNetworkC__RadioControl__start(void );
# 124 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static 
#line 122
void * 

TestNetworkC__Send__getPayload(
#line 121
message_t * msg, 


uint8_t len);
# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void TestNetworkC__Alarm__stop(void );
# 77 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
static am_addr_t TestNetworkC__AMPacket__source(
#line 73
message_t * amsg);
#line 67
static am_addr_t TestNetworkC__AMPacket__destination(
#line 63
message_t * amsg);
# 27 "TestNetworkC.nc"
message_t TestNetworkC__packet[1000];

TestNetworkMsg *TestNetworkC__rcm[1000];
TestNetworkMsg *TestNetworkC__rcmr[1000];
TestNetworkMsg *TestNetworkC__msgamr[1000];

TestNetworkMsg TestNetworkC__tnmsg_in_transit[1000];


bool TestNetworkC__sendBusy[1000];

enum TestNetworkC____nesc_unnamed4287 {
  TestNetworkC__RECEIVER = 0
};

static inline void TestNetworkC__Boot__booted(void );





static void TestNetworkC__RadioControl__startDone(error_t err);










static inline void TestNetworkC__Send__sendDone(message_t *m, error_t err);






static inline message_t *

TestNetworkC__Receive__receive(message_t *msg, void *payload, uint8_t len);






static inline message_t *TestNetworkC__AMReceive__receive(message_t *bufPtr, void *payload, uint8_t len);
#line 89
static inline void TestNetworkC__RadioControl__stopDone(error_t err);

static inline void TestNetworkC__CC2420Config__syncDone(error_t error);






static inline void TestNetworkC__Alarm__fired(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__MoteInit__init(void );
#line 51
static error_t PlatformP__MeasureClock__init(void );
# 42 "/opt/tinyos-2.x/tos/platforms/mica/PlatformP.nc"
static inline void PlatformP__power_init(void );






static inline error_t PlatformP__Init__init(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t MotePlatformP__SubInit__init(void );
# 33 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void MotePlatformP__SerialIdPin__makeInput(void );
#line 30
static void MotePlatformP__SerialIdPin__clr(void );
# 26 "/opt/tinyos-2.x/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP__PlatformInit__init(void );
# 46 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void );
#line 46
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void );
#line 46
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void );
#line 50
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__clr(void );


static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__makeInput(void );
# 21 "/opt/tinyos-2.x/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC__Init__init(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t SimMainP__SoftwareInit__init(void );
# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void SimMainP__Boot__booted(void );
# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t SimMainP__PlatformInit__init(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void SimMainP__Scheduler__init(void );







static bool SimMainP__Scheduler__runNextTask(void );
# 43 "/opt/tinyos-2.x/tos/lib/tossim/SimMainP.nc"
int sim_main_start_mote(void )   ;
# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP__TaskBasic__runTask(
# 41 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x108f83960);



enum SimSchedulerBasicP____nesc_unnamed4288 {

  SimSchedulerBasicP__NUM_TASKS = 9U, 
  SimSchedulerBasicP__NO_TASK = 255
};

uint8_t SimSchedulerBasicP__m_head[1000];
uint8_t SimSchedulerBasicP__m_tail[1000];
uint8_t SimSchedulerBasicP__m_next[1000][SimSchedulerBasicP__NUM_TASKS];




bool SimSchedulerBasicP__sim_scheduler_event_pending[1000];
sim_event_t SimSchedulerBasicP__sim_scheduler_event[1000];

static inline int SimSchedulerBasicP__sim_config_task_latency(void );







static void SimSchedulerBasicP__sim_scheduler_submit_event(void );







static inline void SimSchedulerBasicP__sim_scheduler_event_handle(sim_event_t *e);
#line 95
static inline void SimSchedulerBasicP__sim_scheduler_event_init(sim_event_t *e);
#line 112
static inline uint8_t SimSchedulerBasicP__popTask(void );
#line 131
static inline bool SimSchedulerBasicP__isWaiting(uint8_t id);




static inline bool SimSchedulerBasicP__pushTask(uint8_t id);
#line 158
static inline void SimSchedulerBasicP__Scheduler__init(void );
#line 172
static bool SimSchedulerBasicP__Scheduler__runNextTask(void );
#line 197
static error_t SimSchedulerBasicP__TaskBasic__postTask(uint8_t id);
#line 213
static inline void SimSchedulerBasicP__TaskBasic__default__runTask(uint8_t id);
# 44 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
long long int SimMoteP__euid[1000];
long long int SimMoteP__startTime[1000];
bool SimMoteP__isOn[1000];
sim_event_t *SimMoteP__bootEvent[1000];

uint8_t SimMoteP__radioChannel[1000];
int SimMoteP__tcp_msg[1000][5];




static inline error_t SimMoteP__SimMote__setRadioChannel(uint8_t newRadioChannel);
#line 68
static inline uint8_t SimMoteP__SimMote__getRadioChannel(void );
#line 80
error_t sim_mote_set_radio_channel(int mote, uint8_t newRadioChannel)   ;
#line 92
uint8_t sim_mote_get_radio_channel(int mote)   ;








static inline long long int SimMoteP__SimMote__getEuid(void );


static inline void SimMoteP__SimMote__setEuid(long long int e);


static inline long long int SimMoteP__SimMote__getStartTime(void );


static inline bool SimMoteP__SimMote__isOn(void );



static inline int SimMoteP__SimMote__getVariableInfo(char *name, void **addr, size_t *size);



static void SimMoteP__SimMote__turnOn(void );
#line 131
static inline void SimMoteP__SimMote__turnOff(void );




long long int sim_mote_euid(int mote)   ;








void sim_mote_set_euid(int mote, long long int id)   ;






long long int sim_mote_start_time(int mote)   ;








int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)   ;









void sim_mote_set_start_time(int mote, long long int t)   ;








bool sim_mote_is_on(int mote)   ;









void sim_mote_turn_on(int mote)   ;






void sim_mote_turn_off(int mote)   ;







static inline void SimMoteP__sim_mote_boot_handle(sim_event_t *e);








void sim_mote_enqueue_boot_event(int mote)   ;
#line 244
int *sim_mote_getTcpMsg(int mote)   ;
#line 262
void sim_mote_setTcpMsg(int mote, int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8)   ;










static inline int *SimMoteP__SimMote__getTcpMsg(void );
#line 286
static void SimMoteP__SimMote__setTcpMsg(int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8);
# 20 "/opt/tinyos-2.x/tos/chips/cc2420/csma/sim/CC2420CsmaP.nc"
message_t CC2420CsmaP__buffer[1000];
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t AsyncReceiveAdapterP__receiveDone_task__postTask(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



AsyncReceiveAdapterP__Receive__receive(
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
am_id_t arg_0x109375020, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void AsyncReceiveAdapterP__AsyncReceive__updateBuffer(
#line 49
message_t * msg);
# 45 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
enum AsyncReceiveAdapterP____nesc_unnamed4289 {
#line 45
  AsyncReceiveAdapterP__receiveDone_task = 0U
};
#line 45
typedef int AsyncReceiveAdapterP____nesc_sillytask_receiveDone_task[AsyncReceiveAdapterP__receiveDone_task];
#line 36
message_t * AsyncReceiveAdapterP__msg_[1000];
void * AsyncReceiveAdapterP__payload_[1000];
uint8_t AsyncReceiveAdapterP__len_[1000];

static inline tossim_header_t *AsyncReceiveAdapterP__getHeader(message_t *msg);






static inline void AsyncReceiveAdapterP__AsyncReceive__receive(message_t *msg, void *payload, uint8_t len);
#line 59
static inline void AsyncReceiveAdapterP__receiveDone_task__runTask(void );
#line 77
static inline message_t *AsyncReceiveAdapterP__Receive__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void AsyncSendAdapterP__AMSend__sendDone(
# 31 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
am_id_t arg_0x109376c00, 
# 92 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t AsyncSendAdapterP__AsyncSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

AsyncSendAdapterP__AsyncSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t AsyncSendAdapterP__sendDone_task__postTask(void );
# 44 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
enum AsyncSendAdapterP____nesc_unnamed4290 {
#line 44
  AsyncSendAdapterP__sendDone_task = 1U
};
#line 44
typedef int AsyncSendAdapterP____nesc_sillytask_sendDone_task[AsyncSendAdapterP__sendDone_task];
#line 36
message_t * AsyncSendAdapterP__msg_[1000];
uint8_t AsyncSendAdapterP__len_[1000];

static inline tossim_header_t *AsyncSendAdapterP__getHeader(message_t *msg);






static inline error_t AsyncSendAdapterP__AMSend__send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len);
#line 58
static inline void AsyncSendAdapterP__AsyncSend__sendDone(message_t *msg, uint8_t len);










static inline void AsyncSendAdapterP__sendDone_task__runTask(void );
#line 89
static inline void *AsyncSendAdapterP__AMSend__getPayload(am_id_t id, message_t *msg, uint8_t len);
# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void PureTDMASchedulerP__SplitControl__startDone(error_t error);
#line 117
static void PureTDMASchedulerP__SplitControl__stopDone(error_t error);
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t PureTDMASchedulerP__SubSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

PureTDMASchedulerP__SubSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void PureTDMASchedulerP__SubReceive__updateBuffer(
#line 49
message_t * msg);
# 59 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void PureTDMASchedulerP__CC2420Config__setChannel(uint8_t channel);
#line 52
static error_t PureTDMASchedulerP__CC2420Config__sync(void );





static uint8_t PureTDMASchedulerP__CC2420Config__getChannel(void );
# 35 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
static error_t PureTDMASchedulerP__RadioPowerControl__start(void );
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void PureTDMASchedulerP__Send__sendDone(
#line 44
message_t * msg, 



error_t error);
# 74 "/opt/tinyos-2.x/tos/interfaces/AsyncStdControl.nc"
static error_t PureTDMASchedulerP__GenericSlotter__start(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t PureTDMASchedulerP__BeaconSend__send(
#line 34
message_t * msg, 





uint8_t len);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void PureTDMASchedulerP__Receive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 48 "/opt/tinyos-2.x/tos/lib/tossim/SimMote.nc"
static void PureTDMASchedulerP__SimMote__setTcpMsg(int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8);
# 74 "/opt/tinyos-2.x/tos/interfaces/PacketAcknowledgements.nc"
static bool PureTDMASchedulerP__PacketAcknowledgements__wasAcked(
#line 69
message_t * msg);
# 38 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/FrameConfiguration.nc"
static void PureTDMASchedulerP__FrameConfiguration__setFrameLength(uint32_t numSlots);
#line 32
static void PureTDMASchedulerP__FrameConfiguration__setSlotLength(uint32_t slotTimeBms);
# 77 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
static am_addr_t PureTDMASchedulerP__AMPacket__source(
#line 73
message_t * amsg);
#line 92
static void PureTDMASchedulerP__AMPacket__setDestination(
#line 88
message_t * amsg, 



am_addr_t addr);
#line 136
static am_id_t PureTDMASchedulerP__AMPacket__type(
#line 132
message_t * amsg);
# 39 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
static uint32_t PureTDMASchedulerP__SlotterControl__getSlot(void );
#line 31
static error_t PureTDMASchedulerP__SlotterControl__synchronize(uint8_t toSlot);
# 53 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
enum PureTDMASchedulerP____nesc_unnamed4291 {
  PureTDMASchedulerP__SIMPLE_TDMA_SYNC = 123, 
  PureTDMASchedulerP__MAXCHILDREN = 7, 
  PureTDMASchedulerP__TOTALNODES = 55, 
  PureTDMASchedulerP__NUM_MEASUREMENTS = 9, 
  PureTDMASchedulerP__LP_SAMPLE_TIMES = 200, 
  PureTDMASchedulerP__TOPO_SAMPLE_TIMES = 50, 
  PureTDMASchedulerP__ROOT1 = 50, 
  PureTDMASchedulerP__ADD_THRESHOLD = 20, 
  PureTDMASchedulerP__REDUCE_THRESHOLD = 5
};









#line 65
typedef nx_struct PureTDMASchedulerP__logentry_t {

  TestNetworkMsg  saved_data[PureTDMASchedulerP__MAXCHILDREN];
  nx_uint8_t  handled_saved_data[PureTDMASchedulerP__MAXCHILDREN];
  nx_uint8_t  prob_bit[PureTDMASchedulerP__MAXCHILDREN];
  nx_uint8_t len;
  message_t msg;
  nx_uint8_t avg_prob;
} __attribute__((packed)) PureTDMASchedulerP__logentry_t;


PureTDMASchedulerP__logentry_t PureTDMASchedulerP__m_entry[1000];
TestNetworkMsg * PureTDMASchedulerP__log_payload[1000];

TestNetworkMsg * PureTDMASchedulerP__rcmr[1000];

uint8_t PureTDMASchedulerP__isChild[1000];
uint8_t PureTDMASchedulerP__isParent[1000];
uint8_t PureTDMASchedulerP__isSibling[1000];
uint8_t PureTDMASchedulerP__self_pos[1000];

uint8_t PureTDMASchedulerP__receiving_num[1000];
uint8_t PureTDMASchedulerP__totalChildren[1000];
uint8_t PureTDMASchedulerP__totalParents[1000];

uint8_t PureTDMASchedulerP__flag[1000];


uint8_t PureTDMASchedulerP__MAXLEVELNODE[1000];

uint8_t PureTDMASchedulerP__CURRNODES[1000];







FILE *PureTDMASchedulerP__delay_fp[1000];

FILE *PureTDMASchedulerP__topo_fp[1000];



uint8_t PureTDMASchedulerP__res_list[1000][PureTDMASchedulerP__NUM_MEASUREMENTS];

uint8_t PureTDMASchedulerP__delay_list[1000][PureTDMASchedulerP__NUM_MEASUREMENTS];



uint8_t PureTDMASchedulerP__send_counter[1000];

uint8_t PureTDMASchedulerP__is_primary[1000];

uint8_t PureTDMASchedulerP__rev_counter[1000];

bool PureTDMASchedulerP__init[1000];
uint32_t PureTDMASchedulerP__slotSize[1000];
uint32_t PureTDMASchedulerP__bi[1000];
#line 123
uint32_t PureTDMASchedulerP__sd[1000];
#line 123
uint32_t PureTDMASchedulerP__cap[1000];
uint8_t PureTDMASchedulerP__coordinatorId[1000];

uint8_t PureTDMASchedulerP__i[1000];
uint8_t PureTDMASchedulerP__j[1000];
uint8_t PureTDMASchedulerP__k[1000];

message_t *PureTDMASchedulerP__toSend[1000];
uint8_t PureTDMASchedulerP__toSendLen[1000];


uint8_t PureTDMASchedulerP__schedule_counter[1000][12];



uint8_t PureTDMASchedulerP__up_schedule[1000][12][12];





uint8_t PureTDMASchedulerP__avg_prob[1000];

uint8_t PureTDMASchedulerP__node_list[1000][50];

uint8_t PureTDMASchedulerP__schedule_len[1000];

uint8_t PureTDMASchedulerP__lp_intervals[1000];



uint32_t PureTDMASchedulerP__superframe_length[1000];

bool PureTDMASchedulerP__sync[1000];
bool PureTDMASchedulerP__requestStop[1000];



static inline void PureTDMASchedulerP__reset_parameters(void );
static void PureTDMASchedulerP__readTopoFile(void );
static void PureTDMASchedulerP__generateSchedule(void );

static int PureTDMASchedulerP__find_delay(int node);







static inline error_t PureTDMASchedulerP__Init__init(void );
#line 294
static error_t PureTDMASchedulerP__SplitControl__start(void );
#line 313
static inline void PureTDMASchedulerP__RadioPowerControl__startDone(error_t error);
#line 330
static inline void PureTDMASchedulerP__RadioPowerControl__stopDone(error_t error);










static inline void PureTDMASchedulerP__Slotter__slot(uint32_t slot);
#line 547
static inline error_t PureTDMASchedulerP__Send__send(message_t *msg, uint8_t len);










static inline void PureTDMASchedulerP__SubSend__sendDone(message_t *msg, error_t error);
#line 589
static inline void PureTDMASchedulerP__SubReceive__receive(message_t *msg, void *payload, uint8_t len);
#line 879
static inline void *PureTDMASchedulerP__Send__getPayload(message_t *msg, uint8_t len);








static inline void PureTDMASchedulerP__Receive__updateBuffer(message_t *msg);
#line 902
static inline void PureTDMASchedulerP__CC2420Config__syncDone(error_t error);
static inline void PureTDMASchedulerP__BeaconSend__sendDone(message_t *msg, error_t error);

static void PureTDMASchedulerP__readTopoFile(void );
#line 981
static int PureTDMASchedulerP__find_delay(int node);
#line 995
static inline void PureTDMASchedulerP__reset_parameters(void );
#line 1112
static void PureTDMASchedulerP__generateSchedule(void );
# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void LedsP__Led0__makeOutput(void );
#line 29
static void LedsP__Led0__set(void );





static void LedsP__Led1__makeOutput(void );
#line 29
static void LedsP__Led1__set(void );





static void LedsP__Led2__makeOutput(void );
#line 29
static void LedsP__Led2__set(void );
# 45 "/opt/tinyos-2.x/tos/system/LedsP.nc"
static inline error_t LedsP__Init__init(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
#line 48
static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__sendDone(
#line 44
message_t * msg, 



error_t error);
# 55 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__start(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__size_type dt);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
enum /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0____nesc_unnamed4292 {
  GenericSlotSenderP__0__S_START = 0, 
  GenericSlotSenderP__0__S_OFFSET = 1, 
  GenericSlotSenderP__0__S_SENT = 2, 
  GenericSlotSenderP__0__S_END = 3
};

message_t */*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[1000];
uint8_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[1000];
uint8_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[1000];

static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Boot__booted(void );




static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__alarm(uint8_t at);


static inline error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Init__init(void );






static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__send(message_t *msg, uint8_t len);
#line 119
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__fired(void );
#line 134
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__sendDone(message_t *msg, error_t error);
#line 146
static inline void */*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__getPayload(message_t *msg, uint8_t len);
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__fired(void );
# 9 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
uint16_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm[1000];
sim_time_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[1000];
sim_event_t */*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[1000];

static inline error_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Init__init(void );





static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__handle_timer_fired(sim_event_t *e);
#line 37
static inline bool /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__isRunning(void );




static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__stop(void );
#line 58
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 80
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__overflow(void );
# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void CounterMicro16P__Counter__overflow(void );
# 25 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
sim_time_t CounterMicro16P__t0[1000];

static void CounterMicro16P__scheduleOverflow(void );
static inline void CounterMicro16P__handleOverflow(sim_event_t *evt);

static inline error_t CounterMicro16P__Init__init(void );






static void CounterMicro16P__scheduleOverflow(void );










static inline void CounterMicro16P__handleOverflow(sim_event_t *evt);






static uint16_t CounterMicro16P__Counter__get(void );






static inline bool CounterMicro16P__Counter__isOverflowPending(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__fired(void );
#line 92
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__size_type dt);
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__get(void );
# 66 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[1000];
/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[1000];

enum /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0____nesc_unnamed4293 {

  TransformAlarmC__0__MAX_DELAY_LOG2 = 8 * sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_size_type ) - 1 - 5, 
  TransformAlarmC__0__MAX_DELAY = (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type )1 << /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__MAX_DELAY_LOG2
};

static inline /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__getNow(void );
#line 96
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__set_alarm(void );
#line 136
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type dt);









static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__start(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type dt);




static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__fired(void );
#line 166
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__overflow(void );
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__get(void );






static bool /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__isOverflowPending(void );










static void /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__overflow(void );
# 56 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__upper_count_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[1000];

enum /*Counter32khz16C.TransformCounterC*/TransformCounterC__0____nesc_unnamed4294 {

  TransformCounterC__0__LOW_SHIFT_RIGHT = 5, 
  TransformCounterC__0__HIGH_SHIFT_LEFT = 8 * sizeof(/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_size_type ) - /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__LOW_SHIFT_RIGHT, 
  TransformCounterC__0__NUM_UPPER_BITS = 8 * sizeof(/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type ) - 8 * sizeof(/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_size_type ) + 5, 



  TransformCounterC__0__OVERFLOW_MASK = /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__NUM_UPPER_BITS ? ((/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__upper_count_type )2 << (/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__NUM_UPPER_BITS - 1)) - 1 : 0
};

static /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__get(void );
#line 122
static inline void /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__overflow(void );
# 32 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/Slotter.nc"
static void GenericSlotterP__Slotter__slot(uint32_t num);
# 98 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static GenericSlotterP__Alarm__size_type GenericSlotterP__Alarm__getNow(void );
#line 55
static void GenericSlotterP__Alarm__start(GenericSlotterP__Alarm__size_type dt);






static void GenericSlotterP__Alarm__stop(void );
# 54 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
uint32_t GenericSlotterP__slot[1000];
uint32_t GenericSlotterP__slotLength[1000];
uint32_t GenericSlotterP__frameLength[1000];
bool GenericSlotterP__sync[1000];
uint32_t GenericSlotterP__nextFire[1000];

static inline error_t GenericSlotterP__Init__init(void );








static inline void GenericSlotterP__Boot__booted(void );




static inline error_t GenericSlotterP__AsyncStdControl__start(void );









static error_t GenericSlotterP__SlotterControl__synchronize(uint8_t toSlot);







static inline void GenericSlotterP__FrameConfiguration__setSlotLength(uint32_t slotTimeBms);







static inline void GenericSlotterP__FrameConfiguration__setFrameLength(uint32_t numSlots);
#line 116
static inline void GenericSlotterP__SlotterControl__stop(void );



static void GenericSlotterP__Alarm__fired(void );








static inline uint32_t GenericSlotterP__SlotterControl__getSlot(void );



static inline uint32_t GenericSlotterP__SlotterControl__getRemaining(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__fired(void );
# 9 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
uint16_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm[1000];
sim_time_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[1000];
sim_event_t */*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[1000];

static inline error_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Init__init(void );





static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__handle_timer_fired(sim_event_t *e);
#line 37
static inline bool /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__isRunning(void );




static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__stop(void );
#line 58
static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 80
static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__overflow(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__fired(void );
#line 92
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__size_type t0, /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__size_type dt);
#line 62
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__stop(void );
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__get(void );
# 66 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[1000];
/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[1000];

enum /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1____nesc_unnamed4295 {

  TransformAlarmC__1__MAX_DELAY_LOG2 = 8 * sizeof(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_size_type ) - 1 - 5, 
  TransformAlarmC__1__MAX_DELAY = (/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type )1 << /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__MAX_DELAY_LOG2
};

static inline /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__getNow(void );
#line 91
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__stop(void );




static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__set_alarm(void );
#line 136
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type t0, /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type dt);









static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__start(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type dt);




static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__fired(void );
#line 166
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__overflow(void );
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__get(void );






static bool /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__isOverflowPending(void );










static void /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__overflow(void );
# 56 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__upper_count_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[1000];

enum /*Counter32khz32C.TransformCounterC*/TransformCounterC__1____nesc_unnamed4296 {

  TransformCounterC__1__LOW_SHIFT_RIGHT = 5, 
  TransformCounterC__1__HIGH_SHIFT_LEFT = 8 * sizeof(/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_size_type ) - /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__LOW_SHIFT_RIGHT, 
  TransformCounterC__1__NUM_UPPER_BITS = 8 * sizeof(/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type ) - 8 * sizeof(/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_size_type ) + 5, 



  TransformCounterC__1__OVERFLOW_MASK = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__NUM_UPPER_BITS ? ((/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__upper_count_type )2 << (/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__NUM_UPPER_BITS - 1)) - 1 : 0
};

static /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__get(void );
#line 122
static inline void /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__overflow(void );
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t SenderDispatcherP__SubSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

SenderDispatcherP__SubSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
#line 48
static void SenderDispatcherP__Send__sendDone(
# 39 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
uint8_t arg_0x10975a6d8, 
# 44 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
message_t * msg, 



error_t error);
# 42 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
message_t *SenderDispatcherP__toSend[1000];
uint8_t SenderDispatcherP__toSendLen[1000];
uint8_t SenderDispatcherP__last_id[1000];

static inline error_t SenderDispatcherP__Init__init(void );
#line 59
static error_t SenderDispatcherP__Send__send(uint8_t slotType, message_t *msg, uint8_t len);
#line 94
static inline void *SenderDispatcherP__Send__getPayload(uint8_t slotType, message_t *msg, uint8_t len);







static void SenderDispatcherP__SubSend__sendDone(message_t *msg, error_t error);
#line 121
static inline void SenderDispatcherP__Send__default__sendDone(uint8_t type, message_t *msg, error_t error);
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static error_t BeaconSlotP__SubSend__send(
#line 34
message_t * msg, 





uint8_t len);
#line 71
static 
#line 69
void * 

BeaconSlotP__SubSend__getPayload(
#line 68
message_t * msg, 


uint8_t len);
# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void BeaconSlotP__SubReceive__updateBuffer(
#line 49
message_t * msg);
# 55 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void BeaconSlotP__SyncAlarm__start(BeaconSlotP__SyncAlarm__size_type dt);
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void BeaconSlotP__Send__sendDone(
#line 44
message_t * msg, 



error_t error);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void BeaconSlotP__Receive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 110 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
static void BeaconSlotP__AMPacket__setSource(
#line 106
message_t * amsg, 



am_addr_t addr);
#line 92
static void BeaconSlotP__AMPacket__setDestination(
#line 88
message_t * amsg, 



am_addr_t addr);
#line 136
static am_id_t BeaconSlotP__AMPacket__type(
#line 132
message_t * amsg);
#line 151
static void BeaconSlotP__AMPacket__setType(
#line 147
message_t * amsg, 



am_id_t t);
# 31 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
static error_t BeaconSlotP__SlotterControl__synchronize(uint8_t toSlot);




static uint32_t BeaconSlotP__SlotterControl__getRemaining(void );
static void BeaconSlotP__SlotterControl__stop(void );
# 51 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
message_t BeaconSlotP__syncPkt[1000];
uint8_t BeaconSlotP__syncPktLen[1000];




static inline void BeaconSlotP__write_timestamp(uint8_t *payload, uint32_t timestamp);





static inline uint32_t BeaconSlotP__read_timestamp(uint8_t *payload);





static inline error_t BeaconSlotP__Init__init(void );








static error_t BeaconSlotP__Send__send(message_t *msg, uint8_t len);
#line 93
static inline void BeaconSlotP__SubSend__sendDone(message_t *msg, error_t error);
#line 113
static inline void BeaconSlotP__SubReceive__receive(message_t *msg, void *payload, uint8_t len);
#line 136
static inline void BeaconSlotP__SyncAlarm__fired(void );



static inline void BeaconSlotP__Receive__updateBuffer(message_t *msg);
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__fired(void );
# 9 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
uint16_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm[1000];
sim_time_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[1000];
sim_event_t */*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[1000];

static inline error_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Init__init(void );





static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__handle_timer_fired(sim_event_t *e);
#line 37
static inline bool /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__isRunning(void );




static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__stop(void );
#line 58
static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 80
static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__overflow(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__fired(void );
#line 92
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__size_type dt);
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__get(void );
# 66 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[1000];
/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[1000];

enum /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2____nesc_unnamed4297 {

  TransformAlarmC__2__MAX_DELAY_LOG2 = 8 * sizeof(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_size_type ) - 1 - 5, 
  TransformAlarmC__2__MAX_DELAY = (/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type )1 << /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__MAX_DELAY_LOG2
};

static inline /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__getNow(void );
#line 96
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__set_alarm(void );
#line 136
static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type dt);









static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__start(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type dt);




static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__fired(void );
#line 166
static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__overflow(void );
# 53 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
static void CC2420ControlP__CC2420Config__syncDone(error_t error);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t CC2420ControlP__syncDoneTask__postTask(void );
# 36 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
enum CC2420ControlP____nesc_unnamed4298 {
#line 36
  CC2420ControlP__syncDoneTask = 2U
};
#line 36
typedef int CC2420ControlP____nesc_sillytask_syncDoneTask[CC2420ControlP__syncDoneTask];
#line 12
uint8_t CC2420ControlP__channel[1000];




bool CC2420ControlP__autoAck[1000];
bool CC2420ControlP__hwAutoAck[1000];
static inline error_t CC2420ControlP__Init__init(void );
#line 36
static inline void CC2420ControlP__syncDoneTask__runTask(void );



static error_t CC2420ControlP__CC2420Config__sync(void );






static inline uint8_t CC2420ControlP__CC2420Config__getChannel(void );
static inline void CC2420ControlP__CC2420Config__setChannel(uint8_t ch);
# 63 "/opt/tinyos-2.x/tos/interfaces/Read.nc"
static void CpmModelC__ReadRssi__readDone(error_t result, CpmModelC__ReadRssi__val_t val);
# 52 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
static void CpmModelC__Model__receive(message_t *msg);
#line 51
static void CpmModelC__Model__acked(message_t *msg);

static bool CpmModelC__Model__shouldAck(message_t *msg);
# 640 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
enum CpmModelC____nesc_unnamed4299 {
#line 640
  CpmModelC__read_rssi_task = 3U
};
#line 640
typedef int CpmModelC____nesc_sillytask_read_rssi_task[CpmModelC__read_rssi_task];
#line 59
message_t *CpmModelC__outgoing[1000];
bool CpmModelC__requestAck[1000];
bool CpmModelC__receiving[1000];
bool CpmModelC__rssi[1000];
struct CpmModelC__receive_message;
typedef struct CpmModelC__receive_message CpmModelC__receive_message_t;

struct CpmModelC__receive_message {
  int source;
  sim_time_t start;
  sim_time_t end;
  double power;
  double reversePower;
  int8_t strength;
  bool lost;
  bool ack;
  message_t *msg;
  CpmModelC__receive_message_t *next;
  uint8_t channel;
  uint8_t lqi;
};

CpmModelC__receive_message_t *CpmModelC__outstandingReceptionHead[1000];

static inline CpmModelC__receive_message_t *CpmModelC__allocate_receive_message(void );
static inline void CpmModelC__free_receive_message(CpmModelC__receive_message_t *msg);
static inline sim_event_t *CpmModelC__allocate_receive_event(sim_time_t t, CpmModelC__receive_message_t *m);

static bool CpmModelC__shouldReceive(double SNR, int isCheckReceive);
static inline bool CpmModelC__checkReceive(CpmModelC__receive_message_t *msg);
static double CpmModelC__packetNoise(CpmModelC__receive_message_t *msg);


static inline double CpmModelC__timeInMs(void );
#line 127
static double CpmModelC__noise_hash_generation(void );
#line 155
static inline double CpmModelC__arr_estimate_from_snr(double SNR);
#line 170
static inline int CpmModelC__shouldAckReceive(double snr);
#line 184
static inline void CpmModelC__sim_gain_ack_handle(sim_event_t *evt);
#line 206
double CpmModelC__clearThreshold[1000];










static bool CpmModelC__Model__clearChannel(void );






static void CpmModelC__sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC__receive_message_t *r);
#line 238
static inline double CpmModelC__prr_estimate_from_snr(double SNR);
#line 254
static bool CpmModelC__shouldReceive(double SNR, int isCheckReceive);
#line 293
static inline bool CpmModelC__checkReceive(CpmModelC__receive_message_t *msg);
#line 398
static double CpmModelC__packetNoise(CpmModelC__receive_message_t *msg);
#line 437
static inline void CpmModelC__sim_gain_receive_handle(sim_event_t *evt);
#line 521
static inline void CpmModelC__enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower);
#line 593
static inline void CpmModelC__sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower, int channel_id);







static void CpmModelC__Model__putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower, uint8_t channel_id);
#line 620
static inline sim_event_t *CpmModelC__allocate_receive_event(sim_time_t endTime, CpmModelC__receive_message_t *msg);
#line 632
static inline CpmModelC__receive_message_t *CpmModelC__allocate_receive_message(void );



static inline void CpmModelC__free_receive_message(CpmModelC__receive_message_t *msg);



static inline void CpmModelC__read_rssi_task__runTask(void );
#line 659
static inline void CpmModelC__ReadRssi__default__readDone(error_t error, uint16_t data);
# 79 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
static void TossimPacketModelC__Packet__receive(message_t *msg);
#line 71
static void TossimPacketModelC__Packet__sendDone(message_t *msg, error_t error);








static bool TossimPacketModelC__Packet__shouldAck(message_t *msg);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TossimPacketModelC__startDoneTask__postTask(void );
# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void TossimPacketModelC__Control__startDone(error_t error);
#line 117
static void TossimPacketModelC__Control__stopDone(error_t error);
# 40 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC__GainRadioModel__putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain, 
uint8_t channel_id);


static bool TossimPacketModelC__GainRadioModel__clearChannel(void );
# 93 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
enum TossimPacketModelC____nesc_unnamed4300 {
#line 93
  TossimPacketModelC__startDoneTask = 4U
};
#line 93
typedef int TossimPacketModelC____nesc_sillytask_startDoneTask[TossimPacketModelC__startDoneTask];




enum TossimPacketModelC____nesc_unnamed4301 {
#line 98
  TossimPacketModelC__stopDoneTask = 5U
};
#line 98
typedef int TossimPacketModelC____nesc_sillytask_stopDoneTask[TossimPacketModelC__stopDoneTask];
#line 143
enum TossimPacketModelC____nesc_unnamed4302 {
#line 143
  TossimPacketModelC__sendDoneTask = 6U
};
#line 143
typedef int TossimPacketModelC____nesc_sillytask_sendDoneTask[TossimPacketModelC__sendDoneTask];
#line 65
bool TossimPacketModelC__initialized[1000];
bool TossimPacketModelC__running[1000];
uint8_t TossimPacketModelC__backoffCount[1000];
uint8_t TossimPacketModelC__neededFreeSamples[1000];
message_t *TossimPacketModelC__sending[1000];
bool TossimPacketModelC__transmitting[1000];
uint8_t TossimPacketModelC__sendingLength[1000];
int TossimPacketModelC__destNode[1000];
sim_event_t TossimPacketModelC__sendEvent[1000];

uint8_t TossimPacketModelC__cca_enable_flag[1000];



static inline tossim_metadata_t *TossimPacketModelC__getMetadata(message_t *msg);



static inline error_t TossimPacketModelC__Init__init(void );









static inline void TossimPacketModelC__startDoneTask__runTask(void );




static inline void TossimPacketModelC__stopDoneTask__runTask(void );




static inline error_t TossimPacketModelC__Control__start(void );
#line 137
static inline error_t TossimPacketModelC__PacketAcknowledgements__wasAcked(message_t *ack);





static inline void TossimPacketModelC__sendDoneTask__runTask(void );
#line 157
static inline void TossimPacketModelC__start_csma(void );
static void TossimPacketModelC__send_transmit_with_cca(sim_event_t *evt);

static inline error_t TossimPacketModelC__Packet__send(int dest, message_t *msg, uint8_t len);
#line 183
static inline void TossimPacketModelC__send_backoff(sim_event_t *evt);
static inline void TossimPacketModelC__send_backoff_cancel_packet(sim_event_t *evt);
static inline void TossimPacketModelC__send_transmit(sim_event_t *evt);
static void TossimPacketModelC__send_transmit_done(sim_event_t *evt);

static inline void TossimPacketModelC__send_transmit_with_cca_fake(sim_event_t *evt);

static inline void TossimPacketModelC__start_csma(void );
#line 224
static inline int TossimPacketModelC__sim_packet_header_length(void );



static inline void TossimPacketModelC__send_transmit(sim_event_t *evt);
#line 249
static void TossimPacketModelC__send_transmit_with_cca(sim_event_t *evt);
#line 270
static inline void TossimPacketModelC__send_transmit_with_cca_fake(sim_event_t *evt);
#line 290
static void TossimPacketModelC__send_transmit_done(sim_event_t *evt);







static inline void TossimPacketModelC__GainRadioModel__receive(message_t *msg);





uint8_t TossimPacketModelC__error[1000];

static inline void TossimPacketModelC__GainRadioModel__acked(message_t *msg);










static bool TossimPacketModelC__GainRadioModel__shouldAck(message_t *msg);








static inline void TossimPacketModelC__send_backoff(sim_event_t *evt);
#line 365
static inline void TossimPacketModelC__send_backoff_cancel_packet(sim_event_t *evt);
# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
static void SyncReceiveAdapterP__AsyncReceive__receive(
#line 37
message_t * msg, 
void * payload, 


uint8_t len);
# 8 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncReceiveAdapterP.nc"
static inline message_t *SyncReceiveAdapterP__Receive__receive(am_id_t id, message_t *msg, void *payload, uint8_t len);








static inline void SyncReceiveAdapterP__AsyncReceive__updateBuffer(message_t *msg);
# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t SyncSendAdapterP__SplitControl__start(void );
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t SyncSendAdapterP__AMSend__send(
# 3 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
am_id_t arg_0x109b386c0, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 60
message_t * msg, 








uint8_t len);
#line 124
static 
#line 122
void * 

SyncSendAdapterP__AMSend__getPayload(
# 3 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
am_id_t arg_0x109b386c0, 
# 121 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 36 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
static void SyncSendAdapterP__RadioPowerControl__startDone(error_t error);





static void SyncSendAdapterP__RadioPowerControl__stopDone(error_t error);
# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void SyncSendAdapterP__AsyncSend__sendDone(
#line 44
message_t * msg, 



error_t error);
# 10 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline tossim_header_t *SyncSendAdapterP__getHeader(message_t *msg);




static inline error_t SyncSendAdapterP__AsyncSend__send(message_t *msg, uint8_t len);









static inline void SyncSendAdapterP__AMSend__sendDone(am_id_t id, message_t *msg, uint8_t len);









static inline void *SyncSendAdapterP__AsyncSend__getPayload(message_t *msg, uint8_t len);




static inline error_t SyncSendAdapterP__RadioPowerControl__start(void );

static inline void SyncSendAdapterP__SplitControl__startDone(error_t err);
static inline void SyncSendAdapterP__SplitControl__stopDone(error_t err);
# 49 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC__amAddress(void );
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void TossimActiveMessageC__AMSend__sendDone(
# 39 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b6daf0, 
# 92 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 63
message_t * 



TossimActiveMessageC__Snoop__receive(
# 41 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b697c0, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
#line 67
static 
#line 63
message_t * 



TossimActiveMessageC__Receive__receive(
# 40 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x109b6ac18, 
# 60 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 52 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimActiveMessageC__Model__send(int node, message_t *msg, uint8_t len);
# 54 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
message_t TossimActiveMessageC__buffer[1000];
message_t *TossimActiveMessageC__bufferPointer[1000];

static inline tossim_header_t *TossimActiveMessageC__getHeader(message_t *amsg);







static inline error_t TossimActiveMessageC__AMSend__send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len);
#line 87
static void *TossimActiveMessageC__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len);







static inline void TossimActiveMessageC__Model__sendDone(message_t *msg, error_t result);





static void TossimActiveMessageC__Model__receive(message_t *msg);
#line 119
static inline bool TossimActiveMessageC__Model__shouldAck(message_t *msg);








static inline am_addr_t TossimActiveMessageC__AMPacket__address(void );



static am_addr_t TossimActiveMessageC__AMPacket__destination(message_t *amsg);




static void TossimActiveMessageC__AMPacket__setDestination(message_t *amsg, am_addr_t addr);




static am_addr_t TossimActiveMessageC__AMPacket__source(message_t *amsg);




static inline void TossimActiveMessageC__AMPacket__setSource(message_t *amsg, am_addr_t addr);




static inline bool TossimActiveMessageC__AMPacket__isForMe(message_t *amsg);




static am_id_t TossimActiveMessageC__AMPacket__type(message_t *amsg);




static inline void TossimActiveMessageC__AMPacket__setType(message_t *amsg, am_id_t t);






static inline uint8_t TossimActiveMessageC__Packet__payloadLength(message_t *msg);







static inline uint8_t TossimActiveMessageC__Packet__maxPayloadLength(void );



static inline void *TossimActiveMessageC__Packet__getPayload(message_t *msg, uint8_t len);
#line 208
static inline message_t *TossimActiveMessageC__Snoop__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
#line 228
static inline void TossimActiveMessageC__active_message_deliver_handle(sim_event_t *evt);





static inline sim_event_t *TossimActiveMessageC__allocate_deliver_event(int node, message_t *msg, sim_time_t t);
#line 246
void active_message_deliver(int node, message_t *msg, sim_time_t t)   ;
# 50 "/opt/tinyos-2.x/tos/lib/tossim/ActiveMessageAddressC.nc"
bool ActiveMessageAddressC__set[1000];
am_addr_t ActiveMessageAddressC__addr[1000];

static am_addr_t ActiveMessageAddressC__amAddress(void );
# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(
#line 92
message_t * msg, 






error_t error);
# 114 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static 
#line 112
void * 

/*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(
#line 111
message_t * msg, 


uint8_t len);
# 57 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(message_t *m, error_t err);







static inline void */*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(message_t *m, uint8_t len);
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(
# 40 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x109c0c488, 
# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 60
message_t * msg, 








uint8_t len);
#line 124
static 
#line 122
void * 

/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(
# 40 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x109c0c488, 
# 121 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(
# 38 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x109c0e318, 
# 85 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(
#line 63
message_t * msg);
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask(void );
# 67 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(
#line 63
message_t * amsg);
#line 136
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(
#line 132
message_t * amsg);
# 118 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4303 {
#line 118
  AMQueueImplP__0__CancelTask = 7U
};
#line 118
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask];
#line 161
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4304 {
#line 161
  AMQueueImplP__0__errorTask = 8U
};
#line 161
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask];
#line 49
#line 47
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4305 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[1000];
/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[1000][1];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[1000][1 / 8 + 1];

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket(void );
#line 118
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void );
#line 155
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void );




static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void );
#line 181
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(am_id_t id, message_t *msg, error_t err);
#line 203
static inline void */*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(uint8_t id, message_t *m, uint8_t len);



static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(uint8_t id, message_t *msg, error_t err);
# 10 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
sim_time_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[1000];
sim_event_t */*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[1000];

static inline error_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Init__init(void );
#line 37
static inline bool /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__isRunning(void );




static inline void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__stop(void );
#line 80
static inline void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__overflow(void );
# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__AlarmFrom__stop(void );
# 69 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
enum /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3____nesc_unnamed4306 {

  TransformAlarmC__3__MAX_DELAY_LOG2 = 8 * sizeof(/*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__from_size_type ) - 1 - 5, 
  TransformAlarmC__3__MAX_DELAY = (/*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__to_size_type )1 << /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__MAX_DELAY_LOG2
};
#line 91
static inline void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__stop(void );
#line 166
static inline void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__overflow(void );
# 54 "/opt/tinyos-2.x/apps/wustl/upma/system/SSTdmaSlotSenderP.nc"
enum /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0____nesc_unnamed4307 {
  SSTdmaSlotSenderP__0__S_START = 0, 
  SSTdmaSlotSenderP__0__S_CCA = 1, 
  SSTdmaSlotSenderP__0__S_BACKOFF = 2, 
  SSTdmaSlotSenderP__0__S_CCA2 = 3, 
  SSTdmaSlotSenderP__0__S_SEND = 4, 
  SSTdmaSlotSenderP__0__S_END = 5
};

message_t */*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[1000];
uint8_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[1000];
uint8_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[1000];


static inline error_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Init__init(void );
# 10 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
sim_time_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[1000];


static inline error_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Init__init(void );
#line 80
static inline void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__overflow(void );
# 69 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
enum /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4____nesc_unnamed4308 {

  TransformAlarmC__4__MAX_DELAY_LOG2 = 8 * sizeof(/*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__from_size_type ) - 1 - 5, 
  TransformAlarmC__4__MAX_DELAY = (/*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__to_size_type )1 << /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__MAX_DELAY_LOG2
};
#line 166
static inline void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__overflow(void );
# 41 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
uint32_t RandomMlcgC__seed[1000];


static inline error_t RandomMlcgC__Init__init(void );
# 67 "/opt/tinyos-2.x/tos/lib/tossim/heap.c"
static inline void init_heap(heap_t *heap)
#line 67
{
  heap->size = 0;
  heap->private_size = STARTING_SIZE;
  heap->data = malloc(sizeof(node_t ) * heap->private_size);
}

# 58 "/usr/include/secure/_string.h" 3
static __inline void *
__inline_memcpy_chk(void *__dest, const void *__src, size_t __len)
{
  return __builtin___memcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
}

# 119 "/opt/tinyos-2.x/tos/lib/tossim/heap.c"
static inline void expand_heap(heap_t *heap)
#line 119
{
  int new_size = heap->private_size * 2 + 1;
  void *new_data = malloc(sizeof(node_t ) * new_size);



  __builtin_object_size(new_data, 0) != (size_t )-1 ? __builtin___memcpy_chk(new_data, heap->data, sizeof(node_t ) * heap->private_size, __builtin_object_size(new_data, 0)) : __inline_memcpy_chk(new_data, heap->data, sizeof(node_t ) * heap->private_size);
  free(heap->data);

  heap->data = new_data;
  heap->private_size = new_size;
}


static inline void heap_insert(heap_t *heap, void *data, long long int key)
#line 133
{
  int findex = heap->size;

#line 135
  if (findex == heap->private_size) {
      expand_heap(heap);
    }

  findex = heap->size;
  ((node_t *)heap->data)[findex].key = key;
  ((node_t *)heap->data)[findex].data = data;
  up_heap(heap, findex);

  heap->size++;
}

#line 77
static inline int is_empty(heap_t *heap)
#line 77
{
  return heap->size == 0;
}

static inline int heap_is_empty(heap_t *heap)
#line 81
{
  return is_empty(heap);
}

static inline long long int heap_get_min_key(heap_t *heap)
#line 85
{
  if (is_empty(heap)) {
      return -1;
    }
  else {
      return ((node_t *)heap->data)[0].key;
    }
}

# 309 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
inline static int sim_log_eq(void *key1, void *key2)
#line 309
{
  return strcmp((char *)key1, (char *)key2) == 0;
}

#line 298
inline static unsigned int sim_log_hash(void *key)
#line 298
{
  char *str = (char *)key;
  unsigned int hashVal = 0;
  int hashChar;

  while ((hashChar = * str++)) 
    hashVal = hashChar + (hashVal << 6) + (hashVal << 16) - hashVal;

  return hashVal;
}

#line 151
static inline void sim_log_init()
#line 151
{
  int i;

  channelTable = create_hashtable(128, sim_log_hash, sim_log_eq);

  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      outputs[i].num = 1;
      outputs[i].files = (FILE **)malloc(sizeof(FILE *));
      outputs[i].files[0] = fdopen(1, "w");
    }
}

# 125 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
inline static unsigned int sim_noise_hash(void *key)
#line 125
{
  char *pt = (char *)key;
  unsigned int hashVal = 0;
  int i;

#line 129
  for (i = 0; i < NOISE_HISTORY; i++) {
      hashVal = pt[i] + (hashVal << 6) + (hashVal << 16) - hashVal;
    }
  return hashVal;
}

inline static int sim_noise_eq(void *key1, void *key2)
#line 135
{
  return memcmp((void *)key1, (void *)key2, NOISE_HISTORY) == 0;
}

# 110 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
static inline bool SimMoteP__SimMote__isOn(void )
#line 110
{
  return SimMoteP__isOn[sim_node()];
}

#line 273
static inline int *SimMoteP__SimMote__getTcpMsg(void )
#line 273
{
  return SimMoteP__tcp_msg[sim_node()];
}

# 80 "/usr/include/secure/_string.h" 3
static __inline void *
__inline_memset_chk(void *__dest, int __val, size_t __len)
{
  return __builtin___memset_chk(__dest, __val, __len, __builtin_object_size(__dest, 0));
}






static __inline char *
__inline_strcpy_chk(char *__dest, const char *__src)
{
  return __builtin___strcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
}

# 164 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
static inline void sim_log_add_channel(char *name, FILE *file)
#line 164
{
  sim_log_channel_t *channel;

#line 166
  channel = (sim_log_channel_t *)hashtable_search(channelTable, name);



  if (channel == (void *)0) {
      char *newName = (char *)malloc(strlen(name) + 1);

#line 172
      __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___strcpy_chk(newName, name, __builtin_object_size(newName, 2 > 1)) : __inline_strcpy_chk(newName, name);
      newName[strlen(name)] = 0;

      channel = (sim_log_channel_t *)malloc(sizeof(sim_log_channel_t ));
      channel->name = newName;
      channel->numOutputs = 0;
      channel->size = DEFAULT_CHANNEL_SIZE;
      channel->outputs = (FILE **)malloc(sizeof(FILE *) * channel->size);
      __builtin_object_size(channel->outputs, 0) != (size_t )-1 ? __builtin___memset_chk(channel->outputs, 0, sizeof(FILE *) * channel->size, __builtin_object_size(channel->outputs, 0)) : __inline_memset_chk(channel->outputs, 0, sizeof(FILE *) * channel->size);
      hashtable_insert(channelTable, newName, channel);
    }



  if (channel->numOutputs == channel->size) {
      FILE **newOutputs;
      int newSize = channel->size * 2;

      newOutputs = (FILE **)malloc(sizeof(FILE *) * newSize);
      __builtin_object_size(newOutputs, 0) != (size_t )-1 ? __builtin___memcpy_chk(newOutputs, channel->outputs, channel->size * sizeof(FILE **), __builtin_object_size(newOutputs, 0)) : __inline_memcpy_chk(newOutputs, channel->outputs, channel->size * sizeof(FILE **));

      free(channel->outputs);

      channel->outputs = newOutputs;
      channel->size = newSize;
    }

  channel->outputs[channel->numOutputs] = file;
  channel->numOutputs++;
  sim_log_commit_change();
}

static inline bool sim_log_remove_channel(char *output, FILE *file)
#line 204
{
  sim_log_channel_t *channel;
  int i;

#line 207
  channel = (sim_log_channel_t *)hashtable_search(channelTable, output);

  if (channel == (void *)0) {
      return FALSE;
    }


  for (i = 0; i < channel->numOutputs; i++) {
      FILE *f = channel->outputs[i];

#line 216
      if (file == f) {
          __builtin_object_size(&channel->outputs[i], 0) != (size_t )-1 ? __builtin___memcpy_chk(&channel->outputs[i], &channel->outputs[i + 1], channel->numOutputs - (i + 1), __builtin_object_size(&channel->outputs[i], 0)) : __inline_memcpy_chk(&channel->outputs[i], &channel->outputs[i + 1], channel->numOutputs - (i + 1));
          channel->outputs[channel->numOutputs - 1] = (void *)0;
          channel->numOutputs--;
        }
    }

  return TRUE;
}

# 162 "/opt/tinyos-2.x/tos/lib/tossim/sim_gain.c"
static inline gain_entry_t *sim_gain_allocate_link(int mote, int channel_id)
#line 162
{
  gain_entry_t *newLink = (gain_entry_t *)malloc(sizeof(gain_entry_t ));

#line 164
  newLink->next = (void *)0;
  newLink->mote = mote;
  newLink->channel = channel_id;
  newLink->gain = -10000000.0;
  return newLink;
}

# 55 "/opt/tinyos-2.x/tos/lib/tossim/randomlib.c"
static inline void RandomInitialise(int ij, int kl)
{
  double s;
#line 57
  double t;
  int ii;
#line 58
  int i;
#line 58
  int j;
#line 58
  int k;
#line 58
  int l;
#line 58
  int jj;
#line 58
  int m;






  if (((ij < 0 || ij > 31328) || kl < 0) || kl > 30081) {
      ij = 1802;
      kl = 9373;
    }

  i = ij / 177 % 177 + 2;
  j = ij % 177 + 2;
  k = kl / 169 % 178 + 1;
  l = kl % 169;

  for (ii = 0; ii < 97; ii++) {
      s = 0.0;
      t = 0.5;
      for (jj = 0; jj < 24; jj++) {
          m = i * j % 179 * k % 179;
          i = j;
          j = k;
          k = m;
          l = (53 * l + 1) % 169;
          if (l * m % 64 >= 32) {
            s += t;
            }
#line 86
          t *= 0.5;
        }
      randU[ii] = s;
    }

  randC = 362436.0 / 16777216.0;
  randCD = 7654321.0 / 16777216.0;
  randCM = 16777213.0 / 16777216.0;
  i97 = 97;
  j97 = 33;
  test = TRUE;
}

# 302 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
static inline void sim_noise_alarm()
#line 302
{
  dummy = 5;
}

# 42 "/opt/tinyos-2.x/tos/lib/tossim/sim_packet.c"
inline static tossim_header_t *getHeader(message_t *msg)
#line 42
{
  return (tossim_header_t *)(msg->data - sizeof(tossim_header_t ));
}

# 228 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC__active_message_deliver_handle(sim_event_t *evt)
#line 228
{
  message_t *m = (message_t *)evt->data;

#line 230
  sim_log_debug(169U, "Packet", "Delivering packet to %i at %s\n", (int )sim_node(), sim_time_string());
  TossimActiveMessageC__Model__receive(m);
}

static inline sim_event_t *TossimActiveMessageC__allocate_deliver_event(int node, message_t *msg, sim_time_t t)
#line 234
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 236
  evt->mote = node;
  evt->time = t;
  evt->handle = TossimActiveMessageC__active_message_deliver_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 0;
  evt->data = msg;
  return evt;
}

#line 181
static inline void *TossimActiveMessageC__Packet__getPayload(message_t *msg, uint8_t len)
#line 181
{
  if (len <= 156) {
      return msg->data;
    }
  else {
      return (void *)0;
    }
}

#line 177
static inline uint8_t TossimActiveMessageC__Packet__maxPayloadLength(void )
#line 177
{
  return 156;
}

#line 49
inline static am_addr_t TossimActiveMessageC__amAddress(void ){
#line 49
  unsigned short __nesc_result;
#line 49

#line 49
  __nesc_result = ActiveMessageAddressC__amAddress();
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
#line 128
static inline am_addr_t TossimActiveMessageC__AMPacket__address(void )
#line 128
{
  return TossimActiveMessageC__amAddress();
}

#line 152
static inline bool TossimActiveMessageC__AMPacket__isForMe(message_t *amsg)
#line 152
{
  return TossimActiveMessageC__AMPacket__destination(amsg) == TossimActiveMessageC__AMPacket__address() || 
  TossimActiveMessageC__AMPacket__destination(amsg) == AM_BROADCAST_ADDR;
}

# 286 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 286
{
  uint8_t *base = target;

#line 288
  base[0] = value;
  return value;
}

#line 281
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 281
{
  const uint8_t *base = source;

#line 283
  return base[0];
}

#line 310
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 310
{
  const uint8_t *base = source;

#line 312
  return ((uint16_t )base[0] << 8) | base[1];
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t AsyncReceiveAdapterP__receiveDone_task__postTask(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = SimSchedulerBasicP__TaskBasic__postTask(AsyncReceiveAdapterP__receiveDone_task);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 47 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
static inline void AsyncReceiveAdapterP__AsyncReceive__receive(message_t *msg, void *payload, uint8_t len)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      AsyncReceiveAdapterP__msg_[sim_node()] = msg;
      AsyncReceiveAdapterP__payload_[sim_node()] = payload;
      AsyncReceiveAdapterP__len_[sim_node()] = len;
    }
#line 54
    __nesc_atomic_end(__nesc_atomic); }
  AsyncReceiveAdapterP__receiveDone_task__postTask();
}

# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void PureTDMASchedulerP__Receive__receive(message_t * msg, void * payload, uint8_t len){
#line 41
  AsyncReceiveAdapterP__AsyncReceive__receive(msg, payload, len);
#line 41
}
#line 41
# 129 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline uint32_t GenericSlotterP__SlotterControl__getSlot(void )
#line 129
{
  return GenericSlotterP__slot[sim_node()];
}

# 39 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
inline static uint32_t PureTDMASchedulerP__SlotterControl__getSlot(void ){
#line 39
  unsigned int __nesc_result;
#line 39

#line 39
  __nesc_result = GenericSlotterP__SlotterControl__getSlot();
#line 39

#line 39
  return __nesc_result;
#line 39
}
#line 39
# 47 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
static inline uint8_t CC2420ControlP__CC2420Config__getChannel(void )
#line 47
{
#line 47
  return sim_mote_get_radio_channel(sim_node());
}

# 58 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static uint8_t PureTDMASchedulerP__CC2420Config__getChannel(void ){
#line 58
  unsigned char __nesc_result;
#line 58

#line 58
  __nesc_result = CC2420ControlP__CC2420Config__getChannel();
#line 58

#line 58
  return __nesc_result;
#line 58
}
#line 58
# 146 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static inline void */*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__getPayload(message_t *msg, uint8_t len)
#line 146
{
  return /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__getPayload(msg, len);
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void * PureTDMASchedulerP__SubSend__getPayload(message_t * msg, uint8_t len){
#line 71
  void *__nesc_result;
#line 71

#line 71
  __nesc_result = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__getPayload(msg, len);
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 879 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void *PureTDMASchedulerP__Send__getPayload(message_t *msg, uint8_t len)
#line 879
{
  return PureTDMASchedulerP__SubSend__getPayload(msg, len);
}

# 77 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static am_addr_t PureTDMASchedulerP__AMPacket__source(message_t * amsg){
#line 77
  unsigned short __nesc_result;
#line 77

#line 77
  __nesc_result = TossimActiveMessageC__AMPacket__source(amsg);
#line 77

#line 77
  return __nesc_result;
#line 77
}
#line 77
# 589 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__SubReceive__receive(message_t *msg, void *payload, uint8_t len)
#line 589
{
  unsigned char *__nesc_temp51;
  unsigned char __nesc_temp50;
  unsigned char *__nesc_temp49;
  unsigned char *__nesc_temp48;
  unsigned char __nesc_temp47;
  unsigned char *__nesc_temp46;
  unsigned char __nesc_temp45;
  unsigned char *__nesc_temp44;
#line 590
  am_addr_t src = PureTDMASchedulerP__AMPacket__source(msg);

#line 591
  PureTDMASchedulerP__rcmr[sim_node()] = (TestNetworkMsg *)payload;
  PureTDMASchedulerP__log_payload[sim_node()] = (TestNetworkMsg *)PureTDMASchedulerP__Send__getPayload(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));







  PureTDMASchedulerP__isChild[sim_node()] = 0;
  PureTDMASchedulerP__isParent[sim_node()] = 0;
  PureTDMASchedulerP__isSibling[sim_node()] = 0;



  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata); PureTDMASchedulerP__i[sim_node()]++) {

      if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) == __nesc_ntoh_uint16(PureTDMASchedulerP__log_payload[sim_node()]->children[PureTDMASchedulerP__i[sim_node()]].nxdata)) {
          PureTDMASchedulerP__isChild[sim_node()] = PureTDMASchedulerP__i[sim_node()] + 1;
        }
    }



  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata); PureTDMASchedulerP__i[sim_node()]++) {
      if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) == __nesc_ntoh_uint16(PureTDMASchedulerP__log_payload[sim_node()]->parents[PureTDMASchedulerP__i[sim_node()]].nxdata)) {
          PureTDMASchedulerP__isParent[sim_node()] = PureTDMASchedulerP__i[sim_node()] + 1;
        }
    }


  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalSiblings.nxdata); PureTDMASchedulerP__i[sim_node()]++) {
      if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) == __nesc_ntoh_uint16(PureTDMASchedulerP__log_payload[sim_node()]->siblings[PureTDMASchedulerP__i[sim_node()]].nxdata)) {
          PureTDMASchedulerP__isSibling[sim_node()] = PureTDMASchedulerP__i[sim_node()] + 1;
        }
      if (__nesc_ntoh_uint16(PureTDMASchedulerP__log_payload[sim_node()]->siblings[PureTDMASchedulerP__i[sim_node()]].nxdata) == TOS_NODE_ID % 500) {
          PureTDMASchedulerP__self_pos[sim_node()] = PureTDMASchedulerP__i[sim_node()];
        }
    }


  if (PureTDMASchedulerP__isChild[sim_node()] >= 1) {
      PureTDMASchedulerP__receiving_num[sim_node()] += 1;





      if (PureTDMASchedulerP__lp_intervals[sim_node()] == PureTDMASchedulerP__LP_SAMPLE_TIMES - 1) {

          printf("Child %d average link prob: %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata), __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->avg_link_prob.nxdata));
          __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata) + __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->avg_link_prob.nxdata));
        }



      PureTDMASchedulerP__rev_counter[sim_node()]++;


      if (__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata) == 1) {


          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__isChild[sim_node()] - 1].nxdata, 1);
          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__isChild[sim_node()] - 1].nxdata, 1);


          if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->self_data1.nxdata) > 0) {
              printf("primary parent %d merge child self data %d message\n", TOS_NODE_ID % 500, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_index[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_data[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->self_data1.nxdata));

              if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {
                  printf("Node %d source: %d\n", TOS_NODE_ID, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
                  if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) > 0 && __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) <= PureTDMASchedulerP__NUM_MEASUREMENTS) {
                      PureTDMASchedulerP__res_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) - 1] = __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata);
                      PureTDMASchedulerP__delay_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) - 1] = PureTDMASchedulerP__find_delay(PureTDMASchedulerP__SlotterControl__getSlot() % (PureTDMASchedulerP__TOTALNODES + 1));
                      printf("1----res_list: %d\n", PureTDMASchedulerP__res_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata) - 1]);

                      printf("1----%d %d %d %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata), PureTDMASchedulerP__SlotterControl__getSlot() % (PureTDMASchedulerP__TOTALNODES + 1), TOS_NODE_ID, PureTDMASchedulerP__CC2420Config__getChannel());
                    }
                }







              (__nesc_temp44 = PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, __nesc_hton_uint8(__nesc_temp44, (__nesc_temp45 = __nesc_ntoh_uint8(__nesc_temp44)) + 1), __nesc_temp45);
            }


          if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->curr_num.nxdata) > 0) {
              printf("primary parent %d merge child %d message\n", TOS_NODE_ID % 500, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
              for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->curr_num.nxdata); PureTDMASchedulerP__i[sim_node()]++) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_index[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata));
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_data[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_data[PureTDMASchedulerP__i[sim_node()]].nxdata));
                  (__nesc_temp46 = PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, __nesc_hton_uint8(__nesc_temp46, (__nesc_temp47 = __nesc_ntoh_uint8(__nesc_temp46)) + 1), __nesc_temp47);

                  if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {


                      printf("Node %d source: %d\n", TOS_NODE_ID, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
                      if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata) > 0 && __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata) <= PureTDMASchedulerP__NUM_MEASUREMENTS) {
                          PureTDMASchedulerP__res_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata) - 1] = __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata);

                          PureTDMASchedulerP__delay_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata) - 1] = PureTDMASchedulerP__find_delay(PureTDMASchedulerP__SlotterControl__getSlot() % (PureTDMASchedulerP__TOTALNODES + 1));
                        }
                    }
                }
            }
        }
      else 







        {


          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__isChild[sim_node()] - 1].nxdata, 1);
          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__isChild[sim_node()] - 1].nxdata, 0);

          if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->self_data1.nxdata) > 0) {

              __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].source.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
              __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].self_data1.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->self_data1.nxdata));
              __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].self_data2.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->self_data2.nxdata));
            }


          if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->curr_num.nxdata) > 0) {
              printf("neighbor number of data: %d saved data start: %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->curr_num.nxdata), __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].curr_num.nxdata));
              for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->curr_num.nxdata); PureTDMASchedulerP__i[sim_node()]++) {
                  printf("backup parent %d save child %d message\n", TOS_NODE_ID % 500, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->source.nxdata));
                  printf("saved index: %d, saved data: %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata), __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_data[PureTDMASchedulerP__i[sim_node()]].nxdata));
                  __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].merged_data[PureTDMASchedulerP__i[sim_node()]].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_data[PureTDMASchedulerP__i[sim_node()]].nxdata));
                  __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->merged_index[PureTDMASchedulerP__i[sim_node()]].nxdata));
                  (__nesc_temp48 = PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].curr_num.nxdata, __nesc_hton_uint8(__nesc_temp48, __nesc_ntoh_uint8(__nesc_temp48) + 1));
                }
              printf("merged %d data\n", __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__isChild[sim_node()] - 1].curr_num.nxdata));
            }
        }



      if (
#line 739
      TOS_NODE_ID != 1 && TOS_NODE_ID != 2 && TOS_NODE_ID != 3 && TOS_NODE_ID != 4 && TOS_NODE_ID != 5
       && TOS_NODE_ID != 6 && TOS_NODE_ID != 7 && TOS_NODE_ID != 8 && TOS_NODE_ID != 9) {
          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->self_data1.nxdata, 0);
        }
    }
  else {
    if (PureTDMASchedulerP__isParent[sim_node()] >= 1) {
      }
    else {




      if (PureTDMASchedulerP__isSibling[sim_node()] >= 1) {
#line 765
          PureTDMASchedulerP__rev_counter[sim_node()]++;



          for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata); PureTDMASchedulerP__i[sim_node()]++) {
              if (__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__i[sim_node()]].nxdata) == 1 && __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].handled_saved_data[PureTDMASchedulerP__i[sim_node()]].nxdata) == 0) {
                  if (PureTDMASchedulerP__isSibling[sim_node()] - 1 < PureTDMASchedulerP__self_pos[sim_node()]) {
                      if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata) == 1 || (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenReceive[PureTDMASchedulerP__i[sim_node()]].nxdata) == 1 && __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata) == 0)) {
                          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata, 1);
                          __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].handled_saved_data[PureTDMASchedulerP__i[sim_node()]].nxdata, 1);
                        }
                      else {
#line 775
                        if (__nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata) == 0 && __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenReceive[PureTDMASchedulerP__i[sim_node()]].nxdata) == 0 && PureTDMASchedulerP__self_pos[sim_node()] - (PureTDMASchedulerP__isSibling[sim_node()] - 1) == 1) {
                            __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata, 1);

                            __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].handled_saved_data[PureTDMASchedulerP__i[sim_node()]].nxdata, 1);

                            if (__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].self_data1.nxdata) > 0) {

                                __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_index[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata));
                                __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_data[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].self_data1.nxdata));
                                (__nesc_temp49 = PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, __nesc_hton_uint8(__nesc_temp49, (__nesc_temp50 = __nesc_ntoh_uint8(__nesc_temp49)) + 1), __nesc_temp50);



                                if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {
                                    if (__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata) > 0 && __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata) <= PureTDMASchedulerP__NUM_MEASUREMENTS) {
                                        PureTDMASchedulerP__res_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata) - 1] = __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata);
                                        PureTDMASchedulerP__delay_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].source.nxdata) - 1] = PureTDMASchedulerP__find_delay(PureTDMASchedulerP__SlotterControl__getSlot() % (PureTDMASchedulerP__TOTALNODES + 1));
                                      }
                                  }
                              }
#line 806
                            if (__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].curr_num.nxdata) > 0) {

                                for (PureTDMASchedulerP__j[sim_node()] = 0; PureTDMASchedulerP__j[sim_node()] < __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].curr_num.nxdata); PureTDMASchedulerP__j[sim_node()]++) {

                                    __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_index[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata));
                                    __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->merged_data[__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata)].nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_data[PureTDMASchedulerP__j[sim_node()]].nxdata));
                                    (__nesc_temp51 = PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, __nesc_hton_uint8(__nesc_temp51, __nesc_ntoh_uint8(__nesc_temp51) + 1));
                                    if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {

                                        if (__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata) > 0 && __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata) <= PureTDMASchedulerP__NUM_MEASUREMENTS) {
                                            PureTDMASchedulerP__res_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata) - 1] = __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata);
                                            PureTDMASchedulerP__delay_list[sim_node()][__nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].merged_index[PureTDMASchedulerP__j[sim_node()]].nxdata) - 1] = PureTDMASchedulerP__find_delay(PureTDMASchedulerP__SlotterControl__getSlot() % (PureTDMASchedulerP__TOTALNODES + 1));
                                          }
                                      }
                                  }
                              }
                          }
                        }
                    }
                }
              else {









                if (__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__i[sim_node()]].nxdata) == 0) {
                    if (PureTDMASchedulerP__isSibling[sim_node()] - 1 < PureTDMASchedulerP__self_pos[sim_node()] && __nesc_ntoh_uint8(PureTDMASchedulerP__rcmr[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata) == 1) {
                        __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__i[sim_node()]].nxdata, 1);
                      }
                  }
                }
            }
        }
      }
    }








  PureTDMASchedulerP__Receive__receive(msg, payload, len);
}

# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void BeaconSlotP__Receive__receive(message_t * msg, void * payload, uint8_t len){
#line 41
  PureTDMASchedulerP__SubReceive__receive(msg, payload, len);
#line 41
}
#line 41
# 17 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncReceiveAdapterP.nc"
static inline void SyncReceiveAdapterP__AsyncReceive__updateBuffer(message_t *msg)
{
  free(msg);
}

# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void BeaconSlotP__SubReceive__updateBuffer(message_t * msg){
#line 52
  SyncReceiveAdapterP__AsyncReceive__updateBuffer(msg);
#line 52
}
#line 52
# 31 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
inline static error_t BeaconSlotP__SlotterControl__synchronize(uint8_t toSlot){
#line 31
  unsigned char __nesc_result;
#line 31

#line 31
  __nesc_result = GenericSlotterP__SlotterControl__synchronize(toSlot);
#line 31

#line 31
  return __nesc_result;
#line 31
}
#line 31
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__get(void ){
#line 53
  unsigned int __nesc_result;
#line 53

#line 53
  __nesc_result = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__get();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 75 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__getNow(void )
{
  return /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__get();
}

#line 136
static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type dt)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] = t0;
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()] = dt;
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__set_alarm();
    }
#line 143
    __nesc_atomic_end(__nesc_atomic); }
}

static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__start(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type dt)
{
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__getNow(), dt);
}

# 55 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void BeaconSlotP__SyncAlarm__start(BeaconSlotP__SyncAlarm__size_type dt){
#line 55
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__start(dt);
#line 55
}
#line 55
# 340 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline  uint32_t __nesc_ntoh_uint32(const void * source)
#line 340
{
  const uint8_t *base = source;

#line 342
  return ((((uint32_t )base[0] << 24) | (
  (uint32_t )base[1] << 16)) | (
  (uint32_t )base[2] << 8)) | base[3];
}

# 63 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline uint32_t BeaconSlotP__read_timestamp(uint8_t *payload)
#line 63
{
  nx_uint32_t *ptr = (nx_uint32_t *)payload;

  return __nesc_ntoh_uint32((*ptr).nxdata);
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__stop(void ){
#line 62
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__stop();
#line 62
}
#line 62
# 91 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__stop(void )
{
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__stop();
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void GenericSlotterP__Alarm__stop(void ){
#line 62
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__stop();
#line 62
}
#line 62
# 116 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline void GenericSlotterP__SlotterControl__stop(void )
#line 116
{
  GenericSlotterP__Alarm__stop();
}

# 37 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
inline static void BeaconSlotP__SlotterControl__stop(void ){
#line 37
  GenericSlotterP__SlotterControl__stop();
#line 37
}
#line 37
# 136 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static am_id_t BeaconSlotP__AMPacket__type(message_t * amsg){
#line 136
  unsigned char __nesc_result;
#line 136

#line 136
  __nesc_result = TossimActiveMessageC__AMPacket__type(amsg);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 113 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline void BeaconSlotP__SubReceive__receive(message_t *msg, void *payload, uint8_t len)
#line 113
{
  uint32_t alarmTime;

  if (BeaconSlotP__AMPacket__type(msg) == SIMPLE_TDMA_SYNC) {
      BeaconSlotP__SlotterControl__stop();

      alarmTime = BeaconSlotP__read_timestamp(payload);
      if (alarmTime > 37) {
          alarmTime = alarmTime - 37;
          BeaconSlotP__SyncAlarm__start(alarmTime);
        }
      else {


          BeaconSlotP__SlotterControl__synchronize(1);
        }

      BeaconSlotP__SubReceive__updateBuffer(msg);
    }
  else 
#line 131
    {
      BeaconSlotP__Receive__receive(msg, payload, len);
    }
}

# 41 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void SyncReceiveAdapterP__AsyncReceive__receive(message_t * msg, void * payload, uint8_t len){
#line 41
  BeaconSlotP__SubReceive__receive(msg, payload, len);
#line 41
}
#line 41
# 8 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncReceiveAdapterP.nc"
static inline message_t *SyncReceiveAdapterP__Receive__receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
{
  message_t *duplicate = malloc(sizeof(message_t ));

#line 11
  __builtin_object_size(duplicate, 0) != (size_t )-1 ? __builtin___memcpy_chk(duplicate, msg, sizeof(message_t ), __builtin_object_size(duplicate, 0)) : __inline_memcpy_chk(duplicate, msg, sizeof(message_t ));

  SyncReceiveAdapterP__AsyncReceive__receive(duplicate, payload, len);
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC__Receive__receive(am_id_t arg_0x109b6ac18, message_t * msg, void * payload, uint8_t len){
#line 67
  nx_struct message_t *__nesc_result;
#line 67

#line 67
  __nesc_result = SyncReceiveAdapterP__Receive__receive(arg_0x109b6ac18, msg, payload, len);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 37 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline bool /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__isRunning(void )
{
  return /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[sim_node()] != (void *)0;
}

# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__get(void ){
#line 53
  unsigned short __nesc_result;
#line 53

#line 53
  __nesc_result = CounterMicro16P__Counter__get();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 62 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
static inline bool CounterMicro16P__Counter__isOverflowPending(void )
#line 62
{
#line 62
  return FALSE;
}

# 60 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static bool /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__isOverflowPending(void ){
#line 60
  unsigned char __nesc_result;
#line 60

#line 60
  __nesc_result = CounterMicro16P__Counter__isOverflowPending();
#line 60

#line 60
  return __nesc_result;
#line 60
}
#line 60
# 136 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline void BeaconSlotP__SyncAlarm__fired(void )
#line 136
{
  BeaconSlotP__SlotterControl__synchronize(1);
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__fired(void ){
#line 67
  BeaconSlotP__SyncAlarm__fired();
#line 67
}
#line 67
# 151 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__fired(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      if (/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()] == 0) 
        {
          /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Alarm__fired();
        }
      else 
        {
          /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__set_alarm();
        }
    }
#line 163
    __nesc_atomic_end(__nesc_atomic); }
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__fired(void ){
#line 67
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__fired();
#line 67
}
#line 67
# 19 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__handle_timer_fired(sim_event_t *e)
{
  if (e->cancelled) {
    return;
    }
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__fired();
}











static inline bool /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__isRunning(void )
{
  return /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[sim_node()] != (void *)0;
}

static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__stop(void )
{
  if (/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__isRunning()) 
    {
      /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[sim_node()]->cancelled = 1;
      /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[sim_node()]->cleanup = sim_queue_cleanup_total;

      /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[sim_node()] = (void *)0;
    }
}






static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__startAt(uint16_t t0, uint16_t dt)
{
  sim_event_t *newEvt;
  sim_time_t fireAt;

  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__stop();
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm[sim_node()] = t0 + dt;
  fireAt = /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[sim_node()] + (t0 + dt) * sim_ticks_per_sec() / 1024UL / 1024UL;





  newEvt = sim_queue_allocate_event();
  newEvt->handle = /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__handle_timer_fired;
  newEvt->cleanup = sim_queue_cleanup_none;
  newEvt->time = fireAt > sim_time() ? fireAt : sim_time();

  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[sim_node()] = newEvt;
  sim_queue_insert(newEvt);
}

# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__startAt(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__size_type t0, /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__size_type dt){
#line 92
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Alarm__startAt(t0, dt);
#line 92
}
#line 92
# 48 "/opt/tinyos-2.x/tos/lib/tossim/SimMote.nc"
inline static void PureTDMASchedulerP__SimMote__setTcpMsg(int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8){
#line 48
  SimMoteP__SimMote__setTcpMsg(root, flow0, flow1, flow2, flow3, flow4, flow5, flow6, flow7, flow8);
#line 48
}
#line 48
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t PureTDMASchedulerP__SubSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__send(msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 92 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static void PureTDMASchedulerP__AMPacket__setDestination(message_t * amsg, am_addr_t addr){
#line 92
  TossimActiveMessageC__AMPacket__setDestination(amsg, addr);
#line 92
}
#line 92
# 52 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static error_t PureTDMASchedulerP__CC2420Config__sync(void ){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = CC2420ControlP__CC2420Config__sync();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 48 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
static inline void CC2420ControlP__CC2420Config__setChannel(uint8_t ch)
#line 48
{
  CC2420ControlP__channel[sim_node()] = ch;
}

# 59 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static void PureTDMASchedulerP__CC2420Config__setChannel(uint8_t channel){
#line 59
  CC2420ControlP__CC2420Config__setChannel(channel);
#line 59
}
#line 59
# 315 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 315
{
  uint8_t *base = target;

#line 317
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

# 995 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__reset_parameters(void )
#line 995
{
  PureTDMASchedulerP__slotSize[sim_node()] = 10 * 32;






  PureTDMASchedulerP__bi[sim_node()] = 40000;
  PureTDMASchedulerP__sd[sim_node()] = 40000;
  PureTDMASchedulerP__cap[sim_node()] = 0;

  PureTDMASchedulerP__coordinatorId[sim_node()] = 0;
  PureTDMASchedulerP__init[sim_node()] = FALSE;
  PureTDMASchedulerP__toSend[sim_node()] = (void *)0;
  PureTDMASchedulerP__toSendLen[sim_node()] = 0;
  PureTDMASchedulerP__sync[sim_node()] = FALSE;
  PureTDMASchedulerP__requestStop[sim_node()] = FALSE;
  PureTDMASchedulerP__SimMote__setTcpMsg(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);


  PureTDMASchedulerP__readTopoFile();


  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__NUM_MEASUREMENTS; PureTDMASchedulerP__i[sim_node()]++) {
      PureTDMASchedulerP__res_list[sim_node()][PureTDMASchedulerP__i[sim_node()]] = 0;
    }




  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__NUM_MEASUREMENTS; PureTDMASchedulerP__i[sim_node()]++) {
      PureTDMASchedulerP__delay_list[sim_node()][PureTDMASchedulerP__i[sim_node()]] = PureTDMASchedulerP__CURRNODES[sim_node()];
    }


  PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__schedule_len[sim_node()]][PureTDMASchedulerP__MAXLEVELNODE[sim_node()] + 1];


  PureTDMASchedulerP__generateSchedule();

  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__MAXCHILDREN; PureTDMASchedulerP__i[sim_node()]++) {
      __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].curr_num.nxdata, 0);
      __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].handled_saved_data[PureTDMASchedulerP__i[sim_node()]].nxdata, 0);
    }


  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__schedule_len[sim_node()]; PureTDMASchedulerP__i[sim_node()]++) {
      for (PureTDMASchedulerP__j[sim_node()] = 1; PureTDMASchedulerP__j[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]; PureTDMASchedulerP__j[sim_node()]++) {
          if (TOS_NODE_ID == PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][PureTDMASchedulerP__j[sim_node()]]) {
              PureTDMASchedulerP__log_payload[sim_node()] = (TestNetworkMsg *)PureTDMASchedulerP__Send__getPayload(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));


              if (PureTDMASchedulerP__i[sim_node()] != 0) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][0]);
                  PureTDMASchedulerP__totalChildren[sim_node()] = __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata);
                  for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][0]; PureTDMASchedulerP__k[sim_node()]++) {
                      __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->children[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][PureTDMASchedulerP__k[sim_node()]]);

                      __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, 0);
                      __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, 0);
                    }
                }
              else 
#line 1057
                {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata, 0);
                }




              if (PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__schedule_len[sim_node()] - 1) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][0]);
                  PureTDMASchedulerP__totalParents[sim_node()] = __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata);
                  for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][0]; PureTDMASchedulerP__k[sim_node()]++) {
                      __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->parents[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][PureTDMASchedulerP__k[sim_node()]]);
                    }
                }
              else {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata, 0);
                }


              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalSiblings.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]);
              for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]; PureTDMASchedulerP__k[sim_node()]++) {
                  __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->siblings[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][PureTDMASchedulerP__k[sim_node()]]);
                }


              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->source.nxdata, TOS_NODE_ID);
              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, 0);








              if ((((((((
#line 1091
              TOS_NODE_ID == 1 || TOS_NODE_ID == 2) || TOS_NODE_ID == 3) || TOS_NODE_ID == 4) || TOS_NODE_ID == 5)
               || TOS_NODE_ID == 6) || TOS_NODE_ID == 7) || TOS_NODE_ID == 8) || TOS_NODE_ID == 9) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->self_data1.nxdata, TOS_NODE_ID * 10);
                }



              if (PureTDMASchedulerP__j[sim_node()] == 1) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata, 1);
                }
              else 
#line 1100
                {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata, 0);
                }
            }
        }
    }
}

# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t PureTDMASchedulerP__BeaconSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = BeaconSlotP__Send__send(msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 341 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__Slotter__slot(uint32_t slot)
#line 341
{
  unsigned char __nesc_temp43;
  unsigned char *__nesc_temp42;
#line 343
  message_t *tmpToSend;
  uint8_t tmpToSendLen;
  uint8_t i;
  uint8_t scounter;

  FILE *topo_update_log;
  int node_adjustment;
  int ret;
  int child_flag;



  if (TOS_NODE_ID == 169) {
    }


  if (slot == 0) {
      if (TOS_NODE_ID == 169) {
        }


      if (PureTDMASchedulerP__coordinatorId[sim_node()] == TOS_NODE_ID) {
          PureTDMASchedulerP__BeaconSend__send((void *)0, 0);
        }
      ;
      return;
    }

  if (slot < PureTDMASchedulerP__cap[sim_node()]) {
    }
  else 
#line 372
    {



      if (TOS_NODE_ID != 0 && slot % (PureTDMASchedulerP__TOTALNODES + 1) == 1 && PureTDMASchedulerP__flag[sim_node()] == 0) {
          if (PureTDMASchedulerP__coordinatorId[sim_node()] == TOS_NODE_ID) {
              PureTDMASchedulerP__BeaconSend__send((void *)0, 0);
            }
#line 379
          ;

          PureTDMASchedulerP__flag[sim_node()] = 1;


          PureTDMASchedulerP__CC2420Config__setChannel(22);
          PureTDMASchedulerP__CC2420Config__sync();
          PureTDMASchedulerP__AMPacket__setDestination(& PureTDMASchedulerP__m_entry[sim_node()].msg, AM_BROADCAST_ADDR);
          PureTDMASchedulerP__log_payload[sim_node()] = (TestNetworkMsg *)PureTDMASchedulerP__Send__getPayload(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));
          __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->source.nxdata, TOS_NODE_ID);
          PureTDMASchedulerP__SubSend__send(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));

          PureTDMASchedulerP__send_counter[sim_node()]++;


          printf("Node %d broadcast initialization messages successfully\n", TOS_NODE_ID % 500);
        }
      else {




        if (TOS_NODE_ID != 0 && slot % (PureTDMASchedulerP__TOTALNODES + 1) == 1 && PureTDMASchedulerP__flag[sim_node()] == 1) {


            PureTDMASchedulerP__reset_parameters();
            if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {
                for (i = 0; i < PureTDMASchedulerP__NUM_MEASUREMENTS; i++) {
                    printf("res_list: %d\n", PureTDMASchedulerP__res_list[sim_node()][i]);
                  }
              }
          }
        else {


          if (TOS_NODE_ID != 0 && slot % (PureTDMASchedulerP__TOTALNODES + 1) - 1 == TOS_NODE_ID) {

              PureTDMASchedulerP__lp_intervals[sim_node()]++;


              child_flag = 0;





              if (TOS_NODE_ID <= PureTDMASchedulerP__ROOT1 && TOS_NODE_ID != 1 && TOS_NODE_ID != 2 && TOS_NODE_ID != 3 && TOS_NODE_ID != 4 && TOS_NODE_ID != 5 && TOS_NODE_ID != 6) {

                  for (i = 0; i < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata); i++) {

                      if (__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[i].nxdata) == 0) {
                          (__nesc_temp42 = PureTDMASchedulerP__m_entry[sim_node()].prob_bit[i].nxdata, __nesc_hton_uint8(__nesc_temp42, (__nesc_temp43 = __nesc_ntoh_uint8(__nesc_temp42)) + 1), __nesc_temp43);
                        }
                      else 
                        {
                          child_flag++;
                        }

                      printf("node %d children prob_bit: %d\n", TOS_NODE_ID, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].prob_bit[i].nxdata));
                    }
                }



              if (PureTDMASchedulerP__lp_intervals[sim_node()] == PureTDMASchedulerP__LP_SAMPLE_TIMES && __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata) > 0 && TOS_NODE_ID > 6) {

                  for (i = 0; i < __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata); i++) {

                      PureTDMASchedulerP__avg_prob[sim_node()] = PureTDMASchedulerP__avg_prob[sim_node()] + __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].prob_bit[i].nxdata);
                    }


                  PureTDMASchedulerP__avg_prob[sim_node()] = (float )(PureTDMASchedulerP__avg_prob[sim_node()] * 100) / (float )(__nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata) * PureTDMASchedulerP__LP_SAMPLE_TIMES);

                  printf("Node %d self average probability is: %d\n", TOS_NODE_ID, PureTDMASchedulerP__avg_prob[sim_node()]);




                  if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {

                      __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->avg_link_prob.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata) / child_flag);
                    }
                  else {
#line 462
                    if (child_flag >= 1 && TOS_NODE_ID >= 14) {

                        __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata) / child_flag);

                        printf("Node %d children total average lost is %d, child_flag is: %d\n", TOS_NODE_ID, __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata), child_flag);

                        __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->avg_link_prob.nxdata, (PureTDMASchedulerP__avg_prob[sim_node()] + __nesc_ntoh_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata)) / 2);
                      }
                    else {
                        __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->avg_link_prob.nxdata, PureTDMASchedulerP__avg_prob[sim_node()]);
                      }
                    }

                  printf("Node %d current average link probability is: %d\n", TOS_NODE_ID, __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->avg_link_prob.nxdata));


                  PureTDMASchedulerP__avg_prob[sim_node()] = 0;
                  __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata, 0);
                }





              PureTDMASchedulerP__CC2420Config__setChannel(22);
              PureTDMASchedulerP__CC2420Config__sync();
              PureTDMASchedulerP__AMPacket__setDestination(& PureTDMASchedulerP__m_entry[sim_node()].msg, AM_BROADCAST_ADDR);









              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->source.nxdata, TOS_NODE_ID);

              PureTDMASchedulerP__SubSend__send(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));

              PureTDMASchedulerP__send_counter[sim_node()]++;
              printf("------------------------------------------Node %d broadcast messages successfully-------------------------------\n", TOS_NODE_ID);

              if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {
                  printf("ROOT1: %d\n", PureTDMASchedulerP__ROOT1);
                  printf("setTCPMSG 1: %d %d %d %d %d %d %d %d %d\n", PureTDMASchedulerP__res_list[sim_node()][0], PureTDMASchedulerP__res_list[sim_node()][1], PureTDMASchedulerP__res_list[sim_node()][2], PureTDMASchedulerP__res_list[sim_node()][3], PureTDMASchedulerP__res_list[sim_node()][4], PureTDMASchedulerP__res_list[sim_node()][5], PureTDMASchedulerP__res_list[sim_node()][6], PureTDMASchedulerP__res_list[sim_node()][7], PureTDMASchedulerP__res_list[sim_node()][8]);
                  PureTDMASchedulerP__SimMote__setTcpMsg(PureTDMASchedulerP__ROOT1, PureTDMASchedulerP__res_list[sim_node()][0], PureTDMASchedulerP__res_list[sim_node()][1], PureTDMASchedulerP__res_list[sim_node()][2], PureTDMASchedulerP__res_list[sim_node()][3], PureTDMASchedulerP__res_list[sim_node()][4], PureTDMASchedulerP__res_list[sim_node()][5], PureTDMASchedulerP__res_list[sim_node()][6], PureTDMASchedulerP__res_list[sim_node()][7], PureTDMASchedulerP__res_list[sim_node()][8]);

                  printf("delay list: %d %d %d %d %d %d %d %d %d\n", PureTDMASchedulerP__delay_list[sim_node()][0], PureTDMASchedulerP__delay_list[sim_node()][1], PureTDMASchedulerP__delay_list[sim_node()][2], PureTDMASchedulerP__delay_list[sim_node()][3], PureTDMASchedulerP__delay_list[sim_node()][4], PureTDMASchedulerP__delay_list[sim_node()][5], PureTDMASchedulerP__delay_list[sim_node()][6], PureTDMASchedulerP__delay_list[sim_node()][7], PureTDMASchedulerP__delay_list[sim_node()][8]);

                  PureTDMASchedulerP__delay_fp[sim_node()] = fopen("delay.txt", "a");

                  for (i = 0; i < PureTDMASchedulerP__NUM_MEASUREMENTS; i++) {
                      fprintf(PureTDMASchedulerP__delay_fp[sim_node()], "%d %d\n", i + 1, PureTDMASchedulerP__delay_list[sim_node()][i]);
                    }

                  fclose(PureTDMASchedulerP__delay_fp[sim_node()]);
                }
            }
          else {

            if (TOS_NODE_ID != 0 && slot % (PureTDMASchedulerP__TOTALNODES + 1) - 2 == PureTDMASchedulerP__ROOT1 && PureTDMASchedulerP__lp_intervals[sim_node()] == PureTDMASchedulerP__LP_SAMPLE_TIMES) {

                if (TOS_NODE_ID == PureTDMASchedulerP__ROOT1) {
                    printf("TIME TO LP_SAMPLE_TIMES!!!!! CURRENT AVERAGE LINK PROBABILITY IS %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->avg_link_prob.nxdata));
                  }



                for (i = 0; i < PureTDMASchedulerP__MAXCHILDREN; i++) {
                    __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].prob_bit[i].nxdata, 0);
                  }

                PureTDMASchedulerP__lp_intervals[sim_node()] = 0;
              }
            else {
#line 537
              if (TOS_NODE_ID != 0 && slot % (PureTDMASchedulerP__TOTALNODES + 1) - 2 == PureTDMASchedulerP__ROOT1 + 1 && PureTDMASchedulerP__lp_intervals[sim_node()] == PureTDMASchedulerP__TOPO_SAMPLE_TIMES) {
                }
              }
            }
          }
        }
    }
}

# 32 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/Slotter.nc"
inline static void GenericSlotterP__Slotter__slot(uint32_t num){
#line 32
  PureTDMASchedulerP__Slotter__slot(num);
#line 32
}
#line 32
# 10 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline tossim_header_t *SyncSendAdapterP__getHeader(message_t *msg)
{
  return & ((message_header_t *)msg->header)->tossim;
}

# 124 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * SyncSendAdapterP__AMSend__getPayload(am_id_t arg_0x109b386c0, message_t * msg, uint8_t len){
#line 124
  void *__nesc_result;
#line 124

#line 124
  __nesc_result = TossimActiveMessageC__AMSend__getPayload(arg_0x109b386c0, msg, len);
#line 124

#line 124
  return __nesc_result;
#line 124
}
#line 124
# 35 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline void *SyncSendAdapterP__AsyncSend__getPayload(message_t *msg, uint8_t len)
{
  return SyncSendAdapterP__AMSend__getPayload(__nesc_ntoh_uint8(SyncSendAdapterP__getHeader(msg)->type.nxdata), msg, len);
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void * SenderDispatcherP__SubSend__getPayload(message_t * msg, uint8_t len){
#line 71
  void *__nesc_result;
#line 71

#line 71
  __nesc_result = SyncSendAdapterP__AsyncSend__getPayload(msg, len);
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 94 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
static inline void *SenderDispatcherP__Send__getPayload(uint8_t slotType, message_t *msg, uint8_t len)
#line 94
{
  return SenderDispatcherP__SubSend__getPayload(msg, len);
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void * BeaconSlotP__SubSend__getPayload(message_t * msg, uint8_t len){
#line 71
  void *__nesc_result;
#line 71

#line 71
  __nesc_result = SenderDispatcherP__Send__getPayload(BEACON_SLOT, msg, len);
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__get(void ){
#line 53
  unsigned int __nesc_result;
#line 53

#line 53
  __nesc_result = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__get();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 75 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__getNow(void )
{
  return /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__get();
}

# 98 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static GenericSlotterP__Alarm__size_type GenericSlotterP__Alarm__getNow(void ){
#line 98
  unsigned int __nesc_result;
#line 98

#line 98
  __nesc_result = /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__getNow();
#line 98

#line 98
  return __nesc_result;
#line 98
}
#line 98
# 133 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline uint32_t GenericSlotterP__SlotterControl__getRemaining(void )
#line 133
{
  uint32_t now;
#line 134
  uint32_t diff;

#line 135
  now = GenericSlotterP__Alarm__getNow();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 136
    {
      if (GenericSlotterP__nextFire[sim_node()] > now) {
#line 137
        diff = GenericSlotterP__nextFire[sim_node()] - now;
        }
      else {
#line 138
        diff = 0;
        }
    }
#line 140
    __nesc_atomic_end(__nesc_atomic); }
#line 140
  return diff;
}

# 36 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
inline static uint32_t BeaconSlotP__SlotterControl__getRemaining(void ){
#line 36
  unsigned int __nesc_result;
#line 36

#line 36
  __nesc_result = GenericSlotterP__SlotterControl__getRemaining();
#line 36

#line 36
  return __nesc_result;
#line 36
}
#line 36
# 347 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline  uint32_t __nesc_hton_uint32(void * target, uint32_t value)
#line 347
{
  uint8_t *base = target;

#line 349
  base[3] = value;
  base[2] = value >> 8;
  base[1] = value >> 16;
  base[0] = value >> 24;
  return value;
}

# 57 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline void BeaconSlotP__write_timestamp(uint8_t *payload, uint32_t timestamp)
{
  nx_uint32_t *ptr = (nx_uint32_t *)payload;

#line 60
  __nesc_hton_uint32((*ptr).nxdata, timestamp);
}

# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t BeaconSlotP__SubSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = SenderDispatcherP__Send__send(BEACON_SLOT, msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 40 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC__GainRadioModel__putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double gain, double reverseGain, uint8_t channel_id){
#line 40
  CpmModelC__Model__putOnAirTo(dest, msg, ack, endTime, gain, reverseGain, channel_id);
#line 40
}
#line 40
# 224 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline int TossimPacketModelC__sim_packet_header_length(void )
#line 224
{
  return sizeof(tossim_header_t );
}

#line 79
static inline tossim_metadata_t *TossimPacketModelC__getMetadata(message_t *msg)
#line 79
{
  return (tossim_metadata_t *)& msg->metadata;
}

#line 270
static inline void TossimPacketModelC__send_transmit_with_cca_fake(sim_event_t *evt)
#line 270
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC__getMetadata(TossimPacketModelC__sending[sim_node()]);

#line 273
  duration = 8 * (TossimPacketModelC__sendingLength[sim_node()] + TossimPacketModelC__sim_packet_header_length());
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();
  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  evt->time += duration;
  evt->handle = TossimPacketModelC__send_transmit_done;

  TossimPacketModelC__GainRadioModel__putOnAirTo(66, TossimPacketModelC__sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0, sim_mote_get_radio_channel(sim_node()));
  __nesc_hton_uint8(metadata->ack.nxdata, 0);
  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());
  sim_queue_insert(evt);
}

# 49 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
inline static bool TossimPacketModelC__GainRadioModel__clearChannel(void ){
#line 49
  unsigned char __nesc_result;
#line 49

#line 49
  __nesc_result = CpmModelC__Model__clearChannel();
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 365 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__send_backoff_cancel_packet(sim_event_t *evt)
#line 365
{

  if (TossimPacketModelC__GainRadioModel__clearChannel()) {
      sim_time_t delay;
      message_t *rval = TossimPacketModelC__sending[sim_node()];

#line 370
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC__transmitting[sim_node()] = TRUE;
      evt->handle = TossimPacketModelC__send_transmit_with_cca;
      sim_queue_insert(evt);
    }
  else {
      sim_time_t delay;
      message_t *rval = TossimPacketModelC__sending[sim_node()];

#line 380
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC__transmitting[sim_node()] = TRUE;
      sim_mote_set_radio_channel(sim_node(), 20);

      evt->handle = TossimPacketModelC__send_transmit_with_cca_fake;
      sim_queue_insert(evt);
    }
}

# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void SyncSendAdapterP__AsyncSend__sendDone(message_t * msg, error_t error){
#line 48
  SenderDispatcherP__SubSend__sendDone(msg, error);
#line 48
}
#line 48
# 25 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline void SyncSendAdapterP__AMSend__sendDone(am_id_t id, message_t *msg, uint8_t len)
{
  SyncSendAdapterP__AsyncSend__sendDone(msg, len);
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void TossimActiveMessageC__AMSend__sendDone(am_id_t arg_0x109b6daf0, message_t * msg, error_t error){
#line 99
  SyncSendAdapterP__AMSend__sendDone(arg_0x109b6daf0, msg, error);
#line 99
}
#line 99
# 95 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC__Model__sendDone(message_t *msg, error_t result)
#line 95
{
  TossimActiveMessageC__AMSend__sendDone(TossimActiveMessageC__AMPacket__type(msg), msg, result);
}

# 71 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC__Packet__sendDone(message_t *msg, error_t error){
#line 71
  TossimActiveMessageC__Model__sendDone(msg, error);
#line 71
}
#line 71
# 326 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__send_backoff(sim_event_t *evt)
#line 326
{
  TossimPacketModelC__backoffCount[sim_node()]++;

  if (TossimPacketModelC__GainRadioModel__clearChannel()) {
      TossimPacketModelC__neededFreeSamples[sim_node()]--;
    }
  else {
      TossimPacketModelC__neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
    }

  if (TossimPacketModelC__neededFreeSamples[sim_node()] == 0) {
      message_t *rval = TossimPacketModelC__sending[sim_node()];
      sim_time_t delay;

#line 339
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC__transmitting[sim_node()] = TRUE;
      evt->handle = TossimPacketModelC__send_transmit_with_cca;
      sim_queue_insert(evt);
    }
  else {
    if (sim_csma_max_iterations() == 0 || TossimPacketModelC__backoffCount[sim_node()] <= sim_csma_max_iterations()) {
        sim_time_t backoff = sim_random();
        sim_time_t modulo = sim_csma_high() - sim_csma_low();

#line 350
        modulo *= pow(sim_csma_exponent_base(), TossimPacketModelC__backoffCount[sim_node()]);
        backoff %= modulo;
        backoff += sim_csma_init_low();
        backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
        evt->time += backoff;
        sim_queue_insert(evt);
      }
    else {
        message_t *rval = TossimPacketModelC__sending[sim_node()];

#line 359
        TossimPacketModelC__sending[sim_node()] = (void *)0;
        sim_log_debug(164U, "TossimPacketModelC", "PACKET: Failed to send packet due to busy channel.\n");
        TossimPacketModelC__Packet__sendDone(rval, EBUSY);
      }
    }
}

#line 228
static inline void TossimPacketModelC__send_transmit(sim_event_t *evt)
#line 228
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC__getMetadata(TossimPacketModelC__sending[sim_node()]);

#line 231
  duration = 8 * (TossimPacketModelC__sendingLength[sim_node()] + TossimPacketModelC__sim_packet_header_length());
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();
  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  evt->time += duration;
  evt->handle = TossimPacketModelC__send_transmit_done;

  sim_log_debug(158U, "TossimPacketModelC", "PACKET: Broadcasting packet to everyone.\n");
  TossimPacketModelC__GainRadioModel__putOnAirTo(TossimPacketModelC__destNode[sim_node()], TossimPacketModelC__sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0, sim_mote_get_radio_channel(sim_node()));
  __nesc_hton_uint8(metadata->ack.nxdata, 0);
  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());
  sim_log_debug(159U, "TossimPacketModelC", "PACKET: Send done at %llu.\n", evt->time);
  sim_queue_insert(evt);
}

#line 190
static inline void TossimPacketModelC__start_csma(void )
#line 190
{
  sim_time_t delay;

#line 192
  delay = sim_csma_rxtx_delay();
  delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  TossimPacketModelC__sendEvent[sim_node()].mote = sim_node();
  TossimPacketModelC__sendEvent[sim_node()].time = sim_time() + delay;
  TossimPacketModelC__sendEvent[sim_node()].force = 0;
  TossimPacketModelC__sendEvent[sim_node()].cancelled = 0;
  if (TossimPacketModelC__cca_enable_flag[sim_node()] == 0) {
      TossimPacketModelC__sendEvent[sim_node()].handle = TossimPacketModelC__send_transmit;
    }
  else {
#line 201
    if (TossimPacketModelC__cca_enable_flag[sim_node()] == 1) {
        sim_time_t backoff_random = sim_random();
        sim_time_t backoff = backoff_random;

        backoff %= 100;

        backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();

        TossimPacketModelC__sendEvent[sim_node()].time = sim_time() + backoff;
        TossimPacketModelC__sendEvent[sim_node()].handle = TossimPacketModelC__send_backoff;
      }
    else {
#line 211
      if (TossimPacketModelC__cca_enable_flag[sim_node()] == 2) {

          TossimPacketModelC__sendEvent[sim_node()].time = sim_time() + 2000000;
          TossimPacketModelC__sendEvent[sim_node()].handle = TossimPacketModelC__send_backoff_cancel_packet;
        }
      }
    }
  TossimPacketModelC__sendEvent[sim_node()].cleanup = sim_queue_cleanup_none;
  TossimPacketModelC__transmitting[sim_node()] = TRUE;

  sim_queue_insert(&TossimPacketModelC__sendEvent[sim_node()]);
}

#line 160
static inline error_t TossimPacketModelC__Packet__send(int dest, message_t *msg, uint8_t len)
#line 160
{
  if (!TossimPacketModelC__initialized[sim_node()]) {
      sim_log_error(156U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not initialized!\n");
      return EOFF;
    }
  if (!TossimPacketModelC__running[sim_node()]) {
      sim_log_error(157U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not running!\n");
      return EOFF;
    }

  if (TossimPacketModelC__sending[sim_node()] != (void *)0) {
      return EBUSY;
    }
  TossimPacketModelC__sendingLength[sim_node()] = len;
  TossimPacketModelC__sending[sim_node()] = msg;
  TossimPacketModelC__destNode[sim_node()] = dest;
  TossimPacketModelC__backoffCount[sim_node()] = 0;
  TossimPacketModelC__neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
  TossimPacketModelC__start_csma();

  return SUCCESS;
}

# 52 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
inline static error_t TossimActiveMessageC__Model__send(int node, message_t *msg, uint8_t len){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = TossimPacketModelC__Packet__send(node, msg, len);
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 57 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline tossim_header_t *TossimActiveMessageC__getHeader(message_t *amsg)
#line 57
{
  return (tossim_header_t *)(amsg->data - sizeof(tossim_header_t ));
}





static inline error_t TossimActiveMessageC__AMSend__send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len)
#line 67
{
  error_t err;
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 70
  sim_log_debug(165U, "AM", "AM: Sending packet (id=%hhu, len=%hhu) to %hu\n", id, len, addr);
  __nesc_hton_uint8(header->type.nxdata, id);
  __nesc_hton_uint16(header->dest.nxdata, addr);
  __nesc_hton_uint16(header->src.nxdata, TossimActiveMessageC__AMPacket__address());
  __nesc_hton_uint8(header->length.nxdata, len);
  err = TossimActiveMessageC__Model__send((int )addr, amsg, len + sizeof(tossim_header_t ));
  return err;
}

# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t SyncSendAdapterP__AMSend__send(am_id_t arg_0x109b386c0, am_addr_t addr, message_t * msg, uint8_t len){
#line 69
  unsigned char __nesc_result;
#line 69

#line 69
  __nesc_result = TossimActiveMessageC__AMSend__send(arg_0x109b386c0, addr, msg, len);
#line 69

#line 69
  return __nesc_result;
#line 69
}
#line 69
# 15 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline error_t SyncSendAdapterP__AsyncSend__send(message_t *msg, uint8_t len)
{
  return SyncSendAdapterP__AMSend__send(__nesc_ntoh_uint8(SyncSendAdapterP__getHeader(msg)->type.nxdata), __nesc_ntoh_uint16(SyncSendAdapterP__getHeader(msg)->dest.nxdata), msg, len);
}

# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t SenderDispatcherP__SubSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = SyncSendAdapterP__AsyncSend__send(msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 903 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__BeaconSend__sendDone(message_t *msg, error_t error)
#line 903
{
}

# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void BeaconSlotP__Send__sendDone(message_t * msg, error_t error){
#line 48
  PureTDMASchedulerP__BeaconSend__sendDone(msg, error);
#line 48
}
#line 48
# 93 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline void BeaconSlotP__SubSend__sendDone(message_t *msg, error_t error)
#line 93
{
  if (msg != &BeaconSlotP__syncPkt[sim_node()]) {
#line 94
    BeaconSlotP__Send__sendDone(msg, error);
    }
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t AsyncSendAdapterP__sendDone_task__postTask(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = SimSchedulerBasicP__TaskBasic__postTask(AsyncSendAdapterP__sendDone_task);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 58 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
static inline void AsyncSendAdapterP__AsyncSend__sendDone(message_t *msg, uint8_t len)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      AsyncSendAdapterP__msg_[sim_node()] = msg;
      AsyncSendAdapterP__len_[sim_node()] = len;
    }
#line 64
    __nesc_atomic_end(__nesc_atomic); }
  AsyncSendAdapterP__sendDone_task__postTask();
}

# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void PureTDMASchedulerP__Send__sendDone(message_t * msg, error_t error){
#line 48
  AsyncSendAdapterP__AsyncSend__sendDone(msg, error);
#line 48
}
#line 48
# 136 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static am_id_t PureTDMASchedulerP__AMPacket__type(message_t * amsg){
#line 136
  unsigned char __nesc_result;
#line 136

#line 136
  __nesc_result = TossimActiveMessageC__AMPacket__type(amsg);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 137 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC__PacketAcknowledgements__wasAcked(message_t *ack)
#line 137
{
  tossim_metadata_t *meta = TossimPacketModelC__getMetadata(ack);

  return __nesc_ntoh_uint8(meta->ack.nxdata);
}

# 74 "/opt/tinyos-2.x/tos/interfaces/PacketAcknowledgements.nc"
inline static bool PureTDMASchedulerP__PacketAcknowledgements__wasAcked(message_t * msg){
#line 74
  unsigned char __nesc_result;
#line 74

#line 74
  __nesc_result = TossimPacketModelC__PacketAcknowledgements__wasAcked(msg);
#line 74

#line 74
  return __nesc_result;
#line 74
}
#line 74
# 558 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__SubSend__sendDone(message_t *msg, error_t error)
#line 558
{
  uint32_t slot_at_send_done;
  uint8_t ack_at_send_done;

#line 561
  slot_at_send_done = PureTDMASchedulerP__SlotterControl__getSlot() % PureTDMASchedulerP__superframe_length[sim_node()];
  ack_at_send_done = PureTDMASchedulerP__PacketAcknowledgements__wasAcked(msg) ? 1 : 0;

  if (ack_at_send_done == 0) {
    }



  if (msg == & PureTDMASchedulerP__m_entry[sim_node()].msg) {
      if (PureTDMASchedulerP__AMPacket__type(msg) != PureTDMASchedulerP__SIMPLE_TDMA_SYNC) {
          PureTDMASchedulerP__Send__sendDone(msg, error);
        }
      else 
#line 572
        {
        }
    }
}

# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__sendDone(message_t * msg, error_t error){
#line 48
  PureTDMASchedulerP__SubSend__sendDone(msg, error);
#line 48
}
#line 48
# 134 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__sendDone(message_t *msg, error_t error)
#line 134
{
  if (/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()] == msg) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 136
        /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_END;
#line 136
        __nesc_atomic_end(__nesc_atomic); }
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 137
        /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()] = (void *)0;
#line 137
        __nesc_atomic_end(__nesc_atomic); }
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__sendDone(msg, error);
    }
}

# 121 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
static inline void SenderDispatcherP__Send__default__sendDone(uint8_t type, message_t *msg, error_t error)
#line 121
{
}

# 48 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void SenderDispatcherP__Send__sendDone(uint8_t arg_0x10975a6d8, message_t * msg, error_t error){
#line 48
  switch (arg_0x10975a6d8) {
#line 48
    case TDMA_SLOT:
#line 48
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__sendDone(msg, error);
#line 48
      break;
#line 48
    case BEACON_SLOT:
#line 48
      BeaconSlotP__SubSend__sendDone(msg, error);
#line 48
      break;
#line 48
    default:
#line 48
      SenderDispatcherP__Send__default__sendDone(arg_0x10975a6d8, msg, error);
#line 48
      break;
#line 48
    }
#line 48
}
#line 48
# 131 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline bool SimSchedulerBasicP__isWaiting(uint8_t id)
{
  return SimSchedulerBasicP__m_next[sim_node()][id] != SimSchedulerBasicP__NO_TASK || SimSchedulerBasicP__m_tail[sim_node()] == id;
}

static inline bool SimSchedulerBasicP__pushTask(uint8_t id)
{
  if (!SimSchedulerBasicP__isWaiting(id)) 
    {
      if (SimSchedulerBasicP__m_head[sim_node()] == SimSchedulerBasicP__NO_TASK) 
        {
          SimSchedulerBasicP__m_head[sim_node()] = id;
          SimSchedulerBasicP__m_tail[sim_node()] = id;
        }
      else 
        {
          SimSchedulerBasicP__m_next[sim_node()][SimSchedulerBasicP__m_tail[sim_node()]] = id;
          SimSchedulerBasicP__m_tail[sim_node()] = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

#line 61
static inline int SimSchedulerBasicP__sim_config_task_latency(void )
#line 61
{
#line 61
  return 100;
}

# 303 "/opt/nesc/lib/ncc/nesc_nx.h"
static __inline  int8_t __nesc_hton_int8(void * target, int8_t value)
#line 303
{
#line 303
  __nesc_hton_uint8(target, value);
#line 303
  return value;
}

# 636 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC__free_receive_message(CpmModelC__receive_message_t *msg)
#line 636
{
  free(msg);
}

# 53 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
inline static bool CpmModelC__Model__shouldAck(message_t *msg){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = TossimPacketModelC__GainRadioModel__shouldAck(msg);
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 79 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC__Packet__receive(message_t *msg){
#line 79
  TossimActiveMessageC__Model__receive(msg);
#line 79
}
#line 79
# 298 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__GainRadioModel__receive(message_t *msg)
#line 298
{
  if (TossimPacketModelC__running[sim_node()] && !TossimPacketModelC__transmitting[sim_node()]) {
      TossimPacketModelC__Packet__receive(msg);
    }
}

# 52 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC__Model__receive(message_t *msg){
#line 52
  TossimPacketModelC__GainRadioModel__receive(msg);
#line 52
}
#line 52
# 293 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC__checkReceive(CpmModelC__receive_message_t *msg)
#line 293
{
  double noise = CpmModelC__noise_hash_generation();

  FILE *fp;
  double coin = RandomUniform();


  CpmModelC__receive_message_t *list = CpmModelC__outstandingReceptionHead[sim_node()];
  int count = 0;

#line 302
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      sim_log_debug(128U, "CpmModelC", "checkReceive: outstanding from %d\n", list->source);
      count++;

      if (list->channel != sim_mote_get_radio_channel(sim_node())) {
          list = list->next;
          continue;
        }
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  sim_log_debug(129U, "CpmModelC", "checkReceive: outstanding count %d noise %lf at %lf\n", count, noise, (double )sim_time() / sim_ticks_per_sec());
  msg->lqi = sim_lqi_generate(msg->power - noise);

  fp = fopen("noise_record.txt", "a");
  fprintf(fp, "%d->%d: %f\n", msg->source, TOS_NODE_ID, noise);
  fclose(fp);
#line 395
  return CpmModelC__shouldReceive(msg->power - noise, 1);
}

#line 437
static inline void CpmModelC__sim_gain_receive_handle(sim_event_t *evt)
#line 437
{
  CpmModelC__receive_message_t *mine = (CpmModelC__receive_message_t *)evt->data;
  CpmModelC__receive_message_t *predecessor = (void *)0;
  CpmModelC__receive_message_t *list = CpmModelC__outstandingReceptionHead[sim_node()];

  sim_log_debug(132U, "CpmModelC", "Handling reception event @ %s.\n", sim_time_string());
  while (list != (void *)0) {
      if (list->next == mine) {
          predecessor = list;
        }
      list = list->next;
    }
  if (predecessor) {
      predecessor->next = mine->next;
    }
  else {
#line 452
    if (mine == CpmModelC__outstandingReceptionHead[sim_node()]) {
        CpmModelC__outstandingReceptionHead[sim_node()] = mine->next;
      }
    else {
        sim_log_error(133U, "CpmModelC", "Incoming packet list structure is corrupted: entry is not the head and no entry points to it.\n");
      }
    }
#line 458
  sim_log_debug(134U, "CpmModelC,SNRLoss", "Packet from %i to %i\n", (int )mine->source, (int )sim_node());
  if (!CpmModelC__checkReceive(mine)) {
      sim_log_debug(135U, "CpmModelC,SNRLoss", " - lost packet from %i as SNR was too low.\n", (int )mine->source);
      mine->lost = 1;
    }

  if (mine->channel != sim_mote_get_radio_channel(sim_node())) {
      CpmModelC__free_receive_message(mine);
      CpmModelC__receiving[sim_node()] = 0;
      return;
    }
  if (! mine->lost) {



      tossim_metadata_t *meta = (tossim_metadata_t *)& mine->msg->metadata;

#line 474
      __nesc_hton_int8(meta->strength.nxdata, mine->strength);
      __nesc_hton_uint8(meta->lqi.nxdata, mine->lqi);

      sim_log_debug_clear(136U, "CpmModelC,SNRLoss", "  -signaling reception\n");
      CpmModelC__Model__receive(mine->msg);
      if (mine->ack) {
          sim_log_debug_clear(137U, "CpmModelC", " acknowledgment requested, ");
          printf("ack requested\n");
        }
      else {
          sim_log_debug_clear(138U, "CpmModelC", " no acknowledgment requested.\n");
        }


      if (mine->ack && CpmModelC__Model__shouldAck(mine->msg)) {
          sim_log_debug_clear(139U, "CpmModelC", " scheduling ack.\n");
          CpmModelC__sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
        }
      else {

          CpmModelC__free_receive_message(mine);
        }

      CpmModelC__receiving[sim_node()] = 0;
    }
  else {
      if (RandomUniform() < 0.001) {
          sim_log_debug(140U, "CpmModelC,SNRLoss", "Packet was technically lost, but TOSSIM introduces an ack false positive rate.\n");

          if (mine->ack && CpmModelC__Model__shouldAck(mine->msg)) {
              sim_log_debug_clear(141U, "CpmModelC", " scheduling ack.\n");
              CpmModelC__sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
            }
          else {
              CpmModelC__free_receive_message(mine);
            }
        }
      else {
          CpmModelC__free_receive_message(mine);
        }
      CpmModelC__receiving[sim_node()] = 0;
      sim_log_debug_clear(142U, "CpmModelC,SNRLoss", "  -packet was lost.\n");
    }
}

#line 620
static inline sim_event_t *CpmModelC__allocate_receive_event(sim_time_t endTime, CpmModelC__receive_message_t *msg)
#line 620
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 622
  evt->mote = sim_node();
  evt->time = endTime;
  evt->handle = CpmModelC__sim_gain_receive_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 1;
  evt->data = msg;
  return evt;
}

static inline CpmModelC__receive_message_t *CpmModelC__allocate_receive_message(void )
#line 632
{
  return (CpmModelC__receive_message_t *)malloc(sizeof(CpmModelC__receive_message_t ));
}

#line 521
static inline void CpmModelC__enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower)
#line 521
{
  sim_event_t *evt;
  CpmModelC__receive_message_t *list;
  CpmModelC__receive_message_t *rcv = CpmModelC__allocate_receive_message();
  double noiseStr = CpmModelC__packetNoise(rcv);

#line 526
  rcv->source = source;
  rcv->start = sim_time();
  rcv->end = endTime;
  rcv->power = power;
  rcv->reversePower = reversePower;




  rcv->strength = (int8_t )floor(10.0 * log(pow(10.0, power / 10.0) + pow(10.0, noiseStr / 10.0)) / log(10.0));
  rcv->msg = msg;
  rcv->lost = 0;
  rcv->ack = receive;
  rcv->channel = sim_mote_get_radio_channel(source);





  if (!sim_mote_is_on(sim_node())) {
      sim_log_debug(143U, "CpmModelC", "Lost packet from %i due to %i being off\n", source, sim_node());

      rcv->lost = 1;
    }
  else {
#line 550
    if (!CpmModelC__shouldReceive(power - noiseStr, 0)) {
        sim_log_debug(144U, "CpmModelC,SNRLoss", "Lost packet from %i to %i due to SNR being too low (%i)\n", source, sim_node(), (int )(power - noiseStr));


        rcv->lost = 1;
      }
    else {
#line 556
      if (sim_mote_get_radio_channel(sim_node()) != sim_mote_get_radio_channel(source)) {

          rcv->lost = 1;
        }
      else {
#line 560
        if (CpmModelC__receiving[sim_node()]) {

            sim_log_debug(145U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-reception\n", source, sim_node());
            printf("Lost packet from %i due to %i being mid-reception\n", source, sim_node());

            rcv->lost = 1;
          }
        else {

            CpmModelC__receiving[sim_node()] = 1;
          }
        }
      }
    }
#line 572
  list = CpmModelC__outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      if (list->channel != sim_mote_get_radio_channel(source)) {
          list = list->next;
          continue;
        }
      if (!CpmModelC__shouldReceive(list->power - rcv->power, 0)) {
          sim_log_debug(146U, "Gain,SNRLoss", "Going to lose packet from %i with signal %lf as am receiving a packet from %i with signal %lf\n", list->source, list->power, source, rcv->power);
          list->lost = 1;
        }

      list = list->next;
    }

  rcv->next = CpmModelC__outstandingReceptionHead[sim_node()];
  CpmModelC__outstandingReceptionHead[sim_node()] = rcv;
  evt = CpmModelC__allocate_receive_event(endTime, rcv);
  sim_queue_insert(evt);
}


static inline void CpmModelC__sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower, int channel_id)
#line 593
{
  int prevNode = sim_node();

#line 595
  sim_log_debug(147U, "CpmModelC", "Enqueing reception event for %i at %llu with power %lf.\n", dest, endTime, power);
  sim_set_node(dest);
  CpmModelC__enqueue_receive_event(prevNode, endTime, msg, receive, power, reversePower);
  sim_set_node(prevNode);
}

#line 92
static inline double CpmModelC__timeInMs(void )
#line 92
{
  sim_time_t ftime = sim_time();
  int hours;
#line 94
  int minutes;
#line 94
  int seconds;
  sim_time_t secondBillionths;
  int temp_time;
  double ms_time;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }
  temp_time = (int )(secondBillionths / 10000);

  if (temp_time % 10 >= 5) {
      temp_time += 10 - temp_time % 10;
    }
  else {
      temp_time -= temp_time % 10;
    }
  ms_time = (float )(temp_time / 100.0);
  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;

  ms_time += (hours * 3600 + minutes * 60 + seconds) * 1000;

  return ms_time;
}

# 68 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
static inline uint8_t SimMoteP__SimMote__getRadioChannel(void )
{
  if (SimMoteP__radioChannel[sim_node()] < 11 || SimMoteP__radioChannel[sim_node()] > 26) {
      return 26;
    }

  return SimMoteP__radioChannel[sim_node()];
}

# 238 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC__prr_estimate_from_snr(double SNR)
#line 238
{
  double beta1 = 1.3687;
  double beta2 = 0.9187;
  double SNR_lin = pow(10.0, SNR / 10.0);
  double X = fabs(SNR_lin - beta2);
  double PSE = 0.5 * erfc(beta1 * sqrt(X / 2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 245
  sim_log_debug(126U, "CpmModelC", "SNR is %lf, PRR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1;
    }
  else {
#line 248
    if (prr_hat < 0) {
      prr_hat = 0;
      }
    }
#line 251
  return prr_hat;
}

# 119 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline bool TossimActiveMessageC__Model__shouldAck(message_t *msg)
#line 119
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(msg);

#line 121
  if (__nesc_ntoh_uint16(header->dest.nxdata) == TossimActiveMessageC__amAddress()) {
      sim_log_debug(168U, "Acks", "Received packet addressed to me so ack it\n");
      return TRUE;
    }
  return FALSE;
}

# 80 "/opt/tinyos-2.x/tos/lib/tossim/TossimPacketModel.nc"
inline static bool TossimPacketModelC__Packet__shouldAck(message_t *msg){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = TossimActiveMessageC__Model__shouldAck(msg);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 306 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__GainRadioModel__acked(message_t *msg)
#line 306
{
  if (TossimPacketModelC__running[sim_node()]) {
      tossim_metadata_t *metadata = TossimPacketModelC__getMetadata(TossimPacketModelC__sending[sim_node()]);

#line 309
      __nesc_hton_uint8(metadata->ack.nxdata, 1);
      if (msg != TossimPacketModelC__sending[sim_node()]) {
          TossimPacketModelC__error[sim_node()] = 1;
          sim_log_debug(163U, "TossimPacketModelC", "Requested ack for 0x%x, but outgoing packet is 0x%x.\n", msg, TossimPacketModelC__sending[sim_node()]);
        }
    }
}

# 51 "/opt/tinyos-2.x/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC__Model__acked(message_t *msg){
#line 51
  TossimPacketModelC__GainRadioModel__acked(msg);
#line 51
}
#line 51
# 155 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC__arr_estimate_from_snr(double SNR)
#line 155
{
  double beta1 = 1.3687;
  double beta2 = 0.9187;
  double SNR_lin = pow(10.0, SNR / 10.0);
  double X = fabs(SNR_lin - beta2);
  double PSE = 0.5 * erfc(beta1 * sqrt(X / 2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 162
  sim_log_debug(123U, "CpmModelC,SNRLoss", "SNR is %lf, ARR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1;
    }
  else {
#line 165
    if (prr_hat < 0) {
      prr_hat = 0;
      }
    }
#line 167
  return prr_hat;
}

static inline int CpmModelC__shouldAckReceive(double snr)
#line 170
{
  double prr = CpmModelC__arr_estimate_from_snr(snr);

  double coin = RandomUniform();

#line 174
  printf("randomUniform called again\n");
  if (prr != 0 && prr != 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 179
        prr = 0.0;
        }
    }
#line 181
  return (int )prr;
}

static inline void CpmModelC__sim_gain_ack_handle(sim_event_t *evt)
#line 184
{






  if (
#line 190
  CpmModelC__requestAck[sim_node()] && 
  CpmModelC__outgoing[sim_node()] != (void *)0 && 
  sim_mote_is_on(sim_node())) {
      CpmModelC__receive_message_t *rcv = (CpmModelC__receive_message_t *)evt->data;
      double power = rcv->reversePower;
      double noise = CpmModelC__packetNoise(rcv);
      double snr = power - noise;

#line 197
      if (CpmModelC__shouldAckReceive(snr)) {
          CpmModelC__Model__acked(CpmModelC__outgoing[sim_node()]);
        }
    }
  CpmModelC__free_receive_message((CpmModelC__receive_message_t *)evt->data);
}

# 55 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
static inline error_t SimMoteP__SimMote__setRadioChannel(uint8_t newRadioChannel)
{
  if (newRadioChannel >= 11 && newRadioChannel <= 26) {
      SimMoteP__radioChannel[sim_node()] = newRadioChannel;
      return SUCCESS;
    }

  return FAIL;
}

# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t CC2420ControlP__syncDoneTask__postTask(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = SimSchedulerBasicP__TaskBasic__postTask(CC2420ControlP__syncDoneTask);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__get(void ){
#line 53
  unsigned short __nesc_result;
#line 53

#line 53
  __nesc_result = /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__get();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 75 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__getNow(void )
{
  return /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__get();
}

#line 136
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type dt)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] = t0;
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()] = dt;
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__set_alarm();
    }
#line 143
    __nesc_atomic_end(__nesc_atomic); }
}

static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__start(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type dt)
{
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__getNow(), dt);
}

# 55 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__start(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__size_type dt){
#line 55
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__start(dt);
#line 55
}
#line 55
# 53 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__get(void ){
#line 53
  unsigned short __nesc_result;
#line 53

#line 53
  __nesc_result = CounterMicro16P__Counter__get();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53







inline static bool /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__isOverflowPending(void ){
#line 60
  unsigned char __nesc_result;
#line 60

#line 60
  __nesc_result = CounterMicro16P__Counter__isOverflowPending();
#line 60

#line 60
  return __nesc_result;
#line 60
}
#line 60
# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = SenderDispatcherP__Send__send(TDMA_SLOT, msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 68 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__alarm(uint8_t at)
#line 68
{
}

#line 119
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__fired(void )
#line 119
{
  uint8_t oldState;

  /* atomic removed: atomic calls only */
#line 122
  oldState = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()];
  if (oldState != /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_START) {
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__alarm(2);
    }
  /* atomic removed: atomic calls only */
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_OFFSET;
  if (/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__send(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()], /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[sim_node()]) != SUCCESS) {
      /* atomic removed: atomic calls only */
#line 129
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_END;
    }
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__fired(void ){
#line 67
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__fired();
#line 67
}
#line 67
# 151 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__fired(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      if (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()] == 0) 
        {
          /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Alarm__fired();
        }
      else 
        {
          /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__set_alarm();
        }
    }
#line 163
    __nesc_atomic_end(__nesc_atomic); }
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__fired(void ){
#line 67
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__fired();
#line 67
}
#line 67
# 19 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__handle_timer_fired(sim_event_t *e)
{
  if (e->cancelled) {
    return;
    }
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__fired();
}











static inline bool /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__isRunning(void )
{
  return /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[sim_node()] != (void *)0;
}

static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__stop(void )
{
  if (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__isRunning()) 
    {
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[sim_node()]->cancelled = 1;
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[sim_node()]->cleanup = sim_queue_cleanup_total;

      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[sim_node()] = (void *)0;
    }
}






static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__startAt(uint16_t t0, uint16_t dt)
{
  sim_event_t *newEvt;
  sim_time_t fireAt;

  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__stop();
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm[sim_node()] = t0 + dt;
  fireAt = /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[sim_node()] + (t0 + dt) * sim_ticks_per_sec() / 1024UL / 1024UL;





  newEvt = sim_queue_allocate_event();
  newEvt->handle = /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__handle_timer_fired;
  newEvt->cleanup = sim_queue_cleanup_none;
  newEvt->time = fireAt > sim_time() ? fireAt : sim_time();

  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[sim_node()] = newEvt;
  sim_queue_insert(newEvt);
}

# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__startAt(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__size_type t0, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__size_type dt){
#line 92
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Alarm__startAt(t0, dt);
#line 92
}
#line 92
# 136 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type t0, /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type dt)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] = t0;
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()] = dt;
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__set_alarm();
    }
#line 143
    __nesc_atomic_end(__nesc_atomic); }
}

static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__start(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type dt)
{
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__getNow(), dt);
}

# 55 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void GenericSlotterP__Alarm__start(GenericSlotterP__Alarm__size_type dt){
#line 55
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__start(dt);
#line 55
}
#line 55
#line 67
inline static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__fired(void ){
#line 67
  GenericSlotterP__Alarm__fired();
#line 67
}
#line 67
# 151 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__fired(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      if (/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()] == 0) 
        {
          /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Alarm__fired();
        }
      else 
        {
          /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__set_alarm();
        }
    }
#line 163
    __nesc_atomic_end(__nesc_atomic); }
}

# 67 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__fired(void ){
#line 67
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__fired();
#line 67
}
#line 67
# 19 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__handle_timer_fired(sim_event_t *e)
{
  if (e->cancelled) {
    return;
    }
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__fired();
}

#line 58
static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__startAt(uint16_t t0, uint16_t dt)
{
  sim_event_t *newEvt;
  sim_time_t fireAt;

  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__stop();
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm[sim_node()] = t0 + dt;
  fireAt = /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[sim_node()] + (t0 + dt) * sim_ticks_per_sec() / 1024UL / 1024UL;





  newEvt = sim_queue_allocate_event();
  newEvt->handle = /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__handle_timer_fired;
  newEvt->cleanup = sim_queue_cleanup_none;
  newEvt->time = fireAt > sim_time() ? fireAt : sim_time();

  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[sim_node()] = newEvt;
  sim_queue_insert(newEvt);
}

# 92 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__startAt(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__size_type t0, /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__size_type dt){
#line 92
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__startAt(t0, dt);
#line 92
}
#line 92
# 208 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC__Snoop__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 208
{
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC__Snoop__receive(am_id_t arg_0x109b697c0, message_t * msg, void * payload, uint8_t len){
#line 67
  nx_struct message_t *__nesc_result;
#line 67

#line 67
    __nesc_result = TossimActiveMessageC__Snoop__default__receive(arg_0x109b697c0, msg, payload, len);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 83 "/opt/tinyos-2.x/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_disable_interrupt()
#line 83
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] &= ~(1 << 7);
}






#line 91
__inline  __nesc_atomic_t 
__nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F];

#line 95
  __nesc_disable_interrupt();
  return result;
}



#line 100
__inline  void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F] = original_SREG;
}

# 77 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP__sim_scheduler_event_handle(sim_event_t *e)
#line 77
{
  SimSchedulerBasicP__sim_scheduler_event_pending[sim_node()] = FALSE;








  if (SimSchedulerBasicP__Scheduler__runNextTask()) {
      SimSchedulerBasicP__sim_scheduler_submit_event();
    }
}




static inline void SimSchedulerBasicP__sim_scheduler_event_init(sim_event_t *e)
#line 95
{
  e->mote = sim_node();
  e->force = 0;
  e->data = (void *)0;
  e->handle = SimSchedulerBasicP__sim_scheduler_event_handle;
  e->cleanup = sim_queue_cleanup_none;
}

#line 158
static inline void SimSchedulerBasicP__Scheduler__init(void )
{
  sim_log_debug(93U, "Scheduler", "Initializing scheduler.\n");
  /* atomic removed: atomic calls only */
  {
    __builtin_object_size(SimSchedulerBasicP__m_next[sim_node()], 0) != (size_t )-1 ? __builtin___memset_chk(SimSchedulerBasicP__m_next[sim_node()], SimSchedulerBasicP__NO_TASK, sizeof SimSchedulerBasicP__m_next[sim_node()], __builtin_object_size(SimSchedulerBasicP__m_next[sim_node()], 0)) : __inline_memset_chk(SimSchedulerBasicP__m_next[sim_node()], SimSchedulerBasicP__NO_TASK, sizeof SimSchedulerBasicP__m_next[sim_node()]);
    SimSchedulerBasicP__m_head[sim_node()] = SimSchedulerBasicP__NO_TASK;
    SimSchedulerBasicP__m_tail[sim_node()] = SimSchedulerBasicP__NO_TASK;

    SimSchedulerBasicP__sim_scheduler_event_pending[sim_node()] = FALSE;
    SimSchedulerBasicP__sim_scheduler_event_init(&SimSchedulerBasicP__sim_scheduler_event[sim_node()]);
  }
}

# 46 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static void SimMainP__Scheduler__init(void ){
#line 46
  SimSchedulerBasicP__Scheduler__init();
#line 46
}
#line 46
# 112 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline uint8_t SimSchedulerBasicP__popTask(void )
{
  if (SimSchedulerBasicP__m_head[sim_node()] != SimSchedulerBasicP__NO_TASK) 
    {
      uint8_t id = SimSchedulerBasicP__m_head[sim_node()];

#line 117
      SimSchedulerBasicP__m_head[sim_node()] = SimSchedulerBasicP__m_next[sim_node()][SimSchedulerBasicP__m_head[sim_node()]];
      if (SimSchedulerBasicP__m_head[sim_node()] == SimSchedulerBasicP__NO_TASK) 
        {
          SimSchedulerBasicP__m_tail[sim_node()] = SimSchedulerBasicP__NO_TASK;
        }
      SimSchedulerBasicP__m_next[sim_node()][id] = SimSchedulerBasicP__NO_TASK;
      return id;
    }
  else 
    {
      return SimSchedulerBasicP__NO_TASK;
    }
}

# 40 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
static inline tossim_header_t *AsyncReceiveAdapterP__getHeader(message_t *msg)
{
  return & ((message_header_t *)msg->header)->tossim;
}

# 67 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static am_addr_t TestNetworkC__AMPacket__destination(message_t * amsg){
#line 67
  unsigned short __nesc_result;
#line 67

#line 67
  __nesc_result = TossimActiveMessageC__AMPacket__destination(amsg);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67










inline static am_addr_t TestNetworkC__AMPacket__source(message_t * amsg){
#line 77
  unsigned short __nesc_result;
#line 77

#line 77
  __nesc_result = TossimActiveMessageC__AMPacket__source(amsg);
#line 77

#line 77
  return __nesc_result;
#line 77
}
#line 77
# 66 "TestNetworkC.nc"
static inline message_t *

TestNetworkC__Receive__receive(message_t *msg, void *payload, uint8_t len)
#line 68
{
  am_addr_t src = TestNetworkC__AMPacket__source(msg);
  am_addr_t dest = TestNetworkC__AMPacket__destination(msg);

#line 71
  TestNetworkC__rcmr[sim_node()] = (TestNetworkMsg *)payload;
  return msg;
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static void * AsyncSendAdapterP__AsyncSend__getPayload(message_t * msg, uint8_t len){
#line 71
  void *__nesc_result;
#line 71

#line 71
  __nesc_result = PureTDMASchedulerP__Send__getPayload(msg, len);
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 89 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
static inline void *AsyncSendAdapterP__AMSend__getPayload(am_id_t id, message_t *msg, uint8_t len)
{
  return AsyncSendAdapterP__AsyncSend__getPayload(msg, len);
}

# 124 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(am_id_t arg_0x109c0c488, message_t * msg, uint8_t len){
#line 124
  void *__nesc_result;
#line 124

#line 124
  __nesc_result = AsyncSendAdapterP__AMSend__getPayload(arg_0x109c0c488, msg, len);
#line 124

#line 124
  return __nesc_result;
#line 124
}
#line 124
# 203 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void */*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(uint8_t id, message_t *m, uint8_t len)
#line 203
{
  return /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(0, m, len);
}

# 114 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void * /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(message_t * msg, uint8_t len){
#line 114
  void *__nesc_result;
#line 114

#line 114
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(0U, msg, len);
#line 114

#line 114
  return __nesc_result;
#line 114
}
#line 114
# 65 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void */*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(message_t *m, uint8_t len)
#line 65
{
  return /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(m, len);
}

# 124 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * TestNetworkC__Send__getPayload(message_t * msg, uint8_t len){
#line 124
  void *__nesc_result;
#line 124

#line 124
  __nesc_result = /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(msg, len);
#line 124

#line 124
  return __nesc_result;
#line 124
}
#line 124
# 75 "TestNetworkC.nc"
static inline message_t *TestNetworkC__AMReceive__receive(message_t *bufPtr, void *payload, uint8_t len)
#line 75
{
  int i;
#line 76
  int j;

#line 77
  TestNetworkC__rcm[sim_node()] = (TestNetworkMsg *)payload;
  TestNetworkC__msgamr[sim_node()] = (TestNetworkMsg *)TestNetworkC__Send__getPayload(&TestNetworkC__packet[sim_node()], sizeof(TestNetworkMsg ));
  if (TestNetworkC__msgamr[sim_node()] == (void *)0) {
#line 79
      return;
    }
#line 80
  __nesc_hton_uint8(TestNetworkC__tnmsg_in_transit[sim_node()].self_data1.nxdata, __nesc_ntoh_uint8(TestNetworkC__rcm[sim_node()]->self_data1.nxdata));

  __builtin_object_size(TestNetworkC__msgamr[sim_node()], 0) != (size_t )-1 ? __builtin___memcpy_chk(TestNetworkC__msgamr[sim_node()], &TestNetworkC__tnmsg_in_transit[sim_node()], sizeof(TestNetworkMsg ), __builtin_object_size(TestNetworkC__msgamr[sim_node()], 0)) : __inline_memcpy_chk(TestNetworkC__msgamr[sim_node()], &TestNetworkC__tnmsg_in_transit[sim_node()], sizeof(TestNetworkMsg ));
  if (len != sizeof(TestNetworkMsg )) {
      return bufPtr;
    }
  return bufPtr;
}

# 77 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
static inline message_t *AsyncReceiveAdapterP__Receive__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 77
{
#line 77
  return msg;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * AsyncReceiveAdapterP__Receive__receive(am_id_t arg_0x109375020, message_t * msg, void * payload, uint8_t len){
#line 67
  nx_struct message_t *__nesc_result;
#line 67

#line 67
  switch (arg_0x109375020) {
#line 67
    case 5:
#line 67
      __nesc_result = TestNetworkC__AMReceive__receive(msg, payload, len);
#line 67
      __nesc_result = TestNetworkC__Receive__receive(msg, payload, len);
#line 67
      break;
#line 67
    default:
#line 67
      __nesc_result = AsyncReceiveAdapterP__Receive__default__receive(arg_0x109375020, msg, payload, len);
#line 67
      break;
#line 67
    }
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 140 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline void BeaconSlotP__Receive__updateBuffer(message_t *msg)
#line 140
{
#line 140
  return BeaconSlotP__SubReceive__updateBuffer(msg);
}

# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void PureTDMASchedulerP__SubReceive__updateBuffer(message_t * msg){
#line 52
  BeaconSlotP__Receive__updateBuffer(msg);
#line 52
}
#line 52
# 888 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__Receive__updateBuffer(message_t *msg)
#line 888
{
#line 888
  return PureTDMASchedulerP__SubReceive__updateBuffer(msg);
}

# 52 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncReceive.nc"
inline static void AsyncReceiveAdapterP__AsyncReceive__updateBuffer(message_t * msg){
#line 52
  PureTDMASchedulerP__Receive__updateBuffer(msg);
#line 52
}
#line 52
# 59 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncReceiveAdapterP.nc"
static inline void AsyncReceiveAdapterP__receiveDone_task__runTask(void )
{
  message_t *msg;
  void *payload;
  uint8_t len;

#line 64
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      msg = AsyncReceiveAdapterP__msg_[sim_node()];
      payload = AsyncReceiveAdapterP__payload_[sim_node()];
      len = AsyncReceiveAdapterP__len_[sim_node()];
    }
#line 69
    __nesc_atomic_end(__nesc_atomic); }


  AsyncReceiveAdapterP__AsyncReceive__updateBuffer(AsyncReceiveAdapterP__Receive__receive(__nesc_ntoh_uint8(AsyncReceiveAdapterP__getHeader(msg)->type.nxdata), msg, payload, len));
}

# 39 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
static inline tossim_header_t *AsyncSendAdapterP__getHeader(message_t *msg)
{
  return & ((message_header_t *)msg->header)->tossim;
}

# 181 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(am_id_t id, message_t *msg, error_t err)
#line 181
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] >= 1) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()]].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()], msg, err);
    }
  else {
      sim_log_debug(174U, "PointerBug", "%s received send done for %p, signaling for %p.\n", __FUNCTION__, msg, /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()]].msg);
    }
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void AsyncSendAdapterP__AMSend__sendDone(am_id_t arg_0x109376c00, message_t * msg, error_t error){
#line 99
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(arg_0x109376c00, msg, error);
#line 99
}
#line 99
# 69 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
static inline void AsyncSendAdapterP__sendDone_task__runTask(void )
{
  message_t *msg;
  uint8_t len;

#line 73
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      msg = AsyncSendAdapterP__msg_[sim_node()];
      len = AsyncSendAdapterP__len_[sim_node()];
    }
#line 77
    __nesc_atomic_end(__nesc_atomic); }


  AsyncSendAdapterP__AMSend__sendDone(__nesc_ntoh_uint8(AsyncSendAdapterP__getHeader(msg)->type.nxdata), msg, len);
}

# 52 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static error_t TestNetworkC__CC2420Config__sync(void ){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = CC2420ControlP__CC2420Config__sync();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 91 "TestNetworkC.nc"
static inline void TestNetworkC__CC2420Config__syncDone(error_t error)
#line 91
{
  if (error == SUCCESS) {
    }
  else 
#line 93
    {
      TestNetworkC__CC2420Config__sync();
    }
}

# 902 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__CC2420Config__syncDone(error_t error)
#line 902
{
}

# 53 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static void CC2420ControlP__CC2420Config__syncDone(error_t error){
#line 53
  PureTDMASchedulerP__CC2420Config__syncDone(error);
#line 53
  TestNetworkC__CC2420Config__syncDone(error);
#line 53
}
#line 53
# 36 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
static inline void CC2420ControlP__syncDoneTask__runTask(void )
#line 36
{
  CC2420ControlP__CC2420Config__syncDone(SUCCESS);
}

# 659 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC__ReadRssi__default__readDone(error_t error, uint16_t data)
#line 659
{
}

# 63 "/opt/tinyos-2.x/tos/interfaces/Read.nc"
inline static void CpmModelC__ReadRssi__readDone(error_t result, CpmModelC__ReadRssi__val_t val){
#line 63
  CpmModelC__ReadRssi__default__readDone(result, val);
#line 63
}
#line 63
# 640 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC__read_rssi_task__runTask(void )
{
  double noise = CpmModelC__packetNoise((void *)0);

#line 643
  CpmModelC__rssi[sim_node()] = FALSE;
  sim_log_debug(150U, "CpmModelC", "ReadRssi: noise %f\n", noise);


  CpmModelC__ReadRssi__readDone(SUCCESS, noise + 45);
}

# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PureTDMASchedulerP__SplitControl__startDone(error_t error){
#line 92
  TestNetworkC__RadioControl__startDone(error);
#line 92
}
#line 92
# 31 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/SlotterControl.nc"
inline static error_t PureTDMASchedulerP__SlotterControl__synchronize(uint8_t toSlot){
#line 31
  unsigned char __nesc_result;
#line 31

#line 31
  __nesc_result = GenericSlotterP__SlotterControl__synchronize(toSlot);
#line 31

#line 31
  return __nesc_result;
#line 31
}
#line 31
# 74 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline error_t GenericSlotterP__AsyncStdControl__start(void )
#line 74
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 75
    GenericSlotterP__nextFire[sim_node()] = GenericSlotterP__Alarm__getNow() + GenericSlotterP__slotLength[sim_node()];
#line 75
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 74 "/opt/tinyos-2.x/tos/interfaces/AsyncStdControl.nc"
inline static error_t PureTDMASchedulerP__GenericSlotter__start(void ){
#line 74
  unsigned char __nesc_result;
#line 74

#line 74
  __nesc_result = GenericSlotterP__AsyncStdControl__start();
#line 74

#line 74
  return __nesc_result;
#line 74
}
#line 74
# 313 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__RadioPowerControl__startDone(error_t error)
#line 313
{
  int i;

#line 315
  if (PureTDMASchedulerP__coordinatorId[sim_node()] == TOS_NODE_ID) {
      if (PureTDMASchedulerP__init[sim_node()] == FALSE) {
          PureTDMASchedulerP__SplitControl__startDone(error);
          PureTDMASchedulerP__GenericSlotter__start();
          PureTDMASchedulerP__SlotterControl__synchronize(0);
          PureTDMASchedulerP__init[sim_node()] = TRUE;
        }
    }
  else 
#line 322
    {
      if (PureTDMASchedulerP__init[sim_node()] == FALSE) {
          PureTDMASchedulerP__SplitControl__startDone(error);
          PureTDMASchedulerP__init[sim_node()] = TRUE;
        }
    }
}

# 36 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
inline static void SyncSendAdapterP__RadioPowerControl__startDone(error_t error){
#line 36
  PureTDMASchedulerP__RadioPowerControl__startDone(error);
#line 36
}
#line 36
# 42 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline void SyncSendAdapterP__SplitControl__startDone(error_t err)
#line 42
{
#line 42
  SyncSendAdapterP__RadioPowerControl__startDone(err);
}

# 92 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC__Control__startDone(error_t error){
#line 92
  SyncSendAdapterP__SplitControl__startDone(error);
#line 92
}
#line 92
# 93 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__startDoneTask__runTask(void )
#line 93
{
  TossimPacketModelC__running[sim_node()] = TRUE;
  TossimPacketModelC__Control__startDone(SUCCESS);
}

# 89 "TestNetworkC.nc"
static inline void TestNetworkC__RadioControl__stopDone(error_t err)
#line 89
{
}

# 117 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PureTDMASchedulerP__SplitControl__stopDone(error_t error){
#line 117
  TestNetworkC__RadioControl__stopDone(error);
#line 117
}
#line 117
# 330 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline void PureTDMASchedulerP__RadioPowerControl__stopDone(error_t error)
#line 330
{
  if (PureTDMASchedulerP__requestStop[sim_node()]) {

      PureTDMASchedulerP__requestStop[sim_node()] = FALSE;
      PureTDMASchedulerP__SplitControl__stopDone(error);
    }
}

# 42 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
inline static void SyncSendAdapterP__RadioPowerControl__stopDone(error_t error){
#line 42
  PureTDMASchedulerP__RadioPowerControl__stopDone(error);
#line 42
}
#line 42
# 43 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline void SyncSendAdapterP__SplitControl__stopDone(error_t err)
#line 43
{
#line 43
  SyncSendAdapterP__RadioPowerControl__stopDone(err);
}

# 117 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC__Control__stopDone(error_t error){
#line 117
  SyncSendAdapterP__SplitControl__stopDone(error);
#line 117
}
#line 117
# 98 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline void TossimPacketModelC__stopDoneTask__runTask(void )
#line 98
{
  TossimPacketModelC__running[sim_node()] = FALSE;
  TossimPacketModelC__Control__stopDone(SUCCESS);
}

#line 143
static inline void TossimPacketModelC__sendDoneTask__runTask(void )
#line 143
{
  message_t *msg = TossimPacketModelC__sending[sim_node()];
  tossim_metadata_t *meta = TossimPacketModelC__getMetadata(msg);

#line 146
  __nesc_hton_uint8(meta->ack.nxdata, 0);
  __nesc_hton_int8(meta->strength.nxdata, 0);
  __nesc_hton_uint16(meta->time.nxdata, 0);
  TossimPacketModelC__sending[sim_node()] = FALSE;
  TossimPacketModelC__Packet__sendDone(msg, TossimPacketModelC__running[sim_node()] ? SUCCESS : EOFF);
}

# 161 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void )
#line 161
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()], /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()]].msg, FAIL);
}

# 59 "TestNetworkC.nc"
static inline void TestNetworkC__Send__sendDone(message_t *m, error_t err)
#line 59
{
  if (err != SUCCESS) {
    }
#line 61
  TestNetworkC__sendBusy[sim_node()] = FALSE;
}

# 99 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(message_t * msg, error_t error){
#line 99
  TestNetworkC__Send__sendDone(msg, error);
#line 99
}
#line 99
# 57 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(message_t *m, error_t err)
#line 57
{
  /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(m, err);
}

# 207 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(uint8_t id, message_t *msg, error_t err)
#line 207
{
}

# 89 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(uint8_t arg_0x109c0e318, message_t * msg, error_t error){
#line 89
  switch (arg_0x109c0e318) {
#line 89
    case 0U:
#line 89
      /*TestNetworkAppC.Sender.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(msg, error);
#line 89
      break;
#line 89
    default:
#line 89
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(arg_0x109c0e318, msg, error);
#line 89
      break;
#line 89
    }
#line 89
}
#line 89
# 118 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void )
#line 118
{
  uint8_t i;
#line 119
  uint8_t j;
#line 119
  uint8_t mask;
#line 119
  uint8_t last;
  message_t *msg;

#line 121
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[sim_node()][i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[sim_node()][i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][last].msg = (void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[sim_node()][i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 213 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP__TaskBasic__default__runTask(uint8_t id)
{
}

# 64 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static void SimSchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x108f83960){
#line 64
  switch (arg_0x108f83960) {
#line 64
    case AsyncReceiveAdapterP__receiveDone_task:
#line 64
      AsyncReceiveAdapterP__receiveDone_task__runTask();
#line 64
      break;
#line 64
    case AsyncSendAdapterP__sendDone_task:
#line 64
      AsyncSendAdapterP__sendDone_task__runTask();
#line 64
      break;
#line 64
    case CC2420ControlP__syncDoneTask:
#line 64
      CC2420ControlP__syncDoneTask__runTask();
#line 64
      break;
#line 64
    case CpmModelC__read_rssi_task:
#line 64
      CpmModelC__read_rssi_task__runTask();
#line 64
      break;
#line 64
    case TossimPacketModelC__startDoneTask:
#line 64
      TossimPacketModelC__startDoneTask__runTask();
#line 64
      break;
#line 64
    case TossimPacketModelC__stopDoneTask:
#line 64
      TossimPacketModelC__stopDoneTask__runTask();
#line 64
      break;
#line 64
    case TossimPacketModelC__sendDoneTask:
#line 64
      TossimPacketModelC__sendDoneTask__runTask();
#line 64
      break;
#line 64
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask:
#line 64
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask();
#line 64
      break;
#line 64
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask:
#line 64
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask();
#line 64
      break;
#line 64
    default:
#line 64
      SimSchedulerBasicP__TaskBasic__default__runTask(arg_0x108f83960);
#line 64
      break;
#line 64
    }
#line 64
}
#line 64
#line 56
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = SimSchedulerBasicP__TaskBasic__postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 547 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline error_t PureTDMASchedulerP__Send__send(message_t *msg, uint8_t len)
#line 547
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 548
    {
      if (PureTDMASchedulerP__toSend[sim_node()] == (void *)0) {
          PureTDMASchedulerP__toSend[sim_node()] = msg;
          PureTDMASchedulerP__toSendLen[sim_node()] = len;
          {
            unsigned char __nesc_temp = 
#line 552
            SUCCESS;

            {
#line 552
              __nesc_atomic_end(__nesc_atomic); 
#line 552
              return __nesc_temp;
            }
          }
        }
    }
#line 556
    __nesc_atomic_end(__nesc_atomic); }
#line 555
  return FAIL;
}

# 40 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
inline static error_t AsyncSendAdapterP__AsyncSend__send(message_t * msg, uint8_t len){
#line 40
  unsigned char __nesc_result;
#line 40

#line 40
  __nesc_result = PureTDMASchedulerP__Send__send(msg, len);
#line 40

#line 40
  return __nesc_result;
#line 40
}
#line 40
# 46 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AsyncSendAdapterP.nc"
static inline error_t AsyncSendAdapterP__AMSend__send(am_id_t id, am_addr_t addr, message_t *msg, uint8_t len)
{
  __nesc_hton_uint16(AsyncSendAdapterP__getHeader(msg)->dest.nxdata, addr);
  __nesc_hton_uint8(AsyncSendAdapterP__getHeader(msg)->type.nxdata, id);
  return AsyncSendAdapterP__AsyncSend__send(msg, len);
}

# 69 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(am_id_t arg_0x109c0c488, am_addr_t addr, message_t * msg, uint8_t len){
#line 69
  unsigned char __nesc_result;
#line 69

#line 69
  __nesc_result = AsyncSendAdapterP__AMSend__send(arg_0x109c0c488, addr, msg, len);
#line 69

#line 69
  return __nesc_result;
#line 69
}
#line 69
# 169 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline uint8_t TossimActiveMessageC__Packet__payloadLength(message_t *msg)
#line 169
{
  return __nesc_ntoh_uint8(TossimActiveMessageC__getHeader(msg)->length.nxdata);
}

# 67 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(message_t * msg){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = TossimActiveMessageC__Packet__payloadLength(msg);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 67 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(message_t * amsg){
#line 67
  unsigned short __nesc_result;
#line 67

#line 67
  __nesc_result = TossimActiveMessageC__AMPacket__destination(amsg);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
#line 136
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(message_t * amsg){
#line 136
  unsigned char __nesc_result;
#line 136

#line 136
  __nesc_result = TossimActiveMessageC__AMPacket__type(amsg);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 57 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket(void )
#line 57
{
  uint8_t i;

#line 59
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()]].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 70
    /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] = 1;
    }
}

#line 166
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void )
#line 166
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()] < 1) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[sim_node()]].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(nextMsg);

#line 174
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask();
        }
    }
}

# 92 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline void GenericSlotterP__FrameConfiguration__setSlotLength(uint32_t slotTimeBms)
#line 92
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 93
    GenericSlotterP__slotLength[sim_node()] = slotTimeBms;
#line 93
    __nesc_atomic_end(__nesc_atomic); }
}

# 32 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/FrameConfiguration.nc"
inline static void PureTDMASchedulerP__FrameConfiguration__setSlotLength(uint32_t slotTimeBms){
#line 32
  GenericSlotterP__FrameConfiguration__setSlotLength(slotTimeBms);
#line 32
}
#line 32
# 100 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline void GenericSlotterP__FrameConfiguration__setFrameLength(uint32_t numSlots)
#line 100
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 101
    GenericSlotterP__frameLength[sim_node()] = numSlots;
#line 101
    __nesc_atomic_end(__nesc_atomic); }
}

# 38 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/FrameConfiguration.nc"
inline static void PureTDMASchedulerP__FrameConfiguration__setFrameLength(uint32_t numSlots){
#line 38
  GenericSlotterP__FrameConfiguration__setFrameLength(numSlots);
#line 38
}
#line 38
# 56 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TossimPacketModelC__startDoneTask__postTask(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = SimSchedulerBasicP__TaskBasic__postTask(TossimPacketModelC__startDoneTask);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 103 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC__Control__start(void )
#line 103
{
  if (!TossimPacketModelC__initialized[sim_node()]) {
      sim_log_error(152U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called before initialization!\n");
      return FAIL;
    }
  sim_log_debug(153U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called.\n");
  TossimPacketModelC__startDoneTask__postTask();
  return SUCCESS;
}

# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t SyncSendAdapterP__SplitControl__start(void ){
#line 83
  unsigned char __nesc_result;
#line 83

#line 83
  __nesc_result = TossimPacketModelC__Control__start();
#line 83

#line 83
  return __nesc_result;
#line 83
}
#line 83
# 40 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/SyncSendAdapterP.nc"
static inline error_t SyncSendAdapterP__RadioPowerControl__start(void )
#line 40
{
#line 40
  return SyncSendAdapterP__SplitControl__start();
}

# 35 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/RadioPowerControl.nc"
inline static error_t PureTDMASchedulerP__RadioPowerControl__start(void ){
#line 35
  unsigned char __nesc_result;
#line 35

#line 35
  __nesc_result = SyncSendAdapterP__RadioPowerControl__start();
#line 35

#line 35
  return __nesc_result;
#line 35
}
#line 35
# 59 "/opt/tinyos-2.x/tos/chips/cc2420/interfaces/CC2420Config.nc"
inline static void TestNetworkC__CC2420Config__setChannel(uint8_t channel){
#line 59
  CC2420ControlP__CC2420Config__setChannel(channel);
#line 59
}
#line 59
# 42 "/opt/tinyos-2.x/tos/platforms/mica/PlatformP.nc"
static inline void PlatformP__power_init(void )
#line 42
{
  /* atomic removed: atomic calls only */
#line 43
  {
    * (volatile uint8_t *)&atm128RegFile[sim_node()][0x35] = 1 << SE;
  }
}

# 58 "/opt/tinyos-2.x/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 13 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline error_t /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Init__init(void )
{
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[sim_node()] = sim_time();
  return SUCCESS;
}

# 30 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
static inline error_t CounterMicro16P__Init__init(void )
{
  CounterMicro16P__t0[sim_node()] = sim_time();
  CounterMicro16P__scheduleOverflow();
  return SUCCESS;
}

# 13 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline error_t /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Init__init(void )
{
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[sim_node()] = sim_time();
  return SUCCESS;
}

#line 13
static inline error_t /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Init__init(void )
{
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[sim_node()] = sim_time();
  return SUCCESS;
}

#line 13
static inline error_t /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Init__init(void )
{
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[sim_node()] = sim_time();
  return SUCCESS;
}

#line 13
static inline error_t /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Init__init(void )
{
  /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[sim_node()] = sim_time();
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t MotePlatformP__SubInit__init(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Init__init();
#line 51
  __nesc_result = ecombine(__nesc_result, /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, CounterMicro16P__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Init__init());
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 50 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__clr(void )
#line 50
{
#line 50
  atm128RegFile[sim_node()][27U] &= ~(1 << 4);
}

# 30 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP__SerialIdPin__clr(void ){
#line 30
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__clr();
#line 30
}
#line 30
# 53 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__makeInput(void )
#line 53
{
#line 53
  atm128RegFile[sim_node()][26U] &= ~(1 << 4);
}

# 33 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP__SerialIdPin__makeInput(void ){
#line 33
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP__4__IO__makeInput();
#line 33
}
#line 33
# 26 "/opt/tinyos-2.x/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP__PlatformInit__init(void )
#line 26
{

  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x15] = 0;
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x14] = 0xff;


  MotePlatformP__SerialIdPin__makeInput();
  MotePlatformP__SerialIdPin__clr();

  return MotePlatformP__SubInit__init();
}

# 46 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__set(void )
#line 46
{
  sim_log_debug(44U, "Pins", "Setting bit %i of port %i.\n", (int )0, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 0;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led2__set(void ){
#line 29
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__set();
#line 29
}
#line 29
# 46 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__set(void )
#line 46
{
  sim_log_debug(45U, "Pins", "Setting bit %i of port %i.\n", (int )1, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 1;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led1__set(void ){
#line 29
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__set();
#line 29
}
#line 29
# 46 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__set(void )
#line 46
{
  sim_log_debug(46U, "Pins", "Setting bit %i of port %i.\n", (int )2, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 2;
}

# 29 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led0__set(void ){
#line 29
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__set();
#line 29
}
#line 29
# 54 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void )
#line 54
{
#line 54
  atm128RegFile[sim_node()][26U] |= 1 << 0;
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led2__makeOutput(void ){
#line 35
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput();
#line 35
}
#line 35
# 54 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void )
#line 54
{
#line 54
  atm128RegFile[sim_node()][26U] |= 1 << 1;
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led1__makeOutput(void ){
#line 35
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput();
#line 35
}
#line 35
# 54 "/opt/tinyos-2.x/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void )
#line 54
{
#line 54
  atm128RegFile[sim_node()][26U] |= 1 << 2;
}

# 35 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led0__makeOutput(void ){
#line 35
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput();
#line 35
}
#line 35
# 45 "/opt/tinyos-2.x/tos/system/LedsP.nc"
static inline error_t LedsP__Init__init(void )
#line 45
{
  /* atomic removed: atomic calls only */
#line 46
  {
    sim_log_debug(109U, "Init", "LEDS: initialized.\n");
    LedsP__Led0__makeOutput();
    LedsP__Led1__makeOutput();
    LedsP__Led2__makeOutput();
    LedsP__Led0__set();
    LedsP__Led1__set();
    LedsP__Led2__set();
  }
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__MoteInit__init(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = LedsP__Init__init();
#line 51
  __nesc_result = ecombine(__nesc_result, MotePlatformP__PlatformInit__init());
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 21 "/opt/tinyos-2.x/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC__Init__init(void )
#line 21
{
  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__MeasureClock__init(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = MeasureClockC__Init__init();
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 49 "/opt/tinyos-2.x/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP__Init__init(void )
{
  error_t ok;


  ok = PlatformP__MeasureClock__init();
  ok = ecombine(ok, PlatformP__MoteInit__init());

  if (ok != SUCCESS) {
    return ok;
    }
  PlatformP__power_init();

  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t SimMainP__PlatformInit__init(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = PlatformP__Init__init();
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 80 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__overflow(void )
{
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[sim_node()] = sim_time();
}

# 166 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__overflow(void )
{
}

# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__overflow(void ){
#line 71
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__overflow();
#line 71
}
#line 71
# 122 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static inline void /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__overflow(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[sim_node()]++;
      if ((/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[sim_node()] & /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__OVERFLOW_MASK) == 0) {
        /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__overflow();
        }
    }
#line 130
    __nesc_atomic_end(__nesc_atomic); }
}

# 80 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__overflow(void )
{
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[sim_node()] = sim_time();
}

# 166 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__overflow(void )
{
}

#line 166
static inline void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__overflow(void )
{
}

#line 166
static inline void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__overflow(void )
{
}

#line 166
static inline void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__overflow(void )
{
}

# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__overflow(void ){
#line 71
  /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__4__Counter__overflow();
#line 71
  /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Counter__overflow();
#line 71
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__overflow();
#line 71
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__overflow();
#line 71
}
#line 71
# 122 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static inline void /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__overflow(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[sim_node()]++;
      if ((/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[sim_node()] & /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__OVERFLOW_MASK) == 0) {
        /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__overflow();
        }
    }
#line 130
    __nesc_atomic_end(__nesc_atomic); }
}

# 80 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline void /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__overflow(void )
{
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[sim_node()] = sim_time();
}

#line 80
static inline void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__overflow(void )
{
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[sim_node()] = sim_time();
}

#line 80
static inline void /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__overflow(void )
{
  /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[sim_node()] = sim_time();
}

# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void CounterMicro16P__Counter__overflow(void ){
#line 71
  /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__Counter__overflow();
#line 71
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Counter__overflow();
#line 71
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__Counter__overflow();
#line 71
  /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__overflow();
#line 71
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Counter__overflow();
#line 71
  /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__overflow();
#line 71
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__Counter__overflow();
#line 71
}
#line 71
# 48 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
static inline void CounterMicro16P__handleOverflow(sim_event_t *evt)
{
  CounterMicro16P__t0[sim_node()] = sim_time();
  CounterMicro16P__scheduleOverflow();
  CounterMicro16P__Counter__overflow();
}

# 54 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static bool SimMainP__Scheduler__runNextTask(void ){
#line 54
  unsigned char __nesc_result;
#line 54

#line 54
  __nesc_result = SimSchedulerBasicP__Scheduler__runNextTask();
#line 54

#line 54
  return __nesc_result;
#line 54
}
#line 54
# 83 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC__Init__init(void )
#line 83
{
  sim_log_debug(151U, "TossimPacketModelC", "TossimPacketModelC: Init.init() called\n");
  TossimPacketModelC__initialized[sim_node()] = TRUE;



  TossimPacketModelC__sendEvent[sim_node()].cancelled = 1;
  return SUCCESS;
}

# 173 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static inline error_t PureTDMASchedulerP__Init__init(void )
#line 173
{

  PureTDMASchedulerP__slotSize[sim_node()] = 10 * 32;






  PureTDMASchedulerP__bi[sim_node()] = 40000;
  PureTDMASchedulerP__sd[sim_node()] = 40000;
  PureTDMASchedulerP__cap[sim_node()] = 0;

  PureTDMASchedulerP__coordinatorId[sim_node()] = 0;
  PureTDMASchedulerP__init[sim_node()] = FALSE;
  PureTDMASchedulerP__toSend[sim_node()] = (void *)0;
  PureTDMASchedulerP__toSendLen[sim_node()] = 0;
  PureTDMASchedulerP__sync[sim_node()] = FALSE;
  PureTDMASchedulerP__requestStop[sim_node()] = FALSE;
  PureTDMASchedulerP__SimMote__setTcpMsg(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

  PureTDMASchedulerP__readTopoFile();

  PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__schedule_len[sim_node()]][PureTDMASchedulerP__MAXLEVELNODE[sim_node()] + 1];

  PureTDMASchedulerP__generateSchedule();



  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__NUM_MEASUREMENTS; PureTDMASchedulerP__i[sim_node()]++) {
      PureTDMASchedulerP__delay_list[sim_node()][PureTDMASchedulerP__i[sim_node()]] = PureTDMASchedulerP__CURRNODES[sim_node()];
    }



  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__MAXCHILDREN; PureTDMASchedulerP__i[sim_node()]++) {
      __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].saved_data[PureTDMASchedulerP__i[sim_node()]].curr_num.nxdata, 0);
      __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].handled_saved_data[PureTDMASchedulerP__i[sim_node()]].nxdata, 0);
    }


  __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].avg_prob.nxdata, 0);

  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__MAXCHILDREN; PureTDMASchedulerP__i[sim_node()]++) {
      __nesc_hton_uint8(PureTDMASchedulerP__m_entry[sim_node()].prob_bit[PureTDMASchedulerP__i[sim_node()]].nxdata, 0);
    }

  PureTDMASchedulerP__log_payload[sim_node()] = (TestNetworkMsg *)PureTDMASchedulerP__Send__getPayload(& PureTDMASchedulerP__m_entry[sim_node()].msg, sizeof(TestNetworkMsg ));

  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata, 0);
  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalSiblings.nxdata, 0);
  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata, 0);

  for (PureTDMASchedulerP__i[sim_node()] = 0; PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__schedule_len[sim_node()]; PureTDMASchedulerP__i[sim_node()]++) {
      for (PureTDMASchedulerP__j[sim_node()] = 1; PureTDMASchedulerP__j[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]; PureTDMASchedulerP__j[sim_node()]++) {
          if (TOS_NODE_ID == PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][PureTDMASchedulerP__j[sim_node()]]) {



              if (PureTDMASchedulerP__i[sim_node()] != 0) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][0]);
                  PureTDMASchedulerP__totalChildren[sim_node()] = __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata);
                  for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][0]; PureTDMASchedulerP__k[sim_node()]++) {
                      __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->children[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] - 1][PureTDMASchedulerP__k[sim_node()]]);
                      printf("Node %d children %d\n", TOS_NODE_ID % 500, __nesc_ntoh_uint16(PureTDMASchedulerP__log_payload[sim_node()]->children[PureTDMASchedulerP__k[sim_node()] - 1].nxdata));
                      __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenReceive[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, 0);
                      __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->childrenHandle[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, 0);
                    }
                }
              else 
#line 241
                {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata, 0);
                  printf("node total children: %d\n", __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalChildren.nxdata));
                }



              if (PureTDMASchedulerP__i[sim_node()] < PureTDMASchedulerP__schedule_len[sim_node()] - 1) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][0]);
                  PureTDMASchedulerP__totalParents[sim_node()] = __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata);
                  for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][0]; PureTDMASchedulerP__k[sim_node()]++) {
                      __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->parents[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()] + 1][PureTDMASchedulerP__k[sim_node()]]);
                    }
                }
              else {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalParents.nxdata, 0);
                }


              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->totalSiblings.nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]);
              for (PureTDMASchedulerP__k[sim_node()] = 1; PureTDMASchedulerP__k[sim_node()] <= PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][0]; PureTDMASchedulerP__k[sim_node()]++) {
                  __nesc_hton_uint16(PureTDMASchedulerP__log_payload[sim_node()]->siblings[PureTDMASchedulerP__k[sim_node()] - 1].nxdata, PureTDMASchedulerP__up_schedule[sim_node()][PureTDMASchedulerP__i[sim_node()]][PureTDMASchedulerP__k[sim_node()]]);
                }


              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->source.nxdata, TOS_NODE_ID);
              __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->curr_num.nxdata, 0);



              if ((((((((
#line 270
              TOS_NODE_ID == 1 || TOS_NODE_ID == 2) || TOS_NODE_ID == 3) || TOS_NODE_ID == 4) || TOS_NODE_ID == 5)
               || TOS_NODE_ID == 6) || TOS_NODE_ID == 7) || TOS_NODE_ID == 8) || TOS_NODE_ID == 9) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->self_data1.nxdata, TOS_NODE_ID * 10);
                }



              if (PureTDMASchedulerP__j[sim_node()] == 1) {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata, 1);
                  PureTDMASchedulerP__is_primary[sim_node()] = 1;
                }
              else 
#line 280
                {
                  __nesc_hton_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata, 0);
                  PureTDMASchedulerP__is_primary[sim_node()] = 0;
                }
              printf("node %d i_am_primary: %d, is_primary\n", TOS_NODE_ID % 500, __nesc_ntoh_uint8(PureTDMASchedulerP__log_payload[sim_node()]->i_am_primary.nxdata), PureTDMASchedulerP__is_primary[sim_node()]);
            }
        }
    }



  return SUCCESS;
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static inline error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Init__init(void )
#line 71
{
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()] = (void *)0;
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[sim_node()] = 0;
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_END;
  return SUCCESS;
}

# 60 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline error_t GenericSlotterP__Init__init(void )
#line 60
{
  /* atomic removed: atomic calls only */
#line 61
  {
    GenericSlotterP__slotLength[sim_node()] = 320;
    GenericSlotterP__frameLength[sim_node()] = 40000;
    GenericSlotterP__sync[sim_node()] = FALSE;
  }
  return SUCCESS;
}

# 46 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
static inline error_t SenderDispatcherP__Init__init(void )
#line 46
{
  SenderDispatcherP__toSend[sim_node()] = (void *)0;
  SenderDispatcherP__toSendLen[sim_node()] = 0;
  SenderDispatcherP__last_id[sim_node()] = NO_SLOT;






  return SUCCESS;
}

# 147 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC__AMPacket__setSource(message_t *amsg, am_addr_t addr)
#line 147
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 149
  __nesc_hton_uint16(header->src.nxdata, addr);
}

# 110 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static void BeaconSlotP__AMPacket__setSource(message_t * amsg, am_addr_t addr){
#line 110
  TossimActiveMessageC__AMPacket__setSource(amsg, addr);
#line 110
}
#line 110
# 162 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC__AMPacket__setType(message_t *amsg, am_id_t t)
#line 162
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 164
  __nesc_hton_uint8(header->type.nxdata, t);
}

# 151 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AMPacket.nc"
inline static void BeaconSlotP__AMPacket__setType(message_t * amsg, am_id_t t){
#line 151
  TossimActiveMessageC__AMPacket__setType(amsg, t);
#line 151
}
#line 151
#line 92
inline static void BeaconSlotP__AMPacket__setDestination(message_t * amsg, am_addr_t addr){
#line 92
  TossimActiveMessageC__AMPacket__setDestination(amsg, addr);
#line 92
}
#line 92
# 69 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static inline error_t BeaconSlotP__Init__init(void )
#line 69
{
  BeaconSlotP__AMPacket__setDestination(&BeaconSlotP__syncPkt[sim_node()], AM_BROADCAST_ADDR);
  BeaconSlotP__AMPacket__setType(&BeaconSlotP__syncPkt[sim_node()], SIMPLE_TDMA_SYNC);
  BeaconSlotP__AMPacket__setSource(&BeaconSlotP__syncPkt[sim_node()], TOS_NODE_ID);
  BeaconSlotP__syncPktLen[sim_node()] = sizeof(message_header_t ) + sizeof(nx_uint32_t );
  return SUCCESS;
}

# 19 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
static inline error_t CC2420ControlP__Init__init(void )
{
  CC2420ControlP__channel[sim_node()] = 26;



  CC2420ControlP__autoAck[sim_node()] = TRUE;





  CC2420ControlP__hwAutoAck[sim_node()] = FALSE;

  return SUCCESS;
}

# 68 "/opt/tinyos-2.x/apps/wustl/upma/system/SSTdmaSlotSenderP.nc"
static inline error_t /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Init__init(void )
#line 68
{
  /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[sim_node()] = (void *)0;
  /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[sim_node()] = 0;
  /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[sim_node()] = /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__S_END;
  return SUCCESS;
}

# 44 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
static inline error_t RandomMlcgC__Init__init(void )
#line 44
{
  /* atomic removed: atomic calls only */
#line 45
  RandomMlcgC__seed[sim_node()] = (uint32_t )(TOS_NODE_ID + 1);

  return SUCCESS;
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t SimMainP__SoftwareInit__init(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = RandomMlcgC__Init__init();
#line 51
  __nesc_result = ecombine(__nesc_result, /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, CC2420ControlP__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, BeaconSlotP__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, SenderDispatcherP__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, GenericSlotterP__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, PureTDMASchedulerP__Init__init());
#line 51
  __nesc_result = ecombine(__nesc_result, TossimPacketModelC__Init__init());
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 79 "/opt/tinyos-2.x/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_enable_interrupt()
#line 79
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] |= 1 << 7;
}

# 83 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t TestNetworkC__RadioControl__start(void ){
#line 83
  unsigned char __nesc_result;
#line 83

#line 83
  __nesc_result = PureTDMASchedulerP__SplitControl__start();
#line 83

#line 83
  return __nesc_result;
#line 83
}
#line 83
# 98 "TestNetworkC.nc"
static inline void TestNetworkC__Alarm__fired(void )
#line 98
{
}

# 37 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static inline bool /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__isRunning(void )
{
  return /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[sim_node()] != (void *)0;
}

static inline void /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__stop(void )
{
  if (/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__isRunning()) 
    {
      /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[sim_node()]->cancelled = 1;
      /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[sim_node()]->cleanup = sim_queue_cleanup_total;

      /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[sim_node()] = (void *)0;
    }
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__AlarmFrom__stop(void ){
#line 62
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__Alarm__stop();
#line 62
}
#line 62
# 91 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__stop(void )
{
  /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__AlarmFrom__stop();
}

# 62 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void TestNetworkC__Alarm__stop(void ){
#line 62
  /*TestNetworkAppC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__3__Alarm__stop();
#line 62
}
#line 62
# 42 "TestNetworkC.nc"
static inline void TestNetworkC__Boot__booted(void )
#line 42
{
  TestNetworkC__Alarm__stop();
  TestNetworkC__Alarm__fired();
  TestNetworkC__RadioControl__start();
}

# 63 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static inline void /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Boot__booted(void )
{
}

# 69 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static inline void GenericSlotterP__Boot__booted(void )
{
}

# 49 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
inline static void SimMainP__Boot__booted(void ){
#line 49
  GenericSlotterP__Boot__booted();
#line 49
  /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Boot__booted();
#line 49
  TestNetworkC__Boot__booted();
#line 49
}
#line 49
# 101 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP__SimMote__getEuid(void )
#line 101
{
  return SimMoteP__euid[sim_node()];
}

#line 104
static inline void SimMoteP__SimMote__setEuid(long long int e)
#line 104
{
  SimMoteP__euid[sim_node()] = e;
}

#line 107
static inline long long int SimMoteP__SimMote__getStartTime(void )
#line 107
{
  return SimMoteP__startTime[sim_node()];
}




static inline int SimMoteP__SimMote__getVariableInfo(char *name, void **addr, size_t *size)
#line 114
{
  return __nesc_nido_resolve(sim_node(), name, (uintptr_t *)addr, (size_t *)size);
}

#line 131
static inline void SimMoteP__SimMote__turnOff(void )
#line 131
{
  SimMoteP__isOn[sim_node()] = FALSE;
}

#line 205
static inline void SimMoteP__sim_mote_boot_handle(sim_event_t *e)
#line 205
{
  char buf[128];

#line 207
  sim_print_now(buf, 128);

  SimMoteP__bootEvent[sim_node()] = (sim_event_t *)(void *)0;
  sim_log_debug(101U, "SimMoteP", "Turning on mote %i at time %s.\n", (int )sim_node(), buf);
  SimMoteP__SimMote__turnOn();
}

# 38 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.c"
  void sim_queue_init()
#line 38
{
  init_heap(&eventHeap);
}

  void sim_queue_insert(sim_event_t *event)
#line 42
{
  sim_log_debug(0U, "Queue", "Inserting 0x%p\n", event);
  heap_insert(&eventHeap, event, event->time);
}

# 238 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
static void sim_log_debug(uint16_t id, char *string, const char *format, ...)
#line 238
{
  va_list args;
  int i;

#line 241
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 246
      __builtin_va_start(args, format);
      fprintf(file, "%s DEBUG (%i): ", sim_time_string(), (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

#line 76
static void fillInOutput(int id, char *name)
#line 76
{
  char *termination = name;
  char *namePos = name;
  int count = 0;
  char *newName = (char *)malloc(strlen(name) + 1);

#line 81
  __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___memset_chk(newName, 0, strlen(name) + 1, __builtin_object_size(newName, 0)) : __inline_memset_chk(newName, 0, strlen(name) + 1);

  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___strcpy_chk(newName, namePos, __builtin_object_size(newName, 2 > 1)) : __inline_strcpy_chk(newName, namePos);
        }
      else 
        {
          __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___memcpy_chk(newName, namePos, termination - namePos, __builtin_object_size(newName, 0)) : __inline_memcpy_chk(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, namePos);
      if (channel != (void *)0) {
          count += channel->numOutputs;
        }

      namePos = termination + 1;
    }

  termination = name;
  namePos = name;


  outputs[id].files = (FILE **)malloc(sizeof(FILE *) * count);
  outputs[id].num = 0;


  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___strcpy_chk(newName, namePos, __builtin_object_size(newName, 2 > 1)) : __inline_strcpy_chk(newName, namePos);
        }
      else 
        {
          __builtin_object_size(newName, 0) != (size_t )-1 ? __builtin___memcpy_chk(newName, namePos, termination - namePos, __builtin_object_size(newName, 0)) : __inline_memcpy_chk(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, namePos);
      if (channel != (void *)0) {
          int i;
#line 129
          int j;

#line 130
          for (i = 0; i < channel->numOutputs; i++) {
              int duplicate = 0;
              int outputCount = outputs[id].num;


              for (j = 0; j < outputCount; j++) {
                  if (fileno(outputs[id].files[j]) == fileno(channel->outputs[i])) {
                      duplicate = 1;
                      j = outputCount;
                    }
                }
              if (!duplicate) {
                  outputs[id].files[outputCount] = channel->outputs[i];
                  outputs[id].num++;
                }
            }
        }
      namePos = termination + 1;
    }
}

# 293 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.c"
  char *sim_time_string()
#line 293
{
  sim_print_now(simTimeBuf, 128);
  return simTimeBuf;
}

#line 288
  int sim_print_now(char *buf, int len)
#line 288
{
  return sim_print_time(buf, len, sim_time());
}

#line 265
  int sim_print_time(char *buf, int len, sim_time_t ftime)
#line 265
{
  int hours;
  int minutes;
  int seconds;
  sim_time_t secondBillionths;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  buf[len - 1] = 0;
  return __builtin___snprintf_chk(buf, len - 1, 0, __builtin_object_size(buf, 2 > 1), "%i:%i:%i.%09llu", hours, minutes, seconds, secondBillionths);
}

#line 107
  sim_time_t sim_ticks_per_sec()
#line 107
{
  return 10000000000ULL;
}

#line 100
  sim_time_t sim_time()
#line 100
{
  return sim_ticks;
}








  unsigned long sim_node()
#line 111
{
  return current_node;
}

# 186 "/opt/tinyos-2.x/tos/lib/tossim/heap.c"
static void up_heap(heap_t *heap, int findex)
#line 186
{
  int parent_index;

#line 188
  if (findex == 0) {
      return;
    }

  parent_index = (findex - 1) / 2;

  if (((node_t *)heap->data)[parent_index].key > ((node_t *)heap->data)[findex].key) {
      swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[parent_index]);
      up_heap(heap, parent_index);
    }
}

#line 147
static void swap(node_t *first, node_t *second)
#line 147
{
  long long int key;
  void *data;

  key = first->key;
  first->key = second->key;
  second->key = key;

  data = first->data;
  first->data = second->data;
  second->data = data;
}

# 47 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.c"
  sim_event_t *sim_queue_pop()
#line 47
{
  long long int key;

#line 49
  return (sim_event_t *)heap_pop_min_data(&eventHeap, &key);
}

# 103 "/opt/tinyos-2.x/tos/lib/tossim/heap.c"
static void *heap_pop_min_data(heap_t *heap, long long int *key)
#line 103
{
  int last_index = heap->size - 1;
  void *data = ((node_t *)heap->data)[0].data;

#line 106
  if (key != (void *)0) {
      *key = ((node_t *)heap->data)[0].key;
    }
  ((node_t *)heap->data)[0].data = ((node_t *)heap->data)[last_index].data;
  ((node_t *)heap->data)[0].key = ((node_t *)heap->data)[last_index].key;

  heap->size--;

  down_heap(heap, 0);

  return data;
}

#line 160
static void down_heap(heap_t *heap, int findex)
#line 160
{
  int right_index = (findex + 1) * 2;
  int left_index = findex * 2 + 1;

  if (right_index < heap->size) {
      long long int left_key = ((node_t *)heap->data)[left_index].key;
      long long int right_key = ((node_t *)heap->data)[right_index].key;
      int min_key_index = left_key < right_key ? left_index : right_index;

      if (((node_t *)heap->data)[min_key_index].key < ((node_t *)heap->data)[findex].key) {
          swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[min_key_index]);
          down_heap(heap, min_key_index);
        }
    }
  else {
#line 174
    if (left_index >= heap->size) {
        return;
      }
    else {
        long long int left_key = ((node_t *)heap->data)[left_index].key;

#line 179
        if (left_key < ((node_t *)heap->data)[findex].key) {
            swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[left_index]);
            return;
          }
      }
    }
}

# 52 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.c"
  bool sim_queue_is_empty()
#line 52
{
  return heap_is_empty(&eventHeap);
}

  long long int sim_queue_peek_time()
#line 56
{
  if (heap_is_empty(&eventHeap)) {
      return -1;
    }
  else {
      return heap_get_min_key(&eventHeap);
    }
}


  void sim_queue_cleanup_none(sim_event_t *event)
#line 66
{
  sim_log_debug(1U, "Queue", "cleanup_none: 0x%p\n", event);
}


  void sim_queue_cleanup_event(sim_event_t *event)
#line 71
{
  sim_log_debug(2U, "Queue", "cleanup_event: 0x%p\n", event);
  free(event);
}

  void sim_queue_cleanup_data(sim_event_t *event)
#line 76
{
  sim_log_debug(3U, "Queue", "cleanup_data: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
}

  void sim_queue_cleanup_total(sim_event_t *event)
#line 82
{
  sim_log_debug(4U, "Queue", "cleanup_total: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
  free(event);
}

# 47 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.c"
  void sim_init()
#line 47
{
  sim_queue_init();
  sim_log_init();
  sim_log_commit_change();
  sim_noise_init();

  {
    struct timeval tv;

#line 55
    gettimeofday(&tv, (void *)0);





    if (tv.tv_usec != 0) {
        sim_random_seed(tv.tv_usec);
      }
    else {
        sim_random_seed(tv.tv_sec);
      }
  }
}

# 226 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
static void sim_log_commit_change()
#line 226
{
  int i;

#line 228
  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      if (outputs[i].files != (void *)0) {
          outputs[i].num = 0;
          free(outputs[i].files);
          outputs[i].files = (void *)0;
        }
    }
}

# 63 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
  void sim_noise_init()
{
  int j;
  int i;

#line 67
  for (j = 0; j < 1000; j++) {
      for (i = 0; i < 16; i++) {
          noiseData[j][i].noiseGenTime = 0;
          noiseData[j][i].noiseTable = create_hashtable(NOISE_HASHTABLE_SIZE, sim_noise_hash, sim_noise_eq);
          noiseData[j][i].noiseTrace = (char *)malloc(sizeof(char ) * NOISE_MIN_TRACE);
          noiseData[j][i].noiseTraceLen = NOISE_MIN_TRACE;
          noiseData[j][i].noiseTraceIndex = 0;
        }
    }
}

# 92 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.c"
  void sim_random_seed(int seed)
#line 92
{

  if (seed == 0) {
      seed = 1;
    }
  sim_seed = seed;
}

#line 70
  void sim_end()
#line 70
{
  sim_queue_init();
}



  int sim_random()
#line 76
{
  uint32_t mlcg;
#line 77
  uint32_t p;
#line 77
  uint32_t q;
  uint64_t tmpseed;

#line 79
  tmpseed = (uint64_t )33614U * (uint64_t )sim_seed;
  q = tmpseed;
  q = q >> 1;
  p = tmpseed >> 32;
  mlcg = p + q;
  if (mlcg & 0x80000000) {
      mlcg = mlcg & 0x7FFFFFFF;
      mlcg++;
    }
  sim_seed = mlcg;
  return mlcg;
}

#line 103
  void sim_set_time(sim_time_t t)
#line 103
{
  sim_ticks = t;
}








  void sim_set_node(unsigned long node)
#line 114
{
  current_node = node;
  TOS_NODE_ID = node;
}

#line 199
  int sim_run_next_event()
#line 199
{

  int actuator1 = 157;
  int actuator2 = 180;
  int actuator3 = 108;
  int actuator4 = 175;

  int res_length = 9;



  int *tcpMsg_result;
  int result_to_py = 0;
  int i = 0;
  int res = 0;
  int tmp = 0;

#line 215
  if (!sim_queue_is_empty()) {
      sim_event_t *event = sim_queue_pop();

#line 217
      sim_set_time(event->time);
      sim_set_node(event->mote);




      if ((sim_mote_is_on(event->mote) || event->force) && event->handle != (void *)0) {

          event->handle(event);
          tcpMsg_result = sim_mote_getTcpMsg(event->mote);

          if ((((event->mote == tcpMsg_result[0] || event->mote == actuator1) || event->mote == actuator2) || event->mote == actuator3) || event->mote == actuator4) {



              if (
#line 231
              tcpMsg_result[1] == 0 && tcpMsg_result[1] == 0 && tcpMsg_result[2] == 0 && tcpMsg_result[3] == 0 && tcpMsg_result[4] == 0 && tcpMsg_result[5] == 0
               && tcpMsg_result[6] == 0 && tcpMsg_result[7] == 0 && tcpMsg_result[8] == 0 && tcpMsg_result[9] == 0) {
                }
              else 
                {
                  for (i = 1; i <= res_length; i++) {
                      if (tcpMsg_result[i] == 0) {
                          res = 0;
                        }
                      else 
#line 239
                        {
                          tmp = 10 - tcpMsg_result[i];
                          res = 0;
                          res |= 1u << tmp;
                        }

                      printf("tcpMsg_result bit: %d, res: %d\n", tmp, res);
                      result_to_py += res;
                    }

                  sim_mote_setTcpMsg(event->mote, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                }
            }
        }
      else {
        }
      if (event->cleanup != (void *)0) {
          event->cleanup(event);
        }
    }


  return result_to_py;
}

# 180 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
  bool sim_mote_is_on(int mote)
#line 180
{
  bool result;
  int tmp = sim_node();

#line 183
  sim_set_node(mote);
  result = SimMoteP__SimMote__isOn();

  sim_set_node(tmp);
  return result;
}

#line 244
  int *sim_mote_getTcpMsg(int mote)
#line 244
{
  int *tcpMsgg;
  int tmp = sim_node();

#line 247
  sim_set_node(mote);
  tcpMsgg = SimMoteP__SimMote__getTcpMsg();
  sim_set_node(tmp);
  return tcpMsgg;
}










  void sim_mote_setTcpMsg(int mote, int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8)
#line 262
{
  int tmp = sim_node();

#line 264
  sim_set_node(mote);
  SimMoteP__SimMote__setTcpMsg(root, flow0, flow1, flow2, flow3, flow4, flow5, flow6, flow7, flow8);
  sim_set_node(tmp);
}

#line 286
static void SimMoteP__SimMote__setTcpMsg(int root, int flow0, int flow1, int flow2, int flow3, int flow4, int flow5, int flow6, int flow7, int flow8)
#line 286
{
  SimMoteP__tcp_msg[sim_node()][0] = root;
  SimMoteP__tcp_msg[sim_node()][1] = flow0;
  SimMoteP__tcp_msg[sim_node()][2] = flow1;
  SimMoteP__tcp_msg[sim_node()][3] = flow2;
  SimMoteP__tcp_msg[sim_node()][4] = flow3;
  SimMoteP__tcp_msg[sim_node()][5] = flow4;
  SimMoteP__tcp_msg[sim_node()][6] = flow5;
  SimMoteP__tcp_msg[sim_node()][7] = flow6;
  SimMoteP__tcp_msg[sim_node()][8] = flow7;
  SimMoteP__tcp_msg[sim_node()][9] = flow8;
}

# 298 "/opt/tinyos-2.x/tos/lib/tossim/sim_tossim.c"
  void sim_add_channel(char *channel, FILE *file)
#line 298
{
  sim_log_add_channel(channel, file);
}

  bool sim_remove_channel(char *channel, FILE *file)
#line 302
{
  return sim_log_remove_channel(channel, file);
}

# 49 "/opt/tinyos-2.x/tos/lib/tossim/sim_csma.c"
  int sim_csma_init_high()
#line 49
{
  return csmaInitHigh;
}

#line 52
  int sim_csma_init_low()
#line 52
{
  return csmaInitLow;
}

#line 55
  int sim_csma_high()
#line 55
{
  return csmaHigh;
}

#line 58
  int sim_csma_low()
#line 58
{
  return csmaLow;
}

#line 61
  int sim_csma_symbols_per_sec()
#line 61
{
  return csmaSymbolsPerSec;
}

#line 64
  int sim_csma_bits_per_symbol()
#line 64
{
  return csmaBitsPerSymbol;
}

#line 67
  int sim_csma_preamble_length()
#line 67
{
  return csmaPreambleLength;
}

#line 70
  int sim_csma_exponent_base()
#line 70
{
  return csmaExponentBase;
#line 71
  ;
}

#line 73
  int sim_csma_max_iterations()
#line 73
{
  return csmaMaxIterations;
}

#line 76
  int sim_csma_min_free_samples()
#line 76
{
  return csmaMinFreeSamples;
}

#line 79
  int sim_csma_rxtx_delay()
#line 79
{
  return csmaRxTxDelay;
}

#line 82
  int sim_csma_ack_time()
#line 82
{
  return csmaAckTime;
}



  void sim_csma_set_init_high(int val)
#line 88
{
  csmaInitHigh = val;
}

#line 91
  void sim_csma_set_init_low(int val)
#line 91
{
  csmaInitLow = val;
}

#line 94
  void sim_csma_set_high(int val)
#line 94
{
  csmaHigh = val;
}

#line 97
  void sim_csma_set_low(int val)
#line 97
{
  csmaLow = val;
}

#line 100
  void sim_csma_set_symbols_per_sec(int val)
#line 100
{
  csmaSymbolsPerSec = val;
}

#line 103
  void sim_csma_set_bits_per_symbol(int val)
#line 103
{
  csmaBitsPerSymbol = val;
}

#line 106
  void sim_csma_set_preamble_length(int val)
#line 106
{
  csmaPreambleLength = val;
}

#line 109
  void sim_csma_set_exponent_base(int val)
#line 109
{
  csmaExponentBase = val;
}

#line 112
  void sim_csma_set_max_iterations(int val)
#line 112
{
  csmaMaxIterations = val;
}

#line 115
  void sim_csma_set_min_free_samples(int val)
#line 115
{
  csmaMinFreeSamples = val;
}

#line 118
  void sim_csma_set_rxtx_delay(int val)
#line 118
{
  csmaRxTxDelay = val;
}

#line 121
  void sim_csma_set_ack_time(int val)
#line 121
{
  csmaAckTime = val;
}

# 15 "/opt/tinyos-2.x/tos/lib/tossim/sim_gain.c"
  gain_entry_t *sim_gain_first(int src, int channel_id)
#line 15
{

  sim_log_debug(5U, "channel_switching_debug", "Gain modeling: in sim_gain_first() and channel id is: %u\n", channel_id);

  if (src > 1000) {
      return connectivity[1000][channel_id];
    }
  return connectivity[src][channel_id];
}

  gain_entry_t *sim_gain_next(gain_entry_t *currentLink)
#line 25
{
  return currentLink->next;
}

  void sim_gain_add(int src, int dest, double gain, int channel_id)
#line 29
{
  gain_entry_t *current;
  int temp = sim_node();

#line 32
  if (src > 1000) {
      src = 1000;
    }
  sim_set_node(src);
  current = sim_gain_first(src, channel_id);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          break;
        }
      current = current->next;
    }
  if (current == (void *)0) {
      current = sim_gain_allocate_link(dest, channel_id);
      current->next = connectivity[src][channel_id];
      connectivity[src][channel_id] = current;
    }
  current->mote = dest;
  current->gain = gain;
  current->channel = channel_id;
  sim_log_debug(6U, "Gain", "Adding link from %i to %i with gain %f\n", src, dest, gain);
  sim_set_node(temp);
}

  double sim_gain_value(int src, int dest, int channel_id)
#line 56
{
  gain_entry_t *current;
  int temp = sim_node();

#line 59
  sim_set_node(src);
  current = sim_gain_first(src, channel_id);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          sim_log_debug(7U, "Gain", "Getting link from %i to %i with gain %f\n", src, dest, current->gain);

          return current->gain;
        }
      current = current->next;
    }
  sim_set_node(temp);
  sim_log_debug(8U, "Gain", "Getting default link from %i to %i with gain %f\n", src, dest, 1.0);
  return 1.0;
}

  bool sim_gain_connected(int src, int dest, int channel_id)
#line 75
{
  gain_entry_t *current;
  int temp = sim_node();

#line 78
  sim_set_node(src);
  current = sim_gain_first(src, channel_id);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          return TRUE;
        }
      current = current->next;
    }
  sim_set_node(temp);
  return FALSE;
}

  void sim_gain_remove(int src, int dest, int channel_id)
#line 91
{
  gain_entry_t *current;
  gain_entry_t *prevLink;

  int temp = sim_node();

#line 96
  if (src > 1000) {
      src = 1000;
    }
  sim_set_node(src);
  current = sim_gain_first(src, channel_id);
  prevLink = (void *)0;

  while (current != (void *)0) {
      gain_entry_t *tmp;

#line 105
      if (current->mote == dest) {
          if (prevLink == (void *)0) {
              connectivity[src][channel_id] = current->next;
            }
          else {
              prevLink->next = current->next;
            }
          tmp = current->next;
          sim_gain_deallocate_link(current);
          printf("From sim_gain.c, we have just deallocate the link for Sensor:%u on Channel: %u\n", TOS_NODE_ID, channel_id);
          current = tmp;
        }
      else {
          prevLink = current;
          current = current->next;
        }
    }
  sim_set_node(temp);
}

#line 171
  void sim_gain_deallocate_link(gain_entry_t *linkToDelete)
#line 171
{
  free(linkToDelete);
}

#line 125
  void sim_gain_set_noise_floor(int node, double mean, double range, int channel_id)
#line 125
{
  if (node > 1000) {
      node = 1000;
    }
  localNoise[node][channel_id].mean = mean;
  localNoise[node][channel_id].range = range;
}

#line 149
  double sim_gain_sample_noise(int node, int channel_id)
#line 149
{
  double val;
#line 150
  double adjust;

#line 151
  if (node > 1000) {
      node = 1000;
    }
  val = localNoise[node][channel_id].mean;
  adjust = sim_random() % 2000000;
  adjust /= 1000000.0;
  adjust -= 1.0;
  adjust *= localNoise[node][channel_id].range;
  return val + adjust;
}

#line 175
  void sim_gain_set_sensitivity(double s)
#line 175
{
  sensitivity = s;
}

  double sim_gain_sensitivity()
#line 179
{
  return sensitivity;
}

# 79 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
  void sim_noise_create_model(uint16_t node_id, uint8_t channel_id)
#line 79
{

  makeNoiseModel(node_id, channel_id);
  makePmfDistr(node_id, channel_id);
}

#line 488
  void makeNoiseModel(uint16_t node_id, uint8_t channel_id)
#line 488
{
  int i;




  for (i = 0; i < NOISE_HISTORY; i++) {
      noiseData[node_id][channel_id].key[i] = search_bin_num(noiseData[node_id][channel_id].noiseTrace[i]);

      sim_log_debug(42U, "Insert", "Setting history %i to be %i\n", (int )i, (int )noiseData[node_id][channel_id].key[i]);
    }






  for (i = NOISE_HISTORY; i < noiseData[node_id][channel_id].noiseTraceIndex; i++) {
      sim_noise_add(node_id, noiseData[node_id][channel_id].noiseTrace[i], channel_id);
      arrangeKey(node_id, channel_id);
      noiseData[node_id][channel_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id][channel_id].noiseTrace[i]);
    }
  noiseData[node_id][channel_id].generated = 1;
}

#line 108
  uint8_t search_bin_num(char noise)
{
  uint8_t bin;

#line 111
  if (noise > NOISE_MAX || noise < NOISE_MIN) {
      noise = NOISE_MIN;
    }
  bin = (noise - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1;
  return bin;
}

#line 139
  void sim_noise_add(uint16_t node_id, char noise, uint8_t channel_id)
{
  int i;
  struct hashtable *pnoiseTable = noiseData[node_id][channel_id].noiseTable;
  char *key = noiseData[node_id][channel_id].key;
  sim_noise_hash_t *noise_hash;

#line 145
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);










  sim_log_debug(11U, "Insert", "Adding noise value %hhi\n", noise);
  if (noise_hash == (void *)0) {
      noise_hash = (sim_noise_hash_t *)malloc(sizeof(sim_noise_hash_t ));
      __builtin_object_size((void *)noise_hash->key, 0) != (size_t )-1 ? __builtin___memcpy_chk((void *)noise_hash->key, (void *)key, NOISE_HISTORY, __builtin_object_size((void *)noise_hash->key, 0)) : __inline_memcpy_chk((void *)noise_hash->key, (void *)key, NOISE_HISTORY);

      noise_hash->numElements = 0;
      noise_hash->size = NOISE_DEFAULT_ELEMENT_SIZE;
      noise_hash->elements = (char *)malloc(sizeof(char ) * noise_hash->size);
      __builtin_object_size((void *)noise_hash->elements, 0) != (size_t )-1 ? __builtin___memset_chk((void *)noise_hash->elements, 0, sizeof(char ) * noise_hash->size, __builtin_object_size((void *)noise_hash->elements, 0)) : __inline_memset_chk((void *)noise_hash->elements, 0, sizeof(char ) * noise_hash->size);

      noise_hash->flag = 0;
      for (i = 0; i < NOISE_NUM_VALUES; i++) {
          noise_hash->dist[i] = 0;
        }
      hashtable_insert(pnoiseTable, key, noise_hash);
      sim_log_debug(12U, "Insert", "Inserting %p into table %p with key ", noise_hash, pnoiseTable);
      {
        int ctr;

#line 174
        for (ctr = 0; ctr < NOISE_HISTORY; ctr++) 
          sim_log_debug_clear(13U, "Insert", "%0.3hhi ", key[ctr]);
      }
      sim_log_debug_clear(14U, "Insert", "\n");
    }

  if (noise_hash->numElements == noise_hash->size) 
    {
      char *newElements;
      int newSize = noise_hash->size * 2;

      newElements = (char *)malloc(sizeof(char ) * newSize);
      __builtin_object_size(newElements, 0) != (size_t )-1 ? __builtin___memcpy_chk(newElements, noise_hash->elements, noise_hash->size, __builtin_object_size(newElements, 0)) : __inline_memcpy_chk(newElements, noise_hash->elements, noise_hash->size);
      free(noise_hash->elements);
      noise_hash->elements = newElements;
      noise_hash->size = newSize;
    }

  noise_hash->elements[noise_hash->numElements] = noise;






  noise_hash->numElements++;
}

# 268 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...)
#line 268
{
  va_list args;
  int i;

#line 271
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 276
      __builtin_va_start(args, format);
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 261 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
  void arrangeKey(uint16_t node_id, uint8_t channel_id)
{

  char *pKey = noiseData[node_id][channel_id].key;

#line 265
  __builtin_object_size(pKey, 0) != (size_t )-1 ? __builtin___memcpy_chk(pKey, pKey + 1, NOISE_HISTORY - 1, __builtin_object_size(pKey, 0)) : __inline_memcpy_chk(pKey, pKey + 1, NOISE_HISTORY - 1);
}




  void makePmfDistr(uint16_t node_id, uint8_t channel_id)
{
  int i;
  char *pKey = noiseData[node_id][channel_id].key;
  char *fKey = noiseData[node_id][channel_id].freqKey;

  FreqKeyNum = 0;


  for (i = 0; i < NOISE_HISTORY; i++) {
      pKey[i] = search_bin_num(noiseData[node_id][channel_id].noiseTrace[i]);
    }

  for (i = NOISE_HISTORY; i < noiseData[node_id][channel_id].noiseTraceIndex; i++) {
      if (i == NOISE_HISTORY) {
        }

      sim_noise_dist(node_id, channel_id);
      arrangeKey(node_id, channel_id);
      pKey[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id][channel_id].noiseTrace[i]);
    }

  sim_log_debug_clear(19U, "HASH", "FreqKey = ");
  for (i = 0; i < NOISE_HISTORY; i++) 
    {
      sim_log_debug_clear(20U, "HASH", "%d,", fKey[i]);
    }
  sim_log_debug_clear(21U, "HASH", "\n");
}

#line 202
  void sim_noise_dist(uint16_t node_id, uint8_t channel_id)
{

  int i;
  uint8_t bin;
  float cmf = 0;
  struct hashtable *pnoiseTable = noiseData[node_id][channel_id].noiseTable;
  char *key = noiseData[node_id][channel_id].key;
  char *freqKey = noiseData[node_id][channel_id].freqKey;
  sim_noise_hash_t *noise_hash;

  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);




  if (noise_hash->flag == 1) {
    return;
    }
  for (i = 0; i < NOISE_NUM_VALUES; i++) {
      noise_hash->dist[i] = 0.0;
    }

  for (i = 0; i < noise_hash->numElements; i++) 
    {
      float val;

#line 228
      sim_log_debug(15U, "Noise_output", "Noise is found to be %i\n", noise_hash->elements[i]);
      bin = noise_hash->elements[i] - NOISE_MIN_QUANTIZE;

      val = noise_hash->dist[bin];
      val += (float )1.0;
      noise_hash->dist[bin] = val;
    }

  for (i = 0; i < NOISE_NUM_VALUES; i++) 
    {
      noise_hash->dist[i] = noise_hash->dist[i] / noise_hash->numElements;
      cmf += noise_hash->dist[i];
      noise_hash->dist[i] = cmf;
    }
  noise_hash->flag = 1;


  if (noise_hash->numElements > FreqKeyNum) 
    {
      int j;

#line 248
      FreqKeyNum = noise_hash->numElements;
      __builtin_object_size((void *)freqKey, 0) != (size_t )-1 ? __builtin___memcpy_chk((void *)freqKey, (void *)key, NOISE_HISTORY, __builtin_object_size((void *)freqKey, 0)) : __inline_memcpy_chk((void *)freqKey, (void *)key, NOISE_HISTORY);
      sim_log_debug(16U, "HashZeroDebug", "Setting most frequent key (%i): ", (int )FreqKeyNum);
      for (j = 0; j < NOISE_HISTORY; j++) {
          sim_log_debug_clear(17U, "HashZeroDebug", "[%hhu] ", key[j]);
        }
      sim_log_debug_clear(18U, "HashZeroDebug", "\n");
    }
}

#line 94
  void sim_noise_trace_add(uint16_t node_id, char noiseVal, uint8_t channel_id)
#line 94
{

  if (noiseData[node_id][channel_id].noiseTraceIndex == noiseData[node_id][channel_id].noiseTraceLen) {
      char *data = (char *)malloc(sizeof(char ) * noiseData[node_id][channel_id].noiseTraceLen * 2);

#line 98
      __builtin_object_size(data, 0) != (size_t )-1 ? __builtin___memcpy_chk(data, noiseData[node_id][channel_id].noiseTrace, noiseData[node_id][channel_id].noiseTraceLen, __builtin_object_size(data, 0)) : __inline_memcpy_chk(data, noiseData[node_id][channel_id].noiseTrace, noiseData[node_id][channel_id].noiseTraceLen);
      free(noiseData[node_id][channel_id].noiseTrace);
      noiseData[node_id][channel_id].noiseTraceLen *= 2;
      noiseData[node_id][channel_id].noiseTrace = data;
    }
  noiseData[node_id][channel_id].noiseTrace[noiseData[node_id][channel_id].noiseTraceIndex] = noiseVal;
  noiseData[node_id][channel_id].noiseTraceIndex++;
  sim_log_debug(10U, "Insert", "Adding noise value %i for %i of %i\n", (int )noiseData[node_id][channel_id].noiseTraceIndex, (int )node_id, (int )noiseVal);
}











  char search_noise_from_bin_num(int i)
{
  char noise;

#line 121
  noise = NOISE_MIN + (i - 1) * NOISE_QUANTIZE_INTERVAL;
  return noise;
}

#line 306
  char sim_noise_gen(uint16_t node_id, uint8_t channel_id)
{

  int i;
  int noiseIndex = 0;
  char noise;

  struct hashtable *pnoiseTable = noiseData[node_id][channel_id].noiseTable;

  char *pKey = noiseData[node_id][channel_id].key;
  char *fKey = noiseData[node_id][channel_id].freqKey;
  double ranNum = RandomUniform();
  sim_noise_hash_t *noise_hash;

#line 319
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);
#line 333
  if (noise_hash == (void *)0) {

      sim_log_debug(22U, "Noise_c", "Did not pattern match");

      sim_noise_alarm();
      noise = 0;
      sim_log_debug_clear(23U, "HASH", "(N)Noise\n");
      sim_log_debug(24U, "HashZeroDebug", "Defaulting to common hash.\n");
      __builtin_object_size((void *)pKey, 0) != (size_t )-1 ? __builtin___memcpy_chk((void *)pKey, (void *)fKey, NOISE_HISTORY, __builtin_object_size((void *)pKey, 0)) : __inline_memcpy_chk((void *)pKey, (void *)fKey, NOISE_HISTORY);
      noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);
    }

  sim_log_debug_clear(25U, "HASH", "Key = ");
  for (i = 0; i < NOISE_HISTORY; i++) {
      sim_log_debug_clear(26U, "HASH", "%d,", pKey[i]);
    }
  sim_log_debug_clear(27U, "HASH", "\n");

  sim_log_debug(28U, "HASH", "Printing Key\n");
  sim_log_debug(29U, "HASH", "noise_hash->numElements=%d\n", noise_hash->numElements);


  numTotal++;


  if (noise_hash->numElements == 1) {
      noise = noise_hash->elements[0];
      sim_log_debug_clear(30U, "HASH", "(E)Noise = %d\n", noise);

      numCase1++;
      sim_log_debug(31U, "Noise_c", "In case 1: %i of %i\n", numCase1, numTotal);

      sim_log_debug(32U, "NoiseAudit", "Noise: %i\n", noise);
      return noise;
    }


  numCase2++;
  sim_log_debug(33U, "Noise_c", "In case 2: %i of %i\n", numCase2, numTotal);









  for (i = 0; i < NOISE_NUM_VALUES - 1; i++) {
      sim_log_debug(34U, "HASH", "IN:for i=%d\n", i);
      if (i == 0) {
          if (ranNum <= noise_hash->dist[i]) {
              noiseIndex = i;
              sim_log_debug_clear(35U, "HASH", "Selected Bin = %d -> ", i + 1);
              break;
            }
        }
      else {
#line 390
        if (noise_hash->dist[i - 1] < ranNum && 
        ranNum <= noise_hash->dist[i]) {
            noiseIndex = i;
            sim_log_debug_clear(36U, "HASH", "Selected Bin = %d -> ", i + 1);
            break;
          }
        }
    }
#line 397
  sim_log_debug(37U, "HASH", "OUT:for i=%d\n", i);
  noise = NOISE_MIN_QUANTIZE + i;
  sim_log_debug(38U, "NoiseAudit", "Noise: %i\n", noise);
  return noise;
}

# 103 "/opt/tinyos-2.x/tos/lib/tossim/randomlib.c"
static double RandomUniform(void )
{
  double uni;
  int seed1;
#line 106
  int seed2;




  if (!test) 
    {



      seed1 = sim_random() % 31329;
      seed2 = sim_random() % 30082;

      seed1 = 2;
      seed2 = 2;

      RandomInitialise(seed1, seed2);
    }

  uni = randU[i97 - 1] - randU[j97 - 1];
  if (uni <= 0.0) {
    uni++;
    }
#line 128
  randU[i97 - 1] = uni;
  i97--;
  if (i97 == 0) {
    i97 = 97;
    }
#line 132
  j97--;
  if (j97 == 0) {
    j97 = 97;
    }
#line 135
  randC -= randCD;
  if (randC < 0.0) {
    randC += randCM;
    }
#line 138
  uni -= randC;
  if (uni < 0.0) {
    uni++;
    }
  return uni;
}

# 403 "/opt/tinyos-2.x/tos/lib/tossim/sim_noise.c"
  char sim_noise_generate(uint16_t node_id, uint32_t cur_t, uint8_t channel_id)
#line 403
{
  uint32_t i;
  uint32_t prev_t;
  uint32_t delta_t;
  char *noiseG;
  char noise;

  FILE *ng_fp;

  prev_t = noiseData[node_id][channel_id].noiseGenTime;

  if (noiseData[node_id][channel_id].generated == 0) {
      sim_log_error(39U, "TOSSIM", "Tried to generate noise from an uninitialized radio model of node %hu.\n", node_id);
      return 127;
    }

  if (0 <= cur_t && cur_t < NOISE_HISTORY) {
      noiseData[node_id][channel_id].noiseGenTime = cur_t;
      noiseData[node_id][channel_id].key[cur_t] = search_bin_num(noiseData[node_id][channel_id].noiseTrace[cur_t]);
      noiseData[node_id][channel_id].lastNoiseVal = noiseData[node_id][channel_id].noiseTrace[cur_t];
#line 437
      return noiseData[node_id][channel_id].noiseTrace[cur_t];
    }

  if (prev_t == 0) {
    delta_t = cur_t - (NOISE_HISTORY - 1);
    }
  else {
#line 443
    delta_t = cur_t - prev_t;
    }
  sim_log_debug_clear(40U, "HASH", "delta_t = %d\n", delta_t);
  if (delta_t == 0) {
    noise = noiseData[node_id][channel_id].lastNoiseVal;
    }
  else 
#line 448
    {
      noiseG = (char *)malloc(sizeof(char ) * delta_t);
      for (i = 0; i < delta_t; i++) {
          noiseG[i] = sim_noise_gen(node_id, channel_id);








          arrangeKey(node_id, channel_id);
          noiseData[node_id][channel_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseG[i]);
        }
      noise = noiseG[delta_t - 1];
      noiseData[node_id][channel_id].lastNoiseVal = noise;
      free(noiseG);
    }
  noiseData[node_id][channel_id].noiseGenTime = cur_t;
  if (noise == 0) {
      sim_log_debug(41U, "HashZeroDebug", "Generated noise of zero.\n");
    }










  return noise;
}

# 253 "/opt/tinyos-2.x/tos/lib/tossim/sim_log.c"
static void sim_log_error(uint16_t id, char *string, const char *format, ...)
#line 253
{
  va_list args;
  int i;

#line 256
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 261
      __builtin_va_start(args, format);
      fprintf(file, "%s ERROR (%i): ", sim_time_string(), (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 46 "/opt/tinyos-2.x/tos/lib/tossim/sim_packet.c"
  void sim_packet_set_source(sim_packet_t *msg, uint16_t src)
#line 46
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 48
  __nesc_hton_uint16(hdr->src.nxdata, src);
}

  uint16_t sim_packet_source(sim_packet_t *msg)
#line 51
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 53
  return __nesc_ntoh_uint16(hdr->src.nxdata);
}

  void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)
#line 56
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 58
  __nesc_hton_uint16(hdr->dest.nxdata, dest);
}

  uint16_t sim_packet_destination(sim_packet_t *msg)
#line 61
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 63
  return __nesc_ntoh_uint16(hdr->dest.nxdata);
}

  void sim_packet_set_length(sim_packet_t *msg, uint8_t length)
#line 66
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 68
  __nesc_hton_uint8(hdr->length.nxdata, length);
}

#line 70
  uint16_t sim_packet_length(sim_packet_t *msg)
#line 70
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 72
  return __nesc_ntoh_uint8(hdr->length.nxdata);
}

  void sim_packet_set_type(sim_packet_t *msg, uint8_t type)
#line 75
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 77
  __nesc_hton_uint8(hdr->type.nxdata, type);
}

  uint8_t sim_packet_type(sim_packet_t *msg)
#line 80
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 82
  return __nesc_ntoh_uint8(hdr->type.nxdata);
}

  uint8_t *sim_packet_data(sim_packet_t *p)
#line 85
{
  message_t *msg = (message_t *)p;

#line 87
  return (uint8_t *)& msg->data;
}

#line 89
  void sim_packet_set_strength(sim_packet_t *p, uint16_t str)
#line 89
{
  message_t *msg = (message_t *)p;
  tossim_metadata_t *md = (tossim_metadata_t *)& msg->metadata;

#line 92
  __nesc_hton_int8(md->strength.nxdata, str);
}

#line 94
  void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)
#line 94
{
  if (t < sim_time()) {
      t = sim_time();
    }
  sim_log_debug(43U, "Packet", "sim_packet.c: Delivering packet %p to %i at %llu\n", msg, node, t);
  active_message_deliver(node, (message_t *)msg, t);
}

# 246 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
  void active_message_deliver(int node, message_t *msg, sim_time_t t)
#line 246
{
  sim_event_t *evt = TossimActiveMessageC__allocate_deliver_event(node, msg, t);

#line 248
  sim_queue_insert(evt);
}

#line 101
static void TossimActiveMessageC__Model__receive(message_t *msg)
#line 101
{
  uint8_t len;
  void *payload;

  __builtin_object_size(TossimActiveMessageC__bufferPointer[sim_node()], 0) != (size_t )-1 ? __builtin___memcpy_chk(TossimActiveMessageC__bufferPointer[sim_node()], msg, sizeof(message_t ), __builtin_object_size(TossimActiveMessageC__bufferPointer[sim_node()], 0)) : __inline_memcpy_chk(TossimActiveMessageC__bufferPointer[sim_node()], msg, sizeof(message_t ));
  len = TossimActiveMessageC__Packet__payloadLength(TossimActiveMessageC__bufferPointer[sim_node()]);
  payload = TossimActiveMessageC__Packet__getPayload(TossimActiveMessageC__bufferPointer[sim_node()], TossimActiveMessageC__Packet__maxPayloadLength());

  if (TossimActiveMessageC__AMPacket__isForMe(msg)) {
      sim_log_debug(166U, "AM", "Received active message (%p) of type %hhu and length %hhu for me @ %s.\n", TossimActiveMessageC__bufferPointer[sim_node()], TossimActiveMessageC__AMPacket__type(TossimActiveMessageC__bufferPointer[sim_node()]), len, sim_time_string());
      TossimActiveMessageC__bufferPointer[sim_node()] = TossimActiveMessageC__Receive__receive(TossimActiveMessageC__AMPacket__type(TossimActiveMessageC__bufferPointer[sim_node()]), TossimActiveMessageC__bufferPointer[sim_node()], payload, len);
    }
  else {
      sim_log_debug(167U, "AM", "Snooped on active message of type %hhu and length %hhu for %hu @ %s.\n", TossimActiveMessageC__AMPacket__type(TossimActiveMessageC__bufferPointer[sim_node()]), len, TossimActiveMessageC__AMPacket__destination(TossimActiveMessageC__bufferPointer[sim_node()]), sim_time_string());
      TossimActiveMessageC__bufferPointer[sim_node()] = TossimActiveMessageC__Snoop__receive(TossimActiveMessageC__AMPacket__type(TossimActiveMessageC__bufferPointer[sim_node()]), TossimActiveMessageC__bufferPointer[sim_node()], payload, len);
    }
}

#line 132
static am_addr_t TossimActiveMessageC__AMPacket__destination(message_t *amsg)
#line 132
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 134
  return __nesc_ntoh_uint16(header->dest.nxdata);
}

# 53 "/opt/tinyos-2.x/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC__amAddress(void )
#line 53
{
  if (!ActiveMessageAddressC__set[sim_node()]) {
      ActiveMessageAddressC__addr[sim_node()] = TOS_NODE_ID;
      ActiveMessageAddressC__set[sim_node()] = TRUE;
    }
  return ActiveMessageAddressC__addr[sim_node()];
}

# 157 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static am_id_t TossimActiveMessageC__AMPacket__type(message_t *amsg)
#line 157
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 159
  return __nesc_ntoh_uint8(header->type.nxdata);
}

# 42 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/AlarmMicro16P.nc"
static void /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__stop(void )
{
  if (/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__Alarm__isRunning()) 
    {
      /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[sim_node()]->cancelled = 1;
      /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[sim_node()]->cleanup = sim_queue_cleanup_total;

      /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[sim_node()] = (void *)0;
    }
}

# 96 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static void /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__set_alarm(void )
{
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type now = /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__Counter__get();
#line 98
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type expires;
#line 98
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type remaining;




  expires = /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] + /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()];


  remaining = (/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__to_size_type )(expires - now);


  if (/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] <= now) 
    {
      if (expires >= /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] && 
      expires <= now) {
        remaining = 0;
        }
    }
  else {
      if (expires >= /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] || 
      expires <= now) {
        remaining = 0;
        }
    }
#line 121
  if (remaining > /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__MAX_DELAY) 
    {
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] = now + /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__MAX_DELAY;
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()] = remaining - /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__MAX_DELAY;
      remaining = /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__MAX_DELAY;
    }
  else 
    {
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[sim_node()] += /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()];
      /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[sim_node()] = 0;
    }
  /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__AlarmFrom__startAt((/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_size_type )now << 5, 
  (/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__from_size_type )remaining << 5);
}

# 69 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__Counter__get(void )
{
  /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type rv = 0;

#line 72
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__upper_count_type high = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[sim_node()];
      /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__from_size_type low = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__get();

#line 76
      if (/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__isOverflowPending()) 
        {






          high++;
          low = /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__CounterFrom__get();
        }
      {
        /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type high_to = high;
        /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__to_size_type low_to = low >> /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__LOW_SHIFT_RIGHT;

#line 90
        rv = (high_to << /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__HIGH_SHIFT_LEFT) | low_to;
      }
    }
#line 92
    __nesc_atomic_end(__nesc_atomic); }
  return rv;
}

# 55 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
static uint16_t CounterMicro16P__Counter__get(void )
{
  return (sim_time() - CounterMicro16P__t0[sim_node()]) * 1024UL * 1024UL / sim_ticks_per_sec();
}

# 89 "/opt/tinyos-2.x/tos/lib/tossim/sim_event_queue.c"
static sim_event_t *sim_queue_allocate_event()
#line 89
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 91
  __builtin_object_size(evt, 0) != (size_t )-1 ? __builtin___memset_chk(evt, 0, sizeof(sim_event_t ), __builtin_object_size(evt, 0)) : __inline_memset_chk(evt, 0, sizeof(sim_event_t ));
  evt->mote = sim_node();
  return evt;
}

# 84 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotterP.nc"
static error_t GenericSlotterP__SlotterControl__synchronize(uint8_t toSlot)
#line 84
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 85
    GenericSlotterP__slot[sim_node()] = toSlot - 1;
#line 85
    __nesc_atomic_end(__nesc_atomic); }

  GenericSlotterP__Alarm__stop();
  GenericSlotterP__Alarm__fired();
  return SUCCESS;
}

#line 120
static void GenericSlotterP__Alarm__fired(void )
#line 120
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 121
    GenericSlotterP__nextFire[sim_node()] = GenericSlotterP__Alarm__getNow() + GenericSlotterP__slotLength[sim_node()];
#line 121
    __nesc_atomic_end(__nesc_atomic); }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 122
    GenericSlotterP__slot[sim_node()] = (GenericSlotterP__slot[sim_node()] + 1) % GenericSlotterP__frameLength[sim_node()];
#line 122
    __nesc_atomic_end(__nesc_atomic); }

  GenericSlotterP__Slotter__slot(GenericSlotterP__slot[sim_node()]);

  GenericSlotterP__Alarm__start(GenericSlotterP__slotLength[sim_node()]);
}

# 78 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/BeaconSlotP.nc"
static error_t BeaconSlotP__Send__send(message_t *msg, uint8_t len)
#line 78
{
  uint8_t *payload;
  error_t status;
  uint32_t remaining;

  payload = BeaconSlotP__SubSend__getPayload(&BeaconSlotP__syncPkt[sim_node()], len);

  remaining = BeaconSlotP__SlotterControl__getRemaining();
  BeaconSlotP__write_timestamp(payload, remaining);

  status = BeaconSlotP__SubSend__send(&BeaconSlotP__syncPkt[sim_node()], BeaconSlotP__syncPktLen[sim_node()]);
  return status;
}

# 87 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static void *TossimActiveMessageC__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len)
#line 87
{
  return TossimActiveMessageC__Packet__getPayload(m, len);
}

# 59 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
static error_t SenderDispatcherP__Send__send(uint8_t slotType, message_t *msg, uint8_t len)
#line 59
{
  error_t err;
  message_t *prev_toSend;
  uint8_t prev_toSendLen;
#line 62
  uint8_t prev_id;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 64
    {
      prev_toSend = SenderDispatcherP__toSend[sim_node()];
      prev_toSendLen = SenderDispatcherP__toSendLen[sim_node()];
      prev_id = SenderDispatcherP__last_id[sim_node()];
    }
#line 68
    __nesc_atomic_end(__nesc_atomic); }

  if (prev_id != NO_SLOT) {
      return FAIL;
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 74
    {
      SenderDispatcherP__toSend[sim_node()] = msg;
      SenderDispatcherP__toSendLen[sim_node()] = len;
      SenderDispatcherP__last_id[sim_node()] = slotType;
    }
#line 78
    __nesc_atomic_end(__nesc_atomic); }
  err = SenderDispatcherP__SubSend__send(msg, len);
  if (err != SUCCESS) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 81
        {
          SenderDispatcherP__toSend[sim_node()] = prev_toSend;
          SenderDispatcherP__toSendLen[sim_node()] = prev_toSendLen;
          SenderDispatcherP__last_id[sim_node()] = prev_id;
        }
#line 85
        __nesc_atomic_end(__nesc_atomic); }
    }
  return err;
}

# 290 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static void TossimPacketModelC__send_transmit_done(sim_event_t *evt)
#line 290
{
  message_t *rval = TossimPacketModelC__sending[sim_node()];

#line 292
  TossimPacketModelC__sending[sim_node()] = (void *)0;
  TossimPacketModelC__transmitting[sim_node()] = FALSE;
  sim_log_debug(162U, "TossimPacketModelC", "PACKET: Signaling send done at %llu.\n", sim_time());
  TossimPacketModelC__Packet__sendDone(rval, TossimPacketModelC__running[sim_node()] ? SUCCESS : EOFF);
}

# 102 "/opt/tinyos-2.x/apps/wustl/upma/system/SenderDispatcherP.nc"
static void SenderDispatcherP__SubSend__sendDone(message_t *msg, error_t error)
#line 102
{
  uint8_t prev_last_id;

#line 104
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 104
    prev_last_id = SenderDispatcherP__last_id[sim_node()];
#line 104
    __nesc_atomic_end(__nesc_atomic); }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 106
    {
      if (msg == SenderDispatcherP__toSend[sim_node()]) {
          SenderDispatcherP__toSend[sim_node()] = (void *)0;
        }
    }
#line 110
    __nesc_atomic_end(__nesc_atomic); }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    SenderDispatcherP__last_id[sim_node()] = NO_SLOT;
#line 112
    __nesc_atomic_end(__nesc_atomic); }





  SenderDispatcherP__Send__sendDone(prev_last_id, msg, error);
}

# 197 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static error_t SimSchedulerBasicP__TaskBasic__postTask(uint8_t id)
{
  error_t result;

#line 200
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 200
    {
      result = SimSchedulerBasicP__pushTask(id) ? SUCCESS : EBUSY;
    }
#line 202
    __nesc_atomic_end(__nesc_atomic); }
  if (result == SUCCESS) {
      sim_log_debug(96U, "Scheduler", "Posting task %hhu.\n", id);
      SimSchedulerBasicP__sim_scheduler_submit_event();
    }
  else {
      sim_log_debug(97U, "Scheduler", "Posting task %hhu, but already posted.\n", id);
    }
  return result;
}

#line 69
static void SimSchedulerBasicP__sim_scheduler_submit_event(void )
#line 69
{
  if (SimSchedulerBasicP__sim_scheduler_event_pending[sim_node()] == FALSE) {
      SimSchedulerBasicP__sim_scheduler_event[sim_node()].time = sim_time() + SimSchedulerBasicP__sim_config_task_latency();
      sim_queue_insert(&SimSchedulerBasicP__sim_scheduler_event[sim_node()]);
      SimSchedulerBasicP__sim_scheduler_event_pending[sim_node()] = TRUE;
    }
}

# 601 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static void CpmModelC__Model__putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower, uint8_t channel_id)
#line 601
{

  gain_entry_t *neighborEntry = sim_gain_first(sim_node(), channel_id);

#line 604
  CpmModelC__requestAck[sim_node()] = ack;
  CpmModelC__outgoing[sim_node()] = msg;
  sim_log_debug(148U, "CpmModelC", "Node %i transmitting to %i, finishes at %llu, at channel: %d\n", sim_node(), dest, endTime, channel_id);
  while (neighborEntry != (void *)0) {
      int other = neighborEntry->mote;

      sim_log_debug(149U, "CpmModelC", "Node %i with neighborEntry:%d.\n", sim_node(), neighborEntry->mote);

      CpmModelC__sim_gain_put(other, msg, endTime, ack && (other == dest || dest == AM_BROADCAST_ADDR), power + sim_gain_value(sim_node(), other, channel_id), reversePower + sim_gain_value(other, sim_node(), channel_id), channel_id);
      neighborEntry = sim_gain_next(neighborEntry);
    }
}

#line 398
static double CpmModelC__packetNoise(CpmModelC__receive_message_t *msg)
#line 398
{
  double noise = CpmModelC__noise_hash_generation();
  CpmModelC__receive_message_t *list = CpmModelC__outstandingReceptionHead[sim_node()];
  int count = 0;

#line 402
  noise = pow(10.0, noise / 10.0);






  while (list != (void *)0) {


      sim_log_debug(130U, "CpmModelC", "packetReceive: outstanding from %d\n", list->source);
      count++;

      if (list->channel != sim_mote_get_radio_channel(sim_node())) {
          list = list->next;
          continue;
        }
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  sim_log_debug(131U, "CpmModelC", "packetReceive: outstanding count %d noise %lf at %lf\n", count, noise, (double )sim_time() / sim_ticks_per_sec());
  return noise;
}

#line 127
static double CpmModelC__noise_hash_generation(void )
#line 127
{
  double CT = CpmModelC__timeInMs();
  uint32_t quotient = (sim_time_t )(CT * 10) / 10;
  uint8_t remain = (uint8_t )((sim_time_t )(CT * 10) % 10);
  double noise_val;
  uint16_t node_id = sim_node();

#line 133
  sim_log_debug(121U, "CpmModelC", "IN: noise_hash_generation() with CT: %f and channel id: %d and sensor id: %d\n", CT, sim_mote_get_radio_channel(node_id), node_id);
  if (5 <= remain && remain < 10) {
      noise_val = (double )sim_noise_generate(node_id, quotient + 1, sim_mote_get_radio_channel(node_id));
    }
  else {
      noise_val = (double )sim_noise_generate(node_id, quotient, sim_mote_get_radio_channel(node_id));
    }
  sim_log_debug(122U, "CpmModelC", "@ %s: OUT: noise_hash_generation(): %lf\n", sim_time_string(), noise_val);

  return noise_val;
}

# 92 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
  uint8_t sim_mote_get_radio_channel(int mote)
#line 92
{
  uint8_t result;
  int tmp = sim_node();

#line 95
  sim_set_node(mote);
  result = SimMoteP__SimMote__getRadioChannel();
  sim_set_node(tmp);
  return result;
}

# 254 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static bool CpmModelC__shouldReceive(double SNR, int isCheckReceive)
#line 254
{
  double prr = CpmModelC__prr_estimate_from_snr(SNR);
  double coin = RandomUniform();
  uint16_t node_id = sim_node();

  FILE *fp;

#line 281
  if (prr != 0 && prr != 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 285
        prr = 0.0;
        }
    }
#line 287
  sim_log_debug(127U, "CpmModelC", "Sensor: %u, channel is %u, returned PRR	 in shouldReceive is %lf\n", node_id, sim_mote_get_radio_channel(node_id), prr);


  return prr;
}

# 19 "/opt/tinyos-2.x/tos/lib/tossim/sim_lqi.c"
  uint8_t sim_lqi_generate(double SNR)
{
  uint8_t coin = RandomUniform() * 100;
  uint8_t i;
#line 22
  uint8_t closest_i = 0;


  for (i = 0; i < allSnr_len; i++) {
      if (allSnr[i].snr == SNR) {
          break;
        }
      else 
#line 28
        {
          if (fabs(SNR - allSnr[i].snr) < fabs(SNR - allSnr[closest_i].snr)) {
              closest_i = i;
            }
        }
    }
  i = i == allSnr_len ? closest_i : i;


  return bi_search(allSnr[i].lqi, 0, allSnr[i].numLqi - 1, coin);
}

#line 5
static uint8_t bi_search(lqi_dist_t *lqi, uint8_t low_i, uint8_t high_i, uint8_t coin)
{
  uint8_t i = low_i + (high_i - low_i + 1) / 2;
  uint8_t fromCDF = i == 0 ? 0 : lqi[i - 1].cdf;
  uint8_t toCDF = lqi[i].cdf;

#line 10
  if (fromCDF <= coin && coin < toCDF) {
      return lqi[i].lqi;
    }
  else {
#line 12
    if (fromCDF > coin) {
        return bi_search(lqi, low_i, i - 1, coin);
      }
    else 
#line 14
      {
        return bi_search(lqi, i + 1, high_i, coin);
      }
    }
}

# 317 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static bool TossimPacketModelC__GainRadioModel__shouldAck(message_t *msg)
#line 317
{
  if (TossimPacketModelC__running[sim_node()] && !TossimPacketModelC__transmitting[sim_node()]) {
      return TossimPacketModelC__Packet__shouldAck(msg);
    }
  else {
      return FALSE;
    }
}

# 224 "/opt/tinyos-2.x/tos/lib/tossim/CpmModelC.nc"
static void CpmModelC__sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC__receive_message_t *r)
#line 224
{
  sim_event_t *ackEvent = (sim_event_t *)malloc(sizeof(sim_event_t ));

  ackEvent->mote = source;
  ackEvent->force = 1;
  ackEvent->cancelled = 0;
  ackEvent->time = t;
  ackEvent->handle = CpmModelC__sim_gain_ack_handle;
  ackEvent->cleanup = sim_queue_cleanup_event;
  ackEvent->data = r;

  sim_queue_insert(ackEvent);
}

#line 217
static bool CpmModelC__Model__clearChannel(void )
#line 217
{
  sim_log_debug(125U, "CpmModelC", "Checking clear channel @ %s: %f <= %f \n", sim_time_string(), (double )CpmModelC__packetNoise((void *)0), CpmModelC__clearThreshold[sim_node()]);


  return CpmModelC__packetNoise((void *)0) < CpmModelC__clearThreshold[sim_node()];
}

# 249 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/TossimPacketModelC.nc"
static void TossimPacketModelC__send_transmit_with_cca(sim_event_t *evt)
#line 249
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC__getMetadata(TossimPacketModelC__sending[sim_node()]);

#line 252
  duration = 8 * (TossimPacketModelC__sendingLength[sim_node()] + TossimPacketModelC__sim_packet_header_length());
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();
  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  evt->time += duration;
  evt->handle = TossimPacketModelC__send_transmit_done;

  sim_log_debug(160U, "TossimPacketModelC", "PACKET: Broadcasting packet to everyone.\n");
  TossimPacketModelC__GainRadioModel__putOnAirTo(TossimPacketModelC__destNode[sim_node()], TossimPacketModelC__sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0, sim_mote_get_radio_channel(sim_node()));
  __nesc_hton_uint8(metadata->ack.nxdata, 0);
  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());
  sim_log_debug(161U, "TossimPacketModelC", "PACKET: Send done at %llu.\n", evt->time);
  sim_queue_insert(evt);
}

# 80 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
  error_t sim_mote_set_radio_channel(int mote, uint8_t newRadioChannel)
#line 80
{
  error_t result;
  int tmp = sim_node();

#line 83
  sim_set_node(mote);
  result = SimMoteP__SimMote__setRadioChannel(newRadioChannel);
  sim_set_node(tmp);
  return result;
}

# 40 "/opt/tinyos-2.x/tos/chips/cc2420/control/sim/CC2420ControlP.nc"
static error_t CC2420ControlP__CC2420Config__sync(void )
#line 40
{
  sim_log_debug(119U, "CC2420Config", "CC2420Config: sync: autoAck %d, hwAutoAck %d\n", CC2420ControlP__autoAck[sim_node()], CC2420ControlP__hwAutoAck[sim_node()]);
  sim_mote_set_radio_channel(sim_node(), CC2420ControlP__channel[sim_node()]);
  CC2420ControlP__syncDoneTask__postTask();
  return SUCCESS;
}

# 137 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static void TossimActiveMessageC__AMPacket__setDestination(message_t *amsg, am_addr_t addr)
#line 137
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 139
  __nesc_hton_uint16(header->dest.nxdata, addr);
}

# 71 "/opt/tinyos-2.x/apps/wustl/upma/interfaces/AsyncSend.nc"
static void * /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__getPayload(message_t * msg, uint8_t len){
#line 71
  void *__nesc_result;
#line 71

#line 71
  __nesc_result = SenderDispatcherP__Send__getPayload(TDMA_SLOT, msg, len);
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 78 "/opt/tinyos-2.x/apps/wustl/upma/system/GenericSlotSenderP.nc"
static error_t /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Send__send(message_t *msg, uint8_t len)
#line 78
{
  error_t err;
  uint8_t state_;

  if (msg == (void *)0) {
#line 82
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 84
    {
      state_ = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()];

      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()] = msg;
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[sim_node()] = len;

      if (0 == 0) {
          /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_OFFSET;
        }
      else 
#line 92
        {
          /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_START;
        }
    }
#line 95
    __nesc_atomic_end(__nesc_atomic); }

  if (state_ != /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_END) {
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__alarm(0);
      return FAIL;
    }


  if (/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] == /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_OFFSET) {
      err = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__SubSend__send(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[sim_node()], /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[sim_node()]);
      if (err != SUCCESS) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 106
            /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[sim_node()] = /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__S_END;
#line 106
            __nesc_atomic_end(__nesc_atomic); }
        }
    }
  else 
#line 108
    {
      /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__Alarm__start(0);
      err = SUCCESS;
    }



  return err;
}

# 96 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static void /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__set_alarm(void )
{
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type now = /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__Counter__get();
#line 98
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type expires;
#line 98
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type remaining;




  expires = /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] + /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()];


  remaining = (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__to_size_type )(expires - now);


  if (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] <= now) 
    {
      if (expires >= /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] && 
      expires <= now) {
        remaining = 0;
        }
    }
  else {
      if (expires >= /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] || 
      expires <= now) {
        remaining = 0;
        }
    }
#line 121
  if (remaining > /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__MAX_DELAY) 
    {
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] = now + /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__MAX_DELAY;
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()] = remaining - /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__MAX_DELAY;
      remaining = /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__MAX_DELAY;
    }
  else 
    {
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[sim_node()] += /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()];
      /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[sim_node()] = 0;
    }
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__AlarmFrom__startAt((/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_size_type )now << 5, 
  (/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__from_size_type )remaining << 5);
}

# 69 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__Counter__get(void )
{
  /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type rv = 0;

#line 72
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__upper_count_type high = /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[sim_node()];
      /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__from_size_type low = /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__get();

#line 76
      if (/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__isOverflowPending()) 
        {






          high++;
          low = /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__CounterFrom__get();
        }
      {
        /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type high_to = high;
        /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__to_size_type low_to = low >> /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__LOW_SHIFT_RIGHT;

#line 90
        rv = (high_to << /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__HIGH_SHIFT_LEFT) | low_to;
      }
    }
#line 92
    __nesc_atomic_end(__nesc_atomic); }
  return rv;
}

# 905 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static void PureTDMASchedulerP__readTopoFile(void )
#line 905
{

  char *line = (void *)0;
  size_t len = 0;
  ssize_t read;

  uint8_t line_counter = 0;

  char *token;

  uint8_t counter = 0;



  PureTDMASchedulerP__topo_fp[sim_node()] = fopen("/Users/wangwenchen/github/paper2_experiment/topology.txt", "r");
  if (PureTDMASchedulerP__topo_fp[sim_node()] == (void *)0) {
    exit(1);
    }
  while (getline(&line, &len, PureTDMASchedulerP__topo_fp[sim_node()]) != -1) {




      token = (void *)0;
      counter = 0;


      token = strtok(line, " ");



      while (token != (void *)0) 
        {


          token = strtok((void *)0, " ");

          counter++;
        }

      if (PureTDMASchedulerP__MAXLEVELNODE[sim_node()] < counter && line_counter != 0) {
          PureTDMASchedulerP__MAXLEVELNODE[sim_node()] = counter;
        }




      if (line_counter == 0) {
          PureTDMASchedulerP__CURRNODES[sim_node()] = counter;
        }
      else 
#line 954
        {
          PureTDMASchedulerP__schedule_counter[sim_node()][line_counter - 1] = counter;
        }


      line_counter++;
    }





  PureTDMASchedulerP__schedule_len[sim_node()] = line_counter - 1;





  fclose(PureTDMASchedulerP__topo_fp[sim_node()]);

  if (line) {
      free(line);
    }
}

#line 1112
static void PureTDMASchedulerP__generateSchedule(void )
#line 1112
{
  char *line = (void *)0;
  size_t len = 0;
  ssize_t read;

  uint8_t line_counter = 0;

  char *token;

  uint8_t counter = 0;

  uint8_t i;
#line 1123
  uint8_t j;

  uint8_t node_index = 0;

  PureTDMASchedulerP__node_list[sim_node()][PureTDMASchedulerP__CURRNODES[sim_node()]];



  PureTDMASchedulerP__topo_fp[sim_node()] = fopen("/Users/wangwenchen/github/paper2_experiment/topology.txt", "r");

  if (PureTDMASchedulerP__topo_fp[sim_node()] == (void *)0) {
    exit(1);
    }

  getline(&line, &len, PureTDMASchedulerP__topo_fp[sim_node()]);
  line_counter = 0;


  while ((read = getline(&line, &len, PureTDMASchedulerP__topo_fp[sim_node()])) != -1) {

      int counter = 0;



      PureTDMASchedulerP__up_schedule[sim_node()][line_counter][counter] = PureTDMASchedulerP__schedule_counter[sim_node()][line_counter];




      token = strtok(line, " ");
      counter++;


      PureTDMASchedulerP__up_schedule[sim_node()][line_counter][counter] = atoi(token);





      while (token != (void *)0) 
        {


          token = strtok((void *)0, " ");

          counter++;

          if (counter <= PureTDMASchedulerP__schedule_counter[sim_node()][line_counter]) {

              PureTDMASchedulerP__up_schedule[sim_node()][line_counter][counter] = atoi(token);
            }
        }







      line_counter++;
    }




  for (i = 0; i < PureTDMASchedulerP__schedule_len[sim_node()]; i++) {

      for (j = 1; j <= PureTDMASchedulerP__up_schedule[sim_node()][i][0]; j++) {


          PureTDMASchedulerP__node_list[sim_node()][node_index] = PureTDMASchedulerP__up_schedule[sim_node()][i][j];


          node_index += 1;
        }
    }






  fclose(PureTDMASchedulerP__topo_fp[sim_node()]);
}

# 96 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static void /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__set_alarm(void )
{
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type now = /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__Counter__get();
#line 98
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type expires;
#line 98
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type remaining;




  expires = /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] + /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()];


  remaining = (/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__to_size_type )(expires - now);


  if (/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] <= now) 
    {
      if (expires >= /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] && 
      expires <= now) {
        remaining = 0;
        }
    }
  else {
      if (expires >= /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] || 
      expires <= now) {
        remaining = 0;
        }
    }
#line 121
  if (remaining > /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__MAX_DELAY) 
    {
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] = now + /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__MAX_DELAY;
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()] = remaining - /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__MAX_DELAY;
      remaining = /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__MAX_DELAY;
    }
  else 
    {
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[sim_node()] += /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()];
      /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[sim_node()] = 0;
    }
  /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__AlarmFrom__startAt((/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_size_type )now << 5, 
  (/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__from_size_type )remaining << 5);
}

# 142 "/opt/tinyos-2.x/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC__AMPacket__source(message_t *amsg)
#line 142
{
  tossim_header_t *header = TossimActiveMessageC__getHeader(amsg);

#line 144
  return __nesc_ntoh_uint16(header->src.nxdata);
}

# 981 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static int PureTDMASchedulerP__find_delay(int node)
#line 981
{
  uint8_t i;

#line 983
  for (i = 0; i < PureTDMASchedulerP__CURRNODES[sim_node()]; i++) {
      if (PureTDMASchedulerP__node_list[sim_node()][i] == node) {
          return i + 1;
        }
    }


  return PureTDMASchedulerP__CURRNODES[sim_node()];
}

# 102 "/opt/tinyos-2.x/tos/lib/tossim/sim_packet.c"
  uint8_t sim_packet_max_length(sim_packet_t *msg)
#line 102
{
  return 156;
}

  sim_packet_t *sim_packet_allocate()
#line 106
{
  return (sim_packet_t *)malloc(sizeof(message_t ));
}

  void sim_packet_free(sim_packet_t *p)
#line 110
{
  printf("sim_packet.c: Freeing packet %p\n", p);
  free(p);
}

  void sim_packet_set_dsn(sim_packet_t *msg, uint8_t dsn)
#line 115
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 117
  __nesc_hton_uint8(hdr->dsn.nxdata, dsn);
}

  uint8_t sim_packet_dsn(sim_packet_t *msg)
#line 120
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 122
  return __nesc_ntoh_uint8(hdr->dsn.nxdata);
}

# 43 "/opt/tinyos-2.x/tos/lib/tossim/SimMainP.nc"
  int sim_main_start_mote(void )
#line 43
{
  char timeBuf[128];

#line 45
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 45
    {






      SimMainP__Scheduler__init();





      SimMainP__PlatformInit__init();
      while (SimMainP__Scheduler__runNextTask()) ;





      SimMainP__SoftwareInit__init();
      while (SimMainP__Scheduler__runNextTask()) ;
    }
#line 67
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  sim_print_now(timeBuf, 128);
  sim_log_debug(92U, "SimMainP", "Mote %li signaling boot at time %s.\n", sim_node(), timeBuf);
  SimMainP__Boot__booted();





  return 0;
}

# 172 "/opt/tinyos-2.x/tos/lib/tossim/SimSchedulerBasicP.nc"
static bool SimSchedulerBasicP__Scheduler__runNextTask(void )
{
  uint8_t nextTask;

#line 175
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      nextTask = SimSchedulerBasicP__popTask();
      if (nextTask == SimSchedulerBasicP__NO_TASK) 
        {
          sim_log_debug(94U, "Scheduler", "Told to run next task, but no task to run.\n");
          {
            unsigned char __nesc_temp = 
#line 181
            FALSE;

            {
#line 181
              __nesc_atomic_end(__nesc_atomic); 
#line 181
              return __nesc_temp;
            }
          }
        }
    }
#line 185
    __nesc_atomic_end(__nesc_atomic); }
#line 184
  sim_log_debug(95U, "Scheduler", "Running task %hhu.\n", nextTask);
  SimSchedulerBasicP__TaskBasic__runTask(nextTask);
  return TRUE;
}

# 155 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(uint8_t last, message_t * msg, error_t err)
#line 155
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[sim_node()][last].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(last, msg, err);
}

# 48 "TestNetworkC.nc"
static void TestNetworkC__RadioControl__startDone(error_t err)
#line 48
{
  if (err != SUCCESS) {
      TestNetworkC__RadioControl__start();
    }
  else {
      TestNetworkC__CC2420Config__setChannel(26);
      TestNetworkC__CC2420Config__sync();
    }
}

# 294 "/opt/tinyos-2.x/apps/wustl/upma/lib/macs/paper2_experiment/PureTDMASchedulerP.nc"
static error_t PureTDMASchedulerP__SplitControl__start(void )
#line 294
{
  error_t err;

#line 296
  if (PureTDMASchedulerP__init[sim_node()] == FALSE) {
      PureTDMASchedulerP__FrameConfiguration__setSlotLength(PureTDMASchedulerP__slotSize[sim_node()]);
      PureTDMASchedulerP__FrameConfiguration__setFrameLength(PureTDMASchedulerP__bi[sim_node()] + 1);
    }

  err = PureTDMASchedulerP__RadioPowerControl__start();
  return err;
}

# 37 "/Users/wangwenchen/wcps_apps/pure-tdma/sim/CounterMicro16P.nc"
static void CounterMicro16P__scheduleOverflow(void )
{
  sim_time_t nextOverflow = CounterMicro16P__t0[sim_node()] + 65535 * sim_ticks_per_sec() / 1024UL / 1024UL;

  sim_event_t *overflowEvent = sim_queue_allocate_event();

#line 42
  overflowEvent->handle = CounterMicro16P__handleOverflow;
  overflowEvent->cleanup = sim_queue_cleanup_none;
  overflowEvent->time = nextOverflow;
  sim_queue_insert(overflowEvent);
}

# 136 "/opt/tinyos-2.x/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_euid(int mote)
#line 136
{
  long long int result;
  int tmp = sim_node();

#line 139
  sim_set_node(mote);
  result = SimMoteP__SimMote__getEuid();
  sim_set_node(tmp);
  return result;
}

  void sim_mote_set_euid(int mote, long long int id)
#line 145
{
  int tmp = sim_node();

#line 147
  sim_set_node(mote);
  SimMoteP__SimMote__setEuid(id);
  sim_set_node(tmp);
}

  long long int sim_mote_start_time(int mote)
#line 152
{
  long long int result;
  int tmp = sim_node();

#line 155
  sim_set_node(mote);
  result = SimMoteP__SimMote__getStartTime();
  sim_set_node(tmp);
  return result;
}

  int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)
#line 161
{
  int result;
  int tmpID = sim_node();

#line 164
  sim_set_node(mote);
  result = SimMoteP__SimMote__getVariableInfo(name, ptr, len);
  sim_log_debug(99U, "SimMoteP", "Fetched %s of %i to be %p with len %i (result %i)\n", name, mote, *ptr, *len, result);
  sim_set_node(tmpID);
  return result;
}

  void sim_mote_set_start_time(int mote, long long int t)
#line 171
{
  int tmpID = sim_node();

#line 173
  sim_set_node(mote);
  SimMoteP__startTime[sim_node()] = t;
  sim_log_debug(100U, "SimMoteP", "Setting start time to %llu\n", SimMoteP__startTime[sim_node()]);
  sim_set_node(tmpID);
  return;
}











  void sim_mote_turn_on(int mote)
#line 190
{
  int tmp = sim_node();

#line 192
  sim_set_node(mote);
  SimMoteP__SimMote__turnOn();
  sim_set_node(tmp);
}

#line 118
static void SimMoteP__SimMote__turnOn(void )
#line 118
{
  if (!SimMoteP__isOn[sim_node()]) {
      if (SimMoteP__bootEvent[sim_node()] != (void *)0) {
          SimMoteP__bootEvent[sim_node()]->cancelled = TRUE;
        }
      __nesc_nido_initialise(sim_node());
      SimMoteP__startTime[sim_node()] = sim_time();
      sim_log_debug(98U, "SimMoteP", "Setting start time to %llu\n", SimMoteP__startTime[sim_node()]);
      SimMoteP__isOn[sim_node()] = TRUE;
      sim_main_start_mote();
    }
}

#line 197
  void sim_mote_turn_off(int mote)
#line 197
{
  int tmp = sim_node();

#line 199
  sim_set_node(mote);
  SimMoteP__SimMote__turnOff();

  sim_set_node(tmp);
}










  void sim_mote_enqueue_boot_event(int mote)
#line 214
{
  int tmp = sim_node();

#line 216
  sim_set_node(mote);

  if (SimMoteP__bootEvent[sim_node()] != (void *)0) {
      if (SimMoteP__bootEvent[sim_node()]->time == SimMoteP__startTime[sim_node()]) {

          SimMoteP__bootEvent[sim_node()]->cancelled = FALSE;
          return;
        }
      else {
          SimMoteP__bootEvent[sim_node()]->cancelled = TRUE;
        }
    }

  SimMoteP__bootEvent[sim_node()] = (sim_event_t *)malloc(sizeof(sim_event_t ));
  SimMoteP__bootEvent[sim_node()]->time = SimMoteP__startTime[sim_node()];
  SimMoteP__bootEvent[sim_node()]->mote = mote;
  SimMoteP__bootEvent[sim_node()]->force = TRUE;
  SimMoteP__bootEvent[sim_node()]->data = (void *)0;
  SimMoteP__bootEvent[sim_node()]->handle = SimMoteP__sim_mote_boot_handle;
  SimMoteP__bootEvent[sim_node()]->cleanup = sim_queue_cleanup_event;
  sim_queue_insert(SimMoteP__bootEvent[sim_node()]);

  sim_set_node(tmp);
}

/* Nido variable resolver function */

static int __nesc_nido_resolve(int __nesc_mote,
                               char* varname,
                               uintptr_t* addr, size_t* size)
{
  /* Module TestNetworkC */
  if (!strcmp(varname, "TestNetworkC__packet"))
  {
    *addr = (uintptr_t)&TestNetworkC__packet[__nesc_mote];
    *size = sizeof(TestNetworkC__packet[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TestNetworkC__rcm"))
  {
    *addr = (uintptr_t)&TestNetworkC__rcm[__nesc_mote];
    *size = sizeof(TestNetworkC__rcm[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TestNetworkC__rcmr"))
  {
    *addr = (uintptr_t)&TestNetworkC__rcmr[__nesc_mote];
    *size = sizeof(TestNetworkC__rcmr[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TestNetworkC__msgamr"))
  {
    *addr = (uintptr_t)&TestNetworkC__msgamr[__nesc_mote];
    *size = sizeof(TestNetworkC__msgamr[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TestNetworkC__tnmsg_in_transit"))
  {
    *addr = (uintptr_t)&TestNetworkC__tnmsg_in_transit[__nesc_mote];
    *size = sizeof(TestNetworkC__tnmsg_in_transit[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TestNetworkC__sendBusy"))
  {
    *addr = (uintptr_t)&TestNetworkC__sendBusy[__nesc_mote];
    *size = sizeof(TestNetworkC__sendBusy[__nesc_mote]);
    return 0;
  }

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP__0 */

  /* Module HplAtm128GeneralIOPinP__1 */

  /* Module HplAtm128GeneralIOPinP__2 */

  /* Module HplAtm128GeneralIOPinP__3 */

  /* Module HplAtm128GeneralIOPinP__4 */

  /* Module HplAtm128GeneralIOPinP__5 */

  /* Module HplAtm128GeneralIOPinP__6 */

  /* Module HplAtm128GeneralIOPinP__7 */

  /* Module HplAtm128GeneralIOPinP__8 */

  /* Module HplAtm128GeneralIOPinP__9 */

  /* Module HplAtm128GeneralIOPinP__10 */

  /* Module HplAtm128GeneralIOPinP__11 */

  /* Module HplAtm128GeneralIOPinP__12 */

  /* Module HplAtm128GeneralIOPinP__13 */

  /* Module HplAtm128GeneralIOPinP__14 */

  /* Module HplAtm128GeneralIOPinP__15 */

  /* Module HplAtm128GeneralIOPinP__16 */

  /* Module HplAtm128GeneralIOPinP__17 */

  /* Module HplAtm128GeneralIOPinP__18 */

  /* Module HplAtm128GeneralIOPinP__19 */

  /* Module HplAtm128GeneralIOPinP__20 */

  /* Module HplAtm128GeneralIOPinP__21 */

  /* Module HplAtm128GeneralIOPinP__22 */

  /* Module HplAtm128GeneralIOPinP__23 */

  /* Module HplAtm128GeneralIOPinP__24 */

  /* Module HplAtm128GeneralIOPinP__25 */

  /* Module HplAtm128GeneralIOPinP__26 */

  /* Module HplAtm128GeneralIOPinP__27 */

  /* Module HplAtm128GeneralIOPinP__28 */

  /* Module HplAtm128GeneralIOPinP__29 */

  /* Module HplAtm128GeneralIOPinP__30 */

  /* Module HplAtm128GeneralIOPinP__31 */

  /* Module HplAtm128GeneralIOPinP__32 */

  /* Module HplAtm128GeneralIOPinP__33 */

  /* Module HplAtm128GeneralIOPinP__34 */

  /* Module HplAtm128GeneralIOPinP__35 */

  /* Module HplAtm128GeneralIOPinP__36 */

  /* Module HplAtm128GeneralIOPinP__37 */

  /* Module HplAtm128GeneralIOPinP__38 */

  /* Module HplAtm128GeneralIOPinP__39 */

  /* Module HplAtm128GeneralIOPinP__40 */

  /* Module HplAtm128GeneralIOPinP__41 */

  /* Module HplAtm128GeneralIOPinP__42 */

  /* Module HplAtm128GeneralIOPinP__43 */

  /* Module HplAtm128GeneralIOPinP__44 */

  /* Module HplAtm128GeneralIOPinP__45 */

  /* Module HplAtm128GeneralIOPinP__46 */

  /* Module HplAtm128GeneralIOPinP__47 */

  /* Module HplAtm128GeneralIOSlowPinP__0 */

  /* Module HplAtm128GeneralIOSlowPinP__1 */

  /* Module HplAtm128GeneralIOSlowPinP__2 */

  /* Module HplAtm128GeneralIOSlowPinP__3 */

  /* Module HplAtm128GeneralIOSlowPinP__4 */

  /* Module HplAtm128GeneralIOSlowPinP__5 */

  /* Module HplAtm128GeneralIOSlowPinP__6 */

  /* Module HplAtm128GeneralIOSlowPinP__7 */

  /* Module HplAtm128GeneralIOSlowPinP__8 */

  /* Module HplAtm128GeneralIOSlowPinP__9 */

  /* Module HplAtm128GeneralIOSlowPinP__10 */

  /* Module HplAtm128GeneralIOSlowPinP__11 */

  /* Module HplAtm128GeneralIOSlowPinP__12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  if (!strcmp(varname, "SimSchedulerBasicP__m_head"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP__m_head[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP__m_head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP__m_tail"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP__m_tail[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP__m_tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP__m_next"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP__m_next[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP__m_next[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP__sim_scheduler_event_pending"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP__sim_scheduler_event_pending[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP__sim_scheduler_event_pending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP__sim_scheduler_event"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP__sim_scheduler_event[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP__sim_scheduler_event[__nesc_mote]);
    return 0;
  }

  /* Module SimMoteP */
  if (!strcmp(varname, "SimMoteP__euid"))
  {
    *addr = (uintptr_t)&SimMoteP__euid[__nesc_mote];
    *size = sizeof(SimMoteP__euid[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP__startTime"))
  {
    *addr = (uintptr_t)&SimMoteP__startTime[__nesc_mote];
    *size = sizeof(SimMoteP__startTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP__isOn"))
  {
    *addr = (uintptr_t)&SimMoteP__isOn[__nesc_mote];
    *size = sizeof(SimMoteP__isOn[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP__bootEvent"))
  {
    *addr = (uintptr_t)&SimMoteP__bootEvent[__nesc_mote];
    *size = sizeof(SimMoteP__bootEvent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP__radioChannel"))
  {
    *addr = (uintptr_t)&SimMoteP__radioChannel[__nesc_mote];
    *size = sizeof(SimMoteP__radioChannel[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP__tcp_msg"))
  {
    *addr = (uintptr_t)&SimMoteP__tcp_msg[__nesc_mote];
    *size = sizeof(SimMoteP__tcp_msg[__nesc_mote]);
    return 0;
  }

  /* Module CC2420CsmaP */
  if (!strcmp(varname, "CC2420CsmaP__buffer"))
  {
    *addr = (uintptr_t)&CC2420CsmaP__buffer[__nesc_mote];
    *size = sizeof(CC2420CsmaP__buffer[__nesc_mote]);
    return 0;
  }

  /* Module AsyncReceiveAdapterP */
  if (!strcmp(varname, "AsyncReceiveAdapterP__msg_"))
  {
    *addr = (uintptr_t)&AsyncReceiveAdapterP__msg_[__nesc_mote];
    *size = sizeof(AsyncReceiveAdapterP__msg_[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "AsyncReceiveAdapterP__payload_"))
  {
    *addr = (uintptr_t)&AsyncReceiveAdapterP__payload_[__nesc_mote];
    *size = sizeof(AsyncReceiveAdapterP__payload_[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "AsyncReceiveAdapterP__len_"))
  {
    *addr = (uintptr_t)&AsyncReceiveAdapterP__len_[__nesc_mote];
    *size = sizeof(AsyncReceiveAdapterP__len_[__nesc_mote]);
    return 0;
  }

  /* Module AsyncSendAdapterP */
  if (!strcmp(varname, "AsyncSendAdapterP__msg_"))
  {
    *addr = (uintptr_t)&AsyncSendAdapterP__msg_[__nesc_mote];
    *size = sizeof(AsyncSendAdapterP__msg_[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "AsyncSendAdapterP__len_"))
  {
    *addr = (uintptr_t)&AsyncSendAdapterP__len_[__nesc_mote];
    *size = sizeof(AsyncSendAdapterP__len_[__nesc_mote]);
    return 0;
  }

  /* Module PureTDMASchedulerP */
  if (!strcmp(varname, "PureTDMASchedulerP__m_entry"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__m_entry[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__m_entry[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__log_payload"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__log_payload[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__log_payload[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__rcmr"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__rcmr[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__rcmr[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__isChild"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__isChild[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__isChild[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__isParent"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__isParent[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__isParent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__isSibling"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__isSibling[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__isSibling[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__self_pos"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__self_pos[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__self_pos[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__receiving_num"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__receiving_num[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__receiving_num[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__totalChildren"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__totalChildren[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__totalChildren[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__totalParents"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__totalParents[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__totalParents[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__flag"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__flag[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__flag[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__MAXLEVELNODE"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__MAXLEVELNODE[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__MAXLEVELNODE[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__CURRNODES"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__CURRNODES[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__CURRNODES[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__delay_fp"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__delay_fp[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__delay_fp[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__topo_fp"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__topo_fp[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__topo_fp[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__res_list"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__res_list[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__res_list[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__delay_list"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__delay_list[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__delay_list[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__send_counter"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__send_counter[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__send_counter[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__is_primary"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__is_primary[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__is_primary[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__rev_counter"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__rev_counter[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__rev_counter[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__init"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__init[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__init[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__slotSize"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__slotSize[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__slotSize[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__bi"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__bi[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__bi[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__sd"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__sd[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__sd[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__cap"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__cap[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__cap[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__coordinatorId"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__coordinatorId[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__coordinatorId[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__i"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__i[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__i[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__j"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__j[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__j[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__k"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__k[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__k[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__toSend"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__toSend[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__toSend[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__toSendLen"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__toSendLen[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__toSendLen[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__schedule_counter"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__schedule_counter[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__schedule_counter[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__up_schedule"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__up_schedule[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__up_schedule[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__avg_prob"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__avg_prob[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__avg_prob[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__node_list"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__node_list[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__node_list[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__schedule_len"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__schedule_len[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__schedule_len[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__lp_intervals"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__lp_intervals[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__lp_intervals[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__superframe_length"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__superframe_length[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__superframe_length[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__sync"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__sync[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__sync[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PureTDMASchedulerP__requestStop"))
  {
    *addr = (uintptr_t)&PureTDMASchedulerP__requestStop[__nesc_mote];
    *size = sizeof(PureTDMASchedulerP__requestStop[__nesc_mote]);
    return 0;
  }

  /* Module LedsP */

  /* Module GenericSlotSenderP__0 */
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[__nesc_mote]);
    return 0;
  }

  /* Module AlarmMicro16P__0 */
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[__nesc_mote]);
    return 0;
  }

  /* Module CounterMicro16P */
  if (!strcmp(varname, "CounterMicro16P__t0"))
  {
    *addr = (uintptr_t)&CounterMicro16P__t0[__nesc_mote];
    *size = sizeof(CounterMicro16P__t0[__nesc_mote]);
    return 0;
  }

  /* Module TransformAlarmC__0 */
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt"))
  {
    *addr = (uintptr_t)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[__nesc_mote];
    *size = sizeof(/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[__nesc_mote]);
    return 0;
  }

  /* Module TransformCounterC__0 */
  if (!strcmp(varname, "/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper"))
  {
    *addr = (uintptr_t)&/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[__nesc_mote];
    *size = sizeof(/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[__nesc_mote]);
    return 0;
  }

  /* Module GenericSlotterP */
  if (!strcmp(varname, "GenericSlotterP__slot"))
  {
    *addr = (uintptr_t)&GenericSlotterP__slot[__nesc_mote];
    *size = sizeof(GenericSlotterP__slot[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "GenericSlotterP__slotLength"))
  {
    *addr = (uintptr_t)&GenericSlotterP__slotLength[__nesc_mote];
    *size = sizeof(GenericSlotterP__slotLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "GenericSlotterP__frameLength"))
  {
    *addr = (uintptr_t)&GenericSlotterP__frameLength[__nesc_mote];
    *size = sizeof(GenericSlotterP__frameLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "GenericSlotterP__sync"))
  {
    *addr = (uintptr_t)&GenericSlotterP__sync[__nesc_mote];
    *size = sizeof(GenericSlotterP__sync[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "GenericSlotterP__nextFire"))
  {
    *addr = (uintptr_t)&GenericSlotterP__nextFire[__nesc_mote];
    *size = sizeof(GenericSlotterP__nextFire[__nesc_mote]);
    return 0;
  }

  /* Module AlarmMicro16P__1 */
  if (!strcmp(varname, "/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm"))
  {
    *addr = (uintptr_t)&/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm[__nesc_mote];
    *size = sizeof(/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero"))
  {
    *addr = (uintptr_t)&/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[__nesc_mote];
    *size = sizeof(/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt"))
  {
    *addr = (uintptr_t)&/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[__nesc_mote];
    *size = sizeof(/*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[__nesc_mote]);
    return 0;
  }

  /* Module TransformAlarmC__1 */
  if (!strcmp(varname, "/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0"))
  {
    *addr = (uintptr_t)&/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[__nesc_mote];
    *size = sizeof(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt"))
  {
    *addr = (uintptr_t)&/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[__nesc_mote];
    *size = sizeof(/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[__nesc_mote]);
    return 0;
  }

  /* Module TransformCounterC__1 */
  if (!strcmp(varname, "/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper"))
  {
    *addr = (uintptr_t)&/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[__nesc_mote];
    *size = sizeof(/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[__nesc_mote]);
    return 0;
  }

  /* Module SenderDispatcherP */
  if (!strcmp(varname, "SenderDispatcherP__toSend"))
  {
    *addr = (uintptr_t)&SenderDispatcherP__toSend[__nesc_mote];
    *size = sizeof(SenderDispatcherP__toSend[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SenderDispatcherP__toSendLen"))
  {
    *addr = (uintptr_t)&SenderDispatcherP__toSendLen[__nesc_mote];
    *size = sizeof(SenderDispatcherP__toSendLen[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SenderDispatcherP__last_id"))
  {
    *addr = (uintptr_t)&SenderDispatcherP__last_id[__nesc_mote];
    *size = sizeof(SenderDispatcherP__last_id[__nesc_mote]);
    return 0;
  }

  /* Module DummyChannelMonitorC */

  /* Module BeaconSlotP */
  if (!strcmp(varname, "BeaconSlotP__syncPkt"))
  {
    *addr = (uintptr_t)&BeaconSlotP__syncPkt[__nesc_mote];
    *size = sizeof(BeaconSlotP__syncPkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "BeaconSlotP__syncPktLen"))
  {
    *addr = (uintptr_t)&BeaconSlotP__syncPktLen[__nesc_mote];
    *size = sizeof(BeaconSlotP__syncPktLen[__nesc_mote]);
    return 0;
  }

  /* Module AlarmMicro16P__2 */
  if (!strcmp(varname, "/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm"))
  {
    *addr = (uintptr_t)&/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm[__nesc_mote];
    *size = sizeof(/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero"))
  {
    *addr = (uintptr_t)&/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[__nesc_mote];
    *size = sizeof(/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt"))
  {
    *addr = (uintptr_t)&/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[__nesc_mote];
    *size = sizeof(/*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[__nesc_mote]);
    return 0;
  }

  /* Module TransformAlarmC__2 */
  if (!strcmp(varname, "/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0"))
  {
    *addr = (uintptr_t)&/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[__nesc_mote];
    *size = sizeof(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt"))
  {
    *addr = (uintptr_t)&/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[__nesc_mote];
    *size = sizeof(/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[__nesc_mote]);
    return 0;
  }

  /* Module CC2420ControlP */
  if (!strcmp(varname, "CC2420ControlP__channel"))
  {
    *addr = (uintptr_t)&CC2420ControlP__channel[__nesc_mote];
    *size = sizeof(CC2420ControlP__channel[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CC2420ControlP__autoAck"))
  {
    *addr = (uintptr_t)&CC2420ControlP__autoAck[__nesc_mote];
    *size = sizeof(CC2420ControlP__autoAck[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CC2420ControlP__hwAutoAck"))
  {
    *addr = (uintptr_t)&CC2420ControlP__hwAutoAck[__nesc_mote];
    *size = sizeof(CC2420ControlP__hwAutoAck[__nesc_mote]);
    return 0;
  }

  /* Module CpmModelC */
  if (!strcmp(varname, "CpmModelC__outgoing"))
  {
    *addr = (uintptr_t)&CpmModelC__outgoing[__nesc_mote];
    *size = sizeof(CpmModelC__outgoing[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC__requestAck"))
  {
    *addr = (uintptr_t)&CpmModelC__requestAck[__nesc_mote];
    *size = sizeof(CpmModelC__requestAck[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC__receiving"))
  {
    *addr = (uintptr_t)&CpmModelC__receiving[__nesc_mote];
    *size = sizeof(CpmModelC__receiving[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC__rssi"))
  {
    *addr = (uintptr_t)&CpmModelC__rssi[__nesc_mote];
    *size = sizeof(CpmModelC__rssi[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC__outstandingReceptionHead"))
  {
    *addr = (uintptr_t)&CpmModelC__outstandingReceptionHead[__nesc_mote];
    *size = sizeof(CpmModelC__outstandingReceptionHead[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC__clearThreshold"))
  {
    *addr = (uintptr_t)&CpmModelC__clearThreshold[__nesc_mote];
    *size = sizeof(CpmModelC__clearThreshold[__nesc_mote]);
    return 0;
  }

  /* Module TossimPacketModelC */
  if (!strcmp(varname, "TossimPacketModelC__initialized"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__initialized[__nesc_mote];
    *size = sizeof(TossimPacketModelC__initialized[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__running"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__running[__nesc_mote];
    *size = sizeof(TossimPacketModelC__running[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__backoffCount"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__backoffCount[__nesc_mote];
    *size = sizeof(TossimPacketModelC__backoffCount[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__neededFreeSamples"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__neededFreeSamples[__nesc_mote];
    *size = sizeof(TossimPacketModelC__neededFreeSamples[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__sending"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__sending[__nesc_mote];
    *size = sizeof(TossimPacketModelC__sending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__transmitting"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__transmitting[__nesc_mote];
    *size = sizeof(TossimPacketModelC__transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__sendingLength"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__sendingLength[__nesc_mote];
    *size = sizeof(TossimPacketModelC__sendingLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__destNode"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__destNode[__nesc_mote];
    *size = sizeof(TossimPacketModelC__destNode[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__sendEvent"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__sendEvent[__nesc_mote];
    *size = sizeof(TossimPacketModelC__sendEvent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__cca_enable_flag"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__cca_enable_flag[__nesc_mote];
    *size = sizeof(TossimPacketModelC__cca_enable_flag[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC__error"))
  {
    *addr = (uintptr_t)&TossimPacketModelC__error[__nesc_mote];
    *size = sizeof(TossimPacketModelC__error[__nesc_mote]);
    return 0;
  }

  /* Module TossimComPrintfP */

  /* Module SyncReceiveAdapterP */

  /* Module SyncSendAdapterP */

  /* Module TossimActiveMessageC */
  if (!strcmp(varname, "TossimActiveMessageC__buffer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC__buffer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC__buffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimActiveMessageC__bufferPointer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC__bufferPointer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC__bufferPointer[__nesc_mote]);
    return 0;
  }

  /* Module ActiveMessageAddressC */
  if (!strcmp(varname, "ActiveMessageAddressC__set"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC__set[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC__set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "ActiveMessageAddressC__addr"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC__addr[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC__addr[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP__0 */

  /* Module AMQueueImplP__0 */
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[__nesc_mote]);
    return 0;
  }

  /* Module AlarmMicro16P__3 */
  if (!strcmp(varname, "/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[__nesc_mote]);
    return 0;
  }

  /* Module TransformAlarmC__3 */

  /* Module SSTdmaSlotSenderP__0 */
  if (!strcmp(varname, "/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[__nesc_mote]);
    return 0;
  }

  /* Module AlarmMicro16P__4 */
  if (!strcmp(varname, "/*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero"))
  {
    *addr = (uintptr_t)&/*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[__nesc_mote];
    *size = sizeof(/*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[__nesc_mote]);
    return 0;
  }

  /* Module TransformAlarmC__4 */

  /* Module RandomMlcgC */
  if (!strcmp(varname, "RandomMlcgC__seed"))
  {
    *addr = (uintptr_t)&RandomMlcgC__seed[__nesc_mote];
    *size = sizeof(RandomMlcgC__seed[__nesc_mote]);
    return 0;
  }

  return -1;
}
/* Invoke static initialisers for mote '__nesc_mote' */

static void __nesc_nido_initialise(int __nesc_mote)
{
  /* Module TestNetworkC */
  memset((void *)&TestNetworkC__packet[__nesc_mote], 0, sizeof TestNetworkC__packet[__nesc_mote]);
  memset((void *)&TestNetworkC__rcm[__nesc_mote], 0, sizeof TestNetworkC__rcm[__nesc_mote]);
  memset((void *)&TestNetworkC__rcmr[__nesc_mote], 0, sizeof TestNetworkC__rcmr[__nesc_mote]);
  memset((void *)&TestNetworkC__msgamr[__nesc_mote], 0, sizeof TestNetworkC__msgamr[__nesc_mote]);
  memset((void *)&TestNetworkC__tnmsg_in_transit[__nesc_mote], 0, sizeof TestNetworkC__tnmsg_in_transit[__nesc_mote]);
  TestNetworkC__sendBusy[__nesc_mote] = FALSE;

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP__0 */

  /* Module HplAtm128GeneralIOPinP__1 */

  /* Module HplAtm128GeneralIOPinP__2 */

  /* Module HplAtm128GeneralIOPinP__3 */

  /* Module HplAtm128GeneralIOPinP__4 */

  /* Module HplAtm128GeneralIOPinP__5 */

  /* Module HplAtm128GeneralIOPinP__6 */

  /* Module HplAtm128GeneralIOPinP__7 */

  /* Module HplAtm128GeneralIOPinP__8 */

  /* Module HplAtm128GeneralIOPinP__9 */

  /* Module HplAtm128GeneralIOPinP__10 */

  /* Module HplAtm128GeneralIOPinP__11 */

  /* Module HplAtm128GeneralIOPinP__12 */

  /* Module HplAtm128GeneralIOPinP__13 */

  /* Module HplAtm128GeneralIOPinP__14 */

  /* Module HplAtm128GeneralIOPinP__15 */

  /* Module HplAtm128GeneralIOPinP__16 */

  /* Module HplAtm128GeneralIOPinP__17 */

  /* Module HplAtm128GeneralIOPinP__18 */

  /* Module HplAtm128GeneralIOPinP__19 */

  /* Module HplAtm128GeneralIOPinP__20 */

  /* Module HplAtm128GeneralIOPinP__21 */

  /* Module HplAtm128GeneralIOPinP__22 */

  /* Module HplAtm128GeneralIOPinP__23 */

  /* Module HplAtm128GeneralIOPinP__24 */

  /* Module HplAtm128GeneralIOPinP__25 */

  /* Module HplAtm128GeneralIOPinP__26 */

  /* Module HplAtm128GeneralIOPinP__27 */

  /* Module HplAtm128GeneralIOPinP__28 */

  /* Module HplAtm128GeneralIOPinP__29 */

  /* Module HplAtm128GeneralIOPinP__30 */

  /* Module HplAtm128GeneralIOPinP__31 */

  /* Module HplAtm128GeneralIOPinP__32 */

  /* Module HplAtm128GeneralIOPinP__33 */

  /* Module HplAtm128GeneralIOPinP__34 */

  /* Module HplAtm128GeneralIOPinP__35 */

  /* Module HplAtm128GeneralIOPinP__36 */

  /* Module HplAtm128GeneralIOPinP__37 */

  /* Module HplAtm128GeneralIOPinP__38 */

  /* Module HplAtm128GeneralIOPinP__39 */

  /* Module HplAtm128GeneralIOPinP__40 */

  /* Module HplAtm128GeneralIOPinP__41 */

  /* Module HplAtm128GeneralIOPinP__42 */

  /* Module HplAtm128GeneralIOPinP__43 */

  /* Module HplAtm128GeneralIOPinP__44 */

  /* Module HplAtm128GeneralIOPinP__45 */

  /* Module HplAtm128GeneralIOPinP__46 */

  /* Module HplAtm128GeneralIOPinP__47 */

  /* Module HplAtm128GeneralIOSlowPinP__0 */

  /* Module HplAtm128GeneralIOSlowPinP__1 */

  /* Module HplAtm128GeneralIOSlowPinP__2 */

  /* Module HplAtm128GeneralIOSlowPinP__3 */

  /* Module HplAtm128GeneralIOSlowPinP__4 */

  /* Module HplAtm128GeneralIOSlowPinP__5 */

  /* Module HplAtm128GeneralIOSlowPinP__6 */

  /* Module HplAtm128GeneralIOSlowPinP__7 */

  /* Module HplAtm128GeneralIOSlowPinP__8 */

  /* Module HplAtm128GeneralIOSlowPinP__9 */

  /* Module HplAtm128GeneralIOSlowPinP__10 */

  /* Module HplAtm128GeneralIOSlowPinP__11 */

  /* Module HplAtm128GeneralIOSlowPinP__12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  memset((void *)&SimSchedulerBasicP__m_head[__nesc_mote], 0, sizeof SimSchedulerBasicP__m_head[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP__m_tail[__nesc_mote], 0, sizeof SimSchedulerBasicP__m_tail[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP__m_next[__nesc_mote], 0, sizeof SimSchedulerBasicP__m_next[__nesc_mote]);
  SimSchedulerBasicP__sim_scheduler_event_pending[__nesc_mote] = FALSE;
  memset((void *)&SimSchedulerBasicP__sim_scheduler_event[__nesc_mote], 0, sizeof SimSchedulerBasicP__sim_scheduler_event[__nesc_mote]);

  /* Module SimMoteP */
  memset((void *)&SimMoteP__euid[__nesc_mote], 0, sizeof SimMoteP__euid[__nesc_mote]);
  memset((void *)&SimMoteP__startTime[__nesc_mote], 0, sizeof SimMoteP__startTime[__nesc_mote]);
  memset((void *)&SimMoteP__isOn[__nesc_mote], 0, sizeof SimMoteP__isOn[__nesc_mote]);
  memset((void *)&SimMoteP__bootEvent[__nesc_mote], 0, sizeof SimMoteP__bootEvent[__nesc_mote]);
  SimMoteP__radioChannel[__nesc_mote] = 26;
  memset((void *)&SimMoteP__tcp_msg[__nesc_mote], 0, sizeof SimMoteP__tcp_msg[__nesc_mote]);

  /* Module CC2420CsmaP */
  memset((void *)&CC2420CsmaP__buffer[__nesc_mote], 0, sizeof CC2420CsmaP__buffer[__nesc_mote]);

  /* Module AsyncReceiveAdapterP */
  memset((void *)&AsyncReceiveAdapterP__msg_[__nesc_mote], 0, sizeof AsyncReceiveAdapterP__msg_[__nesc_mote]);
  memset((void *)&AsyncReceiveAdapterP__payload_[__nesc_mote], 0, sizeof AsyncReceiveAdapterP__payload_[__nesc_mote]);
  memset((void *)&AsyncReceiveAdapterP__len_[__nesc_mote], 0, sizeof AsyncReceiveAdapterP__len_[__nesc_mote]);

  /* Module AsyncSendAdapterP */
  memset((void *)&AsyncSendAdapterP__msg_[__nesc_mote], 0, sizeof AsyncSendAdapterP__msg_[__nesc_mote]);
  memset((void *)&AsyncSendAdapterP__len_[__nesc_mote], 0, sizeof AsyncSendAdapterP__len_[__nesc_mote]);

  /* Module PureTDMASchedulerP */
  memset((void *)&PureTDMASchedulerP__m_entry[__nesc_mote], 0, sizeof PureTDMASchedulerP__m_entry[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__log_payload[__nesc_mote], 0, sizeof PureTDMASchedulerP__log_payload[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__rcmr[__nesc_mote], 0, sizeof PureTDMASchedulerP__rcmr[__nesc_mote]);
  PureTDMASchedulerP__isChild[__nesc_mote] = 0;
  PureTDMASchedulerP__isParent[__nesc_mote] = 0;
  PureTDMASchedulerP__isSibling[__nesc_mote] = 0;
  PureTDMASchedulerP__self_pos[__nesc_mote] = 0;
  PureTDMASchedulerP__receiving_num[__nesc_mote] = 0;
  PureTDMASchedulerP__totalChildren[__nesc_mote] = 0;
  PureTDMASchedulerP__totalParents[__nesc_mote] = 0;
  PureTDMASchedulerP__flag[__nesc_mote] = 0;
  PureTDMASchedulerP__MAXLEVELNODE[__nesc_mote] = 0;
  PureTDMASchedulerP__CURRNODES[__nesc_mote] = 0;
  memset((void *)&PureTDMASchedulerP__delay_fp[__nesc_mote], 0, sizeof PureTDMASchedulerP__delay_fp[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__topo_fp[__nesc_mote], 0, sizeof PureTDMASchedulerP__topo_fp[__nesc_mote]);
  memcpy((void *)&PureTDMASchedulerP__res_list[__nesc_mote], (void *)&(unsigned char [PureTDMASchedulerP__NUM_MEASUREMENTS]){ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, sizeof PureTDMASchedulerP__res_list[__nesc_mote]);
  memcpy((void *)&PureTDMASchedulerP__delay_list[__nesc_mote], (void *)&(unsigned char [PureTDMASchedulerP__NUM_MEASUREMENTS]){ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, sizeof PureTDMASchedulerP__delay_list[__nesc_mote]);
  PureTDMASchedulerP__send_counter[__nesc_mote] = 0;
  PureTDMASchedulerP__is_primary[__nesc_mote] = 0;
  PureTDMASchedulerP__rev_counter[__nesc_mote] = 0;
  memset((void *)&PureTDMASchedulerP__init[__nesc_mote], 0, sizeof PureTDMASchedulerP__init[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__slotSize[__nesc_mote], 0, sizeof PureTDMASchedulerP__slotSize[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__bi[__nesc_mote], 0, sizeof PureTDMASchedulerP__bi[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__sd[__nesc_mote], 0, sizeof PureTDMASchedulerP__sd[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__cap[__nesc_mote], 0, sizeof PureTDMASchedulerP__cap[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__coordinatorId[__nesc_mote], 0, sizeof PureTDMASchedulerP__coordinatorId[__nesc_mote]);
  PureTDMASchedulerP__i[__nesc_mote] = 0;
  PureTDMASchedulerP__j[__nesc_mote] = 0;
  PureTDMASchedulerP__k[__nesc_mote] = 0;
  memset((void *)&PureTDMASchedulerP__toSend[__nesc_mote], 0, sizeof PureTDMASchedulerP__toSend[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__toSendLen[__nesc_mote], 0, sizeof PureTDMASchedulerP__toSendLen[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__schedule_counter[__nesc_mote], 0, sizeof PureTDMASchedulerP__schedule_counter[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__up_schedule[__nesc_mote], 0, sizeof PureTDMASchedulerP__up_schedule[__nesc_mote]);
  PureTDMASchedulerP__avg_prob[__nesc_mote] = 0;
  memset((void *)&PureTDMASchedulerP__node_list[__nesc_mote], 0, sizeof PureTDMASchedulerP__node_list[__nesc_mote]);
  PureTDMASchedulerP__schedule_len[__nesc_mote] = 0;
  PureTDMASchedulerP__lp_intervals[__nesc_mote] = 0;
  PureTDMASchedulerP__superframe_length[__nesc_mote] = 55;
  memset((void *)&PureTDMASchedulerP__sync[__nesc_mote], 0, sizeof PureTDMASchedulerP__sync[__nesc_mote]);
  memset((void *)&PureTDMASchedulerP__requestStop[__nesc_mote], 0, sizeof PureTDMASchedulerP__requestStop[__nesc_mote]);

  /* Module LedsP */

  /* Module GenericSlotSenderP__0 */
  memset((void *)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[__nesc_mote], 0, sizeof /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSend[__nesc_mote]);
  memset((void *)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[__nesc_mote], 0, sizeof /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__toSendLen[__nesc_mote]);
  memset((void *)&/*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[__nesc_mote], 0, sizeof /*TDMASlotSenderC.TDMASlotSender.GenericSlotSenderP*/GenericSlotSenderP__0__state[__nesc_mote]);

  /* Module AlarmMicro16P__0 */
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__alarm[__nesc_mote] = 0;
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__zero[__nesc_mote] = 0;
  /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__0__evt[__nesc_mote] = (void *)0;

  /* Module CounterMicro16P */
  memset((void *)&CounterMicro16P__t0[__nesc_mote], 0, sizeof CounterMicro16P__t0[__nesc_mote]);

  /* Module TransformAlarmC__0 */
  memset((void *)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[__nesc_mote], 0, sizeof /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_t0[__nesc_mote]);
  memset((void *)&/*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[__nesc_mote], 0, sizeof /*TDMASlotSenderC.TDMASlotSender.Alarm32khz16C.TransformAlarmC*/TransformAlarmC__0__m_dt[__nesc_mote]);

  /* Module TransformCounterC__0 */
  memset((void *)&/*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[__nesc_mote], 0, sizeof /*Counter32khz16C.TransformCounterC*/TransformCounterC__0__m_upper[__nesc_mote]);

  /* Module GenericSlotterP */
  memset((void *)&GenericSlotterP__slot[__nesc_mote], 0, sizeof GenericSlotterP__slot[__nesc_mote]);
  memset((void *)&GenericSlotterP__slotLength[__nesc_mote], 0, sizeof GenericSlotterP__slotLength[__nesc_mote]);
  memset((void *)&GenericSlotterP__frameLength[__nesc_mote], 0, sizeof GenericSlotterP__frameLength[__nesc_mote]);
  memset((void *)&GenericSlotterP__sync[__nesc_mote], 0, sizeof GenericSlotterP__sync[__nesc_mote]);
  memset((void *)&GenericSlotterP__nextFire[__nesc_mote], 0, sizeof GenericSlotterP__nextFire[__nesc_mote]);

  /* Module AlarmMicro16P__1 */
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__alarm[__nesc_mote] = 0;
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__zero[__nesc_mote] = 0;
  /*GenericSlotterC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__1__evt[__nesc_mote] = (void *)0;

  /* Module TransformAlarmC__1 */
  memset((void *)&/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[__nesc_mote], 0, sizeof /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_t0[__nesc_mote]);
  memset((void *)&/*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[__nesc_mote], 0, sizeof /*GenericSlotterC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__1__m_dt[__nesc_mote]);

  /* Module TransformCounterC__1 */
  memset((void *)&/*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[__nesc_mote], 0, sizeof /*Counter32khz32C.TransformCounterC*/TransformCounterC__1__m_upper[__nesc_mote]);

  /* Module SenderDispatcherP */
  memset((void *)&SenderDispatcherP__toSend[__nesc_mote], 0, sizeof SenderDispatcherP__toSend[__nesc_mote]);
  memset((void *)&SenderDispatcherP__toSendLen[__nesc_mote], 0, sizeof SenderDispatcherP__toSendLen[__nesc_mote]);
  memset((void *)&SenderDispatcherP__last_id[__nesc_mote], 0, sizeof SenderDispatcherP__last_id[__nesc_mote]);

  /* Module DummyChannelMonitorC */

  /* Module BeaconSlotP */
  memset((void *)&BeaconSlotP__syncPkt[__nesc_mote], 0, sizeof BeaconSlotP__syncPkt[__nesc_mote]);
  memset((void *)&BeaconSlotP__syncPktLen[__nesc_mote], 0, sizeof BeaconSlotP__syncPktLen[__nesc_mote]);

  /* Module AlarmMicro16P__2 */
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__alarm[__nesc_mote] = 0;
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__zero[__nesc_mote] = 0;
  /*PureTDMASchedulerC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__2__evt[__nesc_mote] = (void *)0;

  /* Module TransformAlarmC__2 */
  memset((void *)&/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[__nesc_mote], 0, sizeof /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_t0[__nesc_mote]);
  memset((void *)&/*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[__nesc_mote], 0, sizeof /*PureTDMASchedulerC.Alarm32khz32C.TransformAlarmC*/TransformAlarmC__2__m_dt[__nesc_mote]);

  /* Module CC2420ControlP */
  memset((void *)&CC2420ControlP__channel[__nesc_mote], 0, sizeof CC2420ControlP__channel[__nesc_mote]);
  memset((void *)&CC2420ControlP__autoAck[__nesc_mote], 0, sizeof CC2420ControlP__autoAck[__nesc_mote]);
  memset((void *)&CC2420ControlP__hwAutoAck[__nesc_mote], 0, sizeof CC2420ControlP__hwAutoAck[__nesc_mote]);

  /* Module CpmModelC */
  memset((void *)&CpmModelC__outgoing[__nesc_mote], 0, sizeof CpmModelC__outgoing[__nesc_mote]);
  memset((void *)&CpmModelC__requestAck[__nesc_mote], 0, sizeof CpmModelC__requestAck[__nesc_mote]);
  CpmModelC__receiving[__nesc_mote] = 0;
  CpmModelC__rssi[__nesc_mote] = FALSE;
  CpmModelC__outstandingReceptionHead[__nesc_mote] = (void *)0;
  CpmModelC__clearThreshold[__nesc_mote] = -72.0;

  /* Module TossimPacketModelC */
  TossimPacketModelC__initialized[__nesc_mote] = FALSE;
  TossimPacketModelC__running[__nesc_mote] = FALSE;
  memset((void *)&TossimPacketModelC__backoffCount[__nesc_mote], 0, sizeof TossimPacketModelC__backoffCount[__nesc_mote]);
  memset((void *)&TossimPacketModelC__neededFreeSamples[__nesc_mote], 0, sizeof TossimPacketModelC__neededFreeSamples[__nesc_mote]);
  TossimPacketModelC__sending[__nesc_mote] = (void *)0;
  TossimPacketModelC__transmitting[__nesc_mote] = FALSE;
  TossimPacketModelC__sendingLength[__nesc_mote] = 0;
  memset((void *)&TossimPacketModelC__destNode[__nesc_mote], 0, sizeof TossimPacketModelC__destNode[__nesc_mote]);
  memset((void *)&TossimPacketModelC__sendEvent[__nesc_mote], 0, sizeof TossimPacketModelC__sendEvent[__nesc_mote]);
  memset((void *)&TossimPacketModelC__cca_enable_flag[__nesc_mote], 0, sizeof TossimPacketModelC__cca_enable_flag[__nesc_mote]);
  TossimPacketModelC__error[__nesc_mote] = 0;

  /* Module TossimComPrintfP */

  /* Module SyncReceiveAdapterP */

  /* Module SyncSendAdapterP */

  /* Module TossimActiveMessageC */
  memset((void *)&TossimActiveMessageC__buffer[__nesc_mote], 0, sizeof TossimActiveMessageC__buffer[__nesc_mote]);
  TossimActiveMessageC__bufferPointer[__nesc_mote] = &TossimActiveMessageC__buffer[__nesc_mote];

  /* Module ActiveMessageAddressC */
  ActiveMessageAddressC__set[__nesc_mote] = FALSE;
  memset((void *)&ActiveMessageAddressC__addr[__nesc_mote], 0, sizeof ActiveMessageAddressC__addr[__nesc_mote]);

  /* Module AMQueueEntryP__0 */

  /* Module AMQueueImplP__0 */
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current[__nesc_mote] = 1;
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[__nesc_mote]);
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[__nesc_mote]);

  /* Module AlarmMicro16P__3 */
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__zero[__nesc_mote] = 0;
  /*TestNetworkAppC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__3__evt[__nesc_mote] = (void *)0;

  /* Module TransformAlarmC__3 */

  /* Module SSTdmaSlotSenderP__0 */
  memset((void *)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[__nesc_mote], 0, sizeof /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSend[__nesc_mote]);
  memset((void *)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[__nesc_mote], 0, sizeof /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__toSendLen[__nesc_mote]);
  memset((void *)&/*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[__nesc_mote], 0, sizeof /*TestNetworkAppC.SSTdmaSlotSenderC.SSTdmaSlotSenderP*/SSTdmaSlotSenderP__0__state[__nesc_mote]);

  /* Module AlarmMicro16P__4 */
  /*TestNetworkAppC.SSTdmaSlotSenderC.Alarm32khz32C.AlarmMicro16C.AlarmMicro16P*/AlarmMicro16P__4__zero[__nesc_mote] = 0;

  /* Module TransformAlarmC__4 */

  /* Module RandomMlcgC */
  memset((void *)&RandomMlcgC__seed[__nesc_mote], 0, sizeof RandomMlcgC__seed[__nesc_mote]);

}
