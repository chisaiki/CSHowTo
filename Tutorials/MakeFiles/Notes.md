# Makefile Notes

## What is the Point of Makefiles?

Makefiles automate and optimize the build process. Here's why they matter:

### 1. Avoid Recompiling Everything
Without a Makefile, you'd manually compile every file every time:
```bash
g++ file1.cpp -c -o file1.o
g++ file2.cpp -c -o file2.o
g++ file3.cpp -c -o file3.o
g++ file1.o file2.o file3.o -o program
```

With Make, you just type `make` and it **only recompiles changed files**.

### 2. Manage Dependencies
```makefile
main: file1.o file2.o file3.o
	g++ file1.o file2.o file3.o -o main

file1.o: file1.cpp header.h
	g++ -c file1.cpp

file2.o: file2.cpp header.h
	g++ -c file2.cpp
```
If you change `header.h`, Make knows to rebuild both `file1.o` and `file2.o`.

### 3. Save Time on Large Projects
- 100 files, change 1 file → Make only recompiles that 1 file
- Manual: you'd recompile all 100 files (or forget which ones changed)

### 4. Consistency
Everyone on your team uses the same build commands - no "it works on my machine" issues.

### 5. Multiple Targets
```makefile
make        # builds the program
make clean  # deletes output files
make test   # runs tests
make install # installs the program
```

### Real-world Impact
- Small project (3 files): saves a few seconds
- Large project (1000+ files): saves **hours** per build

---

## Clean Target - Deleting Only Output Files

In a Makefile clean target, you should delete:
- **Executable files** (the compiled program)
- **Object files** (`.o` files)
- **Any other intermediate build artifacts**

### Basic Syntax
```makefile
clean:
	rm -f outputfile.exe *.o
```

### Key Points
- Use `rm -f` (the `-f` flag prevents errors if files don't exist)
- List specific output files by name
- Use wildcards like `*.o` for object files
- **Never include source files** like `.cpp`, `.c`, `.h`, `.hpp`

### Example
```makefile
clean:
	rm -f program.exe program *.o
```

This will only delete:
- `program.exe` or `program` (the executable)
- Any `.o` object files
- Your source files remain untouched

---

## Naming the Executable

To name your executable a specific name in a Makefile, use the `-o` flag with the compiler.

### Basic Structure
```makefile
target_name: source_files
	g++ source_files -o executable_name
```

### Example
```makefile
# Name your executable whatever you want
program: sourcecode.cpp
	g++ sourcecode.cpp -o program

clean:
	rm -f program *.o
```

### Key Points
- The `-o` flag specifies the output executable name
- The target name (left of `:`) can match the executable name but doesn't have to
- Make sure your `clean` target deletes the same executable name you specified

### Using Variables (Best Practice)
```makefile
TARGET = myprogram
SOURCES = sourcecode.cpp

$(TARGET): $(SOURCES)
	g++ $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
```

This makes it easy to change the executable name in one place.

---

## Clock Skew Warnings

You might see these warnings:
```
make: Warning: File 'Makefile' has modification time 1.5 s in the future
make: warning: Clock skew detected. Your build may be incomplete.
```

### What They Mean
- Your Makefile timestamp is "in the future" compared to system clock
- Make is warning that dependency checking might be unreliable
- Common in WSL (Windows Subsystem for Linux)
- **Your build still completes successfully**

### Quick Fixes

**Option 1: Update file timestamps (simplest)**
```bash
touch Makefile sourcecode.cpp
```

**Option 2: Add to your Makefile to prevent the warning**
```makefile
.PHONY: clean
```

**Option 3: If it happens frequently in WSL**
```bash
sudo hwclock -s
```

### Should You Worry?
No, if your build completes and the executable works. The clock skew is just a timing sync issue.