CD := cd
CPPC := g++
RM := rm
MKDIR := mkdir -p -v

ROOTDIR := $(shell pwd)
MODE := debug
CPPFLAGS := -std=gnu++17
CPPDEFINES :=
ifeq ($(MODE), debug)
	CPPDEFINES += -D__DEBUG__
else
	CPPFLAGS += -Os
endif
CPPINCLUDE :=
BUILDDIR := $(ROOTDIR)/build/$(MODE)/
OBJECTDIR := $(BUILDDIR)/objects/
BINDIR := $(BUILDDIR)/bin/
BASENAME := $(BINDIR)/hydrogen

export CD CPPC RM MKDIR BASENAME ROOTDIR MODE BUILDDIR BINDIR OBJECTDIR CPPFLAGS CPPDEFINES CPPINCLUDE

.PHONY: setup h1_build h1_clean h2_build h2_clean

h1_build:
	$(CD) ./hydrogen1/ ; $(MAKE) build

h1_clean:
	$(CD) ./hydrogen1/ ; $(MAKE) clean

h2_build:
	$(CD) ./hydrogen2/ ; $(MAKE) build

h2_clean:
	$(CD) ./hydrogen2/ ; $(MAKE) clean