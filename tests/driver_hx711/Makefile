include ../Makefile.tests_common

BOARD ?= native

USEMODULE += xtimer

USEMODULE += hx711
CFLAGS += "-DHX711_PARAM_SCK=GPIO_PIN(0, 2)"
CFLAGS += "-DHX711_PARAM_DOUT=GPIO_PIN(0, 1)"

include $(RIOTBASE)/Makefile.include
