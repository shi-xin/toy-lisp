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

#include <editline/readline.h>

int main(int argc, char** argv) {
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
        printf(": %s\n", input);

        /* free retrieved input */
        free(input);
    }

    return 0;
}



