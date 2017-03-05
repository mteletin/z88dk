#-----------------------------------------------------------------------------
# zlink
# Copyright (c) Paulo Custodio, 2017
# License: http://www.perlfoundation.org/artistic_license_2_0
#-----------------------------------------------------------------------------
PROJ		:= zlink

ifeq ($(OS),Windows_NT)
  EXE 		:= .exe
else
  EXE 		:= $(EXESUFFIX)
endif

CXX			?= g++
INSTALL 	?= install

SRCS 		:= $(wildcard *.cpp)
OBJS 		:= $(SRCS:.cpp=.o)
T_SRCS 		:= $(wildcard t/*.cpp)
T_OBJS 		:= $(T_SRCS:.cpp=.o)
DEPENDS		:= $(SRCS:.cpp=.d) $(T_SRCS:.cpp=.d)

CXXFLAGS	+= -MMD -Wall $(CXXOPT)

define MAKE_EXE
all: $(1)$(EXE)

$(1)$(EXE): $(1).o lib$(PROJ).a 
	${CXX} -o$(1)$(EXE) $(1).o -L. -l$(PROJ) $(CXXFLAGS)

clean::
	$(RM) $(1)$(EXE) $(1).o
endef

$(foreach i,$(PROJ) $(T_SRCS:.cpp=),$(eval $(call MAKE_EXE,$(i))))

all: lib$(PROJ).a

lib$(PROJ).a: $(OBJS)
	ar rcs $@ $(subst $(PROJ).o,,$(OBJS))

install: $(PROJ)$(EXE)
	$(INSTALL) $(PROJ)$(EXE) $(PREFIX)/bin/

test: $(T_SRCS:.cpp=$(EXE))
	set -x -e; $(foreach i,$(T_SRCS:.cpp=$(EXE)),$(i);)

valgrind: 
	$(MAKE) CXXOPT=-g $(T_SRCS:.cpp=$(EXE))
	set -x -e; $(foreach i,$(T_SRCS:.cpp=$(EXE)),valgrind -q --tool=memcheck --leak-check=full --track-fds=yes --error-exitcode=1 $(i);)

clean::
	$(RM) $(OBJS) $(T_OBJS) lib$(PROJ).a $(DEPENDS) core test.*

-include $(DEPENDS)
