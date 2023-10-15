#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<fstream>
#include <string>
#include <cstring>
#include "input_.h"
#include "account.h"
 typedef struct tra{
        char date[];
        float money;
        } transaction;
class account{
private:
        transaction detail[1000];
        int index;
        total_due;
        remaining_due; struct{ char date[]; float money};;
public:
        input_transaction_index();
        input_total_due();
        input_remaining_due();
        get_transaction_index();
        get_total_due();
        get_remaining_due();

        edit_account_data();
};

#endif // ACCOUNT_H
