# Define input files and corresponding output executables
inputs := $(wildcard *.cpp)
outputs := $(inputs:.cpp=)
output_path := ../output

# Default target: build all executables
all: $(outputs)

# Rule to compile each input file into an output executable
$(outputs): %: %.cpp
	@mkdir -p $(output_path)
	g++ -o $(output_path)/$@ $<

# Phony target to clean the project
.PHONY: clean
clean:
	rm -rf $(output_path)
