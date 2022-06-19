SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

CFLAGS :=

LDFLAGS := \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/DepVarList/DepVar -L/home/svishal/Git/pyJacADF/DepVarList/DepVar -lDepVar

all: libDepVarList.so

libDepVarList.so: $(OBJ)
	gcc $(CFLAGS) -O3 -shared -fPIC -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.c DepVarList.h
	gcc $(CFLAGS) -c -O3 -fPIC -o $@ $<