#include "Customer_for_JSON.hpp"
#include "example_of_use.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    // SetTopWindow(frame);

    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(static_cast<int>(My_class_client::ID_Add_Customer), "&Add_Customer...\tCtrl-A",
                     "Add a customer");
    menuFile->AppendSeparator();
    menuFile->Append(static_cast<int>(My_class_client::ID_Customers_save), "&Save all customers...\tCtrl-S",
                     "Save customers");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Customers Management");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");

    Bind(wxEVT_MENU, &MyFrame::OnAdd_Customer, this, static_cast<int>(My_class_client::ID_Add_Customer)); // My_class_client::ID_Add_Customer
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnSaveCustomers, this, static_cast<int>(My_class_client::ID_Customers_save));
}

void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets demonstration for client management",
                 "About Client Management", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnAdd_Customer(wxCommandEvent &event)
{

    auto new_customer = new My_new_Customer_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_customer->ShowModal() == wxID_OK)
    {
        auto customer_number = new_customer->get_customer_number();
        auto customer_name = new_customer->get_name();
        auto customer_account_numbers = new_customer->get_account_numbers();



        long number;

        long account_numbers; // Only one at this time

        if (!customer_number.ToLong(&number))
        {
            wxMessageBox("Error number",
                         "Error ", wxOK | wxICON_INFORMATION);
            return;
        }

        if (!customer_number.ToLong(&account_numbers))
        {
            wxMessageBox("Account numbers",
                         "Error ", wxOK | wxICON_INFORMATION);
            return;
        }

        std::string name = std::string(customer_name);
        Customer customer(number, std::move(name), {1000});
        customers_.push_back(customer);
    }
}

void MyFrame::OnSaveCustomers(wxCommandEvent &event)
{
    ptree pt_write;
    ptree pt_accounts;
    try
    {
        for (auto &customer : customers_)
        {
            pt_accounts.push_back({"", get_a_ptree_from_a_customer(customer)});
                    wxMessageBox(customer.name_, "test", wxOK | wxICON_INFORMATION);
        }
        pt_write.add_child("Customers", pt_accounts);
        std::ofstream file_out("example_write_read.json");
        write_json(file_out, pt_write);
        file_out.close();
    }
    catch (std::exception &e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}
