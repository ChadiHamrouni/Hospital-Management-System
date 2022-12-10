#include"imgui.h"
#include "imgui_internal.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"
#include<iostream>
#include <GLFW/glfw3.h>
#include "../myApp.h"
#include "../header/patient.h"
#include "../header/department.h"
#include "../header/person.h"
int main()
{
	int Tab = 0;
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "ImGui + GLFW", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
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
	//ImFont* mainfont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Calibri.ttf", 15.5f);
	//IM_ASSERT(mainfont != NULL);
	io.Fonts->AddFontDefault();

	//Window Initialization
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	// Person Dummy Data
	Person per1("361-106", "Fadhila Labyedh", "+216 22 225 849");
	Person per2("958-063", "Beji The Matrix", "+216 97 609 765");
	// Patient Dummy Data
	Patient p1("PT516-151", "John Sbou3i", "+216 22 225 849");
	Patient p2("PT396-213", "Ameni Labyedh ", "+216 59 259 745");
	// Doctor Dummy Data
	Doctor doc1("DR159-155", "Slimen Labyedh", "59 256 379", "Heart Surgery", "Vacation", "Austin, Texas 194 Block", "10 years");
	Doctor doc2("DR256-046", "Mariem Bouchoucha", "64 456 572", "Neurology", "Working", "Houston, 254 Block B", "25 years");
	// Department Dummy Data
	Department d1("Surgery", "56%", "9 Rooms");
	Department d2("Neurology", "20%", "3 Rooms");

	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(500, 300));

		if (ImGui::Begin("Login", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
			ImGui::Text("Username >");
			ImGui::Spacing();
			ImGui::Spacing();
			static char usuariotext[128] = "";
			ImGui::InputText(" ", usuariotext, IM_ARRAYSIZE(usuariotext));
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
			ImGui::Text("Password >");
			ImGui::Spacing();
			ImGui::Spacing();
			static char senhatext[128] = "";
			ImGui::InputTextWithHint("  ", "", senhatext, IM_ARRAYSIZE(senhatext), ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			//ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(213, 56, 105, 255));
			ImGui::Button("Login");
			//ImGui::PopStyleColor();

		}ImGui::End();
				
			if (ImGui::Begin("Menu")) {
				ImGui::SetNextWindowSize(ImVec2(1500, 300));
					ImGui::Dummy(ImVec2(0.0f, 15.0f));
					if (ImGui::Button(" Account", ImVec2(230 - 15, 41)))		
						Tab = 1;					
					ImGui::Dummy(ImVec2(0.0f, 40.0f));
					if (ImGui::Button(" Patients", ImVec2(230 - 15, 41)))
						Tab = 2;
					ImGui::Dummy(ImVec2(0.0f, 40.0f));
					if (ImGui::Button(" Doctors", ImVec2(230 - 15, 41)))
						Tab = 3;
					ImGui::Dummy(ImVec2(0.0f, 40.0f));
					if (ImGui::Button(" Departments", ImVec2(230 - 15, 41)))
						Tab = 4;
					ImGui::Dummy(ImVec2(0.0f, 40.0f));
					if (ImGui::Button(" Archives", ImVec2(230 - 15, 41)))
						Tab = 5;
					ImGui::Dummy(ImVec2(0.0f, 20.0f));
					if (Tab == 1) {
						ImGui::SetCursorPos(ImVec2(240, 38));
						if (ImGui::BeginTable("table1", 3))
						{
							ImGui::Separator();
							ImGui::TableNextRow();
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("ID");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("FULL NAME");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("PHONE NUMBER");
							ImGui::Separator();
							myApp::Patients(p2);

						}ImGui::EndTable();
					}
					else if (Tab == 2) {
						ImGui::SetCursorPos(ImVec2(240, 38));
						if (ImGui::BeginTable("table1", 3))
						{
							ImGui::Separator();
							ImGui::TableNextRow();
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("ID");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("FULL NAME");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("PHONE NUMBER");
							ImGui::Separator();
							myApp::Patients(p1);

						}ImGui::EndTable();
					}
					else if (Tab == 3) {
						ImGui::SetCursorPos(ImVec2(240, 38));
						if (ImGui::BeginTable("table1", 7))						
						{
								ImGui::Separator();
								ImGui::TableNextRow();
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("ID");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("FULL NAME");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("PHONE NUMBER");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("DEPARTMENT");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("STATUS");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("ADDRESS");
								ImGui::Separator();
								ImGui::TableNextColumn();
								ImGui::Separator();
								ImGui::Text("QUALIFICATION");
								ImGui::Separator();
								myApp::Doctors(doc1);
								myApp::Doctors(doc2);
						}ImGui::EndTable();						
					}
					else if (Tab == 4) {
						ImGui::SetCursorPos(ImVec2(240, 38));
						if (ImGui::BeginTable("table1", 3))
						{
							ImGui::Separator();
							ImGui::TableNextRow();
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("NAME");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("LOAD");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("FACILITIES");
							ImGui::Separator();
							myApp::Departments(d1);
							myApp::Departments(d2);

						}ImGui::EndTable();
					}
					else {
						ImGui::SetCursorPos(ImVec2(240, 38));
						if (ImGui::BeginTable("table1", 3))
						{
							ImGui::Separator();
							ImGui::TableNextRow();
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("ID");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("FULL NAME");
							ImGui::Separator();
							ImGui::TableNextColumn();
							ImGui::Separator();
							ImGui::Text("PHONE NUMBER");
							ImGui::Separator();
							myApp::Archives(per1);
							myApp::Archives(per2);

						}ImGui::EndTable();
					}
			}ImGui::End();

		//ImGui::ArrowButton("##right", ImGuiDir_Right);
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

