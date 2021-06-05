/************************
 *      BANK CLASS      *
 ************************/

#ifndef __BANK__
#define __BANK__

class Bank
{
    private:
        int _Amount;

    public:
        Bank();
        int getAmout() const;
        void take(const int amout);
        void give(const int amout);
        ~Bank();
};


#endif