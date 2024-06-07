all: clean Shootout VitalMessage

Shootout: Shootout.c
	mkdir bin 2> /dev/null || true
	gcc Shootout.c -o ./bin/Shootout

VitalMessage: VitalMessage.c
	mkdir bin 2> /dev/null || true
	gcc VitalMessage.c -o ./bin/VitalMessage

clean: 
	rm ./bin/Shootout 2> /dev/null || true
	rm ./bin/VitalMessage 2> /dev/null || true
