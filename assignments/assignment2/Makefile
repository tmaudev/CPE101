MAIN=ccard
CFLAGS=-std=c99 -pedantic
LFLAGS=-lm

all: debug run

debug : ${MAIN}_debug
run : ${MAIN}_run

${MAIN}_debug : ${MAIN}.c checkit.h
	gcc -o ${MAIN}_debug ${CFLAGS} -Wall ${MAIN}.c ${LFLAGS}

${MAIN}_run : ${MAIN}.c checkit.h
	gcc -o ${MAIN}_run -DNCHECKIT ${CFLAGS} ${MAIN}.c ${LFLAGS}

clean :
	\rm ${MAIN}_debug ${MAIN}_run

