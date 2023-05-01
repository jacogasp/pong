# Gogot GDExtension Template

This project provides a ready to use Godot game template using GDExtension and
C++.

## Building with CMake

To build this project, use one of the following CMakePresets:

```shell
  "debug"
  "release"
  "macos"
  "linux"
  "windows"
  "ci-macos"
  "ci-linux"
  "ci-windows"
  ```

  for example, for configuring the project:

  ```shell
  cmake --preset macos
  ```

  and to build:

  ```shell
  cmake --build --preset macos
  ```

## Git Hooks

This project provides a GitHub CI/CD action worflow, which builds the game source
code as shared libraries for each OS (`.so` for Linux, `.dylib` for macOS and
`.dll` for Windows) and store them as GitHub artifacts.

The `.githooks` directory provides scripts to automatically download the
artifacts to your local `build` directory, in order to run the game.

To automatically download the artifacts at each pull, link the `.githooks` to
your `.git/hooks` folder with

```shell
ln -s $(pwd)/.githooks/* $(pwd)/.git/hooks
```

> You need **Python** and **GitHub CLI** installed.

## Manually download artifacts

To manually download artifacts, run

```shell
python download_artifacts.py <user>/<repo-name>
```

## Development with Vistual Studio Code

In order to develop with VSCode, create and edit your
`.vscode/c_cpp_properties.json` file and point the `compileCommands` value to
your `compile_commands.json` generated by CMake for your build preset.

For example, if you are building with macos preset, your `c_cpp_properties.json`
should look like

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            // Add the following line
            "compileCommands": "${workspaceFolder}/build/macos/compile_commands.json",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```
