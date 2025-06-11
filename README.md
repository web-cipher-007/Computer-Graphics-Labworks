This repository contains lab assignments and implementations for the Computer Graphics course.<br>
## ⚠️ Notes for Working with Turbo C++
If you're using Turbo C++ (especially Turbo C++ 3.0 in DOSBox), please keep the following points in mind when running graphics programs like the Bresenham Line Algorithm and Midpoint Ellipse Algorithm:

### 📌 1. Setup Requirements
- Install Turbo C++ inside `C:\TURBOC3`.
- Make sure the BGI graphics driver path is correct in your code, for example:  
  ```cpp
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  ```

### 📌 2. Use `clrscr()` and `getch()`
- Use `clrscr()` to clear the screen at the start of your program.
- Use `getch()` at the end to pause the output so the graphics window does not close immediately.

### 📌 3. Use `graphics.h` Carefully
- Turbo C++ supports 16-color VGA graphics (640x480 resolution).
- Use predefined color constants like `RED`, `WHITE`, `BLUE`, etc., instead of numeric color values.

### 📌 4. Avoid Modern C++ Features
- Turbo C++ does **not** support modern C++ features such as `iostream`, `std::vector`, or namespaces.
- Use classic C headers and syntax: `stdio.h`, `conio.h`, `void main()`, `scanf()`, etc.

### 📌 5. Avoid Floating-Point Math Where Possible
- Prefer integer arithmetic to maintain compatibility and performance.
- If floating-point math is necessary, use `float` rather than `double`.

### 📌 6. Use `delay()` for Animation Effects
- The `delay(milliseconds)` function helps slow down drawing steps for visual clarity.

### 📌 7. Graphical Output is Pixel-Based
- Use `putpixel(x, y, COLOR)` to draw pixels.
- Coordinates must stay within screen limits:  
  `0 <= x <= 639`, `0 <= y <= 479`.

### 📌 8. Avoid Compilation Warnings
- Declare all variables before use.
- Consistently use correct data types like `int`, `long`, and `float`.

### 📌 9. Compatible Math Operations
- Avoid direct floating point operations in integer contexts, for example:  
  `(x + 0.5)*(x + 0.5)`  
  Instead, store in a `float` variable first to avoid truncation.
