//
// Created by Benjamin Rozière on 05/03/2018.
//

#ifndef ORCHESTRA_DSPRPARAM_H
#define ORCHESTRA_DSPRPARAM_H


#include <DSPatch.h>

#include <QCheckBox>
#include <QComboBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QObject>
#include <QPushButton>
#include <QSlider>
#include <QWidget>
#include <QWidgetAction>

class QtpWire;

class DsprParam : public QObject
{
    Q_OBJECT

public:
    DsprParam(int compId, int paramId, std::string const& name, DspParameter const& param, QMenu* contextMenu);
    QWidgetAction* action();
    DspParameter const& param();

    int compId() const;
    int paramId() const;
    std::string name() const;

    bool SetBool(bool const& value);
    bool SetInt(int const& value);
    bool SetIntRange(std::pair<int, int> const& intRange);
    bool SetFloat(float const& value);
    bool SetFloatRange(std::pair<float, float> const& floatRange);
    bool SetString(std::string const& value);
    bool SetList(std::vector<std::string> const& value);

    signals:
    void boolUpdated(bool value);
    void intUpdated(int value);
    void floatUpdated(float value);
    void stringUpdated(std::string const& value);
    void triggerUpdated();

private slots:
    void paramChanged(bool value);
    void paramChanged(int value);
    void paramChanged(QString const&);
    void paramChanged();

    void updateSlider(int value);
    void browseForFile();

private:
    bool _settingParam;
    int _compId;
    int _paramId;
    std::string _name;
    DspParameter _param;
    QMenu* _contextMenu;
    QWidgetAction* _action;

    QCheckBox* _checkbox;
    QSlider* _slider;
    QLineEdit* _textBox;
    QComboBox* _listBox;
    QPushButton* _button;
};


#endif //ORCHESTRA_DSPRPARAM_H
