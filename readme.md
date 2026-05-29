# Quantum Mechanical Keyboard Firmware
[Original Website](https://github.com/sjl-03/qmk_firmware)

To compile pro_micro_keymap

```
qmk compile -kb crkbd/rev1 -km pro_micro_keymap
```

Add and compile qmk keymap
```
qmk new-keymap -kb sofle/rev1 -km promicro_rp2040
```
```
Ψ Generating a new keymap


Configure Development Board
For more information, see:
https://docs.qmk.fm/feature_converters

Use converter?
	1. No (default)
	2. bit_c_pro
	3. blok
	4. bonsai_c3
	5. bonsai_c4
	6. elite_pi
	7. helios
	8. imera
	9. kb2040
	10. liatris
	11. michi
	12. promicro_rp2040
	13. proton_c
	14. rp2040_ce
	15. sparkfun_pm2040
	16. stemcell
	17. svlinky
Please enter your choice: [1] 12
Ψ Created a new keymap called promicro_rp2040 in: /Users/shenjunlu/qmk_firmware/keyboards/sofle/keymaps/promicro_rp2040.
Ψ Compile a firmware with your new keymap by typing: qmk compile -kb sofle/rev1 -km promicro_rp2040.
```

```
qmk compile -kb sofle/rev1 -km promicro_rp2040
```
