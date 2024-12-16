#ifndef AST_IO_H
#define AST_IO_H

#include "AST_proc.h"
#include "string_funcs.h"
#include "graphviz_funcs.h"

const dot_node_pars_t DEFAULT_NODE_PARS = {"Mrecord", "black", "#FFEEEE", "filled"};
const dot_edge_pars_t DEFAULT_EDGE_PARS = {NULL, NULL, "#00FF00", 2};
const dot_code_pars_t LIST_DOT_CODE_PARS = {"TB"};

enum opers {
    OP_ADD = 0,
    OP_DIV = 1,
    OP_MUL = 2,
    OP_SUB = 3,
    OP_DIVIDER = 4,
    OP_IF = 5,
};

enum node_types {
    NODE_EMPTY = 0,
    NODE_VAR = 1,
    NODE_NUM = 2,
    NODE_OP = 3,
    NODE_FUNC = 4,
};

ast_tree_elem_t *load_ast_tree(char *text, str_storage_t **storage, char *bufer);
void ast_tree_file_dump_rec(FILE* stream, ast_tree_elem_t *node, size_t indent);
void ast_tree_file_dump(const char path[], ast_tree_t *tree, size_t indent);

void get_node_type(enum node_types *type, long double *value, char *name);
void get_node_string(char *bufer, ast_tree_elem_t *node);
size_t seg_char_cnt(char *left, char *right, char c);
void fprintf_seg(FILE *stream, char *left, char *right);
int put_node_in_dotcode(ast_tree_elem_t *node, dot_code_t *dot_code, str_storage_t **storage);
int convert_subtree_to_dot(ast_tree_elem_t *node, dot_code_t *dot_code, str_storage_t **storage);
void node_dump(FILE *log_file, ast_tree_elem_t *node);

#endif // AST_IO_H