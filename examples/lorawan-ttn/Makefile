# name of your application
APPLICATION = lorawan-ttn

# If no BOARD is found in the environment, use this default:
BOARD ?= b-l072z-lrwan1

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Default region is Europe and default band is 868MHz
LORA_REGION ?= EU868

ACTIVATION_MODE ?= otaa
DEVEUI ?= 70B3D57ED005D1E7
APPEUI ?= 0000000000000000
APPKEY ?= 272E779C396D1E51E94B9BDD39558EB0

# Include the Semtech-loramac package
USEPKG += semtech-loramac
USEMODULE += xtimer
USEMODULE += sx1276  # for a SX1262 radio device

include $(RIOTBASE)/Makefile.include
