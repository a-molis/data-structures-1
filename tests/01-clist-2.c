#if 0
    source "${TEST_DIR}/lib/crunner" -lds -D_GNU_SOURCE -ldl
#endif

#include <libgen.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "clist.h"

test_start("Basic test");

subtest("Simple test clist_add and clist_get",
{
    struct clist *test_list = clist_create(5, sizeof(int));
    for(int i=0; i<4; i++) {
        clist_add(test_list, &i);
    }  
    
    int *output= clist_get(test_list, 2);
    test_assert(*output == 2);
    clist_destroy(test_list);
});



test_end
