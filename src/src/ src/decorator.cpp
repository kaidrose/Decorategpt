#include "decorator.hpp"
#include <Geode/Geode.hpp>

void decorate() {
    // Example: automatically place custom objects in level
    geode::Level* level = geode::getEditorLevel();
    if (!level) return;

    for (auto obj : level->getObjects()) {
        if (obj->getType() == "platform") {
            obj->addChild("KaidenBlock"); // Custom object
        }
    }
}
