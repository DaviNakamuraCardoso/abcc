#include <stdio.h>
#include <stdlib.h>
#include <ast.h>
#include <tokens.h>


struct anode{
    size_t start, end;
    statement_e type;
    token_t* t;
};

struct ast { 
    anode_t **nodes;
    size_t sp;
}; 

ast_t *create_ast(size_t size) {
    ast_t *ast = malloc(sizeof(ast_t));

    ast->nodes = calloc(sizeof(anode_t*), size);
    ast->sp = 0;

    return ast;
}

statement_e get_identifier_st(token_t **tks) {
    (void*) tks;
    return __ST_UNIDENTIFIED;
}

statement_e get_keyword_st(token_t **tks) {
    (void*) tks;
    return __ST_UNIDENTIFIED;

}

statement_e (*st_parsers[])(token_t**) = {
    [IDENTIFIER] = get_identifier_st,
    [KEYWORD] = get_keyword_st,
};

statement_e get_statement(token_t** tks) {
    (void*) tks;
    return __ST_UNIDENTIFIED;
}

size_t parse_expression(token_t** tks, ast_t* ast) {
    size_t skip = 0;


    return ++skip;
}

ast_t *get_ast(token_t** tokens) {

    // TODO: get actual length of tokens
    ast_t *ast = create_ast(100);
    token_t **tpointer = tokens;

    for (
        size_t i = 0; 
        tokens[i] != NULL; 
        i += parse_expression(tokens+(sizeof(token_t*)*i), ast)
    );

	return NULL;
}

anode_t *get_node(size_t start, token_t* t, statement_e type) {
    anode_t* node = malloc(sizeof(anode_t));
    node->start = start;
    node->t = t;
    node->type = type;
    return node;
}




