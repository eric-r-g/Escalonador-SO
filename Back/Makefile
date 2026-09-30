CXX      := g++
CPPFLAGS := -Iinclude                 # Flags de pré-processamento
CXXFLAGS := -MMD -MP                  # Flags de compilação
LDFLAGS  :=                           # Flags de linkagem

SRC      := $(wildcard src/*.cpp)
OBJ      := $(patsubst src/%.cpp,build/%.o,$(SRC))
DEP      := $(OBJ:.o=.d)

TARGET   := back

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

-include $(DEP)
