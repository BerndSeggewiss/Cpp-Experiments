# Simple Makefile for C++ Experiments
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
INCLUDES = -I.

# Chapter 9 targets
ch9_drill:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ "Chapter 9/Drill/StrDrillCh9.cpp" "Chapter 9/Drill/Chrono.cpp"

# Chapter 10 targets  
ch10_ex1:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ "Chapter 10/StrCh10Ex1.cpp"

# Chapter 11 targets
ch11_ex1:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ "Chapter 11/StrCh11Ex1.cpp"

ch11_ex9:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ "Chapter 11/StrCh11Ex9.cpp"

# Chapter 12 targets (note: requires FLTK for graphics)
ch12_ex:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ "Chapter 12/Ex1-5Ch12.cpp"

# Build all non-graphics examples
all: ch9_drill ch10_ex1 ch11_ex1 ch11_ex9 ch12_ex

# Clean build artifacts
clean:
	rm -f ch9_drill ch10_ex1 ch11_ex1 ch11_ex9 ch12_ex

.PHONY: all clean