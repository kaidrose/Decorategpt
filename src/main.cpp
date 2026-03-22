#include "decorator.hpp"
#include <Geode/Geode.hpp>

class KaidenMod : public Mod {
public:
    KaidenMod() : Mod() {}

    void onLoad() override {
        decorate();
    }
};

REGISTER_MOD(KaidenMod)
