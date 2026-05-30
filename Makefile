# See https://github.com/bxparks/EpoxyDuino for documentation about this
# Makefile to compile and run Arduino programs natively on Linux or MacOS.

APP_NAME := tests

ARDUINO_LIBS := libraries/AUnit libraries/eva-core-sk src

include build-tests/EpoxyDuino.mk

doc:
	python -m mkdocs build
