#ifndef G_APPLICATION_H
#define G_APPLICATION_H

#include <application.h>

class GApplication : public Application
{
    friend class Singleton<GApplication>;

protected:
    GApplication(int argc, char** argv);

public:
    void initialize() override;
};

#endif /* G_APPLICATION_H */
