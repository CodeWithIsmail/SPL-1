#include"AllHeaderFile.h"

// Function to print text with padding on all sides and gaps between lines
vector<string>userInput,targetInput;
void printFormatted(const string& text, int maxWidth, int padding, int lineGap, int interLineGap)
{
    int startPos = 0;
    while (startPos < text.length())
    {
        string line = text.substr(startPos, maxWidth - 2 * padding);
        cout << setw(maxWidth) << left << setfill(' ') << string(padding, ' ') + line + string(padding, ' ') << endl;
        startPos += maxWidth - 2 * padding;

        // Add a gap between lines
        for (int i = 0; i < interLineGap; ++i)
        {
            cout << setw(maxWidth) << left << setfill(' ') << string(maxWidth, ' ') << endl;
        }
    }
}

void showtext()
{
    system("color FD");
    cout << "\n\t\t\t\t\t\t Paragraph Typing\n";
    FILE *file = freopen("paraeng1.txt", "r", stdin); // Redirect stdin to read from "input.txt"
    if (file == nullptr)
    {
        cerr << "Error opening file!" << endl;
        //   return 1; // Exit if file opening fails
    }

    const int maxWidth = 120; // Adjust this width according to your terminal or output requirements
    const int padding = 5; // Adjust padding size
    const int lineGap = 2; // Adjust gap at the beginning
    const int interLineGap = 1; // Adjust gap between lines

    // Add empty lines at the beginning for top spacing
    for (int i = 0; i < lineGap; ++i)
    {
        cout << setw(maxWidth) << left << setfill(' ') << string(maxWidth, ' ') << endl;
    }

    string line;
    while (getline(cin, line))
    {
        // Process the line as needed and print with formatted width, padding, and gaps
        targetInput.push_back(line);
        printFormatted(line, maxWidth, padding, lineGap, interLineGap);
    }

    fclose(file); // Close the file when done
    //   return 0;
}
void input(int timesec)
{


    // Redirect stdout to write to "output.txt"

    // Take user input until they enter "exit"
    auto startTime = chrono::high_resolution_clock::now();
    int elapsed_time=0;
    while (elapsed_time<timesec)
    {
        string in;
        cin>>in;

        // Write user input to the file
        auto endTime = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = endTime - startTime;
        elapsed_time=duration.count();

        userInput.push_back(in);

    }

    // Close the file when done
//    return elapsed_time;
    // cout << "Input saved to " << filename << endl;

    // return 0;
}

void check_input(int timesec)
{
       system("cls");

    int timepassed= timesec;

    int totalword=targetInput.size(),wrong=0,score=0;
    for(int i=1; i<=totalword; i++)
    {
        if(targetInput[i]!=userInput[i])
        {
            wrong++;
            score-=5*edit_distance(targetInput[i],userInput[i]);
        }
        else score+=5*targetInput[i].length();

    }

    int GrossSpeed = (totalword) / timepassed; // speed in WPM
    int NetSpeed = (totalword-wrong) / timepassed;

    score = totalword - wrong;
    int accuracy = (totalword-wrong * 100) / totalword;

    system("cls");
    //   cout<<duration.count()/60;
    cout << "\n\n\n\t\t\t\t\t Gross Speed: " << GrossSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Net Speed: " << NetSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Total Key Press: " << totalword;
    cout << "\n\n\t\t\t\t\t Wrong Key Press: " << wrong;
    cout << "\n\n\t\t\t\t\t Accuracy: " << accuracy << "%";
    cout << "\n\n\t\t\t\t\t Score: " << score;
    cout << "\n\n\t\t\t\t\t";
    accuracy > 93 ? cout << " Very Good\n" : cout << " Try to improve\n";
    cout << endl;

    //  drawHistogram(dataset, limit, wrongPressCount);

    ofstream performance("PerformanceHistory.txt", ios::app);
    // string write = "Paragraph Type" + "," + DateFind() + "," + to_string(totalword) + "," + to_string(wrong) + "," + to_string(accuracy) + "," + to_string(score) + "\n";

    performance << write;
    performance.close();
}
void paragraph_type(int timesec)
{
    system("cls");
    system("color FD");
   // showtext();
    cout<<"\n";

    input(timesec);
 check_input( timesec);
}
