objects=infix.o functions.o STACKImplementation.o

evaluation.exe : $(objects)
		gcc -o evaluation.exe $(objects)

functions.o : functions.c functions.h
		gcc -c functions.c

STACKImplementation.o : STACKImplementation.c STACKImplementation.h
		gcc -c STACKImplementation.c

infix.o : infix.c functions.h STACKImplementation.h
		gcc -c infix.c

clean:
		rm evaluation.exe $(objects)
