# include <stdio.h>

int main(int argc, char** argv) {
    puts("hello, world!");
    int added = add_this_two(10, 12);
    return 0;
}


/* this is a comment */

/* function: addition */
int add_this_two(int x, int y) {
    int z = x + y;
    return z
}


/* Structure Declarations
this is used to declare new types.
structures are several variables bundled together into a single package.
We can use structure to represent more complex data types.

structure has to be declared prior to be used.

NOTE: how complex can this be?
*/

typedef struct {
    /* represent a point in 2D space */
    float x;
    float y;
} point;


point p;
p.x = 0.1;
p.y = 0.5;

float length = sqrt(p.x * p.x + p.y * p.y);




/* Conditionals 

NOTE: This looks like R. I'm OK with it.
why is there no semicolon in the end of the conditional block?
*/
if (x > 1 && x < 2) {
    puts("this is fun, what is the alternative?");
} else {
    puts("apparently the alternative is not that different");
}



/* Loops
for and while loops
while loop is straight forward.
for loop requires three expressions separated by semicolons. And they are
an initialiser, a condition, and an incrementer. The initializer is performed
before the loop starts. The condition is checked before each iteration of the
loop. If it is false, the loop is exited. The incrementer is performed at the
end of each iteration of the loop. These loops are often used for counting
as they are more compact than the while loop.

NOTE: different to those loops in R.
*/
int i = 10;
while (i > 0) {
    puts("this is loopy, my friend.");
    i = i - 1;
}


for (int i = 0; i < 10; i++) {
    puts("this is also quite loopy.");
}
/* 
right after i++, shouldn't there be a semicolon? i++;
*/



















