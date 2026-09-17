## Building

### Requirements

* Windows
* CMake 3.15+
* Visual Studio 2022 or another compatible C++ compiler
* Vulkan SDK, when building with Vulkan support
* Git

Clone the repository together with its submodules:

```bash
git clone --recursive https://github.com/RottenKotten/rotten-godot-spout.git
cd rotten-godot-spout
```

If the repository was cloned without submodules:

```bash
git submodule update --init --recursive
```

### Visual Studio 2022

Configure a Vulkan build:

```powershell
cmake -S . -B build `
    -G "Visual Studio 17 2022" `
    -A x64 `
    -DGODOT_SPOUT_ENABLE_VULKAN=ON
```

Build Debug:

```powershell
cmake --build build --config Debug
```

Build Release:

```powershell
cmake --build build --config Release
```

### Optional features

OpenGL backend:

```text
-DGODOT_SPOUT_ENABLE_OPENGL=ON
```

Vulkan backend:

```text
-DGODOT_SPOUT_ENABLE_VULKAN=ON
```

Tracy instrumentation:

```text
-DGODOT_SPOUT_ENABLE_TRACY=ON
```

Options can be combined, for example:

```powershell
cmake -S . -B build `
    -G "Visual Studio 17 2022" `
    -A x64 `
    -DGODOT_SPOUT_ENABLE_VULKAN=ON `
    -DGODOT_SPOUT_ENABLE_TRACY=ON
```

### Ninja

For a single-config generator such as Ninja, specify the build type during configuration:

```powershell
cmake -S . -B build `
    -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DGODOT_SPOUT_ENABLE_VULKAN=ON
```

Then build with:

```powershell
cmake --build build
```

### Install into the demo project

After building, install the extension files into:

```text
demo/addons/godot-spout
```

For Visual Studio:

```powershell
cmake --install build --config Release
```

For a single-config build:

```powershell
cmake --install build
```

The build directory does not need to be named `build` and does not need to be inside the repository. For example:

```powershell
cmake -S . -B out/godot-spout
cmake --build out/godot-spout --config Release
```
