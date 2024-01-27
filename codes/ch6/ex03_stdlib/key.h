#ifndef ___KEYWORD_KEY_H___
#define ___KEYWORD_KEY_H___

struct key {
  char *word;
  int count;
};

extern const int NKEYS;
extern struct key keytab[];

#endif /* __KEYWORD_KEY_H__ */
