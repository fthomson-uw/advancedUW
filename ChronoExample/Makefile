CC=g++-11

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -std=c++20 -Wall -Werror $(OPTFLAGS)
# CFLAGS=-I. -std=gnu++2a -Wall -Werror $(OPTFLAGS)

PROJDIR := $(realpath $(CURDIR)/..)
BUILDDIR := $(PROJDIR)/Output

DIRS = ChronoExample

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) ../bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	# $(CXX) -c -o $$@ $$< $$(CFLAGS)
	/usr/local/bin/g++-11 -c -o $$@ $$< $$(CFLAGS)
endef

ChronoExample: $(OBJ) directories
	 /usr/local/bin/g++-11 $(OBJ) -o ../bin/chronoExample $(OPTFLAGS)
	# $(CXX) $(OBJ) -o ../bin/chronoExample $(OPTFLAGS)


$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)


all: directories

clean:
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)
