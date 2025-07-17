# Makefile for C Learning Examples
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = .
BINDIR = bin

# Create bin directory if it doesn't exist
$(shell mkdir -p $(BINDIR))

# List of source files (without .c extension)
PROGRAMS = hello_world calculator temperature_converter student_records

# Default target
all: $(addprefix $(BINDIR)/, $(PROGRAMS))

# Rule to compile each program
$(BINDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# Individual targets for convenience
hello: $(BINDIR)/hello_world

calc: $(BINDIR)/calculator

temp: $(BINDIR)/temperature_converter

student: $(BINDIR)/student_records

# Clean compiled files
clean:
	rm -rf $(BINDIR)

# Run individual programs
run-hello: $(BINDIR)/hello_world
	./$(BINDIR)/hello_world

run-calc: $(BINDIR)/calculator
	./$(BINDIR)/calculator

run-temp: $(BINDIR)/temperature_converter
	./$(BINDIR)/temperature_converter

run-student: $(BINDIR)/student_records
	./$(BINDIR)/student_records

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Compile all programs"
	@echo "  hello     - Compile hello_world program"
	@echo "  calc      - Compile calculator program"
	@echo "  temp      - Compile temperature_converter program"
	@echo "  student   - Compile student_records program"
	@echo "  clean     - Remove compiled files"
	@echo "  run-*     - Compile and run specific program"
	@echo "  help      - Show this help message"

.PHONY: all clean help hello calc temp student run-hello run-calc run-temp run-student