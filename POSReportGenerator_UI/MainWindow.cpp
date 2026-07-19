#include "MainWindow.h"

#include "imgui.h"

void MainWindow::Draw()
{
    ImGui::Begin("POS Report Generator");

    ImGui::Text("Welcome to POS Report Generator!");

    ImGui::Separator();

    m_toolbar.Draw();

    ImGui::Separator();

    DrawStoreTable();

    ImGui::End();
}

void MainWindow::DrawStoreTable()
{
    if (ImGui::BeginTable(
        "StoreTable",
        7))
    {
        ImGui::TableSetupColumn("Store No");
        ImGui::TableSetupColumn("Store Name");
        ImGui::TableSetupColumn("Status");
        ImGui::TableSetupColumn("POS");
        ImGui::TableSetupColumn("Updated");
        ImGui::TableSetupColumn("Rate");
        ImGui::TableSetupColumn("Open Date");

        ImGui::TableHeadersRow();

        ImGui::EndTable();
    }
}
