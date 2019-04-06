#include "ScrabbleWindow.h"
#include "ui_ScrabbleWindow.h"
#include <iostream>
#include <fstream>

ScrabbleWindow::ScrabbleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScrabbleWindow)
{
    ui->setupUi(this);
    player = new Player();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-94,-84,775,675);
    QGraphicsView* view = new QGraphicsView(scene);
    QVBoxLayout* verticalLayout = new QVBoxLayout(ui->boardFrame);
    verticalLayout->addWidget(view);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    createBoardFrame(view);
    createPlayerDeck("a,b,a,c,o,ll,s");
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
    vector<string> wordVector;
    string word = board->getWord();
    if(word.size() == 0) return;
    word = word.substr(0, word.length()-1);
    boost::split(wordVector, word, boost::is_any_of(","));
    for(int i = 0; i < wordVector.size(); i++){
        vector<int> position = tilePositions[i];
//        cout <<"{" << wordVector[i] ;
//        cout << ", [" << position[0];
//        cout << ", " << position[1] << "]}" << endl;
    }

    resetPlay();
    createPlayerDeck("a,b,a,c,o,ll,s");
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

ScrabbleWindow::~ScrabbleWindow(){
    delete ui;
}
