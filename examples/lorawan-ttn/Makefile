# name of your application
APPLICATION = lorawan-ttn

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Default radio driver is Semtech SX1276 (used by the B-L072Z-LRWAN1 board)
DRIVER ?= sx1276

# Default region is Europe and default band is 868MHz
LORA_REGION ?= EU868

ACTIVATION_MODE ?= otaa
DEVEUI ?= 70B3D57ED005D1E7
APPEUI ?= 0000000000000000
APPKEY ?= 272E779C396D1E51E94B9BDD39558EB0

# OTAA compile time configuration keys
CFLAGS += -DCONFIG_LORAMAC_APP_KEY_DEFAULT=\"$(APPKEY)\"
CFLAGS += -DCONFIG_LORAMAC_APP_EUI_DEFAULT=\"$(APPEUI)\"
CFLAGS += -DCONFIG_LORAMAC_DEV_EUI_DEFAULT=\"$(DEVEUI)\"

# Include the Semtech-loramac package
USEPKG += semtech-loramac
USEMODULE += auto_init_loramac
USEMODULE += xtimer

USEMODULE += $(DRIVER)
USEMODULE += fmt

include $(RIOTBASE)/Makefile.include
