#include "ScrabbleWindow.h"
#include "ui_ScrabbleWindow.h"
#include <iostream>
#include <fstream>

ScrabbleWindow::ScrabbleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScrabbleWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(QCoreApplication::applicationDirPath() + "/images/board/boardWallpaperButtons.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->scrabbleButton->setFlat(true);
    ui->passButton->setFlat(true);
    player = new Player();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,580,510);
    scene->setBackgroundBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
    ui->scoresFrame->setStyleSheet(" .QFrame { background-color: darkgreen }");
    QGraphicsView* view = new QGraphicsView(scene);
    view->setInteractive(true);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    QVBoxLayout* verticalLayout = new QVBoxLayout(ui->boardFrame);
    verticalLayout->addWidget(view);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    createBoardFrame(view);
    //createPlayerDeck("a,b,a,c,o,ll,s");
}

void ScrabbleWindow::createBoardFrame(QGraphicsView* view){

    int rectangleSize = 34;
    QRectF rect(0,0,rectangleSize,rectangleSize);
    QBrush myBrush;
    int xPos = 0;
    int yPos = 0;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            QGraphicsRectItem *rItem = new QGraphicsRectItem(rect);
            scene->addItem(rItem);
            rItem->setPos(xPos,yPos);
            string multiplier = getMultiplierFromCSV(i, j);
            QString imagePath = QCoreApplication::applicationDirPath() + QString::fromStdString("/images/board/"+multiplier+".png");
            myBrush.setTextureImage(QImage(imagePath));
            rItem->setBrush(myBrush);
            xPos += rectangleSize;
        }
        xPos = 0;
        yPos += rectangleSize;
    }
}


void ScrabbleWindow::createPlayerDeck(string letters){
    player->addLettersToPlayerDeck(letters);
    vector<string> playerDeck = player->getPlayerDeck();
    int rectangleSize = 34;
    QRectF rect(0,0,rectangleSize,rectangleSize);
    DraggableTile *dItem;
    int yPos = 140;
    QBrush q;
    for(int j = 0; j < playerDeck.size(); j++){
        string letter = playerDeck[j];
        dItem = new DraggableTile;
        scene->addItem(dItem);
        dItem->setRect(rect);
        dItem->setPos(540,yPos);
        QString imagePath = QCoreApplication::applicationDirPath() + QString::fromStdString("/images/tiles/"+letter+".png");
        q.setTextureImage(QImage(imagePath));
        dItem->setBrush(q);
        dItem->setAnchorPoint(dItem->pos());
        dItem->setLetter(letter);
        player->addWidgetToDeck(dItem);
        yPos += 38;
    }
}

void ScrabbleWindow::on_scrabbleButton_clicked(){
    Board *board = player->getBoard();
    vector<vector<int>> tilePositions = board->getWordPositions();
    string word = board->getWord();
    vector<string> wordVector;
    if(word.size() == 0) return;
    word = word.substr(0, word.length()-1);
    boost::split(wordVector, word, boost::is_any_of(","));
    int firstCol = tilePositions[0][1];
    int lastCol = tilePositions[tilePositions.size()-1][1];
    bool isVertical = firstCol == lastCol;
    wordVector = this->sortPositions(wordVector, isVertical);
    tilePositions = board->getWordPositions();
    word = "";
    for(int i = 0; i < wordVector.size(); i++){
        word += wordVector[i] + ",";
    }
    string json = player->sendMyWord(word.substr(0, word.size()-1), tilePositions[0][0], tilePositions[0][1], isVertical);


//    QTextStream out(stdout);
//    for(int i = 0; i < wordVector.size(); i++){
//        out << QString::fromStdString(wordVector[i] + "\n");
//        out << QString::fromStdString(to_string(tilePositions[i][0]) + "\n");
//        out << QString::fromStdString(to_string(tilePositions[i][1]) + "\n\n");
//    }
//    resetPlay();
//    createPlayerDeck("a,b,a,c,o,ll,s");
}

void ScrabbleWindow::resetPlay(){
    Board *board = player->getBoard();
    vector<DraggableTile*> tiles = player->getWidgetsPlayerDeck();
    vector<vector<int>> tilePositions = board->getWordPositions();
    vector<int> actualPosition;
    //tiles[0]->printGameBoard(board);
    for(int i = 0; i < tiles.size(); i++){
        if(i<tilePositions.size()){
            actualPosition = tilePositions[i];
            player->getBoard()->gameBoard[actualPosition[0]][actualPosition[1]] = "";
        }
        scene->removeItem(tiles[i]);
        delete tiles[i];
    }
    //tiles[0]->printGameBoard(board);
    board->resetWordVector();
    player->resetWidgetsDeck();
    player->resetPlayerDeck();
}

void ScrabbleWindow::placeWordInBoard(string word, vector<vector<int>> wordPositions){
    vector<string> wordVector;
    DraggableTile *dItem;
    Board *board = player->getBoard();
    int rectangleSize = 34;
    QRectF rect(0,0,rectangleSize,rectangleSize);
    QBrush q;
    boost::split(wordVector, word, boost::is_any_of(","));
    for(int j = 0; j < wordPositions.size(); j++){
        string letter = wordVector[j];
        dItem = new DraggableTile;
        scene->addItem(dItem);
        dItem->setRect(rect);
        dItem->setPos(wordPositions[j][1]*34,wordPositions[j][0]*34);
        QString imagePath = QCoreApplication::applicationDirPath() + QString::fromStdString("/images/tiles/"+letter+".png");
        q.setTextureImage(QImage(imagePath));
        dItem->setBrush(q);
        dItem->setAnchorPoint(dItem->pos());
        dItem->setUndraggable();
        board->gameBoard[wordPositions[j][0]][wordPositions[j][1]] = letter;
    }
}

string ScrabbleWindow::getMultiplierFromCSV(int rowPos, int columnPos) {
    string line;
    vector<string> row;
    ifstream multiplierFile = ifstream(QCoreApplication::applicationDirPath().toStdString() + "/gui/multiplierFile.csv");
    if (multiplierFile.is_open()) {
        for(int i = 0; i < rowPos+1; i++)
            getline(multiplierFile, line);
        boost::split(row, line, boost::is_any_of(","));
        return row[columnPos];
        multiplierFile.close();
    } else cout << "File could not be opened.";
    return 0;
}

void ScrabbleWindow::receiveMessage(QString msg){
    QTextStream out(stdout);
    foreach(QString x, msg){
        out << x;
    }
}

ScrabbleWindow::~ScrabbleWindow(){
    delete ui;
}

void ScrabbleWindow::setConexion(SocketCliente *conexion){
    this->conexion = conexion;
    connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(receiveMessage(QString)));
}

SocketCliente* ScrabbleWindow::getConexion(){
    return conexion;
}

vector<string> ScrabbleWindow::sortPositions(vector<string> wordVector, bool isVertical){
    Board *board = player->getBoard();
    vector<vector<int>> tilePositions = board->getWordPositions();
    int position = (isVertical) ? 0:1;
    for(int i = 0; i < wordVector.size()-1; i++){
        for(int j = i+1; j < wordVector.size(); j++){
            if(tilePositions[j][position] < tilePositions[i][position]){
                vector<int> temp = tilePositions[i];
                tilePositions[i] = tilePositions[j];
                tilePositions[j] = temp;
                string tempLetter = wordVector[i];
                wordVector[i] = wordVector[j];
                wordVector[j] = tempLetter;
            }
        }
    }
    board->setWordPositions(tilePositions);
    return wordVector;
}
