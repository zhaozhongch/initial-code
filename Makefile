cc=g++
cf=-c

all:bayesopt

bayesopt:GaubasedonArm.o zminush.o Kernal.o FindMaxu.o Acqui.o Nextu.o
	$(cc) GaubasedonArm.o zminush.o Kernal.o FindMaxu.o Acqui.o Nextu.o -o bayesopt -O2 -larmadillo

GaubasedonArm.o: GaubasedonArm.cpp
	$(cc) $(cf) GaubasedonArm.cpp
zminush.o: zminush.cpp
	$(cc) $(cf) zminush.cpp
Kernal.o: Kernal.cpp
	$(cc) $(cf) Kernal.cpp
FindMaxu.o: FindMaxu.cpp
	$(cc) $(cf) FindMaxu.cpp
Acqui.o: Acqui.cpp
	$(cc) $(cf) Acqui.cpp
Nextu.o: Nextu.cpp
	$(cc) $(cf) Nextu.cpp
clean:
	rm -rf *o bayesopt

