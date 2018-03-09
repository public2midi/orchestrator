//
// Created by Benjamin Rozière on 05/03/2018.
//

#ifndef ORCHESTRA_DSPRCONTROLLER_H
#define ORCHESTRA_DSPRCONTROLLER_H


#include <DSPatch.h>
#include "../include/DsprParam.h"
#include <QtpMain.h>

#include <QFileSystemWatcher>
#include <QObject>

#include <set>

class DsprController : public QObject
{
    Q_OBJECT

public:
    DsprController(QtpMain& mainWindow);
    ~DsprController();

    signals:
    void inputAdded(DspComponent* component, int index);
    void inputRemoved(DspComponent* component, int index);
    void outputAdded(DspComponent* component, int index);
    void outputRemoved(DspComponent* component, int index);
    void parameterAdded(DspComponent* component, int index);
    void parameterRemoved(DspComponent* component, int index);
    void parameterUpdated(DspComponent* component, int index);

public slots:
    void compInserted(QtpComp* qtpComp);
    void compRemoved(int compId);
    void wireConnected(int fromComp, int fromPin, int toComp, int toPin);
    void wireDisconnected(int fromComp, int fromPin, int toComp, int toPin);

    void boolUpdated(bool value);
    void intUpdated(int value);
    void floatUpdated(float value);
    void stringUpdated(std::string const& value);
    void triggerUpdated();

private slots:
    void _loadPlugins();

    void _inputAdded(DspComponent* component, int index);
    void _inputRemoved(DspComponent* component, int index);
    void _outputAdded(DspComponent* component, int index);
    void _outputRemoved(DspComponent* component, int index);
    void _parameterAdded(DspComponent* component, int index);
    void _parameterRemoved(DspComponent* component, int index);
    void _parameterUpdated(DspComponent* component, int index);

private:
    QFileSystemWatcher _fileWatcher;
    QtpMain& _mainWindow;
    std::set<int> _settingParams;
    std::vector<DspPluginLoader> _pluginLoaders;

    std::map<DspComponent const*, QtpComp*> _qtpComps;
    std::map<int, DspComponent*> _components;
    std::map< int, std::vector<DsprParam*> > _params;
    DspCircuit _circuit;
};


#endif //ORCHESTRA_DSPRCONTROLLER_H
