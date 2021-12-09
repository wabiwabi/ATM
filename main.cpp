#include <iostream>
#include <cstdlib>

using namespace std;

void showMenu(){
    cout << "\n\n**********************Main Menu************************\n"<< endl;
    cout << "Options" << endl;
    cout << "\t1. Available Balance " << endl;
    cout << "\t2. Deposit " << endl;
    cout << "\t3. Withdraw " << endl;
    cout << "\t4. Transfer funds to external account" << endl;
    cout << "\t5. Exit " << endl;
    cout << "\n\n*******************************************************"<< endl;

}

void showMenu2(){
 //   cout << "*********Deposit-Menu***********"<< endl;
    cout << "\t1. Deposit from Checking to Savings" << endl;
    cout << "\t2. Deposit from Savings to Checking" << endl;
    cout << "\t3. External deposit to Your Account" << endl;
   // cout << "\t4. Back to previous page" << endl; //havent written the function for this yet
    cout << "\t5. Main Menu " << endl;
    cout << "Selected: ";
}

void showMenu3(){
    cout << "Account to use: " << endl;
    cout << "\tPress s for Savings: " << endl;
    cout << "\tPress c for Checking: " << endl;
    cout << "\tPress 5 for Main Menu " << endl;
    cout << "Selected: ";

}

void showMenu4(){
    cout << "Transfer Options: " << endl;
    cout << "\t1. Transfer to existing beneficiary" << endl;
    //cout << "\t2. Transfer to new beneficiary (option currently unavailable. we apologise for the inconvenience)" << endl;
    cout << "\t5. Main Menu " << endl; //havent written the function for this yet
    cout << "Selected: ";

}

class BeneficiaryInfo{
public:
    string Name;
    string Phone;
    string AccNo;

    BeneficiaryInfo(string name, string phone, string accNo){
    Name = name;
    Phone = phone;
    AccNo = accNo;
    }
};

void DisplayBeneficiaries(){
    int bank;
    cout << "Beneficiary Options: " <<endl;
    BeneficiaryInfo sister("Yonce Carter", "081 445 5723", "62538974");
    cout << "Option 1:" <<  endl;
    cout << "\t Name: " << sister.Name << endl;
    cout << "\t Phone number: " << sister.Phone << endl;
    cout << "\t Account number: " << sister.AccNo << endl<< endl;

    BeneficiaryInfo brother("Bruce J", "065 222 8574", "13277895" );
    cout << "Option 2:" << endl;
    cout << "\t Name: " << brother.Name << endl;
    cout << "\t Phone number: " << brother.Phone << endl;
    cout << "\t Account number: " << brother.AccNo << endl<< endl;

    BeneficiaryInfo aunty ("Kim K", "021 956 7813", "415877923");
    cout << "Option 3:" << endl;
    cout << "\t Name: " << aunty.Name << endl;
    cout << "\t Phone number: " << aunty.Phone << endl;
    cout << "\t Account number: " << aunty.AccNo << endl<< endl;
    //choose beneficiary
    cout << "Pick Beneficiary: " ;
    cin >> bank;
    switch(bank){
    case 1: cout << "Money transfered to: " << sister.Name<< endl; break;

    case 2: cout << "Money transfered to: " << brother.Name << endl; break;

    case 3: cout << "Money transfered to: " << aunty.Name <<endl; break;
    }

}

int main()
{
    //user verifies account with credentials
//    const string AccNo = "536478910";
//    const string AccPin = "56789";
//    cout << "Ënter your Account Number: " << endl;
//    cin >> AccNo;
//    cout << "Ënter your 5 digit Account Pin: " << endl;
//    cin >> AccPin;
//
//    if (AccNo = true && AccPin = true){
//    }
//    else
//        cout << "Incorrect credentials. Please try again." << endl;

    //if credentials pass, move onto the main program
    int option;     //stores selected operation for toggling between balance, deposit, withdraw, and exit (1-4)
    double SavingsBalance = 200.00;
    double CheckingBalance = 250.00;
    do{
        showMenu();
        int bank;       //option for type of banking operation to be done
        char account;      //wheteher client wants to use savings or checking
        cout << "Selected: ";
        cin >> option;
        system("cls");
        switch (option) //toggling between balance, deposit, withdraw, and exit
        {
            case 1: cout << "\n\n \t\t        Your Accounts" << endl; //checks balance
                    cout << "*******************************************************" << endl;
                    cout << "\nUser Name: Honey McBaggins" << endl;
                    cout << "  Savings: $ " << SavingsBalance<< endl; //check balance
                    cout << " Checking: $ " << CheckingBalance<< endl;
            break;
            case 2: cout << "Deposit amount: $ ";               //deposit money
                    double deposit;     //stores the money to be deposited
                    cin >> deposit;
                    if (deposit > 0){
                        cout << "Options: " << endl;
                        showMenu2();
                        cin >> bank;
                        //depositSwitch();
                        switch(bank){
                            case 1: if (deposit <= CheckingBalance){
                                CheckingBalance -= deposit;
                                SavingsBalance += deposit;
                                cout << "Savings balance: $ " << SavingsBalance<< endl;
                                cout << "Checking balance: $ " <<CheckingBalance<< endl;
                            }
                            else
                                cout << "Invalid input: insufficient funds" << endl;
                            break;

                            case 2: if(deposit <= SavingsBalance){
                                        CheckingBalance += deposit;
                                        SavingsBalance -= deposit;
                                        cout << "Savings balance: $ " << SavingsBalance<< endl;
                                        cout << "Checking balance: $ " << CheckingBalance<< endl;
                            }
                            else
                                cout << "Invalid input: insufficient funds" << endl;
                            break;

                            case 3: //deposit externally into Your Accounts
                            showMenu3();
                            cin >> account;
                            switch(account){
                                case 's':   SavingsBalance += deposit;
                                            cout << "Savings balance: $ " << SavingsBalance<< endl; break;
                                case 'c':   CheckingBalance += deposit;
                                            cout << "Checking balance: $ " << CheckingBalance << endl; break;
                            }
                        }
                 }
                    else //belongs to deposit > 0 for deposit entire case
                    cout << "Invalid deposit input" << endl;
                    break;
            case 3: //fixed bugs :)
                    cout << "Withdraw amount: $ " ;             //withdraw money
                    double withdraw;
                    cin >> withdraw;
                    if (withdraw > 0){
                    showMenu3(); //program breaks immediately after this for some reason.
                    cin >> account;
                    switch(account){
                        case 's':
                            if (withdraw <= SavingsBalance ){
                            SavingsBalance-=withdraw;
                            cout << "Savings balance: " << SavingsBalance << endl;
                        }
                            else //belongs to withdraw > 0 for withdraw case
                            cout << "Insufficient funds" << endl;
                            break;
                        case 'c':
                            if (withdraw <= CheckingBalance ){
                            CheckingBalance-=withdraw;
                            cout << "Checking balance: " << CheckingBalance << endl;
                            }
                            else //belongs to withdraw > 0 for withdraw case
                            cout << "Insufficient funds" << endl;
                        break;
                        }
                    }
                    else //belongs to withdraw > 0 for withdraw case
                        cout << "Insufficient funds" << endl;
                break; // belongs to entire withdraw case

            case 4: cout << "Amount to be transferred: $"; //case gives unexpected result when double checking balance after
                    double transfer;                        //operation complete, same as case 3 (withdraw) operation.
                    cin >> transfer;
                    if (transfer > 0){
                    showMenu3();
                    cin >> account;
                        switch(account){
                        case 's':
                          if(transfer <= SavingsBalance){
                            showMenu4();
                            cin >> bank;
////                           code for existing beneficiary OR manual beneficiary
                            DisplayBeneficiaries();
//                               if(bank = 1){
//                                    //which existing beneficiary do you want
//                                }
//                                if (bank = 2){
//                                    //key in new beneficiary
//                                }
                                SavingsBalance-=transfer;
                              cout << "Savings balance: " << SavingsBalance<< endl;
                                }
                             else
                                cout << "Invalid input" << endl;
                            break;
                        case 'c':
                            if(transfer <= CheckingBalance){
                            showMenu4();
                            cin >> bank;
                            DisplayBeneficiaries();

//                           code for existing beneficiary OR manual beneficiary
//                                if(bank = 1){
//                                    //which existing beneficiary do you want
//                                }
//                                if (bank = 2){
//                                    //key in new beneficiary
//                                }
////
                                CheckingBalance-=transfer;
                              cout << "Checking balance: " << CheckingBalance << endl;
                                }
                            ////
                             else
                                cout << "Invalid input" << endl;
                            break;
                            }
                    }
                    else
                        cout << "Invalid input." << endl;
                break;
        }
    } while (option!=5); cout << "\n\n***********************Thank You For Banking With Us!***************************" << endl;

}
                    //delete
//                     cout << "Please key in the following " << endl;
//                     cout << "First and last namee of beneficiary: " << name << endl;
//                     cout << "Beneficiary account number: " << accNo << endl;
//                     cout << "Beneficiary phone number: " phone << endl;

