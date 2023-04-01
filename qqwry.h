#ifndef QQWRY_H_
#define QQWRY_H_

#include <stdio.h>

/* exports: gkb_to_utf8, utf8_to_gbk */
typedef unsigned char            u8;
typedef unsigned short           u16;
typedef unsigned int             u32;
typedef unsigned long long int   u64;
typedef char                     s8;
typedef short                    s16;
typedef int                      s32;
typedef long long int            s64;
typedef unsigned char BOOL8;
typedef unsigned int BOOL;

#define INLINE__ inline
#undef  ARRAY_SIZE
#define ARRAY_SIZE(a) ((sizeof(a))/(sizeof((a)[0])))
static INLINE__ void* xmalloc(u32 size);
INLINE__ static u16 gbk_to_uni(u8 ch, u8 cl);
INLINE__ static u16 uni_to_gbk(u16 uni);
int gbk_to_utf8(unsigned char **ptr, void *pin_buf, s32 in_len);
int utf8_to_gbk(unsigned char **ptr, void *pin_buf, s32 in_len);


/* qqwry */
#define IPDPFILE "cstrike/addons/amxmodx/data/qqwry.dat"
#define DATAMODE_1 0x01
#define DATAMODE_2 0x02

typedef struct TYPEIPINFO {
	unsigned int ipstart;
	unsigned int ipend;
	unsigned char adata[256];
	unsigned char adata_utf8[256];
	unsigned char bdata[256];
	unsigned char bdata_utf8[256];
} IPINFO;

void uint2ip(unsigned char *ip, unsigned int ipno);
void ip2uint(unsigned int *ipno, unsigned char *ip);
void readstr(unsigned char *buf, unsigned int size, unsigned int offset, FILE *fp);
void readstr_utf8(unsigned char *buf, unsigned char *buf_utf8, unsigned int size, unsigned int offset, FILE *fp);
unsigned int bytes2uint(unsigned char *buf, int len);
void readfromfile(unsigned char *buf, unsigned int len, unsigned int offset, FILE *fp);

void readheader(unsigned int *first, unsigned int *last, FILE *fp);
unsigned int readip(unsigned int offset, FILE *fp);
unsigned int readoffset(unsigned int offset, FILE *fp);

unsigned int search(unsigned int firstindex, unsigned int indexcount, unsigned int ip, FILE *fp);
unsigned int fixboffset(unsigned int boffset, FILE *fp);
void getdata(IPINFO *info, unsigned int endindex, FILE *fp);

void getipinfo_uint(IPINFO *info, unsigned int ip);
void getipinfo(IPINFO *info, unsigned char *ip);

#endif