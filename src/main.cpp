#include<iostream>
#include <GLFW/glfw3.h>
#include"imgui_impl_opengl3.h"
#include"imgui_impl_glfw.h"
#include"imgui.h"
#include "implot.h"
#include "implot_internal.h"
#include "../header/patient.h"
#include "../header/doctor.h"
#include "../header/admin.h"
#include "../header/icons.h"

int main() {
	//Initialize Tab selection
	int Tab = 1;
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "ImGui + GLFW", NULL, NULL);

	// Error check if the window fails to create
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	// Initialize ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	//Setting up a new font
	ImFont* mainfont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\ARLRDBD.ttf", 16.9f);
	IM_ASSERT(mainfont != NULL);

	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
	ImFontConfig icons_config;
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	io.Fonts->AddFontFromFileTTF("../Hospital Management/fonts/fa-solid-900.ttf"
		, 16.f, &icons_config, icons_ranges);
	io.Fonts->AddFontDefault();
	ImFont* dash = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\ARLRDBD.ttf", 60);
	
	ImFont* d = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\ARLRDBD.ttf", 18);

	//Window Initialization
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	//Dummy Data
	Patient p1("PT361-106", "Beji The Matrix", "22 225 849", 9, 22, "Male", "Doha 24 Street", "Milan", "10/21/2022", "Mariem Bouaj", "ED", "ED Depart");
	Patient p2("PT159-155", "Slimen Labyedh", "59 256 379", 2, 40, "Male", "Tex 194 Block", "Tunis", "8/10/2022", "Ahmed Selsel", "ED", "ED Depart");
	Patient p3("PT256-046", "Mariem Bouchoucha", "64 456 572", 5, 35, "Female", "25 Block B", "Tunis", "7/15/2022", "Slimen Labyedh", "ED", "ED Depart");
	Person per1("361-106", "Fadhila Labyedh", "22 225 849");
	Person per2("958-063", "Jack Jones", "97 609 765");
	Person per3("396-213", "Ameni Labyedh ", "59 259 745");
	Doctor doc1("DR159-155", "Slimen Labyedh", "Heart Surgery", "Vacation");
	Doctor doc2("DR291-567", "Ahmed Selsel", "Cardiovascular", "Working");
	Admin ad("Ad191-158", "Slim Jim", "58 648 612", "Slim231", "Slimjim123");

	while (!glfwWindowShouldClose(window)) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGuiStyle& style = ImGui::GetStyle();
		style.FramePadding = ImVec2(5, 5);	

		style.Colors[ImGuiCol_TitleBg] = ImColor(4, 135, 156, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(4, 135, 156, 255);
		style.Colors[ImGuiCol_Tab] = ImColor(4, 135, 156, 255);
		style.Colors[ImGuiCol_TabActive] = ImColor(12, 60, 120, 255);
		style.Colors[ImGuiCol_TabHovered] = ImColor(12, 60, 120, 255);
		style.Colors[ImGuiCol_Button] = ImColor(4, 135, 156, 255);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(12, 60, 120, 255);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(12, 60, 120, 255);
		style.Colors[ImGuiCol_Separator] = ImVec4(5.0f, 50.0f, 60.0f, 1.0f);
					
		static ImVec4 active = ImColor(12, 60, 120, 255);
		static ImVec4 inactive = ImColor(4, 135, 156, 255);
		static ImVec4 blue = ImColor(4, 135, 156, 255);
		static ImVec4 darker_blue = ImColor(4, 57, 121, 255);

		static ImVec4 dark_blue = ImColor(67, 64, 64, 255);		
		ImU32 cell_bg_color = ImColor(dark_blue);

		static ImVec4 green = ImColor(21, 98, 21, 255);
		ImU32 green_bg = ImColor(green);

		static ImVec4 red = ImColor(127, 4, 38, 255);
		ImU32 red_bg = ImColor(red);
		
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		if (ImGui::Begin("Hospital Management System", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
			ImGui::SetCursorPos(ImVec2(15, 70));			
			ImGui::BeginChild("left pane", ImVec2(230, 0));
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3);
			ImGui::PushStyleColor(ImGuiCol_Button, Tab == 1 ? active : inactive);
				if (ImGui::Button(ICON_FA_CHART_PIE"  Dashboard", ImVec2(230 - 15, 51)))
					Tab = 1;
								
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 2 ? active : inactive);
				if (ImGui::Button(ICON_FA_ADDRESS_BOOK"  Appointments", ImVec2(230 - 15, 51)))								
					Tab = 2;
										
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 3 ? active : inactive);
				if (ImGui::Button(ICON_FA_USER_DOCTOR"  Doctors", ImVec2(230 - 15, 51)))
					Tab = 3;
	
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 4 ? active : inactive);
				if (ImGui::Button(ICON_FA_USER_SHIELD"  Patients", ImVec2(230 - 15, 51)))
					Tab = 4;
													
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 5 ? active : inactive);
				if (ImGui::Button(ICON_FA_FOLDER_OPEN"  Archives", ImVec2(230 - 15, 51)))
					Tab = 5;
			
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 6 ? active : inactive);
				if (ImGui::Button(ICON_FA_USER"  Profile", ImVec2(230 - 15, 51)))
					Tab = 6;
				
				ImGui::Dummy(ImVec2(0, 25));
				ImGui::PushStyleColor(ImGuiCol_Button, Tab == 7 ? active : inactive);
				if (ImGui::Button(ICON_FA_GEAR"  Settings", ImVec2(230 - 15, 51)))
					Tab = 7;

				ImGui::PopStyleVar();
				ImGui::PopStyleColor(7);
				ImGui::EndChild();
					
				if (Tab == 1) {					
					ImPlot::CreateContext();
					static const char* labels1[] = { "COPD","CRE","AFM","LGV"  };
					static float data1[] = { 0.15f,  0.30f,  0.2f, 0.05f };
					static ImPlotPieChartFlags flags = 0;
					
					if ((data1[0] + data1[1] + data1[2] + data1[3]) < 1){
						ImGui::SameLine();
					}
					
					ImGui::SetCursorPos(ImVec2(310, 420));
					if (ImPlot::BeginPlot("##Pie1", ImVec2(200, 200), ImPlotFlags_Equal | ImPlotFlags_NoMouseText)) {
						ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
						ImPlot::SetupAxesLimits(0, 1, 0, 1);
						ImPlot::PlotPieChart(labels1, data1, 4, 0.5, 0.5, 0.4, "%.2f", 180, flags);
						ImPlot::EndPlot();
					}

					static const char* labels2[] = { "Interns","Visitors","Officials","Trainees","New Staff" };
					static int data2[] = { 1,1,2,3,6 };

					ImPlot::PushColormap(ImPlotColormap_Pastel);
					ImGui::SetCursorPos(ImVec2(600, 420));
					if (ImPlot::BeginPlot("##Pie2", ImVec2(200, 200), ImPlotFlags_Equal | ImPlotFlags_NoMouseText)) {
						ImPlot::SetupAxes(NULL, NULL, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
						ImPlot::SetupAxesLimits(0, 1, 0, 1);
						ImPlot::PlotPieChart(labels2, data2, 5, 0.5, 0.5, 0.4, "%.0f", 180, flags);
						ImPlot::EndPlot();
					}
					ImPlot::PopColormap();
				
					struct ScrollingBuffer{
						int MaxSize;
						int Offset;
						ImVector<ImVec2> Data;
						ScrollingBuffer(int max_size = 2000){
							MaxSize = max_size;
							Offset = 0;
							Data.reserve(MaxSize);
					}

						void AddPoint(float x, float y){
							if (Data.size() < MaxSize)
								Data.push_back(ImVec2(x, y));
							else{
								Data[Offset] = ImVec2(x, y);
								Offset = (Offset + 1) % MaxSize;
								}
						}

						void Erase(){						
							if (Data.size() > 0){
								Data.shrink(0);
								Offset = 0;
							}
						}

					};
					struct RollingBuffer{
						float Span;
						ImVector<ImVec2> Data;
						RollingBuffer() {
							Span = 10.0f;
							Data.reserve(2000);
						}
						void AddPoint(float x, float y) {
							float xmod = fmodf(x, Span);
							if (!Data.empty() && xmod < Data.back().x)
								Data.shrink(0);
							Data.push_back(ImVec2(xmod, y));
						}
					};
					static ScrollingBuffer sdata1, sdata2;
					static RollingBuffer rdata1, rdata2;
					ImVec2 mouse = ImGui::GetMousePos();
					static float t = 0;
					t += ImGui::GetIO().DeltaTime;
					sdata1.AddPoint(t, mouse.x * 0.0005f);
					rdata1.AddPoint(t, mouse.x * 0.0005f);
					sdata2.AddPoint(t, mouse.y * 0.0005f);
					rdata2.AddPoint(t, mouse.y * 0.0005f); 
					static float history = 10.0f;			
					rdata1.Span = history;
					rdata2.Span = history;

					ImGui::SetCursorPos(ImVec2(885, 420));
					if (ImPlot::BeginPlot("##Scrolling", ImVec2(822, 200))){
						ImPlot::SetupAxes(NULL, NULL, flags, flags);
						ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
						ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
						ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL, 0.5f);
						ImPlot::PlotShaded("Mouse X", &sdata1.Data[0].x, &sdata1.Data[0].y, sdata1.Data.size(), -INFINITY, 0, sdata1.Offset, 2 * sizeof(float));
						ImPlot::PlotLine("Mouse Y", &sdata2.Data[0].x, &sdata2.Data[0].y, sdata2.Data.size(), 0, sdata2.Offset, 2 * sizeof(float));
						ImPlot::EndPlot();
					}

					ImGui::SetCursorPos(ImVec2(310, 670));
					if (ImPlot::BeginPlot("##Rolling", ImVec2(1400, 300))){
						ImPlot::SetupAxes(NULL, NULL, flags, flags);
						ImPlot::SetupAxisLimits(ImAxis_X1, 0, history, ImGuiCond_Always);
						ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
						ImPlot::PlotLine("Mouse X", &rdata1.Data[0].x, &rdata1.Data[0].y, rdata1.Data.size(), 0, 0, 2 * sizeof(float));
						ImPlot::PlotLine("Mouse Y", &rdata2.Data[0].x, &rdata2.Data[0].y, rdata2.Data.size(), 0, 0, 2 * sizeof(float));
						ImPlot::EndPlot();
					}
					ImPlot::DestroyContext();
					ad.dashBoardStats(dash);														
				}
				else if (Tab == 2){
					ImGui::SetCursorPos(ImVec2(250, 38));
					if (ImGui::BeginTabBar("Appointments"))
					{
						if (ImGui::BeginTabItem("Latest")){						
							ad.latestAppointment();				
							ImGui::EndTabItem();
							ad.search();
						}

						if (ImGui::BeginTabItem("Future")) {
							ad.futureAppointments();							
							ImGui::EndTabItem();
							ad.search();
						}
						ImGui::EndTabBar();
					}
				}
				else if (Tab == 3) {
					ImGui::SetCursorPos(ImVec2(250, 38));
					if (ImGui::BeginTabBar("Doctors"))
					{						
						if (ImGui::BeginTabItem("Current On Call Doctors")) {		
							ImGui::PushFont(d);
							ad.currentOnCallDoctors(doc1);
							ImGui::PopFont();
							ImGui::EndTabItem();
							ad.search();										
						}

						if (ImGui::BeginTabItem("Current Regular Doctors")) {
							ad.currentRegularDoctors(doc2);
							ImGui::EndTabItem();
							ad.search();
						}

						if (ImGui::BeginTabItem("Add a Doctor")) {
							ad.addDoctorForm();
							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Doctor Requests")) {
							ImGui::SetCursorPos(ImVec2(250, 125));
							if (ImGui::BeginTable("Requests Table", 4, ImGuiTableFlags_Borders)) {								
								ad.doctorRequestHeader();
								for (int i = 0; i < 15; i++) {
									ad.doctorRequest();
								}
							}ImGui::EndTable();
							ad.search();
							ImGui::EndTabItem();
						}
						ImGui::EndTabBar();
					}
				}
				else if (Tab == 4) {
					ImGui::SetCursorPos(ImVec2(250, 38));			
					if (ImGui::BeginTabBar("Patients"))
					{
						if (ImGui::BeginTabItem("Current Patients")) {						
							ImGui::SetCursorPos(ImVec2(250, 125));
								if (ImGui::BeginTable("Current Patient Table", 12, ImGuiTableFlags_Borders)) {
									p1.patientHeader();
									for (int i = 0; i < 6; i++) {
										p1.patientList(p1);
										p2.patientList(p2);
										p3.patientList(p3);
									}	
								}ImGui::EndTable();
							ImGui::EndTabItem();
							ad.search();
						}
						
						if (ImGui::BeginTabItem("Pre-Discharged Patients")) {
							ImGui::SetCursorPos(ImVec2(250, 125));
							if (ImGui::BeginTable("Patients Table", 12, ImGuiTableFlags_Borders)) {
								p1.patientHeader();
								for (int i = 0; i < 10; i++) {
									p1.patientList(p1);
									p2.patientList(p2);
									p3.patientList(p3);
								}
							}ImGui::EndTable();
							ImGui::EndTabItem();
							ad.search();							
						}	

					if (ImGui::BeginTabItem("Patient Requests")) {
						ImGui::SetCursorPos(ImVec2(250, 125));

						if (ImGui::BeginTable("Request Table", 4, ImGuiTableFlags_Borders)) {						
							ad.doctorRequestHeader();
							for (int i = 0; i < 15; i++) {
								ad.doctorRequest();
							}
						}ImGui::EndTable();						
						ad.search();
						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Add Patient")) {
						ad.addPatientForm();
						ImGui::EndTabItem();
					}

					}ImGui::EndTabBar();					
				}
				else if (Tab == 5) {
					ImGui::SetCursorPos(ImVec2(250, 38));
					if (ImGui::BeginTabBar("Archives"))
					{
						if (ImGui::BeginTabItem("Doctors")) {
							ImGui::SetCursorPos(ImVec2(250, 125));

							if (ImGui::BeginTable("Doctors Table", 3, ImGuiTableFlags_Borders)) {
								ad.displayArchivesHeader();
								for (int i = 0; i < 8; i++) {
									per1.archives(per1);
									per2.archives(per2);
									per3.archives(per3);
								}
							}ImGui::EndTable();							
							ImGui::EndTabItem();
						}

						if (ImGui::BeginTabItem("Staff")) {
							ImGui::SetCursorPos(ImVec2(250, 125));

							if (ImGui::BeginTable("Staff Table", 3, ImGuiTableFlags_Borders)) {
								ad.displayArchivesHeader();
								for (int i = 0; i < 7; i++) {
									per1.archives(per1);
									per2.archives(per2);
									per3.archives(per3);
								}
							}ImGui::EndTable();
							ImGui::EndTabItem();					
						}

						if (ImGui::BeginTabItem("Nurses")) {
							ImGui::SetCursorPos(ImVec2(250, 125));
							if (ImGui::BeginTable("Nurses Table", 3, ImGuiTableFlags_Borders)) {
								ad.displayArchivesHeader();
								for (int i = 0; i < 10; i++) {
									per1.archives(per1);
									per2.archives(per2);
									per3.archives(per3);
								}
							}ImGui::EndTable();
							ImGui::EndTabItem();							
						}
						ImGui::EndTabBar();
						ad.search();
					}
				}
				else if (Tab == 6) {
					ad.displayProfile();
				}			
				else if (Tab == 7) {
					ad.displaySettings(io);
				}
			}ImGui::End();	
			
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			glfwSwapBuffers(window);
			// Take care of all GLFW events
			glfwPollEvents();
		}
		// Deletes all ImGUI instances+;
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		// Delete window before ending the program
		glfwDestroyWindow(window);
		// Terminate GLFW before ending the program
		glfwTerminate();
		return 0;
}
