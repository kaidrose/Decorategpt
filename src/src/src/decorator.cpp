#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

void applyDecor(std::string prompt) {
    auto editor = LevelEditorLayer::get();
    if (!editor) return;

    auto selected = editor->getSelectedObjects();
    auto objects = selected->count() > 0 ? selected : editor->getAllObjects();

    for (auto obj : objects) {

        // 🎨 COLORS
        if (prompt.find("glow") != std::string::npos) {
            obj->setColor(ccColor3B{0, 255, 255});
        }

        if (prompt.find("hell") != std::string::npos) {
            obj->setColor(ccColor3B{255, 50, 50});
        }

        if (prompt.find("blue") != std::string::npos) {
            obj->setColor(ccColor3B{50, 150, 255});
        }

        // 🧱 OUTLINE
        if (prompt.find("decorate") != std::string::npos) {
            auto outline = GameObject::createWithKey(1757);
            outline->setPosition(obj->getPosition());
            outline->setScale(obj->getScale() * 1.1f);
            editor->addObject(outline, false);
        }

        // ✨ GLOW
        if (prompt.find("decorate") != std::string::npos) {
            auto glow = GameObject::createWithKey(1755);
            glow->setPosition(obj->getPosition());
            glow->setScale(obj->getScale() * 1.2f);
            editor->addObject(glow, false);
        }

        // 🌊 NINE CIRCLES
        if (prompt.find("nine") != std::string::npos) {
            auto pulse = GameObject::createWithKey(1006);
            pulse->setPosition(obj->getPosition());
            editor->addObject(pulse, false);
        }

        // 🎆 AIR DECO
        if (rand() % 4 == 0) {
            auto deco = GameObject::createWithKey(901);
            deco->setPosition(obj->getPosition() + ccp(10, 10));
            deco->setScale(0.5f + (rand() % 100) / 200.0f);
            editor->addObject(deco, false);
        }

        // 📐 FIX GRID
        if (prompt.find("fix") != std::string::npos) {
            obj->setPosition({
                round(obj->getPositionX() / 10) * 10,
                round(obj->getPositionY() / 10) * 10
            });
        }
    }

    log::info("DecorGPT applied!");
}
