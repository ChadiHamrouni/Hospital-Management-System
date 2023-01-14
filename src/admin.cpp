#include<iostream>
#include <vector>
#include"imgui.h"
#include "implot.h"

#include "../header/admin.h"
#include "../header/doctor.h"
#include "../header/icons.h"

static ImVec4 dark_blue = ImColor(67, 64, 64, 255);
ImU32 cell_bg_color = ImColor(dark_blue);

static ImVec4 red = ImColor(127, 4, 38, 255);
ImU32 red_bg = ImColor(red);

static ImVec4 green = ImColor(21, 98, 21, 255);
ImU32 green_bg = ImColor(green);

Admin::Admin(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Username, std::string Password) : Person(PersonId, FullName, PhoneNumber){
    username = Username;
    password = Password;
}

void Admin::getAdminDetails() {
    std::cout << "Person ID: " << personId << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
}

void Admin::search() {
    static ImGuiTextFilter filter;
    static std::vector<std::string> resources = {
            "Mariem Bouat",
            "Ahmed Bouat",
            "Mariem Bouat",
            "Ahmed Bouat",
            "Mariem Bouat",
            "Ahmed Bouat",
            "Mariem Bouat",
            "Ahmed Bouat"
    };

    ImGui::SetCursorPos(ImVec2(250, 80));
    filter.Draw(ICON_FA_MAGNIFYING_GLASS "  Search", 240);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(29, 47, 74, 255));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, IM_COL32(29, 47, 74, 255));
    ImGui::SetCursorPos(ImVec2(250, 103));

    while (ImGui::IsItemActive()) {
        if (ImGui::ListBoxHeader("##ResourcesList", ImVec2(240, 60))) {
            for (const auto& resource : resources) {
                if (filter.PassFilter(resource.c_str()))
                    ImGui::Text(resource.c_str());
            }
            ImGui::ListBoxFooter();
        }
    }
    ImGui::PopStyleColor(2);
}

void Admin::displayProfile() {
    ImGui::BeginGroup();
    ImGui::SetCursorPos(ImVec2(250, 38));
    ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); 

    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("Description"))
        {
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3);
            ImGui::SetCursorPos(ImVec2(0, 70));
            if (ImGui::BeginTable("Left Side", 1)) {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Button(ICON_FA_LOCK"  Change Passwords", ImVec2(200, 30)); ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();
                ImGui::TableNextColumn();
                ImGui::Button(ICON_FA_ID_CARD_CLIP"  Manage Accounts", ImVec2(200, 30));

            }ImGui::EndTable();

            ImGui::SetCursorPos(ImVec2(350, 70));
            if (ImGui::BeginTable("Right Side", 1)) {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Button(ICON_FA_USER_PLUS"  Add Admin", ImVec2(200, 30));ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();
                ImGui::TableNextColumn();
                ImGui::Button(ICON_FA_CLIPBOARD"  Report", ImVec2(200, 30));

            }ImGui::EndTable();
            ImGui::PopStyleVar();

            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Details"))
        {
            ImGui::Text("ID: 0123456789");
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::EndChild();
    ImGui::EndGroup();
}

void Admin::displaySettings(ImGuiIO& io) {
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3);
    ImGui::SetCursorPos(ImVec2(300, 70));
    if (ImGui::BeginTable("Settings", 1)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::CheckboxFlags("io.ConfigFlags: NavEnableKeyboard", &io.ConfigFlags, ImGuiConfigFlags_NavEnableKeyboard);ImGui::Spacing();ImGui::Spacing();
        ImGui::TableNextColumn();
        ImGui::CheckboxFlags("io.ConfigFlags: NavEnableGamepad", &io.ConfigFlags, ImGuiConfigFlags_NavEnableGamepad);ImGui::Spacing();ImGui::Spacing();
        ImGui::TableNextColumn();
        ImGui::CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", &io.ConfigFlags, ImGuiConfigFlags_NavEnableSetMousePos);ImGui::Spacing();ImGui::Spacing();
        ImGui::TableNextColumn();
        ImGui::CheckboxFlags("io.ConfigFlags: NoMouse", &io.ConfigFlags, ImGuiConfigFlags_NoMouse);ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();ImGui::Spacing();
        ImGui::TableNextColumn();
        static float f1 = 0.123f, f2 = 0.0f;
        ImGui::SliderFloat("", &f1, 0.0f, 1.0f, "Font Size = %.3f");
    }ImGui::EndTable();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 270));
    ImGui::Text("Fonts");
    ImGui::LabelText("", "");
    {
        static int item_current = 0;
        const char* itemsa[] = { "Arial (sans-serif)", "Dr. Ahmed Alel", "Dr. Amira Chaker", "Dr Selim Bouhedi", "EEEE", "FFFF", "GGGG", "HHHH", "IIIIIII", "JJJJ", "KKKKKKK" };
        ImGui::SetCursorPos(ImVec2(300, 296));
        ImGui::Combo(" ", &item_current, itemsa, IM_ARRAYSIZE(itemsa));
    }
    ImGui::PopItemWidth();

    ImGui::SetCursorPos(ImVec2(300, 400));
    ImGui::Button("Revert", ImVec2(130 - 15, 30));
    ImGui::SetCursorPos(ImVec2(450, 400));
    ImGui::Button("Save", ImVec2(130 - 15, 30));
    ImGui::PopStyleVar();
}

void Admin::doctorRequestHeader() {
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("ID");
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("FULL NAME");
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("DEPARTMENT");
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("STATUS");
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
}

void Admin::doctorRequest() {
    ImGui::Dummy(ImVec2(0, 22));
    ImGui::Text(" DR291-251");
    ImGui::TableNextColumn();
    ImGui::Dummy(ImVec2(0, 22));
    ImGui::Text(" Slimen Labyedh");
    ImGui::TableNextColumn();
    ImGui::Dummy(ImVec2(0, 22));
    ImGui::Text(" Neurology");
    ImGui::TableNextColumn();
    ImGui::Dummy(ImVec2(0, -5));
    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, green);
    ImGui::Button("Accept", ImVec2(-FLT_MIN- 2, 0.0f));
    ImGui::PopStyleColor();
    ImGui::Dummy(ImVec2(15, 0));
    ImGui::PushStyleColor(ImGuiCol_Button, red);
    ImGui::Button("Reject", ImVec2(-FLT_MIN-2, 0.0f));
    ImGui::PopStyleColor();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::TableNextColumn();
}

void Admin::displayArchivesHeader() { 
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("ID");
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("FULL NAME");
    ImGui::TableNextColumn();
    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
    ImGui::Text("PHONE NUMBER");
}

void Admin::dashBoardStats(ImFont* font){
    static ImPlotPieChartFlags flags = 0;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10);
    ImGui::SetCursorPos(ImVec2(320, 50));
    if (ImGui::BeginTable("Dashboard Numbers", 4, flags)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(315, 55));
        ImGui::Text("26");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_FOLDER_OPEN"  Appointments");

        ImGui::TableNextColumn();

        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(710, 55));
        ImGui::Text("58");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_USERS"  Current Staff");

        ImGui::TableNextColumn();

        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(1107, 55));
        ImGui::Text("78");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_HOUSE_MEDICAL "  Current Capacity");

        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(1510, 55));
        ImGui::Text("4");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_HANDS_HOLDING_CHILD"  Intensive Care");

        ImGui::TableNextColumn();
        ImGui::TableNextRow();
        ImGui::TableNextColumn();

        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(710, 250));
        ImGui::Text("13");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_VIRUS_COVID "  Covid Cases");

        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(1107, 250));
        ImGui::Text("26");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_CALENDAR_DAYS"  Appointments Today");

        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(1510, 250));
        ImGui::Text("8");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_USER_DOCTOR"  Available Doctors");

        ImGui::TableNextColumn();
        ImGui::PushFont(font);
        ImGui::SetCursorPos(ImVec2(315, 250));
        ImGui::Text("23");
        ImGui::PopFont();
        ImGui::Spacing();
        ImGui::Text(ICON_FA_HAND_HOLDING_MEDICAL"  Filled Rooms");

        ImGui::PopStyleVar();
    }ImGui::EndTable();
}

void Admin::latestAppointment(){
    ImGui::SetCursorPos(ImVec2(250, 125));
    if (ImGui::BeginTable("Apointments Header", 5, ImGuiTableFlags_Borders)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("ID");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("FULL NAME");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("RFFERED TO");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("DATE");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("");

        for (int i = 0; i < 7; i++) {
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, green_bg);
            ImGui::Text("PT192-255");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, green_bg);
            ImGui::Text("Ahmed Bouat");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, green_bg);
            ImGui::Text("Mariem Hlel");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, green_bg);
            ImGui::Text("1/9/2023");
            ImGui::TableNextColumn();
            ImGui::Button("View Details >", ImVec2(-FLT_MIN, 0.0f));
        }
       
        for (int i = 0; i < 4; i++) {
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("PT192-255");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("Ahmed Bouat");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("Mariem Hlel");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("1/9/2023");
            ImGui::TableNextColumn();
            ImGui::Button("View Details >", ImVec2(-FLT_MIN, 0.0f));ImGui::SameLine();
        }       
    }ImGui::EndTable();
}

void Admin::futureAppointments() {
    ImGui::SetCursorPos(ImVec2(250, 125));
    if (ImGui::BeginTable("Appointments Header", 5, ImGuiTableFlags_Borders)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("ID");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("FULL NAME");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("RFFERED TO");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("DATE");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("");

        for (int i = 0; i < 15; i++) {
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("PT192-255");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("Ahmed Bouat");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("Mariem Hlel");
            ImGui::TableNextColumn();
            ImGui::Spacing();
            ImGui::Text("1/9/2023");
            ImGui::TableNextColumn();
            ImGui::Button("View Details >", ImVec2(-FLT_MIN, 0.0f));ImGui::SameLine();
        }
    }ImGui::EndTable();
}

void Admin::currentOnCallDoctors(Doctor doc) {
    ImGui::SetCursorPos(ImVec2(250, 125));
    if (ImGui::BeginTable("Doctors List Header", 4, ImGuiTableFlags_Borders)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("ID");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("FULL NAME");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("DEPARTMENT");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("STATUS");

        for (int i = 0; i < 5; i++) {
            doc.doctorListColorless(doc);          
        }
        doc.doctorList(doc);
        doc.doctorListColorless(doc);
    }ImGui::EndTable();
}

void Admin::currentRegularDoctors(Doctor doc) {
    ImGui::SetCursorPos(ImVec2(250, 125));
    if (ImGui::BeginTable("Doctors List Header", 4, ImGuiTableFlags_Borders)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("ID");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("FULL NAME");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("DEPARTMENT");
        ImGui::TableNextColumn();
        ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color);
        ImGui::Text("STATUS");

        for (int i = 0; i < 6; i++) {
            doc.doctorListColorless(doc);
            doc.doctorList(doc);
        }       
    }ImGui::EndTable();
}

void Admin::addDoctorForm() {
    static char str0[128] = "";
    static char str1[128] = "";
    static char str2[128] = "";
    static char str3[128] = "";
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3);
    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 102));
    ImGui::Text("Full Name");
    ImGui::SetCursorPos(ImVec2(300, 125));
    ImGui::InputText("", str0, IM_ARRAYSIZE(str0));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 102));
    ImGui::Text("Email");
    ImGui::SetCursorPos(ImVec2(700, 125));
    ImGui::InputText("", str1, IM_ARRAYSIZE(str1));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 167));
    ImGui::Text("Phone Number");
    ImGui::SetCursorPos(ImVec2(300, 190));
    ImGui::InputText("", str2, IM_ARRAYSIZE(str2));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 167));
    ImGui::Text("Address");
    ImGui::SetCursorPos(ImVec2(700, 190));
    ImGui::InputText("", str3, IM_ARRAYSIZE(str3));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 236));
    ImGui::Text("Specialty");
    ImGui::LabelText("", "");
    {
        static int item_current = 0;
        const char* itemsa[] = { "Dermatology", "Medical Genetics", "Emergency Medicine", "Diagnostic Radiology", "Anesthesiology", "Allergy", "Immunology", "Pediatrics", "Urology", "Surgery", "Gynecology" };
        ImGui::SetCursorPos(ImVec2(300, 260));
        ImGui::Combo(" ", &item_current, itemsa, IM_ARRAYSIZE(itemsa));
    }
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 236));
    ImGui::Text("Department");
    ImGui::LabelText("", "");
    {
        static int item_currents = 0;
        const char* itemss[] = { "Surgery", "Obstetrics", "Paediatrics", "Cardiology", "Neurology", "Nuclear Medicine", "Orthopaedics", "Infectious diseases", "Gynaecology", "Nursing", "Paramedical" };
        ImGui::SetCursorPos(ImVec2(700, 260));
        ImGui::Combo("  ", &item_currents, itemss, IM_ARRAYSIZE(itemss));
    }
    ImGui::PopItemWidth();

    static int e = 0;
    ImGui::SetCursorPos(ImVec2(700, 330));
    ImGui::RadioButton("M", &e, 0);
    ImGui::SetCursorPos(ImVec2(785, 330));
    ImGui::RadioButton("F", &e, 1);

    static int a = 0;
    ImGui::SetCursorPos(ImVec2(300, 330));
    ImGui::RadioButton("Regular Doctor", &a, 0);
    ImGui::SetCursorPos(ImVec2(450, 330));
    ImGui::RadioButton("On Call", &a, 1);

    ImGui::SetCursorPos(ImVec2(600, 430));
    ImGui::Button("ADD", ImVec2(130 - 15, 30));
    ImGui::PopStyleVar();
}

void Admin::addPatientForm() {
    static char str0[128] = "";
    static char str1[128] = "";
    static char str2[128] = "";
    static char str3[128] = "";
    static char str4[128] = "";
    static char str5[128] = "";
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3);
    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 102));
    ImGui::Text("Full Name");
    ImGui::SetCursorPos(ImVec2(300, 125));
    ImGui::InputText("", str0, IM_ARRAYSIZE(str0));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 102));
    ImGui::Text("Email");
    ImGui::SetCursorPos(ImVec2(700, 125));
    ImGui::InputText("", str1, IM_ARRAYSIZE(str1));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 167));
    ImGui::Text("Phone Number");
    ImGui::SetCursorPos(ImVec2(300, 190));
    ImGui::InputText("", str2, IM_ARRAYSIZE(str2));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 167));
    ImGui::Text("Address");
    ImGui::SetCursorPos(ImVec2(700, 190));
    ImGui::InputText("", str3, IM_ARRAYSIZE(str3));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 230));
    ImGui::Text("City");
    ImGui::SetCursorPos(ImVec2(300, 253));
    ImGui::InputText("", str4, IM_ARRAYSIZE(str4));
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(700, 230));
    ImGui::Text("Reffered to");
    ImGui::LabelText("", "");
    {
        static int item_current = 0;
        const char* itemsa[] = { "Dr. Mariem Bousalem", "Dr. Ahmed Alel", "Dr. Amira Chaker", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi", "Dr Selim Bouhedi" };
        ImGui::SetCursorPos(ImVec2(700, 253));
        ImGui::Combo(" ", &item_current, itemsa, IM_ARRAYSIZE(itemsa));
    }
    ImGui::PopItemWidth();

    ImGui::PushItemWidth(300);
    ImGui::SetCursorPos(ImVec2(300, 297));
    ImGui::Text("Entry Date (mm/dd/yyyy)");
    ImGui::SetCursorPos(ImVec2(300, 320));
    ImGui::InputText("", str2, IM_ARRAYSIZE(str2));
    ImGui::PopItemWidth();

    static int c = 0;
    ImGui::SetCursorPos(ImVec2(700, 330));
    ImGui::RadioButton("M", &c, 0);
    ImGui::SetCursorPos(ImVec2(785, 330));
    ImGui::RadioButton("F", &c, 1);

    ImGui::SetCursorPos(ImVec2(600, 430));
    ImGui::Button("ADD", ImVec2(130 - 15, 30));
    ImGui::PopStyleVar();
}
