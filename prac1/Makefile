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
MONT = monticulo
ARBOL = arbol
EJEC = huf


all: ${MONT} ${ARBOL} ${EJEC} #lo que se generará al ejecutar "make"
#---------------------------------------------------------
# "linkar" y generar ejecutable. Indicamos que "main_p2_e1" requiere "main_p2_e1.o"
${MONT}: ${MONT}.o
	${CC} ${CPPFLAGS} ${MONT}.cpp -c -o ${MONT}.o

${ARBOL}: ${ARBOL}.o
	${CC} ${CPPFLAGS} ${ARBOL}.cpp -c -o ${ARBOL}.o

${EJEC}: ${EJEC}.o
	${CC}  ${CPPFLAGS} ${EJEC}.cpp ${MONT}.o ${ARBOL}.o -o ${EJEC}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${EJEC}.o ${EJEC}
	$(RM) ${ARBOL}.o ${ARBOL}
	$(RM) ${MONT}.o ${MONT}
