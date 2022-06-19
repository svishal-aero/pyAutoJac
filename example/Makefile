LDFLAGS := \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/DepVarList/DepVar -L/home/svishal/Git/pyJacADF/DepVarList/DepVar -lDepVar \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/DepVarList -L/home/svishal/Git/pyJacADF/DepVarList -lDepVarList \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/Variable -L/home/svishal/Git/pyJacADF/Variable -lVariable \
	-Wl,-rpath=/home/svishal/Git/pyJacADF/Jacobian -L/home/svishal/Git/pyJacADF/Jacobian -lJacobian -lm

all: test.c
	cd ../Jacobian; pymake; cd -
	gcc $(CFLAGS) -O3 -fPIC $^ $(LDFLAGS)
