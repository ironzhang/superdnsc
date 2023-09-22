# Makefile

ROOT_PATH=../..
FILE_WATCHER_PATH=$(ROOT_PATH)/pkg/filewatch

include $(ROOT_PATH)/inc.mk

TARGET=test
C_FILES=$(wildcard *.cpp) $(wildcard $(FILE_WATCHER_PATH)/*.cpp)
O_FILES=$(C_FILES:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(O_FILES)
	$(CC) -o $(TARGET) $^ $(LFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(O_FILES) $(TARGET)
