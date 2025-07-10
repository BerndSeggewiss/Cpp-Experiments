# C++ Experiments Repository

This repository contains C++ programming exercises from Stroustrup's "Programming: Principles and Practice Using C++" book, organized by chapters 9-12.

## Repository Structure

```
├── Chapter 9/          # Class design, data abstraction
├── Chapter 10/         # Input/output streams
├── Chapter 11/         # Customizing input/output  
├── Chapter 12/         # Graphics library (FLTK)
├── std_lib_facilities.h # Common header file
├── std_lib.h           # Alternative header file
└── Makefile           # Build configuration
```

## Code Review Improvements Applied

### ✅ Fixed Issues:
- **Missing Headers**: Added `std_lib_facilities.h` and `std_lib.h` required by the exercises
- **Logic Bugs**: Fixed incorrect date arithmetic in `Chrono.cpp` `add_day()` function
- **Hardcoded Paths**: Removed Windows-specific absolute file paths, made code portable
- **File Naming**: Standardized filenames, removed trailing spaces
- **Validation Logic**: Fixed redundant conditions in date validation
- **Build System**: Added Makefile for easy compilation
- **Platform Dependencies**: Made graphics code conditional with clear documentation

### 📝 Key Changes:
1. **Date Logic Fix**: `add_day()` now correctly adds days instead of always setting to day+1
2. **Portable Paths**: File operations now use relative paths instead of hardcoded Windows paths
3. **Graphics Support**: Chapter 12 exercises documented as requiring FLTK library
4. **Build Support**: Added Makefile with individual targets for each chapter

## Building the Projects

### Prerequisites
- C++ compiler supporting C++11 (g++, clang++)
- For Chapter 12 graphics: FLTK library (optional)

### Using the Makefile
```bash
# Build specific chapters
make ch9_drill    # Chapter 9 date/time exercises
make ch10_ex1     # Chapter 10 file I/O
make ch11_ex1     # Chapter 11 text processing
make ch11_ex9     # Chapter 11 binary file conversion
make ch12_ex      # Chapter 12 (note: needs FLTK for full functionality)

# Build all examples
make all

# Clean build artifacts
make clean
```

### Manual Compilation
```bash
# Chapter 9 example
g++ -std=c++11 -I. "Chapter 9/Drill/StrDrillCh9.cpp" "Chapter 9/Drill/Chrono.cpp" -o ch9_drill

# Chapter 10 example  
g++ -std=c++11 -I. "Chapter 10/StrCh10Ex1.cpp" -o ch10_ex1

# Chapter 11 example
g++ -std=c++11 -I. "Chapter 11/StrCh11Ex1.cpp" -o ch11_ex1
```

## Chapter Overview

### Chapter 9: Classes
- **Drill**: Date class implementation with multiple namespaces
- **Exercises**: Various class design problems
- **Key Files**: `Chrono.h`, `Chrono.cpp`, `StrDrillCh9.cpp`

### Chapter 10: Input/Output Streams
- **Focus**: File I/O, stream operations
- **Examples**: Reading numbers from files, data processing
- **Key Files**: `StrCh10Ex*.cpp`

### Chapter 11: Customizing I/O
- **Focus**: Advanced I/O operations, binary files
- **Examples**: Text processing, binary conversion
- **Key Files**: `StrCh11Ex*.cpp`

### Chapter 12: Graphics (FLTK Required)
- **Focus**: GUI programming with FLTK
- **Examples**: Drawing shapes, text rendering
- **Note**: Requires FLTK library installation
- **Key Files**: `Ex1-5Ch12.cpp`, `Ex6Ch12.cpp`

## Installing FLTK (for Chapter 12)

### Ubuntu/Debian:
```bash
sudo apt-get install libfltk1.3-dev
```

### macOS:
```bash
brew install fltk
```

### Windows:
Download from [FLTK website](https://www.fltk.org/software.php)

## Running Examples

Most examples expect input files in the same directory. Sample files are provided where needed:
- `Text.txt` - Sample text file for Chapter 11 exercises
- `raw_temps.txt` - Temperature data for Chapter 10
- Various `.txt` files for specific exercises

## Code Quality Notes

The code follows the style and patterns from Stroustrup's textbook:
- Uses `using namespace std;` (acceptable for learning exercises)
- Follows book's naming conventions
- Includes error handling with custom `error()` function
- Demonstrates progressive C++ concepts chapter by chapter

## Contributing

When adding new exercises or fixes:
1. Follow existing naming conventions
2. Use relative paths, not absolute
3. Test compilation with the provided Makefile
4. Document any external dependencies
5. Ensure cross-platform compatibility

## License

Educational exercises based on "Programming: Principles and Practice Using C++" by Bjarne Stroustrup.