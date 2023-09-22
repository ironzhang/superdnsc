# inc.mk

AR=ar
CC=g++

IPATH=-I$(ROOT_PATH) -I$(ROOT_PATH)/pkg
CFLAGS=$(IPATH) -std=c++11 -g -W -Wall -Wno-unused-parameter -Wno-deprecated -D__MACOS__

LPATH=
LFLAGS=$(LPATH)

