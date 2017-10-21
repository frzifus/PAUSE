# This file is part of PAUSE.
#
# PAUSE is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the frzifus, either version 3 of the License.
#
# PAUSE is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# see <http://www.gnu.org/licenses/>.

CXX=gcc
CXXFLAGS=-std=gnu99 -I ./src/ -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -c -O3

SOURCEDIR=./src/

PATH := /usr/bin:$(PATH)

LDFLAGS=

SOURCES:= $(shell find $(SOURCEDIR) -name '*.c')
OBJDIR=./build/obj
OBJ=$(SOURCES:.c=.o)
OBJECTS=$(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))
EXECUTABLE=build/bin/PAUSE

all: objFolder $(SOURCES) $(EXECUTABLE)
	@echo Finish!!

$(EXECUTABLE): objFolder $(OBJ)
	@echo Build executable $@
	@$(CXX) $(LDFLAGS) $(OBJECTS) $(STATLIBS) -o $@

.c.o:
	@echo Build object $@
	@$(CXX) $(CXXFLAGS) $< -o $(OBJDIR)/$@

objFolder:
	@echo Create folder
	mkdir -p build/bin
	for folder in $(shell ls -d src/*) ; do \
		mkdir -p $(OBJDIR)/$$folder ; \
	done

clean:
	rm -f $(shell find build/ -name '*.o')

distclean:
	rm -fr build

install:
	cp ./build/bin/PAUSE /usr/bin/PAUSE
run:
	@echo Run executable
	./$(EXECUTABLE)
