//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"
#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands

// your code goes here 



// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn): document(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}


// Insert text at a given position
void ECTextDocumentCtrl::InsertTextAt(int pos, const std::vector<char> &listCharsToIns) 
{
    ECInsertCommand *cmd = new ECInsertCommand(document, pos, listCharsToIns);
    cmd->Execute(); // Execute the insert command
    commandHistory.ExecuteCmd(cmd); // Store command in history
}

// Remove text at a given position
void ECTextDocumentCtrl::RemoveTextAt(int pos, int lenToRemove) 
{
    ECRemoveCommand *cmd = new ECRemoveCommand(document, pos, lenToRemove);
    cmd->Execute(); // Execute the remove command
    commandHistory.ExecuteCmd(cmd); // Store command in history
}

// Capitalize text at a given position
void ECTextDocumentCtrl::CapTextAt(int pos, int lenToCap) 
{
    ECCapitalizeCommand *cmd = new ECCapitalizeCommand(document, pos, lenToCap);
    cmd->Execute(); // Execute the capitalize command
    commandHistory.ExecuteCmd(cmd); // Store command in history
}

// Lowercase text at a given position
void ECTextDocumentCtrl::LowerTextAt(int pos, int lenToLower) 
{
    ECLowercaseCommand *cmd = new ECLowercaseCommand(document, pos, lenToLower);
    cmd->Execute(); // Execute the lowercase command
    commandHistory.ExecuteCmd(cmd); // Store command in history
}

// Undo last action
bool ECTextDocumentCtrl::Undo() 
{
    return commandHistory.Undo(); // Call undo in command history
}

// Redo last undone action
bool ECTextDocumentCtrl::Redo() 
{
    return commandHistory.Redo(); // Call redo in command history
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() : docCtrl(*this)
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
  return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
  return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  // your code here
  listChars.insert(listChars.begin() + pos, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  // your code here
  listChars.erase(listChars.begin() + pos);
}

void ECTextDocument :: CapCharAt(int pos)
{
  // your code here
  if (pos < listChars.size()) 
  {
    listChars[pos] = toupper(listChars[pos]);
  }
}

void ECTextDocument :: LowerCharAt(int pos)
{
  // your code here
  if (pos < listChars.size()) 
  {
    listChars[pos] = tolower(listChars[pos]);
  }
}

