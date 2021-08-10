#include <iostream>
#include <string>

using namespace std;
typedef enum { False, True } boolean;

string texttomorse(char text){
    switch(text){
        case 'A':return ".-"; break;
        case 'B':return "-..."; break;
        case 'C':return "-.-."; break;
        case 'D':return "-.."; break;
        case 'E':return "."; break;
        case 'F':return "..-."; break;
        case 'G':return "--."; break;
        case 'H':return "...."; break;
        case 'I':return ".."; break;
        case 'J':return ".---"; break;
        case 'K':return "-.-"; break;
        case 'L':return ".-.."; break;
        case 'M':return "--"; break;
        case 'N':return "-."; break;
        case 'O':return "---"; break;
        case 'P':return ".--."; break;
        case 'Q':return "--.-"; break;
        case 'R':return ".-."; break;
        case 'S':return "..."; break;
        case 'T':return "-"; break;
        case 'U':return "..-"; break;
        case 'V':return "...-"; break;
        case 'W':return ".--"; break;
        case 'X':return "-..-"; break;
        case 'Y':return "-.--"; break;
        case 'Z':return "--.."; break;
        case ' ':return ""; break;
        default:
        return "*"; break;
    }
}
string morsetotext(string morse){
        if(morse == ".-"){return "A";}
        else if(morse == "-..."){return "B";}
        else if(morse == "-.-."){return "C";}
        else if(morse == "-.."){return "D";}
        else if(morse == "."){return "E";}
        else if(morse == "..-."){return "F";}
        else if(morse == "--."){return "G";}
        else if(morse == "...."){return "H";}
        else if(morse == ".."){return "I";}
        else if(morse == ".---"){return "J";}
        else if(morse == "-.-"){return "K";}
        else if(morse == ".-.."){return "L";}
        else if(morse == "--"){return "M";}
        else if(morse == "-."){return "N";}
        else if(morse == "---"){return "O";}
        else if(morse == ".--."){return "P";}
        else if(morse == "--.-"){return "Q";}
        else if(morse == ".-."){return "R";}
        else if(morse == "..."){return "S";}
        else if(morse == "-"){return "T";}
        else if(morse == "..-"){return "U";}
        else if(morse == "...-"){return "V";}
        else if(morse == ".--"){return "W";}
        else if(morse == "-..-"){return "X";}
        else if(morse == "-.--"){return "Y";}
        else if(morse == "--.."){return "Z";}
        else if(morse == ""){return " ";}
        else{return "*";}
}

int main()
{
    char key;
    bool loop = True;
    cout << "\nInstructions:\n";
    cout << "\ta)In case of conversion from text to morse code\n\t\tDo not enter a digit and special character.\n";
    cout << "\tb)In case of conversion from morse code to text\n\t\t1) Enter a space between every aplhabet.\n\t\t2) After every word enter double space.\n";
    cout << "\n\t'*' represents an invalid character in string.\n";
    while(loop)
    {
        boolean toMorse = True;
        int index = 0;
        string temp;
        string input;
        string output = "";
        
        cout << "\nEnter English text or morse code(- and . only):\n";
        getline(cin, input);
        
        //checking for morse code input if true then change toMorse variable to False else true.
        if(input[0] == '.' || input[0] == '-'){
            toMorse = False;
        }
        else{
            toMorse = True;
        }
        
        //checking for toMorse variable if true then go to texttomorse function else go to morsetotext function.
        if(toMorse){
            cout << endl << "The required morse code is :" << endl;
            for(int i = 0;i < input.length(); i++){
                //if statement to add a space after every letter except for the first letter
                //We add a space to differentiate between different morse codes
                if(i != 0){
                    output += " ";
                }
                output = output + texttomorse(toupper(input[i]));
            }
        }
        else{
            cout << endl << "The required english text is :" << endl;
            for(int i = 0;i <= input.length(); i++){
                if(input[i] == ' '){
                    temp = input.substr(index, i-index);
                    output += morsetotext(temp);
                    index = i + 1;
                }
                if(i == input.length() - 1){
                    temp = input.substr(index, i+1-index);
                    output += morsetotext(temp);
                    index = i + 1;
                }
            }
        }
        cout << output << endl;
        
        cout << endl << "Enter 'r' to restart or any other key to exit" << endl;
        cin >> key;
        if(key != 'r'){
            loop = False;
        }
        
        cin.clear();
        cin.ignore();   
    } 
}


