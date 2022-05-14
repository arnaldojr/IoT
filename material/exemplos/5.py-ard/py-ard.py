#!/usr/bin/python3
# -*- coding: utf-8 -*-


# instalar pyserial
# pip intall pyserial

import serial

#
# win NO ARDUINO SIMULADO É COM3 E NO PYTHON É COM4
# linux NO ARDUINO SIMULADO É /dev/tnt0 E NO PYTHON É /dev/tnt1
#

#serialName = "/dev/tnt1"# estou no linux
serialName = "COM14"  ## é a porta onde o arduino esta conectado
baud = 115200

COM = serial.Serial(serialName,baud)
COM.flushInput()        ## limpa o buffer
print("Abrindo Serial")

cont = 0

while cont < 50:
    ##### olá  - 3 caracteres 3char  124 - 3char
    dado = str(COM.readline()) #FAZ A LEITURA
    dado = dado[2:][:-8]
    print(dado)
    cont = cont +1


print("fechando Serial")
COM.close()

