CD := cd
CPPC := g++
RM := rm
MKDIR := mkdir

ROOTDIR := $(shell pwd)
MODE := debug
CPPFLAGS :=
CPPDEFINES :=
ifeq ($(MODE), debug)
	CPPDEFINES += -D__DEBUG__
else
	CPPFLAGS += -Os
endif
BUILDDIR := $(ROOTDIR)/build/$(MODE)/
OBJECTDIR := $(BUILDDIR)/objects/
BINDIR := $(BUILDDIR)/bin/
BASENAME := $(BINDIR)/hydrogen

export CD CPPC RM MKDIR BASENAME ROOTDIR MODE BUILDDIR BINDIR OBJECTDIR CPPFLAGS CPPDEFINES

.PHONY: setup h1_build, h1_clean
setup:
	$(MKDIR) -p -v $(BUILDDIR)
	$(MKDIR) -p -v $(OBJECTDIR)
	$(MKDIR) -p -v $(BINDIR)

h1_build:
	$(CD) ./hydrogen1/ ; $(MAKE) build

h1_clean:
	$(CD) ./hydrogen1/ ; $(MAKE) clean