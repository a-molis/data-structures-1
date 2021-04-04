# output binary name
bin=ds

# Compiler/linker flags
CDFLAGS += -g -Wall -fPIC -DLOGGER=$(LOGGER)
LDLIBS +=
LDFLAGS +=

src=linked_list.c clist.c ds.c
obj=$(src:.c=.o)

all: $(bin) libds.so

$(bin): $(obj)
	$(CC) $(CDFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -o $@

libds.so: $(obj)
	$(CC) $(CDFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -shared -o $@

clist.o: clist.c clist.h
linked_list.o: linked_list.c linked_list.h
ds.o: ds.c clist.h linked_list.h

clean:
	rm -f $(bin) $(obj) libds.o vgcore.*
