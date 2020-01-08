/* 
Interactive Prompt 

REPL
read-evaluate-print loop

A way is needed to interact with this toy lisp.
C uses a compiler, where you can change the program, recompile and run it.
It would be good if we could do something better, and interact with the
language dynamically. Then we test its behaviour under a number of conditions
very quickly.

This is a program that prompts the user for some input, and when supplied with
it, replies back with some message. This system is called a REPL.


*/






/* basic setup - a loop */

#include <stdio.h>
#include <stdlib.h>

#include "mpc.h"  /* file is local, use "" */

#include <editline/readline.h>


/* use operator string to decide which operation to perform */
long eval_op(long x, char* op, long y) {
    if (strcmp(op, "+") == 0) { return x + y; }
    if (strcmp(op, "-") == 0) { return x - y; }
    if (strcmp(op, "*") == 0) { return x * y; }
    if (strcmp(op, "/") == 0) { return x / y; }
    return 0;
}


/* evaluation function */
/* ok, now this is recursion, and it is unlike the way the author had described
it */
long eval(mpc_ast_t* t) {
    /* if tagged as number return it directly */
    if (strstr(t->tag, "number")) {
        return atoi(t->contents);
    }

    /* the operator is always second child */
    char* op = t->children[1]->contents;

    /* we store the third child in 'x' */
    long x = eval(t->children[2]);

    /* iterate the remaining children and combining. */
    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}












int main(int argc, char** argv) {

    /* create some parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Lispy = mpc_new("lispy");

    /* define them with the following language */
    mpca_lang(MPCA_LANG_DEFAULT,
        "                                                        \
            number    : /-?[0-9]+/ ;                             \
            operator  : '+' | '-' | '*' | '/' ;                  \
            expr      : <number> | '(' <operator> <expr>+ ')' ;  \
            lispy     : /^/ <operator> <expr>+ /$/ ;             \
        ",
        Number, Operator, Expr, Lispy);
    /* print version and exit information */
    puts("Toy Lisp v0.1");
    puts("Press control+c to Exit\n");

    /* a never ending loop */
    while (1) {

        /* output prompt and get input */
        char* input = readline("toy-lisp>>> ");
        /* add input to history */
        add_history(input);


        /* echo input back to user */
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            
            long result = eval(r.output);
            printf("%li\n", result);
            mpc_ast_delete(r.output);
        } else {
            /* otherwise print the error */
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        /* free retrieved input */
        free(input);
    }
    /* undefine and delete our parsers */
    mpc_cleanup(4, Number, Operator, Expr, Lispy);

    return 0;
}



