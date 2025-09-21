PLATFORM = $(shell uname -m)

ifneq ($(PLATFORM),aarch64)
ifneq ($(UNAME_S),Darwin)
ifeq ($(origin AS),default)
AS = aarch64-elf-as
endif
ifeq ($(origin CC),default)
CC = aarch64-elf-gcc
endif
endif
endif

CFLAGS ?= -g -Wall -Wextra -std=c99

ifeq ($(UNAME_S),Darwin)
CFLAGS += -fPIE
else
CFLAGS += -pedantic -Werror
endif
LDFLAGS ?= -pie -Wl,--fatal-warnings

C_OBJS = $(patsubst %.c,%.o,$(wildcard *.c))
AS_OBJS = $(patsubst %.s,%.o,$(wildcard *.s))
ALL_OBJS = $(filter-out example.o,$(C_OBJS) $(AS_OBJS) vendor/unity.o)

CC_CMD = $(CC) $(CFLAGS) -c -o $@ $<

ifeq ($(PLATFORM),aarch64)
	MAYBE_QEMU ?=
else
	MAYBE_QEMU ?= qemu-aarch64 -L /usr/aarch64-linux-gnu
endif

all: tests
	@$(MAYBE_QEMU) ./$<

tests: $(ALL_OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(ALL_OBJS)

%.o: %.s
	@$(AS) -o $@ $<

%.o: %.c
	@$(CC_CMD)

vendor/unity.o: vendor/unity.c vendor/unity.h vendor/unity_internals.h
	@$(CC_CMD)

clean:
	@rm -f *.o vendor/*.o tests

.PHONY: all clean
