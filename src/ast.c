#include <stdio.h>
#include <stdlib.h>
#include <ast.h>
#include <tokens.h>


struct anode {
    size_t start, end;
    token_t* t;
};

struct ast { 
    anode_t **nodes;
    size_t sp;
}; 

ast_t *get_ast(token_t** tokens) {
	(void)tokens;
	return NULL;
}


