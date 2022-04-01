APPNAME := $(BASENAME)_1
_OBJECTS := main hylex
OBJECTS := $(foreach obj, $(_OBJECTS), $(OBJECTDIR)/$(obj).o)

$(OBJECTDIR)/%.o : %.cpp
	$(CPPC) $(CPPFLAGS) $(CPPDEFINES) -c -o $@ $^

$(APPNAME) : $(OBJECTS)
	$(CPPC) -o $@ $^
	echo $(APPNAME)

.PHONY: build clean
build:
	$(MAKE) $(APPNAME)

clean:
	$(RM) $(OBJECTS) $(APPNAME)