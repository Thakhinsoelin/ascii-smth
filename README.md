# ascii-smth
Backend for ascii social media platform site

## Prerequisites

- [Visual Studio Code](https://code.visualstudio.com/)
- [CMake](https://cmake.org/) (version 3.10 or higher)
- [Ninja](https://ninja-build.org/) (recommended)
- [Git](https://git-scm.com/)
- [vcpkg](https://github.com/microsoft/vcpkg) (remember to follow the instruction from the vcpkg readme page)
- Visual Studio Build Tools (with C++ support) or MSVC

## Getting Started

### 1. Clone the repository

```powershell
git clone https://github.com/ThaKhinso/ascii-smth.git
cd ascii-smth
```


### 2. Open the project in Visual Studio Code
**This project use the msvc as the compiler so you need to first open the developer powershell for VS2022 and from there cd to the project you cloned and type**
```powershell
code .
```

### 3. Setup the environment variables
In the setupenv.ps1 script, change the VCPKG_ROOT to your own folder of vcpkg you cloned.
Run the provided PowerShell script to set the `VCPKG_ROOT` environment variable:

```powershell
.\setupenv.ps1
```

### 4. Configure cmake

- Press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> and select `CMake: Select Configure Preset`, then choose `default`.
- Press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> and select `CMake: Build`.

CMake and vcpkg will automatically install the required dependencies (`crow`, `fmt`).

### 5. Build and Run the application
After the above steps, you should see that cmake has written the build files to the build folder. To run the build system if you are in the project root:
```powershell
cmake --build build
```
or replace the build argument behind --build to where the build files are written

After building, you can run the executable from the terminal:

```powershell
.\build\HelloWorld.exe
```

The server will start on port 18080.  
Visit [http://localhost:18080/](http://localhost:18080/) in your browser.

## Notes

- All dependencies are managed via vcpkg and specified in `vcpkg.json`.
- The project targets Windows 10 or later (`_WIN32_WINNT=0x0A00`).
- For more details, see the [official Microsoft guide for vcpkg with VS Code](https://learn.microsoft.com/en-us/cpp/build/vcpkg).

Note that commands should also work in other operating systems. You might need to setup environment vairable in your operating systems' ways tho.