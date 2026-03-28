<!--
    SPDX-FileCopyrightText: 2022 Felipe Kinoshita <kinofhek@gmail.com>
    SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
    SPDX-License-Identifier: CC0-1.0
-->

# Localquens

is a fork of KDE Eloquens that runs entirely on your local machine. It is a lorem ipsum generator. The upstream version relied the now-defunct loripsum.net API. Based off what the upstream code seems to expect and some googling, I took a crack at reconstructing it and bundling it with this fork.

## Dependencies

- CMake 3.16+
- Qt 6.5+ (Core, Gui, Qml, QuickControls2, Svg, Widgets)
- KDE Frameworks 6.7+ (Kirigami, CoreAddons, Config, I18n, DBusAddons)
- Extra CMake Modules (ECM) 6.7+

On Arch Linux: `sudo pacman -S cmake extra-cmake-modules qt6-base qt6-declarative qt6-svg kirigami`

## Building

```sh
cmake -B build
cmake --build build
./build/bin/localquens
```
