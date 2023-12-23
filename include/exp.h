
typedef enum {
    OP_IF,
    OP_ELSE,
    OP_WHILE,
    OP_FOR,
    OP_AA,
    OP_CALL,
    OP_DOT,
    OP_ARROW,
    OP_FUNCTION,
    OP_VARDEC,
    OP_ASSIGNMENT,
} operations_e;

int pushop(ast_t*, tokens_t**);


