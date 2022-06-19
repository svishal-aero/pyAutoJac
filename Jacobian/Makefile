SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

CFLAGS :=

LDFLAGS := \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/DepVarList/DepVar -L/home/svishal/Git/pyJacADF/DepVarList/DepVar -lDepVar \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/DepVarList -L/home/svishal/Git/pyJacADF/DepVarList -lDepVarList \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/Variable -L/home/svishal/Git/pyJacADF/Variable -lVariable

all: libJacobian.so

libJacobian.so: $(OBJ)
	gcc $(CFLAGS) -O3 -shared -fPIC -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.c Jacobian.h
	gcc $(CFLAGS) -c -O3 -fPIC -o $@ $<