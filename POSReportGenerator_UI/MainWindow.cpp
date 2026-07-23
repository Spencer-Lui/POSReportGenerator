#include "MainWindow.h"
#include "imgui.h"

void MainWindow::Draw()
{
    ImGui::Begin("POS Report Generator");

    ImGui::Text("Welcome to POS Report Generator!");

    ImGui::Separator();

    //if (m_toolbar.DrawImportButton())
    //{
    //    // 下一章接 ExportService
    //}

    if (m_toolbar.DrawExportButton())
    {
        auto stores =
            m_storeService.GetSummary();

        std::string exportPath =
            "POSReport.csv";

        bool result =
            m_exportService.ExportStoreSummary(
                stores,
                exportPath);

        if (result)
        {
            m_statusMessage = "Export Success!";
            m_exportSuccess = true;

            m_lastExportPath = exportPath;
        }
        else
        {
            m_statusMessage = "Export Failed!";
            m_exportSuccess = false;

            m_lastExportPath.clear();
        }
    }

    ImGui::Separator();

    if (!m_statusMessage.empty())
    {
        if (m_exportSuccess)
        {
            ImGui::TextColored(
                ImVec4(0.0f, 1.0f, 0.0f, 1.0f),
                "%s",
                m_statusMessage.c_str());
        }
        else
        {
            ImGui::TextColored(
                ImVec4(1.0f, 0.0f, 0.0f, 1.0f),
                "%s",
                m_statusMessage.c_str());
        }

        if (!m_lastExportPath.empty())
        {
            ImGui::Text("Output:");

            ImGui::TextWrapped(
                "%s",
                m_lastExportPath.c_str());
        }

        ImGui::Separator();
    }

    DrawStoreTable();

    ImGui::End();
}

void MainWindow::DrawStoreTable()
{
    if (ImGui::BeginTable(
        "StoreTable",
        7,
        ImGuiTableFlags_Borders |
        ImGuiTableFlags_RowBg |
        ImGuiTableFlags_Resizable |
        ImGuiTableFlags_ScrollY |
        ImGuiTableFlags_Sortable))
    {
        ImGui::TableSetupColumn("Store No");
        ImGui::TableSetupColumn("Store Name");
        ImGui::TableSetupColumn("Status");
        ImGui::TableSetupColumn("POS");
        ImGui::TableSetupColumn("Updated");
        ImGui::TableSetupColumn("Rate");
        ImGui::TableSetupColumn("Open Date");

        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableHeadersRow();

        ImGuiTableSortSpecs* sortSpecs =
            ImGui::TableGetSortSpecs();

        auto stores =
            m_storeService.GetSummary();

        for (const auto& store : stores)
        {
            DrawStoreRow(store);
        }

        ImGui::EndTable();
    }
}
void MainWindow::DrawStoreRow(const StoreInfo& store)
{
    ImGui::TableNextRow();

    ImGui::TableSetColumnIndex(0);
    ImGui::Text("%s", store.GetStoreNo().c_str());

    ImGui::TableSetColumnIndex(1);
    ImGui::Text("%s", store.GetStoreName().c_str());

    ImGui::TableSetColumnIndex(2);
    //ImGui::Text("%s", store.GetUpdateStatus().c_str());
    DrawUpdateStatus(store);

    ImGui::TableSetColumnIndex(3);
    ImGui::Text("%d", store.GetPosCount());

    ImGui::TableSetColumnIndex(4);
    ImGui::Text("%d", store.GetUpdatedPos());

    ImGui::TableSetColumnIndex(5);
    ImGui::Text("%d%%", store.GetUpdateRate());

    ImGui::TableSetColumnIndex(6);
    ImGui::Text("%s", store.GetOpenDate().c_str());
}
void MainWindow::DrawUpdateStatus(const StoreInfo& store)
{
    const std::string& status = store.GetUpdateStatus();

    if (status == "Success")
    {
        ImGui::TextColored(
            ImVec4(0.0f, 1.0f, 0.0f, 1.0f),
            "%s",
            status.c_str());
    }
    else if (status == "Updating")
    {
        ImGui::TextColored(
            ImVec4(1.0f, 1.0f, 0.0f, 1.0f),
            "%s",
            status.c_str());
    }
    else if (status == "Failed")
    {
        ImGui::TextColored(
            ImVec4(1.0f, 0.0f, 0.0f, 1.0f),
            "%s",
            status.c_str());
    }
    else
    {
        ImGui::Text("%s", status.c_str());
    }
}
