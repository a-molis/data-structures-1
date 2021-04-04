#if 0
    source "${TEST_DIR}/lib/crunner" -lds -D_GNU_SOURCE -ldl
#endif

#include <libgen.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//#include "clist.h"

test_start("Basic test");

subtest("test clist",
{
    test_assert(9 == 9);
});

test_end
