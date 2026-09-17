## Upstream

This repository is a personal fork of [buresu/godot-spout](https://github.com/buresu/godot-spout), focused primarily on bug fixes, performance improvements, and optimizations required for my own use cases.
The original project and its authors remain the upstream source for the extension.

# godot-spout
Godot Spout Addon via GDExtension  
Forward+ D3D12 and Vulkan are supported for input/output.  
Compatibility/OpenGL3 is optionally supported for output only.  

## Build
See [`BUIILD.md`](BUIILD.md) for details.

## License
MIT License

## Known issues
- Dynamic switching to output viewport texture results in an empty texture.
- OpenGL3 input is not supported yet because can not get native input texture handle from godot.
