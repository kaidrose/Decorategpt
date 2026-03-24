#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

extern void applyDecor(std::string prompt);

class $modify(MyEditorUI, EditorUI) {

    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer)) return false;

        // Decor button
        auto decorBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png"),
            this,
            menu_selector(MyEditorUI::onDecor)
        );
        decorBtn->setPosition({200, 100});
        this->addChild(decorBtn);

        // Random button
        auto randomBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_shuffleBtn_001.png"),
            this,
            menu_selector(MyEditorUI::onRandom)
        );
        randomBtn->setPosition({250, 100});
        this->addChild(randomBtn);

        return true;
    }

    void onDecor(CCObject*) {
        applyDecor("glow decorate");
    }

    void onRandom(CCObject*) {
        int r = rand() % 3;

        if (r == 0) applyDecor("glow");
        if (r == 1) applyDecor("hell");
        if (r == 2) applyDecor("nine");
    }
};
