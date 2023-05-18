# guide: https://api.riot-os.org/group__pkg__semtech-loramac.html

# name of your application
APPLICATION = lorawan

# Use the ST B-L072Z-LRWAN1 board by default:
BOARD ?= b-l072z-lrwan1

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

USEMODULE += sx1276  # for a SX1276 radio device
USEMODULE += semtech_loramac_rx

USEPKG += semtech-loramac

LORA_REGION = EU868

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include
