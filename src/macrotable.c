#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <macrotable.h>

#define MTSIZE 101 

struct mtable {
    mnode_t *nodes[MTSIZE];
};


/**
 * The C Programming Language
 */
static size_t hash(char* s)
{ 
    size_t hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval;
}

mtable_t *mtnew(void)
{
    mtable_t* mt = malloc(sizeof(mtable_t));
    for (size_t i = 0; i < MTSIZE; i++) mt->nodes[i] = NULL;

    return mt;
}

mnode_t *mnnew(char* s, token_t** ts, size_t l)
{
    mnode_t *n = malloc(sizeof(mnode_t));
    n->macro = strdup(s);
    n->length = l;
    n->ts = ts;

    return n;
}


mnode_t* mtset(mtable_t *mt, char *macro, token_t** ts, size_t l)
{
    size_t index = hash(macro);
    mnode_t *first = mt->nodes[index];
    mt->nodes[index] = mnnew(macro, ts, l);
    mt->nodes[index]->next = first;

    return mt->nodes[index];
} 

mnode_t* mtget(mtable_t *mt, char* macro)
{
    size_t index = hash(macro);

    for (mnode_t *n = mt->nodes[index]; n != NULL; n = n->next) if (strcmp(n->macro, macro) == 0) return n;

    return NULL;
} 

