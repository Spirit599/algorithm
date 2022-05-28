class Solution {
public:
    /**
     * @param letters: A string
     * @return: A string
     */
    string lowercaseToUppercase2(string &letters) {
        
        transform(letters.begin(), letters.end(), letters.begin(), ::toupper);
        return letters;
    }
};