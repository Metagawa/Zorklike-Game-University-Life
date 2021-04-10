//preprocessor
#include "uniZork.h"
#include "character.h"
#include "event.h"
#include "eventlist.h"
#include "ramble.h"
#include "ramblelist.h"
#include "ui_uniZork.h"
#include <QDesktopWidget>
#include <QMovie>
#include <QScrollBar>
#include <QSound>
#include <QStringList>
#include <QStyle>
#include <QTabBar>
#include <QTabWidget>
#include <Qt>
#include <QtCore>
#include <iostream>
//preprocessor macros
#define playSound(a) (a.stop(), a.play())
//namespace definition
using namespace std;
//globals
bool interactEnabled = false;
bool examineClicked = false;
// example of reference
bool &examine = examineClicked;
bool mapIsHidden = true;
//Sound definitions
QSound scratchSfx(":/sfx/scratch.wav");
QSound crumpleSfx(":/sfx/crumple.wav");
QSound penSfx(":/sfx/pen.wav");
QSound clickSfx(":/sfx/click.wav");

Zork::Zork(QWidget *parent) : QMainWindow(parent), ui(new Ui::Zork)
{
  //font definitions
  QFontDatabase::addApplicationFont(":/barbies-jalous-sisters.handwriting.ttf");
  QFontDatabase::addApplicationFont("  :/fonts/Graduate-Regular.ttf");
  //example of a union
  union
  {
    //storage of character names (occupies same memory)
    char *timsname;
    char *charactername;
  };
  //name declaration and creation of character, prints names to character
  string name = "Tim";
  timsname = (char *)name.c_str();
  tim = new Character(timsname);
  charname = new Character(charactername);
  cout << "Character name set to " << charactername << endl;
  Person *timAsAPerson = dynamic_cast<Person *>(tim);
  timAsAPerson->greet();

  //creates new event list and ramble list objects
  eventList = new EventList();
  rambleList = new RambleList();

  //interfaces with ui elements here
  ui->setupUi(this);
  this->setWindowTitle("University Life");
  ui->quitOverlay->hide();
  ui->lasso->hide();
  ui->quitSheet->hide();
  ui->map->hide();
  //updates ui elements to be shown or hidden based on stack index
  updateOnChangeStackPaneIndex();
  //creates room layout
  uniLife = new UniLife();
  //creates new time object, sets time, day and weather
  time = new Times();
  //creates a vector list of days
  textDayList = new vector<string>({"", "", "", "", "", "", ""});
  string welcomeText = "Welcome to University Life!\n\n";
  (*textDayList)[0] = (welcomeText);
  //initializes some ui properties like stack widget index, scrollbar properties and the watch time.
  ui->plainTextEdit->setPlainText(QString::fromStdString((*textDayList)[0]));
  ui->plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->stackedWidget->setCurrentIndex(1);
  updateOnChangeStackPaneIndex();
  ui->lcdNumber->display(QString::fromStdString(time->getTimeString()));
  ui->polaroidLabel->setText(
      QString::fromStdString(uniLife->currentRoom->shortDescription()));
  debug(welcomeText);

  // update disable buttons
  updateDisabledDirections();
}

//simple check to hide uneeded ui elements on certain stack widget panes
void Zork::updateOnChangeStackPaneIndex()
{
  if (ui->stackedWidget->currentIndex() == 0)
  {
    ui->spiral->show();
    ui->watch->show();
    ui->lcdNumber->show();
    ui->mainMenuScreen->hide();
  }
  else if (ui->stackedWidget->currentIndex() == 1)
  {
    ui->mainMenuScreen->show();
    ui->spiral->hide();
    ui->watch->hide();
    ui->lcdNumber->hide();
  }
  else if (ui->stackedWidget->currentIndex() == 2)
  {
    ui->mainMenuScreen->hide();
    ui->spiral->hide();
    ui->watch->hide();
    ui->lcdNumber->hide();
  }
}

//disables directions based on current room exits
void Zork::updateDisabledDirections()
{
  //updates plain text edit properties to prevent the player from highlighting text
  ui->plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

  //enables all room exits
  ui->northButton->setDisabled(false);
  ui->southButton->setDisabled(false);
  ui->eastButton->setDisabled(false);
  ui->westButton->setDisabled(false);

  //disables room exits based on possible current room exits
  if (uniLife->currentRoom->nextRoom("north") == NULL)
  {
    ui->northButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("south") == NULL)
  {
    ui->southButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("east") == NULL)
  {
    ui->eastButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("west") == NULL)
  {
    ui->westButton->setDisabled(true);
  }
}

//function to start a particular event
void Zork::eventStartSpecific()
{
  //runs a debug check to print the current event's text to the terminal
  debugMini(currentEvent->text);
  //checks if the current event has one or two options
  updateNumberOfOptions();
  //changes the current room if the event has a room flag
  updateLocation();
  // sets the event scene stacked widget page
  ui->stackedWidget->setCurrentIndex(2);
  // sets the eventText box equal to the event dialogue.
  QString currentEventText = QString::fromStdString(currentEvent->text);
  ui->eventText->setPlainText(currentEventText);
  updateNotebookDuringEvent(currentEventText);
  // sets options equal to event options
  QString currentEventOption1 =
      QString::fromStdString(currentEvent->leftOptiontext);
  ui->option_1->setText(currentEventOption1);
  QString currentEventOption2 =
      QString::fromStdString(currentEvent->rightOptiontext);
  ui->option_2->setText(currentEventOption2);
  //update second character pixmap based on if the current event has a character flagged
  ui->person_2->setPixmap(
      QPixmap(QString::fromStdString(currentEvent->pixmapCharacterResource)));

  // update background image based on room, time and weather
  bool isRaining = time->isRaining();
  if (time->isDayTime() && !isRaining)
  {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getDayClear())));
  }
  else if (time->isDayTime() && isRaining)
  {
    QMovie *movie =
        new QMovie(QString::fromStdString(uniLife->currentRoom->getDayRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  }
  else if (!time->isDayTime() && !isRaining)
  {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getNightClear())));
  }
  else if (!time->isDayTime() && isRaining)
  {
    QMovie *movie = new QMovie(
        QString::fromStdString(uniLife->currentRoom->getNightRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  }
  // calls updateOnChangeStackPaneIndex so that ui elements are hidden correctly.
  updateOnChangeStackPaneIndex();
}

void Zork::eventStart()
{
  //debug stuff to check if events are set and loaded correctly
  cout << "Attempting to set current event...\n";
  //exception call
  try
  {
    if (eventList->eventNumber > 19)
    {
      cout << "Failed to set an event...\n";
      //throws an exception if we've left the bounds of the event array and returns to the explore scene
      exceptionZork eventException;
      throw eventException;
    }
    else
    {
      //if we're in the bounds of the event array, loads the event.
      currentEvent = eventList->getNextEvent();
      cout << "New current event set!\n";
      //runs a debug check to print the current event's text to the terminal
      debugMini(currentEvent->text);
      //checks if the current event has one or two options
      updateNumberOfOptions();
      //changes the current room if the event has a room flag
      updateLocation();
      // sets the event scene stacked widget page
      ui->stackedWidget->setCurrentIndex(2);
      // sets the eventText box equal to the event dialogue.
      QString currentEventText = QString::fromStdString(currentEvent->text);
      ui->eventText->setPlainText(currentEventText);
      updateNotebookDuringEvent(currentEventText);
      // sets options equal to event options
      QString currentEventOption1 =
          QString::fromStdString(currentEvent->leftOptiontext);
      ui->option_1->setText(currentEventOption1);
      QString currentEventOption2 =
          QString::fromStdString(currentEvent->rightOptiontext);
      ui->option_2->setText(currentEventOption2);
      //update second character pixmap based on if the current event has a character flagged
      ui->person_2->setPixmap(QPixmap(
          QString::fromStdString(currentEvent->pixmapCharacterResource)));
      // update background image based on room, time and weather
      bool isRaining = time->isRaining();
      if (time->isDayTime() && !isRaining)
      {
        ui->imageBackground_2->setPixmap(QPixmap(
            QString::fromStdString(uniLife->currentRoom->getDayClear())));
      }
      else if (time->isDayTime() && isRaining)
      {
        QMovie *movie = new QMovie(
            QString::fromStdString(uniLife->currentRoom->getDayRain()));
        ui->imageBackground_2->setMovie(movie);
        movie->start();
      }
      else if (!time->isDayTime() && !isRaining)
      {
        ui->imageBackground_2->setPixmap(QPixmap(
            QString::fromStdString(uniLife->currentRoom->getNightClear())));
      }
      else if (!time->isDayTime() && isRaining)
      {
        QMovie *movie = new QMovie(
            QString::fromStdString(uniLife->currentRoom->getNightRain()));
        ui->imageBackground_2->setMovie(movie);
        movie->start();
      }
      // calls updateOnChangeStackPaneIndex so that ui elements are hidden correctly.
      updateOnChangeStackPaneIndex();
    }
  }
  //exception catcher
  catch (exception &e)
  {
    cout << "No event left to return! Returning to explore scene...\n";
  }
}

//destructor calls
Zork::~Zork()
{
  delete ui;
  delete uniLife;
  delete textDayList;
  delete time;
  delete rambleList;
}

//updates various sections after moving to a new room.
//updates time, watch face, day, weather, event active chance
// sets a new tab of the notebook on new day and creates a new text box for it
void Zork::updatePositionAfterMoving()
{
  // starts final event if you reach the end of the week without completing all events
  if (time->getDayNum() == 6 && time->getTime() >= 21)
  {
    currentEvent = eventList->createFinalEvent();
    eventStartSpecific();
  }

  //resets examine button click
  examineClicked = false;
  //disables interact button and then re-enables it based on chance to have an event occur
  ui->actButton->setDisabled(true);
  interactChance();
  //updates current widget based on if a new day has started
  ui->tabWidget->setCurrentIndex(time->getDayNum());
  bool itsABrandNewDay = time->advanceTime();
  //if a new day has started, creates a new notebook tab,
  //a new text box for today's notes and sets the correct styling.
  if (itsABrandNewDay)
  {
    auto w = new QWidget;
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setSpacing(0);
    QSpacerItem *item =
        new QSpacerItem(13, 0, QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addSpacerItem(item);
    hlayout->setMargin(0);
    int tabIndex = time->getDayNum();
    QPlainTextEdit *pte = new QPlainTextEdit(this);
    pte->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, "
        "255);background-image:url(:/images/misc/lines.png);padding-left: 10;");
    pte->setFont(QFont("MV Boli", 12));
    pte->setReadOnly(true);
    pte->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pte->setTextInteractionFlags(Qt::NoTextInteraction);
    hlayout->addSpacerItem(item);
    hlayout->addWidget(pte);
    w->setLayout(hlayout);
    ui->tabWidget->insertTab(
        tabIndex, w, QString::fromStdString(time->getDayString(tabIndex)));
    ui->tabWidget->setCurrentIndex(time->getDayNum());
  }
  //updates watch face time
  ui->lcdNumber->display(QString::fromStdString(time->getTimeString()));

  //checks if the initial day is still the current day, if it is,
  //we put our text into the initial text box instead of a generated one
  if (time->getDayNum() == 0)
  {
    QString currentPlainText =
        ui->plainTextEdit->toPlainText() + QString::fromStdString("\n") +
        QString::fromStdString(uniLife->currentRoom->longDescription() + "\n" +
                               eventExistsText);

    ui->plainTextEdit->setPlainText(currentPlainText);
    // Puts the scroll bar to the bottom as setting the text moves it back to the top
    ui->plainTextEdit->moveCursor(QTextCursor::End);
    ui->plainTextEdit->ensureCursorVisible();
  }
  else
  {
    QPlainTextEdit *qpte =
        ui->tabWidget->currentWidget()->findChild<QPlainTextEdit *>();
    QString currentPlainText =
        qpte->toPlainText() + QString::fromStdString("\n") +
        QString::fromStdString(uniLife->currentRoom->longDescription() + "\n" +
                               eventExistsText);
    qpte->setPlainText(currentPlainText);
    // Puts the scroll bar to the bottom as setting the text moves it back to the top
    qpte->moveCursor(QTextCursor::End);
    qpte->ensureCursorVisible();
  }

  // Disables movement buttons based on if movement in that direction is possible or not
  updateDisabledDirections();

  // update image for room based on time, day and weather
  bool isRaining = time->isRaining();
  if (time->isDayTime() && !isRaining)
  {
    ui->imageBackground->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getDayClear())));
  }
  else if (time->isDayTime() && isRaining)
  {
    QMovie *movie =
        new QMovie(QString::fromStdString(uniLife->currentRoom->getDayRain()));
    ui->imageBackground->setMovie(movie);
    movie->start();
  }
  else if (!time->isDayTime() && !isRaining)
  {
    ui->imageBackground->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getNightClear())));
  }
  else if (!time->isDayTime() && isRaining)
  {
    QMovie *movie = new QMovie(
        QString::fromStdString(uniLife->currentRoom->getNightRain()));
    ui->imageBackground->setMovie(movie);
    movie->start();
  }
  //sets polaroid text to the current room name
  ui->polaroidLabel->setText(
      QString::fromStdString(uniLife->currentRoom->shortDescription()));
}

//moves to the room to the north, plays a sound, calls update position
void Zork::on_northButton_clicked()
{
  playSound(scratchSfx);
  Command *command = new Command("go", "north");
  uniLife->processCommand(*command);
  updatePositionAfterMoving();
}
//moves to the room to the east, plays a sound, calls update position
void Zork::on_eastButton_clicked()
{
  playSound(scratchSfx);
  Command *command = new Command("go", "east");
  uniLife->processCommand(*command);
  updatePositionAfterMoving();
}
//moves to the room to the west, plays a sound, calls update position
void Zork::on_westButton_clicked()
{
  playSound(scratchSfx);
  Command *command = new Command("go", "west");
  uniLife->processCommand(*command);
  updatePositionAfterMoving();
}
//moves to the room to the south, plays a sound, calls update position
void Zork::on_southButton_clicked()
{
  playSound(scratchSfx);
  Command *command = new Command("go", "south");
  uniLife->processCommand(*command);
  updatePositionAfterMoving();
}

//Checks if the interact button is currently visible, and if the examine button has been clicked
//if the interact button is disabled, allows the player to examine once for another chance to activate it
void Zork::on_examineButton_clicked()
{
  if (!interactEnabled && !examineClicked)
  {
    //Call the interact chance function to try enable the button
    interactChance();
    //prevents player from spamming examine
    examineClicked = true;
    if (!interactEnabled)
    {
      QString currentEventText =
          "I looked around but didn't see anything interesting...";
      updateNotebookDuringEvent(currentEventText);
      ui->plainTextEdit->moveCursor(QTextCursor::End);
    }
    else
    {
      QString currentEventText =
          "On closer inspection, It looked like something was happening...";
      updateNotebookDuringEvent(currentEventText);
      ui->plainTextEdit->moveCursor(QTextCursor::End);
    }
  }

  //example of Template class
  TemplatePair<bool> boolChecks(interactEnabled, examineClicked);
  //prints the value of interactEnabled and examineClicked to the terminal for debug
  boolChecks.printPair();
  playSound(scratchSfx);
}

//prints some tutorial info to the notebook
void Zork::on_infoButton_clicked()
{
  QString str = "Welcome to University Life! Your name is " +
                QString::fromUtf8(charname->getName().c_str()) +
                ". In University life your goal is to explore the campus, meet "
                "new people and have fun along the way. New events appear "
                "around every corner, so make sure to explore the campus every "
                "day and night during your first week as a college student!";

  //calls notebook text updating function
  updateNotebookDuringEvent(str);

  playSound(scratchSfx);
}

//displays the map in the notebook
//hides ui elements while the map is displayed
void Zork::on_mapButton_clicked()
{

  playSound(scratchSfx);

  if (mapIsHidden)
  {
    ui->lasso->show();
    ui->lasso->setGeometry(uniLife->currentRoom->getLassoX(),
                           uniLife->currentRoom->getLassoY(), 50, 50);
    ui->northButton->setDisabled(true);
    ui->southButton->setDisabled(true);
    ui->eastButton->setDisabled(true);
    ui->westButton->setDisabled(true);
    ui->actButton->setDisabled(true);
    ui->examineButton->setDisabled(true);
    ui->quitButton->setDisabled(true);
    ui->infoButton->setDisabled(true);
    ui->notebookButton->hide();
    ui->map->show();
    ui->plainTextEdit->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, 255);background-image: "
        "url(:/images/misc/lines.png);padding-left: 10; color: "
        "rgba(0,0,0,0)");
    mapIsHidden = false;

    for (int i = 1; i < ui->tabWidget->count(); i++)
    {
      QPlainTextEdit *qpte =
          ui->tabWidget->widget(i)->findChild<QPlainTextEdit *>();
      qpte->setStyleSheet(
          "border: 0;background-color: rgb(255, 255, 255);background-image: "
          "url(:/images/misc/lines.png);padding-left: 10; color: "
          "rgba(0,0,0,0)");
    }
    QString tabStyle =
        "QTabBar::tab{min-width: "
        "0px;max-width: 0px; color: rgba(0,0,0,0);background-color: "
        "rgba(0,0,0,0);border: none;"
        "padding-bottom:14px;}";
    ui->tabWidget->setStyleSheet(tabStyle);
  }
  else
  {
    ui->lasso->hide();
    updateDisabledDirections();
    ui->actButton->setDisabled(false);
    ui->examineButton->setDisabled(false);
    ui->quitButton->setDisabled(false);
    ui->infoButton->setDisabled(false);
    ui->notebookButton->show();

    ui->map->hide();
    mapIsHidden = true;
    ui->plainTextEdit->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, 255);background-image: "
        "url(:/images/misc/lines.png);padding-left: 10; color: ");

    for (int i = 1; i < ui->tabWidget->count(); i++)
    {
      QPlainTextEdit *qpte =
          ui->tabWidget->widget(i)->findChild<QPlainTextEdit *>();
      qpte->setStyleSheet(
          "border: 0;background-color: rgb(255, 255, 255);background-image: "
          "url(:/images/misc/lines.png);padding-left: 10; color: ");
    }
    //reinitializes the tab styling so it can be displayed correctly
    QString tabStyle = "QTabBar::tab{"
                       "background-color:rgb(255, 255, 127);border -"
                       "bottom:1px dotted Grey;"
                       "border-top:1px solid LightGrey;"
                       "border-left:1px solid LightGrey;"
                       "border-right:1px solid LightGrey;"
                       "color:"
                       "rgb(0, 0, 0);"
                       "margin-right:2px;"
                       "padding-top:5px;"
                       "padding-bottom:5px;"
                       "padding-right:10px;"
                       " padding-left:10px;"
                       "}"

                       "QTabBar::tab:enabled{"
                       "background-color:rgb(255, 255, 127);"
                       "border-bottom:1px dotted Grey;"
                       "border-top:1px solid LightGrey;"
                       "border-left:1px solid LightGrey;"
                       "border-right:1px solid LightGrey;"
                       "color:"
                       "rgb(0, 0, 0);"
                       "margin-right:2px;"
                       "padding-top:5px;"
                       "padding-bottom:5px;"
                       "padding-right:10px;"
                       "padding-left:10px;"
                       "}"
                       "QTabBar::tab:selected{"
                       "background-color:rgb(100, 255, 100);"
                       "padding-bottom:8px;"
                       "border-bottom:none;"

                       "}";
    ui->tabWidget->setStyleSheet(tabStyle);
  }
}
//begins a new event in sequence, increments the event array number
void Zork::on_actButton_clicked()
{
  //basic check to see if we've reached the final event, begins the final event if we have
  if (eventList->eventNumber > 19)
  {
    currentEvent = eventList->createNoEvent();
    eventStartSpecific();
  }
  playSound(scratchSfx);
  //starts the event at current arrayEvents[eventNumber] index
  eventStart();
  eventList->eventNumber++;
}

//starts a new game
void Zork::on_goToExplore_clicked()
{
  playSound(clickSfx);
  ui->stackedWidget->setCurrentIndex(0);
  updatePositionAfterMoving();
  updateOnChangeStackPaneIndex();
  // starts specific day one introductory event
  currentEvent = eventList->createDayOneEvent();
  eventStartSpecific();
}

//opens the quit sheet overlay, hides ui elements
void Zork::on_quitButton_clicked()
{
  playSound(crumpleSfx);
  // disable all buttons
  ui->northButton->setDisabled(true);
  ui->southButton->setDisabled(true);
  ui->eastButton->setDisabled(true);
  ui->westButton->setDisabled(true);
  ui->actButton->setDisabled(true);
  ui->examineButton->setDisabled(true);
  ui->quitButton->setDisabled(true);
  ui->infoButton->setDisabled(true);
  ui->mapButton->setDisabled(true);
  ui->quitOverlay->show();
  ui->quitSheet->show();
}

//opens the quit sheet overlay, for main menu
void Zork::on_quitButton_2_clicked()
{
  playSound(crumpleSfx);

  ui->quitOverlay->show();
  ui->quitSheet->show();
}

//shows hidden ui elements, checks that directions are displayed accurately.
void Zork::on_quitCancel_clicked()
{
  playSound(crumpleSfx);

  updateDisabledDirections();
  ui->actButton->setDisabled(false);
  ui->examineButton->setDisabled(false);
  ui->quitButton->setDisabled(false);
  ui->infoButton->setDisabled(false);
  ui->quitOverlay->hide();
  ui->quitSheet->hide();
  ui->mapButton->setDisabled(false);
}

//exits the game
void Zork::on_quitConfirm_clicked() { exit(EXIT_SUCCESS); }

//loads a random ramble from the arraylist of rambles and outputs it to the notebook
void Zork::on_notebookButton_clicked()
{
  currentRamble = rambleList->getRandomRambles();
  QString currentRambleText = QString::fromStdString(currentRamble->text);
  updateNotebookDuringEvent(currentRambleText);
  playSound(penSfx);
}

//takes in values from the event objects and updates the game state based on them
//updates location, option text, event text, prints event text to the notebook
void Zork::on_option_1_clicked()
{
  playSound(clickSfx);

  if (currentEvent->isEnd)
  {
    playSound(penSfx);

    if (currentEvent->locationLeft)
    {
      uniLife->setLocation(currentEvent->locationLeft);
      updateLocation();
      updatePositionAfterMoving();
    }
    ui->stackedWidget->setCurrentIndex(0);
    updateOnChangeStackPaneIndex();
    return;
  }

  currentEvent = currentEvent->leftOption;
  updateNumberOfOptions();
  QString currentEventText = QString::fromStdString(currentEvent->text);
  ui->eventText->setPlainText(currentEventText);

  QString currentEventOption1 =
      QString::fromStdString(currentEvent->leftOptiontext);
  ui->option_1->setText(currentEventOption1);

  QString currentEventOption2 =
      QString::fromStdString(currentEvent->rightOptiontext);
  ui->option_2->setText(currentEventOption2);
  updateNotebookDuringEvent(currentEventText);
}
//takes in values from the event objects and updates the game state based on them
//updates location, option text, event text, prints event text to the notebook
void Zork::on_option_2_clicked()
{
  playSound(clickSfx);
  if (currentEvent->isEnd)
  {
    playSound(penSfx);
    if (currentEvent->locationRight)
    {
      uniLife->setLocation(currentEvent->locationRight);
      updateLocation();
      updatePositionAfterMoving();
    }
    ui->stackedWidget->setCurrentIndex(0);
    updateOnChangeStackPaneIndex();
    return;
  }

  currentEvent = currentEvent->rightOption;
  updateNumberOfOptions();

  QString currentEventText = QString::fromStdString(currentEvent->text);
  ui->eventText->setPlainText(currentEventText);

  QString currentEventOption1 =
      QString::fromStdString(currentEvent->leftOptiontext);
  ui->option_1->setText(currentEventOption1);

  QString currentEventOption2 =
      QString::fromStdString(currentEvent->rightOptiontext);
  ui->option_2->setText(currentEventOption2);
  updateNotebookDuringEvent(currentEventText);
}

//takes in value from the current event object and disables the second option if none exists.
void Zork::updateNumberOfOptions()
{
  if (currentEvent->isSolo)
  {
    ui->option_2->hide();
  }
  else
  {
    ui->option_2->show();
  }
}

//updates the current location background based on time, day and weather.
void Zork::updateLocation()
{
  bool isRaining = time->isRaining();
  if (time->isDayTime() && !isRaining)
  {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getDayClear())));
  }
  else if (time->isDayTime() && isRaining)
  {
    QMovie *movie =
        new QMovie(QString::fromStdString(uniLife->currentRoom->getDayRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  }
  else if (!time->isDayTime() && !isRaining)
  {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getNightClear())));
  }
  else if (!time->isDayTime() && isRaining)
  {
    QMovie *movie = new QMovie(
        QString::fromStdString(uniLife->currentRoom->getNightRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  }
}

//random chance to activate the interact button so a player can start a new event.
void Zork::interactChance()
{
//sets interactEnabled as true based on random chance
    interactEnabled = (rand() % 100) < 65;

  //if interactEnabled is true, returns a message to the notebook.
  if (interactEnabled)
  {
    ui->actButton->setDisabled(false);
    eventExistsText = "It looked like something was going on...\n";
  }
  else
    eventExistsText = "";
}

//method to update the notebook text during an event, or whenever we pass in a string.
void Zork::updateNotebookDuringEvent(QString currentEventText)
{
  //checks what day the notebook is on, to print text to the correct textt box
  if (time->getDayNum() == 0)
  {
    QString currentPlainText = ui->plainTextEdit->toPlainText() +
                               QString::fromStdString("\n") + currentEventText;
    //resets cursor location to the bottom where the new text is located
    ui->plainTextEdit->setPlainText(currentPlainText);
    ui->plainTextEdit->moveCursor(QTextCursor::End);
  }
  else
  {
    QPlainTextEdit *qpte =
        ui->tabWidget->currentWidget()->findChild<QPlainTextEdit *>();

    QString currentPlainText =
        qpte->toPlainText() + QString::fromStdString("\n") + currentEventText;
    //resets cursor location to the bottom where the new text is located
    qpte->setPlainText(currentPlainText);
    qpte->moveCursor(QTextCursor::End);
  }
  //simple check for exiting the game based on the current event's text.
  if (currentEventText == "Exit Game")
  {
    // starts specific event
    exit(EXIT_SUCCESS);
  }
}
