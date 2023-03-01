#ifndef __ABR_H_
#define __ABR_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct noeud{
    char * mot;
    struct noeud *fg, *fd;
} Noeud, *Arbre;

#endif