#include "AST_proc.h"
#include "graphviz_funcs.h"
#include "string_funcs.h"
#include "AST_io.h"
#include "general.h"

#include <cstdio>

const char LOG_FILE_PATH[] = "./logs/log.html";
const char DOT_DIR_PATH[] = "./logs";
const char DOT_FILE_NAME[] = "graph.dot";
const char DOT_IMG_NAME[] = "gr_img.png";
// const char LOG_FILE_PATH[] = "./logs/log.html";


// const char EXPRESSION_FILE_PATH[] = "./expression.txt";
const size_t CHUNK_SIZE = 1024;

int main(const int argc, const char *argv[]) {
    char bufer[BUFSIZ] = {};
    dot_code_t dot_code = {}; dot_code_t_ctor(&dot_code, LIST_DOT_CODE_PARS);
    ast_tree_t tree = {}; ast_tree_ctor(&tree, LOG_FILE_PATH);
    dot_dir_t dot_dir = {}; dot_dir_ctor(&dot_dir, DOT_DIR_PATH, DOT_FILE_NAME, DOT_IMG_NAME);

    str_storage_t *storage = str_storage_t_ctor(CHUNK_SIZE);
    str_t text = read_text_from_file("./input.txt");


    tree.root = load_ast_tree(text.str_ptr, &storage, bufer);

    ast_tree_file_dump("./output.txt", &tree, 4);
    convert_subtree_to_dot(tree.root, &dot_code, &storage);

    dot_code_render(&dot_dir, &dot_code);

    sub_tree_dtor(tree.root);
    str_storage_t_dtor(storage);
    FREE(text.str_ptr);
}
