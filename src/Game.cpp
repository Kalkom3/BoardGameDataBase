#include "Game.h"
int Game::g_nr=0;
Game::Game(QString _name,int _complexity,int _randomness,int _interaction, int _time, int _minPlayers, int _maxPlayers)
{
    nr=g_nr;
    g_nr++;
    name=_name;
    maxPlayers=_maxPlayers;
    minPlayers=_minPlayers;

    paramChanged=false;

    QFont font;
    font.setBold(1);

    QString fname = __FILE__;
    fname.chop(12);
    pos[0]=((nr%5)*220);
    pos[1]=((nr/5)*410);

    QString buttonTxt = QString("%1").arg(nr+1);
    activateButton=new QPushButton(buttonTxt);
    activateButton->setGeometry(QRect(pos[0],pos[1],20,20));
    activateButton->setFixedSize(20,20);


    properties.push_back(_complexity);
    properties.push_back(_randomness);
    properties.push_back(_interaction);
    properties.push_back(_time);

    labels[0]->setPlainText("Complexity:");
    labels[1]->setPlainText("Randomness:");
    labels[2]->setPlainText("Interaction:");
    labels[3]->setPlainText(name);
    labels[0]->setPos(pos[0],pos[1]+205);
    labels[1]->setPos(pos[0],pos[1]+260);
    labels[2]->setPos(pos[0],pos[1]+315);
    labels[3]->setPos(pos[0]+25,pos[1]-10);

    labels[0]->setScale(1.2);
    labels[1]->setScale(1.2);
    labels[2]->setScale(1.2);
    labels[3]->setScale(1.4);

    labels[0]->setFont(font);
    labels[1]->setFont(font);
    labels[2]->setFont(font);
    labels[3]->setFont(font);

    image[0]= new QImage(fname+"resources/"+name+".jpg");
    if(image[0]->isNull())
    {
        image[0]= new QImage(fname+"resources/noIMG.png");
    }
    image[1]= new QImage(fname+"resources/stars("+(char)(properties[0]+48)+").png");
    image[2]= new QImage(fname+"resources/stars("+(char)(properties[1]+48)+").png");
    image[3]= new QImage(fname+"resources/stars("+(char)(properties[2]+48)+").png");

    gitem.push_back(new QGraphicsPixmapItem(QPixmap::fromImage(image[0]->scaled(190,190,Qt::KeepAspectRatio))));
    gitem.push_back(new QGraphicsPixmapItem(QPixmap::fromImage(image[1]->scaled(190,50,Qt::KeepAspectRatio))));
    gitem.push_back(new QGraphicsPixmapItem(QPixmap::fromImage(image[2]->scaled(190,50,Qt::KeepAspectRatio))));
    gitem.push_back(new QGraphicsPixmapItem(QPixmap::fromImage(image[3]->scaled(190,50,Qt::KeepAspectRatio))));

    gitem.push_back(labels[0]);
    gitem.push_back(labels[1]);
    gitem.push_back(labels[2]);
    gitem.push_back(labels[3]);

    gitem[0]->setPos(pos[0],pos[1]+20);
    gitem[1]->setPos(pos[0],pos[1]+225);
    gitem[2]->setPos(pos[0],pos[1]+280);
    gitem[3]->setPos(pos[0],pos[1]+335);
}


void Game::openGameView(bool isModal)
{
    std::vector<QImage>images;
    for(int i=0;i<4;i++)
    {
        images.push_back(*image[i]);
    }
    bool tempParamChanged;
    gameWindow = new GameView(gitem,properties,&tempParamChanged);
    gameWindow->exec();
    if(tempParamChanged==true)
    {
        qDebug()<<properties[0];
        qDebug()<<properties[1];
        qDebug()<<properties[2];
        checkParams();
    }

}

void Game::checkParams()
{
    QString fname = __FILE__;
    fname.chop(12);
    for(int i=0;i<3;i++)
    {
        QImage* newImg = new QImage(fname+"resources/stars("+(char)(properties[i]+48)+").png");
        delete gitem[i+1];
        gitem[i+1]=new QGraphicsPixmapItem(QPixmap::fromImage(newImg->scaled(190,50,Qt::KeepAspectRatio)));
        gitem[i+1]->setPos(pos[0],pos[1]+220+(i*55));

    }
    paramChanged=true;
}

void Game::setNewPos(int nr)
{
    pos[0]=((nr%5)*225);
    pos[1]=((nr/5)*410);

    activateButton->setGeometry(QRect(pos[0],pos[1],20,20));
    labels[0]->setPos(pos[0],pos[1]+205);
    labels[1]->setPos(pos[0],pos[1]+260);
    labels[2]->setPos(pos[0],pos[1]+315);
    labels[3]->setPos(pos[0]+25,pos[1]-10);

    gitem[0]->setPos(pos[0],pos[1]+20);
    gitem[1]->setPos(pos[0],pos[1]+225);
    gitem[2]->setPos(pos[0],pos[1]+280);
    gitem[3]->setPos(pos[0],pos[1]+335);
}

Game::~Game()
{

}
