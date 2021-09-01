objects := $(patsubst %.c,%.o,$(wildcard src/*.c))

foo : $(objects)
		gcc -o foo $(objects) -I. 