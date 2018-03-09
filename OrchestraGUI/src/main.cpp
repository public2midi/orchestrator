//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <QApplication>
#include <QtpMain.h>
#include "../include/DsprController.h"

int main(int argc, char** argv) {

    //Orchestrator orchestrator;

    //orchestrator.start();
    //getchar();
    //orchestrator.stop();

    QApplication app(argc, argv);
    QtpMain mainWindow;

    mainWindow.show();

    DsprController controller(mainWindow);

    return app.exec();
}
