#*****************************************************************
# File:   Makefile
# Author: PSCD-Unizar
# Date:   octubre 2017
# Coms:   Ejemplo de Makefile
#         Ejecutar 'make' para compilar (o 'make -f Makefile')
#         Ejecutar 'make' clean para limpiar (borrar lo que genere)
#         Suponemos que 'main_p2_e1.cpp' contiene un '#include "otroFuente.hpp"' cuya
#         implementación está en 'otroFuente.cpp'.
#         El objetivo es generar el ejecutable 'main_p2_e1'
#*****************************************************************

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # para limpiar
CC = g++         # para compilar
#---------------------------------------------------------
# para compilación y enlazado ("linkado")
CPPFLAGS=-I. -O2 -std=c++11     # opciones compilación
#---------------------------------------------------------
# vars
EJEC = prueba

all: ${EJEC} #lo que se generará al ejecutar "make"
#---------------------------------------------------------
# "linkar" y generar ejecutable. Indicamos que "main_p2_e1" requiere "main_p2_e1.o"
${EJEC}: ${EJEC}.o 
	${CC} ${EJEC}.o -o ${EJEC} ${CPPFLAGS}

#---------------------------------------------------------
# compilar: generará "main_p2_e1.o". Indicamos que depende de "main_p2_e1.cpp"
${EJEC}.o: ${EJEC}.cpp
	${CC} -c ${EJEC}.cpp


#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${EJEC}.o ${EJEC} 
