
# pvinis unicorne


## Compile

> Note: make sure to run `qmk setup` before compiling. It will clone qmk_firmware.

```sh
qmk compile -kb boardsource/unicorne -km pvinis
```

## Flash

```sh
qmk flash -kb boardsource/unicorne -km pvinis
```

Then to enter the bootloader, do one of the following:
- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (top left key for left side, top right key for right side) and plug in the keyboard.
- **Physical reset button**: Press and hold the right physical button, then press and release the left physical button, then release the right physical button. Same thing for both sides.
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.




