CXX = g++

TARGET = LiarsDeckValidCardSimulation.exe

SRCS = src/main.cpp src/util.cpp

OBJS = obj/main.o obj/util.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

obj/%.o: src/%.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(TARGET) obj/*.o