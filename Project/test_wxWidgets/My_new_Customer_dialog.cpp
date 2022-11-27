#include "My_new_Customer_dialog.hpp"

My_new_Customer_dialog::My_new_Customer_dialog(wxWindow *parent, wxWindowID id, const wxString &title)
	// ,
	//                            const wxPoint & position, const wxSize & size, long style )
	: wxDialog(parent, id, title) //, position, size, style)
{
	auto text_customer_number = new wxStaticText(this, -1, "Customer Number: ", wxPoint(10, 20), wxSize(180, 20));
	auto text_name = new wxStaticText(this, -1, "Name : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_account_numbers = new wxStaticText(this, -1, "Account Numbers: ", wxPoint(10, 80), wxSize(180, 20));

	// int my_value;
	// wxIntegerValidator<int> val(&my_value, wxNUM_VAL_THOUSANDS_SEPARATOR);
	// val.SetRange(0, 100); // set allowable range
	// auto edit_customer_number = new wxTextCtrl(panel,
	//                                            static_cast<int>(My_class_client::ID_Customer_number),
	//                                            "0",
	//                                            wxPoint(200, 20), wxSize(100, 20),
	//                                            wxTEXT_ALIGNMENT_CENTER,
	//                                            val);
	edit_customer_number_ = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_name_ = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_account_numbers_ = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));


	wxButton *b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 120), wxDefaultSize);
	wxButton *c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 120), wxDefaultSize);
	// ShowModal();
}

wxString My_new_Customer_dialog::get_customer_number(){
	return edit_customer_number_->GetValue();
}

wxString My_new_Customer_dialog::get_name(){
	return edit_name_->GetValue();
}

wxString My_new_Customer_dialog::get_account_numbers(){
	return edit_account_numbers_->GetValue();
}