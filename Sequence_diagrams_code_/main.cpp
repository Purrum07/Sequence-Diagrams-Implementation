#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class File_validator{   //Here we have the way i decided to validate the file
public:
    bool validate(fstream & inFile){
        inFile.open("results.txt");

        if(!inFile){
            cout<<"Unable to open file results.txt";
            return false;
        }else{
            //return true;
        }

        inFile.close();
    }
};


struct Participant{  // We can create a struct to define the Participant as a combination of name and score
public:

    string name = "";
    int score = 0;

};

bool compare(Participant a, Participant b) { return a.score>b.score; } //With this we can compare the scores in the struct

vector<Participant> competitors;
                                     //is easier to order the scores
class File_reader{
public:

    void read(fstream & inFile){       // In this part the system opens the file and reads it complete to obtain the names and scores in order to create the
                                       // different participants
        vector<int> vectornum;
        vector<string> participants;
        inFile.open("results.txt");
        string cosas;

        while(!inFile.eof()){
            getline(inFile, cosas, ',');
            participants.push_back(cosas);
        }

        inFile.close();

        //for(int i = 0; i< participants.size(); i++){
          //  cout<<participants[i];
        //}

        for (int i = 0; i<participants.size(); i++){

            if(i%2) {

                vectornum.push_back(stoi(participants[i]));
            }
        }

        //cout<<endl<<vectornum[0]<<endl;
        //cout<<vectornum[1]<<endl;
        //cout<<vectornum[2]<<endl;
        //cout<<vectornum[3]<<endl;
        //cout<<"-----------"<<endl;


        int j = 0;
        for(int i=0; i<participants.size(); i++) {

            if(i%2){
                Participant p_temp;
                p_temp.name = participants.at(i-1);
                p_temp.score = vectornum[j++];
                competitors.push_back(p_temp);
            }
        }

    }
};

class Sorter{
public:
    void sortear() {
        sort(competitors.begin(), competitors.end(), compare); //We can sort the scores with the struct comparing the scores
    }
};

class Out_formatter{
public:
    void format(){
        cout<<"The top three competitors are: "<<endl; // Finally the format is done and everything is presented to the user
        for(int i=0; i<3; i++) {
            cout << competitors[i].name << " " << competitors[i].score <<  endl;
        }
    }
};




int main()
{
    fstream inFile;

    File_validator Fv;
    Fv.validate(inFile);

    File_reader Fr;
    Fr.read(inFile);

    Sorter s;
    s.sortear();

    Out_formatter Of;
    Of.format();

    return 0;
}
