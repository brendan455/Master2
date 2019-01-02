#BOOST_FOLDER=/ccipl/logiciels/boost/include/
BOOST_FOLDER=
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Makefile for Unix & Linux Systems #
# using a GNU C++ compiler #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# compiler flags
# -g --Enable debugging
# -Wall --Turn on all warnings
# -D_USE_FIXED_PROTOTYPES_
# --Force the compiler to use the correct headers
# -ansi --Don't use GNU ext; do use ansi standard.

INC=-I$(BOOST_FOLDER) \
 -I./include \

CXX=g++ -o
CXXFLAGS=-std=c++11 -fopenmp -Wall -Wextra -DNDEBUG -g $(INC)
LFLAGS=-std=c++11 -fopenmp -Wall -Wextra -DNDEBUG -I$(BOOST_FOLDER) -lm

SRCDIR=source
OBJDIR=objet
BINDIR=.
rm=rm -f

OBJ=$(OBJDIR)/main.o \

TARGET=$(BINDIR)/

all: $(TARGET)

$(TARGET): $(OBJ)
	@g++ $^ -o $@ $(LFLAGS)
	@echo "Linking complete."

$(OBJDIR)/main.o: ./$(SRCDIR)/main.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled main.o"

#---------------------
# Compilation
#---------------------
# $(OBJDIR)/main.o: ./$(SRCDIR)/main.cpp
# 	@$(CXX) $@ -c $< $(CXXFLAGS)
# 	@echo "Compiled main.o"

#---------------------
# PHONEY
#---------------------
.PHONEY: clean
clean:
	@$(rm) $(OBJ)
	@echo "Cleanup complete."

.PHONEY: remove
remove: clean
	@$(rm) $(TARGET)
	@echo "Executable removed."
