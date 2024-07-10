#ifndef HASH_H
#define HASH_H

#include "palavra.h"

#define NTAB 127

typedef tPalavra* Hash[NTAB];

static void inicializa (Hash tab);

static int hash (char* s);



#endif