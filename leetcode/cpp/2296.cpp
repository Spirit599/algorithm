class TextEditor {
public:
    string str;
    int curIndex = 0;
    TextEditor() {

    }
    
    void addText(string text) {

        // string left = str.substr(0, curIndex);
        // string right = str.substr(curIndex);
        // str = left + text + right;
        str.insert(curIndex, text);
        curIndex += text.size();
        // cout<<str<<endl;
    }
    
    int deleteText(int k) {

        int ret = min(k, curIndex);
        // string left = str.substr(0, curIndex - ret);
        // string right = str.substr(curIndex);
        // str = left + right;
        curIndex -= ret;
        str.erase(curIndex, ret);
        // cout<<str<<endl;
        return ret;
    }
    
    string cursorLeft(int k) {

        curIndex = max(curIndex - k, 0);
        int len = min(curIndex, 10);
        return str.substr(curIndex - len, len);
    }
    
    string cursorRight(int k) {

        curIndex = min(curIndex + k, (int)str.size());
        int len = min(curIndex, 10);
        return str.substr(curIndex - len, len);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */