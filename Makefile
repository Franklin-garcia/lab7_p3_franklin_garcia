#esta regla compila el programa principal
main:  Main.cpp Usuario.cpp Cliente.cpp Administrador.cpp Personal.cpp Chef.cpp Lavaplatos.cpp Mesero.cpp
	g++ -o main Main.cpp Usuario.cpp Cliente.cpp Administrador.cpp Personal.cpp Chef.cpp Lavaplatos.cpp Mesero.cpp
