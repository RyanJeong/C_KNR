#ifndef ___KEY_H___
#define ___KEY_H___

struct key {
    char *word;
    int  count;
};

extern const int        NKEYS;
extern       struct key keytab[];

#endif