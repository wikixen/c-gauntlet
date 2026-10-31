CFLAGS= -lm
FILE?=sorts

TARGET = build/${FILE}
SRC = src/${FILE}.c

default: build run

.PHONY: build
build:
	gcc ${CFLAGS} -o ${TARGET} ${SRC}

.PHONY: run
run:
	./${TARGET}