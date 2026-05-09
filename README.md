# MessiPass

> Simple C++ password manager demo (educational/demo purposes only).

## Description

`MessiPass` is a small command-line C++ program that manages a list of passwords in a plaintext file (`passwords.txt`). It's intended for learning and demonstration of basic file I/O and simple password storage concepts.

## Files

- `main.cpp` — program entry point
- `MessiPass.cpp` — implementation
- `MessiPass.h` — header for the implementation
- `passwords.txt` — plaintext storage used by the program

## Requirements

- A C++ compiler supporting C++11 or later (g++, clang, MSVC)

## Build (g++)

Run this in the project root directory:

```bash
g++ main.cpp MessiPass.cpp -o MessiPass.exe
```

## Run

On Windows (PowerShell / CMD):

```powershell
./MessiPass.exe
```

On other platforms, adjust the executable name accordingly.

## Usage

The program reads and writes `passwords.txt` in the project folder. Because the file is plaintext, do not store real or sensitive credentials here.

## Security Notice

This project stores passwords in plaintext and is for educational/demonstration use only. Do NOT use this for real password management. Consider using a proper password manager or encrypting stored data if you expand this project.

## Contributing

Feel free to open issues or submit PRs to improve the project. Suggested improvements:

- Add encryption for stored data
- Replace plaintext storage with a secure database
- Improve command-line interface and input validation

## License

This repository is provided without a license. Add a suitable license file if you intend to share or reuse the code.

---

Created for the local `MessiPass` project.
