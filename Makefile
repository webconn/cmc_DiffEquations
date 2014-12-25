TARGET = diffeq
OBJS = main.o grid.o runge-kutta.o func1.o system1.o test.o boundary.o func2.o

CFLAGS = -std=gnu99 -Iinclude -g
LDFLAGS = -lm

OBJS := $(addprefix build/, $(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc -o $@ $^ $(LDFLAGS)

$(OBJS): | build

build: 
	mkdir build

build/%.o: %.c
	gcc -c -o $@ $^ $(CFLAGS)

clean:
	rm $(TARGET) build -rf
