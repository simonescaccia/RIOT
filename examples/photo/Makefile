# name of your application
APPLICATION = photo

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

USEMODULE += analog_util
USEMODULE += xtimer
USEMODULE += periph_gpio

FEATURES_REQUIRED += periph_adc

include $(RIOTBASE)/Makefile.include
