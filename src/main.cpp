#include <Geode/Geode.hpp>

#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/SecretLayer2.hpp>

using namespace geode::prelude;

bool isSecretLayer2{false};

class $modify(MyPlayLayer, PlayLayer) {
    void onQuit() {
        PlayLayer::onQuit();

        if (isSecretLayer2) {
            isSecretLayer2 = false;
            GameManager::get()->fadeInMusic("secretLoop02.mp3");
        }
    }
};

class $modify(MySecretLayer2, SecretLayer2) {
    void onSecretLevel(CCObject* sender) {
        isSecretLayer2 = true;

        SecretLayer2::onSecretLevel(sender);
    }
};
