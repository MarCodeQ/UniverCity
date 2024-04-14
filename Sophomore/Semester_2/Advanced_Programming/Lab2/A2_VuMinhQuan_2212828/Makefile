# Define input files and corresponding output executables
inputs := $(wildcard *.cpp)
outputs := $(inputs:.cpp=)
# output_path := A2_VuMinhQuan_2212828

# Default target: build all executables
all: $(outputs)

# Rule to compile each input file into an output executable
$(outputs): %: %.cpp
	g++ -o $@ $<

# Phony target to clean the project
.PHONY: clean
clean:
	rm -rf
