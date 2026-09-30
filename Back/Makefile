CC      := g++
CFLAGS  := -Wall -Wextra -O2 -std=c++20
LDFLAGS :=
LDLIBS  := -lm

TARGET  := back
SRCS    := $(wildcard **/*.cpp)
SRCS    += $(wildcard *.cpp)
OBJS    := $(SRCS:.cpp=.o)

CFLAGS += -MMD -MP
-include $(OBJS:.o=.d)

.PHONY: all clean install test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f $(OBJS) $(TARGET)

test: $(TARGET)
	./$(TARGET) --test
