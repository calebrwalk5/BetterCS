#include "../menu.hpp"
#include <filesystem>
#include "../config.hpp"
#include <sstream>

void Menu::drawSkinChangerTab() {
    if (ImGui::BeginTabItem("Skin Changer")) {
        ImGui::EndTabItem();
    }
}
