#!/bin/sh
ifconfig -a | egrep -io "([0-9a-f]{2}:){5}[0-9a-f]{2}"
