#ifndef DEFINE_H
#define DEFINE_H

// unsigned ints
typedef unsigned char u8; //=========> %c
typedef unsigned short u16; //=======> %hu
typedef unsigned int u32; //=========> %u  
typedef unsigned long long u64; //===> %llu 

// signed ints
typedef signed char s8; //===========> %c
typedef signed short s16; //=========> %hi,  %hd
typedef signed int s32; //===========> %i,   %d
typedef signed long long s64; //=====> %lli, %lld

// regular ints
typedef char i8; //==================> %c
typedef short i16; //================> %hi,  %hd
typedef int i32; //==================> %i,   %d
typedef long long i64; //============> %lli, %lld

// floats
typedef float f32; //================> %f,  %g,  %e,  %a
typedef double f64; //===============> %lf, %lg, %le, %la

// bool
typedef u8 b8;
typedef u32 b32;

#define true 1
#define false 0

//~ Assist

#define Gigabytes(count) (u64) (count * 1024 * 1024 * 1024)
#define Megabytes(count) (u64) (count * 1024 * 1024)
#define Kilobytes(count) (u64) (count * 1024)

#define Min(a, b) (((a)<(b))?(a):(b))
#define Max(a, b) (((a)>(b))?(a):(b))

#define MemoryCopy(d, s, z) memmove((d), (s), (z))
#define MemoryCopyStruct(d, s) MemoryCopy((d), (s), Min(sizeof(*(d)), sizeof(*(s))))
#define MemoryZero(d, z) memset((d), 0, (z))
#define MemoryZeroStruct(d, s) MemoryZero((d), sizeof(s))
#define ArraySize(a) (sizeof(a) / sizeof(a[0]))

//~ String















#endif // DEFINE_H
