OBJECTDIR := $(OBJECTDIR)/hydrogen1

APPNAME := $(BASENAME)1
_OBJECTS := main hylex
OBJECTS := $(foreach obj, $(_OBJECTS), $(OBJECTDIR)/$(obj).o)
CPPINCLUDE := -I"$(ROOTDIR)/hydrogen1"

$(OBJECTDIR)/%.o : %.cpp
	echo $(OBJECTDIR)
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