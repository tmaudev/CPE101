MAIN=quadratic
CFLAGS=-ansi -Wall -pedantic

all: debug run

debug : ${MAIN}_debug
run : ${MAIN}_run

${MAIN}_debug : ${MAIN}.c checkit.h
	gcc -o ${MAIN}_debug ${CFLAGS} ${MAIN}.c -lm

${MAIN}_run : ${MAIN}.c checkit.h
	gcc -o ${MAIN}_run -DNCHECKIT ${CFLAGS} ${MAIN}.c -lm

clean :
	\rm ${MAIN}_debug ${MAIN}_run

