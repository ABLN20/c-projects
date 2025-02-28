//
//  ECCommand.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECCommand_h
#define ECCommand_h
class ECTextDocument; // Forward declaration

#include <vector>

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Command to insert text
class ECInsertCommand : public ECCommand
{
public:
    ECInsertCommand(ECTextDocument &doc, int pos, const std::vector<char> &chars);
    void Execute() override;         // Execute the insert command
    void UnExecute() override;       // Undo the insert command

private:
    ECTextDocument &document;
    int position;
    std::vector<char> insertedChars;
};

// ******************************************************
// Command to remove text
class ECRemoveCommand : public ECCommand
{
public:
    ECRemoveCommand(ECTextDocument &doc, int pos, int len);
    void Execute() override;         // Execute the remove command
    void UnExecute() override;       // Undo the remove command

private:
    ECTextDocument &document;
    int position;
    int length;
    std::vector<char> removedChars; // Store removed characters to restore them
};

// ******************************************************
// Command to capitalize text
class ECCapitalizeCommand : public ECCommand
{
public:
    ECCapitalizeCommand(ECTextDocument &doc, int pos, int len);
    void Execute() override;         // Execute the capitalize command
    void UnExecute() override;       // Undo the capitalize command

private:
    ECTextDocument &document;
    int position;
    int length;
    std::vector<char> originalChars; // Store original characters to restore them
};

// ******************************************************
// Command to lowercase text
class ECLowercaseCommand : public ECCommand
{
public:
    ECLowercaseCommand(ECTextDocument &doc, int pos, int len);
    void Execute() override;         // Execute the lowercase command
    void UnExecute() override;       // Undo the lowercase command

private:
    ECTextDocument &document;
    int position;
    int length;
    std::vector<char> originalChars; // Store original characters to restore them
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory();
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    // your code goes here
    std::vector<ECCommand*> undoList; // List of executed commands for undo
    std::vector<ECCommand*> redoList; // List of undone commands for redo
};


#endif /* ECCommand_h */
