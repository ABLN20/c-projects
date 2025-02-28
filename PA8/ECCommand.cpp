//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"
#include "ECTextDocument.h"
// ******************************************************
// Implement insert command

ECInsertCommand::ECInsertCommand(ECTextDocument &doc, int pos, const std::vector<char> &chars)
    : document(doc), position(pos), insertedChars(chars) {}

void ECInsertCommand::Execute() 
{
    for (char ch : insertedChars) {
        document.InsertCharAt(position++, ch); // Insert each character at the given position
    }
}

void ECInsertCommand::UnExecute() 
{
    for (int i = insertedChars.size() - 1; i >= 0; --i) {
        document.RemoveCharAt(position - 1); // Remove the last inserted character
    }
}

// ******************************************************
// Implement remove command

ECRemoveCommand::ECRemoveCommand(ECTextDocument &doc, int pos, int len)
    : document(doc), position(pos), length(len) 
{
    // Store the removed characters for undo
    for (int i = 0; i < length; ++i) {
        removedChars.push_back(document.GetCharAt(position)); // Store each character
    }
}

void ECRemoveCommand::Execute() 
{
    for (int i = 0; i < length; ++i) {
        document.RemoveCharAt(position); // Remove characters starting at position
    }
}

void ECRemoveCommand::UnExecute() 
{
    for (char ch : removedChars) {
        document.InsertCharAt(position++, ch); // Restore removed characters
    }
}

// ******************************************************
// Implement capitalize command

ECCapitalizeCommand::ECCapitalizeCommand(ECTextDocument &doc, int pos, int len)
    : document(doc), position(pos), length(len) 
{
    // Store original characters for undo
    for (int i = 0; i < length; ++i) {
        originalChars.push_back(document.GetCharAt(position + i)); // Store each character
    }
}

void ECCapitalizeCommand::Execute() 
{
    for (int i = 0; i < length; ++i) {
        document.CapCharAt(position + i); // Capitalize characters
    }
}

void ECCapitalizeCommand::UnExecute() 
{
    for (int i = 0; i < length; ++i) {
        document.LowerCharAt(position + i); // Restore original characters to lowercase
    }
}

// ******************************************************
// Implement lowercase command

ECLowercaseCommand::ECLowercaseCommand(ECTextDocument &doc, int pos, int len)
    : document(doc), position(pos), length(len) 
{
    // Store original characters for undo
    for (int i = 0; i < length; ++i) {
        originalChars.push_back(document.GetCharAt(position + i)); // Store each character
    }
}

void ECLowercaseCommand::Execute() 
{
    for (int i = 0; i < length; ++i) {
        document.LowerCharAt(position + i); // Lowercase characters
    }
}

void ECLowercaseCommand::UnExecute() 
{
    for (int i = 0; i < length; ++i) {
        document.CapCharAt(position + i); // Restore original characters to uppercase
    }
}

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
  // your code goes here
}

ECCommandHistory :: ~ECCommandHistory()
{
{
  // Cleanup: delete all commands in undo and redo lists
  for (auto cmd : undoList) {
    delete cmd; // Free memory for each command in undoList
  }
  for (auto cmd : redoList) {
    delete cmd; // Free memory for each command in redoList
  }
}
}

void ECCommandHistory::ExecuteCmd(ECCommand *pCmd) 
{
    if (pCmd) 
    {
        undoList.push_back(pCmd); // Store in undo history
    }
}

bool ECCommandHistory::Undo() 
{
    if (undoList.empty())
        return false; // Nothing to undo

    auto cmd = undoList.back(); // Get the last command
    cmd->UnExecute(); // Undo the command
    redoList.push_back(cmd); // Add to redo history
    undoList.pop_back(); // Remove from undo history
    return true; // Undo was successful
}

bool ECCommandHistory::Redo() 
{
    if (redoList.empty())
        return false; // Nothing to redo

    auto cmd = redoList.back(); // Get the last undone command
    cmd->Execute(); // Re-execute the command
    undoList.push_back(cmd); // Add back to undo history
    redoList.pop_back(); // Remove from redo history
    return true; // Redo was successful
}