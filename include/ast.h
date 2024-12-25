#ifndef __AST_H
#define __AST_H

#include "tokens.h"

typedef struct ast ast_t;
typedef struct anode anode_t;

anode_t *startnode(ast_t*);
anode_t *endnode(ast_t*, anode_t*);
ast_t* get_ast(token_t**);

typedef enum {
    __ST_UNIDENTIFIED,
    ST_IF,
    ST_ELSE,
    ST_FOR,
    ST_WHILE,
    ST_ADD,
    ST_SUB,
    ST_MUL,
    ST_DIV,
    ST_CALL,
    ST_FUN,
    ST_VAR,
    ST_ASG, 
    ST_COUNT
    
} statement_e;



#endif


