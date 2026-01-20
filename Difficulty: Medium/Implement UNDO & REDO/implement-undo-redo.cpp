class Solution {
  private:
    string doc;
    stack<char> undoStack;
    stack<char> redoStack;

  public:
    void append(char x) {
        doc.push_back(x);
        undoStack.push(x);
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            char last = undoStack.top();
            undoStack.pop();
            doc.pop_back();
            redoStack.push(last);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            char ch = redoStack.top();
            redoStack.pop();
            doc.push_back(ch);
            undoStack.push(ch);
        }
    }

    string read() {
        return doc;
    }
};
