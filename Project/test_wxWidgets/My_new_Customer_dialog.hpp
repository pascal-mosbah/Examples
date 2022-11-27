#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Customer.hpp"

class My_new_Customer_dialog: public wxDialog
{
public:

	My_new_Customer_dialog ( wxWindow * parent, wxWindowID id, const wxString & title);
 
	wxString get_customer_number();
	wxString get_name();
	wxString get_account_numbers();

private:

	void OnOk( wxCommandEvent & event );
	wxTextCtrl *edit_customer_number_;
	wxTextCtrl *edit_name_;
	wxTextCtrl *edit_account_numbers_;
};