#ifndef ATOM_INCLUDE
#define ATOM_INCLUDE

extern         int Atom_length(const char * str);
extern const char *Atom_new   (const char * str, int len);
extern const char *Atom_string(const char * str);
extern const char *Atom_int   (long n);

#endif
