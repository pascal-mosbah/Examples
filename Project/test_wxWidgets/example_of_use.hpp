#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Customer.hpp"
#include "My_new_Customer_dialog.hpp"

class MyFrame_Add_Customer : public wxFrame
{
public:
    MyFrame_Add_Customer();

private:
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnAdd_Customer(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSaveCustomers(wxCommandEvent &event);

    std::vector<Customer> customers_;
};

enum class My_class_client : int
{
    ID_Add_Customer = 1,
    ID_Customer_field = 2,
    ID_Customers_save = 3
};
