#ifndef RED_H
#define RED_H
#include "SDL_net.h"
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
#include "Constants.h"
#include "Pala.h"

class Red
{
    public:
        Red();
        virtual ~Red();

        int inicia();
        int iniciaServidor(int port);

        int esperaClientes(int nclientes, int numeroPlayers, int playerNumInicial);
        int iniciaCliente(std::string host, int port);

        int clienteRecibeNumeros(int *numeroJugadores, int *jugador);
        int clienteRecibeDatos(char* msg);
        int clienteEnviaDireccion(int cliente, int direccion);

        int servidorEnviaNumeros(TCPsocket * cliente, int numeroJugadores, int numeroCliente);
        int servidorEnviaDatosATodos(char* msg);
        int servidorRecibeDatos(std::vector<Pala*> palas, float deltaTime);

    protected:
        char buffer[MAX_BUFFER];
        TCPsocket tcpsock;
        int connectedClients;
        TCPsocket clientes[MAX_PLAYERS];

        int envia(TCPsocket* cliente, char* msg);
        int recibe(TCPsocket* cliente, char * msg);
    private:
};

#endif // RED_H
