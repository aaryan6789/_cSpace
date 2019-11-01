/* main.c  * Created on: Jun 24, 2018 * Author: Harsh */

#include "helper.h"

static int y = 10;
void foo()
{
    static int x = 5;		// Local Static Variable
    printf("%d ", y);
    x++;
    printf("%d ", x);
}

int main(){
    foo();
    printf("%d ", y++);
    foo();
    //printf("%d ", x);		// <-- error: 'x' undeclared (first use in this function)


    // Stack Direction
    int main_local_var;
    func(&main_local_var);


    return 0;
}

/* There are two issues here, lifetime and scope.
 * The scope of variable is where the variable name can be seen.
 * Here, x is visible only inside function foo().
 *
 * The lifetime of a variable is the period over which it exists.
 * If x were defined without the keyword static,
 * the lifetime would be from the entry into foo() to the return from foo();
 * so it would be re-initialized to 5 on every call.
 *
 * The keyword static acts to extend the lifetime of a variable to
 * the lifetime of the program ;
 * e.g. initialization occurs once and once only and then the variable retains
 * its value - whatever it has come to be - over all future calls to foo().
 *
 * Output: 6 7
 *
 * Reason: static variable is initialized only once (unlike auto variable) and
 *  further definition of static variable would be bypassed during runtime.
 *
 *  And if it is not initialized manually, it is initialised by value 0
 *  automatically.
 *
 *
 * Local Static VS Global Static
 * Local static:
 * 1. Default value is zero.
 * 2. Stored in data section(bss or initialized) of memory.
 * 3. Scope or visibility is within the block or a function
 * 4. Life of local static variable starts and only ends with the program.
 *
 * Global static:
 * 1. If a global variable is static,
 * the scope or visibility is within that file only,
 * even using extern in another file won’t work. It gives linkage error.
 * 2. Global static variable is a variable defined outside of any blocks and
 *  is accessible in all blocks in the same file where it is defined & is persistent.
 *
 */
