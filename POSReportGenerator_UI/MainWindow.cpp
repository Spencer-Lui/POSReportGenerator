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

        auto stores =
            m_storeService.GetSummary();

        for (const auto& store : stores)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", store.GetStoreNo().c_str());

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%s", store.GetStoreName().c_str());

            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%s", store.GetUpdateStatus().c_str());

            ImGui::TableSetColumnIndex(3);
            ImGui::Text("%d", store.GetPosCount());

            ImGui::TableSetColumnIndex(4);
            ImGui::Text("%d", store.GetUpdatedPos());

            ImGui::TableSetColumnIndex(5);
            ImGui::Text("%d%%", store.GetUpdateRate());

            ImGui::TableSetColumnIndex(6);
            ImGui::Text("%s", store.GetOpenDate().c_str());
        }

        ImGui::EndTable();
    }
}
