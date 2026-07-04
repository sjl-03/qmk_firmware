# Pro Micro RP2040 instead of the stock ATmega32u4 Pro Micro
CONVERT_TO = promicro_rp2040

# Extra source files — keymap.c is picked up automatically, these aren't.
SRC += os.c \
       homerow.c \
       luna.c \
       rgb.c \
       combos.c \
       keyboard.c

# --- Features ---------------------------------------------------------
OLED_ENABLE          = yes
WPM_ENABLE            = yes
RGBLIGHT_ENABLE       = yes    # whole-board underglow; see rgb.c for the
                                # per-layer colours. If your existing LED
                                # code drives per-key RGB Matrix instead,
                                # switch this to RGB_MATRIX_ENABLE = yes
                                # and update rgb.c to match.
CAPS_WORD_ENABLE      = yes
COMBO_ENABLE          = yes
REPEAT_KEY_ENABLE     = yes
KEY_OVERRIDE_ENABLE   = yes
DYNAMIC_MACRO_ENABLE  = yes
NKRO_ENABLE           = yes
EXTRAKEY_ENABLE       = yes    # needed for KC_MPLY / KC_VOLU / etc.
BOOTMAGIC_ENABLE      = lite   # hold top-left key while plugging in to
                                # reset EEPROM if you ever get stuck

MOUSEKEY_ENABLE       = no
AUDIO_ENABLE          = no
