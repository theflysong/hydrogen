OBJECTDIR := $(OBJECTDIR)/hydrogen2

APPNAME := $(BASENAME)2
_OBJECTS := main
OBJECTS := $(foreach obj, $(_OBJECTS), $(OBJECTDIR)/$(obj).o)
CPPINCLUDE := -I"$(ROOTDIR)/hydrogen2"

$(OBJECTDIR)/%.o : $(SRCDIR)/%.cpp
	$(MKDIR) $(dir $@)
	$(CPPC) $(CPPFLAGS) $(CPPDEFINES) $(CPPINCLUDE) -c -o $@ $^

$(APPNAME) : $(OBJECTS)
	$(MKDIR) $(dir $@)
	$(CPPC) -o $@ $^
	echo $(APPNAME)

.PHONY: build clean
build: $(APPNAME)
	echo "done" 

clean:
	$(RM) $(OBJECTS) $(APPNAME)