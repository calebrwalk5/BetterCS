#include "../menu.hpp"
#include <filesystem>
#include "../config.hpp"
#include <sstream>

const char* skinNames[] = {
    "Default",
    "Test"
};


void Menu::drawSkinChangerTab() {
    if (ImGui::BeginTabItem("Skin Changer")) {
        Weapon* weapon = (Weapon*) Interfaces::entityList->GetClientEntity((uintptr_t)Globals::localPlayer->activeWeapon() & 0xFFF);
        if (weapon && weapon->itemIndex() != ItemIndex::INVALID) {
            const char* weaponName = itemIndexMap.at(weapon->itemIndex());

            char buf[256];
            snprintf(buf, 256, "Misc>Skins>Skins>%s>PaintKit", weaponName);

            char buf2[256];
            snprintf(buf2, 256, "Misc>Skins>Skins>%s>Wear", weaponName);

            int paintkit = CONFIGINT(buf);
            float wear = (float)CONFIGINT(buf2)/100.f;

            if (ImGui::Combo("Skin", &paintkit, skinNames, IM_ARRAYSIZE(skinNames))) {
                CONFIGINT(buf) = paintkit;
            }
            if (ImGui::SliderFloat("Wear", &wear, 0.f, 1.f)) {
                CONFIGINT(buf2) = (int)(wear*100.f);
            }
        }
        ImGui::EndTabItem();
    }
}
