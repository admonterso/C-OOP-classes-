    /*
    At the end of year 2004, the regional agencies of the Polish Military Recruitment Office (known as WKU in Polish) is sending a call to all boys born in 1984. Every recruit has his personal 11-digit identification number (PESEL, format: YYMMDDXXXXX, where YYMMDD is the date of birth, and XXXXX is a zero-padded integer smaller than 100000). Every agency of the Military Recruitment Office has its own code (MRO, format: a place code consisting of 3 upper case letters and a one-digit number). But this year the army underwent some reforms and not all boys at conscription age are going to be recruited. The list of closed down MRO points is as follows: the code of the closed down MRO is followed by the code of some other MRO, to which all the recruits are now going to be assigned. The list of recruits contains their PESEL codes. Your task is to prepare the complete list of recruits and determine the codes of their new MRO-s.

    Input
    s [the number of tests <= 10]
    p [the number of boys at conscription age <= 100000]
    PESEL and MRO code
    z [the number of closed down MRO points <= 100000]
    old_code new_code [old_code - the code of closed down MRO,
    new_code - its new MRO code]
    p [the number of recruits <= 100000]
    PESEL [PESEL code of recruit]
    [empty line]
    [next tests]
    Output
    one PESEL and MRO code per line in the order of input
    [empty line between tests]
    [other results]
    Example
    Input:
    1
    4
    84101011111 GDA1
    84010122222 GDA2
    84010233333 GDA2
    84020255555 GDY1
    1
    GDA2 GDA1
    3
    84101011111
    84010122222
    84020255555

    Output:
    84101011111 GDA1
    84010122222 GDA1
    84020255555 GDY1
    */

    #include <iostream>
    #include <string>
    #include <sstream>
    using namespace std;
    struct HMRO
    {
        string PESEL;
        string MRO;
    };

    struct MRO
    {
        string oldMRO;
        string newMRO;
    };

    class calculateNewAdress{
        private:
            int HMROSNUM;
            int MROSNUM;
            int checkRecruitsLength;
            HMRO HMROS[100000];
            MRO MROS[100000];
            string recruitsToCheck[100000];
            HMRO HMROSTooutput[100000];
        public:
            calculateNewAdress(HMRO *HMROSs, int HMROSNum, MRO *MROSs , int MROSNum, string *recruitsToChecks, int recruitsToChecksLength){
                HMROSNUM = HMROSNum;
                MROSNUM = MROSNum;
                checkRecruitsLength = recruitsToChecksLength;
                for (int i = 0; i < HMROSNum; i++) {
                    HMROS[i].PESEL = HMROSs[i].PESEL;
                    HMROS[i].MRO = HMROSs[i].MRO;
                    //cout<< HMROS[i].PESEL +" "+ HMROSs[i].MRO<< endl;
                }
                
                for (int i = 0; i < MROSNum; i++) {
                    MROS[i].oldMRO = MROSs[i].oldMRO;
                    MROS[i].newMRO = MROSs[i].newMRO;
                    //cout<<MROS[i].oldMRO +" "+MROS[i].newMRO<< endl;
                }
            
                
                for(int i = 0; i<recruitsToChecksLength; i++){
                    recruitsToCheck[i] = recruitsToChecks[i];
                    //cout<< recruitsToCheck[i]<< endl;
                }
             //cout<< endl;
            }
        void alocate(){
            int k = 0;
            for(int i = 0; i<checkRecruitsLength; i++){
                for(int j = 0; j<HMROSNUM; j++){
                    if(recruitsToCheck[i] == HMROS[j].PESEL){
                        HMROSTooutput[k].PESEL = HMROS[j].PESEL;
                        HMROSTooutput[k].MRO = HMROS[j].MRO;
                        //cout<<HMROSTooutput[k].PESEL+ " " + HMROSTooutput[k].MRO <<" "<< endl;
                        k++;
                    }
                }
                
        
                //cout<<recruitsToCheck[i]+ " " + HMROS[i].PESEL<< endl;
                
               
                //HMROSTooutput[i].MRO = HMROS[i].MRO;
            }
            //cout<< endl;
        }    
        void check(){
            for(int i = 0; i<checkRecruitsLength; i++){
                for(int j = 0; j<MROSNUM; j++){
                    if(HMROSTooutput[i].MRO == MROS[j].oldMRO){
                        HMROSTooutput[i].MRO = MROS[j].newMRO;
                    }
                }
               
            }
            
           // cout<<HMROSTooutput[2].MRO + " " + HMROS[2].PESEL<< endl;
        }
        void display(){
           for(int i = 0; i<checkRecruitsLength;i++){
            cout<< HMROSTooutput[i].PESEL +" "+ HMROSTooutput[i].MRO<< endl;
           }
            cout<< endl;
        }
    };


    int main() {
        string line;
        
        // Read input line by line until the end of file (EOF)
        
        getline(cin, line);
            // Process the line
        int test = stoi(line); // the count of test
        calculateNewAdress* adress[test];
        int conscriptionAgeBoys; 
        for(int i = 0; i<test; i++){
        getline(cin, line);
        try{
            conscriptionAgeBoys = stoi(line);
        }
        catch(const std::out_of_range& e){
            cout << line << endl;
        }
        
        HMRO HMROS[conscriptionAgeBoys];

        for(int i = 0; i < conscriptionAgeBoys; i++){

            getline(cin, line);
            istringstream iss(line);
            iss >> HMROS[i].PESEL >> HMROS[i].MRO;
            //cout << HMROS[i].PESEL + " " + HMROS[i].MRO << endl;
        }
        
        getline(cin, line);
    
        int numberOfClosedDownMRO = stoi(line);

        MRO MROS[numberOfClosedDownMRO];
        
        for(int i = 0; i < numberOfClosedDownMRO; i++){

            getline(cin, line);
            istringstream iss(line);
            iss >> MROS[i].oldMRO >>MROS[i].newMRO;
            //cout << MROS[i].oldMRO + " " + MROS[i].newMRO << endl;
        }

        getline(cin, line);

        int numberOfrecruitsThatNeedToCkeck= stoi(line);

        string recruitsThatNeedToCkeck[numberOfrecruitsThatNeedToCkeck];
        for(int i = 0; i<numberOfrecruitsThatNeedToCkeck; i++){

        getline(cin, line);
        istringstream iss(line);
        iss >> recruitsThatNeedToCkeck[i];
            //cout <<recruitsThatNeedToCkeck[i] << endl;
        }
            int length = sizeof(recruitsThatNeedToCkeck) / sizeof(recruitsThatNeedToCkeck[0]);
            
            adress[i] = new calculateNewAdress(HMROS, conscriptionAgeBoys, MROS, numberOfClosedDownMRO, recruitsThatNeedToCkeck, length);
            adress[i]->alocate();
            adress[i]->check();
            //adress[i]->display();
            getline(cin, line);
    }
        for(int i = 0; i<test; i++){
            adress[i]->display();
        }
        return 0;
    }
