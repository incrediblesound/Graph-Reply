CFLAGS   += -g

# Be super strict about everything
CFLAGS   += -std=c99 -Werror -Wall -Wextra -pedantic -O2
CPPFLAGS += -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2

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
