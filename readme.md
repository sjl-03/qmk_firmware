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

| Parts  | Image  | Link for Reference  |
|---|---|---|
| 42x Kailh Choc V1 or MX Hot Swap Sockets  | <img width="119" height="129" alt="image" src="https://github.com/user-attachments/assets/be1bc41a-356d-4961-a3fa-31b406fa8c73" />  |   |
| 42x 1N4148 SOD-123 Diodes  | <img width="125" height="119" alt="image" src="https://github.com/user-attachments/assets/7a6490d5-97ff-4be8-81c7-6baf3d3bb271" />  |   |
| 4x Mill-Max Machined 12 Pin Sockets (More needed if have LED)  | <img width="125" height="109" alt="image" src="https://github.com/user-attachments/assets/25536af4-cd70-47d1-8b47-ff3f81855723" />  |   |
| 12x 4 Pin RGB Male needle   | <img width="117" height="119" alt="image" src="https://github.com/user-attachments/assets/fc47a5b8-2eba-4c59-bf39-2bd8ddec39ad" />  | https://www.aliexpress.com/item/1005004194804142.html?spm=a2g0o.order_list.order_list_main.41.1cb21802MQdPLC  |
| 2x Microcontrollers (Pro Micro, Elite-C or Similar for wired, OR Nice!Nano V2 or similar for wireless)  | <img width="112" height="123" alt="image" src="https://github.com/user-attachments/assets/9203f79b-e1e7-44f4-ab37-6dd5838b456e" />  |   |
| 42x MX or Choc V1 Switches  | <img width="130" height="121" alt="image" src="https://github.com/user-attachments/assets/b2c491a1-a051-449b-b785-cb3d305a012b" /> (Choc) <img width="242" height="125" alt="image" src="https://github.com/user-attachments/assets/5698c51e-9d89-49c0-8dff-d3640548befb" /> (MX) |   |
| 42x MX or Choc V1 Keycaps  |   |   |
| 2x TRRS 3.5mm PJ-320A Audio Jack (Wired)  | <img width="328" height="322" alt="image" src="https://github.com/user-attachments/assets/3ed6d4ed-25f9-40ed-88c9-bf8155935b81" />  | https://www.aliexpress.com/item/1005003111662179.html?spm=a2g0o.productlist.main.2.2ceac8uMc8uMBN&algo_pvid=e0d2b629-f064-4c36-83d6-68df71704824&algo_exp_id=e0d2b629-f064-4c36-83d6-68df71704824-1&pdp_ext_f=%7B%22order%22%3A%22963%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21GBP%210.77%210.77%21%21%216.78%216.78%21%40211b430817811231465587856e0caf%2112000046559590833%21sea%21UK%212695018311%21X%211%210%21n_tag%3A-29919%3Bd%3A247dfc80%3Bm03_new_user%3A-29895&curPageLogUid=Le0Kvc2pYtGU&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005003111662179%7C_p_origin_prod%3A  |
| 1x TRRS Male to Male Cable (Wired)  | <img width="125" height="122" alt="image" src="https://github.com/user-attachments/assets/11f82715-990c-40d0-a06b-410ebbba3062" />  |   |
| 2x Battery (Wireless)  | <img width="130" height="109" alt="image" src="https://github.com/user-attachments/assets/66282967-73eb-43c8-b62e-6209407b6f06" />  |   |
| 2x Right Angle PH2 Battery Connector (Wireless)  | <img width="122" height="120" alt="image" src="https://github.com/user-attachments/assets/33eaf99e-f814-4fc8-af7d-2c4ff6230b54" />  |   |
| 2x 3 Pin Toggle Switch (MSK-12C02 or PCM12SMTR) (Wireless)  | <img width="123" height="111" alt="image" src="https://github.com/user-attachments/assets/2c43a7e4-d343-4b51-add5-68bbf7e95853" />  |   |
| 2x Tactile Push Button Switch (3x6x4.3mm) (Wireless)  | <img width="113" height="117" alt="image" src="https://github.com/user-attachments/assets/e60c2cc1-391f-4a6a-b247-709b2ee6c1e6" />  |   |
| 2x Displays (.91 Inch OLED or Nice!View) (optional)  | <img width="135" height="127" alt="image" src="https://github.com/user-attachments/assets/76ed4e35-5fd5-4e43-be94-9277744ca476" />  | https://www.aliexpress.com/item/1005006365845676.html?spm=a2g0o.order_list.order_list_main.287.1cb21802MQdPLC  |
| 2x Rotary Encoder  | <img width="132" height="103" alt="image" src="https://github.com/user-attachments/assets/58d4f0fa-3877-4537-81ae-96c20e6352fa" />  | https://www.aliexpress.com/item/1005005983134515.html?spm=a2g0o.order_list.order_list_main.297.1cb21802MQdPLC  |
| PCB  |   |   |
| Case  |   |   |

Others
- Standoff
- Screw
