#include "socketcliente.h"

SocketCliente::SocketCliente()
{
}

SocketCliente* SocketCliente::socketPtr = nullptr;
SocketCliente* SocketCliente::getInstance(){
    if(!socketPtr) socketPtr = new SocketCliente();
    return socketPtr;
}

bool SocketCliente::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("192.168.0.15"); // To know this Ip in console: hostname -I | awk '{print $1}'
    info.sin_port = ntohs(9050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
     return false;

    pthread_t hilo;
    pthread_create(&hilo,0,SocketCliente::controlador,(void *)this);
    pthread_detach(hilo);
    return true;
}


void * SocketCliente::controlador(void *obj)
{
    SocketCliente *padre = (SocketCliente*)obj;
    char *buffer = (char*)calloc(1024,sizeof(char));
    while (true) {
        string mensaje;
        while (1) {
            int bytes = recv(padre->descriptor,buffer,1024,0);
            mensaje.append(buffer,bytes);
            if(bytes < 1024)
                break;
        }
        if(mensaje != ""){
            cout << "BUFFER: " + mensaje <<endl;
            emit padre->NewMensaje(QString::fromStdString(mensaje));
            memset(buffer,0,sizeof(buffer));
        }
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}


void SocketCliente::sendMessage(const char *msn)
{
   // char *mensaje = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: keep-alive\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.94 Safari/537.36\r\nX-Client-Data: CIm2yQEIorbJAQiptskBCLiIygEI3pbKAQ==\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: es-419,es;q=0.8,en;q=0.6\r\n\n";

    cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;
}
