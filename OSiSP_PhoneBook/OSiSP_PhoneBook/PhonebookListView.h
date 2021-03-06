#pragma once

#include "ListView.h"
#include "PhoneDataBase.h"
#include <vector>

enum class SEARCH_TYPE
{
	SURNAME,
	TELEPHONE,
	STREET
};

class PhonebookListView
{
public:
	PhonebookListView(int X, int Y, int nWidth, int nHeight, HWND hWndParent, int listViewIdentifier, HINSTANCE hInst, RECT windowRect);
	void ChangeSize(int newWidth, int newHeight);
	void Refresh(bool isSearchRefresh = false);
	void SearchAndRefresh(SEARCH_TYPE searchType, LPTSTR searchKey);
	PhoneBookNode *GetSelectedItem();
	void SaveEditedPhoneBookNode(PhoneBookNode *value);

	void EditSelectedRow();
	void EndEditSelectedRow();
	~PhonebookListView();

private:	
	//methods

	void InitListLiew(bool isRefresh = false);	
	void InitPhoneBookList();

	//fields

	ListView *listViewPhonebook;
	double ratioX;
	double ratioY;
	double ratioNWidth;
	double ratioNHeight;
	PhoneDataBase *phoneDataBase;
	std::vector<PhoneBookNode*>* phoneBookList;

};

