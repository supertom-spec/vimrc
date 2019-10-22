#ifndef _DEBUG_H_
#define _DEBUG_H_

typedef unsigned char BYTE;

int debug_flag = 1;

void debug_msg(const char *msg) {
    if ( !debug_flag ) {
        return;
    }
    printf("[+] %s\n", msg);
}

void debug_hex(const char *msg, BYTE* addr, int n) {
    if ( !debug_flag ) {
        return;
    }
    printf("[+] Memory of 0x%X (%s): \n", addr, msg);
    printf("0000:  ");
    for (int i = 0; i < n; i++) {
        printf("%02x", *(addr+i));
        if ( (i+1) % 2 == 0 ) {
            printf(" ");
        }
        if ( (i+1) % 8 == 0 ) {
            printf("  ");
        }
        if ( (i+1) % 16 == 0 ) {
            printf("\n%04X:  ", i+1);
        }
    }
    printf("\n");
}
/*
typedef struct debug {
    int flag;
    void (*msg)(const char *msg);
    void (*hex)(const char *msg, BYTE* addr, int n);
} debug;
*/
//debug d = { 1, msg:debug_msg, hex:debug_hex };

#endif /* _DEBUG_H_ */
