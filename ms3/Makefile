NAME = spiralMemory
INCLUDE = helperFunctions
CC = g++
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj

CPPFLAGS = -Wall
H_DEPS = ../$(INCLUDE).h
OBJ_DEPS = $(addprefix $(OBJDIR)/,$(NAME).o $(INCLUDE).o)
CPP_DEPS = $(NAME).cpp ../$(INCLUDE).cpp


all: $(BUILDDIR)/$(NAME) $(CPP_DEPS) $(H_DEPS)

$(BUILDDIR)/$(NAME): $(OBJ_DEPS) | $(BUILDDIR)
	$(CC) -o $@ $(OBJ_DEPS) $(CPPFLAGS)

$(OBJDIR)/$(NAME).o: $(NAME).cpp $(H_DEPS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CPPFLAGS)

$(OBJDIR)/$(INCLUDE).o: ../$(INCLUDE).cpp | $(OBJDIR)
	$(CC) -c -o $@ $< $(CPPFLAGS)

$(OBJDIR):
	mkdir -p $@

$(BUILDDIR):
	mkdir -p $@
