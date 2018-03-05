//
// Created by Benjamin Rozière on 04/03/2018.
//

#ifndef ORCHESTRA_APPKERNEL_H
#define ORCHESTRA_APPKERNEL_H


#include <vector>
#include <dspatch/DspPluginLoader.h>

class AppKernel {

private:
    std::vector<DspPluginLoader> _loaders;
    bool _booted;
    std::string _pluginsDir;
    std::string _configDir;

public:
    void boot(void);
    void shutdown();
};


#endif //ORCHESTRA_APPKERNEL_H
