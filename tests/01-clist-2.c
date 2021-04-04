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

subtest("Simple test for clist_iterate and clist_iterate_rev",
{
    int capacity = 5;;
    struct clist *test_list = clist_create(capacity, sizeof(int));
    for(int i=0; i<15; i++) {
        clist_add(test_list, &i);
    }

    struct clist_iterator iter = clist_create_iter();
    void *elem;
    for (int i=14; i>=10; i--) {
        printf("%d\n", i);
        elem = clist_iterate(test_list, &iter);
        int iterate_output = *((int *) elem);
        test_assert(iterate_output == i);
    }
});


test_end
