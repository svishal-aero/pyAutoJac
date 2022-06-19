LDFLAGS := \
	-Wl,-rpath=/home/svishal/Git/pyAutoJac/DepVarList/DepVar -L/home/svishal/Git/pyAutoJac/DepVarList/DepVar -lDepVar \
	-Wl,-rpath=/home/svishal/Git/pyAutoJac/DepVarList -L/home/svishal/Git/pyAutoJac/DepVarList -lDepVarList \
	-Wl,-rpath=/home/svishal/Git/pyAutoJac/Variable -L/home/svishal/Git/pyAutoJac/Variable -lVariable \
	-Wl,-rpath=/home/svishal/Git/pyAutoJac/Jacobian -L/home/svishal/Git/pyAutoJac/Jacobian -lJacobian -lm

all: test.c
	gcc $(CFLAGS) -O3 -fPIC $^ $(LDFLAGS)
