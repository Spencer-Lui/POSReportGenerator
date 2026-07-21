#include "Toolbar.h"

#include "imgui.h"

bool Toolbar::DrawImportButton()
{
    return ImGui::Button("Import CSV");
}

bool Toolbar::DrawExportButton()
{
    ImGui::SameLine();

    return ImGui::Button("Export CSV");
}
