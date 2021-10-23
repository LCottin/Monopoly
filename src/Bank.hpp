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
        void input(const int amout);
        bool output(const int amout);
        ~Bank();
};


#endif