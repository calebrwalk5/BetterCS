#include "menu.hpp"

#include "imgui/imgui.h"

#include "roboto.hpp"


void style() {
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text] = ImVec4(0.85f, 0.65f, 0.05f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.24f, 0.24f, 0.24f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.011f, 0.305f, 0.970f, 0.40f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.011f, 0.305f, 0.970f, 0.67f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.011f, 0.305f, 0.970f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.443f, 0.564f, 0.600f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f); 
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.011f, 0.305f, 0.970f, 0.40f); 
    colors[ImGuiCol_ButtonActive] = ImVec4(0.01f, 0.30f, 0.97f, 0.40f); 
    colors[ImGuiCol_Header] = ImVec4(0.011f, 0.305f, 0.970f, 0.31f); 
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.011f, 0.305f, 0.970f, 0.80f); 
    colors[ImGuiCol_HeaderActive] = ImVec4(0.011f, 0.305f, 0.970f, 1.00f); 
    colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f); 
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f); 
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f); 
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.011f, 0.305f, 0.970f, 0.25f); 
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.011f, 0.305f, 0.970f, 0.67f); 
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.011f, 0.305f, 0.970f, 0.95f); 
    colors[ImGuiCol_Tab] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f); 
    colors[ImGuiCol_TabHovered] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f); 
    colors[ImGuiCol_TabActive] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f); 
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.011f, 0.305f, 0.970f, 0.97f); 
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.011f, 0.305f, 0.970f, 1.00f); 
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f); 
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f); 
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f); 
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f); 
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.011f, 0.305f, 0.970f, 0.35f); 
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f); 
    colors[ImGuiCol_NavHighlight] = ImVec4(0.011f, 0.305f, 0.970f, 1.00f); 
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f); 
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f); 
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f); 
    colors[ImGuiCol_Header] = ImVec4(0.00784313725490196, 0.28627450980392155, 0.9764705882352941, 1.0);

    ImGui::GetStyle().ScrollbarSize = 8;
    ImGui::GetStyle().ScrollbarRounding = 0;
    ImGui::GetStyle().WindowRounding = 6;
    ImGui::GetStyle().ChildRounding = 3;
    ImGui::GetStyle().FrameRounding = 4;
    ImGui::GetStyle().TabRounding = 2;

}

    void Menu::onPollEvent(SDL_Event * event,
      const int result) {
      if (result && ImGui_ImplSDL2_ProcessEvent(event) && Menu::open) {
        event -> type = 0;
      }
    }

    void Menu::onSwapWindow(SDL_Window * window) {
      if (!initialised) {
        gl3wInit();
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplOpenGL3_Init("#version 100");
        ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
        style();
        ImGui::GetIO().Fonts -> AddFontFromMemoryCompressedTTF(Roboto_compressed_data, Roboto_compressed_size, 14.f);
        initialised = true;
      }

      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplSDL2_NewFrame(window);

      ImGuiIO & io = ImGui::GetIO();
      int w, h;
      SDL_GetWindowSize(window, & w, & h);
      Globals::screenSizeX = w;
      Globals::screenSizeY = h;
      io.DisplaySize = ImVec2((float) w, (float) h);

      ImGui::NewFrame();

      Menu::drawOverlay(ImGui::GetBackgroundDrawList());
      if (Menu::open) {
        io.MouseDrawCursor = true; // TODO:find workaround at some point because ugly
        Menu::drawMenu();
        if (devWindow) {
          drawDevWindow();
        }
        if (demoWindow) {
          ImGui::ShowDemoWindow();
        }
      } else {
        io.MouseDrawCursor =false;
      }

      if (ImGui::IsKeyPressed(SDL_SCANCODE_INSERT,false)) {
        Config::reloadCfgList();
        Menu::open = !Menu::open;
      }

      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Menu::drawMenu() {
      ImGui::SetNextWindowSize(ImVec2 {
        1100,
        620
      });
      ImGui::Begin("BetterCS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
      auto bWidth = ImVec2(119, 90); //115 20
      ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(2, 5));

      ImGui::BeginChild("pane1", ImVec2(135, 0), true);

      ImGui::GetStyle().Colors[ImGuiCol_Button] = (Menu::tabSelected == 0) ? ImVec4(0.444f, 0.600f, 1.000f, 1.00f) : ImVec4(0.444f, 0.600f, 1.000f, 1.00f);
      if (ImGui::Button("Aim", bWidth)) {
        Menu::tabSelected = 0;
      } //ImGui::SameLine();

      ImGui::GetStyle().Colors[ImGuiCol_Button] = (Menu::tabSelected == 1) ? ImVec4(0.444f, 0.600f, 1.000f, 1.00f) : ImVec4(0.03f, 0.23f, 0.04f, 0.62f);
      if (ImGui::Button("Visuals", bWidth)) {
        Menu::tabSelected = 1;
      } //ImGui::SameLine();

      ImGui::GetStyle().Colors[ImGuiCol_Button] = (Menu::tabSelected == 2) ? ImVec4(0.444f, 0.600f, 1.000f, 1.00f) : ImVec4(0.444f, 0.600f, 1.000f, 1.00f);
      if (ImGui::Button("Misc", bWidth)) {
        Menu::tabSelected = 2;
      }
      ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0.444f, 0.600f, 1.000f, 1.00f);

      ImGui::GetStyle().Colors[ImGuiCol_Button] = (Menu::tabSelected == 4) ? ImVec4(0.00784313725490196, 0.28627450980392155, 0.9764705882352941, 1.0) : ImVec4(0.03f, 0.23f, 0.04f, 0.62f);
      if (ImGui::Button("Rage", bWidth)) {
        Menu::tabSelected = 4;
      }
      // ImGui::SameLine();
      ImGui::PopStyleVar();

      ImGui::EndChild();

      ImGui::SameLine();

      ImGui::BeginChild("pane2", ImVec2(0, 0), true);
      //ImGui::Separator();
      //ImGui::Separator();

      switch (tabSelected) {
      case 0: {
        Menu::drawLegitTab();
        break;
      }
      case 1: {
        Menu::drawVisualsTab();
        break;
      }
      case 2: {
        Menu::drawMiscTab();
        break;
      }
      case 3: {
        Menu::drawRageTab();
        break;
      }
      case 4: {
        Menu::drawRageTab();
        break;
      }
      }
      ImGui::EndChild();

      ImGui::End();
    }