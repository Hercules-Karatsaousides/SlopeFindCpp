# Slope Calculator (Windows)

A simple interactive C++ console program that computes the slope of the line connecting two user-provided points.

This repository has been adjusted to improve compatibility across different Windows machines.

## What's included
- Windows console color support via ANSI escape sequences (enabled automatically on Windows 10+).
- Input validation with friendly prompts.
- Minimal dependencies and simple CMake configuration.

## Requirements
- Windows 10 or later recommended (for colorized output). The app enables VT100 (ANSI) processing at runtime.
- A C++17-capable compiler (e.g., MinGW-w64 GCC, MSVC).
- CMake 3.15 or newer.

## Build and Run (CLion)
This project is configured for CLion.

- Open the project folder in CLion.
- Use the existing active profile (e.g., Debug) and its preconfigured build directory.
- Build the target named `untitled`.
- Run the `untitled` executable from CLion.

Notes:
- The CMake minimum requirement has been lowered to 3.15 and the C++ standard set to C++17 to improve portability.
- On MinGW, the executable is linked statically for libgcc and libstdc++ via `target_link_options` to help execution on machines without the toolchain installed.

## Using the app
- The program prints a banner and instructions.
- Press Enter to continue when prompted, then enter coordinates for points A and B in the form: `x y` (e.g., `4.5 -5.5`).
- If the x-coordinates are the same, the program reports that the slope is undefined (vertical line).

## Console colors on Windows
This program uses ANSI escape sequences for colored output. On Windows 10+ command consoles and Windows Terminal, these are supported when VT processing is enabled. The program enables this automatically at startup.

If colors do not render correctly:
- Try running in Windows Terminal (from Microsoft Store) or a modern terminal emulator.
- Ensure you are not redirecting output to a file or a terminal that doesn't support ANSI.

## Troubleshooting
- Build errors about CMake version: install CMake 3.15+ or newer.
- Build errors about the C++ standard: ensure your compiler supports C++17.
- If the program builds but the colors look like `\x1b[...m`, your console doesn't support ANSI; try Windows Terminal.
- If the console does not clear between screens, `system("cls")` may not affect some IDE consoles; run from a standard Command Prompt or Windows Terminal.

## License
This project is provided as-is for demonstration/educational purposes.