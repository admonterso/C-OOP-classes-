#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

// return true if word is an identifier, otherwise return false
bool isIdent(string word)
{
        int len=word.size();
        bool isid=!isdigit(word[0]);
        for(int j=0;j<len && isid;j++) if (!isalnum(word[j]) && word[j]!='_')  isid = false;
        return isid;
}

class Scanner {
private:
        string line;
        string comment;
        string before_comment;
        string result;
        int comment_pos;
public:
        bool ReadLine(istream& in) { getline(in, line); return !in.eof(); }
        void PrintLine(ostream& out) { out << line << endl; }
        // identify the part within a comment, and the part which is before the comment
        Scanner& SplitLine() {
                comment_pos = line.find("//");
                if (comment_pos >= 0) {
                comment = line.substr(comment_pos);
                before_comment=line.substr(0,comment_pos);
                } // otherwise comment_pos = std::string::npos = -1
                else { comment = ""; before_comment = line; }
                return *this;
        }
        // transform the part "before_comment", in such a way that any non-identifier is removed,
	// BUT the rest (including whitespaces) is left
        Scanner& Transform()
	// begin: part 1, You are allowed to change the code ONLY between the brackets {} below
	{
    istringstream iss(before_comment);
    string word;
    result = "";
    bool first_word = true;
    while (iss >> word) {
        // check if the word is an identifier
        if (isIdent(word)) {
            // add a space before the word if it's not the first word in the result
            if (!first_word) {
                result += " ";
            }
            result += word;
            first_word = false;
        }
    }
    // add a space at the end of the result if there is at least one identifier
    if (!first_word) {
        result += " ";
    }
    return *this;
    }


	
	// end: part 1
        void Print(ostream& out) { cout << ">" << result << comment << endl; }
};

int main()
{
        Scanner info;
        while (info.ReadLine(cin))
        {
                info.SplitLine().Transform().Print(cout);
        }

}