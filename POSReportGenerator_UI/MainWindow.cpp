#include "MainWindow.h"

#include "imgui.h"

void MainWindow::Draw()
{
    ImGui::Begin("POS Report Generator");

    ImGui::Text("Welcome to POS Report Generator!");

    ImGui::Separator();

    /*ImGui::Button("Import CSV");

    ImGui::SameLine();

    ImGui::Button("Export Excel");*/

    m_toolbar.Draw();

    ImGui::End();
    
}
