//
// Created by esteban on 28/03/19.
//

#include "server_Socket.hpp"

/* ------------------------------------
*
*        SOCKET PRIVATE METHODS
*
* -----------------------------------*/

bool server_Socket::createSocket() {

    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(descriptor < 0){
        return false;
    }

    socketInfo.sin_family = AF_INET;

    //Allows that any computer that knows the server ip connects to it
    string ip_address;
    string configPath = "../TextFiles/config.properties";
    ifstream config_file(configPath);
    vector<string> info;
    string line;
    if (config_file.is_open()){
        getline(config_file,line);
        info.clear();
        boost::split(info,line,boost::is_any_of("="));
        ip_address=info[1];
        config_file.close();// Closes file.
    } else cout << "Properties file not opened.";

    socketInfo.sin_addr.s_addr = inet_addr(ip_address.c_str()); // To know this Ip in console: hostname -I | awk '{print $1}'

    //Indicates the server socket port. The htons only allows "small" socket ports. htonl for "big" socket port.
    socketInfo.sin_port = htons(this->port);

    //Optional: clean the structure before connecting to the clients. IDK why
    memset(&socketInfo.sin_zero,0, sizeof(socketInfo.sin_zero));

    return true;
}

bool server_Socket::connectWithClients() {

    if((bind(descriptor, (sockaddr *)&socketInfo, (socklen_t) sizeof(socketInfo))) <0){
        return false;
    }
    //The 4 is the number of clients that we are going to listenClient from the server
    listen(descriptor,4);
    return true;
}

void server_Socket::sendSingleMessage(const char *msg, int descriptor) {
    send(descriptor, msg, strlen(msg), 0);
}

void server_Socket::listenClient(string* bufferText,dataSocketServer inData) {
    dataSocketServer *data = (dataSocketServer*)&inData;
    while (true) {
        char buffer[300] = {0};
        //Another "blocking function". The while stops until the server receives a new message.
        int bytes = recv(data->descriptor, buffer, 300, 0);
        bufferText->append(buffer, bytes);

        if (bytes <= 0){
            close(data->descriptor);
            pthread_exit(NULL);
        }
        if (bytes < 300) {
            break;
        }
    };
}

void server_Socket::runThreads() {
    for(int i= 0; i< cThreads.size();i++) {
        thread clientThread(&server_Socket::clientHandler,this,(void*) &cThreads[i]);  // Crea el Thread
        clientThread.detach(); // Pone a correr el Thread de manera independiente (Daemon)
    }
    cout<<"Todos los clientes listos!"<<endl;
}

void* server_Socket::clientHandler(void *object) {
    dataSocketServer *data = (dataSocketServer*)object;
    while(true){
        string rec_msg;
        listenClient(&rec_msg,*data);
        msgHandler(rec_msg.c_str());
    }
}

/* ------------------------------------
*
*        SOCKET PUBLIC METHODS
*
* -----------------------------------*/

server_Socket::server_Socket() {}

bool server_Socket::initSocket(int port) {
    this->port = port;
    if(!createSocket()){
        cout<<"Error al crear el socket"<<endl;
        throw string("Error al crear el socket");
    }
    if (!connectWithClients()){
        cout<<"Error al conectar con el kernel"<<endl;
        throw string("Error al conectar con el kernel");
    }

    return true;
}

void server_Socket::addFirstClient() {
    cout<<"Esperando Cliente!"<<endl;
    dataSocketServer data;
    socklen_t structureSize = sizeof(data.socketInfo);

    //A "blocking function" is declared. The while stops until the server receives a new client.
    data.descriptor = accept(descriptor,(sockaddr *)&data.socketInfo,&structureSize);

    if(data.descriptor < 0){
        cout<<"Error al aceptar al cliente"<<endl;
    }else {
        string p_Num;
        listenClient(&p_Num,data);
        setMaxCap(p_Num);
        clients.push_back(data.descriptor);
        cThreads.push_back(data);
        //sendSingleMessage("Game Created succesfully",data.descriptor);
        p_Num = "Game Code is:"+code;
        //sendSingleMessage(p_Num.c_str(),data.descriptor);
        cout<<"Cantidad maxima de clientes:"<<max_cap<<endl;
        cout<<"Clientes conectados: "<<clients.size()<<endl;
    }
}

void server_Socket::addClients() {
    cout<<"Esperando Cliente!"<<endl;
    dataSocketServer data;
    socklen_t structureSize = sizeof(data.socketInfo);

    //A "blocking function" is declared. The while stops until the server receives a new client.
    data.descriptor = accept(descriptor,(sockaddr *)&data.socketInfo,&structureSize);

    if(data.descriptor < 0){
        cout<<"Error al aceptar al cliente"<<endl;
    }else {
        string recv_code;
        listenClient(&recv_code,data);
        if (recv_code == code) {
            clients.push_back(data.descriptor);
            cThreads.push_back(data);

            //sendSingleMessage("Join to Game succesfully",data.descriptor);
            cout<<"Clientes conectados: "<<clients.size()<<endl;
        } else {
            sendSingleMessage("Wrong recv_code!",data.descriptor);
        }
    }
}

void server_Socket::runServer() {
    runThreads();
}

void server_Socket::sendMessagetoAll(string msg) {
    for (int i = 0; i < clients.size(); i++) {

        //cout << "bytes enviados " <<
        sendSingleMessage(msg.c_str(),clients[i]);
    }
}


void server_Socket::setMaxCap(string info) {
    this->max_cap = stoi(info);
}


void server_Socket::msgHandler(const char *msg) {
    cout<<">> "<<msg<<endl;
}


