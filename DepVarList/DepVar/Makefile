SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

CFLAGS :=

LDFLAGS :=

all: libDepVar.so

libDepVar.so: $(OBJ)
	gcc $(CFLAGS) -O3 -shared -fPIC -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.c DepVar.h
	gcc $(CFLAGS) -c -O3 -fPIC -o $@ $<