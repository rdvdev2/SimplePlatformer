#ifndef SIMPLEPLATFORMER_IUPDATEABLE_H
#define SIMPLEPLATFORMER_IUPDATEABLE_H

namespace SP::Util {

    class IUpdateable {
        virtual void Update(float deltaUTime) = 0;
    };
}


#endif //SIMPLEPLATFORMER_IUPDATEABLE_H
