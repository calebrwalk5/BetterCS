#include "../menu.hpp"

#include <filesystem>

#include "../config.hpp"

void Menu::drawMovementTab() {
    if (ImGui::BeginTabBar("##movementTabs")) {
      if (ImGui::BeginTabItem("Movement")) {
        ImGui::BeginChild("Movement", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.38, ImGui::GetWindowHeight() * 0.326f), true); {
          ImGui::Text("Movement");
          ImGui::Separator();
          ImGui::Checkbox("Auto Hop", & CONFIGBOOL("Misc>Misc>Movement>Auto Hop"));
          ImGui::Checkbox("Humanised Bhop", & CONFIGBOOL("Misc>Misc>Movement>Humanised Bhop"));
          if (CONFIGBOOL("Misc>Misc>Movement>Humanised Bhop")) {
            ImGui::Text("Bhop Hitchance");
            ImGui::SetNextItemWidth(ImGui::GetWindowContentRegionWidth());
            ImGui::SliderInt("##Bhop Hitchance", & CONFIGINT("Misc>Misc>Movement>Bhop Hitchance"), 0, 100);
            ImGui::Text("Bhop Max Misses");
            ImGui::SetNextItemWidth(ImGui::GetWindowContentRegionWidth());
            ImGui::SliderInt("##Bhop Max Misses", & CONFIGINT("Misc>Misc>Movement>Bhop Max Misses"), 0, 16);
            ImGui::Text("Bhop Max Hops Hit");
            ImGui::SetNextItemWidth(ImGui::GetWindowContentRegionWidth());
            ImGui::SliderInt("##Bhop Max Hops Hit", & CONFIGINT("Misc>Misc>Movement>Bhop Max Hops Hit"), 0, 16);
          }
          if (CONFIGBOOL("Misc>Misc>Movement>Edge Jump")) {
            static bool toggled = false;
            Menu::CustomWidgets::drawKeyBinder("Key", & CONFIGINT("Misc>Misc>Movement>Edge Jump Key"), & toggled);
            ImGui::SameLine();
          }
          ImGui::Checkbox("Edge Jump", & CONFIGBOOL("Misc>Misc>Movement>Edge Jump"));
          if (CONFIGBOOL("Misc>Misc>Movement>JumpBug")) {
            static bool toggled = false;
            Menu::CustomWidgets::drawKeyBinder("Key", & CONFIGINT("Misc>Misc>Movement>JumpBug Key"), & toggled);
            ImGui::SameLine();
          }
          ImGui::Checkbox("JumpBug", & CONFIGBOOL("Misc>Misc>Movement>JumpBug"));
          if (CONFIGBOOL("Misc>Misc>Movement>EdgeBug")) {
            static bool toggled = false;
            Menu::CustomWidgets::drawKeyBinder("Key", & CONFIGINT("Misc>Misc>Movement>EdgeBug Key"), & toggled);
            ImGui::SameLine();
          }

          if (CONFIGBOOL("Misc>Misc>Movement>Block Bot")) {
            static bool toggled = false;
            Menu::CustomWidgets::drawKeyBinder("Key", & CONFIGINT("Misc>Misc>Movement>Block Bot Key"), & toggled);
            ImGui::SameLine();
          }
          ImGui::Checkbox("Block Bot", & CONFIGBOOL("Misc>Misc>Movement>Block Bot"));
          ImGui::Checkbox("EdgeBug", & CONFIGBOOL("Misc>Misc>Movement>EdgeBug"));
          ImGui::Checkbox("Fast Duck", & CONFIGBOOL("Misc>Misc>Movement>Fast Duck"));
          ImGui::SameLine();
          ImGui::TextDisabled("?");
          if (ImGui::IsItemHovered())
            ImGui::SetTooltip("May cause untrusted, use at own risk!");
          ImGui::EndChild();
        }
      }
    }
}