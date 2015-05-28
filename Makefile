CFLAGS   += -g

# Automatically sort out header dependencies
CPPFLAGS += -MD -MF $(patsubst %.o,.%.mk,$@) -MP
-include $(patsubst %.o,.%.mk,$(obj))

objs = \
	disk_utility.o \
	input.o \
	link_utility.o \
	main_utility.o \
	node_math.o \
	node_utility.o \
	reply.o \
	tree_utility.o

all: reply

reply: $(objs)

clean:
	rm -f -- .*.mk *.o reply

.PHONY: all clean
.DELETE_ON_ERROR:
