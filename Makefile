CC := g++
CFLAGS := -std=c++17 -Iinclude -pthread

SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGET := executable

SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(BUILDDIR) $(TARGET)