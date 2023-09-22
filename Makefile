# Makefile

ROOT_PATH=.
FILE_WATCHER_PATH=$(ROOT_PATH)/pkg/filewatch

include $(ROOT_PATH)/inc.mk

C_FILES=$(wildcard $(FILE_WATCHER_PATH)/*.cpp)
O_FILES=$(C_FILES:.cpp=.o)

.PHONY: clean

all: $(O_FILES)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(O_FILES)
